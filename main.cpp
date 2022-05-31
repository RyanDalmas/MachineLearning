#ifndef __MAIN_CPP__
#define __MAIN_CPP__

#include <iostream>
#include <string>
#include <regex>
#include "algorithm.cpp"
#include "file_system.cpp"
#include "classifier.cpp"
#include "validator.cpp"

int main()
{

    system("CLS");

    std::cout << "=== Welcome to Ryan's Machine Learning Project ===" << std::endl;
    std::cout << std::endl;
    std::cout << "(1) Small test data set" << std::endl;
    std::cout << "(2) Large test data set" << std::endl;
    std::cout << "(3) Small personal set" << std::endl;
    std::cout << "(4) Large personal set" << std::endl;
    std::cout << std::endl;
    std::cout << "-> ";

    int Select = -1;

    std::cin >> Select;

    std::string file_name = "";

    switch (Select) {
    case 1:
        file_name = "small_data_set.txt";
        break;
    case 2:
        file_name = "large_data_set.txt";
        break;
    case 3:
        file_name = "small_ds_personal.txt";
        break;
    case 4:
        file_name = "large_ds_personal.txt";
        break;
    default:
        break;
    }

    File_System *f = new File_System();

    std::vector<Class_Object> training_data = f->load_data(file_name);

    int FeatureCount = training_data[0].feature_set.size();

    Algorithm* a = new Algorithm(FeatureCount);

    system("CLS");

    a->greedyForwardI(training_data);
    a->greedyBackwards(training_data);

    return 0;
}

#endif