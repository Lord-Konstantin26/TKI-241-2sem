#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>

int main() {
    std::vector<int> V;
    std::map<int, int> M;
    
    std::cout << "Enter elements (Ctrl+D/Ctrl+Z to end): ";
    
    // Считываем все числа из потока ввода до конца
    std::copy(std::istream_iterator<int>(std::cin),
              std::istream_iterator<int>(),
              std::back_inserter(V));
    
    if (V.empty()) {
        std::cout << "No elements entered!" << std::endl;
        return 1;
    }
    
    // Заполнение отображения M без использования условных конструкций
    for (auto it = V.begin(); it != V.end(); ++it) {
        M[*it]++;  
    }
    
    // Вывод результатов в порядке возрастания значений элементов
    std::cout << "\nResult (element : count):" << std::endl;
    for (auto it = M.begin(); it != M.end(); ++it) {
        std::cout << it->first << " : " << it->second << std::endl;
    }
    
    return 0;
}
