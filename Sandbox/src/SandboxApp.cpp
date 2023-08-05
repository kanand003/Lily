#include <Lily.h>

class ExampleLayer : public Lily::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		LY_INFO("ExampleLayer::Update");
	}

	void OnEvent(Lily::Event& event) override
	{
		LY_TRACE("{0}", event);
	}
};

class Sandbox : public Lily::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Lily::ImGuiLayer());
	}
	~Sandbox()
	{
		 
	}
};

Lily::Application* Lily::CreateApplication()
{
	return new Sandbox();
}