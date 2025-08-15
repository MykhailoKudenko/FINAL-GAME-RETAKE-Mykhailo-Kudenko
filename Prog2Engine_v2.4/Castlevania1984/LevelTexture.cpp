#include "pch.h"
#include "LevelTexture.h"

LevelTexture::LevelTexture(const Vector2f& pos, const std::string& filepath)
{
    m_Pos = pos;
    m_Texture = new Texture(filepath);
}

LevelTexture::~LevelTexture()
{
    delete m_Texture;
    m_Texture = nullptr;
}

void LevelTexture::Draw(bool IsDebug) const
{
    m_Texture->Draw(m_Pos);
}

void LevelTexture::Update(float elapsedSec)
{

}