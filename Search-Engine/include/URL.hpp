#include <iostream>
#include <string>

#ifndef URL_H
#define URL_H

/* Esta eh a interface de qualquer URL.
 *  O que caracteriza uma URL eh a seu nome e o ponteiro para a proxima URL
 */
class URL {

private:
  // String com o nome da URL
  std::string nome_url;

  // Ponteiro para a proxima URL da lista
  URL *next_url;

  // Numero de / na URL
  int profundidade;

  // Metodo de verificacao do protocolo http
  bool URL_certa(std::string s);

public:
  // Métodos construtores
  URL(std::string nome);
  URL(std::string nome, URL *next, int profundidade);

  // Método destrutor
  ~URL();

  // Retorna o nome da URL
  std::string GetNome();

  // Retorna o ponteiro next_url
  URL *GetNextURL();

  // Retorna a profundidade da url
  int GetProfundidade();

  // Seta o ponteiro next
  void SetNext(URL *u);

  // Verifica se a URL criada eh valida
  bool URL_valida();

  // Formata a URL de acordo com as especificacoes
  void FormataURL();

  // Formata pra Host
  // Retorna uma string com a copia da url formatada e tbm sem o http
  std::string FormataPraHost();

  bool operator==(const URL &rhs) const;

  // Calcula o numero de / em uma URL
  int CalculaProfundidade();

  // Operador que compara o tamanho de duas URLs, ou seja, o numero de
  // caminhos (barras) que elas tem
  bool operator<(URL &u);

  // Imprime o nome da URL
  void ImprimeURL();
};

#endif