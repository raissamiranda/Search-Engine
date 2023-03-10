#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

#include "Escalonador.hpp"
#include "FilaHost.hpp"
#include "Host.hpp"
#include "ListaURL.hpp"
#include "URL.hpp"

int main(int argc, char *argv[]) {

  // Variavel para armazenar o nome do arquivo obtido na linha de comando
  char *nome_arquivo = argv[1];
  std::string nome_arquivo_str(nome_arquivo);

  // Verifica se o arquivo eh .txt
  bool arquivo_valido = nome_arquivo_str.find(".txt");
  if (!arquivo_valido) {
    std::cout << "Arquivo com formato inadequado" << std::endl;
    return 1;
  }

  // Formatando o nome do arquivo de saida
  std::string aux = nome_arquivo_str;
  aux.erase(aux.find(".txt"), 4);
  std::string final = ("-out.txt");
  std::string nome_arquivo_saida = aux + final;

  // Abrindo arquivos para leitura e saida
  std::ifstream arquivo(nome_arquivo_str);
  if (arquivo.fail()) {
    std::cout << "Erro ao abrir arquivo!" << std::endl;
    return 1;
  }

  std::ofstream arquivo_saida(nome_arquivo_saida);
  if (arquivo_saida.fail()) {
    std::cout << "Erro ao abrir arquivo!" << std::endl;
    return 1;
  }

  // Criacao do escalonador que sera utilizado
  Escalonador *esc = new Escalonador();

  // Redireciona o cout para o arquivo de saida
  std::streambuf *coutbuf = std::cout.rdbuf();
  std::cout.rdbuf(arquivo_saida.rdbuf());

  // Percorre o arquivo e realiza as operacoes
  std::string string_lida, nome_host;
  int quant;

  while (arquivo >> string_lida) {
    // arquivo >> string_lida;

    // Comando: ADD_URLS <quantidade>
    if (string_lida == "ADD_URLS") {
      arquivo >> quant;
      for (int i = 0; i < quant; i++) {
        arquivo >> string_lida;
        URL *u = new URL(string_lida);
        esc->ADD_URL(u);
      }
    }

    // Comando: ESCALONA_TUDO
    else if (string_lida == "ESCALONA_TUDO") {
      esc->ESCALONA_TUDO();
    }

    // Comando: ESCALONA
    else if (string_lida == "ESCALONA") {
      arquivo >> quant;
      esc->ESCALONA(quant);
    }

    // Comando: ESCALONA_HOST
    else if (string_lida == "ESCALONA_HOST") {
      arquivo >> nome_host;
      arquivo >> quant;
      esc->ESCALONA_HOST(nome_host, quant);
    }

    // Comando: VER_HOST
    else if (string_lida == "VER_HOST") {
      arquivo >> nome_host;
      esc->VER_HOST(nome_host);
    }

    // Comando: LISTA_HOST
    else if (string_lida == "LISTA_HOSTS") {
      esc->LISTA_HOSTS();
    }

    // Comando: LIMPA_HOST
    else if (string_lida == "LIMPA_HOST") {
      arquivo >> nome_host;
      esc->LIMPA_HOST(nome_host);
    }

    // Comando: LIMPA_TUDO
    else if (string_lida == "LIMPA_TUDO") {
      esc->LIMPA_TUDO();
    } else {
      arquivo.close();
      std::cout.rdbuf(coutbuf);
      return 1;
    }
  }

  arquivo.close();

  // Devolve o controle do cout para o terminal
  std::cout.rdbuf(coutbuf);
  return 0;
}