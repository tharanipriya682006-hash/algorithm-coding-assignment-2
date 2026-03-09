#include <iostream>
#include <vector>
#include <climits>
#include <algorithm> // ✅ Add this line for next_permutation
using namespace std;

int travellingSalesman(vector<vector<int>> &graph, int startCity) {
    int numCities = graph.size();

    vector<int> cities;
    for (int i = 0; i < numCities; i++) {
        if (i != startCity)
            cities.push_back(i);
    }

    int minPathCost = INT_MAX;

    do {
        int currentCost = 0;
        int currentCity = startCity;

        for (int i = 0; i < cities.size(); i++) {
            currentCost += graph[currentCity][cities[i]];
            currentCity = cities[i];
        }

        currentCost += graph[currentCity][startCity];

        if (currentCost < minPathCost)
            minPathCost = currentCost;

    } while (next_permutation(cities.begin(), cities.end()));

    return minPathCost;
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 15, 20, 25},
        {10, 0, 35, 25, 30},
        {15, 35, 0, 30, 5},
        {20, 25, 30, 0, 15},
        {25, 30, 5, 15, 0}
    };

    int startCity = 0;
    int minCost = travellingSalesman(graph, startCity);

    cout << "Minimum cost of travelling salesman tour: " << minCost << endl;

    return 0;
}
