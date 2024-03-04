#include "defs.hpp"
#include "windows/info.cpp"

class Entity {
public:
    Vector2 pos;
    Vector2 size;
    Color color;

    Entity(const Vector2& initialPos, const Vector2& entitySize, const Color& entityColor)
        : pos(initialPos), size(entitySize), color(entityColor) {}

    virtual void Draw() {
        DrawRectangle(pos.x, pos.y, size.x, size.y, color);
    }

    virtual void Move() {
        // Default movement: no movement
    }
};

class PlayerEntity : public Entity {
public:
    PlayerEntity(const Vector2& initialPos, const Vector2& entitySize, const Color& entityColor)
        : Entity(initialPos, entitySize, entityColor) {}

    // Override the Move function for player-specific movement
    void Move() override {
        const float speed = 200.0f * GetFrameTime(); // Adjust the speed as needed

        if (IsKeyDown(KEY_RIGHT)) {
            pos.x += speed;
        }
        if (IsKeyDown(KEY_LEFT)) {
            pos.x -= speed;
        }
        if (IsKeyDown(KEY_DOWN)) {
            pos.y += speed;
        }
        if (IsKeyDown(KEY_UP)) {
            pos.y -= speed;
        }
    }
};

int main() {
    InitWindow(800, 600, "test");
    SetTargetFPS(60);
    rlImGuiSetup(true); // Sets up ImGui with either a dark or light default theme

    // Create an instance of the PlayerEntity class
    PlayerEntity player({0, 0}, {30, 30}, WHITE);
    InfoWindow info("Info Window");
    while (not WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        // Draw and move the player
        player.Draw();
        player.Move();

        rlImGuiBegin();

        // Additional ImGui content or UI interactions can be added here
        info.RenderImGui(TextFormat("time since last frame: %f", GetFrameTime()));
        rlImGuiEnd();
        EndDrawing();
    }

    rlImGuiShutdown();
    CloseWindow();
    return 0;
}
