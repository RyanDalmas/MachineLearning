#ifndef __NODE_H__
#define __NODE_H__

#include <vector>
#include "feature.cpp"

class Node {

private:
    Node* next;
    std::vector<Feature> feature_set;

public:
    Node();
    ~Node();
    std::vector<Feature>& get_set() {
        return this->feature_set;
    }

    Node* get_next() {
        return this->next;
    }
};

#endif