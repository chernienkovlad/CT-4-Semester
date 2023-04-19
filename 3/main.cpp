// find_if, count_if, remove_if, partition, min_element, set_intersection

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main()
{
    // vector<int> v = {1, 3, 5, 7, 9, 10, 11, 12, 13, 14};
    // int thr;
    // thr = 7;
    // int cnt = count_if(v.begin(), v.end(), [thr] (int element) {return (element > thr);});
    // cout << cnt << endl;

    vector<string> v = {"Ksu", "Ksusha", "David", "Ivan", "Savva", "Korney", "Vlad"};
    vector<string> v1 = {"Pin", "Savva", "Vlad", "Sin", "Zin", "Vitek"};
    vector<string> v2(7);
    // vector<string> shk = {"Sin", "Zin", "Pin"};
    // vector<string>::iterator result = find_if(v.begin(), v.end(), [] (string word) {return (word[0] == 'K');}); // вернуть первого, нач на К
    // vector<string>::reverse_iterator it = v.rbegin();
    // cout << *(next(it)) << endl;
    auto it_ = set_intersection(v.begin(), v.end(), v1.begin(), v1.end(), v2.begin());
    // cout << *it_ << endl;
    // for (auto it = it_; it != v.end(); it++)
    // {
    //     v.erase(it);
    //     it--;
    // }
    for (auto s : v2)
        cout << s << endl;

    // set<int> s = {1, 5, 9};
    // auto it = s.begin();
    // it += 1; // error: no viable overloaded '+='
    // cout << *it << endl;

    return 0;
}
