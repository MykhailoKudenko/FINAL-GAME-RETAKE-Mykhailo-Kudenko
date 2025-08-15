#include "pch.h"
#include "CameraController.h"

CameraController::CameraController(float screenWidth, float screenHeight)
    : m_ScreenWidth{ screenWidth }, m_ScreenHeight{ screenHeight }
{}

void CameraController::Aim(float levelW, float levelH, float startX, float startY, Vector2f trackCenter)
{
    Vector2f cameraPos;

    // Centeron  player
    cameraPos.x = trackCenter.x - m_ScreenWidth / 2;
    cameraPos.y = trackCenter.y - m_ScreenHeight / 2;

   

    //  X
    if (cameraPos.x < startX)
        cameraPos.x = startX;
    else if (cameraPos.x + m_ScreenWidth > startX + levelW)
        cameraPos.x = startX + levelW - m_ScreenWidth;

    //  Y
    if (cameraPos.y < startY)
        cameraPos.y = startY;
    else if (cameraPos.y + m_ScreenHeight > startY + levelH)
        cameraPos.y = startY + levelH - m_ScreenHeight;

    glPushMatrix();
    glTranslatef(-cameraPos.x, -cameraPos.y, 0);

    
}



void CameraController::Reset() 
{
    glPopMatrix();
}
