#include <iostream>
#include "fetchData.h"

int main()
{
    CityGraph americas("Americas"), polar("Polar"), oceania("Oceania"), eurasica("eurasica");
    std::cout << "Hello, World!" << std::endl;

    //parse through countrytoregions and find the americas region
    //Need: name, 10, region
    ifstream file("../ContinentsData/countries.csv");
    string val;

    //read name
    for(int i = 0; i < 1; i++) {
        getline(file, val, ',');
    }
    getline(file, val);
    string countryName = val;

    //skip to region
    for(int i = 0; i < 10; i++) {
        getline(file, val, ',');
    }

    //read region
    getline(file, val);
    string region = val;

    //hold countryToRegion
    string line;
    while(getline(file, line)) {
        map<string, string> countryToRegion;
        countryToRegion.emplace(countryName, region);
    }
    file.close();


    //call getData with the regions graph
    getData(americas, polar, oceania, eurasica);
    americas.dijkstra("Miami", "Tampa");

    return 0;
}
