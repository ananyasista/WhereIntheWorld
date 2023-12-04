#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <filesystem>
#include "cityGraph.h"

using namespace std;
// how are we getting data and building our graphs to be used in our program

// https://www.codeproject.com/Articles/820116/Embedding-Python-program-in-a-C-Cplusplus-code
// https://docs.python.org/3/extending/embedding.html

City parseCsv(string &csvLine, unordered_map<string, Country> countryObjects) {
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
    return City(id, cityName, countryName, longitude, latitude, countryObjects[countryName]);
};



void getData(CityGraph &americas, CityGraph &polar, CityGraph &oceania, CityGraph &eurasica)
{
    //CityGraph americas("americas"), polar("polar"), oceania("oceania"), eurasica("eurasica");
    map<string, string> countryToRegion; // fill using countries.csv
    // create map of country name to country object which is to be used in parseCsv so I can add a country object
    unordered_map<string, Country> countryObjects;

    map<string, int> regionToGraph; // use when adding cities to a graph
    regionToGraph["Americas"] = 0;
    regionToGraph["Europe"] = 1;
    regionToGraph["Polar"] = 2;
    regionToGraph["Oceania"] = 3;
    regionToGraph["Asia"] = 4;
    regionToGraph["Africa"] = 5;


    //parse through countrytoregions and find the americas region
    //Need: name, 10, region
    ifstream fileCountries("../ContinentsData/countries.csv");
    string val;

    //hold countryToRegion
    //read and parse city file
    string line;
    while(getline(fileCountries, line)) {
        istringstream fileCountries(line);

        //read country name
        getline(fileCountries, val, ',');
        getline(fileCountries, val, ',');
        string countryName = val;
        // read abbreviation (3 letter version)
        getline(fileCountries, val, ',');
        string abrev = val;
        // skip to capitol
        for (int i = 0; i < 3; i++)
            getline(fileCountries, val, ',');
        // read capitol
        getline(fileCountries, val, ',');
        string cap = val;
        getline(fileCountries, val, ',');
        // read currency
        getline(fileCountries, val, ',');
        string curr = val;
        //skip to region
        for (int i = 0; i < 3; i++) {
            getline(fileCountries, val, ',');
        }

        //read region
        getline(fileCountries, val, ',');
        string region = val;
        // skip to timezone
        for (int i = 0; i < 3; i++)
            getline(fileCountries, val, ',');
        getline(fileCountries, val, ',');
        string timez = val;
        countryToRegion.emplace(countryName, region);
        Country c (countryName, region, cap, curr, timez, abrev);
        countryObjects[countryName] = c;
        //regionToGraph[countryToRegion[city.getCountryName()]].insertCity(city);
    }
    fileCountries.close();

//    //temp test
//    for(auto pair : countryToRegion) {
//        cout << "Country: " << pair.first << "Region: " << pair.second << endl;
//    }


    cout << "COUNTRIES HAVE PARSED------------------" << endl;
    //id, name, state_id, state_code, state_name, country_id, country_code, country_name, latitude, longitude, wikiDataId
    //Need: name, city code, country_name, lat, long
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

//    cout << countryToRegion["United States Minor Outlying Islands"] << endl;

    while(getline(file, line)) {
        //temp test
        City city = parseCsv(line, countryObjects);

//        cout << "ID: " << city.getId() << ", City Name: " << city.getName() << ", Country Name: " << city.getCountryName() << ", Latitude: " << city.getLatitude() << ", Longitude: " << city.getLongitude() << endl;
        //cityMap[city.getName()].emplace_back(city.getCountryName(), city.getLatitude());
//        regionToGraph["Americas"].insertCity(city);

        //americas.insertCity(city);

        switch(regionToGraph[countryToRegion[city.getCountryName()]]) {
            case 0:
                americas.insertCity(city);
//                cout << "Americas added" << endl;
                break;
            case 1:
                eurasica.insertCity(city);
//                cout << "Eurasica added" << endl;
                break;
            case 2:
                polar.insertCity(city);
//                cout << "Polar added" << endl;
                break;
            case 3:
                oceania.insertCity(city);
//                cout << "Oceania added" << endl;
                break;
            case 4:
                eurasica.insertCity(city);
//                cout << "Eurasica added" << endl;
                break;
            case 5:
                eurasica.insertCity(city);
//                cout << "Eurasica added" << endl;
                break;
            default:
                americas.insertCity(city);
        }
    }

    file.close();

}
