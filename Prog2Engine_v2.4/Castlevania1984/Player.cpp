#include "pch.h"
#include "Player.h"
#include "GameManager.h"


Texture* Player::s_PlayerAccend = nullptr;
Texture* Player::s_PlayerDecend = nullptr;
Texture* Player::s_PlayerJumpDuck = nullptr;
Texture* Player::s_PlayerDeath = nullptr;
Texture* Player::s_PlayerWalk = nullptr;
Texture* Player::s_PlayerWhipAttack = nullptr;


Player::Player(const Vector2f& startPos, std::vector<Projectile*>& projectiles)
    : m_Projectiles(projectiles)
    , m_AccendAnimation(s_PlayerAccend, 0, 2, 0.2, true)
    , m_DecendAnimation(s_PlayerDecend, 0, 2, 0.2, true)
    , m_WalkAnimation(s_PlayerWalk, 0, 3, 0.2, true)
    , m_DeathAnimation(s_PlayerDeath, 0, 2, 0.6, false)
{
    m_Pos = startPos;
    m_NumberofHearts = 0; 
    m_DoesHaveanAxe = false;
    m_DoeshaveaKnife = false;
    m_LastXDir = 1;
    m_IsOnStairs = false;
    m_isDead = false;
    m_IsOnTheGround = false;
    m_IsMoving = false;
}

