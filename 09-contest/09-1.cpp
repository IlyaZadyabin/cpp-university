#include <iostream>
#include <string>
#include <set>

// тип 1 неукорачивающаяся КЗ грамматика

int isBelongsToLanguage(const std::string& str){
    char state = 'a';
    int ans = 1, cntA = 0, cntZero = 0, cntB = 0, cntOne = 0;

    if(str[0] != 'a'){
        ans = 0;
    } else {
        for (const auto &item : str) {
            if(item == 'a' && state == 'a'){
                cntA++;
            } else if(item == '0' && (state == 'a' || state == '0')){
                state = '0';
                cntZero++;
            } else if(item == 'b' && (state == '0' || state == 'b')){
                state = 'b';
                cntB++;
            } else if(item == '1' && (state == 'b' || state == '1')){
                state = '1';
                cntOne++;
            } else {
                ans = 0;
                break;
            }
        }
        if(cntA != cntB || cntZero != cntOne){
            ans = 0;
        }
    }
    return ans;
}

int main()
{
    std::string input;
    while(std::cin >> input){
        std::cout << isBelongsToLanguage(input) << std::endl;
    }
}
