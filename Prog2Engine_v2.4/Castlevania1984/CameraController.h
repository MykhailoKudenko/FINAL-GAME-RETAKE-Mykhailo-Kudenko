#pragma once
#include "Texture.h"
#include "utils.h"
#include <iostream>

class CameraController
{
public:


	CameraController(float screenWidth, float screenHeight);

	void Aim(float levelW, float levelH, float startX, float startY, Vector2f trackCenter);

	void Reset();
private:

	const float m_ScreenWidth;
	const float m_ScreenHeight;
};
