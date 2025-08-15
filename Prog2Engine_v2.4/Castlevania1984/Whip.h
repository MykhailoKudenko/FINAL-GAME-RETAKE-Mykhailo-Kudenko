#pragma once
#include "Projectile.h"

class Whip : public Projectile 
{
public:
    Whip(const Vector2f& pos);

    void Update(float elapsedSec) override;
    void Draw(bool IsDebug) const override;

    

private:
   
};

