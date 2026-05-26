#include "Ai.h"

void Ai::Update()
{
    if (!searching || start == nullptr || end == nullptr)
        return;

    if (current == end)
    {
        for (Node* n : currentPath)
        {
            if (n != start && n != end)
                n->fillColor = GREEN;
        }

        start->fillColor = BLUE;
        end->fillColor = YELLOW;

        searching = false;
        return;
    }

    vector<Node*> possibleMoves;

    auto tryAdd = [&](int r, int c)
        {
            if (r < 0 || c < 0 || r >= ROWS || c >= COLS)
                return;

            Node* n = &grid[r][c];

            if (n->blocked)
                return;

            for (Node* v : visited)
                if (v == n)
                    return;

            possibleMoves.push_back(n);
        };

    tryAdd(current->row - 1, current->col);
    tryAdd(current->row + 1, current->col);
    tryAdd(current->row, current->col - 1);
    tryAdd(current->row, current->col + 1);

    if (possibleMoves.empty())
    {
        attempt++;
        attemptColor = GetUniqueColor();
        current = start;
        visited.clear();
        currentPath.clear();

        visited.push_back(current);
        currentPath.push_back(current);

        return;
    }


    current = possibleMoves[GetRandomValue(0, possibleMoves.size() - 1)];

    visited.push_back(current);
    currentPath.push_back(current);

    if (current != start && current != end)
    {
        current->fillColor = attemptColor;
    }


}