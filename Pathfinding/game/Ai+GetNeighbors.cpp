#include "Ai.h"

vector<Node*> Ai::GetNeighbors(Node* node)
{



	auto isWithinGrid = [&](int row, int col) -> bool
		{
			return row >= 0 && col >= 0 && row < ROWS && col < COLS;
		};

	vector<Node*> neighbors;

	if (isWithinGrid(node->row - 1, node->col))
	{
		Node* north = &grid[node->row - 1][node->col]; // above
		neighbors.push_back(north);
	}

	if (isWithinGrid(node->row + 1, node->col))
	{
		Node* south = &grid[node->row + 1][node->col]; // below
		neighbors.push_back(south);
	}

	if (isWithinGrid(node->row, node->col + 1))
	{
		Node* east = &grid[node->row][node->col + 1]; // right
		neighbors.push_back(east);
	}

	if (isWithinGrid(node->row, node->col - 1))
	{
		Node* west = &grid[node->row][node->col - 1]; // left
		neighbors.push_back(west);
	}

	return neighbors;
}