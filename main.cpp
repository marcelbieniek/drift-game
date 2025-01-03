/*******************************************************************************************
*
*   raylib-cpp [core] example - Basic window (adapted for HTML5 platform)
*
*   This example is prepared to compile for PLATFORM_WEB, PLATFORM_DESKTOP and PLATFORM_RPI
*   As you will notice, code structure is slightly diferent to the other examples...
*   To compile it for PLATFORM_WEB just uncomment #define PLATFORM_WEB at beginning
*
*   This example has been created using raylib-cpp (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2015 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include <iostream>


#include "raylib-cpp/include/raylib-cpp.hpp"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

//----------------------------------------------------------------------------------
// Global Variables Definition
//----------------------------------------------------------------------------------
int screenWidth = 800;
int screenHeight = 450;

// void UpdateDrawFrame(void)     // Update and Draw one frame
// {
//     // Update
//     //----------------------------------------------------------------------------------
//     // TODO: Update your variables here
//     //----------------------------------------------------------------------------------

//     // Draw
//     //----------------------------------------------------------------------------------
//     BeginDrawing();

//         ClearBackground(RAYWHITE);

//         DrawText("Congrats! You created your first raylib-cpp window!", 160, 200, 20, RED);

//     EndDrawing();
//     //----------------------------------------------------------------------------------
// }

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    raylib::Window window(screenWidth, screenHeight, "DriftGame", FLAG_WINDOW_UNDECORATED | FLAG_VSYNC_HINT);
    raylib::Vector2 carPosition{(float)screenWidth / 2, (float)screenHeight / 2};
    raylib::Texture2D carTex{"car_sprite.png"};

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    raylib::Text currentFps{"current fps"};

    // Main game loop
    while (!window.ShouldClose())    // Detect window close button or ESC key
    {
        if(raylib::Keyboard::IsKeyDown(KEY_RIGHT))
            carPosition.x += 2.0f;
        if(raylib::Keyboard::IsKeyDown(KEY_LEFT))
            carPosition.x -= 2.0f;
        if(raylib::Keyboard::IsKeyDown(KEY_UP))
            carPosition.y -= 2.0f;
        if(raylib::Keyboard::IsKeyDown(KEY_DOWN))
            carPosition.y += 2.0f;

        currentFps.text = std::to_string(GetFPS());

        BeginDrawing();

        ClearBackground(DARKGRAY);

        DrawText("Congrats! You created your first raylib-cpp window!", 160, 200, 20, RED);

        // carPosition.DrawCircle(50, raylib::Color::Red());
        carTex.Draw(carPosition);

        currentFps.Draw(10, 10);

        EndDrawing();
    }
#endif

    return 0;
}
