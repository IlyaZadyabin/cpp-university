#include <iostream>
#include <algorithm>
#include <cmath>
#include <complex>
#include <vector>
#include <array>
#include <limits>
namespace Equations
{
    constexpr int arr_size = 3, eps_multiplier = 32;

    template<typename T>
    std::pair <bool, std::vector<std::complex <T>>> quadratic(std::array <std::complex <T>, arr_size> v){
        typedef std::vector<std::complex <T>> vec_type;
        typedef std::complex<T> type;

        std::complex <T> c = v[0], b = v[1], a = v[2];
        std::pair <bool, vec_type> answer;
        auto eps = eps_multiplier * std::numeric_limits<T>::epsilon();

        answer.first = true;
        if(std::norm(a) < eps){
            if(std::norm(b) < eps){
                if(std::norm(c) < eps){
                    answer.first = false;
                } else {
                    answer.second = vec_type{};
                }
            } else {
                answer.second = vec_type{-c / b};
            }
        } else {
            auto discriminant = b*b - type(4)*a*c;
            auto x1 = (-b + sqrt(discriminant)) / (type(2)*a);
            auto x2 = (-b - sqrt(discriminant)) / (type(2)*a);
            answer.second = vec_type{x1, x2};
        }
        return answer;
    }
}
