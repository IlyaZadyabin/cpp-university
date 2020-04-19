#include <iostream>
#include <math.h>
#include <new>
#include <vector>
#include <bits/c++config.h>
#include <iterator>
#include <cstdint>

void process(std::vector <int64_t> &vec, int64_t edge){

        vec.reserve(2 * vec.size());
        for(auto i = vec.rbegin(); i != vec.rend(); i++){
            if(*i >= edge){
                vec.push_back(*i);
            }
        }
}
