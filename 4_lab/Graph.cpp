#include <iostream>
#include <limits>
#include <algorithm>
#include <fstream>
#include "Graph.h"

using namespace std;

Graph::Graph(int vertices) : vertices(vertices) {
    adjList.resize(vertices);
}

Graph::~Graph() {} 

void Graph::addEdge(int u, int v, int weight) {
    adjList[u].emplace_back(v, weight);
    adjList[v].emplace_back(u, weight); 
}

pair<int, vector<int>> Graph::dijkstra(int start, int end) {
    vector<int> dist(vertices, numeric_limits<int>::max());
    vector<int> prev(vertices, -1);
    vector<bool> visited(vertices, false);

    dist[start] = 0;
    for (int i = 0; i < vertices - 1; ++i) {
        int minDist = numeric_limits<int>::max();
        int minIndex = -1;
        for (int j = 0; j < vertices; ++j) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                minIndex = j;
            }
        }
        if (minIndex == -1) break; 
        visited[minIndex] = true;
        for (const auto& neighbor : adjList[minIndex]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (!visited[v] && dist[minIndex] + weight < dist[v]) {
                dist[v] = dist[minIndex] + weight;
                prev[v] = minIndex; 
            }
        }
    }

    vector<int> path;
    for (int at = end; at != -1; at = prev[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());
    return { dist[end], path }; 
}

void Graph::showPath(const Manager& manager, const Garage& garage, const Phone& phone, const Computer& computer, const Tablet& tablet, int destination, const string& productType, const string& orderType) {
    int managerCity = manager.getCity();
    int garageCity = garage.getCity();
    int warehouseCity = -1;

    if (productType == "phone") {
        warehouseCity = phone.getCity(); 
    }
    else if (productType == "computer") {
        warehouseCity = computer.getCity(); 
    }
    else if (productType == "tablet") {
        warehouseCity = tablet.getCity(); 
    }
    else {
        cout << "Invalid product type." << endl;
        return;
    }
    
    auto resultToWarehouse = dijkstra(managerCity, warehouseCity);
    if (resultToWarehouse.first != numeric_limits<int>::max()) {
        cout << "Total distance from manager (City " << managerCity << ") to warehouse (City " << warehouseCity << "): " << resultToWarehouse.first << endl;
        cout << "Path from manager (City " << managerCity << ") to warehouse (City " << warehouseCity << "): ";
        for (int city : resultToWarehouse.second) {
            cout << city << " ";
        }
        cout << endl;
    }
    else {
        cout << "No available path from manager (City " << managerCity << ") to warehouse (City " << warehouseCity << ")." << endl;
    }

    if (orderType == "purchase"){
        auto resultToWarehouse = dijkstra(garageCity, warehouseCity);
        auto resultToDestination = dijkstra(warehouseCity, destination);

        if (resultToWarehouse.first != numeric_limits<int>::max() && resultToDestination.first != numeric_limits<int>::max()) {
            int totalDistance = resultToWarehouse.first + resultToDestination.first;
            cout << "Total distance from garage (City " << garageCity << ") to warehouse (City " << warehouseCity << ") and then to destination (City " << destination << "): " << totalDistance << endl;
            cout << "Path from garage (City " << garageCity << ") to warehouse (City " << warehouseCity << "): ";
            for (int city : resultToWarehouse.second) {
                cout << city << " ";
            }
            cout << " ";
            cout << "Path from warehouse (City " << warehouseCity << ") to destination (City " << destination << "): ";
            for (int city : resultToDestination.second) {
                cout << city << " ";
            }
            cout << endl;
        }
        else {
            cout << "No available path from garage (City " << garageCity << ") to warehouse (City " << warehouseCity << ") or from warehouse (City " << warehouseCity << ") to destination (City " << destination << ")." << endl;
        }
    }
    else {
        auto resultToDestination = dijkstra(garageCity, destination);
        if (resultToDestination.first != numeric_limits<int>::max()) {
            cout << "Total distance from garage (City " << garageCity << ") to destination (City " << destination << "): " << resultToDestination.first << endl;
            cout << "Path from garage (City " << garageCity << ") to destination (City " << destination << "): ";
            for (int city : resultToDestination.second) {
                cout << city << " ";
            }
            cout << endl;
        }
        else {
            cout << "No available path from garage (City " << garageCity << ") to destination (City " << destination << ")." << endl;
        }
    }
}

void Graph::readGraph(const string& filename) {
    ifstream file(filename); 
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return;
    }

    file >> vertices; 
    adjList.clear(); 
    adjList.resize(vertices);

    int u, v, weight;
    while (file >> u >> v >> weight) {
        addEdge(u, v, weight);
    }

    file.close(); 
    cout << "Graph data successfully loaded from file: " << filename << endl;
}

vector<Order> Graph::readOrders(const string& filename) {
    vector<Order> orders;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return orders;
    }

    string type, product;
    int city;
    while (file >> type >> city >> product) {
        if (type != "sale" && type != "purchase") {
            cerr << "Error: invalid order type in file: " << type << endl;
            continue;
        }
        orders.push_back({ type, city, product });
    }

    file.close(); 
    cout << "Orders successfully loaded from file: " << filename << endl;
    return orders;
}
