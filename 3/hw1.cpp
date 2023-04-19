#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void init(vector<int>& v);
void print_numbers(vector<int>& v, int number);

int main()
{
    vector<int> numbers;
    init(numbers);

    int number = 0;
    cin >> number;
    print_numbers(numbers, number);

    return 0;
}

void init(vector<int>& v)
{
    int N = 0;
    cin >> N;

    int tmp = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
}

void print_numbers(vector<int>& v, int number)
{
    vector<int>::iterator num_it = find_if(v.begin(), v.end(), [number] (int element) {return (element > number);});
    if (num_it != v.begin() && num_it != v.end())
    {
        --num_it;
        for (; num_it != v.begin(); --num_it)
            cout << *num_it << ' ';
        cout << *(v.begin()) << endl;
    }
}
