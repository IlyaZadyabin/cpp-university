#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

struct action{
    char CHAR;
    std::string NEW;
};

int main()
{
    typedef std::pair<std::string, std::vector <action>> elemType;
    std::map <std::string, std::vector <action>> machineActions;
    std::vector <std::string> endStates;
    char CHAR;
    std::string CUR, NEW;
    std::cin >> CUR;
    while(CUR != "END"){
        std::cin >> CHAR >> NEW;
        machineActions.insert(elemType(CUR, std::vector<action>{}));
        machineActions[CUR].push_back(action{CHAR, NEW});
        std::cin >> CUR;
    }

    std::cin >> CUR;
    while(CUR != "END"){
        endStates.push_back(CUR);
        std::cin >> CUR;
    }

    std::string curState, testString;
    std::cin >> curState >> testString;

    std::vector <action> tmp_action;
    bool symbolWasFound, isStringAllowed = true;
    for (auto i = 0; i < (int) testString.size(); i++) {
        tmp_action = machineActions[curState];

        symbolWasFound = false;
        for (const auto &item : tmp_action) {
            if(item.CHAR == testString[i]){
                symbolWasFound = true;
                curState = item.NEW;
                break;
            }
        }
        if(!symbolWasFound){
            std::cout << 0 << "\n" << i << "\n" << curState << std::endl;
            isStringAllowed = false;
            break;
        }
    }
    bool isEndValid = false;
    if(isStringAllowed){
        for (const auto &state : endStates) {
            if(curState == state){
                isEndValid = true;
                break;
            }
        }
        if(isEndValid) {
            std::cout << 1 << "\n" << testString.size() << "\n" << curState << std::endl;
        } else {
            std::cout << 0 << "\n" << testString.size() << "\n" << curState << std::endl;
        }
    }

}
