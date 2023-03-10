#include "Escalonador.hpp"
#include "FilaHost.hpp"
#include "Host.hpp"
#include "ListaURL.hpp"
#include "URL.hpp"
#include <iostream>
#include <string>

// Construtores de Escalonador
Escalonador::Escalonador() { fila_de_hosts = new FilaHost(); }

Escalonador::~Escalonador() {
  if (fila_de_hosts != nullptr) {
    delete fila_de_hosts;
    fila_de_hosts = nullptr;
  }
}

// Metodo que adiciona uma URL no host adequado e no local adequado da sua lista
void Escalonador::ADD_URL(URL *u) {
  // Se a URL nao for valida, nao adicionar
  if (!u->URL_valida()) {
    return;
  }

  // Garante que eh possivel adicionar urls depois de limpar a fila de hosts
  if (fila_de_hosts == nullptr) {
    fila_de_hosts = new FilaHost();
  }

  // Formata o nome da url nas especificacoes indicadas
  u->FormataURL();

  // Cria um host com o nome formatado pra host e ja adiciona u na primeira
  // URL
  Host *new_host = new Host(u->GetNome());

  // Ver se host ja existe
  bool encontrei_host = false;
  Host *p = fila_de_hosts->GetFrente();
  while (p != nullptr) {
    // Se o host já existe: colocar URL no lugar certo da lista dele e
    // Exclui o host redundante criado
    if (host_points_to_equal_object(p, new_host)) {
      p->InsereURL(u);
      encontrei_host = true;
      delete new_host;
      break;
    }
    p = p->GetNext();
  }

  // Se o host nao existe: enfileirar ele e colocar URL em sua lista
  if (!encontrei_host) {
    fila_de_hosts->EnfileiraHost(new_host);
  }
}

// Imprime a lista de URLs de cada Host.
// Quando escalonadas, as URLs sao exibidas e removidas da lista
void Escalonador::ESCALONA_TUDO() {
  if (fila_de_hosts == nullptr) {
    return;
  }
  Host *p = fila_de_hosts->GetFrente();
  while (p != nullptr) {
    if (!p->GetPonteiroPraLista()->EstaVazia()) {
      p->GetPonteiroPraLista()->Escalona();
      p->GetPonteiroPraLista()->SetPrimeiro(nullptr);
      p->GetPonteiroPraLista()->SetUltimo(nullptr);
    }
    p = p->GetNext();
  }
}

// Escalona a quantidade passada como parametro
void Escalonador::ESCALONA(int n) {
  if (fila_de_hosts == nullptr) {
    return;
  }

  // Percorre a fila de hosts
  Host *p = fila_de_hosts->GetFrente();
  if (p != nullptr) {

    URL *r;
    URL *q = p->GetPonteiroPraLista()->GetPrimeiro();

    // Escalona n vezes
    for (int i = 0; i < n; i++) {
      if (q == nullptr) {
        p = p->GetNext();
        if (p == nullptr) {
          break;
        } else {
          q = p->GetPonteiroPraLista()->GetPrimeiro();
        }
      }
      q->ImprimeURL();
      r = q->GetNextURL();
      delete q;

      q = r;

      if (r == nullptr) {
        p->GetPonteiroPraLista()->SetPrimeiro(nullptr);
        p->GetPonteiroPraLista()->SetUltimo(nullptr);
        p = p->GetNext();
        if (p == nullptr) {
          break;
        } else {
          q = p->GetPonteiroPraLista()->GetPrimeiro();
        }
      }
    }
  }
}

// Escalona n urls do host passado como parametro
void Escalonador::ESCALONA_HOST(std::string s, int n) {
  if (fila_de_hosts == nullptr) {
    return;
  }
  Host *p = fila_de_hosts->GetFrente();

  while (p != nullptr) {
    // Se achar o host na fila
    if (p->GetNome() == s) {

      // Verificar se o numero de urls dele eh menor ou igual ao numero
      // pedido pra ser escalonado
      if (p->GetPonteiroPraLista()->TamanhoLista() <= n) {
        // Se for menor, escalona todas que tiverem
        p->GetPonteiroPraLista()->Escalona();
        p->GetPonteiroPraLista()->SetPrimeiro(nullptr);
        p->GetPonteiroPraLista()->SetUltimo(nullptr);
        break;

      } else {
        // Se nao for, escalona apenas n urls
        URL *q = p->GetPonteiroPraLista()->GetPrimeiro();
        URL *r = q->GetNextURL();
        for (int i = 0; i < n; i++) {
          q->ImprimeURL();
          r = q->GetNextURL();
          delete q;
          q = r;
          p->GetPonteiroPraLista()->SetPrimeiro(r);
        }
      }
      break;
    }
    p = p->GetNext();
  }
}

// Printa as URLs do host passado como parametro
void Escalonador::VER_HOST(std::string host) {
  if (fila_de_hosts == nullptr) {
    return;
  }
  Host *p = fila_de_hosts->GetFrente();
  while (p != nullptr) {
    if (p->GetNome() == host) {
      p->GetPonteiroPraLista()->ImprimeListaURL();
      break;
    }
    p = p->GetNext();
  }
  if (p == nullptr) {
    std::cout << "Host nao encontrado para printar sua lista" << std::endl;
  }
}

// Printa todos os hosts na ordem que foi conhecido
void Escalonador::LISTA_HOSTS() {
  if (fila_de_hosts == nullptr) {
    return;
  }
  fila_de_hosts->ImprimeFilaHost();
}

// Limpa a lista de URLs do host
void Escalonador::LIMPA_HOST(std::string host) {
  if (fila_de_hosts == nullptr) {
    return;
  }
  Host *p = fila_de_hosts->GetFrente();
  while (p != nullptr) {
    if (p->GetNome() == host) {
      p->RemoveTodasURLS();
      break;
    }
    p = p->GetNext();
  }
}

// Limpa todas as URLs, inclusive os hosts
void Escalonador::LIMPA_TUDO() {
  if (fila_de_hosts == nullptr) {
    return;
  }
  Host *p = fila_de_hosts->GetFrente();
  // Remove todas as URLs de cada Host
  while (p != nullptr) {
    p->RemoveTodasURLS();
    p = p->GetNext();
  }
  delete fila_de_hosts;
  fila_de_hosts = nullptr;
}
