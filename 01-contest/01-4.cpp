#include <iostream> 
#include <math.h>
#include <iomanip>

int main(void)
{
    int cnt = 0;
    double num = 0, root_of_squares = 0, medium_value = 0;   

    while(!(std::cin >> num).eof()) {
        medium_value += num;
        root_of_squares += num * num;
        cnt++;
    }

    root_of_squares /= cnt;
    medium_value /= cnt;

    double ans = sqrt(root_of_squares - medium_value * medium_value);

    std::cout << std::setprecision(10) << medium_value << std::endl;
    std::cout << std::setprecision(10) << ans << std::endl;
    return 0;
}