void Player::Update(float elapsedSec)
{
    m_AccendAnimation.Update(elapsedSec);
    m_DecendAnimation.Update(elapsedSec);
    m_WalkAnimation.Update(elapsedSec);
    m_DeathAnimation.Update(elapsedSec);


    m_IsMoving = false;



    if (m_Health <= 0)
    {
        m_isDead = true;
        m_DeathReturnDelay = m_DeathReturnDelay - elapsedSec;
        m_DeathAnimation.Update(elapsedSec);
    }
    


    if (m_StunCurrent >= 0)
    {
        m_StunCurrent -= elapsedSec;
    }
    if (m_InvonurabilityCurrent >= 0)
    {
        m_InvonurabilityCurrent -= elapsedSec;
    }
    if (m_ProjectileCooldownCurrent >= 0.f)
    {
        m_ProjectileCooldownCurrent -= elapsedSec;
    }
    if (m_WhipCooldownCurrent >= 0.f)
    {
        m_WhipCooldownCurrent -= elapsedSec;
    }
    if (m_JumpTimeCurrent >= 0.f)
    {
        m_JumpTimeCurrent -= elapsedSec;
    }
    if (m_isDead == false)
    {
        if (m_IsOnStairs)
        {
            OnStairsUpdate(elapsedSec);
        }
        else if (m_StunCurrent <= 0)
        {
            const Uint8* pStates = SDL_GetKeyboardState(nullptr);
            if (m_CurrentStair != nullptr)
            {
                if (!m_CurrentStair->IsInverted())
                {
                    if (utils::IsOverlapping(m_CurrentStair->GetBottomTrigger(), GetHitbox()))
                    {
                        if (pStates[SDL_SCANCODE_W])
                        {
                            m_IsOnStairs = true;
                            m_Pos = m_CurrentStair->GetBottomCentre();
                        }
                    }

                    if (utils::IsOverlapping(m_CurrentStair->GetTopTrigger(), GetHitbox()))
                    {
                        if (pStates[SDL_SCANCODE_S])
                        {
                            m_IsOnStairs = true;
                            m_Pos = m_CurrentStair->GetTopCentre();
                        }
                    }
                }
                else
                {
                    if (utils::IsOverlapping(m_CurrentStair->GetBottomTrigger(), GetHitbox()))
                    {
                        if (pStates[SDL_SCANCODE_S])
                        {
                            m_IsOnStairs = true;
                            m_Pos = m_CurrentStair->GetBottomCentre();
                        }
                    }

                    if (utils::IsOverlapping(m_CurrentStair->GetTopTrigger(), GetHitbox()))
                    {
                        if (pStates[SDL_SCANCODE_W])
                        {
                            m_IsOnStairs = true;
                            m_Pos = m_CurrentStair->GetTopCentre();
                        }
                    }
                }

            }


            // movement input

            float moveDir = 0.f;
            if (m_WhipCooldownCurrent <= 0)
            {
                if (pStates[SDL_SCANCODE_D])
                {
                    moveDir += 1.f;
                    m_IsMoving = true;
                }
                if (pStates[SDL_SCANCODE_A])
                {
                    moveDir -= 1.f;
                    m_IsMoving = true;
                }
            }



            // movement

            if (!GameManager::DoesCollideWithBlock(Rectf(m_Pos.x + moveDir * m_playerSpeed * elapsedSec, m_Pos.y, m_Hitbox.width, m_Hitbox.height)))
            {
                m_Pos.x += moveDir * m_playerSpeed * elapsedSec;
            }



            // gravity

            if (moveDir != 0)
            {
                m_LastXDir = moveDir;
            }

            float newY = m_Pos.y;

            if (m_JumpTimeCurrent <= 0)
            {
                newY = m_Pos.y + m_GravityAcceleration * elapsedSec;
            }
            else
            {
                newY = m_Pos.y + m_JumpSpeed * elapsedSec;
            }


            if (!GameManager::DoesCollideWithBlock(Rectf(m_Pos.x, newY, m_Hitbox.width, m_Hitbox.height)))
            {
                m_Pos.y = newY;
            }

            if (GameManager::DoesCollideWithBlock(Rectf(m_Pos.x, m_Pos.y - 10, m_Hitbox.width, m_Hitbox.height)))
            {
                m_IsOnTheGround = true;
            }
            else
            {
                m_IsOnTheGround = false;
            }

            if (pStates[SDL_SCANCODE_SPACE] && m_IsOnTheGround && m_JumpTimeCurrent <= 0)
            {
                m_JumpTimeCurrent = m_JumpTimeMax;
            }

            if (pStates[SDL_SCANCODE_X] && m_ProjectileCooldownCurrent <= 0.f && m_NumberofHearts > 0 && m_DoeshaveaKnife == true)
            {
                m_NumberofHearts--;
                m_ProjectileCooldownCurrent = m_ProjectileCooldownMax;

                Vector2f knifeVelocity = Vector2f{ (float)m_LastXDir, 0 };
                m_Projectiles.push_back(new Knife(Vector2f{ m_Pos.x + m_Hitbox.width / 2, m_Pos.y + m_Hitbox.height / 2 }, knifeVelocity));
            }

            if (pStates[SDL_SCANCODE_X] && m_ProjectileCooldownCurrent <= 0.f && m_NumberofHearts > 0 && m_DoesHaveanAxe == true)
            {
                m_NumberofHearts--;
                m_ProjectileCooldownCurrent = m_ProjectileCooldownMax;

                Vector2f AxeVelocity = Vector2f{ (float)m_LastXDir, 0 };
                m_Projectiles.push_back(new Axe(Vector2f{ m_Pos.x + m_Hitbox.width / 2, m_Pos.y + m_Hitbox.height / 2 }, AxeVelocity));
            }


            if (pStates[SDL_SCANCODE_Z] && m_WhipCooldownCurrent <= 0.f)
            {

                m_WhipCooldownCurrent = m_WhipCooldownMax;


                if (m_LastXDir == 1)
                {

                    m_Projectiles.push_back(new Whip(Vector2f{ m_Pos.x + m_Hitbox.width / 2, m_Pos.y + m_Hitbox.height / 2-5 }));
                }
                else if (m_LastXDir == -1)
                {
                    m_Projectiles.push_back(new Whip(Vector2f{ m_Pos.x + m_Hitbox.width / 2 - 50, m_Pos.y + m_Hitbox.height / 2-5 }));
                }

            }

        }
        else
        {
            if (!GameManager::DoesCollideWithBlock(Rectf(m_Pos.x, m_Pos.y + m_KnockbackSpeed * elapsedSec, m_Hitbox.width, m_Hitbox.height)))
            {
                m_Pos.y += m_KnockbackSpeed * elapsedSec;
            }

        }
    }
    
}

