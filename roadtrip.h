#include <iostream>
#include <fstream>
using namespace std;
// have a boolean keeping track of which algorithm is being used

// calculating distance function
// will check first which algorithm we want to use, then run that algorithm

// dijkstra's function

// prim's function

// edges will be calculated using this formula:
// https://www.geeksforgeeks.org/program-distance-two-points-earth/
// or acos(sin(lat1)*sin(lat2)+cos(lat1)*cos(lat2)*cos(lon2-lon1))*6371
// https://stackoverflow.com/questions/27928/calculate-distance-between-two-latitude-longitude-points-haversine-formula
// 6371 is earth's radius in km (kilometers)

// display itinerary function
// shows all the cities and countries you will travel through

// will need to have a vector that holds all the continent graphs

//void bellmanFord(string st, string en) {
//    City start = findCity(st);
//    City end = findCity(en);
//    map<City, cPair> distance; // pair<Pred, Total Distance>
//    for(auto city : regionGraph)
//        distance[city.first] = make_pair(City(), DBL_MAX);
//    distance[start] = make_pair(City(), 0);
//
//    // relax all edges
//    for(int i = 0; i < regionGraph.size() - 1; ++i) {
//        for (auto vertex: regionGraph) {
//            City curr = vertex.first;
//            for (auto edge: vertex.second) {
//                City neighbor = edge.first; // destination
//                double w = edge.second;
//                if (distance[curr].second != DBL_MAX && distance[curr].second + w < distance[neighbor].second) {
//                    distance[neighbor] = make_pair(curr, distance[curr].second + w);
//                }
//            }
//        }
//    }
//
//    // check for negative cycles; above doesn't guarantee shortest distance if graph doesn't contain negative
//    // weight cycle. if we get shorter path, then there is a cycle
//    // but since we don't have any negative weight we will ignore this step
//
////        for (auto vertex: regionGraph)
////        {
////            for (auto edge: vertex.second)
////            {
////                City u = vertex.first; // source not changing
////                City v = edge.first; // destination
////                double w = edge.second;
////                if (distance[u].second != DBL_MAX && distance[u].second + w < distance[v].second)
////                {
////                    cout << "Graph contains negative weight cycle" << endl;
////                    return;
////                }
////            }
////        }
//    stack<City> roadtrip;
//    City current = end;
//    while(current != start){
//        roadtrip.push(current);
//        current = distance[current].first;
//    }
//
//
//    // print trip
//    int step = 1;
//    while(!roadtrip.empty()){
//        cout << step << ". " << roadtrip.top().getName() << ", " << roadtrip.top().getCountryName() << " Distance"" Between: " << distance[roadtrip.top()].second << endl;
//        roadtrip.pop();
//        step++;
//    }
//}
//    void kruskal(string st, string en) {
//        // use stepik module 8 solutions
//        City start = findCity(st);
//        City end = findCity(en);
//        map<City, vector<cPair>> mst;
////        DisjointSet ds;
//////        multimap<double, pair<City, City>> edgeList = ds.makeSet(regionGraph);
////        double totalDistance = 0;
////        for(const auto& entry : edgeList){
////            double w = entry.first;
////            pair<City, City> p = entry.second;
////            City u = p.first;
////            City v = p.second;
////            City x = ds.findRoot(u);
////            City y = ds.findRoot(v);
////            if(x != y) {
////                mst[u].push_back(make_pair(v, w));
////                mst[v].push_back(make_pair(u, w));
////                ds.unionSet(x, y);
////            }
////        }
//
//        map<City, City> parent;
//        map<City, int> rank;
//
//        for(auto city : regionGraph){
//            parent[city.first] = city.first;
//            rank[city.first] = 0;
//        }
//
//        for(auto edge : edgeList){
//            City u = edge.second.first;
//            City v = edge.second.second;
//
//            City set_u = find(u, parent);
//            City set_v = find(v, parent);
//
//            if(set_u != set_v){
//                mst[u].push_back(make_pair(v, edge.first));
//                merge(set_u, set_v, parent, rank);
//            }
//
//        }
//
//        //dfs from kapoor's lecture
//        set<City> visited;
//        stack<City> s;
//        s.push(start);
//        visited.insert(start);
//        map<City, cPair> relations;
//        //parent[start] = make_pair(City(), -1);
//        double kTotalDistance = 0;
//
//        while(!s.empty())
//        {
//            City u = s.top();
//            s.pop();
//
//            for (auto pair: mst[u])
//            {
//                City v = pair.first;
//                if (visited.find(v) == visited.end())
//                {
//                    visited.insert(v);
//                    relations[v] = make_pair(u, pair.second);
//                    s.push(v);
//                }
//            }
//        }
//
//        stack<City> roadtrip;
//        City current = end;
//        while(current != start) {
//            roadtrip.push(current);
//            kTotalDistance += relations[current].second;
//            current = relations[current].first;
//        }
//
//        roadtrip.push(start);
//
//        // print trip
//        int step = 1;
//        while(!roadtrip.empty()){
//            cout << step << ". " << roadtrip.top().getName() << ", " << roadtrip.top().getCountryName() <<
//            "Distance Between: " << relations[roadtrip.top()].second << endl;
//            roadtrip.pop();
//            step++;
//        }
//        cout << "Total Distance: " << kTotalDistance << endl;
//    }


//City find(City child, map<City, City> parent){
//    if(child != parent[child]){
//        parent[child] = find(parent[child], parent);
//    }
//    return parent[child];
//}
//
//void merge(City x, City y, map<City, City> &parent, map<City, int> &rank)
//{
//    x = find(x, parent);
//    y = find(y, parent);
//
//    if (rank[x] > rank[y])
//    {
//        parent[y] = x;
//    }
//    else
//    {
//        parent[x] = y;
//    }
//
//    if (rank[x] == rank[y])
//    {
//        rank[y]++;
//    }
//}

