#include "Player.h"

using namespace MidnightEngine;

Player::Player(glm::vec2 position)
	: m_Position(position), m_Direction(glm::vec2(1.0f, 0.0f)), m_Timer(1 / m_Speed), m_Dead(false)
{
}

void Player::LoadAssets()
{
	m_Texture = Texture2D::Create(1, 1);
}

void Player::OnUpdate(MidnightEngine::Timestep ts)
{
	if (Input::IsKeyPressed(ME_KEY_D) &&
		(m_Segments.size() > 0 ? m_Segments[0].GetPosition() - m_Position != glm::vec2(1.0f, 0.0f) : true))
	{
		m_Direction = glm::vec2(1.0f, 0.0f);
	}
	else if (Input::IsKeyPressed(ME_KEY_A) &&
		(m_Segments.size() > 0 ? m_Segments[0].GetPosition() - m_Position != glm::vec2(-1.0f, 0.0f) : true))
	{
		m_Direction = glm::vec2(-1.0f, 0.0f);
	}
	else if (Input::IsKeyPressed(ME_KEY_W) &&
		(m_Segments.size() > 0 ? m_Segments[0].GetPosition() - m_Position != glm::vec2(0.0f, 1.0f) : true))
	{
		m_Direction = glm::vec2(0.0f, 1.0f);
	}
	else if (Input::IsKeyPressed(ME_KEY_S) &&
		(m_Segments.size() > 0 ? m_Segments[0].GetPosition() - m_Position != glm::vec2(0.0f, -1.0f) : true))
	{
		m_Direction = glm::vec2(0.0f, -1.0f);
	}

	for (size_t i = 1; i < m_Segments.size(); i++)
	{
		if (m_Segments[i].GetPosition() == m_Position)
		{
			m_Dead = true;
		}
	}

	m_Timer -= ts;
	if (m_Timer < 0)
	{
		Move(m_Direction);
		m_Timer = 1 / m_Speed;
	}
}
void Player::OnRender()
{
	Renderer2D::DrawQuad(m_Position, { 1.0f, 1.0f }, glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
	for (auto& segment : m_Segments)
	{
		segment.OnRender();
	}
}

void Player::Move(glm::vec2 direction)
{
	if (m_Segments.size() > 0)
	{
		for (int i = m_Segments.size() - 1; i > 0; i--)
		{
			m_Segments[i].SetPosition(m_Segments[i - 1].GetPosition());
		}

		m_Segments[0].SetPosition(m_Position);
	}

	m_Position += direction;
}

void Player::AddSegment()
{
	if (m_Segments.size() == 0)
	{
		m_Segments.push_back(SnakeSegment(m_Position));
	}
	else
	{
		m_Segments.push_back(SnakeSegment(m_Segments[m_Segments.size() - 1].GetPosition()));
	}
}