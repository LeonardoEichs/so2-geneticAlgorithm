#include "floatfann.h"
#include "fann_cpp.h"

#include <ios>
#include <iostream>
#include <fstream>
#include <sstream>
#include <sys/time.h>

using namespace std;

// Test function that demonstrates usage of the fann C++ wrapper
void run()
{
    // Load file previously trained (for example by learn_sequence)
    FANN::neural_net net;
    net.create_from_file("learn_sequential.net");

    // load datafile
    FANN::training_data data;
    if (data.read_train_from_file("../data/backgroundState_FANN.data")) {
        data.scale_train_data(-1, 1);

        // Seed with last pattern from dataset.
        fann_type *previousOutput = data.get_input()[data.length_train_data()];

        // Length of dream
        for (unsigned int i = 0; i < 10000; i++)
        {
            fann_type *tmpOutput;
            tmpOutput = net.run(previousOutput);
            previousOutput = tmpOutput; // feedback loop.

            // print out each
            for (unsigned int j = 0; j < data.num_input_train_data(); j++) {
                cout << "RESULT " << i << " " << j << " " << previousOutput[j] <<endl;
            }
        }
    } else
        cout << "Data file could not be loaded" << endl;

}

/* Startup function. Syncronizes C and C++ output, calls the test function
   and reports any exceptions */
int main(int argc, char **argv)
{
    try
    {
        std::ios::sync_with_stdio(); // Syncronize cout and printf output
        run();
    }
    catch (...)
    {
        cerr << endl << "Abnormal exception." << endl;
    }
    return 0;
}
