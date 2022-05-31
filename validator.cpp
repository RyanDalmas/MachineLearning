#ifndef __VALIDATOR_CPP__
#define __VALIDATOR_CPP__

#include <string>
#include "validator.h"
#include "class_object.h"
#include "classifier.cpp"
#include <algorithm>
#include <iterator>
#include <iostream>

double Validator::leave_one_out(std::vector<Feature *> set, std::vector<Class_Object> training_data)
{
    int correct_guesses = 0;
    #pragma omp parallel for
    for (int instance_counter = 0; instance_counter < training_data.size(); instance_counter++)
    {
        Classifier *c = new Classifier();
        c->train(training_data, instance_counter);
        Class_Object t;
        t = t.copy(training_data[instance_counter]);
        t = c->test(t, set);

        correct_guesses += (t.cl == training_data[instance_counter].cl) ? 1 : 0;
    }

    return ((double)correct_guesses / (double)training_data.size());
}

double Validator::leave_one_outI(int* set, std::vector<Class_Object> training_data)
{
    int correct_guesses = 0;
    #pragma omp parallel for
    for (int instance_counter = 0; instance_counter < training_data.size(); instance_counter++)
    {
        Classifier *c = new Classifier();
        c->train(training_data, instance_counter);
        Class_Object t;
        t = t.copy(training_data[instance_counter]);
        t = c->testI(t, set);

        correct_guesses += (t.cl == training_data[instance_counter].cl) ? 1 : 0;
        delete c;
    }

    return ((double)correct_guesses / (double)training_data.size());
}

#endif