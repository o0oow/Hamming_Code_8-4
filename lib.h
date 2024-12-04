#ifndef LIB_H
#define LIB_H

#include <vector>

// Функция для вычисления контрольного бита
int check_parity(int n, int i, const std::vector<int>& code);

// Основная функция для работы с кодом Хэмминга
void hamming_code(const std::vector<int>& data);

#endif
