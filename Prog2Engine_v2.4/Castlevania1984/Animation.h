#pragma once
#include "Texture.h"

class Animation
{
public:
    Animation(Texture* texture,float xStartOffset, int frameCount, float frameDuration, bool looping = true);
    void Update(float elapsedSec);
    void Draw(const Vector2f& position, bool isFlipped) const;
    void Reset();
    bool IsFinished() const;
    //Animation(Texture* texture,float xStartOffset, int frameCount, float frameDuration, const Rectf& frameSize, bool looping = true);
private:
    Texture* m_Texture;
    const int m_FrameCount;
    const float m_FrameDuration;
    const float m_xStartOffset;
    

    int m_CurrentFrame;
    float m_TimeToNextFrame;
    
    bool m_IsLooping;
    bool m_IsFinished;
};

