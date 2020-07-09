#include <iostream>
#include <string>
#include <vector>
#include <set>

struct rule{
    char leftPart;
    std::string rightPart;
    bool isIncluded = false;
};

bool isChangedAfterInsert(const rule& line, std::set <char>& host){
    auto beginSize = host.size();
    if(host.find(line.leftPart) != host.end()){
        for (const auto &item : line.rightPart) {
            if(isupper(item)){
                host.insert(item);
            }
        }
    }
    return beginSize != host.size();
}

int main()
{
    std::vector <rule> grammar;
    std::set <char> host = {'S'};
    std::string rightPart;
    char leftPart;

    while(std::cin >> leftPart && std::cin >> rightPart){
        grammar.push_back(rule{leftPart, rightPart, false});
    }

    for(auto i = 0; i < (int) grammar.size(); i++){
        if(isChangedAfterInsert(grammar[i], host)){
            i = -1;
        }
    }

    for (auto &item : grammar) {
        item.isIncluded = host.find(item.leftPart) != host.end();
        if(item.isIncluded){
            std::cout << item.leftPart << " " << item.rightPart << std::endl;
        }
    }
}
