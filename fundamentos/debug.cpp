#include <iostream>
#include <vector>

int main() {
    std::vector<int> numeros{10, 20, 30};

    int suma = 0;

    for (int numero : numeros) {
        suma += numero;
    }

    std::cout << suma << '\n';

    return 0;
}