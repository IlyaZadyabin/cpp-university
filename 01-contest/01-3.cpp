#include <iostream> 
class Sub
{ 
    public: 
        int num;
        Sub(int a, int b) {
            num = a - b;
        }

        Sub(Sub prev, int b)
        {
            num = prev.value() - b;
        }

        Sub(int b, Sub prev)
        {
            num = b - prev.value();
        }

        int value() const {
            return num;
        }
};
