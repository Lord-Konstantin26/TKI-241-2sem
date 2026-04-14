#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <iterator>

struct less_abs : public std::function<bool(int, int)> {
    bool operator()(int a, int b) const {
        return std::abs(a) < std::abs(b);
    }

    less_abs() : std::function<bool(int, int)>(
        [this](int a, int b) { return this->operator()(a, b); }
    ) {
    }
};

void printVector(const std::vector<int>& V, const std::string& message) {
    std::cout << message << ": ";
    for (int num : V) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> V;
    
    std::cout << "Введите целые числа (Ctrl+D/Ctrl+Z для окончания ввода): ";
    
    // Считываем все числа из потока ввода до конца
    std::copy(std::istream_iterator<int>(std::cin),
              std::istream_iterator<int>(),
              std::back_inserter(V));
    
    if (V.empty()) {
        std::cout << "Ошибка: не введено ни одного числа!" << std::endl;
        return 1;
    }
    
    printVector(V, "Исходный вектор");
    
    less_abs cmp;
    std::sort(V.begin(), V.end(), cmp);
    
    printVector(V, "Отсортированный вектор (по |a| < |b|)");
    
    // Вывод абсолютных значений
    std::cout << "Абсолютные значения: ";
    for (int num : V) {
        std::cout << std::abs(num) << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
