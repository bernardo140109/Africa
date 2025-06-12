#include <iostream>
#include <string>
#include <vector>

// Cores ANSI inspiradas na África
const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string YELLOW = "\033[33m";
const std::string GREEN = "\033[32m";
const std::string ORANGE = "\033[38;5;208m"; // laranja (extended color)

void printColoredBox(
    const std::vector<std::string>& curiosidades, 
    const std::vector<std::string>& resumo,
    int boxWidth = 40,
    int boxHeight = 10)
{
    // Imprime topo da caixa
    std::cout << ORANGE << "+" << std::string(boxWidth - 2, '-') << "+" << RESET;

    // Espaço para as duas colunas lado a lado
    int resumoWidth = 40;

    std::cout << "  "; // separação entre as caixas

    std::cout << GREEN << "+" << std::string(resumoWidth - 2, '-') << "+" << RESET << "\n";

    for (int i = 0; i < boxHeight; i++) {
        // Linha da curiosidade
        std::cout << ORANGE << "|" << RESET;

        if (i < (int)curiosidades.size()) {
            std::string line = curiosidades[i];
            if ((int)line.size() > boxWidth - 2) {
                line = line.substr(0, boxWidth - 5) + "...";
            }
            std::cout << RED << line;
            // Preencher espaço restante com espaços
            std::cout << std::string(boxWidth - 2 - line.size(), ' ');
        } else {
            std::cout << std::string(boxWidth - 2, ' ');
        }

        std::cout << ORANGE << "|" << RESET;

        std::cout << "  "; // separação

        // Linha do resumo
        std::cout << GREEN << "|" << RESET;

        if (i < (int)resumo.size()) {
            std::string line = resumo[i];
            if ((int)line.size() > resumoWidth - 2) {
                line = line.substr(0, resumoWidth - 5) + "...";
            }
            std::cout << YELLOW << line;
            std::cout << std::string(resumoWidth - 2 - line.size(), ' ');
        } else {
            std::cout << std::string(resumoWidth - 2, ' ');
        }

        std::cout << GREEN << "|" << RESET << "\n";
    }

    // Rodapé
    std::cout << ORANGE << "+" << std::string(boxWidth - 2, '-') << "+" << RESET;
    std::cout << "  ";
    std::cout << GREEN << "+" << std::string(resumoWidth - 2, '-') << "+" << RESET << "\n";
}

int main() {
    std::vector<std::string> curiosidades = {
        "Africa tem mais de 50 paises.",
        "O Deserto do Sahara e enorme.",
        "Berco da humanidade, com os primeiros homos.",
        "Rio Nilo e o mais longo do mundo.",
        "Miles de linguas sao faladas aqui."
    };

    std::vector<std::string> resumo = {
        "Este quadro mostra fatos interessantes sobre",
        "a diversidade, historia e geografia da Africa.",
        "Pode ser usado para estudos ou para enriquecer",
        "qualquer texto ou apresentacao relacionada ao tema.",
        "Explore e descubra mais curiosidades!"
    };

    printColoredBox(curiosidades, resumo);

    return 0;
}
