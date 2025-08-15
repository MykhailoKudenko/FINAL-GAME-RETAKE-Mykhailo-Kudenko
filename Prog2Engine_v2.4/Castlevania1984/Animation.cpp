#include "pch.h"
#include "Animation.h"

Animation::Animation(Texture* texture, float xStartOffset, int frameCount, float frameDuration, bool looping)
    : m_Texture(texture)
    , m_FrameCount(frameCount)
    , m_FrameDuration(frameDuration)
    , m_xStartOffset(xStartOffset)
    , m_CurrentFrame(0)
    , m_IsLooping(looping)
    , m_IsFinished(false)
    , m_TimeToNextFrame(0)
{

}

void Animation::Update(float elapsedSec)
{   
    if (!m_IsFinished)
    {
        m_TimeToNextFrame = m_TimeToNextFrame + elapsedSec;
        if (m_TimeToNextFrame >= m_FrameDuration)
        {
            m_TimeToNextFrame = 0;
            m_CurrentFrame++;
            if (m_CurrentFrame >= m_FrameCount)
            {
                if (m_IsLooping)
                {
                    m_CurrentFrame = 0;
                }
                else
                {
                    m_IsFinished = true;
                    m_CurrentFrame = m_FrameCount - 1;
                }

            }
        }
    }
}

void Animation::Draw(const Vector2f& position, bool isFlipped) const
{
    float frameWidth = (m_Texture->GetWidth() - m_xStartOffset) / m_FrameCount;
    Rectf textureSource = Rectf(m_xStartOffset + frameWidth * m_CurrentFrame, 0, frameWidth, m_Texture->GetHeight());
    Rectf textureDestination = Rectf(position.x, position.y, frameWidth, m_Texture->GetHeight());

    

    if (isFlipped)
    {
        glPushMatrix();
        glTranslatef(textureDestination.left + textureDestination.width, textureDestination.bottom, 0);
        glScalef(-1, 1, 1); 
        m_Texture->Draw(Rectf(0, 0, frameWidth, textureDestination.height), textureSource);
        glPopMatrix();
    }
    else
    {
        m_Texture->Draw(textureDestination, textureSource);
    }

    

}

void Animation::Reset()
{
    m_CurrentFrame = 0;
    m_IsFinished = false;
    m_TimeToNextFrame = 0;
}

bool Animation::IsFinished() const
{
    return(m_IsFinished);
}
