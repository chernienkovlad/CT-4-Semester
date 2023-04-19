#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include <chrono>

std::vector<int> BuildVector(int i)
{
    return (std::vector<int>){i, i + 1, i + 2, i + 3, i + 4};
}

std::array<int, 5> BuildArray(int i)
{
    return (std::array<int, 5>){i, i + 1, i + 2, i + 3, i + 4};
}

int main()
{
    // int x = 5;
    // int a[3];
    // a[0] = 47;
    // a[1] = 56;
    // a[2] = 78;
    // int y = 2;
    // for (int* z = &y; z != &x; z++)
    // {
    //     std::cout << *z << std::endl;  // out: 2
    // }

    // std::vector<int> v = {1, 2, 3};
    // int& a = v[0];
    // std::cout << a << std::endl;
    // for (int i = 4; i < 100; ++i)
    // {
    //     v.push_back(i);
    // }
    // std::cout << a << std::endl;  // v.reserve(1000000); если занем, что будем пушить 1000000 эл-ов

    // std::deque<int> d = {4, 5, 6};
    // d.push_back(7);
    // d.push_front(3);
    // d.pop_front();
    // d.pop_front();
    // for (int i = 0; i < d.size(); ++i)
    // {
    //     std::cout << d[i] << std::endl;
    // }

    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < 1000000; ++i)
    {
        auto a = BuildVector(i);
    }
    auto fin = std::chrono::steady_clock::now();
    auto duration = fin - start;
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() << std::endl;

    return 0;
}