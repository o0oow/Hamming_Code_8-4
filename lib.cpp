#include "lib.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Проверка четности группы битов
int check_parity(int n, int i, const vector<int>& code) {
    int p = 0, k;
    for (int j = i; j <= n; j = k + i) {
        for (k = j; k < j + i && k <= n; k++) {
            if (code[k] == 1) {
                p++;
            }
        }
    }
    return (p % 2 == 0) ? 0 : 1; // Возвращаем 0 для четного, 1 для нечетного
}

// Основная функция кодирования, проверки и исправления
void hamming_code(const vector<int>& data) {
    const int num = 4; // Количество информационных битов
    const int r = 4;   // Количество контрольных битов
    const int n = num + r; // Общий размер кода

    // Подготовка массива для кодирования
    vector<int> code(n + 1, 0);
    int j = 0;

    // Распределение информационных битов
    for (int i = 1; i <= n; i++) {
        if ((i & (i - 1)) != 0) { // Пропускаем позиции степеней двойки
            code[i] = data[j++];
        }
    }

    // Вычисление контрольных битов
    for (int i = 1; i <= n; i <<= 1) { // Позиции 1, 2, 4, 8
        code[i] = check_parity(n, i, code);
    }

    // Вывод закодированного сообщения
    cout << "Encoded Hamming Code: ";
    for (int i = n; i > 0; i--) {
        cout << code[i] << " ";
    }
    cout << endl;

    // Ввод принятого кода
    cout << "Enter the received code (8 bits): ";
    vector<int> received(n + 1);
    for (int i = n; i > 0; i--) {
        cin >> received[i];
    }

    // Проверка ошибок
    int error_position = 0;
    for (int i = 1; i <= n; i <<= 1) { // Позиции контрольных битов
        if (check_parity(n, i, received) != 0) {
            error_position += i;
        }
    }

    // Обработка результата
    if (error_position == 0) {
        cout << "Received code is correct!" << endl;

        // Декодирование данных
        cout << "Decoded data: ";
        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) != 0) { // Пропускаем контрольные биты
                cout << received[i] << " ";
            }
        }
        cout << endl;

    } else if (error_position > n) {
        cout << "Too many errors detected! Unable to correct." << endl;
    } else {
        cout << "Error detected at position: " << error_position << endl;

        // Исправляем единственную ошибку
        received[error_position] ^= 1;

        // Вывод исправленного кода
        cout << "Corrected code: ";
        for (int i = n; i > 0; i--) {
            cout << received[i] << " ";
        }
        cout << endl;

        // Декодирование данных
        cout << "Decoded data: ";
        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) != 0) { // Пропускаем контрольные биты
                cout << received[i] << " ";
            }
        }
        cout << endl;
    }
}
