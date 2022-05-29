#ifndef __CLASSIFIER_H__
#define __CLASSIFIER_H__

#include <string>
#include <vector>
#include "class_object.h"

class Classifier {

    private:
        std::vector<Class_Object> training_data;

    public:
        Classifier() {}
        ~Classifier() {}

        void train(std::vector<Class_Object> training_data);

        Class_Object test(std::string input_object);
        Class_Object test(Class_Object t);
        Class_Object test(Class_Object t, std::vector<Feature *> set);

};


#endif