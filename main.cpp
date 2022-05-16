#ifndef __MAIN_CPP__
#define __MAIN_CPP__

#include <iostream>
#include <string>
#include <regex>

int main()
{

    int FeatureCount = -1;
    int SelectAlgorithm = -1;

    int Tries_1 = 0, Tries_2 = 0;

    do
    {

        system("CLS");

        std::cout << "Welcome to Ryan Dalmas's Feature Selection Algorithm" << std::endl
                  << std::endl;

        (Tries_2 > 0) ? std::cout << "Enter Feature Count (" << Tries_2 << ") -> " : std::cout << "Enter Feature Count -> ";

        std::string UserInput = "";
        std::string user_input_validate = "^[0-9]+$";

        std::cin >> UserInput;

        if (std::regex_match(UserInput, std::regex(user_input_validate)))
        {
            FeatureCount = std::stoi(UserInput);
            break;
        }

    } while (true);

    do
    {

        system("CLS");

        std::cout << "Welcome to Ryan Dalmas's Feature Selection Algorithm" << std::endl << std::endl;

        std::cout << "(1) Forward Selection" << std::endl;
        std::cout << "(2) Backward Elimination" << std::endl;

        std::cout << std::endl;

        (Tries_2 > 0) ? std::cout << "Select Algorithm (" << Tries_2 << ") -> " : std::cout << "Select Algorithm -> ";

        std::string UserInput = "";
        std::string user_input_validate = "^[0-9]+$";

        std::cin >> UserInput;

        if (std::regex_match(UserInput, std::regex(user_input_validate)))
        {
            SelectAlgorithm = std::stoi(UserInput);
            break;
        }

    } while (true);

    

    system("pause");
    return 0;
}

#endif