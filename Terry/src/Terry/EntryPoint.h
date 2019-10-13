#pragma once
#ifdef TR_PLATFORM_WINDOW
extern Terry::Application* Terry::CreateApplication();
int main(int argc, char** argv) {
	printf("entry point hapends............");
	auto app = Terry::CreateApplication();
	app->Run();
	delete app;
}
#endif