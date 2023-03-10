#include "ListaURL.hpp"
#include "URL.hpp"
#include <iostream>
#include <string>

#ifndef HOST_H
#define HOST_H

/* Esta eh a interface de qualquer Host
 *  O que caracteriza um Host eh seu nome, o ponteiro para o proximo Host e uma
 * lista de URLs que ele pertence
 */
class Host {

private:
  // String com o nome do host
  std::string nome_host;

  // Ponteiro para o proximo host
  Host *next_host;

  // Lista de URLs desse host
  ListaURL *lista_de_urls;

public:
  // Método construtor
  Host(std::string nome);

  // Método destrutor
  ~Host();

  // Retorna a string com o nome do host
  std::string GetNome();

  // Retorna o ponteiro next do host
  Host *GetNext();

  // Retorna o ponteiro que aponta pra lista de URLs
  ListaURL *GetPonteiroPraLista();

  // Seta o ponteiro que aponta pra lista de URLs
  void SetPonteiroPraLista(ListaURL *u);

  // Seta o ponteiro next do host
  void SetNext(Host *h);

  // Operador que verifica se dois hosts sao iguais
  bool operator==(Host &h);

  // Insere uma URL na lista de URLs desse host ja no lugar adequado
  void InsereURL(URL *u);

  // Remove todas as URLS da lista desse Host
  void RemoveTodasURLS();

  // Imprime o nome do Host
  void ImprimeHost();
};

// Verifica se dois ponteiros estão apontando para o mesmo host
bool host_points_to_equal_object(Host *a, Host *b);

#endif