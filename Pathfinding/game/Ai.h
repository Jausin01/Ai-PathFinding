#pragma once
#include <raylib.h>
#include <raymath.h>
#include <vector>
#include "Node.h"

using namespace std;

class Ai
{
public:

#define ROWS 20
#define COLS 50
#define NODE_SIZE 25 // Width and Heigh 

	static const int screenW = 1000;
	static const int screenH = 500;

	vector<vector<Node>> grid;
	Node *start, *end;
	bool searching = false;

	Node* current = nullptr;
	vector<Node*> visited;
	vector<Node*> currentPath;

	int attempt = 0;
	Color attemptColor;
	vector<Color> usedColors;



	Node* GetRandomNode();
	void Main();
	void Start();
	void Update();
	void Draw();
	void Interaction();
	void RestartGame();
	vector<Node*> GetNeighbors(Node* node);

	// NEXT WEEK
	void BFS(Node* s, Node* e);
	void DFS(Node* s, Node* e);
	void Djikstra(Node* s, Node* e);
	void AStar(Node* s, Node* e);

	void RandomSearch(Node* s, Node* e);
	Color GetUniqueColor();

};