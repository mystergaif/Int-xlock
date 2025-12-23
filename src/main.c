#include <stdio.h>
#include <time.h>
#include <raylib.h>

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    printf("Raylib Clock");

    InitWindow(screenWidth, screenHeight, "Raylib Clock");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        
        time_t now = time(NULL);
        struct tm *t = localtime(&now);

        // format HH:MM:SS
        const char* timeText = TextFormat("%02d:%02d:%02d", t->tm_hour, t->tm_min, t->tm_sec);

        // 2. render
        BeginDrawing();
            ClearBackground(BLACK); // black 

            
            int fontSize = 80;
            int textWidth = MeasureText(timeText, fontSize);
            DrawText(timeText, screenWidth/2 - textWidth/2, screenHeight/2 - fontSize/2, fontSize, GREEN);
            
            DrawText("ESC to exit", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
