#include <string>
#include <vector>
#include "city.h"

using namespace std;

class Country {
private:
    string name;
    City capitol; // can get population and capitol name from this class
    vector<string> languages;
    string currency;
    string timeZone;
    vector<City> cities;
    bool connected; // says whether a given country is connected to other countries
    // neighbors?? keeps track of bordering countries; maybe do in graph class
    // emoji - figure out how to store this (store as string I think)
    // shape - figure out how to store this (store as string I think)
public:
    // create constructor

    void getAllCities(); // maybe have it return a vector instead?
    void getAllData(); // returns all the data, so when we search for a country
    void addCities(); // adds cities for this country object
    void findCity(string cityName); // returns a specific city
};