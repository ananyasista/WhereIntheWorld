#include "cityGraph.h"

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