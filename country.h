#pragma once
#include <string>
#include <vector>

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
    string flagSvg; // stores location of svg file
    // emoji - figure out how to store this (store as string I think)
    // shape - figure out how to store this (store as string I think)
public:
    // create constructor
    Country (string n, string r, string cap, string c, string t, string a) {
        name = n;
        region = r;
        capitol = cap;
        currency = c;
        timeZone = t;
        abbreviation = a;
        flagSvg = "../shapes/" + a + ".svg";
    }
    Country () {
        name = "";
        region = "";
        currency = "";
        timeZone = "";
        abbreviation = "";
        flagSvg = "";
    }

    void getCountryInfo () {
        cout << "Country: " << name << endl;
        cout << "Region: " << region << endl;
        cout << "Capitol: " << capitol << endl;
        cout << "Currency: " << currency << endl;
    }
};