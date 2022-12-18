#pragma once
#ifdef  LY_PLATFORM_WINDOWS

extern Lily::Application* Lily::CreateApplication();

int main(int argc,char** argv)
{
	auto app = Lily::CreateApplication();
	//Sandbox* sandbox = new Sandbox();
	app->Run();
	delete app;

}

#endif //  LY_PLATFORM_WINDOWS
