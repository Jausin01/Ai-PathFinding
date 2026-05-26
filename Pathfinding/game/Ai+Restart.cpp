#include "Ai.h"

void Ai::RestartGame()
{
	for (auto& row : grid)
	{
		for (auto& node : row)
		{
			node.ResetNode();
		}

	}

	// block some nodes
	for (int i = 0; i < ROWS * COLS * 0.1; i++)
	{
		GetRandomNode()->blocked = true;
	}

	start = GetRandomNode();
	start->fillColor = BLUE;
	start->blocked = false;
	start->dispTxt = "S";

	end = GetRandomNode();
	end->fillColor = GREEN;
	end->blocked = false;
	end->dispTxt = "E";


}