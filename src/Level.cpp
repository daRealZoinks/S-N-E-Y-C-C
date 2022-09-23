#include "Level.h"

using namespace MidnightEngine;

Level::Level()
{
	auto x = Random::Range(-8, 8);
	auto y = Random::Range(-4, 4);

	glm::vec2 position = { x, y };

	m_Player = Player(position);

	SpawnFood();
}

void Level::Init()
{
	InitializeBondaries();

	m_Player.LoadAssets();
}

void Level::InitializeBondaries()
{
	auto width = 20;

	for (int i = -width; i < width; i++)
	{
		m_Walls.push_back(Wall({ i, 9 }));
		m_Walls.push_back(Wall({ i, 10 }));
		m_Walls.push_back(Wall({ i, -9 }));
		m_Walls.push_back(Wall({ i, -10 }));
	}

	auto height = 10;

	for (int i = -height; i < height; i++)
	{
		m_Walls.push_back(Wall({ 17, i }));
		m_Walls.push_back(Wall({ 18, i }));
		m_Walls.push_back(Wall({ -17, i }));
		m_Walls.push_back(Wall({ -18, i }));
	}
}

void Level::SpawnFood()
{
	m_Food.reset();

	int x;
	int y;
	glm::vec2 foodPosition;

	x = Random::Range(-5, 5);
	y = Random::Range(-3, 3);
	foodPosition = { x, y };

	for (auto& position : m_Player.GetSegmentPositions())
	{
		ME_INFO("found position: ({0},{1}), verifying", x, y);

		if (foodPosition == position)
		{
			x = Random::Range(-5, 5);
			y = Random::Range(-3, 3);
			foodPosition = { x, y };
			ME_INFO("recaltulating");
		}
		else
		{
			ME_INFO("final position: ({0},{1})", x, y);
			break;
		}
	}

	m_Food = CreateRef<Food>(foodPosition);
	m_Food->LoadAssets();
}

void Level::OnUpdate(Timestep ts)
{
	m_Player.OnUpdate(ts);
	if (m_Player.GetPosition() == m_Food->GetPosition())
	{
		SpawnFood();
		m_Player.AddSegment();
	}

	auto& positionsThatKill = GetWallPositions();

	if (std::find(positionsThatKill.begin(), positionsThatKill.end(), m_Player.GetPosition()) != positionsThatKill.end())
	{
		Reset();
	}

	if (m_Player.GetDead())
	{
		Reset();
	}
}

void Level::OnRender()
{
	m_Player.OnRender();
	m_Food->OnRender();

	for (auto& wall : m_Walls)
	{
		wall.OnRender();
	}
}

void Level::Reset()
{
	if (m_HighScore < m_Player.GetScore())
	{
		m_HighScore = m_Player.GetScore();
	}

	m_Player = Player();
	SpawnFood();
}