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
    cout << "DIJKSTRA's --------------" << endl;
    americas.dijkstra("Miami Gardens, FL", "Coral City, FL");
    cout << "KRUSKAL's --------------" << endl;
//    americas.kruskal("Vilano Beach, FL", "Jacksonville, FL");
    return 0;
}
