#include <iostream>
/*
L1 = { a^n * b^m * c^m * d^n | m, n > 0 }.
S aAd
A aAd
A bB
B bBс
B c
*/

void B (int n, int m) {
    if(m > 0) {
        std::cout << 'b';
        B(n, m - 1);
        std::cout << 'c';
    } else {
        std::cout << 'c';
    }
}

void A (int n, int m) {
    if(n > 0) {
        std::cout << 'a';
        A(n - 1, m);
        std::cout << 'd';
    } else if(m > 0){
        std::cout << 'b';
        B(n, m - 1);
    }
}

void S (int n, int m) {
    std::cout << 'a';
    A(n - 1, m);
    std::cout << 'd';
    if(n > 1){
        std::cout << std::endl;
        S(n - 1, m + 1);
    }
}

int main ()
{
    int k;
    std::cin >> k;
    if(k % 2 == 0 && k >= 4) {
        S((k - 2) / 2, 1);
    }
}
