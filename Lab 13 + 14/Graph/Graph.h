#pragma once
#include "AdjList.h"
#include <ctime>
#include <cstdlib>

class Graph
{
	int size;
	int vertices;
	AdjList* array;
	void DFSRec(int v, bool visited[]);
	int minDistance(int dist[], bool sptSet[]);

public:
	Graph(int maxVertices);
	Node* createVertex(int newValue);
	void insertVertex(Node* ver);
	void insertEdge(int src, int dest, int cost);
	void showGraphStructure();
	void showVertices();
	void dijkstra(int src);
	void BFS(int startNode);
	void DFS(int startNode);
	~Graph();
};
