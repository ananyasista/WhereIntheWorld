#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <filesystem>
#include "city.h"
#include "cityGraph.h"

using namespace std;
// how are we getting data and building our graphs to be used in our program

// https://www.codeproject.com/Articles/820116/Embedding-Python-program-in-a-C-Cplusplus-code
// https://docs.python.org/3/extending/embedding.html

City parseCsv(string &csvLine) {
    istringstream iss(csvLine);
    string val;

    //read id
    getline(iss, val, ',');
    int id;
    istringstream(val) >> id;

    //read city name
    getline(iss, val, ',');
    string cName = val;

    //skip to city code
    for(int i = 0; i < 1; i++) {
        getline(iss, val, ',');
    }

    //read city code
    getline(iss, val, ',');
    string cityCode = val;


    //skip to countryName
    for(int i = 0; i < 3; i++) {
        getline(iss, val, ',');
    }

    //read country name
    getline(iss, val, ',');
    string countryName = val;

    //read latitude & longitude
    getline(iss, val, ',');
    double latitude;
    istringstream(val) >> latitude;

    getline(iss, val, ',');
    double longitude;
    istringstream(val) >> longitude;

    //city name + code
    string cityName = cName + ", " + cityCode;

    //city object
    return City(id, cityName, countryName, longitude, latitude);
};



void getData(CityGraph &americas, CityGraph &polar, CityGraph &oceania, CityGraph &eurasica)
{
    //CityGraph americas("americas"), polar("polar"), oceania("oceania"), eurasica("eurasica");
    map<string, string> countryToRegion; // fill using countries.csv

    map<string, CityGraph> regionToGraph; // use when adding cities to a graph
    regionToGraph["Americas"] = americas;
    regionToGraph["Europe"] = eurasica;
    regionToGraph["Polar"] = polar;
    regionToGraph["Oceania"] = oceania;
    regionToGraph["Asia"] = eurasica;
    regionToGraph["Africa"] = eurasica;


    //parse through countrytoregions and find the americas region
    //Need: name, 10, region
    ifstream fileCountries("../ContinentsData/countries.csv");
    string val;

    //read name
    for(int i = 0; i < 1; i++) {
        getline(fileCountries, val, ',');
    }
    getline(fileCountries, val);
    string countryName = val;

    //skip to region
    for(int i = 0; i < 10; i++) {
        getline(fileCountries, val, ',');
    }

    //read region
    getline(fileCountries, val);
    string region = val;

    //hold countryToRegion
    //read and parse city file
    string line;
    while(getline(fileCountries, line)) {
        countryToRegion.emplace(countryName, region);
        //regionToGraph[countryToRegion[city.getCountryName()]].insertCity(city);
    }
    fileCountries.close();

    //id, name, state_id, state_code, state_name, country_id, country_code, country_name, latitude, longitude,
    // wikiDataId
    //Need: name, country_name, lat, long
    string citiesFile = "../ContinentsData/floridaCities.csv";

    //open csv file
    ifstream file(citiesFile);
    if(!file) {
        cout << "error" << endl;
        return;
    }
    // cout << "here" << endl;
    //Map to store city data
    // map<string, vector<pair<string, double>>> cityMap;


    while(getline(file, line)) {
        //temp test
        City city = parseCsv(line);

//        cout << "ID: " << city.getId() << ", City Name: " << city.getName() << ", Country Name: " << city.getCountryName() << ", Latitude: " << city.getLatitude() << ", Longitude: " << city.getLongitude() << endl;
        //cityMap[city.getName()].emplace_back(city.getCountryName(), city.getLatitude());
        // regionToGraph[countryToRegion[city.getCountryName()]].insertCity(city);
        americas.insertCity(city);
    }

    file.close();

}
