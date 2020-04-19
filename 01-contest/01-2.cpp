#include <iostream> 
class A 
{ 
    public: 
        int a, b = 0;
        A() {
            std::cin >> a;
            b = 0;
        }

        A(A &prev) {
            std::cin >> a;
            b = 1;
            a += prev.a;
        }

        ~A() {
            if(b != 0)
            std::cout << a << std::endl;
        }
};
