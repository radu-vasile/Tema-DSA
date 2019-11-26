#include "TemaDSA.h"
using namespace std;
ifstream fin("input.txt");

int main()
{
	int n, k, it = 0, x;

	fin >> n;
	Pozitie* poz = new Pozitie[n * n]; //Cream un vector obiect,in fiecare obiect o sa introducem atat coordonatele pozitiei respective cat si costul;

	//Introducem coordonatele si costul pentru fiecare obiect
	for (int i = 0; i < n ; i++)
	{
		for (int j = 0; j < n ; j++)
		{
			fin >> k;
			poz[it].x = i;
			poz[it].y = j;
			poz[it].cost = k;
			it++;
		}
	}
	cout << "Choose one method: \n";
	cout << "1. Move right and down\n";
	cout << "2. Move left, right, up and down\n";

	cin >> x; //Alegem daca vrem sa avem in lista de adiacenta vecinii din toate directiile sau doar de jos si dreapta;

	for (int i = 0; i < it; i++)
	{
		for (int j = 0; j < it; j++)
		{
			if (i != j)
			{
				if (x == 1) { // daca am ales 1
					if ((poz[i].x + 1 == poz[j].x && poz[j].y == poz[i].y) || (poz[i].y + 1 == poz[j].y && poz[i].x == poz[j].x)) // adaugam in lista de adiacenta vecinii;
					{
						poz[i].adjacencyList.push_back(j);
					}
				}
				else //daca am ales 2
				{
					if ((poz[i].x + 1 == poz[j].x && poz[j].y == poz[i].y) || (poz[i].y + 1 == poz[j].y && poz[i].x == poz[j].x) || (poz[i].x - 1 == poz[j].x && poz[j].y == poz[i].y) || (poz[i].y - 1 == poz[j].y && poz[i].x == poz[j].x))
					{
						poz[i].adjacencyList.push_back(j);
					}
				}
			}
		}
	}
	Dijkstra(n, poz);

	return 0;
}