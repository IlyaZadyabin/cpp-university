#include <iostream>

class S
{
private:
    int num = 0, sum = 0;
    bool isNumReceived = true, start = false;
public:
    explicit operator bool() const {
        return isNumReceived;
    }

    S(){
        while(std::cin >> num){
            start = true;
            sum += num;
        }
        isNumReceived = false;
    }

    ~S(){
        if(start) {
            std::cout << sum << std::endl;
        }
    }
};
