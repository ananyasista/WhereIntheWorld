#pragma once
#include <string>

using namespace std;
// update this class to properly represent our idea
class Country {
private:
    string name;
    string region; // maybe
    string capitol;
    string currency;
    string abbreviation;
    string timeZone; // maybe
    string flag; // stores location of svg file
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
        return flag;
    }
};