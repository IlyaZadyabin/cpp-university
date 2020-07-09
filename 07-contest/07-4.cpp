#include <iostream>
#include <map>
#include <vector>
#include <string>

class State{
private:
    std::map<std::vector<char>, std::vector<char>> statesMap;
    char curState = 'S';
public:
    State() {
        typedef std::pair<std::vector<char>, std::vector<char>> pairType;
        statesMap.insert(pairType({'S', '0'}, {'S', '0', 'R'}));
        statesMap.insert(pairType({'S', '1'}, {'A', '1', 'R'}));
        statesMap.insert(pairType({'S', '#'}, {'S', '#', 'S'}));
        statesMap.insert(pairType({'A', '0'}, {'A', '0', 'R'}));
        statesMap.insert(pairType({'A', '1'}, {'S', '1', 'R'}));
        statesMap.insert(pairType({'A', '#'}, {'B', '#', 'L'}));
        statesMap.insert(pairType({'B', '0'}, {'B', '0', 'L'}));
        statesMap.insert(pairType({'S', '1'}, {'A', '1', 'R'}));
        statesMap.insert(pairType({'B', '1'}, {'B', '1', 'L'}));
        statesMap.insert(pairType({'B', '#'}, {'C', '#', 'R'}));
        statesMap.insert(pairType({'S', '1'}, {'A', '1', 'R'}));
        statesMap.insert(pairType({'C', '0'}, {'C', '0', 'R'}));
        statesMap.insert(pairType({'C', '1'}, {'D', '0', 'S'}));
        statesMap.insert(pairType({'D', '0'}, {'D', '0', 'S'}));
    }

    int changeState(char *input){
        auto iter = statesMap.find(std::vector <char> {curState, *input});
        *input = iter->second[1];
        curState = iter->second[0];
        int ans = 0;
        if(iter->second[2] == 'R'){
            ans = 1;
        } else if(iter->second[2] == 'L'){
            ans = -1;
        }
        return ans;
    }

    char getState() const{
        return curState;
    }
};

int main()
{
    char input;
    std::vector <char> line;
    while(std::cin >> input){
        line.push_back(input);
    }

    int i = 0, shift;
    State state;
    char prevState = state.getState(), prevSymbol;
    while(line[i] == '#'){
        i++;
    }

    while(i < (int) line.size() && i >= 0){
        prevSymbol = line[i];
        shift = state.changeState(&line[i]);
        if(shift == 0 && prevState == state.getState() && prevSymbol == line[i]){
            break;
        }
        prevState = state.getState();
        i += shift;
    }

    for (const auto &item : line) {
        std::cout << item;
    }
}
