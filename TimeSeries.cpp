#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "TimeSeries.hpp"

using namespace std;

/*
Calls a PHP script with the name of the Time Series, then outputs
the data to a file called rawData.txt
*/
void TimeSeries::createFile(string seriesName) {
    string command = string("echo -n \"").append(seriesName).append("\" | php get_from_iot.php > rawData.txt");
    std::system(command.c_str());
}

/*
Very useful method used to transform the raw data from the time series
to a new file in which the Neural Network can use to train
STILL NEEDS TO INSERT THE FIRST LINE FOR THE DOCUMENT
*/
void TimeSeries::organizeFile(int num_inp, int num_out) {
    string line;

    ifstream file_raw;
    file_raw.open("rawData.txt");
    ofstream file_new;
    file_new.open("trainingData.txt");

    int lines_count = 0;
    while (getline(file_raw , line))
        ++lines_count;
    file_raw.clear();
    file_raw.seekg(0, ios::beg);

    file_new << (lines_count-num_inp-(num_out - 1)) - 1 << " " << num_inp << " " << num_out << endl;

    for (int count = 1; count <= lines_count - num_out - num_inp; count++) {

      for (int j = 0; j < num_inp; j++) {
          for (int i = 1; i <= count + j; i++)
              getline(file_raw, line);
          file_new << line.c_str() << " ";
          file_raw.clear();
          file_raw.seekg(0, ios::beg);
      }
      file_new << endl;

      for (int j = 1; j <= num_out; j++) {
          for (int i = 1; i <= count + num_inp + j - 1; i++)
              getline(file_raw, line);
          file_new << line.c_str() << " ";
          file_raw.clear();
          file_raw.seekg(0, ios::beg);
      }
      file_new << endl;
    }

    file_new.close();
    file_raw.close();
}
