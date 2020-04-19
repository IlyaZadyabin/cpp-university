#include <iostream>
#include <vector>
#include <functional>

template <class InputIt, typename F>
void myapply(InputIt first, InputIt last, F f){
    for(auto it = first; it != last; it = std::next(it, 1)){
        f(*it);
    }
}

template <class InputIt, class Predicate>
std::vector <std::reference_wrapper <typename std::iterator_traits <InputIt> ::value_type> > 
myfilter2(InputIt first, InputIt last, Predicate f){
    std::vector <std::reference_wrapper <typename std::iterator_traits <InputIt> ::value_type> > vec{};
    for(auto it = first; it != last; it = std::next(it, 1)){
        if(f(*it)){
            vec.insert(vec.end(), *it);
        }
    }
    return vec;
}
