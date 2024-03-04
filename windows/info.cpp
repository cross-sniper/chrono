#include "../defs.hpp"

class InfoWindow
{
protected:
	const char* title;
public:
    InfoWindow(const char* title) : title(title){}

    // Function to render ImGui content
    void RenderImGui(const char* text)
    {
        // Create a simple window
        ImGui::Begin(title);

        // Add content to the window
        ImGui::Text(text);

        // End the ImGui window
        ImGui::End();
    }
};

