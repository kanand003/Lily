#include "hzpch.h"

#include "Application.h"
#include "Lily/Events/ApplicationEvent.h"
#include "Lily/Log.h"

#include "GLFW/glfw3.h"

namespace Lily
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}
	Application::~Application()
	{

	}
	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(0, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
		/*
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			LY_CORE_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			LY_CORE_TRACE(e);
		}
		
		while (true);
		*/
	}
}