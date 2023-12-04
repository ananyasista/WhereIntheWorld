#pragma once
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <climits>
#include "city.h"
#include <chrono>
#include <thread>
#include <atomic>

using namespace std;

typedef pair<City, double> cPair; // node, distance

//class DisjointSet {
//    map<City, City> parent;
//    function<bool(const cPair&, const cPair&)> minDistanceComp = [] (const cPair &one, const cPair &two) {
//        return one.second > two.second;
//    };
//public:
//    multimap<double, pair<City, City>> makeSet(map<City, vector<pair<City, double>>>& graph) {
//        // return a multimap
//        multimap<double, pair<City, City>> edgeList;
//        for(pair<City, vector<pair<City, double>>> city : graph) {
//            parent[city.first] = city.first;
//            for(auto cityList : city.second) {
//                edgeList.insert({cityList.second, {city.first, cityList.first}});
//            }
//        }
//        return edgeList;
//    }
//    // find root of the set in which vertex k belongs to
//    City findRoot(City k) {
//        if(parent[k] == k)
//            return k;
//        return findRoot(parent[k]);
//    }
//    //union two subsets that a and b are inside
//    void unionSet(City a, City b) {
//        // find roots of two sets in which vertex a and b belong to
//        City x = findRoot(a);
//        City y = findRoot(b);
//
//        parent[y] = x;
//    }
//
//    City returnParent(City start){
//        return parent[start];
//    }
//};

//atomic<bool> finished(false);

//put bool above as parameter reference to Dijkstras and Prims, set to true at end

void myFunction(atomic<bool> &status) {
    for(int i = 0; i <= 100; ++i){
        this_thread::sleep_for(chrono::milliseconds(50));
    }

    status = true;
}

void showProgressBar(atomic<bool> status){
    const int totalProgress = 50;
    const int barWidth = 50;

    while(!status) {
        for(int progress = 0; progress <= totalProgress *2; ++progress){
            float percentage;
            int barLength;

            if(progress <= totalProgress) {
                percentage = (float)progress / totalProgress;
                barLength = (int)(percentage * barWidth);
            } else {
                percentage = (float)(2 * totalProgress - progress) / totalProgress;
                barLength = (int)(percentage * barWidth);
            }

            cout << "[";
            for(int i = 0; i < barWidth; ++i) {
                if(i < barLength){
                    cout << "=";
                } else {
                    cout << " ";
                }
            }
            cout << "] " << int(percentage * 100.0) << "%";
            cout.flush();

            this_thread::sleep_for(chrono::milliseconds(100)); //adjust for speed of bar
        }

        cout << endl;
    }
}

//when running functions in main, do the following:
thread functionThread();
