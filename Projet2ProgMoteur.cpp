//#pragma once
//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <chrono>
//#include "MapGenerator.h"
//
//
//
//
//int main()
//{
//    MapGenerator* map = new MapGenerator(300);
//    
//    bool canSpawnTree = true;
//    const int mapSize = map->m_mapSize;
//    //const int pixelCount = map->m_cellCount;
//    //const float smoothness = 0.101f;
//    //const float smoothness = 0.03f;
//    const float smoothness = 0.06f;
//
//    //const int seed = 10;
//    int screenSize = 1000;
//    const float pixelSize = 20.f;
//    
//    //const float pixelSize = floor(screenSize / pixelCount);
//
//    std::cout << pixelSize << std::endl;
//    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");  
//
//    //sf::Image mapImage;
//    //mapImage.create(mapSize, mapSize, sf::Color::Green);
//    //sf::Texture screenTexture;
//    sf::Sprite screenSprite;
//    sf::View zoomView(sf::FloatRect(0, 0, window.getSize().x / 10, window.getSize().y / 10));
//    //sf::View classicView(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));
//    zoomView.setCenter(window.getSize().x / 2, window.getSize().y / 2);
//
//
//    //float wSizeX4 = window.getSize().x / 4;
//    //float wSizeY4 = window.getSize().y / 4;
//    //long long t1 = std::chrono::high_resolution_clock::now().time_since_epoch().count();
//    //std::srand((unsigned int)t1);
//    //int a = rand() % 10;
//    //float b = (float)a/100;
//
//    //sf::RectangleShape rectangles[pixelCount][pixelCount];
//
//    //for (size_t i = 0; i < pixelCount; i++)
//    //{
//    //    for (size_t j = 0; j < pixelCount; j++)
//    //    {
//    //        float rand = stb_perlin_noise3_seed(i * smoothness , j * smoothness, 0, 0, 0, 0, seed) + 1;
//    //        float rand2 = stb_perlin_noise3_seed(i * smoothness * 2, j * smoothness * 2, 0, 0, 0, 0, seed * 4) + 1;
//    //        float rand3 = stb_perlin_noise3_seed(i * smoothness * 4, j * smoothness * 4, 0, 0, 0, 0, seed * 1000) + 1;
//    //        float rand4 = stb_perlin_noise3_seed(i * smoothness * 4, j * smoothness * 4, 0, 0, 0, 0, seed * 150) + 1;
//    //        float rand5 = stb_perlin_noise3_seed(i * smoothness * 2, j * smoothness * 2, 0, 0, 0, 0, seed * 150) + 1;
//    //        float rand6 = stb_perlin_noise3_seed(i * smoothness * 4, j * smoothness * 4, 0, 0, 0, 0, seed * 150) + 1;
//
//    //        //float rand = stb_perlin_turbulence_noise3(i * smoothness, j * smoothness, 0, 2.0f, 3.f, 1);
//    //        //float rand = rand1 + rand2;
//    //        //n float stb_perlin_turbulence_noise3(float x, float y, float z, float lacunarity, float gain, int octaves);
//
//    //        if (rand < 0)
//    //        {
//    //            rand = 0;
//    //            std::cout << "< 0" << std::endl;
//    //        }
//    //        else if (rand > 2)
//    //            rand = 2;
//    //        //std::cout << rand << " ; ";
//    //        sf::Color newColor;
//    //        if (rand < 0.1f)
//    //        {
//    //            newColor = sf::Color(50, -100 * rand + 255, 100, 255);
//    //        }
//    //        else if (rand >= 0.1f && rand < 1.f)
//    //        {
//    //            newColor = sf::Color(50, -50 * rand2 + 200, 100, 255);
//    //        }
//    //        else if (rand >= 1.f && rand < 1.5f)
//    //        {
//    //            newColor = sf::Color(50, -33 * rand + 150, 100, 255);
//    //        }
//    //        else if (rand >= 1.5f && rand < 2.f)
//    //        {
//    //            newColor = sf::Color(50, -25 * rand + 130, 100, 255);
//    //        }
//    //        //newColor = sf::Color(255, 255, 255, 126 * rand);
//    //        //noir(0) et blanc(1)
//    //        for (size_t k = 0; k < pixelSize; k++)
//    //        {
//    //            for (size_t l = 0; l < pixelSize; l++)
//    //            {
//    //                mapImage.setPixel(k + pixelSize * i, l + pixelSize * j, newColor);
//
//    //            }
//    //        }
//
//    //        //Sprite
//    //        float seuil;
//    //        if (j < 30)
//    //            seuil = 1.3f;
//    //        else if (j < 100)
//    //            seuil = 1.f;
//    //        else if (j < 300)
//    //            seuil = 0.8f;
//
//    //        if (rand4 < 0.9 && rand2 > 1.2)
//    //        {
//    //            for (size_t k = 0; k < pixelSize; k++)
//    //            {
//    //                for (size_t l = 0; l < pixelSize; l++)
//    //                {
//    //                    mapImage.setPixel(k + pixelSize * i, l + pixelSize * j, gravelTile.getPixel(k, l));
//
//    //                }
//    //            }
//    //        }
//
//    //        else if (rand3 < seuil)
//    //        {
//    //            for (size_t k = 0; k < pixelSize; k++)
//    //            {
//    //                for (size_t l = 0; l < pixelSize; l++)
//    //                {
//    //                    mapImage.setPixel(k + pixelSize * i, l + pixelSize * j, groundTile.getPixel(k, l));
//
//    //                }
//    //            }
//    //        }
//    //        else if (rand4 > 1.3 && j > 50 && rand2 < 0.8)
//    //        {
//    //            for (size_t k = 0; k < pixelSize; k++)
//    //            {
//    //                for (size_t l = 0; l < pixelSize; l++)
//    //                {
//    //                    mapImage.setPixel(k + pixelSize * i, l + pixelSize * j, goldTile.getPixel(k, l));
//
//    //                }
//    //            }
//    //        }
//    //        else if (rand5 > 1.4 && j > 100 && rand6 < 0.8)
//    //        {
//    //            for (size_t k = 0; k < pixelSize; k++)
//    //            {
//    //                for (size_t l = 0; l < pixelSize; l++)
//    //                {
//    //                    mapImage.setPixel(k + pixelSize * i, l + pixelSize * j, diamondTile.getPixel(k, l));
//
//    //                }
//    //            }
//    //        }
//    //        else 
//    //        {
//    //            for (size_t k = 0; k < pixelSize; k++)
//    //            {
//    //                for (size_t l = 0; l < pixelSize; l++)
//    //                {
//    //                    mapImage.setPixel(k + pixelSize * i, l + pixelSize * j, stoneTile.getPixel(k, l));
//
//    //                }
//    //            }
//    //        }
//    //    }
//    //}
//
//    //HeightMap
//    /*for (size_t i = 0; i < pixelCount; i++)
//    {
//        float rand1 = floor(stb_perlin_noise3_seed(i * smoothness,0, 0, 0, 0, 0, seed) * 10 + 20);
//        std::cout << rand1 << std::endl;
//
//        int a = rand() % 10;
//
//        
//       
//        for (size_t j = 0; j <= rand1; j++)
//        {   
//            if (canSpawnTree && a == 1 && (j == rand1 - 1 || j == rand1 - 2 || j == rand1 - 3 || j == rand1 - 4))
//            {
//                for (size_t k = 0; k < pixelSize; k++)
//                {
//                    for (size_t l = 0; l < pixelSize; l++)
//                    {
//                        mapImage.setPixel(k + pixelSize * i, l + pixelSize * j, treeTile.getPixel(k, l));
//                    }
//                }
//            }
//            else if (canSpawnTree && a == 1 && (j == rand1 - 5 || j == rand1 - 6))
//            {
//                for (size_t k = 0; k < pixelSize; k++)
//                {
//                    for (size_t l = 0; l < pixelSize; l++)
//                    {
//                        mapImage.setPixel(k + pixelSize * i, l + pixelSize * j, foliageTile.getPixel(k, l));
//                    }
//                }
//            }
//            else if (j == rand1)
//            {
//                for (size_t k = 0; k < pixelSize; k++)
//                {
//                    for (size_t l = 0; l < pixelSize; l++)
//                    {
//                        mapImage.setPixel(k + pixelSize * i, l + pixelSize * j, grassTile.getPixel(k, l));
//                    }
//                }
//            }
//            else
//            {
//                for (size_t k = 0; k < pixelSize; k++)
//                {
//                    for (size_t l = 0; l < pixelSize; l++)
//                    {
//                        mapImage.setPixel(k + pixelSize * i, l + pixelSize * j, sf::Color(153, 204, 255));
//                    }
//                }
//            }
//        }
//        if (a == 1)
//        {
//            canSpawnTree = false;
//        }
//        else {
//            canSpawnTree = true;
//
//        }
//    }*/
//
//    //screenTexture.loadFromImage(map->generate());
//    //screenTexture.loadFromImage(mapImage);
//    screenSprite = map->generate();
//  
//    //Boucle 
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//            //Zoom
//            if (event.type == sf::Event::MouseWheelScrolled)
//            {
//                if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
//                {
//                    if (event.mouseWheelScroll.delta == 1)
//                    {
//                        if (zoomView.getSize().x * 0.9f > 50)
//                           zoomView.setSize(zoomView.getSize() * 0.9f);
//                    }
//                    else if (event.mouseWheelScroll.delta == -1)
//                    {
//                        if (zoomView.getSize().x * 1.1f < mapSize)
//                        {
//                            zoomView.setSize(zoomView.getSize() * 1.1f);
//                        }
//                        else {
//                            zoomView.setSize(mapSize, mapSize);
//                            zoomView.setCenter(mapSize/2, mapSize/2);
//                        }
//                    }
//                    if ((zoomView.getCenter().x + zoomView.getSize().x / 2) > mapSize)
//                        zoomView.setCenter(mapSize - zoomView.getSize().x / 2, zoomView.getCenter().y);
//
//                    if ((zoomView.getCenter().x - zoomView.getSize().x / 2) < 0)
//                        zoomView.setCenter(zoomView.getSize().x / 2, zoomView.getCenter().y);
//
//                    if ((zoomView.getCenter().y + zoomView.getSize().y / 2) > mapSize)
//                        zoomView.setCenter(zoomView.getCenter().x, mapSize - zoomView.getSize().y / 2);
//
//                    if ((zoomView.getCenter().y - zoomView.getSize().y / 2) < 0)
//                        zoomView.setCenter(zoomView.getCenter().x, zoomView.getSize().y / 2);
//
//                    window.setView(zoomView);
//                }
//            }
//        }
//
//        //Deplacement
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (zoomView.getCenter().x + zoomView.getSize().x/2) < mapSize)
//        {
//            zoomView.setCenter(zoomView.getCenter().x + 1, zoomView.getCenter().y);
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && (zoomView.getCenter().x - zoomView.getSize().x / 2) > 0)
//        {
//            zoomView.setCenter(zoomView.getCenter().x - 1, zoomView.getCenter().y);
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (zoomView.getCenter().y + zoomView.getSize().y / 2) < mapSize)
//        {
//            zoomView.setCenter(zoomView.getCenter().x, zoomView.getCenter().y + 1);
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && (zoomView.getCenter().y - zoomView.getSize().y / 2) > 0)
//        {
//            zoomView.setCenter(zoomView.getCenter().x, zoomView.getCenter().y - 1);
//        }
//            
//
//        window.setView(zoomView);
//
//        window.clear();
//
//        window.draw(screenSprite);
//
//        window.display();
//    }
//    return 0;
//}