#ifndef __FILE_SYSTEM_CPP__
#define __FILE_SYSTEM_CPP__

#include "file_system.h"
#include "class_object.h"
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

std::vector<Class_Object> File_System::load_data(std::string file_name)
{
    std::vector<Class_Object> r;

    std::fstream strm;
    strm.open(file_name, std::ios_base::in);

    while (!strm.eof())
    {
        std::string line = "";

        getline(strm, line);

        if (line == "")
            continue;

        Class_Object t;
        t = t.build(line);
        t.id = r.size();

        r.push_back(t);
    }

    strm.close();
    std::cout << "Data set read from file." << std::endl;
    return this->normalize(r);
}

std::vector<Class_Object> File_System::normalize(std::vector<Class_Object> set) {
    std::vector<std::pair<int,double>> mins(set[0].feature_set), maxs(set[0].feature_set);

    for(int i = 0; i < set.size(); i++) {
        for(int j = 0; j < set[i].feature_set.size(); j++) {
            if(set[i].feature_set[j].second < mins[j].second) mins[j].second = set[i].feature_set[j].second;

            if(set[i].feature_set[j].second > maxs[j].second) maxs[j].second = set[i].feature_set[j].second;
        }
    }

    for(int i = 0; i < set.size(); i++) {
        for(int j = 0; j < set[i].feature_set.size(); j++) {
            set[i].feature_set[j].second = ((set[i].feature_set[j].second - mins[j].second)/(maxs[j].second - mins[j].second));
        }
    }
    std::cout << "Data set normalized." << std::endl;
    return set;
}

#endif