#include "URL.hpp"
#include <iostream>

#ifndef LISTAURL_H
#define LISTAURL_H

/* Esta eh a interface de uma Lista de URLs
 *  O que caracteriza uma lista de URLs eh o primeiro e o ultimo elemento dela
 */
class ListaURL {

private:
  // Ponteiro para o primeiro elemento da lista
  URL *primeiro;

  // Ponteiro para o ultimo elemento da lista
  URL *ultimo;

public:
  // Metodo construtor de uma ListaURL
  ListaURL(URL *u);
  ListaURL();

  // Metodo destrutor de uma ListaURL
  ~ListaURL();

  // Retorna o primeiro ponteiro
  URL *GetPrimeiro();

  // Retorna o primeiro ponteiro
  URL *GetUltimo();

  // Seta o ponteiro primeiro
  void SetPrimeiro(URL *u);

  // Seta o ponteiro ultimo
  void SetUltimo(URL *u);

  // Testa se a lista esta vazia
  bool EstaVazia();

  // Apaga todas as URLs da lista
  void EsvaziaLista();

  // Printa todas as URLS da lista
  void ImprimeListaURL();

  // Imprime cada URL e em seguida a remove
  void Escalona();

  // Retorna o numero de URLs que a lista possui
  int TamanhoLista();
};

#endif