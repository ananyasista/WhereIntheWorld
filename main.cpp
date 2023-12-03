#include <iostream>
#include "fetchData.h"

int main()
{
    CityGraph americas("Americas"), polar("Polar"), oceania("Oceania"), eurasica("eurasica");
    std::cout << "Hello, World!" << std::endl;
    //call getData with the regions graph
    getData(americas, polar, oceania, eurasica);
    americas.dijkstra("Tampa, FL", "Jacksonville, FL");

    return 0;
}
