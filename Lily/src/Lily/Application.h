#pragma once
#include "Core.h"
//#include "Events/Event.h"
//#include "Events/ApplicationEvent.h"
#include "Window.h"
#include "Lily/LayerStack.h"
#include "Lily/Events/Event.h"
#include "Lily/Events/ApplicationEvent.h"

namespace Lily
{
	class LILY_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
	};
	

	//To be defined in Client
	Application* CreateApplication();
}
