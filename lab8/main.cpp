#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<int> arr = { 3, -5, 7, -2, 8, -1, 4, -3, 6, -7 };

    cout << "Масив: ";
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    auto minPos = min_element(arr.begin(), arr.end());
    int minIndex = distance(arr.begin(), minPos);
    cout << "Індекс мінімального елемента: " << minIndex << endl;

    int firstNegIndex = -1, secondNegIndex = -1;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] < 0) {
            if (firstNegIndex == -1) {
                firstNegIndex = i;
            }
            else {
                secondNegIndex = i;
                break;
            }
        }
    }

    int sumBetweenNegatives = 0;
    if (firstNegIndex != -1 && secondNegIndex != -1 && secondNegIndex > firstNegIndex + 1) {
        sumBetweenNegatives = accumulate(arr.begin() + firstNegIndex + 1, arr.begin() + secondNegIndex, 0);
    }

    cout << "Сума між першим і другим від’ємними елементами: " << sumBetweenNegatives << endl;

    stable_partition(arr.begin(), arr.end(), [](int x) {
        return abs(x) <= 1;
        });

    cout << "Перетворений масив: ";
    for (int elem : arr) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}