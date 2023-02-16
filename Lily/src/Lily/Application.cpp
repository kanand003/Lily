#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Lily/Log.h"

namespace Lily
{
	Application::Application()
	{

	}
	Application::~Application()
	{

	}
	void Application::Run()
	{
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
	}
}