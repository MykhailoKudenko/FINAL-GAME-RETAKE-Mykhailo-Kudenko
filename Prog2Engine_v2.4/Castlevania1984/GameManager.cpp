#include "pch.h"
#include "GameManager.h"

GameManager::GameManager() : 
    m_MenuTexture (new Texture("../../Resources/Reworked textures/Menu/MainMenu.png"))
    ,m_MenuAnimation(m_MenuTexture, 0, 2, 0.2, true)
{
    Axe::LoadTexture();
    Knife::LoadTexture();

    Zombie::LoadTexture();
    Bat::LoadTexture();
    Dog::LoadTexture();
    FishMan::LoadTexture();

    FirePlace::LoadTexture();
    Candle::LoadTexture();
    Boss::LoadTexture();
    Player::LoadTextures();


    m_RespawnPos = Vector2f{ 20.f, 30.f };
    m_Player = new Player(m_RespawnPos, m_Projectiles);
    
    m_Hud = new Hud();

    m_Hud->SetPlayer(m_Player);


    SpawnLevelTexturesAndBlocks();
    
    SpawnEnemiesAndChests();

    m_CameraController = new CameraController(256.f * 1, 240.f * 1);

    

    m_CameraAim = Rectf{ 0, 0, 768, 10000 };

    m_Inmenu = true;
    m_InDebug = false;
    LivesLeft = 3;
    
}

