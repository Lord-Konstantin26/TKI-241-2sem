#include <iostream>
#include <deque>

int main() {
    std::deque<int> D;
    int N;

    std::cout << "Enter number of elements (even): ";
    std::cin >> N;

    if (N % 2 != 0) {
        std::cout << "Number of elements must be even!" << std::endl;
        return 1;
    }

    std::cout << "Enter " << N << " elements: ";
    for (int i = 0; i < N; ++i) {
        int value;
        std::cin >> value;
        D.push_back(value);
    }

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