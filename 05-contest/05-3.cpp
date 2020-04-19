#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include <memory>
#include <unordered_map>

class abstractFigureCreator
{
    public:
        virtual Figure * create(const std::string &p) const = 0;
};

template <class C>
class FigureCreator : public abstractFigureCreator
{
    public:
        Figure * create(const std::string &p) const override { return C::make(p); }
};

class FigureFactory
{
    protected:
    std::unordered_map<char, std::unique_ptr<abstractFigureCreator>> _factory;
    //std::map <char, abstractFigureCreator*> _factory;

    public:
        FigureFactory();
        FigureFactory(const FigureFactory &) { }
        FigureFactory &operator=(const FigureFactory &) { return *this; }
        ~FigureFactory() { _factory.clear(); }

        static FigureFactory *factory_instance() {
            static FigureFactory instance;
            return &instance;
        }

        template <class C> void add(char id);
        Figure *CreateFigure(char id, const std::string &parameter);
};

template <class C>
void FigureFactory::add(const char id)
{
    if (_factory.find(id) == _factory.end()) {
        _factory[id] = static_cast<std::unique_ptr<abstractFigureCreator>>(new FigureCreator<C>());
    }
}

Figure *FigureFactory::CreateFigure(char id, const std::string &parameter){
    auto it = _factory.find(id);
    if (it != _factory.end()) {
        return it->second->create(parameter);
    } else {
        return nullptr;
    }
}

FigureFactory::FigureFactory() {
    add<Rectangle>('R');
    add<Circle>('C');
    add<Square>('S');
}

bool comp(Figure * a, Figure * b){
    return a->get_square() < b->get_square();
}

int main()
{
    std::vector<Figure*> arr;
    char idx;
    std::string line, parameter;

    while (getline(std::cin, line)) {
        std::stringstream stream(line);
        stream >> idx;
        getline(stream, parameter);
        arr.push_back(FigureFactory::factory_instance()->CreateFigure(idx, parameter));
    }

    std::stable_sort(arr.begin(), arr.end(), comp);
    for (auto &item : arr) {
        std::cout << item->to_string() << std::endl;
    }
    for(auto & i : arr){
        delete i;
    }
}
