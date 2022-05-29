#ifndef __ALGORITHM_H__
#define __ALGORITHM_H__

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "feature.cpp"
#include "class_object.h"

class Algorithm {

private:
    int featureCount;

public:
    Algorithm(int _featureCount) : featureCount(_featureCount) {}
    ~Algorithm() {}

    void greedyForward(std::vector<Class_Object>);
    void greedyBackwards(std::vector<Class_Object> training_data);

    double evaluate(const std::vector<Feature*>, std::vector<Class_Object>);

    std::vector<Feature *> complement(std::vector<Feature *> input);

    void print(std::vector<Feature *>);
};

#endif