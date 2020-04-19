#include <iostream>
#include <math.h>

enum { SIZE = 100 };

namespace numbers{

    class complex{

    private:
        double re_= 0, im_= 0;
    public:
        complex(double re = 0, double im = 0){
            re_ = re;
            im_ = im;
        }
        explicit complex(std::string in){
            const char* str = in.c_str();
            char* next;
            re_ = strtod(str + 1, &next);
            im_ = strtod(next + 1, NULL);
        }
        const double im(void) const {
            return im_;
        }
        const double re(void) const {
            return re_;
        }
        const double abs2(void) const {
            return re_ * re_ + im_ * im_;
        }
        const double abs(void) const {
            return sqrt(re_ * re_ + im_ * im_);
        }
        friend complex operator+ (const complex &A, const complex &B);
        friend complex operator- (const complex &A, const complex &B);
        friend complex operator* (const complex &A, const complex &B);
        friend complex operator/ (const complex &A, const complex &B);

        const complex operator+= (const complex &in) {
            this->im_ += in.im_;
            this->re_ += in.re_;
            complex A(re_, im_);
            return A;
        }

        const complex operator-= (const complex &in){
            this->im_ -= in.im_;
            this->re_ -= in.re_;
            complex A(re_, im_);
            return A;
        }

        const complex operator*= (const complex &in){
            double tmp_im = this->re_ * in.im_ + this->im_ * in.re_;
            this->re_ = this->re_ * in.re_ - this->im_ * in.im_;
            this->im_ = tmp_im;
            complex A(re_, im_);    
            return A;
        }

        const complex operator/= (const complex &in){
            double tmp_im = (in.re_ * this->im_ - this->re_ * in.im_) / (in.abs2());
            this->re_ = (this->re_ * in.re_ + this->im_ * in.im_) / (in.abs2());
            this->im_ = tmp_im;
            complex A(re_, im_);
            return A;
        }

        const complex operator~ (void) const {
            complex Out(re_, -im_);
            return Out;
        }

        const complex operator- (void) const {
            complex Out(-re_, -im_);
            return Out;
        }

        std::string to_string(void) const {
            char output[SIZE];
            snprintf(output, SIZE, "(%.10g,%.10g)", re_, im_);
            return std::string(output);
        }
    };

    complex operator+ (const complex &A, const complex &B) {
        complex Out(A.re_ + B.re_, A.im_ + B.im_);
        return Out;
    }

    complex operator- (const complex &A, const complex &B) {
        complex Out(A.re_ - B.re_, A.im_ - B.im_);
        return Out;
    }

    complex operator* (const complex &A, const complex &B) {
        complex Out(A.re_ * B.re_ - A.im_ * B.im_, A.re_ * B.im_ + B.re_ * A.im_);
        return Out;
    }

    complex operator/ (const complex &A, const complex &B) {
        complex Out((A.re_ * B.re_ + A.im_ * B.im_) / (B.abs2()), (B.re_ * A.im_ - A.re_ * B.im_) / (B.abs2()));
        return Out;
    }
}
