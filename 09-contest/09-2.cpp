#include <iostream>
#include <string>
#include <set>

int isBelongsToLanguage(const std::string& str){
    int ans = 1;
    enum state { A, B, C, D, E, F, G, N, S };
    //A = 1, B = 10, C = 11, D = 100,
    //E = 101, F = 110, G = 111;

    state cur_state = N;
    for (const auto &item : str) {
        if(cur_state == S){
            break;
        }

        switch (cur_state) {
            case N: if(item == '1'){
                        cur_state = A;
                    } else if(item != '0'){
                        cur_state = S;
                    }
                    break;
            case A: if(item == '0'){
                        cur_state = B;
                    } else if(item == '1'){
                        cur_state = C;
                    } else {
                        cur_state = S;
                    }
                    break;
            case B: if(item == '1'){
                        cur_state = E;
                    } else if(item == '0'){
                        cur_state = D;
                    } else {
                        cur_state = S;
                    }
                    break;
            case C: if(item == '1'){
                        cur_state = G;
                    } else if(item == '0'){
                        cur_state = F;
                    } else {
                        cur_state = S;
                    }
                    break;
            case D: if(item == '1'){
                        cur_state = A;
                    } else if(item == '0'){
                        cur_state = N;
                    } else {
                        cur_state = S;
                    }
                    break;
            case E: if(item == '1'){
                        cur_state = C;
                    } else if(item == '0'){
                        cur_state = B;
                    } else {
                        cur_state = S;
                    }
                    break;
            case F: if(item == '1'){
                        cur_state = E;
                    } else if(item == '0'){
                        cur_state = D;
                    } else {
                        cur_state = S;
                    }
                    break;
            case G: if(item == '1'){
                        cur_state = G;
                    } else if(item == '0'){
                        cur_state = F;
                    } else {
                        cur_state = S;
                    }
                    break;
            case S:
                break;
        }
    }
    if(cur_state == S || cur_state == A || cur_state == B || cur_state == C || cur_state == N){
        ans = 0;
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
