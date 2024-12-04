#include "lib.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cout << "Hamming Code Program" << endl;
    cout << "====================" << endl;

    const int data_size = 4; // Длина входных данных
    vector<int> data(data_size);

    // Ввод данных
    cout << "Enter 4 data bits (0 or 1): ";
    for (int i = 0; i < data_size; i++) {
        cin >> data[i];
        if (data[i] != 0 && data[i] != 1) {
            cout << "Invalid input! Please enter only 0 or 1." << endl;
            return 1;
        }
    }

    // Выполнение кодирования и проверки
    hamming_code(data);

    return 0;
}