void GameManager::SpawnLevelTexturesAndBlocks()
{

    
    m_CutsceneTriggeres.push_back(new CutsceneTrigger{ Vector2f(660, 0 ),Rectf(0, 0, 100, 200), Rectf(768, 8, 1536, 10000), Vector2f(800, 38), Vector2f(800, 38) });
    m_CutsceneTriggeres.push_back(new CutsceneTrigger{ Vector2f(768 + 1500, 100),Rectf(0, 0, 20, 200), Rectf(768 + 1536, 8, 512, 10000), Vector2f(768 + 1500+50, 130), Vector2f(768 + 1500+50, 130) });

    m_CutsceneTriggeres.push_back(new CutsceneTrigger{ Vector2f(768 + 1500 + 50, 100),Rectf(0, 0, 50, 50), Rectf(768 + 1536, 8, 512, 10000), Vector2f(768 + 1500 + 50, 130)});

    m_CutsceneTriggeres.push_back(new CutsceneTrigger{ Vector2f(2330, 25),Rectf(0, 0, 20, 10), Rectf(768 + 1536, 8, 512, 10000), Vector2f(768 + 1500 + 50, 130) });
    m_CutsceneTriggeres.push_back(new CutsceneTrigger{ Vector2f(2650, 25),Rectf(0, 0, 20, 10), Rectf(768 + 1536, 8, 512, 10000), Vector2f(768 + 1500 + 50, 130) });

    m_CutsceneTriggeres.push_back(new CutsceneTrigger{ Vector2f(2330 + 30, 25 - 30),Rectf(0, 0, 20, 10), Rectf(768 + 1536, -192 + 8, 512, 192), Vector2f(768 + 1500 + 50, 130) });
    m_CutsceneTriggeres.push_back(new CutsceneTrigger{ Vector2f(2650 + 30, 25 - 30),Rectf(0, 0, 20, 10), Rectf(768 + 1536, -192 + 8, 512, 192), Vector2f(768 + 1500 + 50, 130) });

    m_CutsceneTriggeres.push_back(new CutsceneTrigger{ Vector2f(768 + 1500+ 512, 100),Rectf(0, 0, 20, 200), Rectf(768 + 1536 + 512, 8, 768 ,10000 ), Vector2f(768 + 1500 + 50 + 512, 130), Vector2f(768 + 1500 + 50 + 512, 130) });

    m_CutsceneTriggeres.push_back(new CutsceneTrigger{ Vector2f(3300 ,20),  Rectf{ 3300, 20, 280, 180 },  Rectf{ 3300, 20, 280, 180 }, Vector2f(768 + 1500 + 50 + 512, 130) });

   

    //real stuff
    m_LevelTextures.push_back(new LevelTexture{ Vector2f(0, 0), "../../Resources/Reworked textures/Levels/Enterance.png" });
    m_LevelTextures.push_back(new LevelTexture(Vector2f(768, 8), "../../Resources/Reworked textures/Levels/Hall.png"));
    m_LevelTextures.push_back(new LevelTexture(Vector2f(768+1536, 8), "../../Resources/Reworked textures/Levels/CryptA.png"));
    m_LevelTextures.push_back(new LevelTexture(Vector2f(768 + 1536, -192 +8), "../../Resources/Reworked textures/Levels/CryptB.png"));
    m_LevelTextures.push_back(new LevelTexture(Vector2f(768 + 1536+512, 8), "../../Resources/Reworked textures/Levels/PhantomBat.png"));

    //betweel levels
    m_Blocks.push_back(new Block{ Vector2f(768 + 200 - 50 - 200, 10), Rectf(0, 0, 50, 192)});
    m_Blocks.push_back(new Block{ Vector2f(768 + 200 + 1536 - 10 - 200, -300), Rectf(0, 0, 20, 492)});
    m_Blocks.push_back(new Block{ Vector2f(768 + 200 + 1536 - 10 + 512 - 200, -300), Rectf(0, 0, 20, 492)});
    m_Blocks.push_back(new Block{ Vector2f(768 + 200 + 1536 - 10 + 512 + 768 - 200, -300), Rectf(0, 0, 20, 492)});

    m_Blocks.push_back(new Block{ Vector2f(0 , 0), Rectf(0, 0, 3780 - 1, 23)});
    m_Blocks.push_back(new Block{ Vector2f(-20 , 0), Rectf(0, 0, 20, 200)});

    m_Blocks.push_back(new Block{ Vector2f(1655 - 200, 75), Rectf(0, 0, 48, 15)}); // lvl1 platform 1
    m_Blocks.push_back(new Block{ Vector2f(1720 - 200, 106), Rectf(0, 0, 160, 15)}); // lvl1 platform 2
    m_Blocks.push_back(new Block{ Vector2f(1895 - 200, 75), Rectf(0, 0, 96, 15)}); // lvl1 platform 3
    m_Blocks.push_back(new Block{ Vector2f(2360 - 200, 106), Rectf(0, 0, 16 * 17, 15) }); // lvl1 platform 5

    m_Blocks.push_back(new Block{ Vector2f(2630 - 200, 75), Rectf(0, 0, 48, 15) }); // lvl2 platform 1
    m_Blocks.push_back(new Block{ Vector2f(2760 - 200, 25), Rectf(0, 0, 64, 80)}); // lvl2 wall
    m_Blocks.push_back(new Block{ Vector2f(2823 - 200, 91), Rectf(0, 0, 32, 15)}); // lvl2 platform 2
    m_Blocks.push_back(new Block{ Vector2f(2855 - 200, 75), Rectf(0, 0, 48, 15)}); // lvl2 platform 3
    m_Blocks.push_back(new Block{ Vector2f(2920 - 200, 106), Rectf(0, 0, 16 * 13, 15)}); // lvl2 platform 4

    m_Blocks.push_back(new Block{ Vector2f(2632 - 200 - 32, -70), Rectf(0, 0, 32, 15)}); // lvl3 platform 1
    m_Blocks.push_back(new Block{ Vector2f(2520 - 200 - 32, -103), Rectf(0, 0, 48 * 5, 15)}); // lvl3 platform 2
    m_Blocks.push_back(new Block{ Vector2f(2792 - 200 - 32, -103), Rectf(0, 0, 32, 15)}); // lvl3 platform 3
    m_Blocks.push_back(new Block{ Vector2f(2856 - 200 - 32, -103), Rectf(0, 0, 160, 15)}); // lvl3 platform 4

    // lvl4
    m_Blocks.push_back(new Block{ Vector2f(3145 - 200, 75), Rectf(0, 0, 176, 15)}); // lvl4 platform 1
    m_Blocks.push_back(new Block{ Vector2f(3687 - 200, 42), Rectf(0, 0, 32, 15)}); // lvl4 platform 2
    m_Blocks.push_back(new Block{ Vector2f(3735 - 200, 75), Rectf(0, 0, 48, 15)}); // lvl4 platform 3

    //Stairs

    m_Stairs.push_back(new Stairs{ Rectf(1380, 25, 20, 10), Rectf(1450, 90, 20, 10) }); // lvl1 stairs 1
    m_Stairs.push_back(new Stairs{ Rectf(1480, 90, 20, 10), Rectf(1515, 120, 20, 10) }); // lvl1 stairs 2
    m_Stairs.push_back(new Stairs{ Rectf(1660, 120, 20, 10),Rectf(1695, 90, 20, 10) }); // lvl1 stairs 3 Rectf(1695, 90, 20, 10)
    m_Stairs.push_back(new Stairs{ Rectf(2060, 25, 20, 10), Rectf(2150, 120, 20, 10) }); // lvl1 stairs 4

    m_Stairs.push_back(new Stairs{ Rectf(2330, 22, 20, 10), Rectf(2420 - 20, -55, 20, 10) }); // lvl2 stairs1 down 
    m_Stairs.push_back(new Stairs{ Rectf(2650, 22, 20, 10), Rectf(2770 - 20, -88, 20, 10) }); // lvl2 stairs2 down 
    m_Stairs.push_back(new Stairs{ Rectf(2685, 90, 20, 10), Rectf(2760, 24, 20, 10) }); // lvl2 stairs1 up
    m_Stairs.push_back(new Stairs{ Rectf(2455, 90, 20, 10), Rectf(2530, 24, 20, 10) }); // lvl2 stairs2 up

    m_Stairs.push_back(new Stairs{ Rectf(2910, 120, 20, 10), Rectf(2950, 90, 20, 10) }); // lvl4 stairs 1
    m_Stairs.push_back(new Stairs{ Rectf(3105, 90, 20, 10), Rectf(3170, 24, 20, 10) }); // lvl4 stairs 2
    m_Stairs.push_back(new Stairs{ Rectf(3535, 90, 20, 10), Rectf(3490, 55, 20, 10) }); // lvl4 stairs 3


   
}

