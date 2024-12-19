#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include "Order.h"
#include "Manager.h"
#include "Garage.h"
#include "Phone.h"
#include "Computer.h"
#include "Tablet.h"

using namespace std;

class Graph {
public:
    Graph(int vertices);
    ~Graph(); 
    void addEdge(int u, int v, int weight);
    pair<int, vector<int>> dijkstra(int start, int end); 
    void showPath(const Manager& manager, const Garage& garage, const Phone& phone, const Computer& computer, const Tablet& tablet, int destination, const string& productType, const string& orderType);
    void readGraph(const string& filename);
    vector<Order> readOrders(const string& filename);

private:
    int vertices;
    vector<vector<pair<int, int>>> adjList; 
};

#endif // GRAPH_H
