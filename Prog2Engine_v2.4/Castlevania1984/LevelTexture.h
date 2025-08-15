#pragma once
#include "Entity.h"

class LevelTexture : public Entity
{
public:
    explicit LevelTexture(const Vector2f& pos, const std::string& filepath);
    ~LevelTexture(); 

    void Draw(bool IsDebug) const;
    void Update(float elapsedSec) override;

private:
    
    Texture* m_Texture;
    
   
};

