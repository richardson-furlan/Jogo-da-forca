#include <iostream>
#include "chuta.hpp"
#include "letra_existe.hpp"

namespace Forca {
    void chuta(std::map<char, bool>& chutou, std::vector<char>& chutes_errados, std::string& palavra_secreta)
    {
        std::cout << "Seu chute: ";
        char chute;
        std::cin >> chute;

        chutou[chute] = true;

        if (letra_existe(chute, palavra_secreta)) {
            std::cout << "Você acertou! Seu chute esta na palavra." << std::endl;
        }
        else {
            std::cout << "Você errou! Seu chute nao esta na palavra." << std::endl;
            chutes_errados.push_back(chute);
        }
        std::cout << std::endl;
    }
}