#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class MapGenerator {
public:
	MapGenerator(int);
	~MapGenerator();

	sf::Sprite generate();
	void fillCell(sf::Image*, int, int);
	sf::Sprite getMapSprite();
	int getMapSize();
	void fillMapImage();
	float getPerlin(unsigned int, unsigned int, int, int);
	void generateCaves();
	void generateGround();
	void generateOre(float, float, float, int);
	void generateSkyAndTrees();
	void generateHell();
	void generateDungeons();
	void spawnTree(int, int);
	void spawnDungeon(int, int, int);
	void spawnDungeonRoom(int, int, int);

private:
	sf::Image m_mapImage;
	sf::Texture m_mapTexture;
	sf::Sprite m_mapSprite;
	const int m_cellCount;
	const int m_cellSize;
	const int m_mapSize;
	double m_noiseRate;
	int m_seed;
	bool m_canSpawnTree;
	std::vector<std::vector<int>> arrTileIndex;
	int m_dungeonSize;


	sf::Image m_groundTile;             //1
	sf::Image m_grassTile;              //2
	sf::Image m_stoneTile;              //3
	sf::Image m_goldTile;               //4
	sf::Image m_gravelTile;             //5
	sf::Image m_diamondTile;            //6
	sf::Image m_treeTile;               //7
	sf::Image m_foliageTile;            //8
	sf::Image m_skyTile;	            //9
	sf::Image m_stoneCaveTile;          //10
	sf::Image m_lavaTile;               //11
	sf::Image m_coalTile;               //12
	sf::Image m_rubyTile;               //13
	sf::Image m_emeraldTile;            //14
	sf::Image m_mossTile;               //15
	sf::Image m_cloudWallTile;          //16
	sf::Image m_cloudWallBackgroundTile;//17
	sf::Image m_woodPlankTile;			//18
	sf::Image m_woodPlankBackgroundTile;//19
	sf::Image m_brickTile;				//20
	sf::Image m_brickBackgroundTile;	//21
	sf::Image m_lavaBrickTile;			//22
	sf::Image m_lavaBrickBackgroundTile;//23


	sf::Clock m_deltaClock;
};