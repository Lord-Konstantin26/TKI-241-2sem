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
    
    int N = D.size();
    auto i = D.begin();
    std::advance(i, N / 2);
    
    for (int k = 0; k < N / 2; ++k) {
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
