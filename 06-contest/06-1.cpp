#include <iostream>
#include <algorithm>
#include <set>

long long int distance(long long int x1, long long int y1, long long int x2, long long int y2)
{
    return std::abs(x1 - x2) + std::abs(y1 - y2);
}

int main()
{
    long long int m, n;
    std::cin >> m >> n;
    long long int r1, c1, r2, c2;
    std::set <long long int> arr;
    while(std::cin >> r1 >> c1 >> r2 >> c2){
        arr.insert(distance(r1, c1, r2, c2));
        arr.insert(distance(r1, c1, r2, c2 + n));
        arr.insert(distance(r1, c1, r2, c2 - n));
        arr.insert(distance(r1, c1, r2 + m, c2));
        arr.insert(distance(r1, c1, r2 - m, c2));
        arr.insert(distance(r1, c1, r2 + m, c2 + n));
        arr.insert(distance(r1, c1, r2 + m, c2 - n));
        arr.insert(distance(r1, c1, r2 - m, c2 + n));
        arr.insert(distance(r1, c1, r2 - m, c2 - n));
        std::cout << *arr.begin() << std::endl;
        arr.clear();
    }
}
