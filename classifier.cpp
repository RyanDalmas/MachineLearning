#ifndef __CLASSIFIER_CPP__
#define __CLASSIFIER_CPP__

#include "classifier.h"
#include "split.cpp"

void Classifier::train(std::vector<Class_Object> training_data) {
    if(!training_data.empty())
        this->training_data = training_data;
}

Class_Object Classifier::test(std::string input_object) {
    Class_Object t;
    t = t.build(input_object);

    float min_distance = INT_MAX;
    int min_class = -1;

    for(int Counter = 0; Counter < this->training_data.size(); Counter++) {
        float eud = t.euclidean_distance(this->training_data[Counter]);

        if(eud < min_distance) {
            min_distance = eud;
            min_class = this->training_data[Counter].cl;
        }
    }

    return t;
}

Class_Object Classifier::test(Class_Object t) {

    float min_distance = INT_MAX;
    int min_class = -1;

    for(int Counter = 0; Counter < this->training_data.size(); Counter++) {
        float eud = t.euclidean_distance(this->training_data[Counter]);

        if(eud < min_distance) {
            min_distance = eud;
            min_class = this->training_data[Counter].cl;
        }
    }

    t.cl = min_class;

    return t;
}

Class_Object Classifier::test(Class_Object t, std::vector<Feature *> set) {

    float min_distance = INT_MAX;
    int min_class = -2;

    for(int Counter = 0; Counter < this->training_data.size(); Counter++) {
        float eud = t.euclidean_distance(this->training_data[Counter], set);

        if(eud < min_distance) {
            min_distance = eud;
            min_class = this->training_data[Counter].cl;
        }
    }

    t.cl = min_class;

    return t;
}

#endif