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
//    getData(americas, polar, oceania, eurasica, countryToRegion);
    progressBar display;
    display.runD(americas, polar, oceania, eurasica, countryToRegion);
    cout << "Region Graph Size: " << endl;
    cout << "Americas Size: " << americas.getSize() << endl;
    cout << "Polar Size: " << polar.getSize() << endl;
    cout << "Eur Size: " << eurasica.getSize() << endl;
    cout << "Oceania Size: " << oceania.getSize() << endl << endl;


    cout << "DIJKSTRA's --------------" << endl;
//    string start = "Tampa";
//    string end = "Jacksonville";
//    if(parseInput(start, "United States", end, "United States", countryToRegion)){
//        cout << americas.dijkstra(start, end);
//    }
//    string start1 = "Tampa, FL";
//    string end1 = "Jacksonville, FL";
//    if(parseInput(start1, "United States", end1, "United States", countryToRegion)){
//        string result = americas.dijkstra(start1, end1);
//        cout << result;
//        printTrip(result);
//    }

//    americas.dijkstra("Tampa, FL", "Jacksonville, FL");
//    americas.prim("Tampa, FL", "Jacksonville, FL");
//    americas.prim("Tampa, FL", "Edgewood, FL");
//    cout << "Sydney to Melbourne: " << endl;
//    oceania.dijkstra("Sydney, NSW", "Melbourne, VIC");
//    cout << "Los Angeles to Durango, Mexico: " << endl;
//    americas.dijkstra("Los Angeles, CA", "El Salto, DUR");
//    cout << "Toronto to Miami: " << endl;
//    americas.dijkstra("Toronto, ON", "Miami, FL");
    cout << "Rome to Stockholm: " << endl;
//    cout << eurasica.dijkstra("Rome, 62", "Stockholm, AB");
//    americas.runD("Tuscumbia, AL", "Tuskegee, AL");
//    cout << endl;
//    cout << "PRIMS --------------" << endl;
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
