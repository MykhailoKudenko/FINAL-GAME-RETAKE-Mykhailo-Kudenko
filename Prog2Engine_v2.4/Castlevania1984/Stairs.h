#pragma once
#include "utils.h"
#include <iostream>

class Stairs
{
public:
    Stairs(const Rectf& bottomTrigger, const Rectf& topTrigger);

    const Rectf& GetBottomTrigger() const;
    const Rectf& GetTopTrigger() const;
    const Vector2f& GetBottomCentre() const;
    const Vector2f& GetTopCentre() const;
    
    void Draw(bool IsDebug) const;

    bool IsInverted() const;

private:
    const Rectf m_BottomTrigger;
    const Vector2f m_BottomCentre;

    const Rectf m_TopTrigger;
    const Vector2f m_TopCentre;
    
};

