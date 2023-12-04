#pragma once
#include "disjointSet.h"
#include <unordered_map>
#include <set>
#include <bits/stdc++.h>
#include <float.h>
#include <iostream>
#include <climits>
#include <sstream>
#include <chrono>
#include <thread>
#include <atomic>

using namespace std;

typedef pair<City, double> cPair; // node, distance

class CityGraph {
private:
    atomic<bool> finished;
    string region;
    unordered_map<City, vector<pair<City, double>>, City::Hash> regionGraph; // weight will distance
    function<bool(const cPair&, const cPair&)> minDistanceComp = [] (const cPair &one, const cPair &two) {
        return one.second > two.second;
    };
    map<int, string> cityIDs;
    map<double, City> sortedLong;
    string printPath(City start, City end, unordered_map<City, cPair, City::Hash> parents, bool pathType){
        stack<City> roadtrip;
        City current = end;
        while(current != start){
            roadtrip.push(current);
            current = parents[current].first;
        }

        ostringstream output;
        streambuf* p_cout_streambuf = cout.rdbuf();
        cout.rdbuf(output.rdbuf());
        roadtrip.push(start);

        // testing country objects
        cout << "--------Start Country Information----------" << endl;
        start.getCountryObj();
        cout << "Start City WikiData Information: " << start.getWikiDataLink() << endl;
        cout << "--------End Country Information----------" << endl;
        end.getCountryObj();
        cout << "End City WikiData Information: " << start.getWikiDataLink() << endl;
        cout << "********************************************************" << endl;

        // print trip; false indicates Dijikstra's, true indicates Prims
        int step = 1;
        double distance = 0;
        if(pathType){
            while(!roadtrip.empty())
            {
                if (step > 1)
                {
                    distance += parents[roadtrip.top()].second;
                }
                cout << step << ". " << roadtrip.top().getName() << ", " << roadtrip.top().getCountryName() << " | Distance so far: " << distance << endl;
                roadtrip.pop();
                step++;
            }
        } else {
            while(!roadtrip.empty())
            {
                distance = parents[roadtrip.top()].second;
                cout << step << ". " << roadtrip.top().getName() << ", " << roadtrip.top().getCountryName() << " | Distance so far: " << distance << endl;
                roadtrip.pop();
                step++;
            }
        }
        cout << "Total distance travelled: " << distance << endl;
        cout.rdbuf(p_cout_streambuf);
        return output.str();
    }
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

    int getSize() {
        return regionGraph.size();
    }

    void insertCity(City &start) {
        sortedLong[start.getLongitude()] = start;
        auto lower_bound = sortedLong.lower_bound(start.getLongitude() - 1);
        auto upper_bound = sortedLong.upper_bound(start.getLongitude() + 1);

        regionGraph[start] = {};

        for(auto it = lower_bound; it != upper_bound; ++it){
            double dist = start.distanceBetween(it->second);
            if(dist <= 50){
                regionGraph[it->second].push_back(make_pair(start, dist));
                regionGraph[start].push_back(make_pair(it->second, dist));
            }
        }
    }

    string dijkstra(string st, string en) {
        // used stepik code for reference
        City start = findCity(st);
        City end = findCity(en);
        if(start == City() || end == City()){
            return "Hmmm, we couldn't find one of those cities. Check that it's spelled and formatted right!\n";
        }

        priority_queue<cPair, vector<cPair>, decltype(minDistanceComp)> pq(minDistanceComp);
        unordered_map<City, pair<City, double>, City::Hash> distance; // pair<Pred, Total Distance>
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

        finished = true;
        return printPath(start, end, distance, false);

    }

    string prim(string st, string en) {
        City start = findCity(st);
        City end = findCity(en);
        if(start == City() || end == City()){
            return "Hmmm, we couldn't find one of those cities. Check that it's spelled and formatted right!\n";
        }
        priority_queue<cPair, vector<cPair>, decltype(minDistanceComp)> pq(minDistanceComp);
        // start is our source vector
        unordered_map<City, cPair, City::Hash> parent;
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
                    parent[v] = make_pair(u, w);
                    pq.push(make_pair(v, parent[v].second));
                }
            }
        }

        return printPath(start, end, parent, true);
    }

    City findCity(string cityName) {
        for(auto city : regionGraph) {
            if(cityName == city.first.getName())
                return city.first;
        }
        return City();
    }

//    void showProgressBar(){
//        const int totalProgress = 50;
//        const int barWidth = 50;
//
//        while(!finished) {
//            for(int progress = 0; progress <= totalProgress *2; ++progress){
//                float percentage;
//                int barLength;
//
//                if(progress <= totalProgress) {
//                    percentage = (float)progress / totalProgress;
//                    barLength = (int)(percentage * barWidth);
//                } else {
//                    percentage = (float)(2 * totalProgress - progress) / totalProgress;
//                    barLength = (int)(percentage * barWidth);
//                }
//
//                cout << "[";
//                for(int i = 0; i < barWidth; ++i) {
//                    if(i < barLength){
//                        cout << "=";
//                    } else {
//                        cout << " ";
//                    }
//                }
//                cout << "] " << int(percentage * 100.0) << "%";
//                cout.flush();
//
//                this_thread::sleep_for(chrono::milliseconds(100)); //adjust for speed of bar
//            }
//
//            cout << endl;
//        }
//    }
//
//    void runD(string start, string end){
//        thread functionThread(&CityGraph::dijkstra, this, start, end);
//        thread progressBarThread(&CityGraph::showProgressBar, this);
//
//        functionThread.join();
//        progressBarThread.join();
//    }
};