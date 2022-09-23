#include "Wall.h"

using namespace MidnightEngine;

Wall::Wall(glm::vec2 position)
	: m_Position(position)
{
}

void Wall::LoadAssets()
{
	m_Texture = Texture2D::Create(1, 1);
}

void Wall::OnRender()
{
	Renderer2D::DrawQuad(m_Position, { 1.0f, 1.0f }, glm::vec4(0.1f, 0.1f, 0.1f, 1.0f));
}