#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <iostream>
#include "Individual.hpp"
#include "Environment.hpp"
#include "TimeSeries.hpp"

#define H1 "000050c58075b2700490226529d4620000000000000000000000000000ffffffffffffffff"
#define H2 "000050c580a7b2700490226529d4620000000000000000000000000000ffffffffffffffff"
#define L "00244b92844704382c9b2b8528b0630000000000000000000000000000ffffffffffffffff"
#define O0 "00244b9284e204382c4b2b8528c5620000000000000000000000000000ffffffffffffffff"
#define O1 "00244b92841103382c272c8528c5620000000000000000000000000000ffffffffffffffff"
#define LPC "00244b92844704382c9b2b8528b0630000000000000000000000000000ffffffffffffffff"
#define RL "00254992842003382c3b2c8528d4620000000000000000000000000000ffffffffffffffff"
#define M "00020000002003382c312c8528d4620000000000000000000000000000ffffffffffffffff"

using namespace std;

int main(int argc, char* argv[]) {
  int index;
  char *timeSerie = NULL;
  int c;

  opterr = 0;


  while ((c = getopt (argc, argv, "lgs:")) != -1)
    switch (c)
      {
      case 'l':
        cout << "----------- TIME SERIES NAMES -----------" << endl;
        cout <<  endl;
        cout << "----------- HD Water Consumption (hydrometers) -----------" << endl;
        cout << "1 -> Hydrometer 1: " << H1 << endl;
        cout << "2 -> Hydrometer 2: " << H2 << endl;
        cout << "----------- SMART LISHA (power consumption) -----------" << endl;
        cout << "3 -> Lamp: " << L << endl;
        cout << "4 -> Outlet 0: " << O0 << endl;
        cout << "5 -> Outlet 1: " << O1 << endl;
        cout << "----------- SMART LISHA (Lighting) -----------" << endl;
        cout << "6 -> Lamp power consumption: " << LPC << endl;
        cout << "7 -> Room Lighting: " << RL << endl;
        cout << "8 -> Movement: " << M << endl;
        return 0;
      case 's':
        switch(atoi(optarg)) {
          case(1):
            timeSerie = H1;
            break;
          case(2):
            timeSerie = H2;
            break;
          case(3):
            timeSerie = L;
            break;
          case(4):
            timeSerie = O0;
            break;
          case(5):
            timeSerie = O1;
            break;
          case(6):
            timeSerie = LPC;
            break;
          case(7):
            timeSerie = RL;
            break;
          case(8):
            timeSerie = M;
            break;
          default:
            cout << "Invalid Time Serie number" << endl;
            return 0;
        }
        TimeSeries::createFile(timeSerie);
        TimeSeries::organizeFile(4, 1);
        break;
      case 'g':
      {
        srand (time(NULL));
        Environment env = Environment(1000, 10000, 100, 0.8, 0.3);
        env.run();
        cout << "-----------------------" << endl;
        cout << env.best().fitness_score << endl;
        cout << env.generation << endl;
        break;
      }
      case '?':
        if (optopt == 's')
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
      }

  for (index = optind; index < argc; index++)
    printf ("Non-option argument %s\n", argv[index]);




}
