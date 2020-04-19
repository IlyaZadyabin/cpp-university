#include <iostream>
#include <math.h>
#include <new>
#include <vector>
#include <bits/c++config.h>
#include <iterator>
#include <cstdint>

void process(const std::vector <uint64_t> &first_vec,
        std::vector<uint64_t> &second_vec, int pace){
    if((first_vec.size() > 0) && (second_vec.size() > 0)) {
        auto j = second_vec.end() - 1;
        auto i = first_vec.begin();
        for(; (i < first_vec.end()) && (j >= second_vec.begin()); i += pace, j--){
            *j += *i;
        }
    }
}
