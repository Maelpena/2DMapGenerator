#pragma once

#include "MapGenerator.h"
#include "stb_perlin.h"
#include <iostream>
#include <chrono>




MapGenerator::MapGenerator(int cellCount) :m_cellCount(cellCount), m_cellSize(20), m_mapSize(m_cellCount* m_cellSize), m_noiseRate(0.06), m_seed(10), m_canSpawnTree(true), m_dungeonSize(5)
{
    m_mapImage.create(m_mapSize, m_mapSize, sf::Color::Green);
    m_groundTile.loadFromFile("./sprite/ground.png");
    m_grassTile.loadFromFile("./sprite/grass.png");
    m_stoneTile.loadFromFile("./sprite/stone.png");
    m_goldTile.loadFromFile("./sprite/goldOre.png");
    m_gravelTile.loadFromFile("./sprite/gravel.png");
    m_diamondTile.loadFromFile("./sprite/diamond.png");
    m_treeTile.loadFromFile("./sprite/tree.png");
    m_foliageTile.loadFromFile("./sprite/foliage.png");
    m_skyTile.loadFromFile("./sprite/sky.png");
    m_stoneCaveTile.loadFromFile("./sprite/stoneCave.png");
    m_lavaTile.loadFromFile("./sprite/lava.png");
    m_coalTile.loadFromFile("./sprite/coal.png");
    m_rubyTile.loadFromFile("./sprite/ruby.png");
    m_emeraldTile.loadFromFile("./sprite/emerald.png");
    m_mossTile.loadFromFile("./sprite/moss.png");
    m_cloudWallTile.loadFromFile("./sprite/cloudWall.png");
    m_cloudWallBackgroundTile.loadFromFile("./sprite/cloudWallBackground.png");
    m_woodPlankTile.loadFromFile("./sprite/woodPlank.png");
    m_woodPlankBackgroundTile.loadFromFile("./sprite/woodPlankBackground.png");
    m_brickTile.loadFromFile("./sprite/brick.png");
    m_brickBackgroundTile.loadFromFile("./sprite/brickBackground.png");
    m_lavaBrickTile.loadFromFile("./sprite/lavaBrick.png");
    m_lavaBrickBackgroundTile.loadFromFile("./sprite/lavaBrickBackground.png");

    arrTileIndex.resize(m_cellCount, std::vector<int>(m_cellCount, 0));
}

MapGenerator::~MapGenerator()
{}

sf::Sprite MapGenerator::generate()
{
    sf::Time dt = m_deltaClock.getElapsedTime();
    dt.asSeconds();
    long long t1 = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::srand((unsigned int)t1);
    m_seed = rand() % 500;
    generateGround();
    generateOre(0.8, 1, 0.25f, 6);   //Diamond
    generateOre(0.5, 1, 0.2f, 4);    //Gold
    generateOre(0, 0.5,0.10f, 5);    //Gravel
    generateOre(0.2, 1, 0.15f, 12);  //Coal
    generateOre(0.7, 1,0.25f, 13);   //Ruby
    generateOre(0.6, 0.8, 0.20f, 14);//Emerald
    generateCaves();
    generateSkyAndTrees();
    generateHell();
    generateDungeons();

    std::cout << m_deltaClock.getElapsedTime().asMilliseconds() - dt.asMilliseconds() << std::endl;
    fillMapImage();
    std::cout << m_deltaClock.getElapsedTime().asMilliseconds() - dt.asMilliseconds() << std::endl;

    m_mapTexture.loadFromImage(m_mapImage);
    m_mapSprite.setTexture(m_mapTexture);
    return m_mapSprite;
}

void MapGenerator::fillCell(sf::Image* tile, int i, int j)
{
    for(size_t k = 0; k < m_cellSize; k++)
    {
        for (size_t l = 0; l < m_cellSize; l++)
        {
            m_mapImage.setPixel(k + m_cellSize * i, l + m_cellSize * j, tile->getPixel(k, l));
        }
    }
}

