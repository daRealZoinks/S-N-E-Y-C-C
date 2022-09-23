#include "GameLayer.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace MidnightEngine;

GameLayer::GameLayer()
	: Layer("GameLayer")
{
	auto& window = Application::Get().GetWindow();
	CreateCamera(window.GetWidth(), window.GetHeight());

	Random::Init();
}

void GameLayer::OnAttach()
{
	m_Level.Init();
}
void GameLayer::OnDetach()
{
}

void GameLayer::OnUpdate(Timestep ts)
{
	m_Level.OnUpdate(ts);

	RenderCommand::SetClearColor({ 0.05f, 0.05f, 0.05f, 1.0f });
	RenderCommand::Clear();

	Renderer2D::BeginScene(*m_Camera);
	m_Level.OnRender();
	Renderer2D::EndScene();
}
void GameLayer::OnImGuiRender()
{
	uint32_t playerScore = m_Level.GetPlayerScore();
	std::string scoreStr = std::string("Score: ") + std::to_string(playerScore) + std::string("     HighScore: ") + std::to_string(m_Level.GetHighScore());
	ImGui::GetForegroundDrawList()->AddText(ImGui::GetWindowPos(), 0xffffffff, scoreStr.c_str());
}
void GameLayer::OnEvent(Event& event)
{
	EventDispatcher dispatcher(event);
	dispatcher.Dispatch<WindowResizeEvent>(ME_BIND_EVENT_FN(GameLayer::OnWindowResizeEvent));
}

bool GameLayer::OnWindowResizeEvent(WindowResizeEvent& event)
{
	CreateCamera(event.GetWidth(), event.GetHeight());

	return false;
}

void GameLayer::CreateCamera(uint32_t width, uint32_t height)
{
	float aspectRatio = (float)width / (float)height;

	float camWidth = 10;

	float bottom = -camWidth;
	float top = camWidth;
	float left = bottom * aspectRatio;
	float right = top * aspectRatio;

	m_Camera = CreateScope<OrthographicCamera>(left, right, bottom, top);
}