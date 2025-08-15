#include "pch.h"
#include "CutsceneTrigger.h"

CutsceneTrigger::CutsceneTrigger(const Vector2f& triggerPos, const Rectf& triggerArea, const Rectf& newCameraBox, const Vector2f& NewSpawnPoint)
	:m_TriggerArea(triggerArea)
	, m_NewCameraBox(newCameraBox)
	, m_NewSpawnPoint(NewSpawnPoint)
	, m_NewPlayerPos(Vector2f{0,0})
{
	m_Pos = triggerPos;
	m_DoesTeleport = false;
}

CutsceneTrigger::CutsceneTrigger(const Vector2f& triggerPos, const Rectf& triggerArea, const Rectf& newCameraBox, const Vector2f& NewSpawnPoint, const Vector2f& NewPlayerPos)
	:m_TriggerArea(triggerArea)
	, m_NewCameraBox(newCameraBox)
	, m_NewSpawnPoint(NewSpawnPoint)
	, m_NewPlayerPos(NewPlayerPos)
{
	m_Pos = triggerPos;
	m_DoesTeleport = true;
}



void CutsceneTrigger::Update(float elapsedSec)
{
	
}
void CutsceneTrigger::Draw(bool IsDebug) const
{
	//debug
	utils::SetColor(Color4f(1, 0, 0, 1));
	utils::DrawRect(GettriggerArea());
	utils::DrawLine(m_Pos, m_NewSpawnPoint);
}

bool CutsceneTrigger::GetDoesTeleport() const
{
	return(m_DoesTeleport);
}

Rectf CutsceneTrigger::GettriggerArea() const
{
	
	return(Rectf{ m_Pos.x, m_Pos.y, m_TriggerArea.width, m_TriggerArea.height });
}
Rectf CutsceneTrigger::GetnewCameraAim() const
{
	return(m_NewCameraBox);
}
Vector2f CutsceneTrigger::GetNewSpawnPoint() const
{
	return(m_NewSpawnPoint);
}

Vector2f CutsceneTrigger::GetNewPlayerPos() const
{
	return(m_NewPlayerPos);
}