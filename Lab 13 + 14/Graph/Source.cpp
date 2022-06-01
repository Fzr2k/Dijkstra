#include "Graph.h"
#include <string>

int main()
{
	Graph obj(9);
	obj.insertEdge(0, 1, 4);
	obj.insertEdge(0, 7, 8);
	obj.insertEdge(1, 0, 4);
	obj.insertEdge(1, 2, 8);
	obj.insertEdge(1, 7, 11);
	obj.insertEdge(2, 1, 8);
	obj.insertEdge(2, 3, 7);
	obj.insertEdge(2, 5, 4);
	obj.insertEdge(2, 8, 2);
	obj.insertEdge(3, 2, 7);
	obj.insertEdge(3, 4, 9);
	obj.insertEdge(3, 5, 14);
	obj.insertEdge(4, 3, 9);
	obj.insertEdge(4, 5, 10);
	obj.insertEdge(5, 2, 4);
	obj.insertEdge(5, 3, 14);
	obj.insertEdge(5, 4, 10);
	obj.insertEdge(5, 6, 2);
	obj.insertEdge(6, 5, 2);
	obj.insertEdge(6, 7, 1);
	obj.insertEdge(6, 8, 6);
	obj.insertEdge(7, 0, 8);
	obj.insertEdge(7, 1, 11);
	obj.insertEdge(7, 6, 1);
	obj.insertEdge(7, 8, 7);
	obj.insertEdge(8, 2, 2);
	obj.insertEdge(8, 6, 6);
	obj.insertEdge(8, 7, 7);

	cout << "Vertices in graph :- " << endl;
	obj.showVertices();
	cout << endl << "Graph Structure :- " << endl;
	obj.showGraphStructure();
	cout << endl << "Shortest paths from 0 using dijsktra :- "<< endl;
	obj.dijkstra(0);
	cout << endl;

	return 0;
}