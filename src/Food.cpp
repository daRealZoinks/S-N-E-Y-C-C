#include "Food.h"

using namespace MidnightEngine;

Food::Food(glm::vec2 position)
	: m_Position(position)
{
}

void Food::LoadAssets()
{
	m_Texture = Texture2D::Create(1, 1);
}

void Food::OnRender()
{
	Renderer2D::DrawQuad(m_Position, { 1.0f, 1.0f }, glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
}