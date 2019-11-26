#include "TemaDSA.h"

void Dijkstra(int n, Pozitie* poz)
{
	set<pair<int, int>> tail; //cream un vector in care pastram nodul;
	int distances[500];
	for (int i = 0; i < n * n; i++)
	{
		distances[i] = 999; //initializam distantele fiecarui nod ca fiind 999
	}

	//Consideram ca 1 este nodul de plecare.
	distances[0] = 0; //distanta nodului de plecare este 0;

	tail.insert(make_pair(0, 0));

	while (!tail.empty()) // cat timp exista elemente in vector
	{
		int vertex = tail.begin()->second;
		tail.erase(tail.begin());

		for (size_t i = 0; i < poz[vertex].adjacencyList.size(); i++)
		{
			int neighbour = poz[vertex].adjacencyList[i];
			int cost = poz[neighbour].cost;

			if (distances[neighbour] > distances[vertex] + cost)
			{
				tail.erase(make_pair(distances[neighbour], neighbour));
				distances[neighbour] = distances[vertex] + cost;
				tail.insert(make_pair(distances[neighbour], neighbour));
			}
		}
	}

	for (int i = 0; i < n*n; i++)
	{
		cout << distances[i] << " ";
	}
}