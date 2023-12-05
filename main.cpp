#include <iostream>
#include "fetchData.h"

int main()
{
    CityGraph americas("Americas");
    CityGraph polar("Polar");
    CityGraph oceania("Oceania");
    CityGraph eurasica("eurasica");
    unordered_map<string, string> countryToRegion;
    std::cout << "Hello, World!" << std::endl;
    //call getData with the regions graph
    getData(americas, polar, oceania, eurasica, countryToRegion);
    cout << "Region Graph Size: " << endl;
    cout << "Americas Size: " << americas.getSize() << endl;
    cout << "Polar Size: " << polar.getSize() << endl;
    cout << "Eur Size: " << eurasica.getSize() << endl;
    cout << "Oceania Size: " << oceania.getSize() << endl << endl;


    cout << "DIJKSTRA's --------------" << endl;
    string start = "Rome, 62";
    string end = "Stockholm, AB";
    if(parseInput(start, "Ilkj", end, "Sweden", countryToRegion)){
        vector<string> output = eurasica.dijkstra(start, end);
        cout << output[1] << output[2] << output[0];
    }
    string start1 = "Rome, 62";
    string end1 = "Stockholm, AB";
    if(parseInput(start1, "Italy", end1, "Sweden", countryToRegion)){
        vector<string> output = eurasica.dijkstra(start1, end1);
        cout << output[1] << output[2] << output[0];
        printTrip(output);
    }

    cout << "PRIMS --------------" << endl;

//    americas.dijkstra("Tampa, FL", "Jacksonville, FL");
    if(parseInput(start1, "Italy", end1, "Sweden", countryToRegion)){
        vector<string> output = eurasica.prim(start1, end1);
        cout << output[1] << output[2] << output[0];
        printTrip(output);
    }
//    americas.prim("Tampa, FL", "Edgewood, FL");
//    cout << "Sydney to Melbourne: " << endl;
//    oceania.dijkstra("Sydney, NSW", "Melbourne, VIC");
//    cout << "Los Angeles to Durango, Mexico: " << endl;
//    americas.dijkstra("Los Angeles, CA", "El Salto, DUR");
//    cout << "Toronto to Miami: " << endl;
//    americas.dijkstra("Toronto, ON", "Miami, FL");
//    cout << "Rome to Stockholm: " << endl;
//    cout << eurasica.dijkstra("Rome, 62", "Stockholm, AB");
//    cout << endl;

//    cout << "Sydney to Melbourne: " << endl;
//    oceania.prim("Sydney, NSW", "Melbourne, VIC");
//    cout << "Los Angeles to Durango, Mexico: " << endl;
//    americas.prim("Los Angeles, CA", "El Salto, DUR");
//    cout << "Toronto to Miami: " << endl;
//    americas.prim("Toronto, ON", "Miami, FL");
//    cout << "Rome to Stockholm: " << endl;
//    cout << eurasica.prim("Rome, 62", "Stockholm, AB");
    return 0;
}
