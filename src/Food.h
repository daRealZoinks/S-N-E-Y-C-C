#pragma once

#include <MidnightEngine.h>

class Food
{
public:
	Food(glm::vec2 position);
	void LoadAssets();

	void OnRender();

	const glm::vec2& GetPosition() const { return m_Position; }

private:
	glm::vec2 m_Position;
	MidnightEngine::Ref<MidnightEngine::Texture2D> m_Texture;
};