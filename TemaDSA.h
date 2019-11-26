#pragma once
#include <iostream>
#include <fstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

class Pozitie
{
public:
	Pozitie()
	{
		x = 0;
		y = 0;
		cost = 0;
	}
	int x;
	int y;
	int cost;
	vector<int>adjacencyList;
};


void Dijkstra(int n, Pozitie* poz);