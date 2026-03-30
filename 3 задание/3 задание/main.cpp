#include <iostream>
#include <vector>
#include <map>

int main() {
    // Исходный вектор
    std::vector<int> V = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9 };

    // Вспомогательное отображение M
    std::map<int, int> M;

    // Заполнение отображения M без использования условных конструкций
    for (auto it = V.begin(); it != V.end(); ++it) {
        M[*it]++;  
    }

    // Вывод результатов в порядке возрастания значений элементов
    std::cout << "Результат (элемент : количество повторений):" << std::endl;
    for (auto it = M.begin(); it != M.end(); ++it) {
        std::cout << it->first << " : " << it->second << std::endl;
    }

    return 0;
}