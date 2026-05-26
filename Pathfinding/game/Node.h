#pragma once
#include <raylib.h>
#include <string>

using namespace std;

inline void DrawRectLinesVec(Vector2 pos, Vector2 size, Color outlineColor)
{
	DrawRectangleLines(pos.x, pos.y, size.x, size.y, outlineColor);
}

struct Node
{
	Node(int row, int col, Vector2 pos, Vector2 size, bool blocked,Color fillColor = GRAY, Color outlineColor = BLACK)
	{
		this->row = row;
		this->col = col;
		this->fillColor = fillColor;
		this->pos = pos;
		this->size = size;
		this->outlineColor = outlineColor;
		this->blocked = blocked;
	}

	int row, col;

	Vector2 pos;
	Vector2 size;
	Color fillColor = BLACK, outlineColor = BLACK;
	Color baseColor = GRAY;
	bool blocked = false;
	string dispTxt;
	float weight;


	void Draw()
	{
		Color drawColor = fillColor;

		if (blocked)
		{
			drawColor = BLACK;
		}

		DrawRectangleV(pos, size, drawColor);

		DrawRectLinesVec(pos, size, outlineColor);

		if (dispTxt.empty())
			return;

		int textHeight = 20;
		int textWidth = MeasureText(dispTxt.c_str(), textHeight);

		Vector2 txtPos = {
			pos.x + size.x / 2 - textWidth / 2,
			pos.y + size.y / 2 - textHeight / 2
		};

		DrawText(dispTxt.c_str(), txtPos.x, txtPos.y, textHeight, WHITE);
	}

	void ResetNode()
	{
		blocked = false;
		dispTxt = "";
		baseColor = GRAY;
		fillColor = baseColor;
	}


};