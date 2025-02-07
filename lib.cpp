#include "lib.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int check_parity(int n, int i, const vector<int>& code) {
    int p = 0, k;
    for (int j = i; j <= n; j = k + i) {
        for (k = j; k < j + i && k <= n; k++) {
            if (code[k] == 1) {
                p++;
            }
        }
    }
    return (p % 2 == 0) ? 0 : 1; 
}

// Основная функция кодирования, проверки и исправления
void hamming_code(const vector<int>& data) {
    const int num = 4; 
    const int r = 4;  
    const int n = num + r; 

    
    vector<int> code(n + 1, 0);
    int j = 0;

    for (int i = 1; i <= n; i++) {
        if ((i & (i - 1)) != 0) {
            code[i] = data[j++];
        }
    }

    for (int i = 1; i <= n; i <<= 1) { // Позиции 1, 2, 4, 8
        code[i] = check_parity(n, i, code);
    }

    cout << "Encoded Hamming Code: ";
    for (int i = n; i > 0; i--) {
        cout << code[i] << " ";
    }
    cout << endl;

    cout << "Enter the received code (8 bits): ";
    vector<int> received(n + 1);
    for (int i = n; i > 0; i--) {
        cin >> received[i];
    }

    int error_position = 0;
    for (int i = 1; i <= n; i <<= 1) { // Позиции контрольных bits
        if (check_parity(n, i, received) != 0) {
            error_position += i;
        }
    }

    if (error_position == 0) {
        cout << "Received code is correct!" << endl;

        cout << "Decoded data: ";
        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) != 0) {
                cout << received[i] << " ";
            }
        }
        cout << endl;

    } else if (error_position > n) {
        cout << "Too many errors detected! Unable to correct." << endl;
    } else {
        cout << "Error detected at position: " << error_position << endl;

        received[error_position] ^= 1;

        cout << "Corrected code: ";
        for (int i = n; i > 0; i--) {
            cout << received[i] << " ";
        }
        cout << endl;

        cout << "Decoded data: ";
        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) != 0) { 
                cout << received[i] << " ";
            }
        }
        cout << endl;
    }
}
