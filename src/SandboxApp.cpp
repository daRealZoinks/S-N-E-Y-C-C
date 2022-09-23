#include <MidnightEngine.h>
#include <MidnightEngine/Core/EntryPoint.h>

#include "GameLayer.h"

class Sandbox : public MidnightEngine::Application
{
public:
	Sandbox()
	{
		PushLayer(new GameLayer());
	}

	~Sandbox() {}
};

MidnightEngine::Application* MidnightEngine::CreateApplication()
{
	return new Sandbox();
}