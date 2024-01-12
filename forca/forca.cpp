#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "imprime_cabecalho.hpp"
#include "le_arquivo.hpp"
#include "sorteia_palavra.hpp"
#include "chuta.hpp"
#include "imprime_erros.hpp"
#include "imprime_palavra.hpp"
#include "chuta.hpp"
#include "adiciona_palavra.hpp"
#include "nao_acertou.hpp"
#include <fstream>


using namespace std;

static string palavra_secreta;
static map<char, bool> chutou;
static vector<char> chutes_errados;

int main()
{   
    using namespace Forca;
    imprime_cabecalho();

    palavra_secreta = sorteia_palavra();

    while(nao_acertou(palavra_secreta, chutou) && chutes_errados.size() < 5) {
        imprime_erros(chutes_errados);

        imprime_palavra(palavra_secreta, chutou);

        chuta(chutou, chutes_errados, palavra_secreta);
    }

    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era: " << palavra_secreta << endl;

    if(nao_acertou(palavra_secreta, chutou)){
        cout << "Voce perdeu! Tente novamente!" << endl;
    }
    else{
        cout << "Parabens! Voce acertou a palavra secreta!" << endl;

        ifstream file("palavras.txt");
        if (!file.is_open()) {
            cout << "Erro ao abrir o arquivo." << endl;
                return 1;
            }

        string line;
        while (getline(file, line)) {
        cout << line << endl;
        }

        file.close();
        
        cout << "Voce deseja adicionar uma nova palavra ao banco? (S/N) ";
        char resposta;
        cin >> resposta;

        if(resposta == 'S'){
            adiciona_palavra();
        }
    }

    cin.get();
}