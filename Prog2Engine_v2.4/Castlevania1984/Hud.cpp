#include "pch.h"
#include "Hud.h"



Hud::Hud()
    : m_pPlayer(nullptr), m_TextCurrentHp(nullptr), m_TextCurrentLives(nullptr)
{
    
    m_HudTexture = new Texture("../../Resources/Reworked textures/Menu/UpBar.png");
    m_KnifeTexture = new Texture("../../Resources/Reworked textures/Drops/Knife.png");
    m_AxeTexture = new Texture("../../Resources/Reworked textures/Drops/AxeDrop.png");

    m_HasAxe = false; 
    m_HasKnife = false;
    m_NumberOfLives = 3;
}

Hud::~Hud()
{
    delete m_TextCurrentHp;
    m_TextCurrentHp = nullptr;

    delete m_TextCurrentLives;
    m_TextCurrentLives = nullptr;

    delete m_HudTexture;
    m_HudTexture = nullptr;

    delete m_KnifeTexture;
    m_KnifeTexture = nullptr;

    delete m_AxeTexture;
    m_AxeTexture = nullptr;

}

void Hud::SetPlayer(Player* player)
{
    m_pPlayer = player;
}

void Hud::Update(float)
{
    if (!m_pPlayer) return;

    delete m_TextCurrentHp;
    m_TextCurrentHp = new Texture(std::to_string(m_pPlayer->m_NumberofHearts),"../../Resources/Reworked textures/Words/DIN-Light.otf",25,Color4f{ 1,1,1,1 });

    delete m_TextCurrentLives;
    m_TextCurrentLives = new Texture(std::to_string(m_NumberOfLives), "../../Resources/Reworked textures/Words/DIN-Light.otf", 25, Color4f{ 1,1,1,1 });

}

void Hud::Draw() const
{
    if (!m_pPlayer) return;

    utils::SetColor(Color4f{ 0, 0, 0, 1 });
    utils::FillRect(0, 768, 1024, 416);
   
    m_HudTexture->Draw(Rectf(0, 768, 1024, 116));

    
    utils::SetColor(Color4f{ 1, 0, 0, 1 });
    utils::FillRect(Rectf(200, 816, 1 + 15 * m_pPlayer->m_Health, 24));

    
    if (m_TextCurrentHp)
    {
        m_TextCurrentHp->Draw(Vector2f(720, 810));
    }

    if (m_TextCurrentLives)
    {
        m_TextCurrentLives->Draw(Vector2f(720, 775));
    }

    

    if (m_HasAxe)
    {
        
        m_AxeTexture->Draw(Rectf(530, 773, 15 * 4, 14 * 4));

    }
    else if (m_HasKnife)
    {

        m_KnifeTexture->Draw(Rectf(530, 780, 16 * 4, 9 * 4));
        
    }

    

}

void Hud::TakeNumberOfLives(int lives)
{
    m_NumberOfLives = lives;
}


void Hud::TakeDrop(Drop::DropType drop)
{
    switch (drop)
    {
    case Drop::DropType::Knife:
        m_HasAxe = false;
        m_HasKnife = true;
        break;
    case Drop::DropType::Axe:
        m_HasAxe = true;
        m_HasKnife = false;
        break;
    }

   
}

void Hud::Resetweapon()
{
    m_HasAxe = false;
    m_HasKnife = false;
}