#include "pch.h"
#include "FishMan.h"

#include "GameManager.h"

Texture* FishMan::s_FishManTexture = nullptr;

FishMan::FishMan(const Vector2f& startPos)
    : Enemy(startPos, 80.f, Rectf(0, 0, 20, 40)),
    m_WalkDistance(40.f),
    m_DistanceTravelled(0.f),
    m_MovingRight(true),
    m_GravityAcceleration(-45),
    m_JumpingTime(0.5),
    m_JusmpingSpeed(90)
    , m_Animation(s_FishManTexture, 0, 2, 0.2)
{
    m_isActive = false;
}

void FishMan::Update(float elapsedSec)
{
    m_Animation.Update(elapsedSec);

    if (m_isActive == true)
    {
        
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

        if (m_DistanceTravelled > m_WalkDistance)
        {
            m_DistanceTravelled = 0;
            m_MovingRight = !m_MovingRight;
        }

        if (m_JumpingTime > 0)
        {
            m_JumpingTime = m_JumpingTime - elapsedSec;
            m_Pos.y = m_Pos.y + m_JusmpingSpeed * elapsedSec;
        }

    }
}

void FishMan::Activate()
{
    m_isActive = true;
}

void FishMan::Draw(bool IsDebug) const
{
    if (m_isActive)
    {
        if (!m_MovingRight)
        {
            m_Animation.Draw(m_Pos, false);
        }
        else
        {
            m_Animation.Draw(m_Pos, true);
        }
    }


    if (IsDebug)
    {
        utils::SetColor(Color4f(0, 1, 0, 1));
        utils::DrawRect(Rectf(m_Pos.x, m_Pos.y, m_Hitbox.width, m_Hitbox.height));
    }

}

void FishMan::LoadTexture()
{
    if (!s_FishManTexture)
    {
        s_FishManTexture = new Texture("../../Resources/Reworked textures/Enemies/FishMan.png"); //<- replace later
    }
}

void FishMan::FreeTexture()
{
    delete s_FishManTexture;
    s_FishManTexture = nullptr;
}