
#include "raylib.h"
#include <time.h>
#include <stdlib.h>

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 400;
    const int screenHeight = 800;
    float tetraminosRadius = 20*sqrt(2);
    const int squareSide = 40;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    
    // spawn position
    int tetraminosSpawnPosition[1] = { (int)squareSide/2, (int)squareSide/2 };

    // colors matrix
    int colors_matrix[9][19];
    int r = 20;
    int c = 10;

    for(int i=0; i<r; ++i) {
        for(int j=0; j<c; ++j) {
            colors_matrix[i][j] = 0;
        }
    }

    typedef struct 
    {
        int x;
        int y;
    } tuple;
    // tetraminus piece
  // Rectangle, 4 components
    typedef struct {
        tuple piece1;                // Rectangle top-left corner position x
        tuple piece2;                // Rectangle top-left corner position y
        tuple piece3;            // Rectangle width
        tuple piece4;           // Rectangle height
    } Tetraminus;



    // position of moving tetraminus
    // Vector2 tetraminosPosition = { tetraminosRadius/2, tetraminosRadius/2 };
    // Vector2 tetraminosPosition = { squareSide/2, squareSide/2 };
    Vector2 tetraminosPosition = { 0, 0 };

    Tetraminus tetraO = {{0,4},{0,5},{1,4},{1,5}};
    Tetraminus tetraI = {{0,4},{1,4},{2,4},{3,4}};

    SetTargetFPS(200);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        // move the tetraminos
        //----------------------------------------------------------------------------------
        if (IsKeyPressed(KEY_RIGHT) && tetraminosPosition.x < screenWidth - squareSide ) { 
            tetraminosPosition.x += 40.0f; 
            }
        if (IsKeyPressed(KEY_LEFT) && tetraminosPosition.x >= squareSide) { 
            tetraminosPosition.x -= 40.0f; 
            }
        // if (IsKeyDown(KEY_UP) && tetraminosPosition.y >= 0) { 
        //     tetraminosPosition.y -= 40.0f; 
        //     }
        if (IsKeyPressed(KEY_DOWN) && tetraminosPosition.y < screenHeight - squareSide) { 
            tetraminosPosition.y += 40.0f;
            }
        //--------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
            // Draw grid
            for (int x = 0; x < screenWidth; x += screenWidth/10) {
                DrawLine(x, 0, x, screenHeight, BLACK);
            }
            for (int y = 0; y < screenHeight; y += screenHeight/20) {
                DrawLine(0, y, screenWidth, y, BLACK);
            }


            
            for(int i=0; i<r; ++i) {
                for(int j=0; j<c; ++j) {
                    // spawnPoint
                    if ((i>=0 && i<=(3)) && (j>=3 && j<=(6))) {
                        colors_matrix[i][j] = 1;
                        DrawRectangle(j*squareSide,i*squareSide,squareSide,squareSide,GREEN); // coordinate in pixel
                        // draw a tetraminus
                        DrawRectangle(j*squareSide,i*squareSide,squareSide,squareSide,GREEN);
                    }
                }
            }

            // DrawText("move the tetraminos with arrow keys", 50, (float)screenHeight/2, 19, DARKGRAY);

            // DrawRectangle(tetraminosPosition.x, tetraminosPosition.y, squareSide,squareSide, ORANGE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}