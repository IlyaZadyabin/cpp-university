#include <iostream>
#include <algorithm>
#include <cmath>

namespace Game {
    template<typename T>
    class Coord {
    public:
        typedef T value_type;
        T row, col;

        Coord() = default;

        explicit Coord(T r) : row(r), col(r) {}

        Coord(T r, T c) : row(r), col(c) {}
    };

    template<typename T>
    typename T::value_type dist(const T &field, const T &first, const T &second) {
        typedef typename T::value_type val;
        val r1 = first.row, c1 = first.col, r2 = second.row, c2 = second.col;

        double tmp_c1 = c1;
        val u1 = c1;
        val v1 = r1 + (val) std::floor(tmp_c1 / 2);

        double tmp_c2 = c2;
        val u2 = c2;
        val v2 = r2 + (val) std::floor(tmp_c2 / 2);

        val du = u2 - u1;
        val dv = v2 - v1;

        if(du * dv >= 0){
            return std::max(std::abs(du), std::abs(dv));
        } else {
            return std::abs(du) + std::abs(dv);
        }
    }
}
