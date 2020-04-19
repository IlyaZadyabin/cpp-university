#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <functional>
#include <string>

namespace numbers{
    complex eval(const std::vector<std::string> &args, const complex &z) {
        complex_stack Stack;

        std::map< std::string, std::function<complex_stack(complex_stack&)> > Table{
            {std::string("+"),[](complex_stack &stack){
                complex_stack Ans(stack);
                complex b = +Ans; Ans = ~Ans; 
                complex a = +Ans; Ans = ~Ans;
                return Ans << complex(a.re() + b.re(), a.im() + b.im());} },
            {std::string("-"),[](complex_stack &stack){
                complex_stack Ans(stack);
                complex b = +Ans; Ans = ~Ans;
                complex a = +Ans; Ans = ~Ans;
                return Ans << complex(a.re() - b.re(), a.im() - b.im());} },
            {std::string("*"),[](complex_stack &stack){
                complex_stack Ans(stack);
                complex b = +Ans; Ans = ~Ans;
                complex a = +Ans; Ans = ~Ans;
                return Ans << complex(a.re() * b.re() - a.im() * b.im(),
                        a.re() * b.im() + b.re() * a.im());} },
            {std::string("~"),[](complex_stack &stack){
                complex_stack Ans(stack);
                complex a = +Ans; Ans = ~Ans;
                return Ans << complex(a.re(), -a.im());} },
            {std::string("#"),[](complex_stack &stack){
                complex_stack Ans(stack);
                complex a = +Ans; Ans = ~Ans;
                return Ans << complex(-a.re(), -a.im());} },
            {std::string("!"),[](complex_stack &stack){
                complex_stack Ans(stack);
                complex num = +Ans;
                return Ans << num;} },
            {std::string(";"),[](complex_stack &stack){
                complex_stack Ans(stack);
                Ans = ~Ans; 
                return Ans;} },
            {std::string("z"),[=](complex_stack &stack){
                complex_stack Ans(stack);
                return Ans << z;} },
            {std::string("/"),[](complex_stack &stack){
                complex_stack Ans(stack);
                complex b = +Ans; Ans = ~Ans;
                complex a = +Ans; Ans = ~Ans;
                return Ans << complex((a.re() * b.re() + a.im() * b.im()) / (b.abs2()),
                        (b.re() * a.im() - a.re() * b.im()) / (b.abs2()));} } };

        for (size_t i = 0; i < args.size(); i++){ 
            if(Table.count(args.at(i)) > 0){
                Stack = Table[args.at(i)](Stack);
            } else {
                Stack = (Stack << complex(args.at(i)));
            }
        }
        return complex(+Stack);
    }
}

