#include <iostream>
#include "fetchData.h"

int main()
{
    CityGraph americas("Americas");
    CityGraph polar("Polar");
    CityGraph oceania("Oceania");
    CityGraph eurasica("eurasica");
    std::cout << "Hello, World!" << std::endl;
    //call getData with the regions graph
    getData(americas, polar, oceania, eurasica);
    cout << "Region Graph Size: " << endl;
    cout << "Americas Size: " << americas.getSize() << endl;
    cout << "Polar Size: " << polar.getSize() << endl;
    cout << "Eur Size: " << eurasica.getSize() << endl;
    cout << "Oceania Size: " << oceania.getSize() << endl;

//    americas.prim("Tampa, FL", "Jacksonville, FL");
    // cout << "BELLMAN FORD----------------" << endl;
//    americas.bellmanFord("Tampa, FL", "Jacksonville, FL");
    cout << "DIJKSTRA's --------------" << endl;
    cout << "Sydney to Melbourne: " << endl;
    oceania.dijkstra("Sydney, NSW", "Melbourne, VIC");
    // cout << "Bellman-Ford's --------------" << endl;
    // oceania.bellmanFord("Sydney, NSW", "Melbourne, VIC");
    cout << "PRIMS --------------" << endl;
    oceania.prim("Sydney, NSW", "Melbourne, VIC");
//    cout << "Los Angeles to Durango, Mexico: " << endl;
//    americas.dijkstra("Los Angeles, CA", "El Salto, DUR");
//    cout << "Toronto to Miami: " << endl;
//    americas.dijkstra("Toronto, ON", "Miami, FL");
//    cout << "Toronto to Miami: " << endl;
//    americas.dijkstra("Toronto, ON", "Miami, FL");
//    americas.dijkstra("Miami Gardens, FL", "Carol City, FL");
//    cout << "KRUSKAL's --------------" << endl;
//    americas.kruskal("Villano Beach, FL", "Jacksonville, FL");
//    cout << "Toronto to Miami: " << endl;
//    americas.kruskal("Toronto, ON", "Miami, FL");
//    cout << "Los Angeles to Durango Mexico: " << endl;
//    americas.kruskal("Los Angeles, CA", "El Salto, DUR");
//    cout << "Toronto to Miami: " << endl;
//    americas.kruskal("Toronto, ON", "Miami, FL");
//    cout << "Toronto to Miami: " << endl;
//    americas.kruskal("Toronto, ON", "Miami, FL");

    return 0;
}
