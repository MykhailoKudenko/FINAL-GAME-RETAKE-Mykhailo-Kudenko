#include "pch.h"
#include "Drop.h"
#include "GameManager.h"

Drop::Drop(const Vector2f& pos, DropType type)
    : m_DropType(type)
{
    m_Pos = pos;

    m_Hitbox = Rectf{ 0, 0, 16, 16 };


    switch (type)
    {
    case DropType::HeartSmall:
        m_Texture = new Texture("../../Resources/Reworked textures/Drops/SmallHeart.png");
        break;
    case DropType::HeartBig:
        m_Texture = new Texture("../../Resources/Reworked textures/Drops/BigHeart.png");
        break;
    case DropType::Knife:
        m_Texture = new Texture("../../Resources/Reworked textures/Drops/Knife.png");
        break;
    case DropType::Axe:
        m_Texture = new Texture("../../Resources/Reworked textures/Drops/AxeDrop.png");
        break;
    }
}
Drop::~Drop()
{
    delete m_Texture;
    m_Texture = nullptr;
}

void Drop::Draw(bool IsDebug) const
{
    if (m_Texture->IsCreationOk())
    {
        m_Texture->Draw(m_Pos);
    }

    if (IsDebug)
    {
        utils::SetColor(Color4f(1.f, 0.4f, 0.7f, 1.f));
        utils::DrawRect(Rectf(m_Pos.x, m_Pos.y, m_Hitbox.width, m_Hitbox.height));
    }
}

void Drop::Update(float elapsedSec)
{
    float newY = m_Pos.y + m_GravityAcceleration * elapsedSec;

    if (!GameManager::DoesCollideWithBlock(Rectf(m_Pos.x, newY, m_Hitbox.width, m_Hitbox.height)))
    {
        m_Pos.y = newY;
    }
}

Rectf Drop::GetHitBox() const
{
    return(Rectf(m_Pos.x, m_Pos.y, m_Hitbox.width, m_Hitbox.height));
}

Drop::DropType Drop::GetType() const
{
    return m_DropType;
}