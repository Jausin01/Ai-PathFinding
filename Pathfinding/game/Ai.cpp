#include "Ai.h"



void Ai::Main()
{
    Start();
    InitWindow(screenW, screenH, "AI Path Finding");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        Interaction();
        Update();
 
        BeginDrawing();
        ClearBackground(DARKGRAY);
        
        Draw();
        



        EndDrawing();
    }

    CloseWindow();



}

void Ai::Start()
{


    for (int row = 0; row < ROWS; row++)
    {
        float y = NODE_SIZE * row;
        vector<Node> rowNodes;
        for (int col = 0; col < COLS; col++)
        {
            float x = NODE_SIZE * col;
            Node node(row, col, Vector2{ x,y }, Vector2{ NODE_SIZE,NODE_SIZE }, false);

            rowNodes.push_back(node);
        }
        grid.push_back(rowNodes);
    }

    RestartGame();
}

