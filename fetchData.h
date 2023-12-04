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

    getline(iss, val, ',');
    string wiki = val;
    //city name + code
    string cityName = cName + ", " + cityCode;

    //city object
    return City(id, cityName, countryName, longitude, latitude, wiki, countryObjects[countryName]);
};



void getData(CityGraph &americas, CityGraph &polar, CityGraph &oceania, CityGraph &eurasica, unordered_map<string, string> &countryToRegion)
{
    // create map of country name to country object which is to be used in parseCsv so I can add a country object
    unordered_map<string, Country> countryObjects;

    unordered_map<string, int> regionToGraph; // use when adding cities to a graph
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
    }
    fileCountries.close();

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

    while(getline(file, line)) {
        City city = parseCsv(line, countryObjects);

        switch(regionToGraph[countryToRegion[city.getCountryName()]]) {
            case 0:
                americas.insertCity(city);
                break;
            case 1:
                eurasica.insertCity(city);
                break;
            case 2:
                polar.insertCity(city);
                break;
            case 3:
                oceania.insertCity(city);
                break;
            case 4:
                eurasica.insertCity(city);
                break;
            case 5:
                eurasica.insertCity(city);
                break;
            default:
                americas.insertCity(city);
        }
    }

    file.close();
}

bool parseInput(string startCity, string startCountry, string endCity, string endCountry, unordered_map<string, string> countryToRegion){
    string startRegion = countryToRegion[startCountry];
    string endRegion = countryToRegion[endCountry];

    //check that countries exist in our database
    if(startRegion == "" || endRegion == "" ){
        cout << "We couldn't find that country! Please check that it's spelled right." << endl;
        return false;
    }

    // make sure start and destination are on the same landmass
    if(startRegion != endRegion)
    {
        cout << "I don't think cars that can drive across the ocean have been made yet... please enter a destination that is connected by land!" << endl;
        return false;
    }

    return true;
}

void printTrip(string itinerary){
    ofstream tripFile;
    tripFile.open("itinerary.txt");
    tripFile << itinerary << endl << endl;
    tripFile << "  ---------------------------.\n"
                " `/\"\"\"\"/\"\"\"\"/|\"\"|'|\"\"||\"\"|   ' \\.\n"
                " /    /    / |__| |__||__|      |\n"
                "/----------=====================|\n"
                "| \\  /V\\  /    _.               |\n"
                "|()\\ \\W/ /()   _            _   |\n"
                "|   \\   /     / \\          / \\  |-( )\n"
                "=C========C==_| ) |--------| ) _/==] _-{Happy Driving!}_)\n"
                " \\_\\_/__..  \\_\\_/_ \\_\\_/ \\_\\_/__.__.\n"
                "--Line art by: TIM, from https://www.asciiart.eu/vehicles/cars--" << endl;

    cout << "Your itinerary has been downloaded!" << endl;
}
