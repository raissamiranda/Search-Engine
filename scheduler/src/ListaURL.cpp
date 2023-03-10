#include "ListaURL.hpp"
#include "URL.hpp"
#include <iostream>

// Construtores de ListaURL
ListaURL::ListaURL(URL *u) {
  if (!u->URL_valida()) {
    primeiro = nullptr;
    ultimo = nullptr;
  } else {
    primeiro = u;
    ultimo = primeiro;
  }
}

ListaURL::ListaURL() {
  primeiro = nullptr;
  ultimo = nullptr;
}

// Destrutor de ListaURL
ListaURL::~ListaURL() { EsvaziaLista(); }

// Remove todas as URLs da lista
void ListaURL::EsvaziaLista() {
  URL *p = primeiro;
  while (p != nullptr) {
    URL *q = p->GetNextURL();
    delete p;
    primeiro = q;
    p = q;
  }
  ultimo = nullptr;
}

// Get do primeiro ponteiro
URL *ListaURL::GetPrimeiro() { return primeiro; }

// Get do ultimo ponteiro
URL *ListaURL::GetUltimo() { return ultimo; }

// Seta o primeiro ponteiro
void ListaURL::SetPrimeiro(URL *u) { primeiro = u; }

// Seta o ultimo ponteiro
void ListaURL::SetUltimo(URL *u) { ultimo = u; }

// Verifica se a lista esta vazia, se sim, retorna true
bool ListaURL::EstaVazia() {
  return (primeiro == nullptr && ultimo == nullptr);
}

// Imprime todas as URLs da lista
void ListaURL::ImprimeListaURL() {
  if (!EstaVazia()) {
    URL *p = GetPrimeiro();
    while (p != nullptr) {
      p->ImprimeURL();
      p = p->GetNextURL();
    }
  }
}

// Imprime cada URL e em seguida a remove da lista
void ListaURL::Escalona() {
  URL *p = GetPrimeiro();
  while (p != nullptr) {
    p->ImprimeURL();
    URL *q = p->GetNextURL();
    delete p;
    p = nullptr;
    primeiro = q;
    p = q;
  }
  ultimo = nullptr;
}

// Calcula o numero de URLs que a lista possui
int ListaURL::TamanhoLista() {
  int contador = 0;
  URL *p = GetPrimeiro();

  if (EstaVazia()) {
    return 0;
  } else {
    while (p != nullptr) {
      contador++;
      p = p->GetNextURL();
    }
    return contador;
  }
}
