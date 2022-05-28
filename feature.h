#ifndef __FEATURE_H__
#define __FEATURE_H__

#include <vector>

class Feature {

private:
    int number;

public:
    Feature(int _number) : number(_number) {}
    ~Feature();

    int getFeature() {
        return this->number;
    }
};

#endif