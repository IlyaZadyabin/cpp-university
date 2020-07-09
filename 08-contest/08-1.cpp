#include <iostream>

int isBelongs(const std::string& str){
    int ans = 1, stateNum = 0;

    for (auto &item : str) {
        if(item == '1' || item == '2'){
            stateNum = 1;
        } else if(item == '3' || item == '4'){
            if(stateNum){
                ans = 0;
                break;
            }
        } else {
            ans = 0;
            break;
        }
    }
    return ans;
}

int main()
{
    std::string input;
    while(std::cin >> input){
        std::cout << isBelongs(input) << std::endl;
    }
}