void GameManager::SpawnEnemiesAndChests()
{
    m_Enemies.push_back(new Zombie{ Vector2f(1170, 35) });
    m_Enemies.push_back(new Zombie{ Vector2f(1220, 35) });
    m_Enemies.push_back(new Zombie{ Vector2f(1270, 35) });

    m_Enemies.push_back(new Zombie{ Vector2f(1400, 35) });
    m_Enemies.push_back(new Zombie{ Vector2f(1450, 35) });

    m_Enemies.push_back(new Zombie{ Vector2f(1600, 35) });
    m_Enemies.push_back(new Zombie{ Vector2f(1650, 35) });

    m_Enemies.push_back(new Zombie{ Vector2f(2000, 35) });
    m_Enemies.push_back(new Zombie{ Vector2f(2050, 35) });

    m_Enemies.push_back(new Zombie{ Vector2f(2200, 35) });

    m_Enemies.push_back(new Dog{ Vector2f(1470, 93) });
    m_Enemies.push_back(new Dog{ Vector2f(1570, 123) });
    m_Enemies.push_back(new Dog{ Vector2f(1750, 93) });

    m_Enemies.push_back(new Bat{ Vector2f(2750 -300, 123) });
    m_Enemies.push_back(new Bat{ Vector2f(2950 - 300, 50) });
    m_Enemies.push_back(new Bat{ Vector2f(2850 - 300, 50) });


    m_Enemies.push_back(new FishMan{ Vector2f(2450, -120) });
    m_Enemies.push_back(new FishMan{ Vector2f(2470, -120) });

    m_Enemies.push_back(new FishMan{ Vector2f(2630, -120) });
    m_Enemies.push_back(new FishMan{ Vector2f(2650, -120) });
    

    m_Enemies.push_back(new Zombie{ Vector2f(2850, 35) });
    m_Enemies.push_back(new Zombie{ Vector2f(2900, 35) });
    m_Enemies.push_back(new Zombie{ Vector2f(3000, 35) });
    m_Enemies.push_back(new Zombie{ Vector2f(3050, 35) });

    m_Enemies.push_back(new Zombie{ Vector2f(2950, 93) });
    m_Enemies.push_back(new Zombie{ Vector2f(3100, 93) });


    //Chests
    m_Chests.push_back(new FirePlace{ Vector2f(70, 25), Drop::DropType::HeartBig });
    m_Chests.push_back(new FirePlace{ Vector2f(170, 25), Drop::DropType::HeartBig });
    m_Chests.push_back(new FirePlace{ Vector2f(270, 25), Drop::DropType::HeartBig });
    m_Chests.push_back(new FirePlace{ Vector2f(370, 25), Drop::DropType::HeartBig });
    m_Chests.push_back(new FirePlace{ Vector2f(470, 25), Drop::DropType::HeartBig });

    m_Chests.push_back(new Candle{ Vector2f(1070, 35), Drop::DropType::HeartSmall });
    m_Chests.push_back(new Candle{ Vector2f(1270, 35), Drop::DropType::Knife });
    m_Chests.push_back(new Candle{ Vector2f(1470, 35), Drop::DropType::HeartSmall });
    m_Chests.push_back(new Candle{ Vector2f(1670, 35), Drop::DropType::HeartSmall });
    m_Chests.push_back(new Candle{ Vector2f(1870, 35), Drop::DropType::Axe });
    m_Chests.push_back(new Candle{ Vector2f(2070, 35), Drop::DropType::HeartBig });
    m_Chests.push_back(new Candle{ Vector2f(2270, 35), Drop::DropType::HeartSmall });
    m_Chests.push_back(new Candle{ Vector2f(2470, 35), Drop::DropType::HeartSmall });

    m_Chests.push_back(new Candle{ Vector2f(1470 + 1500, 35), Drop::DropType::Axe });
    m_Chests.push_back(new Candle{ Vector2f(1670 + 1500, 35), Drop::DropType::HeartSmall });
    m_Chests.push_back(new Candle{ Vector2f(1870 + 1500, 35), Drop::DropType::HeartSmall });
    m_Chests.push_back(new Candle{ Vector2f(2070 + 1500, 35), Drop::DropType::HeartBig });
    m_Chests.push_back(new Candle{ Vector2f(2270 + 1500, 35), Drop::DropType::HeartSmall });
    m_Chests.push_back(new Candle{ Vector2f(2470 + 1500, 35), Drop::DropType::HeartSmall });


    m_Boss = new Boss{ Vector2f(3400, 150), Rectf{ 3300, 20, 280, 180 } };
}


