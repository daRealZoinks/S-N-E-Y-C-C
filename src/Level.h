#pragma once

#include <MidnightEngine.h>

#include "Player.h"
#include "Food.h"
#include "Random.h"
#include "Wall.h"

class Level
{
public:
	Level();
	void Init();

	void SpawnFood();

	inline const uint32_t& GetPlayerScore() { return m_Player.GetScore(); }
	inline const uint32_t& GetHighScore() const { return m_HighScore; }

	inline const std::vector<glm::vec2> GetWallPositions() const
	{
		std::vector<glm::vec2> positions;
		for (auto& wall : m_Walls)
		{
			positions.push_back(wall.GetPosition());
		}
		return positions;
	}

	void OnUpdate(MidnightEngine::Timestep ts);
	void OnRender();

	void Reset();

	void InitializeBondaries();

private:
	Player m_Player;
	MidnightEngine::Ref<Food> m_Food;
	uint32_t m_HighScore = 0;

	std::vector<Wall> m_Walls;
};