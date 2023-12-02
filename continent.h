#include "country.h"
#include "unordered_map"

class Continent {
    // maybe this should be represented at a graph class
    // then each instance will represent a continent and the nodes and edges are how all the countries connect and
    // border each other????
private:
    string continentName;
    unordered_map<Country, vector<pair<Country, int>>> continentMap; // weight will distance from capitols (i think)
public:
    void insertCountry(Country to, Country from);
};