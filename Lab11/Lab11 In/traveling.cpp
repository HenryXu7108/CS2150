//skeleton code from traveling-skeleton.cpp
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#include "middleearth.h"
/**
 *@brief solve a traveling salesman problem
 *@return return the shortest route and distance
 *@todo need to write acceptence test 
 *@author Wenhao Xu
 *@file traveling.cpp
 */
float computeDistance(MiddleEarth& me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);

int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);

    // TODO: YOUR CODE HERE
    string startCity = dests[0];
    dests.erase(dests.begin());
    sort(dests.begin(), dests.end());
    float minDis = 9999999999999.0 ;
    vector<string> minRoute;
    do{
      float curDis = computeDistance(me, startCity, dests);
      if(minDis > curDis) {
	minDis = curDis;
	minRoute = dests;
      }

    }while(next_permutation(dests.begin(), dests.end()));

    cout<< "Minimum path has distance "<< minDis << ": ";
    printRoute(startCity, minRoute);
			    
	   
    
    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance(MiddleEarth& me, const string& start, vector<string> dests) {
    // TODO: YOUR CODE HERE
  float dist = 0.0;
  dist += me.getDistance(start, dests[0]); // start->City1
  for(int i = 0; i<dests.size()-1; i++){
    dist += me.getDistance(dests[i], dests[i+1]);
  }
  dist += me.getDistance(dests[dests.size()-1], start);//City-1 -> start
  return dist;
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute(const string& start, const vector<string>& dests) {
    // TODO: YOUR CODE HERE
  string output = start;
  for(int i = 0; i<dests.size(); i++){
    output += "->";
    output += dests[i];
  }
  output += "->";
  output += start;
  cout<< output << endl;
}
