#include "pch.h"
#include "Boss.h"
#include "GameManager.h"

Texture* Boss::s_BossTexture = nullptr;
int Boss::s_MaxHp = 16;
float Boss::m_m_InvincibilityMax = 0.5;

Boss::Boss(const Vector2f& startPos, const Rectf& triggerArea)
    : Enemy(startPos, 70.f, Rectf(0, 0, 48, 22)),
    m_FightBox{ triggerArea },
    m_State(State::Sitting),
    m_InvincibilityCurrent(0.f),
    m_TextureChangeTimer(0.f),
    m_Hp(s_MaxHp),
    m_SlowSpeed(70.f),
    m_FastSpeed(300.f),
    m_Animation(s_BossTexture, 48, 2, 0.2)
{
    m_TargetPoint.x = static_cast<float>(std::rand() % static_cast<int>(m_FightBox.width)) + m_FightBox.left;
    m_TargetPoint.y = static_cast<float>(std::rand() % static_cast<int>(m_FightBox.height)) + m_FightBox.bottom;
}

Boss::~Boss()
{
    
}

void Boss::LoadTexture()
{
    if (!s_BossTexture)
    {
        s_BossTexture = new Texture("../../Resources/Reworked textures/Enemies/Boss.png"); 
    }
}

void Boss::FreeTexture()
{
    delete s_BossTexture;
    s_BossTexture = nullptr;
}

void Boss::Draw(bool IsDebug) const
{
    if (m_State == State::Sitting)
    {
        s_BossTexture->Draw(Vector2f(m_Pos.x, m_Pos.y), Rectf{0, 0, 48, 23});
    }
    else
    {
        m_Animation.Draw(m_Pos, false);
    }

    if (IsDebug)
    {
        
        utils::SetColor(Color4f(0, 1, 0, 1));
        utils::DrawRect(m_FightBox);
        utils::DrawRect(GetHitbox());
    }
    
}

void Boss::DrawHp() const
{
    utils::SetColor(Color4f(1, 0.75f, 0.8f, 1));
    utils::FillRect(Rectf(200, 783, 1 + 15 * m_Hp, 24));
}

Rectf Boss::GetTrigger() const
{
    return(m_FightBox);
}

void Boss::Update(float elapsedSec)
{
    switch (m_State)
    {
    case State::Sitting:
        break;

    case State::MovingToPoint:
        MoveToTarget(elapsedSec, m_TargetPoint, m_SlowSpeed, State::ChasingPlayer);
        break;

    case State::ChasingPlayer:
        MoveToTarget(elapsedSec, m_PlayerPos, m_FastSpeed, State::MovingToPoint);
        break;
    }

    if (m_InvincibilityCurrent > 0.f)
        m_InvincibilityCurrent -= elapsedSec;

    m_Animation.Update(elapsedSec);
}

void Boss::MoveToTarget(float elapsedSec, const Vector2f& target, float speed, State nextState)
{
    Vector2f direction = target - m_Pos;
    float distance = direction.Length();

    if (distance > 1.f)
        m_Pos += direction.Normalized() * speed * elapsedSec;
    else
    {
        m_Pos = target;
        m_State = nextState;

        m_TargetPoint.x = static_cast<float>(std::rand() % static_cast<int>(m_FightBox.width)) + m_FightBox.left;
        m_TargetPoint.y = static_cast<float>(std::rand() % static_cast<int>(m_FightBox.height)) + m_FightBox.bottom;
    }
}

void Boss::Activate()
{
    if (m_State == State::Sitting)
    {
        m_State = State::MovingToPoint;
    }
}
void Boss::TakeDamage()
{
    if (m_InvincibilityCurrent <= 0.f)
    {
        m_Hp = m_Hp - 1;
        m_InvincibilityCurrent = m_m_InvincibilityMax;
    }
    
}
bool Boss::IsDead()
{
    if (m_Hp <= 0)
    {
        return(true);
    }
    else 
    {
        return(false);
    }
}

void Boss::SetPlayerPos(const Vector2f& PlayerPos)
{
    m_PlayerPos = PlayerPos;
}


