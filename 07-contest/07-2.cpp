#include <iostream>

//Ackermann function

class Result : public std::exception
{
private:
    long long res;
public:
    explicit Result(long long res_) : res(res_){}
    long long getRes() { return res; }
};

class Rec
{
private:
    long long a{}, b{};
    int k{};
public:
    Rec(long long a_, long long b_, int k_) : a(a_), b(b_), k(k_){}

    ~Rec() noexcept(false) {
        if(k == 0){
            throw Result(a + b);
        } else if(k > 0 && b == 1){
            throw Result(a);
        } else {
            try{
                Rec tmp_rec = Rec(a, b-1, k);
            }
            catch(Result &res){
                try {
                    Rec next_Rec = Rec(a, res.getRes(), k-1);
                }
                catch(Result &res){
                    throw res;
                }
            }
        }
    }
};

int main()
{
    long long a{}, b{};
    int k{};

    while(std::cin >> a >> b >> k) {
        try {
            Rec initial = Rec(a, b, k);
        }
        catch (Result &res){
            std::cout << res.getRes() << std::endl;
        }
    }
}
