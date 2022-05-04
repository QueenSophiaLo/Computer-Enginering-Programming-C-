#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "math.h"
#include <cmath>
#include <iomanip>

using namespace std;

#define EARTH_RADIUS 3958.8 // The radius of the earth is approximately 3,958.8 mi.
#define AIRPLANE_SPEED 525  // The average passenger jet flies at a speed of somewhere between around 460-575 mph

class Location {
      public:
      string locationName;
      double lon;
      double lat;
    };

// This function is used to create the vector of Location objects used for calculations
vector<Location> assign(){
    Location p1;
    p1.locationName = "Norwalk, CT, USA";
    p1.lon = -73.43632;
    p1.lat = 41.121880;
   
    Location p2;
    p2.locationName = "Bartow, FL, USA";
    p2.lon = -80.681831;
    p2.lat = 27.891005;
   
    Location p3;
    p3.locationName = "Albany, GA, USA";
    p3.lon = -84.224236;
    p3.lat = 31.594915;
   
    Location p4;
    p4.locationName = "Central City, CO, USA";
    p4.lon = -105.516830;
    p4.lat = 39.803318;
   
    Location p5;
    p5.locationName = "Newport, AR, USA";
    p5.lon = -91.271286;
    p5.lat = 35.618671;
   
    Location p6;
    p6.locationName = "Malibu, CA, USA";
    p6.lon = -118.788193;
    p6.lat = 34.031246;
   
    Location p7;
    p7.locationName = "Rome, NY, USA";
    p7.lon = -75.484924;
    p7.lat = 43.227978;
   
    Location p8;
    p8.locationName = "Tuckegee, AL, USA";
    p8.lon = -85.968628;
    p8.lat = 31.806484;
   
    Location p9;
    p9.locationName = "Jacksonville, IL, USA";
    p9.lon = -90.256218;
    p9.lat = 39.741550;
   
    Location p10;
    p10.locationName = "Panama City, FL, USA";
    p10.lon = -85.683029;
    p10.lat = 30.193626;

// Here the vector is created and has all the objects pushed into it
    vector<Location> locations;
    locations.push_back(p1);
    locations.push_back(p2);
    locations.push_back(p3);
    locations.push_back(p4);
    locations.push_back(p5);
    locations.push_back(p6);
    locations.push_back(p7);
    locations.push_back(p8);
    locations.push_back(p9);
    locations.push_back(p10);

    return locations;
}

// The program will begin by greeting the user with a quick description of the application’s function
string programDescription() {
    string desc = "This program produces the flight time between two different cities chosen by the user from a list.";
    return desc;
}

// This function presents the user with an enumerated list of options 
void enumList(vector<Location> locations, int exclude) {
    cout << " -City/State/Country name-  -Latitude-  -Longitude-" << endl;
    for(int i=0; i < locations.size(); i++){    // This loop that goes through the values and outputs them
        if(i != exclude){ // This ensures that it does not print whichever index is passed to it
            cout << right << setw(2) << i + 1 <<". " << setw(26) << left << locations.at(i).locationName;
            cout << setw(12) << left << locations.at(i).lat;    //  Formatting for the list
            cout << setw(13) << left << locations.at(i).lon << endl;
        }
    }
}

int inputRequest(vector<Location> locations, int exclude) {
    string input;
    int intInput;
    bool valid = false;
    while(valid == false){
        cin >> input;
        intInput = atoi(input.c_str()) - 1;
        if(intInput < locations.size() && intInput >= 0 && intInput != exclude){
            valid = true;
        }else{
            cout << "Please enter a valid index:" << endl;
        }
    }
    return intInput;
}

// Used to convert the angles into radians from degrees so the haversine function can properly provide distance
double dtor(double angle) { // dtor (degrees to radians)
    return M_PI * angle / 180;
}

double haversine(double lat1, double lon1, double lat2, double lon2) {
    // Creates new variables to put the radian versions of the angles into
    double latRad1 = dtor(lat1);
    double latRad2 = dtor(lat2);
    double lonRad1 = dtor(lon1);
    double lonRad2 = dtor(lon2);
    // Haversine formula
    return 2*EARTH_RADIUS*asin(  sqrt( pow( sin( ( latRad2 - latRad1 ) / 2), 2 )+ cos(latRad1) * cos(latRad2) * pow( sin( ( lonRad2 - lonRad1 ) / 2),2) ) );
}

// This function divides the flight distance by 525 (our chosen airplane speed) to give the time it takes to travel that distance in hours.
double getFlightTime(double lat1, double lon1, double lat2, double lon2) {
    return haversine(lat1, lon1, lat2, lon2)/AIRPLANE_SPEED;
}

int main() {
    // integers used for the index of the location cities
    int depart, arrive;
    // create the list of locations
    vector<Location> locations = assign();

    cout << programDescription() << endl;   // output program synopsis
    cout << "Which city are you flying from? (please provide the numerical index.)" << endl;
    enumList(locations, locations.size()); // prints out the list of all locations, list size is given as the exclude to ensure it prints all locations no matter the size of the list
    depart = inputRequest(locations, locations.size());
    cout << "What city are you flying to? (Please provide the numerical index)" << endl; // requests a destination from the user
    enumList(locations, depart);
    arrive = inputRequest(locations, depart);
    cout << "The flight time between these two cities is about ";
    cout << getFlightTime(locations.at(depart).lat, locations.at(depart).lon, locations.at(arrive).lat, locations.at(arrive).lon);
    cout << " hours" << endl;
return 0;
}
