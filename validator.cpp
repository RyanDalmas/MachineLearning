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
    for (int instance_counter = 0; instance_counter < training_data.size(); instance_counter++)
    {
        Classifier *c = new Classifier();

        std::vector<Class_Object> snipped_training_data(training_data);

        Class_Object snip = snipped_training_data[instance_counter];

        snipped_training_data.erase(snipped_training_data.begin() + instance_counter);

        c->train(snipped_training_data);
        Class_Object t;
        t = t.copy(snip);
        t = c->test(t, set);

        correct_guesses += (t.cl == snip.cl) ? 1 : 0;

        //Estd::cout << "check" << std::endl;
        //t.print();
        //snip.print();
    }

    return ((double)correct_guesses / (double)training_data.size());
}

#endif