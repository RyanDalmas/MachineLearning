#ifndef __FILE_SYSTEM_H__
#define __FILE_SYSTEM_H__

#include "class_object.h"
#include <vector>
#include <string>

class File_System {

    private:
        std::string file_name;

    public:
        File_System() {}
        ~File_System() {}
        std::vector<Class_Object> load_data(std::string file_name);
        std::vector<Class_Object> normalize(std::vector<Class_Object> set);
};


#endif