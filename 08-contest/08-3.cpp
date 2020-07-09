#include<iostream>
#include<string>

struct Terminals{
    bool onlyTerminals = true;
    bool onlyNonTerminals = true;
};

Terminals checkTerminals(const std::string& left){
    Terminals ans;
    for (const auto &item : left) {
        if(isupper(item)){
            ans.onlyTerminals = false;
        } else {
            ans.onlyNonTerminals = false;
        }
    }
    return ans;
}

bool containsTheS(const std::string& right){
    for (const auto &item : right) {
        if(item == 'S'){
            return true;
        }
    }
    return false;
}

int main()
{
    bool containsBeginRule = false, isContextFree = true, isNonReducing = true;
    bool isEmpty = true, isOnlyTerminals = false;
    int amountOfEpsilons = 0, amountOfS = 0, ans;

    std::string left, right;
    Terminals check;
    while(std::cin >> left && std::cin >> right){
        if(!isOnlyTerminals){
            isEmpty = false;
            check = checkTerminals(left);
            if(check.onlyTerminals) isOnlyTerminals = true;
            if (left[0] == 'S' && left.size() == 1) containsBeginRule = true;

            if (isContextFree) {
                if (!check.onlyNonTerminals || left.size() != 1) isContextFree = false;
                if (left.size() > right.size()) isNonReducing = false;
                if (right[0] == '_' && right.size() == 1) amountOfEpsilons++;
                if(right[0] == '_' && right.size() == 1 && left[0] != 'S') isNonReducing = false;
                if (containsTheS(right)) amountOfS++;
            }
        }
    }

    if(isEmpty || !containsBeginRule || isOnlyTerminals){
        ans = -1;
    } else if(isContextFree){
        isNonReducing = isNonReducing && ((amountOfEpsilons == 1 && amountOfS == 0) || amountOfEpsilons == 0);
        ans = isNonReducing ? 23 : 2;
    } else {
        ans = 10;
    }
    std::cout << ans << std::endl;
}
