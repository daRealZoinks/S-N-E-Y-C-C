#include "SnakeSegment.h"

using namespace MidnightEngine;

SnakeSegment::SnakeSegment(glm::vec2 position)
	: m_Position(position)
{
	LoadAssets();
}

void SnakeSegment::LoadAssets()
{
	m_Texture = Texture2D::Create(1, 1);
}

void SnakeSegment::OnRender()
{
	Renderer2D::DrawQuad(m_Position, { 0.9f, 0.9f }, glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
}