void Player::Draw(bool IsDebug) const
{
    if (m_isDead)
    {
        m_DeathAnimation.Draw(m_Pos, false);
    } 
    else if (m_WhipCooldownCurrent > 0.1)
    {

        if (m_LastXDir == -1)
        {
            s_PlayerWhipAttack->Draw(Vector2f{ m_Pos.x - 32,m_Pos.y});
        }
        else if (m_LastXDir == 1)
        {
            DrawMirrored(s_PlayerWhipAttack, Vector2f{ m_Pos.x + 32,m_Pos.y }, Rectf{ 0, 0, 16, 32 });
            
        
        }

    } else
    if (m_IsOnStairs)
    {
        if (m_LastXDir == -1)
        {
            if (m_CurrentStair->IsInverted())
            {
                //std::cout << "inv" << std::endl;
                if (m_IsMoving)
                {
                    m_AccendAnimation.Draw(m_Pos, false);
                }
                else
                {
                    s_PlayerAccend->Draw(m_Pos, Rectf{ 0, 0, 16, 32 });

                }
            }
            else
            {
                if (m_IsMoving)
                {
                    m_DecendAnimation.Draw(m_Pos, false);
                }
                else
                {
                    s_PlayerDecend->Draw(m_Pos, Rectf{ 0, 0, 16, 32 });

                }
            }
        } 
        else if (m_LastXDir == 1)
        {
            if (m_CurrentStair->IsInverted())
            {
                //std::cout << "inv" << std::endl;
                if (m_IsMoving)
                {
                    m_DecendAnimation.Draw(m_Pos, true);
                }
                else
                {

                    DrawMirrored(s_PlayerDecend, m_Pos, Rectf{ 0, 0, 16, 32 });
                }
            }
            else
            {
                if (m_IsMoving)
                {
                    m_AccendAnimation.Draw(m_Pos, true);
                }
                else
                {

                    DrawMirrored(s_PlayerAccend, m_Pos, Rectf{ 0, 0, 16, 32 });
                }
            }
            
        }
            
    } else if (m_LastXDir == -1)
    {

        if (!m_IsOnTheGround || m_StunCurrent >0)
        {
            s_PlayerJumpDuck->Draw(m_Pos);
        }
        else
        {
            if (m_IsMoving)
            {
                m_WalkAnimation.Draw(m_Pos, false);
            }
            else
            {
                s_PlayerWalk->Draw(m_Pos, Rectf{ 0, 0, 16, 32 });
            }
        }

    }
    else if (m_LastXDir == 1)
    {
        if (!m_IsOnTheGround || m_StunCurrent > 0)
        {
            
            DrawMirrored(s_PlayerJumpDuck, m_Pos, Rectf{ 0, 0, 16, 32 });
        }
        else
        {
            if (m_IsMoving)
            {
                m_WalkAnimation.Draw(m_Pos, true);
            }
            else
            {
                
                DrawMirrored(s_PlayerWalk, m_Pos, Rectf{ 0, 0, 16, 32 });
            }
        }
    }




    if (IsDebug){
        utils::SetColor(Color4f(0, 1, 0, 1));
        utils::DrawRect(Rectf(m_Pos.x, m_Pos.y, m_Hitbox.width, m_Hitbox.height));
    }
    
}

void Player::DrawMirrored(Texture* pTexture, const Vector2f& destPos, const Rectf& srcRect) const
{
    if (pTexture == nullptr) return;

    glPushMatrix();
    glTranslatef(destPos.x + srcRect.width, destPos.y, 0.f);
    glScalef(-1.f, 1.f, 1.f);
    if (srcRect.height <= pTexture->GetHeight() && srcRect.width <= pTexture->GetWidth())
    {
        pTexture->Draw(Vector2f{ 0.f, 0.f }, srcRect);
    }
    else
    {
        pTexture->Draw(Vector2f{ 0.f, 0.f });
    }
   
    glPopMatrix();
}

void Player::TakeDamage()
{
    if (m_InvonurabilityCurrent <= 0)
    {
        m_InvonurabilityCurrent = m_InvonurabilityMax;
        m_StunCurrent = m_StunMax;

        m_Health = m_Health - 1;
    }

}

Rectf Player::GetHitbox() const
{
    return(Rectf(m_Pos.x, m_Pos.y, m_Hitbox.width, m_Hitbox.height));;
}

void Player::Teleport(const Vector2f& NewPos)
{
    m_Pos = NewPos;
}

void Player::TakeDrop(Drop::DropType drop)
{
    switch (drop)
    {
    case Drop::DropType::HeartSmall:
        m_NumberofHearts = m_NumberofHearts + 1;
        break;
    case Drop::DropType::HeartBig:
        m_NumberofHearts = m_NumberofHearts + 5;
        break;
    case Drop::DropType::Knife:
        m_DoesHaveanAxe = false;
        m_DoeshaveaKnife = true;
        break;
    case Drop::DropType::Axe:
        m_DoesHaveanAxe = true;
        m_DoeshaveaKnife = false;
        break;
    }
}

