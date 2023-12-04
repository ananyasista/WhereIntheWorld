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
    americas.dijkstra("Tampa, FL", "Jacksonville, FL");
    cout << "PRIM's -------------------" << endl;
    americas.prim("Tampa, FL", "Jacksonville, FL");
    cout << "iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii" << endl;
    americas.prim("Tampa, FL", "Edgewood, FL");
//    cout << "Sydney to Melbourne: " << endl;
//    oceania.dijkstra("Sydney, NSW", "Melbourne, VIC");
//    cout << "PRIMS --------------" << endl;
//    oceania.prim("Sydney, NSW", "Melbourne, VIC");
//    cout << "Los Angeles to Durango, Mexico: " << endl;
//    americas.dijkstra("Los Angeles, CA", "El Salto, DUR");
//    cout << "Toronto to Miami: " << endl;
//    americas.dijkstra("Toronto, ON", "Miami, FL");
//    cout << "Rome to Stockholm: " << endl;
//    eurasica.dijkstra("Rome, 62", "Stockholm, AB");
//    eurasica.prim("Rome, 62", "Stockholm, AB");


    return 0;
}