void GameManager::ClearEnemiesAndChests()
{
    for (Enemy* enemy : m_Enemies)
    {
        delete enemy;
    }
    m_Enemies.clear();

    for (Drop* p : m_Drops)
    {
        delete p;
    }
    m_Drops.clear();


    for (Chest* p : m_Chests)
    {
        delete p;
    }
    m_Chests.clear();

    delete m_Boss;
    m_Boss = nullptr;
}

GameManager::~GameManager()
{
    delete m_Boss;
    m_Boss = nullptr;

    delete m_MenuTexture;
    m_MenuTexture = nullptr;

    delete m_CameraController;
    m_CameraController = nullptr;

    delete m_Player;
    m_Player = nullptr;
    
    delete m_Hud;
    m_Hud = nullptr;

    for (Block* b : m_Blocks)
        delete b;
    m_Blocks.clear();

    for (Enemy* e : m_Enemies)
        delete e;
    m_Enemies.clear();

    for (Projectile* p : m_Projectiles)
        delete p;
    m_Projectiles.clear();

    for (Drop* p : m_Drops)
        delete p;
    m_Drops.clear();

    for (Stairs* p : m_Stairs)
        delete p;
    m_Stairs.clear();

    for (Chest* p : m_Chests)
        delete p;
    m_Chests.clear();

    for (LevelTexture* p : m_LevelTextures)
            delete p;
    m_LevelTextures.clear();

    for (CutsceneTrigger* p : m_CutsceneTriggeres)
        delete p;
    m_CutsceneTriggeres.clear();

    Axe::FreeTexture();
    Knife::FreeTexture();

    Zombie::FreeTexture();
    Bat::FreeTexture();
    Dog::FreeTexture();
    FishMan::FreeTexture();

    FirePlace::FreeTexture();
    Candle::FreeTexture();
    Boss::FreeTexture();

    Player::FreeTextures();
}

void GameManager::Draw() const
{
    if (!m_Inmenu)
    {
        glPushMatrix();

        glScalef(4, 4, 1);

        m_CameraController->Aim(m_CameraAim.width, 10000, m_CameraAim.left, m_CameraAim.bottom, Vector2f(m_Player->GetPos().x + m_Player->GetHitbox().width / 2, m_Player->GetPos().y));

        //m_CameraController->Aim(100000, 100000, 100000, 100000, m_Player->GetPos());
        for (LevelTexture* levelTexture : m_LevelTextures)
        {
            if (levelTexture)
                levelTexture->Draw(m_InDebug);
        }



        if (m_Boss->IsDead() == false)
        {
            m_Boss->Draw(m_InDebug);
        }

        if (m_InDebug)
        {
            for (Block* block : m_Blocks)
            {
                if (block)
                    block->Draw(m_InDebug);

            }

            for (Stairs* stair : m_Stairs)
            {
                if (stair)
                    stair->Draw(m_InDebug);
            }

            for (CutsceneTrigger* CutsceneTrigger : m_CutsceneTriggeres)
            {
                if (CutsceneTrigger)
                    CutsceneTrigger->Draw(m_InDebug);
            }

        }


        for (Drop* drop : m_Drops)
        {
            if (drop)
                drop->Draw(m_InDebug);
        }

        for (Chest* chest : m_Chests)
        {
            if (chest)
                chest->Draw(m_InDebug);
        }

        for (Enemy* enemy : m_Enemies)
        {
            if (enemy)
                enemy->Draw(m_InDebug);
        }

        for (Projectile* projectile : m_Projectiles)
        {
            if (projectile)
                projectile->Draw(m_InDebug);
        }





        m_Player->Draw(m_InDebug);



        m_CameraController->Reset();

        glPopMatrix();

        m_Hud->Draw();
        m_Boss->DrawHp();
    }
    else
    {
        glPushMatrix();

        glScalef(4, 4, 1);
        m_MenuAnimation.Draw(Vector2f(0, 0), false);

        glPopMatrix();
    }
   
    
}

