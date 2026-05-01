int main() {
    std::vector<int> V;
    
    std::cout << "Введите целые числа (Ctrl+D/Ctrl+Z для окончания ввода): ";
    
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
    
    // Создаем вектор абсолютных значений
    std::vector<int> absV;
    absV.reserve(V.size());
    for (int num : V) {
        absV.push_back(std::abs(num));
    }
    printVector(absV, "Абсолютные значения");
    
    return 0;
}
