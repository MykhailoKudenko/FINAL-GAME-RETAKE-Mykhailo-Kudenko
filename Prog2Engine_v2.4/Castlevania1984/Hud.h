#pragma once
#include "Player.h"



class Hud
{
public:
    Hud();

    ~Hud();

    void Draw() const;
    void Update(float elapsedSec);
    void SetPlayer(Player* player); 
    void TakeDrop(Drop::DropType drop);

private:
    Player* m_pPlayer;

    Texture* m_HudTexture;

    Texture* m_TextCurrentHp;

    Texture* m_KnifeTexture;
    Texture* m_AxeTexture;

    bool m_HasAxe;

    bool m_HasKnife;
};

