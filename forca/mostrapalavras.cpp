#include "mostrapalavras.hpp"

std::string mostrapalavras() {

    std::ifstream file("palavras.txt");
    if (!file.is_open()) {
        std::cout << "Erro ao abrir o arquivo." << std::endl;

        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    file.close();
}