#pragma once
#include "disjointSet.h"
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <bits/stdc++.h>
#include <float.h>
#include <iostream>
#include <climits>

using namespace std;

typedef pair<City, double> cPair; // node, distance

class CityGraph {
    // maybe this should be represented at a graph class
    // then each instance will represent a continent and the nodes and edges are how all the countries connect and
    // border each other????
private:
    string region;
    map<City, vector<pair<City, double>>> regionGraph; // weight will distance
    function<bool(const cPair&, const cPair&)> minDistanceComp = [] (const cPair &one, const cPair &two) {
        return one.second > two.second;
    };
    map<int, string> cityIDs;
public:
    CityGraph(){
        region = "";
    }

    CityGraph(string regName) {
        region = regName;
    }
    string getName() {
        return region;
    }
    void insertCity(City &start) {
        regionGraph[start] = {};
        for(auto &city : regionGraph){
            if(city.first != start){
                if(start.distanceBetween(city.first) <= 50){
                    city.second.push_back(make_pair(start, start.distanceBetween(city.first)));
                    regionGraph[start].push_back(make_pair(city.first, start.distanceBetween(city.first)));
                }
            }
        }
    }

    void dijkstra(string st, string en) {
        // used stepik code for reference
        City start = findCity(st);
        City end = findCity(en);
        priority_queue<cPair, vector<cPair>, decltype(minDistanceComp)> pq(minDistanceComp);
        map<City, pair<City, double>> distance; // pair<Pred, Total Distance>
        for(auto city : regionGraph)
            distance.emplace(city.first, make_pair(City(), DBL_MAX));
        distance[start] = make_pair(City(), 0);
         // push start to pq
        pq.push(make_pair(start, 0)); // City node, distance
        while (!pq.empty()) {
            cPair curr = pq.top();
            pq.pop();
            City u = curr.first; // current node
            for (auto pair: regionGraph[u]) { // looking at neighbors
                City v = pair.first; // neighbor
                double w = pair.second; // weight of edge
                if (distance[v].second > (distance[u].second + w)) { // relaxing
                    distance[v] = make_pair(u, distance[u].second + w);
                    pq.push(make_pair(v, distance[v].second));
                }
            }
        }
        cout << regionGraph.size() << endl;
        cout << distance.size() << endl;
        // now distance is complete
        stack<City> roadtrip;
        City current = end;
        while(current != start){
            roadtrip.push(current);
            current = distance[current].first;
        }

        roadtrip.push(start);

        // print trip
        int step = 1;
        while(!roadtrip.empty()){
            cout << step << ". " << roadtrip.top().getName() << ", " << roadtrip.top().getCountryName() << " Distance"" Between: " << distance[roadtrip.top()].second << endl;
            roadtrip.pop();
            step++;
        }
    }
    void kruskal(string st, string en) {
        // use stepik module 8 solutions
        City start = findCity(st);
        City end = findCity(en);
        DisjointSet ds;
        multimap<City, pair<City, double>> edgeList = ds.makeSet(regionGraph);
        double totalDistance = 0;
        for(const auto& entry : edgeList){
            double w = entry.second.second;
            pair<City, City> p = make_pair(entry.first, entry.second.first);
            City u = p.first;
            City v = p.second;
            City x = ds.findRoot(u);
            City y = ds.findRoot(v);
            if(x != y) {
                totalDistance += w;
                ds.unionSet(x, y);
            }
        }
        stack<City> roadtrip;
        City current = end;
        while(current != start) {
            roadtrip.push(current);
            current = ds.findRoot(current);
        }

        roadtrip.push(start);

        // print trip
        int step = 1;
        while(!roadtrip.empty()){
            cout << step << ". " << roadtrip.top().getName() << ", " << roadtrip.top().getCountryName() << endl;
            // " Distance"" Between: " << distance[roadtrip.top()].second <<
            roadtrip.pop();
            step++;
        }
    }
    void prim(string st, string en) {
        City start = findCity(st);
        City end = findCity(en);
        priority_queue<cPair, vector<cPair>, decltype(minDistanceComp)> pq(minDistanceComp);
        // start is our source vector
        map<City, cPair> parent;
        for(auto city : regionGraph)
            parent.insert(make_pair(city.first, make_pair(City(),DBL_MAX)));
        set<City> inMst;
        pq.push(make_pair(start, 0)); // add source vertex to min heap

        while(!pq.empty()) {
            cPair uPair = pq.top();
            City u = pq.top().first;
            pq.pop();

            if (inMst.find(u) != inMst.end())
                continue;
            inMst.insert(u);
            for (auto pair: regionGraph[u]) {
                City v = pair.first; // child
                double w = pair.second;
                if(inMst.find(v) == inMst.end() && parent[v].second > w) {
                    parent[v] = uPair;
                    pq.push(make_pair(v, parent[v].second));
                }
            }
        }
        stack<City> roadtrip;
        double totalDistance = 0;
        City current = end;
        while(current != start){
            roadtrip.push(current);
            totalDistance += parent[current].second;
            current = parent[current].first;
        }

        roadtrip.push(start);

        // print trip
        int step = 1;
        while(!roadtrip.empty()){
            cout << step << ". " << roadtrip.top().getName() << ", " << roadtrip.top().getCountryName() << endl;
            roadtrip.pop();
            step++;
        }
        cout << "Total Distance To Travel: " << totalDistance << endl;
    }

    City findCity(string cityName) {
        for(auto city : regionGraph) {
            if(cityName == city.first.getName())
                return city.first;
        }
        return City();
    }
};