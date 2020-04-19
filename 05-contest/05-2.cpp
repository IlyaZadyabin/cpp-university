#include <iostream>
#include <vector>
#include <cmath>

class Rectangle : public Figure
{
    private:
        double width, height;
    public:
        Rectangle(double w, double h) : width(w), height(h) {}

        double get_square() const override  {
            return width * height;
        }

        static Rectangle * make(const std::string& str){
            std::string::size_type ptr;
            double x = std::stod(str, &ptr);
            double y = std::stod(str.substr(ptr));
            return new Rectangle(x, y);
        }
};

class Square : public Figure
{
    private:
        double side;
    public:
        explicit Square(double s) : side(s) {}

        double get_square() const override {
            return side * side;
        }

        static Square * make(const std::string& str){
            return new Square(std::stod(str));
        }
};

class Circle : public Figure
{
    private:
        double rad;
    public:
        explicit Circle(double r) : rad(r) {}

        double get_square() const override {
            return rad * rad *  M_PI;
        }

        static Circle * make(const std::string& str){
            return new Circle(std::stod(str));
        }
};
