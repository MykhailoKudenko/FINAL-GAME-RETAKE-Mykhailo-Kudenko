#pragma once
#include "Enemy.h"
#include "Animation.h"

class Boss : public Enemy
{
public:
    Boss(const Vector2f& startPos, const Rectf& triggerArea);
    ~Boss();

    void Update(float elapsedSec) override final;
    void Draw(bool IsDebug) const override final;
    void DrawHp() const;

    void Activate();
    void TakeDamage();
    bool IsDead();
    void SetPlayerPos( const Vector2f& PlayerPos);
    Rectf GetTrigger() const;

    static void LoadTexture();
    static void FreeTexture();

private:

   

    Animation m_Animation;

    enum class State
    {
        Sitting,
        MovingToPoint,
        ChasingPlayer
    };

    void MoveToTarget(float elapsedSec, const Vector2f& target, float speed, State nextState);

    static Texture* s_BossTexture;


    const Rectf m_FightBox;
    State m_State;
    Vector2f m_TargetPoint;
    Vector2f m_PlayerPos;

    float m_InvincibilityCurrent;
    static float m_m_InvincibilityMax;
    float m_TextureChangeTimer;
    int m_Hp;

    const float m_SlowSpeed;
    const float m_FastSpeed;

    static int s_MaxHp;

    
};

