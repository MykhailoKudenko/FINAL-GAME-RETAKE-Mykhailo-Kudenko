#include "pch.h"
#include "Stairs.h"

Stairs::Stairs(const Rectf& bottomTrigger, const Rectf& topTrigger):
    m_BottomTrigger (bottomTrigger), m_TopTrigger(topTrigger), 
    m_BottomCentre(Vector2f(bottomTrigger.left + bottomTrigger.width / 2, bottomTrigger.bottom + bottomTrigger.height / 2)),
    m_TopCentre(Vector2f(topTrigger.left + topTrigger.width / 2, topTrigger.bottom + topTrigger.height / 2))
{

}

bool Stairs::IsInverted() const
{

    

    if (m_BottomCentre.y > m_TopCentre.y)
    {
        return(true);
    }
    else
    {
        return(false);
    }
}

void Stairs::Draw(bool IsDebug) const
{
    utils::SetColor(Color4f(1, 1, 0, 1));
    utils::DrawRect(m_BottomTrigger);
    utils::SetColor(Color4f(1, 0.5, 0, 1));
    utils::DrawRect(m_TopTrigger);
    utils::DrawLine(m_BottomCentre, m_TopCentre);
}


const Rectf& Stairs::GetBottomTrigger() const
{
    return m_BottomTrigger;
}

const Rectf& Stairs::GetTopTrigger() const
{
    return m_TopTrigger;
}

const Vector2f& Stairs::GetBottomCentre() const
{
    return m_BottomCentre;
}
const Vector2f& Stairs::GetTopCentre() const
{
    return m_TopCentre;
}

