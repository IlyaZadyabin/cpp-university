#include <iostream>
#include <vector>
#include <algorithm>
#include <fcntl.h>
#include <sys/inotify.h>

class Matrix
{
    private:
        std::vector<std::vector<uint32_t>> vec_of_rows;
    public:
        Matrix(){
            vec_of_rows.emplace_back(std::vector <uint32_t> {});
        }
        uint32_t & operator()(uint64_t y, uint64_t x){
            return vec_of_rows[y][x];
        }
        auto & operator()(uint64_t y){
            return vec_of_rows[y];
        }
        void add_row(){
            vec_of_rows.emplace_back(std::vector <uint32_t > {});
        }
        size_t rows(){
            return vec_of_rows.size();
        }
};

void reduce(uint32_t & m, uint32_t power)
{
    int64_t tmp = m - power;
    m = tmp < 0 ? 0 : tmp;
}

void execute_amendment(Matrix & m, uint32_t y, uint32_t x, uint32_t power)
{
    reduce(m(y,x), power);

    if(x >= 1)                              reduce(m(y, x - 1), power / 2);
    if(x < m(y).size() - 1)                 reduce(m(y, x + 1), power / 2);
    if(y >= 1)                              reduce(m(y-1,x), power/2);
    if(y < m.rows() - 1)                    reduce(m(y+1,x), power/2);
    if(y >= 1 && x >= 1)                    reduce(m(y-1,x-1), power/4);
    if(y >= 1 && x < m(y).size() - 1)       reduce(m(y-1,x+1), power/4);
    if(y < m.rows() - 1 && x >= 1)          reduce(m(y+1,x-1), power/4);
    if(y < m.rows() - 1 && x < m(y).size()) reduce(m(y+1,x+1), power/4);
}

int main()
{
    Matrix matrix;
    uint32_t num{};
    uint32_t row{};
    char tmp{};
    std::vector <uint32_t> amendments{};
    while(true){
        if(std::cin.peek() == '\n') {
            std::cin.get(tmp);
            if(std::cin.peek() == '\n') {
                break;
            }
            matrix.add_row();
            row++;
        }
        std::cin >> num;
        matrix(row).push_back(num);
    }

    while(std::cin >> num){
        amendments.push_back(num);
    }

    std::sort(amendments.begin(), amendments.end());
    uint32_t max = 0;
    uint32_t max_x = 0, max_y = 0;
    while(!amendments.empty()) {
        for (auto i = 0; i < matrix.rows(); i++) {
            for (auto j = 0; j < matrix(i).size(); j++) {
                if (matrix(i, j) > max) {
                    max = matrix(i, j);
                    max_y = i, max_x = j;
                }
            }
        }
        execute_amendment(matrix, max_y, max_x, amendments.back());
        amendments.pop_back();
        max = 0;
    }
    for (auto i = 0; i < matrix.rows(); i++) {
        for (auto j = 0; j < matrix(i).size(); j++) {
            printf("%u ", matrix(i,j));
        }
        printf("\n");
    }
}
