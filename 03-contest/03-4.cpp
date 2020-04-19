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

class Sum{
    double ans = 0;
    double x_;
    public:
        Sum(double x = 0) : x_(x) {}

        void operator() (double x){
            ans += x;
        }
        double ret_ans(){
            return ans;
        }
};

int main(void){
    double num;
    std::vector <double> arr;
    while(std::cin >> num){
        arr.push_back(num);
    }

    int amount = arr.size() / 10;
    arr.erase(arr.begin() + arr.size() - amount, arr.end());
    arr.erase(arr.begin(), arr.begin() + amount);

    std::sort(arr.begin(), arr.end());

    amount = arr.size() / 10;
    arr.erase(arr.begin() + arr.size() - amount, arr.end());
    arr.erase(arr.begin(), arr.begin() + amount);

    Sum s = std::for_each(arr.begin(), arr.end(), Sum());
    std::cout << std::fixed << std::setprecision(10) << s.ret_ans() / arr.size() << std::endl;
}
