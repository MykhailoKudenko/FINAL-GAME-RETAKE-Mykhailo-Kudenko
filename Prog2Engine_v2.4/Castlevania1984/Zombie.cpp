#include "pch.h"
#include "Zombie.h"
#include "GameManager.h"

Texture* Zombie::s_ZombieTexture = nullptr;

Zombie::Zombie(const Vector2f& startPos)
    : Enemy(startPos, 40.f, Rectf(0, 0, 16, 32)),
    m_WalkDistance(100.f),
    m_DistanceTravelled(0.f),
    m_MovingRight(true),
    m_GravityAcceleration(-45)
    , m_Animation(s_ZombieTexture, 0, 2, 0.2)
{}

void Zombie::Update(float elapsedSec)
{
    m_Animation.Update(elapsedSec);

    float movement;
    float positiveMovement;
    if (m_MovingRight)
    {
        movement = m_Speed * elapsedSec;
    }
    else
    {
        movement = -m_Speed * elapsedSec;
    }

    if (movement < 0)
        positiveMovement = -movement;
    else
        positiveMovement = movement;
   

    m_DistanceTravelled += positiveMovement;

    // gravity


    float newY = m_Pos.y + m_GravityAcceleration * elapsedSec;
    float newX = m_Pos.x + movement;
    if (!GameManager::DoesCollideWithBlock(Rectf(m_Pos.x, newY, m_Hitbox.width, m_Hitbox.height)))
    {
        m_Pos.y = newY;
    }
    if (!GameManager::DoesCollideWithBlock(Rectf(newX, m_Pos.y, m_Hitbox.width, m_Hitbox.height)))
    {
        m_Pos.x = newX;
    }
    else
    {
        m_DistanceTravelled = 0;
        m_MovingRight = !m_MovingRight;
    }

    if (m_DistanceTravelled > m_WalkDistance )
    {
        m_DistanceTravelled = 0;
        m_MovingRight = !m_MovingRight;
    }
}

void Zombie::Draw(bool IsDebug) const
{
    if (!m_MovingRight)
    {
        m_Animation.Draw(m_Pos , false);
    }
    else
    {
        m_Animation.Draw(m_Pos, true);
    }
    

    if (IsDebug)
    {
        utils::SetColor(Color4f(0, 1, 0, 1));
        utils::DrawRect(Rectf(m_Pos.x, m_Pos.y, m_Hitbox.width, m_Hitbox.height));
    }

}

void Zombie::LoadTexture()
{
    if (!s_ZombieTexture)
    {
        s_ZombieTexture = new Texture("../../Resources/Reworked textures/Enemies/Zombie.png"); 
    }
}

void Zombie::FreeTexture()
{
    delete s_ZombieTexture;
    s_ZombieTexture = nullptr;
}