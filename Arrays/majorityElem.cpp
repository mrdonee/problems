//Given an array in which there is guaranteed to be a majority (>50%) element, efficiently find that element

#include <vector>
#include <iostream>
using namespace std;

int majorityElem(vector<int> arr) {
    if (!arr.size()) {
        return -1;
    }
    int count = 1, elem = arr[0];
    for(int i = 1; i < arr.size(); i++) {
        if (arr[i] == elem)
            count++;
        else
            count--;
        if (count <= 0) {
            elem = arr[i];
            count = 1;
        }
    }
    return elem;
}

int main() {
    cout << majorityElem({8}) << endl; // 8
    cout << majorityElem({0, 1, 0}) << endl; // 0
    cout << majorityElem({0, 1, 1}) << endl; // 1
    cout << majorityElem({1, 0, 1}) << endl; // 1
    cout << majorityElem({0, 2, 4, 0, 0, 4, 2, 0, 5, 0, 0}) << endl; // 0
}
