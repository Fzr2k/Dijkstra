#include "Graph.h"

Graph::Graph(int maxVertices)
{
	array = new AdjList[maxVertices];
	for (int i = 0; i < maxVertices; i++)
	{
		array[i].head = NULL;
	}
	size = maxVertices;
	vertices = 0;
}

void Graph::insertVertex(Node* ver)
{
	if (vertices == 0)
	{
		array[0].head = ver;
		vertices = 1;
	}
	else
	{
		Node* tempNode;
		bool flag = false;
		for (int i = 0; i < vertices; i++)
		{
			tempNode = array[i].head;
			if (tempNode)
			{
				if (tempNode->data == ver->data)
				{
					flag = true;
				}
			}
		}
		if (!flag)
		{
			array[vertices].head = ver;
			vertices++;
		}
		else
		{
			cout << "Duplicate value found" << endl;
		}
	}
}

Node* Graph::createVertex(int newValue)
{
	Node* newNode = new Node;
	newNode->data = newValue;
	newNode->next = NULL;
	newNode->cost = 0;

	return newNode;
}

void Graph::insertEdge(int src, int dest, int cost)
{
	bool flag = false;

	if (vertices <= size)
	{
		for (int i = 0; i < vertices; i++)
		{
			if (array[i].head->data == src)
			{
				flag = true;
				break;
			}
		}

		if (!flag)	//If source vertex not found, then create one
		{
			array[vertices].head = createVertex(src);
			vertices++;
		}

		flag = false;

		for (int i = 0; i < vertices; i++)
		{
			if (array[i].head->data == dest)
			{
				flag = true;
				break;
			}
		}

		if (!flag)	//If destination vertex not found, then create one
		{
			array[vertices].head = createVertex(dest);
			vertices++;
		}

		Node* tempNode;
		for (int i = 0; i < vertices; i++)
		{
			tempNode = array[i].head;
			if (tempNode->data == src)
			{
				while (tempNode->next)
				{
					tempNode = tempNode->next;
				}
				tempNode->next = createVertex(dest);
				tempNode->next->cost = cost;
			}
		}
	}
	else
	{
		cout << "Graph is full" << endl;
	}
}

void Graph::showVertices()
{
	Node* tempNode;
	for (int i = 0; i < vertices; i++)
	{
		tempNode = array[i].head;
		cout << tempNode->data << endl;
	}
}

void Graph::BFS(int startNode)
{
	bool* visited = new bool[vertices];
	for (int i = 0; i < vertices; i++)
	{
		visited[i] = false;
	}

	Queue queue(vertices);

	visited[startNode] = true;
	queue.push_back(startNode);

	cout << "Graph according to BFS starting from vertex " << startNode << " :- " << endl;

	while (!queue.isEmpty())
	{
		int currVertex = queue.front_El();
		cout << currVertex << " ";
		queue.pop_front();

		Node* tempNode;
		int i = 0;

		for (i = 0; i < vertices; i++)
		{
			tempNode = array[i].head;
			if (tempNode->data == currVertex)
			{
				break;
			}
		}

		tempNode = array[i].head;

		while (tempNode)
		{
			int adjVertex = tempNode->data;
			if (!visited[adjVertex])
			{
				visited[adjVertex] = true;
				queue.push_back(adjVertex);
			}
			tempNode = tempNode->next;
		}
	}
}

void Graph::DFS(int startNode)
{
	bool* visited = new bool[vertices];
	for (int i = 0; i < vertices; i++)
	{
		visited[i] = false;
	}

	DFSRec(startNode, visited);
}

void Graph::DFSRec(int startNode, bool visited[])
{
	visited[startNode] = true;

	cout << startNode << " ";

	Node* tempNode;
	int i = 0;

	for (i = 0; i < vertices; i++)
	{
		tempNode = array[i].head;
		if (tempNode->data == startNode)
		{
			break;
		}
	}

	tempNode = array[i].head;

	while (tempNode)
	{
		int adjVertex = tempNode->data;
		if (!visited[adjVertex])
		{
			DFSRec(adjVertex, visited);
		}
		tempNode = tempNode->next;
	}
}

void Graph::showGraphStructure()
{
	Node* tempNode;
	for (int i = 0; i < vertices; i++)
	{
		tempNode = array[i].head;
		while (tempNode)
		{
			if (tempNode->next)
				cout << tempNode->data << "->";
			else
				cout << tempNode->data;
			tempNode = tempNode->next;
		}
		cout << endl;
	}
}

void Graph::dijkstra(int src)
{
	int** matrix = new int*[vertices];			//Creating a 2D array containing graph's costs
	for (int i = 0; i < vertices; i++)
	{
		matrix[i] = new int[vertices];
	}

	for (int i = 0; i < vertices; i++)
	{
		for (int j = 0; j < vertices; j++)
		{
			matrix[i][j] = 0;
		}
	}
	Node* tempNode;

	for (int i = 0; i < vertices; i++)			//Putting values inside the matrix in an ascending manner
	{											//i.e array[0] represents links of 0 with other points 
		int row = array[i].head->data;
		tempNode = array[i].head->next;
		while (tempNode)
		{
			matrix[row][tempNode->data] = tempNode->cost;
			tempNode = tempNode->next;
		}
	}

	//for (int i = 0; i < vertices; i++)		//Uncomment to see the matrix on console
	//{
	//	for (int j = 0; j < vertices; j++)
	//	{
	//		cout << matrix[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	//cout << endl;

	int* dist = new int[vertices];
	bool* sptSet = new bool[vertices];

	for (int i = 0; i < vertices; i++)
	{
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}

	dist[src] = 0;

	for (int i = 0; i < vertices - 1; i++)
	{
		int u = minDistance(dist, sptSet);

		sptSet[u] = true;

		for (int j = 0; j < vertices; j++)
		{
			if (!sptSet[j] && matrix[u][j] && dist[u] != INT_MAX && dist[u] + matrix[u][j] < dist[j])
				dist[j] = dist[u] + matrix[u][j];
		}
	}

	cout << ("Vertex \t\t Distance from Source\n");
	for (int i = 0; i < vertices; i++)
		cout << array[i].head->data << "\t\t\t" << dist[i] << endl;
}

int Graph::minDistance(int dist[], bool sptSet[])
{ 
	int min = INT_MAX, min_index;

	for (int v = 0; v < vertices; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

Graph::~Graph()
{
	Node* tempNode;
	Node* deleteNode;
	for (int i = 0; i < vertices; i++)
	{
		tempNode = array[i].head;
		while (tempNode)
		{
			deleteNode = tempNode;
			tempNode = tempNode->next;
			delete deleteNode;
		}
	}
	delete[]array;
}