void GameManager::Update(float elapsedSec)
{

    InputManager(elapsedSec);

    if (!m_Inmenu)
    {
        if (m_Player->IsDead() || m_Player->GetPos().y < -200)
        {

            LivesLeft--;


            if (LivesLeft <= 0)
            {
                m_Inmenu = true;
                m_InDebug = false;
                LivesLeft = 3;
                m_RespawnPos = Vector2f{ 20.f, 30.f };
                m_CameraAim = Rectf{ 0, 0, 768, 10000 };

                m_Player->Revive(m_RespawnPos);
                m_Player->ResetNumberOfHearts();
                m_Hud->Resetweapon();

                ClearEnemiesAndChests();

                SpawnEnemiesAndChests();

            }
            else
            {
                m_Player->Revive(m_RespawnPos);

                ClearEnemiesAndChests();

                SpawnEnemiesAndChests();
                

            }
           

           

            m_Hud->TakeNumberOfLives(LivesLeft);
        }



        m_Player->Update(elapsedSec);



        m_Hud->Update(elapsedSec);

        UpdateStairs(elapsedSec);
        UpdateEnemies(elapsedSec);
        UpdateDrops(elapsedSec);
        UpdateProjectiles(elapsedSec);
        UpdateChests(elapsedSec);
        UpdateCutSceneTriggers(elapsedSec);
        UpdateBoss(elapsedSec);
    }
    else
    {
        m_MenuAnimation.Update(elapsedSec);
    }

    



}

