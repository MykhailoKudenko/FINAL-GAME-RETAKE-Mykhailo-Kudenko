#pragma once

#include "utils.h"

#include "Entity.h"
#include "Player.h"
#include "Block.h"
#include "CameraController.h"

#include "Hud.h"


#include "Enemy.h"
#include "Zombie.h"
#include "Bat.h"
#include "Dog.h"
#include "FishMan.h"
#include "Boss.h"

#include "Projectile.h"
#include "Whip.h"
#include "Knife.h"
#include "Axe.h"

#include "Drop.h"


#include "Stairs.h"
#include "CutsceneTrigger.h"



#include "Chest.h"
#include "FirePlace.h"
#include "Candle.h"

#include "LevelTexture.h"

class GameManager
{

public:
    GameManager();
    ~GameManager();

    void Update(float elapsedSec);
    void Draw() const;

    //void LoadLevel(const std::string& levelFilePath);
    bool static DoesCollideWithBlock(const Rectf& rect);
private:

     void SpawnLevelTexturesAndBlocks();


     void SpawnEnemiesAndChests();
     void ClearEnemiesAndChests();

     
     void UpdateStairs(float elapsedSec);
     void UpdateEnemies(float elapsedSec);
     void UpdateDrops(float elapsedSec);
     void UpdateProjectiles(float elapsedSec);
     void UpdateChests(float elapsedSec);
     void UpdateCutSceneTriggers(float elapcedSec);
     void UpdateBoss(float elapcedSec);

     void InputManager(float elapcedSec);

     Texture* m_MenuTexture;
     Animation m_MenuAnimation;

     CameraController* m_CameraController;



     Player* m_Player;

     Rectf m_CameraAim;

     Vector2f m_RespawnPos;

     Hud* m_Hud;

     

     static std::vector<Block*> m_Blocks;
     std::vector<Stairs*> m_Stairs;
     std::vector <LevelTexture*> m_LevelTextures;
     std::vector <CutsceneTrigger*> m_CutsceneTriggeres;

     std::vector<Enemy*> m_Enemies;
     std::vector<Drop*> m_Drops;
     std::vector<Projectile*> m_Projectiles;
     std::vector<Chest*> m_Chests;
  
     Boss* m_Boss;

     bool m_Inmenu;
     bool m_InDebug;
};

