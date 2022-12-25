#pragma once
#ifdef  LY_PLATFORM_WINDOWS

extern Lily::Application* Lily::CreateApplication();

int main(int argc,char** argv)
{
	Lily::Log::Init();
	LY_CORE_WARN("Initialized Log!");
	int a = 5;
	LY_CORE_INFO("Hello Log! Var={0}",a);

	auto app = Lily::CreateApplication();
	//Sandbox* sandbox = new Sandbox();
	app->Run();
	delete app;

}

#endif //  LY_PLATFORM_WINDOWS
