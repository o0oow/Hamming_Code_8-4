#include "lib.h"
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Функция для проверки четности группы бит
int check_parity(int n, int i, const vector<int>& code) {
    int p = 0, k;
    for (int j = i; j <= n; j = k + i) {
        for (k = j; k < j + i && k <= n; k++) {
            if (code[k] == 1) {
                p++;
            }
        }
    }
    return (p % 2 == 0) ? 0 : 1; // Возвращает 0 для четного, 1 для нечетного
}

// Основная функция для кодирования, проверки и исправления ошибок
void hamming_code(const vector<int>& data) {
    const int num = 4; // Количество информационных битов фиксировано
    const int r = 3;   // Количество контрольных битов для длины 4
    const int n = num + r; // Общий размер данных

    // Подготовка массива с контрольными битами
    vector<int> code(n + 1, 0);
    int j = 0;

    // Распределение информационных битов
    for (int i = 1; i <= n; i++) {
        if ((i & (i - 1)) != 0) { // Проверка, что позиция не является степенью двойки
            code[i] = data[j++];
        }
    }

    // Вычисление контрольных битов
    for (int i = 1; i <= n; i <<= 1) { // Позиции 1, 2, 4
        code[i] = check_parity(n, i, code);
    }

    // Вывод закодированного сообщения
    cout << "Encoded Hamming Code: ";
    for (int i = n; i > 0; i--) {
        cout << code[i] << " ";
    }
    cout << endl;

    // Ввод принятого кода
    cout << "Enter the received code (7 bits): ";
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

    // Исправление ошибки
    if (error_position == 0) {
        cout << "Received code is correct!" << endl;
    } else {
        // Исправляем единственную ошибку
        cout << "Error detected at position: " << error_position << endl;
        received[error_position] ^= 1; // Инвертируем бит
        cout << "Corrected code: ";
        for (int i = n; i > 0; i--) {
            cout << received[i] << " ";
        }
        cout << endl;

        // Декодирование данных (извлечение только информационных битов)
        cout << "Decoded data: ";
        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) != 0) { // Пропускаем контрольные биты
                cout << received[i] << " ";
            }
        }
        cout << endl;
    }
}
