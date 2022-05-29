#ifndef __SPLIT_CPP__
#define __SPLIT_CPP__

#include <vector>
#include <string>

std::vector<std::string> split(std::string input_str)
{
    std::vector<std::string> r;

    std::string t = "";
    for (auto i : input_str)
    {
        if (i == ' ')
        {
            if(t != "" && t != " ") r.push_back(t);
            t = "";
        }
        else
        {
            t += i;
        }
    }

    //std::cout << "Split Size: " << r.size() << std::endl;
    return r;
}

#endif