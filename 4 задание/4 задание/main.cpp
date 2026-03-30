#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>

struct less_abs : public std::function<bool(int, int)> {
    bool operator()(int a, int b) const {
        return std::abs(a) < std::abs(b);
    }

    less_abs() : std::function<bool(int, int)>(
        [this](int a, int b) { return this->operator()(a, b); }
    ) {
    }
};

int main() {
    std::vector<int> V;
    int n, num;

    std::cout << "Введите количество элементов: ";
    std::cin >> n;

    std::cout << "Введите " << n << " целых чисел: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> num;
        V.push_back(num);
    }

    std::cout << "\nИсходный вектор: ";
    for (int num : V) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    less_abs cmp;

    std::sort(V.begin(), V.end(), cmp);

    std::cout << "Отсортированный вектор (по |a| < |b|): ";
    for (int num : V) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Абсолютные значения: ";
    for (int num : V) {
        std::cout << std::abs(num) << " ";
    }
    std::cout << std::endl;

    return 0;
}