#include "pch.h"
#include "Bat.h"

Texture* Bat::s_BatTexture = nullptr;

Bat::Bat(const Vector2f& startPos)
    : Enemy(startPos, 40.f, Rectf(0, 0, 16, 16)),
      m_FlyDistance(150.f),  
      m_DistanceTravelled(0.f),
      m_MovingRight(true)
    , m_Animation(s_BatTexture, 0, 3, 0.2)
{
    m_dirCountDown = 0.25;
}

void Bat::Update(float elapsedSec)
{
    m_Animation.Update(elapsedSec);

    float movement = m_Speed * elapsedSec;

    m_dirCountDown = m_dirCountDown + elapsedSec;

    if (m_dirCountDown >= 0.5)
    {
        m_MovingUp = !m_MovingUp;
        m_dirCountDown = 0;
    }

    if (m_MovingRight)
    {
        m_Pos.x += movement;
    }
    else
    {
        m_Pos.x -= movement;
    }

    if (m_MovingUp)
    {
        m_Pos.y += movement;
    }
    else
    {
        m_Pos.y -= movement;
    }

    //std::cout << m_Pos.y << std::endl;

    m_DistanceTravelled += movement;

    if (m_DistanceTravelled > m_FlyDistance)
    {
        m_DistanceTravelled = 0;
        m_MovingRight = !m_MovingRight;
    }
}

void Bat::Draw(bool IsDebug) const
{
    if (!m_MovingRight)
    {
        m_Animation.Draw(m_Pos, false);
    }
    else
    {
        m_Animation.Draw(m_Pos, true);
    }
    if (IsDebug)
    {
        utils::SetColor(Color4f(1, 1, 0, 1));
        utils::DrawRect(Rectf(m_Pos.x, m_Pos.y, m_Hitbox.width, m_Hitbox.height));
    }
}

void Bat::LoadTexture()
{
    if (!s_BatTexture)
    {
        s_BatTexture = new Texture("../../Resources/Reworked textures/Enemies/Bat.png"); 
    }

}

void Bat::FreeTexture()
{
    delete s_BatTexture;
    s_BatTexture = nullptr;
}