#ifndef __ALGORITHM_CPP__
#define __ALGORITHM_CPP__

#include "algorithm.h"
#include <vector>
#include <iostream>

void Algorithm::run()
{
    switch (this->sAlgorithm)
    {
    case 1:
        this->greedyForward();
        break;
    case 2:
        // Other one
        break;
    default:
        break;
    }
}

void Algorithm::greedyForward()
{
    int FeatureCount = 0;
    system("CLS");
    std::cout << "Feature-Count -> ";
    std::cin >> FeatureCount;

    std::vector<std::vector<Feature *>> f_set;

    std::vector<Feature*> a;
    f_set.push_back(a);

    std::vector<Feature *> max_accuracy_set, running_max_set;
    int max_accuracy = 0;

    for (int Counter = 0; Counter < FeatureCount; Counter++)
    {

        // Generate
        for (int f_counter = 0; f_counter < FeatureCount; f_counter++)
        {
            std::vector<Feature *> t = f_set[0];

            bool Check = false;
            for (int i = 0; i < t.size(); i++) Check = t[i]->getFeature() == f_counter | Check;

            if (!Check)
            {
                t.push_back(new Feature(f_counter));
                f_set.push_back(t);
            }
        }

        std::cout << "{";
        for (int i = 0; i < f_set.size(); i++)
        {
            print(f_set[i]);
            (i < f_set.size() - 1) ? std::cout << "," : std::cout << "";
        }
        std::cout << "}" << std::endl;

        // Evaluate
        int temp_eval = 0;
        for (int f_counter = 0; f_counter < f_set.size(); f_counter++)
        {
            int eval = evaluate(f_set[f_counter]);

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

        f_set.erase(f_set.begin(), f_set.end());
        f_set.push_back(running_max_set);
    }

    std::cout << "Accuracy: " << max_accuracy << std::endl;

    std::cout << "Feature Set: ";

    print(max_accuracy_set);

    std::cout << std::endl;
}

void Algorithm::print(std::vector<Feature *> p)
{
    std::cout << "{";

    for (int i = 0; i < p.size(); i++)
    {
        std::cout << p[i]->getFeature() << (i < p.size() - 1 ? "," : "");
    }

    std::cout << "}";
}

int Algorithm::evaluate(const std::vector<Feature *> t)
{
    return rand() % 100 + 1;
}

#endif