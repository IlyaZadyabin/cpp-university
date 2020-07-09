#include <iostream>
#include "boost/date_time/gregorian/gregorian.hpp"

boost::gregorian::date string_to_date(std::string s){
    std::string delimiter = "-";
    size_t pos;
    int year, month, day;

    pos = s.find(delimiter);
    year = std::stoi(s.substr(0, pos));
    s.erase(0, pos + delimiter.length());

    pos = s.find(delimiter);
    month = std::stoi(s.substr(0, pos));
    s.erase(0, pos + delimiter.length());

    day = std::stoi(s);

    return boost::gregorian::date(year, month, day);
}

int main()
{
    std::string line;
    std::cin >> line;
    boost::gregorian::date tmp_date = string_to_date(line);
    boost::gregorian::date_duration dur;
    long long days = 0;

    while(std::cin >> line){
        boost::gregorian::date cur_date = string_to_date(line);
        dur = cur_date - tmp_date;
        days += abs(dur.days());
        tmp_date = cur_date;
    }
    std::cout << days << std::endl;
}
