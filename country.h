#pragma once
#include <string>

using namespace std;

class Country {
private:
    string name;
    string region;
    string capitol;
    string currency;
    string abbreviation;
    string timeZone;
    string flag; // stores location of image file
public:
    // create constructor
    Country (string n, string r, string cap, string c, string t, string a) {
        name = n;
        region = r;
        capitol = cap;
        currency = c;
        timeZone = t;
        abbreviation = a;
        flag = "../countryFlags/" + a + ".png";
    }
    Country () {
        name = "";
        region = "";
        currency = "";
        timeZone = "";
        abbreviation = "";
        flag = "";
    }

    void getCountryInfo () {
        cout << "Country: " << name << endl;
        cout << "Region: " << region << endl;
        cout << "Capitol: " << capitol << endl;
        cout << "Currency: " << currency << endl;
    }

    string getFlag() {
        return flag; // was going to be used but never got chance to implement idea for our frontend
    }
};