void Player::OnStairsUpdate(float elapsedSec)
{
    Vector2f bottom = m_CurrentStair->GetBottomCentre();
    Vector2f top = m_CurrentStair->GetTopCentre();

    Vector2f direction = top - bottom;
    float length = sqrtf(direction.x * direction.x + direction.y * direction.y);
    if (length != 0)
    {
        direction.x /= length;
        direction.y /= length;
    }

    const Uint8* pStates = SDL_GetKeyboardState(nullptr);
    if (m_CurrentStair->IsInverted())
    {
        if (pStates[SDL_SCANCODE_S] || pStates[SDL_SCANCODE_D])
        {
            m_Pos = m_Pos + direction * m_playerStairSpeed * elapsedSec;
            m_IsMoving = true;
            m_LastXDir = 1;
        }
        else if (pStates[SDL_SCANCODE_W] || pStates[SDL_SCANCODE_A])
        {
            m_Pos = m_Pos - direction * m_playerStairSpeed * elapsedSec;
            m_IsMoving = true;
            m_LastXDir = -1;
        }
    }
    else
    {
        if (pStates[SDL_SCANCODE_W] || pStates[SDL_SCANCODE_D])
        {
            m_Pos = m_Pos + direction * m_playerStairSpeed * elapsedSec;
            m_IsMoving = true;
            m_LastXDir = 1;
        }
        else if (pStates[SDL_SCANCODE_S] || pStates[SDL_SCANCODE_A])
        {
            m_Pos = m_Pos - direction * m_playerStairSpeed * elapsedSec;
            m_IsMoving = true;
            m_LastXDir = -1;
        }
    }

    

    
    Vector2f stairVec = top - bottom;
    Vector2f playerVec = m_Pos - bottom;

    float stairLenSquared = stairVec.x * stairVec.x + stairVec.y * stairVec.y;
    float dot = playerVec.x * stairVec.x + playerVec.y * stairVec.y;

    
    if (dot < -10.0f || dot > stairLenSquared + 10.0f) 
    {
        m_IsOnStairs = false;
    }
}

void Player::EnterStairs(Stairs* stairs)
{
        m_CurrentStair = stairs;


}

bool Player::IsOnStairs()
{
    return(m_IsOnStairs);
}

bool Player::IsDead()
{

    if (m_DeathReturnDelay >= 0)
    {
        return(false);
    }
    else
    {
        return(m_isDead);
    }
    
}

void Player::Revive(const Vector2f& revivePos)
{
    m_Health = 16;
    m_isDead = false;
    m_Pos = revivePos;
    m_DeathReturnDelay = 1.2;
}

void Player::LoadTextures()
{
    if (!s_PlayerAccend)
    {
        s_PlayerAccend = new Texture("../../Resources/Reworked textures/Player/Accend.png"); 
    }
    if (!s_PlayerDecend)
    {
        s_PlayerDecend = new Texture("../../Resources/Reworked textures/Player/Decend.png");
    }
    if (!s_PlayerJumpDuck)
    {
        s_PlayerJumpDuck = new Texture("../../Resources/Reworked textures/Player/JumpDuck.png");
    }
    if (!s_PlayerDeath)
    {
        s_PlayerDeath = new Texture("../../Resources/Reworked textures/Player/Death.png");
    }
    if (!s_PlayerWalk)
    {
        s_PlayerWalk = new Texture("../../Resources/Reworked textures/Player/Walk.png");
    }
    if (!s_PlayerWhipAttack)
    {
        s_PlayerWhipAttack = new Texture("../../Resources/Reworked textures/Player/Whip.png");
    }
}

void Player::FreeTextures()
{
    delete s_PlayerAccend;
    s_PlayerAccend = nullptr;

    delete s_PlayerDecend;
    s_PlayerDecend = nullptr;

    delete s_PlayerJumpDuck;
    s_PlayerJumpDuck = nullptr;

    delete s_PlayerDeath;
    s_PlayerDeath = nullptr;

    delete s_PlayerWalk;
    s_PlayerWalk = nullptr;

    delete s_PlayerWhipAttack;
    s_PlayerWhipAttack = nullptr;
}

