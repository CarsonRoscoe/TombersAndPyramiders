#pragma once

#include "GeneratorManager.h"
#include <vector>
#include "GameManager.h"

GeneratorManager* GeneratorManager::s_instance;

GeneratorManager* GeneratorManager::getInstance()
{
	if (s_instance == NULL)
		s_instance = new GeneratorManager();
	return s_instance;
}

/*std::shared_ptr<GeneratorManager> GeneratorManager::s_instance;

std::shared_ptr<GeneratorManager> GeneratorManager::getInstance()
{
	if (s_instance == nullptr)
		s_instance = GameManager::getInstance()->createGameObject<GeneratorManager>(true);
	return s_instance;
}*/

GeneratorManager::GeneratorManager()
{
	for (int i = 0; i < WORLD_WIDTH; i++)
	{
		for (int j = 0; j < WORLD_HEIGHT; j++)
		{
			worldMatrix[i][j] = 0;
		}
	}
}

void GeneratorManager::generateLevel(int width, int height, int detailLevel, int level) 
{
	std::shared_ptr<Level> temp = std::make_shared<Level>();
	levels.push_back(temp);
	m_worldTree = std::make_shared<BinaryTree>(width, height);
	m_worldTree->partition(level, detailLevel);
	m_worldTree->makeCorridors(levels[level]->rooms);

}

void GeneratorManager::drawLevel(int level) {
	
	for (int i = 0; i < levels[level]->corridors.size(); i++) {
		levels[level]->corridors[i]->draw();
	}

	int exitRoom = rand() % levels[level]->rooms.size();
	levels[level]->rooms[exitRoom]->m_exit = true;
	for (int i = 0; i < levels[level]->rooms.size(); i++) {
		levels[level]->rooms[i]->draw();
	}

	//draw/spawn items

}

void GeneratorManager::recordRoom(std::shared_ptr<Room> r)
{
	for (int i = 0; i < r->m_width; i++)
	{
		for (int j = 0; j < r->m_height; j++)
		{
			worldMatrix[r->m_xCoord + j][r->m_yCoord + i] += 1;
		}
	}
}

void GeneratorManager::recordCorridor(std::shared_ptr<Corridor> c)
{
	for (int i = 0; i < c->m_width; i++)
	{
		for (int j = 0; j < c->m_height; j++)
		{
			worldMatrix[c->m_xCoord + j][c->m_yCoord + i] += 1;	
		}
	}
}

void GeneratorManager::showWorld() 
{
	for (int i = 0; i < WORLD_HEIGHT; i++)
	{
		for (int j = 0; j < WORLD_WIDTH; j++)
		{
			std::cout << worldMatrix[j][i] << " ";
		}
		std::cout << std::endl;
	}
}