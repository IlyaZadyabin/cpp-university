#include <iostream>
#include <cmath>
#include <new>
#include <vector>
#include <bits/c++config.h>
#include <iterator>
#include <cstdint>
#include <algorithm>
#include <map>
#include <limits>
#include <iomanip>

template <class T>
typename T::value_type process(T container){
    typename T::value_type sum{};
    if(container.size() > 0){
        sum += *std::next(container.end(), -1);
        if(container.size() > 2){
            sum += *std::next(container.end(), -3);
            if(container.size() > 4){
                sum += *std::next(container.end(), -5);
            }
        }
    } else {
        typename T::value_type def{};
        return def;
    }
    return sum;
};
