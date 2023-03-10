#include "Host.hpp"
#include <iostream>

#ifndef FILAHOST_H
#define FILAHOST_H

/* Esta eh a interface de qualquer fila de hosts
 *  Ela eh caracterizada por um
 */

class FilaHost {

private:
  // Ponteiro para o primeiro elemento da fila
  Host *frente;

  // Ponteiro para o ultimo elemento da fila
  Host *tras;

public:
  // Metodo construtor de FilaHost
  FilaHost();

  // Metodo destrutor de FilaHost
  ~FilaHost();

  // Retorna o ponteiro de frente
  Host *GetFrente();

  // Retorna o ponteiro de tras
  Host *GetTras();

  // Seta o ponteiro da frente
  void SetFrente(Host *h);

  // Seta o ponteiro de tras
  void SetTras(Host *h);

  // Verifica se a fila esta vazia
  bool FilaVazia();

  // Adiciona um host de nome h na fila
  void EnfileiraHost(Host *h);

  // Remove todos os Hosts da fila
  void RemoveTodosHosts();

  // Imprime o nome dos hosts presentes na fila
  void ImprimeFilaHost();
};

#endif