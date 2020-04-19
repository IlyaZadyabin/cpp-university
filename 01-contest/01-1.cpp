#include <iostream> 
class Sum 
{ 
    public: 
        int value;
        Sum(int a, int b) {
            value = a + b;
        }

        Sum(Sum prev, int b)
        {
            value = prev.get() + b;
        }

        int get() const {
            return value;
        }
}; 
