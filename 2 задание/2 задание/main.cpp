#include <iostream>
#include <deque>
#include <iterator>

int main() {
    std::deque<int> D;
    
    std::cout << "Enter elements (even number of elements): ";
    
    // Читаем все числа из потока ввода до конца
    std::copy(std::istream_iterator<int>(std::cin),
              std::istream_iterator<int>(),
              std::back_inserter(D));
    
    // Проверяем, что количество элементов четное
    if (D.size() % 2 != 0) {
        std::cout << "Number of elements must be even!" << std::endl;
        return 1;
    }
    
    if (D.empty()) {
        std::cout << "No elements entered!" << std::endl;
        return 1;
    }
    
    size_t n = D.size();  // теперь маленькая n
    auto i = D.begin();
    std::advance(i, n / 2);
    
    for (size_t k = 0; k < n / 2; ++k) {  // здесь тоже n
        i = D.insert(i, -1);
        ++i;
        ++i;
    }
    
    std::cout << "Resulting deque: ";
    for (int val : D) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
