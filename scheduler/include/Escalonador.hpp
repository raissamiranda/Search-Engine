#include "FilaHost.hpp"
#include "Host.hpp"
#include "ListaURL.hpp"
#include "URL.hpp"
#include <iostream>

#ifndef ESCALONADOR_H
#define ESCALONADOR_H

/* Esta eh a interface de um escalonador
 *  Ele eh caracterizado por uma fila de hosts
 */
class Escalonador {

private:
  // Fila de hosts
  FilaHost *fila_de_hosts;

public:
  // Metodo construtor do Escalonador
  Escalonador();

  // Metodo destrutor do Escalonador
  ~Escalonador();

  /* Adiciona uma URL no escalonador
   *  -Se preciso, cria um host antes de adicionar a url nele
   */
  void ADD_URL(URL *u);

  // Exibe um host e todas suas URLS, proximo host e todas suas URLS
  // Sempre que exibidas, sao removidas da lista tambem
  void ESCALONA_TUDO();

  /* Limita a quantidade escalonada
   * - ver se a quantidade n é maior que o numero de urls
   * - caso possivel escalona as n ou quantas tiverem(se tiver menos que n)
   */
  void ESCALONA(int n);

  // Sao escalonadas apenas n URLS desse host especificado
  void ESCALONA_HOST(std::string s, int n);

  // Procura o host na fila e printa todas as URLs dele
  void VER_HOST(std::string host);

  // Printa todos os hosts na ordem que foram conhecidos
  void LISTA_HOSTS();

  // Limpa a lista de URLs desse host
  void LIMPA_HOST(std::string host);

  // Remove todas as urls dos hosts, depois remove todos os hosts
  void LIMPA_TUDO();
};

#endif