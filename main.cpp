
//
//  main.cpp
//  LLTemplate
//
//  Created by James Shockey on 12/6/16.
//  Copyright © 2016 James Shockey. All rights reserved.
//

/*
 *
 *	Linked List lab.
 *	- Build a library for singly linked list.
 *	- Replace the airport array in main with a Linked List.
 *  - sort the array.
 *
 */

#include "slist.h"
#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

void simpleSortTotal(Airport *s[], int c);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);

void simpleSortTotal(linkedlist *data) {
  int c = data->size();
  node *ai = data->get_node(0);
  while (ai != NULL) {
    node *aj = ai;
    while (aj != NULL) {
      if (ai->airport->distance < aj->airport->distance) {
				
        // data.swap(i, j);
        Airport temp = *ai->airport;
        *ai->airport = *aj->airport;
        *aj->airport = temp;
      }
      aj = aj->next;
    }
    // printf("%d\n", i);
    ai = ai->next;
  }
}

int main() {
  ifstream infile;
  int c = 0;
  Airport *airportArr[100000]; // Replace array with Linked List
  int airportCount;
  linkedlist airports = linkedlist();

  infile.open("airport-codes_US.csv", ifstream::in);

  Airport austin = Airport();
  austin.latitude = 30.19449997;
  austin.longitude = -97.66989899;

  if (infile.is_open()) {
    char buf[257];
    infile.getline(buf, 256, '\n');
    while (true) {
      if (!infile.good()) {
        break;
      }

      Airport *a = new Airport();

      airportArr[c] = new Airport();

      infile.getline(a->code, 256, ','); // ident

      if (string(a->code) == "\n" || string(a->code) == "") {
        break;
      }

      infile.getline(buf, 256, ','); // type
      infile.getline(buf, 256, ','); // name

      infile.getline(buf, 256, ','); // long
      a->longitude = atof(buf);
      infile.getline(buf, 256, ','); // lat
      a->latitude = atof(buf);

      infile.getline(buf, 256, ',');
      infile.getline(buf, 256, ',');
      infile.getline(buf, 256, ',');
      infile.getline(buf, 256, ',');
      infile.getline(buf, 256, ',');
      infile.getline(buf, 256, ',');
      infile.getline(buf, 256, ',');
      infile.getline(buf, 256, '\n');

      a->distance = distanceEarth(austin.latitude, austin.longitude, a->latitude,
                                  a->longitude);

      if (!(c % 1000)) {
        cout << a->code << ": long: " << a->longitude << " lat: " << a->latitude
             << " distance: " << a->distance << endl;
      }

      c++;

      airports.add(a);
    }

    airportCount = c - 1;
    infile.close();

  } else {
    cout << "Error opening file";
  }

  printf("sorting\n");
  simpleSortTotal(&airports);
  printf("done\n");

  for (int i = 0; i < 0; i++) {
    // printf("a\n");
    Airport *a = airports.get(i);
    printf("%s: %f\n", a->code, a->distance);
  }
}

#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

// This function converts decimal degrees to radians
double deg2rad(double deg) { return (deg * pi / 180); }

//  This function converts radians to decimal degrees
double rad2deg(double rad) { return (rad * 180 / pi); }

/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r) / 2);
  v = sin((lon2r - lon1r) / 2);
  return 2.0 * earthRadiusKm *
         asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

/*
Provide sort routine on linked list
*/
/*
void simpleSortTotal()
{
}
*/
