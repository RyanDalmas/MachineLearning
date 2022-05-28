#ifndef __ALGORITHM_H__
#define __ALGORITHM_H__

#include "node.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Node.cpp"
#include "Feature.cpp"

class Algorithm
{

private:
    int (Algorithm::*classifier)(const std::vector<Feature*> t);

    int featureCount, sAlgorithm;

public:
    Algorithm(int _featureCount, int _sAlgorithm) : featureCount(_featureCount), sAlgorithm(_sAlgorithm) {
        srand (time(NULL));

        this->classifier = evaluate;
    }
    ~Algorithm() {

    }

    void run();

    void greedyForward();

    int evaluate(const std::vector<Feature*> t);

    void print(std::vector<Feature *> p);
};

#endif