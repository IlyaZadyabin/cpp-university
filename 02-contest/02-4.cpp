#include <iostream>
#include <math.h>
#include <new>
#include <vector>
#include <string>
#include <bits/c++config.h>
#include "cmc_complex.h"
#include "cmc_complex_stack.h"
#include "cmc_complex_eval.h"

using namespace numbers;

int main(int argc, char **argv){
    complex C(argv[1]);
    double R = strtod(argv[2], NULL);
    int N = strtol(argv[3], NULL, 10); 
    std::vector <std::string> arguments;

    for(int i = 4; i < argc; i ++){
        arguments.push_back(std::string(argv[i]));    
    }

    complex middle_i(0,0), integral(0,0);

    for(int i = 1; i <= N; i++){
        double alpha = 2 * M_PI * i / N;
        middle_i = complex(R * cos(alpha), R * sin(alpha)) + C;
        integral += eval(arguments, middle_i) * complex(-R * sin(alpha), R * cos(alpha));
    }

    integral *= 2 * M_PI / N;

    std::cout << integral.to_string() << std::endl;
    return 0;
}

