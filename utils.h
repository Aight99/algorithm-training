#include <iostream>
#include <vector>
using namespace std;

template <typename T>
vector<T> readVector(int length) {
    vector<T> result(length);
    for (int i = 0; i < length; ++i) {
        cin >> result[i];
    }
    return result;
}

template <typename T>
void printVector(vector<T> v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
}