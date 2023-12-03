#pragma once
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <climits>
#include "city.h"

using namespace std;

typedef pair<City, double> cPair; // node, distance

class DisjointSet {
    map<City, City> parent;
    function<bool(const cPair&, const cPair&)> minDistanceComp = [] (const cPair &one, const cPair &two) {
        return one.second > two.second;
    };
public:
    multimap<City, pair<City, double>> makeSet(map<City, vector<pair<City, double>>>& graph) {
        // return a multimap
        multimap<City, pair<City, double>> edgeList;
        for(pair<City, vector<pair<City, double>>> city : graph) {
            parent[city.first] = city.first;
            for(auto cityList : city.second) {
                edgeList.insert({city.first, cityList});
            }
        }
        return edgeList;
    }
    //find root of the set in which vertex k belongs to
    City findRoot(City k) {
        if(parent[k] == k)
            return k;
        return findRoot(parent[k]);
    }
    //union two subsets that a and b are inside
    void unionSet(City a, City b) {
        // find roots of two sets in which vertex a and b belong to
        City x = findRoot(a);
        City y = findRoot(b);

        parent[y] = x;
    }
};