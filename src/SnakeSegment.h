#pragma once

#include <MidnightEngine.h>

class SnakeSegment
{
public:
	SnakeSegment(glm::vec2 position);

	void LoadAssets();

	void OnRender();

	const glm::vec2& GetPosition() const { return m_Position; }
	void SetPosition(glm::vec2 position) { m_Position = position; }

private:
	glm::vec2 m_Position;
	MidnightEngine::Ref<MidnightEngine::Texture2D> m_Texture;
};