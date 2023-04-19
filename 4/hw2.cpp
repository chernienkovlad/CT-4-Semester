#include <iostream>
#include <vector>
#include <map>
#include <string>

template <typename T>
bool f1(std::vector<T> vector, T element)
{
    for (auto item : vector)
        if (item == element)
            return true;
    
    return false;
}

template <typename T1, typename T2>
bool f1(std::map<T1, T2> map, std::pair<T1, T2> element)
{
    for (auto pair : map)
        if (pair == element)
            return true;

    return false;
}

template <typename T>
bool f2(std::vector<T> vector, T element)
{
    return (vector.size() + 1) % 2;
}

template <typename T1, typename T2>
bool f2(std::map<T1, T2> map, std::pair<T1, T2> element)
{
    return (map.size() + 1) % 2;
}

class checker
{
public:
    int counter = 0;

    template <class foo, typename C, typename T>
    void check(foo func, std::vector<C> vector, T element)
    {
        for (auto container : vector)
            if (func(container, element))
                (this->counter)++;
    }
    ~checker()
    {
        std::cout << counter << std::endl;
    }
};

int main()
{
    checker ch;
    
    std::vector<std::vector<int>> vector = {{1, 3, 34, 43}, {34, 3, 3, 4, 3}};
    std::vector<std::map<const std::string, int>> map = {{{"a", 1}, {"b", 2}}, {{"hello", 345}, {"world", 345}}};

    ch.check(f1<int>, vector, 3);
    ch.check(f1<const std::string, int>, map, std::make_pair("a", 1));
    ch.check(f2<int>, vector, 0);
    ch.check(f2<const std::string, int>, map, std::make_pair("0", 0));

    return 0;
}
