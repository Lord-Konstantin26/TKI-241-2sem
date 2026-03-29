#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <string>

int main() {
    std::string name;
    int N;

    std::cout << "Введите имя файла: ";
    std::cin >> name;
    std::cout << "Введите N (1-26): ";
    std::cin >> N;

    if (N < 1 || N > 26) {
        std::cerr << "Ошибка: N должно быть в диапазоне от 1 до 26" << std::endl;
        return 1;
    }

    std::ofstream outputFile(name);

    if (!outputFile.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл " << name << std::endl;
        return 1;
    }

    std::ostream_iterator<char> fileIterator(outputFile, "");

    char currentChar = 'A';
    std::generate_n(fileIterator, N, [&currentChar]() {
        return currentChar++;
        });

    outputFile.close();
    std::cout << "Успешно записано " << N << " букв в файл " << name << std::endl;

    return 0;
}