void MapGenerator::fillMapImage()
{
    for (size_t i = 0; i < arrTileIndex.size(); i++)
    {
        for (size_t j = 0; j < arrTileIndex.size(); j++)
        {

            switch (arrTileIndex[i][j])
            {
            case 1:
                fillCell(&m_groundTile, i, j);
                break;
            case 2:
                fillCell(&m_grassTile, i, j);
                break;
            case 3:
                fillCell(&m_stoneTile, i, j);
                break;
            case 4:
                fillCell(&m_goldTile, i, j);
                break;
            case 5:
                fillCell(&m_gravelTile, i, j);
                break;
            case 6:
                fillCell(&m_diamondTile, i, j);
                break;
            case 7:
                fillCell(&m_treeTile, i, j);
                break;
            case 8:
                fillCell(&m_foliageTile, i, j);
                break;
            case 9:
                fillCell(&m_skyTile, i, j);
                break;
            case 10:
                fillCell(&m_stoneCaveTile, i, j);
                break;
            case 11:
                fillCell(&m_lavaTile, i, j);
                break;
            case 12:
                fillCell(&m_coalTile, i, j);
                break;
            case 13:
                fillCell(&m_rubyTile, i, j);
                break;
            case 14:
                fillCell(&m_emeraldTile, i, j);
                break;
            case 15:
                fillCell(&m_mossTile, i, j);
                break;
            case 16:
                fillCell(&m_cloudWallTile, i, j);
                break;
            case 17:
                fillCell(&m_cloudWallBackgroundTile, i, j);
                break;
            case 18:
                fillCell(&m_woodPlankTile, i, j);
                break;
            case 19:
                fillCell(&m_woodPlankBackgroundTile, i, j);
                break;
            case 20:
                fillCell(&m_brickTile, i, j);
                break;
            case 21:
                fillCell(&m_brickBackgroundTile, i, j);
                break;
            case 22:
                fillCell(&m_lavaBrickTile, i, j);
                break;
            case 23:
                fillCell(&m_lavaBrickBackgroundTile, i, j);
                break;
            default:
                break;
            }

        }
    }
}

float MapGenerator::getPerlin(unsigned int i, unsigned int j, int noiseRateFactor, int seedFactor)
{
    return stb_perlin_noise3_seed(i * m_noiseRate * noiseRateFactor, j * m_noiseRate * noiseRateFactor, 0, 0, 0, 0, m_seed * seedFactor) + 1;
    
}

sf::Sprite MapGenerator::getMapSprite()
{
    return m_mapSprite;
}

int MapGenerator::getMapSize()
{
    return m_mapSize;
}

void MapGenerator::generateCaves()
{
    for (size_t i = 0; i < m_cellCount; i++)
    {
        for (int j = 0; j < m_cellCount; j++)
        {
            float a = i * m_noiseRate;
            float perl = stb_perlin_turbulence_noise3(i * m_noiseRate / 1.5, j * m_noiseRate / 1.5, m_seed, .8f, 3.f, 2);
            if (perl < 0.50)
            {
                arrTileIndex[i][j] = 10;
               
            }
            else if (perl > 0.50 && perl < 0.60 && j > m_cellCount/4 && j < m_cellCount / 2)
                arrTileIndex[i][j] = 15;
        }
    }
}

void MapGenerator::generateGround()
{

    for (size_t i = 0; i < m_cellCount; i++)
    {
        for (size_t j = 0; j < m_cellCount; j++)
        {
            float perl = getPerlin(i, j, 4, 3);
            float seuil;
            if (j < 60) 
                seuil = 1.3f;
            else if (j < 120)
                seuil = 1.f;
            else
                seuil = 0.8f;
            seuil = j/float(m_cellCount) *1.3 + .5;


            if (perl > seuil)
            {
                arrTileIndex[i][j] = 1; //ground
            }
            else
            {
                arrTileIndex[i][j] = 3; //stone
            }

        }
    }

}

void MapGenerator::generateOre(float minDepthPercent, float maxDepthPercent, float rarity, int oreIndex)
{
    long long t1 = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::srand((unsigned int)t1);
    int seed = rand() % 10000;

    for (size_t i = 0; i < m_cellCount; i++)
    {
        for (size_t j = 0; j < m_cellCount; j++)
        {
            float perl = getPerlin(i, j, 2, seed);
            float perl2 = getPerlin(i, j, 4, seed);

            if (perl > 1 + rarity && j > minDepthPercent * m_cellCount && j < maxDepthPercent * m_cellCount && perl2 < 1 - rarity && arrTileIndex[i][j] == 3)
            {
                arrTileIndex[i][j] = oreIndex;
            }
        }
    }
}

void MapGenerator::generateSkyAndTrees()
{
    for (size_t i = 0; i < m_cellCount; i++)
    {
        int heightMax = floor(getPerlin(i, 0, 1, 52) * 10) + 20;
        if (arrTileIndex[i][heightMax] != 10)
        {
            int treeSpawnChance = rand() % 10;
            if (treeSpawnChance == 1 && m_canSpawnTree)
            {
                spawnTree(i, heightMax);
                m_canSpawnTree = false;
            }
            else {
                m_canSpawnTree = true;
                arrTileIndex[i][heightMax] = 2;
            }
        }

        for (size_t j = 0; j < heightMax; j++)
        {
            if (arrTileIndex[i][j] != 7 && arrTileIndex[i][j] != 8)
                arrTileIndex[i][j] = 9;
        }
    }
}

