#pragma once
#include "utils.h"
#include "Entity.h"

class CutsceneTrigger : public Entity
{
public:
    CutsceneTrigger(const Vector2f& triggerPos, const Rectf& triggerArea, const Rectf& newCameraBox, const Vector2f& NewSpawnPoint);

    CutsceneTrigger(const Vector2f& triggerPos, const Rectf& triggerArea, const Rectf& newCameraBox, const Vector2f& NewSpawnPoint, const Vector2f& NewPlayerPos);

    void Update(float elapsedSec) override final;
    void Draw(bool IsDebug) const override final;

    Rectf GettriggerArea() const;
    Rectf GetnewCameraAim() const;
    Vector2f GetNewSpawnPoint() const;

    bool GetDoesTeleport() const;

    Vector2f GetNewPlayerPos() const;

private:
    const Rectf m_TriggerArea;
    const Rectf m_NewCameraBox;
    const Vector2f m_NewSpawnPoint;
    const Vector2f m_NewPlayerPos;

    bool m_DoesTeleport;

};

