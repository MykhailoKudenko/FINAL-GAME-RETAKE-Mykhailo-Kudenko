#pragma once
#include "Entity.h"

#include "Projectile.h"
#include "Drop.h"
#include "Stairs.h"


class Player : public Entity {

    friend class Hud;

public:
    Player(const Vector2f& startPos, std::vector<Projectile*>& projectiles);

    void Update(float elapsedSec) override;

    void Draw(bool IsDebug) const override;

    void TakeDamage();

    Rectf GetHitbox() const;

    void TakeDrop(Drop::DropType drop);

    bool IsOnStairs();
    bool IsDead();

    void EnterStairs(Stairs* stairs);

    void Revive(const Vector2f& revivePos);

    void Teleport(const Vector2f& NewPos);

    static void LoadTextures();
    static void FreeTextures();

private:

    static Texture* s_PlayerAccend;
    static Texture* s_PlayerDecend;
    static Texture* s_PlayerJumpDuck;
    static Texture* s_PlayerDeath;
    static Texture* s_PlayerWalk;
    static Texture* s_PlayerWhipAttack;

    Animation m_AccendAnimation;
    Animation m_DecendAnimation;
    Animation m_WalkAnimation;
    Animation m_DeathAnimation;

    void OnStairsUpdate(float elapsedSec);
    void DrawMirrored(Texture* pTexture, const Vector2f& destPos, const Rectf& srcRect) const;

    float const m_InvonurabilityMax = 1;
    float m_InvonurabilityCurrent = 0;
    float const m_StunMax = 0.5;
    float m_StunCurrent = 0;

    float const m_KnockbackSpeed = 45;
    float const m_playerSpeed = 45 *1;
    float const m_playerStairSpeed = 45;
    float const m_GravityAcceleration = -45;
    float const m_JumpSpeed = 125;

    int m_Health = 16;



    Rectf const m_Hitbox = Rectf(0.f, 0.f, 16.f, 32.f);

    Stairs* m_CurrentStair = nullptr;

    int m_LastXDir;
    float m_ProjectileCooldownCurrent = 0.f;
    const float m_ProjectileCooldownMax = 0.5f;
    float m_WhipCooldownCurrent = 0.f;
    const float m_WhipCooldownMax = 0.3f;
    float m_JumpTimeCurrent = 0.f;
    const float m_JumpTimeMax = 0.3f;

    float m_DeathReturnDelay = 1.2;

    std::vector<Projectile*>& m_Projectiles;

    int m_NumberofHearts;

    bool m_DoesHaveanAxe;
    bool m_DoeshaveaKnife;

    bool m_IsOnStairs;
    bool m_isDead;
    bool m_IsOnTheGround;

    bool m_IsMoving;
};
