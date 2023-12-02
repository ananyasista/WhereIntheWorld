#include "city.h"
#include <unordered_map>
// #include <priority_queue>
#include <unordered_set>
#include <set>
#include <bits/stdc++.h>
#include <float.h>
using namespace std;

typedef pair<City, double> cPair;

class CityGraph {
    // maybe this should be represented at a graph class
    // then each instance will represent a continent and the nodes and edges are how all the countries connect and
    // border each other????
private:
    string region;
    map<City, vector<pair<City, double>>> regionGraph; // weight will distance
//    auto minDistanceComp = [] (const cPair &one, const cPair &two) {
//        return one.second > two.second;
//    };


public:
    CityGraph(string regName) {
        region = regName;
    }
    void insertCity(City start, City end) {
        if(start.distanceBetween(end) <= 50)
        {
            regionGraph[start].push_back(std::make_pair(end, start.distanceBetween(end)));
            if (regionGraph.find(end) == regionGraph.end())
                regionGraph[end] = {};
        }
    }
    void dijkstra(City start, City end) {
        // priority_queue<cPair, vector<cPair>, decltype(minDistanceComp)> pq(minDistanceComp);

        // specify source vertex S == start
        // initialize two arrays and two sets
        set<City> visited; // this is set S
        set<City> processing; // this is set V-S ver
        map<City, double> distance;
        map<City, City> predecessor;

        for(auto location : regionGraph) {
            distance[location.first] = DBL_MAX;
            processing.insert(location.first);
        }
        distance[start] = 0;
        // finish this
    }
    void prim(City start, City end) {
        // start after lunch
    }
};