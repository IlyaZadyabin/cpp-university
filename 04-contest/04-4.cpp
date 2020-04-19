#include <iostream>
#include <math.h>
#include <new>
#include <vector>
#include <bits/c++config.h>
#include <iterator>
#include <cstdint>
#include <algorithm>
#include <map>
#include <functional>

template <class Iterator>
Iterator self_remove (Iterator first, Iterator last, Iterator idx)
{
    Iterator ans = first;
    while (first != last) {
        if (first != idx) {
            *ans = std::move(*first);
            ans++;
        }
        first++;
    }
    return ans;
}

template <class It1, class It2>
It2 myremove(It1 first1, It1 last1, It2 first2, It2 last2)
{
    std::vector <typename std::iterator_traits <It1> ::value_type> v1;
    std::copy(first1, last1, back_inserter(v1)); 
    std::sort(v1.begin(), v1.end()); 
    auto it = std::unique(v1.begin(), v1.end()); 
    v1.resize(std::distance(v1.begin(), it)); 
    
    for(auto v1_it = 0; v1_it < (int) v1.size(); v1_it++){
        if(first2 + v1[v1_it] <= last2 && v1[v1_it] >= 0){
            last2 = self_remove(first2, last2, first2 + v1[v1_it]);
            for(auto i = v1_it + 1; i < (int) v1.size(); i++){
                v1[i]--;
            }
        }
    }
    return last2;
}
