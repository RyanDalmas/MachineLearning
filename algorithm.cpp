#ifndef __ALGORITHM_CPP__
#define __ALGORITHM_CPP__

#include "algorithm.h"
#include <vector>
#include <iostream>
#include "validator.h"
#include <algorithm>
#include <numeric>
#include <iterator>

void Algorithm::greedyForward(std::vector<Class_Object> training_data)
{
    std::vector<std::vector<Feature *>> f_set;

    std::vector<Feature*> a;
    f_set.push_back(a);

    std::vector<Feature *> max_accuracy_set, running_max_set;
    double max_accuracy = 0;

    for (int Counter = 0; Counter < this->featureCount; Counter++)
    {
        std::cout << "Feature split #" << Counter << std::endl;
        // Generate
        for (int f_counter = 0; f_counter < this->featureCount; f_counter++)
        {
            std::cout << ".";
            std::vector<Feature *> t = f_set[0];

            bool Check = false;
            for (int i = 0; i < t.size(); i++) Check = t[i]->getFeature() == f_counter || Check;

            if (!Check)
            {
                t.push_back(new Feature(f_counter));
                f_set.push_back(t);
            }
        }

        // Evaluate
        double temp_eval = 0;
        for (int f_counter = 0; f_counter < f_set.size(); f_counter++)
        {
            std::cout << "trying " << f_counter << " of " << f_set.size() << std::endl;
            if(f_set[f_counter].empty()) continue;

            double eval = evaluate(f_set[f_counter], training_data);

            if (eval > max_accuracy)
            {
                max_accuracy = eval;
                max_accuracy_set = f_set[f_counter];
            }

            if (eval > temp_eval)
            {
                temp_eval = eval;
                running_max_set = f_set[f_counter];
            }
        }

        if(max_accuracy > temp_eval) break;

        f_set.erase(f_set.begin(), f_set.end());
        f_set.push_back(running_max_set);
    }

    std::cout << "Greedy Forward|Accuracy: " << max_accuracy << std::endl;

    std::cout << "Greedy Forward|Feature Set: ";

    print(max_accuracy_set);

    std::cout << std::endl;
}

void Algorithm::greedyBackwards(std::vector<Class_Object> training_data)
{
    std::vector<std::vector<Feature *>> f_set;

    std::vector<Feature*> a;
    f_set.push_back(a);

    std::vector<Feature *> max_accuracy_set, running_max_set;
    double max_accuracy = 0;

    for (int Counter = 0; Counter < this->featureCount; Counter++)
    {
        // Generate
        for (int f_counter = 0; f_counter < this->featureCount; f_counter++)
        {
            std::vector<Feature *> t = f_set[0];

            bool Check = false;
            for (int i = 0; i < t.size(); i++) Check = t[i]->getFeature() == f_counter || Check;

            if (!Check)
            {
                t.push_back(new Feature(f_counter));
                f_set.push_back(t);
            }
        }

        // Evaluate
        double temp_eval = 0;
        for (int f_counter = 0; f_counter < f_set.size(); f_counter++)
        {
            if(f_set[f_counter].empty()) continue;

            double eval = evaluate(this->complement(f_set[f_counter]), training_data);

            if (eval > max_accuracy)
            {
                max_accuracy = eval;
                max_accuracy_set = f_set[f_counter];
            }

            if (eval > temp_eval)
            {
                temp_eval = eval;
                running_max_set = f_set[f_counter];
            }
        }

        if(max_accuracy > temp_eval) break;

        f_set.erase(f_set.begin(), f_set.end());
        f_set.push_back(running_max_set);
    }

    std::cout << "Greedy Backward|Accuracy: " << max_accuracy << std::endl;

    std::cout << "Greedy Backward|Feature Set: ";

    print(max_accuracy_set);

    std::cout << std::endl;
}


void Algorithm::print(std::vector<Feature *> p)
{
    std::cout << "{";

    for (int i = 0; i < p.size(); i++)
    {
        std::cout << (p[i]->getFeature()+1) << (i < p.size() - 1 ? "," : "");
    }

    std::cout << "}";
}

void Algorithm::printI(int* p)
{
    std::cout << "{";

    for (int i = 0; i < this->featureCount; i++)
    {
        std::cout << p[i] << " ";
    }

    std::cout << "}";
}

double Algorithm::evaluate(const std::vector<Feature *> set, std::vector<Class_Object> training_data)
{
    Validator* v = new Validator();

    return v->leave_one_out(set, training_data);
}

double Algorithm::evaluateI(int* set, std::vector<Class_Object> training_data)
{
    Validator* v = new Validator();

    return v->leave_one_outI(set, training_data);
}

std::vector<Feature *> Algorithm::complement(std::vector<Feature *> input) {
    std::vector<Feature *> r;

    for(int i = 0; i < this->featureCount; i++) {
        r.push_back(new Feature(i));
    }

    for(int i = 0; i < input.size(); i++) {
        for(int j = r.size()-1; j >= 0; j--) {
            if(r[j]->getFeature() == input[i]->getFeature()) r.erase(r.begin()+j);
        }
    }

    return r;
}

void Algorithm::greedyForwardI(std::vector<Class_Object> training_data)
{
    int* empty_set = new int[this->featureCount];

    std::fill(empty_set, empty_set+this->featureCount, 0);

    std::vector<int*> f_set;
    f_set.push_back(empty_set);

    int* max_accuracy_set,* running_max_set;
    double max_accuracy = 0;

    for (int Counter = 0; Counter < this->featureCount; Counter++)
    {
        std::cout << "Feature split #" << Counter << std::endl;
        // Generate
        for (int f_counter = 0; f_counter < this->featureCount; f_counter++)
        {
            std::cout << ".";
            int* t = new int[this->featureCount];
            for(int i = 0; i < this->featureCount; i++) t[i] = f_set[0][i];

            if (!t[f_counter])
            {
                t[f_counter] = 1;
                f_set.push_back(t);
            }

        }

        // Evaluate
        double temp_eval = 0;
        for (int f_counter = 0; f_counter < f_set.size(); f_counter++)
        {
            std::cout << "trying " << f_counter << " of " << f_set.size() << std::endl;
            int sum;
            std::accumulate(f_set[f_counter], f_set[f_counter]+this->featureCount, sum);
            if(sum == 0) continue;

            double eval = evaluateI(f_set[f_counter], training_data);

            if (eval > max_accuracy)
            {
                max_accuracy = eval;
                max_accuracy_set = f_set[f_counter];
            }

            if (eval > temp_eval)
            {
                temp_eval = eval;
                running_max_set = f_set[f_counter];
            }
        }

        //if(max_accuracy > temp_eval) break;   

        f_set.erase(f_set.begin(), f_set.end());
        f_set.push_back(running_max_set);
    }

    std::cout << "Greedy Forward|Accuracy: " << max_accuracy << std::endl;

    std::cout << "Greedy Forward|Feature Set: ";

    printI(max_accuracy_set);

    std::cout << std::endl;
}


#endif