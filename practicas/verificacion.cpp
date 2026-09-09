#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> numeros{5, 1, 4, 2, 3};

    std::sort(numeros.begin(), numeros.end());

    int suma = std::accumulate(numeros.begin(), numeros.end(), 0);

    for (int numero : numeros) {
        std::cout << numero << ' ';
    }

    std::cout << "\nSuma: " << suma << '\n';

    return 0;
}