void MapGenerator::spawnTree(int i,int j)
{
    long long t1 = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::srand((unsigned int)t1);

    arrTileIndex[i][j] = 1;

    int treeHeight = rand() % 8 + 3;
    
    for (size_t k = 1; k < treeHeight; k++)
    {
        arrTileIndex[i][j - k] = 7;
    }
    for (size_t l = 0; l < 5; l++)
    {
        if (i + l - 2 >= 0 && i + l - 2 < m_cellCount)
        {
            if (l < 4 && l >0 && arrTileIndex[i + l - 2][j - treeHeight - 2] != 7)
                arrTileIndex[i + l - 2][j - treeHeight - 2] = 8;

            if (arrTileIndex[i + l - 2][j - treeHeight] != 7)
                arrTileIndex[i + l - 2][j - treeHeight] = 8;
            if (arrTileIndex[i + l - 2][j - treeHeight - 1] != 7)
                arrTileIndex[i + l - 2][j - treeHeight - 1] = 8;
        }
    }
}

void MapGenerator::generateHell()
{
    long long t1 = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::srand((unsigned int)t1);

    for (size_t i = 0; i < m_cellCount; i++)
    {
        int heightMax = floor(getPerlin(i * 20, 0, 1, 69) * 10) + 7;
        int hellHeight = floor(getPerlin(i, 0, 2, 14) * 10) + 10;
        int lavaHeight = 18;

        for (size_t j = 0; j < heightMax; j++)
        {
            arrTileIndex[i][m_cellCount - 1 - j - hellHeight] = 10;
        }
        for (size_t j = 0; j < lavaHeight; j++)
        {
            if (arrTileIndex[i][m_cellCount - 1 - j] == 10)
                arrTileIndex[i][m_cellCount - 1 - j ] = 11;
        }
    }
}

void MapGenerator::generateDungeons()
{

    long long t1 = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::srand((unsigned int)t1);
    for (size_t i = 0; i < floor(m_cellCount/20); i++)
    {
        int spawnHeight = (m_dungeonSize - 1) * floor(rand() % m_cellCount / (m_dungeonSize - 1));
        int spawnWidth = (m_dungeonSize - 1) * floor(rand() % m_cellCount / (m_dungeonSize - 1));

        if (spawnHeight < 20)
            spawnDungeon(spawnWidth, spawnHeight, 1);
        else if (spawnHeight < 40)
            spawnDungeon(spawnWidth, spawnHeight, 2);
        else if (spawnHeight < m_cellCount - 50)
            spawnDungeon(spawnWidth, spawnHeight, 3);
        else
            spawnDungeon(spawnWidth, spawnHeight, 4);
    }
}

void MapGenerator::spawnDungeon(int i, int j, int type)
{
    long long t1 = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::srand((unsigned int)t1);

    spawnDungeonRoom(i, j, type);

    int nbRoom = rand() % 6 + 3;

    for (size_t k = 0; k < nbRoom; k++)
    {
        int newRoom = rand() % 4;
        switch (newRoom)
        {
        case 0:
            j = j + m_dungeonSize - 1;
            break;
        case 1:
            j = j - m_dungeonSize + 1;

            break;
        case 2:
            i = i + m_dungeonSize - 1;
            break;
        case 3:
            i = i - m_dungeonSize + 1;
            break;
        default:
            break;
        }
        spawnDungeonRoom(i, j, type);
    }  
}

void MapGenerator::spawnDungeonRoom(int i, int j, int type)
{
    int tileType = 0;
    int backgroundTileType = 0;

    switch (type)
    {
    case 1:
        tileType = 16;
        backgroundTileType = 17; 
        break;
    case 2:
        tileType = 18;
        backgroundTileType = 19;
        break;
    case 3:
        tileType = 20;
        backgroundTileType = 21;
        break;
    case 4:
        tileType = 22;
        backgroundTileType = 23;
    default:
        break;
    }

    for (size_t h = 0; h < m_dungeonSize; h++)
    {
        for (size_t w = 0; w < m_dungeonSize; w++)
        {
            if (j + h < m_cellCount && j + h >= 0 && i + w >= 0 && i + w < m_cellCount)
            {
                if ((h == 0 || h == m_dungeonSize - 1) && w != floor(m_dungeonSize / 2) || ((w == 0 || w == m_dungeonSize - 1) && h != m_dungeonSize - 2))
                {
                    arrTileIndex[i + w][j + h] = tileType;
                }
                else
                {
                    arrTileIndex[i + w][j + h] = backgroundTileType;
                }
            }
        }
    }
}