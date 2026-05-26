#include "Ai.h"

void Ai::Draw()
{
    for (auto& row : grid)
    {
        for (auto& col : row)
        {
            col.Draw();
        }
    }


}