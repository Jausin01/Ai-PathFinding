#include "Ai.h"

void Ai::Interaction()
{
	if (IsKeyPressed(KEY_R))
	{
		RestartGame();
	}

    if (IsKeyPressed(KEY_S))
    {
        searching = true;
        usedColors.clear();
        attemptColor = GetUniqueColor();
        current = start;
        visited.clear();
        currentPath.clear();

        visited.push_back(current);
        currentPath.push_back(current);

        attempt = 0;
    }

}

