#pragma once
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <unordered_map>
#include "country.h"

using namespace std;

class City {
private:
    string name;
    int id;
    string countryName;
    double longitude;
    double latitude;
    double toRadians(const double &degree) {
        double one_deg = (M_PI) / 180;
        return (one_deg * degree);
    }
    Country country;
    string wikiDataLink;
public:
    City(int d, string n, string cN, double lon, double lat, string wd, Country c) {
        id = d;
        name = n;
        countryName = cN;
        longitude = lon;
        latitude = lat;
        wikiDataLink = "https://www.wikidata.org/wiki/" + wd;
        country = c;
    }

    City() { // default constructor
        id = -1;
        name = "";
        countryName = "";
        longitude = -1;
        latitude = -1;
        wikiDataLink = "";
    }

    string getName() const {
        return name;
    }

    string getCountryName() const {
        return countryName;
    }

    double getLatitude() const {
        return latitude;
    }

    double getLongitude() const {
        return longitude;
    }

    int getId() const{
        return id;
    }

    void getCountryObj() {
        country.getCountryInfo();
    }

    string getWikiDataLink() {
        return wikiDataLink;
    }

    double distanceBetween(City a) {
        // calculates distance between two cities based on lat and long
        // got formula of how to calculate from:
        // https://www.geeksforgeeks.org/program-distance-two-points-earth/
        // convert to radians
        double lat1 = toRadians(latitude);
        double long1 = toRadians(longitude);
        double lat2 = toRadians(a.getLatitude());
        double long2 = toRadians(a.getLongitude());

        double dlong = long2 - long1;
        double dlat = lat2 - lat1;

        double distance = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlong / 2), 2);

        distance = 2 * asin(sqrt(distance));

        double rad = 3956; // help with putting result in miles
        return distance * rad;
    }

    bool operator<(const City &city) const {
        return id < city.getId();
    }

    bool operator!=(const City &city) const {
        return id != city.getId();
    }

    bool operator==(const City &city) const {
        return id == city.getId();
    }

    struct Hash {
        // our hash to create an unordered map with City objects as the key
        size_t operator()(const City& city) const {
            size_t hashValue = 0;
            hashValue ^= hash<string>{}(city.name);
            hashValue ^= hash<int>{}(city.id);
            hashValue ^= hash<string>{}(city.countryName);
            hashValue ^= hash<double>{}(city.longitude);
            hashValue ^= hash<double>{}(city.latitude);

            return hashValue;
        }
    };
};
