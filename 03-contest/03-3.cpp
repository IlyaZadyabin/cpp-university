#include <iostream>
#include <math.h>
#include <new>
#include <vector>
#include <bits/c++config.h>
#include <iterator>
#include <cstdint>
#include <algorithm>
#include <map>

void process(const std::vector <int> &v1, std::vector<int> &v2)
{
    if(v1.size() > 0 && v2.size() > 0) {
        std::vector <int> tmp_v1 = v1;
        std::vector <int> tmp_v2;
        
        std::sort(tmp_v1.begin(), tmp_v1.end()); 
        auto it = std::unique(tmp_v1.begin(), tmp_v1.end()); 
        tmp_v1.resize(std::distance(tmp_v1.begin(), it)); 
        
        auto v1_it = tmp_v1.begin();

        for(auto v2_it = v2.begin(); v2_it != v2.end(); v2_it++){
            if(v1_it != tmp_v1.end() && (*v1_it < 0 || *v1_it >= (int) v2.size())){
                v1_it++, v2_it--;
            } else if(v1_it != tmp_v1.end() && std::distance(v2.begin(), v2_it) == *v1_it) {
                v1_it++;
            } else if(std::distance(v2.begin(), v2_it) != *v1_it || v1_it == tmp_v1.end()){
                tmp_v2.push_back(*v2_it);
            } 
        }
        v2 = tmp_v2;
    }
}
