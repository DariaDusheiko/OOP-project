#include <iostream>
#include "Graph.h"
#include "Phone.h"
#include "Computer.h"
#include "Tablet.h"

using namespace std;

int main() {
    Graph g(0);
    
    string graphFile, ordersFile;
    
    cout << "Enter the name of the file to load the graph: ";
    cin >> graphFile;
    g.readGraph(graphFile);
    cout << endl;

    cout << "Enter the name of the file to load the orders: ";
    cin >> ordersFile;
    vector<Order> orders = g.readOrders(ordersFile);
    cout << endl;

    int managerCity, garageCity, phoneCity, computerCity, tabletCity;

    cout << "Enter the city for the manager: ";
    cin >> managerCity;

    cout << "Enter the city for the garage: ";
    cin >> garageCity;

    cout << "Enter the city for the phone warehouse: ";
    cin >> phoneCity;

    cout << "Enter the city for the computer warehouse: ";
    cin >> computerCity;

    cout << "Enter the city for the tablet warehouse: ";
    cin >> tabletCity;

    cout << endl;

    Manager manager(managerCity);
    Garage garage(garageCity);
    Phone phone(phoneCity);
    Computer computer(computerCity);
    Tablet tablet(tabletCity);

    int i = 1;
    for (Order order : orders) {
        cout << i << " order:\n";
        g.showPath(manager, garage, phone, computer, tablet, order.city, order.product, order.type);
        cout << endl;
        i++;
    }

    return 0;
}
