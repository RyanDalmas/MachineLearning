#ifndef __CLASS_OBJECT_H__
#define __CLASS_OBJECT_H__

#include <vector>
#include "split.cpp"
#include <cmath>

struct Class_Object {
    int cl = -1;
    int id = -1;
    std::vector<std::pair<int, float>> feature_set;
    void print() {
        std::cout << "Instance " << this->id << std::endl;
        std::cout << "> Class: " << this->cl << std::endl;
        std::cout << "> Features: " << this->feature_set.size() << std::endl;
        std::cout << "> Here is feature 1: " << this->feature_set[0].second << std::endl;
        std::cout << std::endl;
    }
    Class_Object build(std::string input_str) {
        std::vector<std::string> split_string = split(input_str);

        Class_Object t;
        t.cl = (int)std::stof(split_string[0]);
        for (int i = 1; i < split_string.size(); i++)
        {
            t.feature_set.push_back(std::pair<int, float>(i, std::stof(split_string[i])));
        }
        return t;
    }
    float euclidean_distance(Class_Object t) {

        if(t.feature_set.size() != this->feature_set.size()) return -1;

        float running_sum = 0.0f;

        for(int i = 0; i < this->feature_set.size(); i++) {
            running_sum += pow((this->feature_set[i].second - t.feature_set[i].second), 2);
        }

        return sqrt(running_sum);
    }
    float euclidean_distance(Class_Object t, const std::vector<Feature*> set) {

        if(t.feature_set.size() != this->feature_set.size()) std::cout << "ERROR, FEATURES CANNOT BE COMPUTED";

        float running_sum = 0.0f;

        for(int i = 0; i < this->feature_set.size(); i++) {
            bool Check = false;
            for(int z = 0; z < set.size(); z++) Check = ((i) == set[z]->getFeature()) ? true || Check : false || Check;

            //if(Check) std::cout << "Feature #" << t.feature_set[i].first << " used." << std::endl;

            if(Check) running_sum += pow((t.feature_set[i].second - (double)this->feature_set[i].second), 2);
        }

        return sqrt(running_sum);
    }
    Class_Object copy(Class_Object i) {
        Class_Object r;
        r.cl = i.cl;
        r.feature_set = i.feature_set;
        return r;
    }
};

#endif