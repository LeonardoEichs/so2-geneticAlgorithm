#ifndef TIMESERIES
#define TIMESERIES

#include <string>
using namespace std;

class TimeSeries {
  public:
    static void createFile(string seriesName);
    static void organizeFile(int num_inp, int num_out);
};

#endif
