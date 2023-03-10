#include "URL.hpp"
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

// Sufixos de URLs invalidos
static const char *sufixos_invalidos[] = {".jpg", ".gif", ".mp3", ".avi",
                                          ".doc", ".pdf", nullptr};

/* Construtor de uma URL
 * Esse construtor vai construir uma URL com uma string vazia no campo nome
 * caso a URL recebida nao seja uma URL com a formatacao correta
 */
URL::URL(std::string nome) {
  if (URL_certa(nome)) {
    nome_url = nome;
    profundidade = CalculaProfundidade();
  } else {
    nome_url = "";
    profundidade = -1;
  }
  next_url = nullptr;
}

// Construtor de uma URL que recebe seu nome e ja um ponteiro para a proxima URL
// da lista
URL::URL(std::string nome, URL *next, int profundidade) {
  if (URL_certa(nome)) {
    nome_url = nome;
    next_url = next;
    profundidade = CalculaProfundidade();
  } else {
    nome_url = "";
    next_url = nullptr;
    profundidade = -1;
  }
}

// Operador == para URLs, que compara o nome delas
bool URL::operator==(const URL &rhs) const {
  return (nome_url == rhs.nome_url);
}

// Destrutor de uma URL
URL::~URL() {}

// Retorna o nome da URL
std::string URL::GetNome() { return nome_url; }

// Retorna o ponteiro next_url
URL *URL::GetNextURL() { return next_url; }

// Retorna a profundidade da URL
int URL::GetProfundidade() { return profundidade; }

// Seta o ponteiro next_url
void URL::SetNext(URL *u) { next_url = u; }

/* Esse metodo verifica se a URL esta na formatacao adequada, ou seja
 *  se eh um protocolo http e se possui sufixos invalidos
 */
bool URL::URL_certa(std::string nome) {
  std::string prefix_http = "http";
  bool eh_http = nome.substr(0, 4) == prefix_http;

  bool sufixo_valido = true;
  int numero_de_sufixos_invalidos =
      (sizeof(sufixos_invalidos) / sizeof(char *)) - 1;
  for (int i = 0; i < numero_de_sufixos_invalidos; i++) {
    if (nome.find(sufixos_invalidos[i]) != std::string::npos) {
      sufixo_valido = false;
      break;
    }
  }

  return (eh_http && sufixo_valido);
}

// Verifica se a URL eh valida, ou seja, se foi criada de acordo com o metodo
// URL_certa
bool URL::URL_valida() { return (nome_url != ""); }

// Formata a URL nas especificacoes dadas
void URL::FormataURL() {
  if (URL_certa(nome_url)) {
    // Retira a parte www. da url, se houver
    if (nome_url.find("www.") != std::string::npos) {
      nome_url.erase(nome_url.find("www."), 4);
    }

    // Retira a barra no final da url, se houver
    char ultimo_caracter = nome_url[nome_url.length() - 1];
    if (ultimo_caracter == '/') {
      nome_url.pop_back();
    }

    // Retira tudo apos fragmento, se houver
    int pos = 0;
    for (size_t i = 0; i < nome_url.length(); i++) {
      if (nome_url[i] == '#') {
        pos = i;
        break;
      }
    }

    if (pos != 0) {
      int tamanho_fragmento = nome_url.length() - pos;
      nome_url.erase(nome_url.find('#'), tamanho_fragmento);
    }
  }
}

/* Retorna uma string copia da URL sem o http e sem os cam
 *  Importante ser uma copia porque ela vai ser usada apenas para comparar com
 * os host ja existentes na fila A url que sera adicionada na lista tera o http,
 * por isso ela nao eh modificada
 */
std::string URL::FormataPraHost() {
  FormataURL();
  // Remove o http:// do inicio da URL
  std::string copia_string;
  copia_string = nome_url;
  size_t pos_http = copia_string.find("http://");
  if (pos_http != std::string::npos) {
    copia_string.erase(copia_string.find("http://"), 7);
  }

  // Remove os caminhos prefixados com / da URL
  int pos = 0;
  for (size_t i = 0; i < copia_string.length(); i++) {
    if (copia_string[i] == '/') {
      pos = i;
      break;
    }
  }

  if (pos != 0) {
    int tamanho_caminhos = copia_string.length() - (pos);
    copia_string.erase(copia_string.find('/'), tamanho_caminhos);
  }

  return copia_string;
}

// Calcula o numero de caminhos presentes na url
int URL::CalculaProfundidade() {
  int numero_de_caminhos = 0;
  for (size_t i = 0; i < nome_url.length() - 1; i++) {
    if (nome_url[i] == '/') {
      numero_de_caminhos++;
    }
  }

  // Retira as duas barras contidas no protocolo http://
  return numero_de_caminhos - 2;
}

// Operador < de URLs
bool URL::operator<(URL &u) { return (profundidade < u.profundidade); }

// Imprime o nome_url dessa URL
void URL::ImprimeURL() { std::cout << GetNome() << std::endl; }
