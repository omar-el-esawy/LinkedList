#include <iostream>
#include "List.cpp"

using namespace std;


int main() {
    cout << "default constructor\n";
    List<int> defList;
    defList.push_back(2);
    defList.push_front(1);
    for (auto x: defList)
        cout << x << ' ';
    cout << '\n';
    cout << "parameterized  constructor\n";
    List<int> parList(5, 3);
    for (auto x: parList)
        cout << x << ' ';
    cout << '\n';
    cout << "size: " << parList.size() << '\n';
    parList = defList;
    for (auto x: parList)
        cout << x << ' ';
    cout << '\n';
    cout << "using iterator after copy constructor\n";
    auto it = parList.end();
    it--;
    cout << *it << endl;
    cout << "insert in the the second postion\n";
    auto bit = parList.begin();
    bit++;
    parList.insert(3, bit);
    for (auto x: parList)
        cout << x << ' ';
    cout << '\n';
    cout << "delete in the the second postion\n";
    auto it2 = parList.begin();
    it2++;
    parList.erase(it2);
    for (auto x: parList)
        cout << x << ' ';

    return 0;
}