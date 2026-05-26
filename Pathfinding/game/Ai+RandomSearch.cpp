#include "Ai.h"

void Ai::RandomSearch(Node* s, Node* e)
{
	if (s == nullptr || e == nullptr)
	{
		return;
	}


	int attempt = 0;

	while (true)
	{
		attempt++;

		Node* current = s;
		vector<Node*> visitedNodes;
		vector<Node*> currentPath;
		
		visitedNodes.push_back(current);
		currentPath.push_back(current);

		bool found = false;

		int redValue = 255 - (attempt * 4);
		if (redValue < 80)
		{
			redValue = 80;
		}

		while (true)
		{
			if (current == e)
			{
				found = true;
				break;
			}

			vector<Node*> possibleMoves;

			auto tryAdd = [&](int r, int c)
			{
				if (r < 0 || c < 0 || r >= (int)grid.size() || c >= (int)grid[0].size())
					return;

				Node* n = &grid[r][c];

				if (n->blocked)
					return;

				for (Node* v : visitedNodes)
				{
					if (v == n)
						return;
				}

				possibleMoves.push_back(n);
			};

			tryAdd(current->row - 1, current->col);
			tryAdd(current->row + 1, current->col);
			tryAdd(current->row, current->col - 1);
			tryAdd(current->row, current->col + 1);

			if (possibleMoves.empty())
			{
				break;
			}

			current = possibleMoves[GetRandomValue(0, possibleMoves.size() - 1)];

			visitedNodes.push_back(current);
			currentPath.push_back(current);

			if (current != s && current != e)
			{
				current->fillColor = Color{
					(unsigned char)redValue,
					0,
					0,
					255
				};
			}

		}

		if (found)
		{
			for (Node* n : currentPath)
			{
				if (n != s && n != e)
				{
					n->fillColor = GREEN;
				}
			}

			s->fillColor = BLUE;
			e->fillColor = YELLOW;

			return;
		}



	}


}