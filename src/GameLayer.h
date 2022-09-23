#pragma once

#include "MidnightEngine.h"
#include "Level.h"

class GameLayer : public MidnightEngine::Layer
{
public:
	GameLayer();
	virtual ~GameLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	virtual void OnUpdate(MidnightEngine::Timestep ts) override;
	virtual void OnImGuiRender() override;
	virtual void OnEvent(MidnightEngine::Event& event) override;
	bool OnWindowResizeEvent(MidnightEngine::WindowResizeEvent& event);

private:
	void CreateCamera(uint32_t width, uint32_t height);

private:
	MidnightEngine::Scope<MidnightEngine::OrthographicCamera> m_Camera;
	Level m_Level;
};