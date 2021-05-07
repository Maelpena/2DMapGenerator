#pragma once
#include "Display.h"
#include <iostream>

Display::Display(MapGenerator* map) :m_screenSize(1000), m_window(sf::VideoMode(m_screenSize, m_screenSize), "Map Genarator"),
m_view(sf::FloatRect(0, 0, m_window.getSize().x / 10, m_window.getSize().y / 10))
{
    m_view.setCenter(m_window.getSize().x / 2, m_window.getSize().y / 2);
	m_map = map;
    m_mapSize = map->getMapSize();
    m_moveSpeed = 0.5f;
}

Display::~Display()
{
    delete m_map;
}

void Display::update()
{
    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();
            if (event.type == sf::Event::MouseButtonPressed)
                if (event.mouseButton.button == sf::Mouse::Right)
                    m_map->generate();

            if (event.type == sf::Event::MouseWheelScrolled)
            {
                if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
                {
                    if (event.mouseWheelScroll.delta == 1)
                    {
                        if (m_view.getSize().x * 0.9f > 200)
                            m_view.setSize(m_view.getSize() * 0.9f);
                    
                    }
                    else if (event.mouseWheelScroll.delta == -1)
                    {
                        if (m_view.getSize().x * 1.1f < m_mapSize)
                        {
                            m_view.setSize(m_view.getSize() * 1.1f);
                        }
                        else {
                            m_view.setSize(m_mapSize, m_mapSize);
                            m_view.setCenter(m_mapSize / 2, m_mapSize / 2);
                        }
                    }
                    if ((m_view.getCenter().x + m_view.getSize().x / 2) > m_mapSize)
                        m_view.setCenter(m_mapSize - m_view.getSize().x / 2, m_view.getCenter().y);

                    if ((m_view.getCenter().x - m_view.getSize().x / 2) < 0)
                        m_view.setCenter(m_view.getSize().x / 2, m_view.getCenter().y);

                    if ((m_view.getCenter().y + m_view.getSize().y / 2) > m_mapSize)
                        m_view.setCenter(m_view.getCenter().x, m_mapSize - m_view.getSize().y / 2);

                    if ((m_view.getCenter().y - m_view.getSize().y / 2) < 0)
                        m_view.setCenter(m_view.getCenter().x, m_view.getSize().y / 2);

                }
            }
        }

        //Deplacement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (m_view.getCenter().x + m_view.getSize().x / 2) < m_mapSize)
        {
            m_view.setCenter(m_view.getCenter().x + m_moveSpeed, m_view.getCenter().y);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && (m_view.getCenter().x - m_view.getSize().x / 2) > 0)
        {
            m_view.setCenter(m_view.getCenter().x - m_moveSpeed, m_view.getCenter().y);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (m_view.getCenter().y + m_view.getSize().y / 2) < m_mapSize)
        {
            m_view.setCenter(m_view.getCenter().x, m_view.getCenter().y + m_moveSpeed);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && (m_view.getCenter().y - m_view.getSize().y / 2) > 0)
        {
            m_view.setCenter(m_view.getCenter().x, m_view.getCenter().y - m_moveSpeed);
        }


        m_window.setView(m_view);

        m_window.clear();

        m_window.draw(m_map->getMapSprite());

        m_window.display();
    }
}