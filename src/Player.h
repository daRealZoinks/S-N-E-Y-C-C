#pragma once

#include <MidnightEngine.h>

#include "SnakeSegment.h"

class Player
{
public:
	Player(glm::vec2 position = { 0.0f, 0.0f });
	void LoadAssets();

	void OnUpdate(MidnightEngine::Timestep ts);
	void OnRender();

	void Move(glm::vec2 direction);

	inline const glm::vec2& GetPosition() const { return m_Position; }
	void AddSegment();

	inline const std::vector<glm::vec2> GetSegmentPositions() const
	{
		std::vector<glm::vec2> positions;

		positions.push_back(m_Position);

		for (auto& segment : m_Segments)
		{
			positions.push_back(segment.GetPosition());
		}

		return positions;
	}

	inline const bool& GetDead() const { return m_Dead; }

	uint32_t GetScore() const { return m_Segments.size(); }

private:
	glm::vec2 m_Position;
	MidnightEngine::Ref<MidnightEngine::Texture2D> m_Texture;

	glm::vec2 m_Direction;
	std::vector<SnakeSegment> m_Segments;
	float m_Speed = 3;

	float m_Timer;

	bool m_Dead;
};