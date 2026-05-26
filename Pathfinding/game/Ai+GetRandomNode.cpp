#include "Ai.h"

Node* Ai::GetRandomNode()
{
    int randomRow = GetRandomValue(0, ROWS - 1);
    int randomCol = GetRandomValue(0, COLS - 1);

    while (grid[randomRow][randomCol].blocked)
    {
        randomRow = GetRandomValue(0, ROWS - 1);
        randomCol = GetRandomValue(0, COLS - 1);
    }

    return &grid[randomRow][randomCol];
}