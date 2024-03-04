#include "defs.hpp"//other includes, and possible helper functions
#include "windows/info.cpp"


int main()
{
	InitWindow(800,600,"test");
	SetTargetFPS(60);
	rlImGuiSetup(true); 	// sets up ImGui with ether a dark or light default theme
	while(not WindowShouldClose()){
		BeginDrawing();
		ClearBackground(BLACK);
		rlImGuiBegin();
		bool open = true;

		ImGui::ShowDemoWindow(&open);
		rlImGuiEnd();
		EndDrawing();
	}

	rlImGuiShutdown();
	CloseWindow();
}
