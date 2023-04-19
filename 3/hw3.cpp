#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

template <typename T>
vector<T> foo(set<T> s, T elem)
{
    auto s_it = s.end();
    --s_it;

    vector<T> v;
    for (; s_it != s.begin(); --s_it)
    {
        if (*s_it > elem)
        {
            v.push_back(*s_it);
        }
    }
    if (*(s.begin()) > elem) v.push_back(*(s.begin()));
   
    return v;
}

int main()
{
    set<int> s = {3, 1, 34, 57, 13, 8, 92};
    int elem = 21;

    vector<int> v = foo(s, elem);

    for (auto elem : v)
        cout << elem << ' ';
    cout << endl;

    return 0;
}
