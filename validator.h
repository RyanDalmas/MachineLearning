#ifndef __VALIDATOR_H__
#define __VALIDATOR_H__

#include <string>
#include <vector>
#include "feature.cpp"

class Validator
{

private:
    double (*classifier)(std::vector<Feature *> set, std::vector<Class_Object> training_data);

public:
    Validator() {}
    ~Validator() {}

    // Input: a feature subset, a classifier, and the data set
    // Output: model accuracy using inputs
    double leave_one_out(std::vector<Feature *> set, std::vector<Class_Object> training_data);
};

#endif