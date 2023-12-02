#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class City {
private:
    string name;
    int id;
    // string population;
    // string timeZone;
    string countryName;
    double longitude;
    double latitude;
    double toRadians(const double &degree) {
        double one_deg = (M_PI) / 180;
        return (one_deg * degree);
    }
public:
    City(int d, string n, string cN, double lon, double lat) {
        id = d;
        name = n;
        countryName = cN;
        longitude = lon;
        latitude = lat;
    }
    string getName(){
        return name;
    }
    string getCountryName() {
        return countryName;
    }
    double getLatitude() {
        return latitude;
    }
    double getLongitude() {
        return longitude;
    }
    int getId() const{
        return id;
    }
    double distanceBetween(City a) {
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

        double rad = 3956; // in miles
        return distance * rad;
    }
    string findContinent(unordered_map<string, string> countryList){
        return countryList[countryName];
    }

    bool operator<(const City &city) const {
        return id < city.getId();
    }
};
