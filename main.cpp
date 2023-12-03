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
    cout << "DIJKSTRA's --------------" << endl;
    cout << "Paris to Rome: " << endl;
    eurasica.dijkstra("Paris, IDF", "Rome, 62");
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
