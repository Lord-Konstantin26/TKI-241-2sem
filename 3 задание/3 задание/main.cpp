#include <iostream>
#include <vector>
#include <map>

int main() {
    std::vector<int> V;
    std::map<int, int> M;
    int N;
    
    std::cout << "Enter number of elements: ";
    std::cin >> N;
    
    std::cout << "Enter " << N << " elements: ";
    for (int i = 0; i < N; ++i) {
        int value;
        std::cin >> value;
        V.push_back(value);
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
