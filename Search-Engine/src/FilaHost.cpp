#include "FilaHost.hpp"
#include "Host.hpp"
#include "ListaURL.hpp"
#include "URL.hpp"
#include <iostream>

// Construtor de uma fila vazia
FilaHost::FilaHost() {
  frente = nullptr;
  tras = nullptr;
}

// Destrutor de uma fila de hosts
FilaHost::~FilaHost() {
  Host *p = frente;
  while (p != nullptr) {
    Host *q = p->GetNext();
    delete p;
    frente = q;
    p = q;
  }
  tras = nullptr;
}

// Get do ponteiro da frente
Host *FilaHost::GetFrente() { return frente; }

// Get do ponteiro de tras
Host *FilaHost::GetTras() { return tras; }

// Seta o ponteiro da frente
void FilaHost::SetFrente(Host *h) { frente = h; }

// Seta o ponteiro de tras
void FilaHost::SetTras(Host *h) { tras = h; }

// Retorna true se a lista estiver vazia
bool FilaHost::FilaVazia() { return (frente == nullptr && tras == nullptr); }

// Adiciona um host na fila
void FilaHost::EnfileiraHost(Host *h) {
  /*  Para filas nao vazias (testado na main antes):
   *  - O ultimo elemento tera seu next apontando para o host q sera
   * adicionado
   *  - O ponteiro tras sera atualizado para o host que foi adicionado
   */
  if (FilaVazia()) {
    frente = h;
    tras = h;
  } else {
    tras->SetNext(h);
    h->SetNext(nullptr);
    tras = h;
  }
}

// Imprime o nome de todos os hosts na ordem em que foi conhecido
void FilaHost::ImprimeFilaHost() {
  Host *p = GetFrente();
  while (p != nullptr) {
    p->ImprimeHost();
    p = p->GetNext();
  }
}
