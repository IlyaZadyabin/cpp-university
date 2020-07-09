#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>

template <typename T> T distance(const T &x1, const T &y1, const T &x2, const T &y2) {
    return std::max(std::abs(x1 - x2), std::abs(y1 - y2));
}

template <typename T> class Coord{
public:
    typedef T value_type;
    T row, col;
    Coord()= default;
    explicit Coord(T r) : row(r), col(r){}
    Coord(T r, T c) : row(r), col(c){}
};

template <typename T> typename T::value_type dist(const T &field, const T &first, const T &second){
    typename T::value_type m = field.row, n = field.col;
    std::set <typename T::value_type> arr;
    typename T::value_type r1 = first.row, c1 = first.col, r2 = second.row, c2 = second.col;

    arr.insert(distance <typename T::value_type> (r1, c1, r2, c2));
    arr.insert(distance <typename T::value_type> (r1, c1, r2, c2 + n));
    arr.insert(distance <typename T::value_type> (r1, c1, r2, c2 - n));
    arr.insert(distance <typename T::value_type> (r1, c1, r2 + m, c2));
    arr.insert(distance <typename T::value_type> (r1, c1, r2 - m, c2));
    arr.insert(distance <typename T::value_type> (r1, c1, r2 + m, c2 + n));
    arr.insert(distance <typename T::value_type> (r1, c1, r2 + m, c2 - n));
    arr.insert(distance <typename T::value_type> (r1, c1, r2 - m, c2 + n));
    arr.insert(distance <typename T::value_type> (r1, c1, r2 - m, c2 - n));
    return *arr.begin();
}