void GameManager::UpdateBoss(float elapsedSec)
{
    if (m_Boss->IsDead() == false)
    {
        if (utils::IsOverlapping(m_Boss->GetTrigger(), m_Player->GetHitbox()))
        {
            m_Boss->Activate();
        }

        if (utils::IsOverlapping(m_Boss->GetHitbox(), m_Player->GetHitbox()))
        {
            m_Player->TakeDamage();
        }



        for (Projectile* projectile : m_Projectiles)
        {
            if (utils::IsOverlapping(m_Boss->GetHitbox(), projectile->GetHitbox()))
            {
                m_Boss->TakeDamage();

            }
        }

        m_Boss->Update(elapsedSec);
        m_Boss->SetPlayerPos(m_Player->GetPos());
    }
   
}
void GameManager::UpdateStairs(float elapsedSec)
{
    for (Stairs* stair : m_Stairs)
    {
        if (m_Player->IsOnStairs() == false)
        {
            if (utils::IsOverlapping(stair->GetBottomTrigger(), m_Player->GetHitbox()))
            {
                m_Player->EnterStairs(stair);
            }
            else if (utils::IsOverlapping(stair->GetTopTrigger(), m_Player->GetHitbox()))
            {
                m_Player->EnterStairs(stair);
            }
        }

    }
}
void GameManager::UpdateEnemies(float elapsedSec)
{
    for (Enemy* enemy : m_Enemies)
    {
        if (enemy)
            enemy->Update(elapsedSec);

        if (utils::IsOverlapping(enemy->GetHitbox(), m_Player->GetHitbox()))
        {
            m_Player->TakeDamage();

        }
        Dog* dog = dynamic_cast<Dog*>(enemy);
        if (dog != nullptr)
        {
            if (utils::GetDistance(Vector2f{ enemy->GetHitbox().left, enemy->GetHitbox().bottom }, Vector2f{ m_Player->GetHitbox().left, m_Player->GetHitbox().bottom }) < 150)
            {

                dog->Activate();
            }

        }

        FishMan* fishman = dynamic_cast<FishMan*>(enemy);
        if (fishman != nullptr)
        {
            if (utils::GetDistance(Vector2f{ enemy->GetHitbox().left, enemy->GetHitbox().bottom }, Vector2f{ m_Player->GetHitbox().left, m_Player->GetHitbox().bottom }) < 100)
            {
                
                fishman->Activate();
            }

        }

    }

    for (size_t i = 0; i < m_Enemies.size(); )
    {
        bool WasKilled = false;

        for (Projectile* projectile : m_Projectiles)
        {
            if (projectile && utils::IsOverlapping(projectile->GetHitbox(), m_Enemies[i]->GetHitbox()))
            {
                WasKilled = true;
                break;
            }
        }

        if (WasKilled)
        {
            m_Drops.push_back(new Drop{ m_Enemies[i]->GetPos(),Drop::DropType::HeartSmall });
            delete m_Enemies[i];
            m_Enemies.erase(m_Enemies.begin() + i);
        }
        else
        {
            ++i;
        }
    }
}
void GameManager::UpdateDrops(float elapsedSec)
{
    for (Drop* drop : m_Drops)
    {
        if (drop)
            drop->Update(elapsedSec);
    }
    for (size_t i = 0; i < m_Drops.size(); )
    {
        if (utils::IsOverlapping(m_Drops[i]->GetHitBox(), m_Player->GetHitbox()))
        {
            m_Player->TakeDrop(m_Drops[i]->GetType());
            m_Hud->TakeDrop(m_Drops[i]->GetType());

            delete m_Drops[i];
            m_Drops.erase(m_Drops.begin() + i);
        }
        else
        {
            ++i;
        }
    }
}
void GameManager::UpdateProjectiles(float elapsedSec)
{
    for (Projectile* projectile : m_Projectiles)
    {
        if (projectile)
            projectile->Update(elapsedSec);

    }

    for (size_t i = 0; i < m_Projectiles.size(); )
    {
        if (m_Projectiles[i] && m_Projectiles[i]->IsActive() == false)
        {
            delete m_Projectiles[i];
            m_Projectiles.erase(m_Projectiles.begin() + i);
        }
        else
        {
            ++i;
        }
    }
}
void GameManager::UpdateChests(float elapsedSec)
{
    for (Chest* chest : m_Chests)
    {
        if (chest)
            chest->Update(elapsedSec);


    }

    for (size_t i = 0; i < m_Chests.size(); )
    {
        bool WasKilled = false;

        for (Projectile* projectile : m_Projectiles)
        {
            if (projectile && utils::IsOverlapping(projectile->GetHitbox(), m_Chests[i]->GetHitbox()))
            {
                WasKilled = true;
                break;
            }
        }

        if (WasKilled)
        {

            m_Drops.push_back(new Drop{ m_Chests[i]->GetPos(),m_Chests[i]->GetType() });
            delete m_Chests[i];
            m_Chests.erase(m_Chests.begin() + i);
        }
        else
        {
            ++i;
        }
    }
}
void GameManager::UpdateCutSceneTriggers(float elapcedSec)
{
    for (CutsceneTrigger* Cutscene : m_CutsceneTriggeres)
    {
        
        if (utils::IsOverlapping(Cutscene->GettriggerArea(), m_Player->GetHitbox()))
        {
            m_RespawnPos = Cutscene->GetNewSpawnPoint();
            m_CameraAim = Cutscene->GetnewCameraAim();
            if (Cutscene->GetDoesTeleport())
            {
                m_Player->Teleport(Cutscene->GetNewPlayerPos());
            }

        }

    }
}

void GameManager::InputManager(float elapsedSec)
{
    const Uint8* pStates = SDL_GetKeyboardState(nullptr);

    static bool prevF1State = false;
    bool currentF1State = pStates[SDL_SCANCODE_F1];

    if (m_Inmenu)
    {
        if (pStates[SDL_SCANCODE_RETURN])
        {
            m_Inmenu = false;
        }
    }
    else
    {
        if (currentF1State && !prevF1State) 
        {
            m_InDebug = !m_InDebug;
        }
    }

    prevF1State = currentF1State;
}
std::vector<Block*> GameManager::m_Blocks;

bool GameManager::DoesCollideWithBlock(const Rectf& rect)
{
    for (Block* obj : m_Blocks)
    {
        if (utils::IsOverlapping(obj->GetHitBox(), rect))
        {
            return(true);
        }
    }
    return(false);
}