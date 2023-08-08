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
		//LY_INFO("ExampleLayer::Update");
		if (Lily::Input::IsKeyPressed(LY_KEY_TAB))
			LY_TRACE("Tab key is pressed (poll)!");
	}

	void OnEvent(Lily::Event& event) override
	{
		//LY_TRACE("{0}", event);
		if (event.GetEventType() == Lily::EventType::KeyPressed)
		{
			Lily::KeyPressedEvent& e = (Lily::KeyPressedEvent&)event;
			if (e.GetKeyCode() == LY_KEY_TAB)
				LY_TRACE("Tab key is pressed (event)!");
			LY_TRACE("{0}", (char)e.GetKeyCode());
		}
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