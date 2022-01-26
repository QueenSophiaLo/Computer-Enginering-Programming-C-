#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "math.h"
#include <cmath>

using namespace std;

#define EARTHRADIUS 3958.8 // The radius of the earth is approximately 3,958.8 mi.

class Location {
    public:
    vector<string> cityName = {"Norwalk", "New Britain","Middletown","Belle Glade","Bartow","Atlantic City","Albany","Jacksonville","Idaho City","Coral Gables"};
    vector<string> stateName = {"CT", "CT", "CT", "FL", "FL", "NJ", "GA", "IL", "ID", "FL"};
    vector<string> country = {"USA", "USA", "USA", "USA", "USA", "USA", "USA", "USA", "USA", "USA"};
    vector<double> latitude = { 41.121880, 41.681408, 41.562794, 26.687412, 27.891005, 39.370121, 31.594915, 39.741550, 43.828850, 25.750156};
    vector<double> longitude = {-73.436432, -72.794746, -72.681610, -80.681831, -81.847359, -74.438942, -84.224236, -90.256218, -115.837860, -80.279640};
};

// The program will begin by greeting the user with a quick description of the application’s function
void programDescription() {
    cout << "FIXME" << endl;
}

// This function presents the user with an enumerated list of options 
// (locations with GPS coordinates in latitude and longitude formation)
void enumList() {
    for (int i = 0; i <= 10; ++i) { // create a for loop that goes through the values and outputs them
        cout << "  -City/State/Country Name-   -Latitude-   -Longitude-" << endl;
        cout << i+1 << ".     " << (Location.at(i)).cityName << ", " << (Location.at(i)).stateName << ", " << (Location.at(i)).country;
        cout << "     " << (Location.at(i)).latitude << (Location.at(i)).longitude << endl;
    }
}

/*

// This function prompts the user to select a departure location
void selectDepLoca() {
    cout << "Select a departure location by entering in the enumerated value associated with the desired location" << endl;
    
}

// The same list will be presented again with the exclusion of the previously selected location to allow the user to select a destination
void enumListNoDest() {
    
}

// Once the user has selected both a departure and a destination location, we will compute the distance to both of those locations.
// This distance cannot be computed using typical Euclidean distance between two points
// we are dealing with points on the surface of a sphere
// This will require us to use the Haversine formula to calculate distance across the surface of the sphere
// The Haversine formula (Links to an external site.) appears as follows...

double haversine(double lat1, double long1, double lat2, double long2, double radius) {        // compute distance to departure location selected by user
                            // compute distance to destination location selected by user
    // distance between latitude and longitude

    
double d; // distance between two points
double r; // radius of the sphere
double lat1; // latitude of point 1
double lat2; // lattitude of point 2
double long1; // longitude of point 1
double long2; // longitude of point 2

return d; // The value being returned is the haversine distance in miles between the two latitude/longitude points passed to the function (lat1/long1, lat2,long2).
}

// Once you have computed the distance between the two points
// approximate the speed of the plane to find the average flight time to get between the two points
// The average passenger jet flies at a speed of somewhere between around 460-575 mph
// Choose a value in this range to represent the speed of the jet

// calculate the approximate time to fly between the two selected points. 

double getFlightTime(double lat1, double long1, double lat2, double long2);


*/

int main() {

// variables...
// φ1, φ2 are the latitude of point 1 and latitude of point 2,
// λ1, λ2 are the longitude of point 1 and longitude of point 2.
// r is the radius of the sphere
// d is the distance between the two points

cout << programDescription() << endl;   // output program synopsis 
cout << enumList << endl;




return 0;
}


