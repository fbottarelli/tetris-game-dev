
#include "raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 400;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    // first block start position
    Vector2 tetraminosPosition = { (float)40, (float)40 };

    SetTargetFPS(15);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    float tetraminosRadius = 40;
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        // move the tetraminos
        //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_RIGHT) && tetraminosPosition.x <= screenWidth - tetraminosRadius ) { 
            tetraminosPosition.x += 40.0f; 
            }
        if (IsKeyDown(KEY_LEFT) && tetraminosPosition.x >= tetraminosRadius) { 
            tetraminosPosition.x -= 40.0f; 
            }
        // if (IsKeyDown(KEY_UP) && tetraminosPosition.y >= 0) { 
        //     tetraminosPosition.y -= 40.0f; 
        //     }
        if (IsKeyDown(KEY_DOWN) && tetraminosPosition.y <= screenHeight - tetraminosRadius) { 
            tetraminosPosition.y += 40.0f;
            }
        //----------------------------------------------------------------------------------


        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
            // Draw grid
            for (int x = 0; x < screenWidth; x += 50) {
                DrawLine(x, 0, x, screenHeight, BLACK);
            }
            for (int y = 0; y < screenHeight; y += 50) {
                DrawLine(0, y, screenWidth, y, BLACK);
            }

            DrawText("move the tetraminos with arrow keys", 50, (float)screenHeight/2, 19, DARKGRAY);

            DrawPoly(tetraminosPosition, 4, tetraminosRadius, 45, BROWN);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}