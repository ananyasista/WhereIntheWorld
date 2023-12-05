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
    // parsing our city csv lines and creates city objects to be inserted in to a cityGraph object
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



void getData(CityGraph &americas, CityGraph &polar, CityGraph &oceania, CityGraph &eurasica, unordered_map<string, string> &countryToRegion, unordered_map<string, int> regionToGraph)
{
    // create map of country name to country object which is to be used in parseCsv so I can add a country object
    unordered_map<string, Country> countryObjects;

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

    // cout << "COUNTRIES HAVE PARSED------------------" << endl;
    //id, name, state_id, state_code, state_name, country_id, country_code, country_name, latitude, longitude, wikiDataId
    //Need: name, city code, country_name, lat, long
    string citiesFile = "../ContinentsData/cities.csv";

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

vector<string> parseInput(string startCity, string startCountry, string endCity, string endCountry, unordered_map<string, string> countryToRegion){
    // validating user input
    string startRegion = countryToRegion[startCountry];
    string endRegion = countryToRegion[endCountry];
    vector<string> output;

    //check that countries exist in our database
    if(startRegion == "" || endRegion == "" ){
        output.push_back("We couldn't find that country!\nPlease check that it's spelled right.\n");
        output.push_back("");
        output.push_back("");
        return output;
    }

    // make sure start and destination are on the same landmass
    if(startRegion != endRegion)
    {
        output.push_back("I don't think cars that can drive across\n the ocean have been made yet... \nplease enter a destination that is connected by land!\n");
        output.push_back("");
        output.push_back("");
        return output;
    }

    output.push_back("");
    output.push_back("");
    output.push_back("");
    return output;

}

void printTrip(vector<string> itinerary){
    // creates a downloadable text file with the trip path
    ofstream tripFile;
    tripFile.open("itinerary.txt");
    tripFile << itinerary[1] << itinerary[2] << itinerary[0] << endl << endl;
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
