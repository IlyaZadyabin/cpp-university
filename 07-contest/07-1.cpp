#include <iostream>

class rec{
    std::string str;
public:
    ~rec() noexcept(false) {
        if(std::cin >> str) {
            try {
                rec new_rec = rec();
            }
            catch (int error) {
                std::cout << str << std::endl;
                throw 0;
            }
        } else {
            throw 0;
        }
    }
};

int main()
{
    try{
        rec first = rec();
    }
    catch(int error){}
}
