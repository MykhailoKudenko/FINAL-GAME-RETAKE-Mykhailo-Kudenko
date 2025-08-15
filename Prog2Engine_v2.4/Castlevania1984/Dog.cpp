#include "pch.h"
#include "Dog.h"
#include "GameManager.h"

Texture* Dog::s_DogTexture = nullptr;

Dog::Dog(const Vector2f& startPos)
    : Enemy(startPos, 80.f, Rectf(0, 0, 32, 16)),
    m_WalkDistance(150.f),
    m_DistanceTravelled(0.f),
    m_MovingRight(true),
    m_GravityAcceleration(-45)
    , m_Animation(s_DogTexture, 32, 3, 0.2)
{
    m_isActive = false;
}

void Dog::Update(float elapsedSec)
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
    }
}

void Dog::Activate()
{
    m_isActive = true;
}

void Dog::Draw(bool IsDebug) const
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
    else
    {
        s_DogTexture->Draw(m_Pos, Rectf(0, 0, 30, 16));
    }

    if (IsDebug)
    {
        utils::SetColor(Color4f(0, 1, 0, 1));
        utils::DrawRect(Rectf(m_Pos.x, m_Pos.y, m_Hitbox.width, m_Hitbox.height));
    }

}

void Dog::LoadTexture()
{
    if (!s_DogTexture)
    {
        s_DogTexture = new Texture("../../Resources/Reworked textures/Enemies/Dog.png"); 
    }
}

void Dog::FreeTexture()
{
    delete s_DogTexture;
    s_DogTexture = nullptr;
}