#include "Host.hpp"
#include "ListaURL.hpp"
#include <iostream>

// Construtores de um Host
Host::Host(std::string nome) {
  // Cria uma url sem www. / no final e fragmentos
  URL *nova_url = new URL(nome);
  nova_url->FormataURL();

  // Formata a url novamente para apenas o nome do host e armazena numa string
  std::string formato_host = nova_url->FormataPraHost();

  // Atribui o nome do host ao nome formatado corretamente
  nome_host = formato_host;

  // Adiciona a url na lista dele, se for valida
  lista_de_urls = new ListaURL(nova_url);

  // Atribui nullptr ao ponteiro next_host
  next_host = nullptr;
}

// Destrutor de um Host
Host::~Host() { delete lista_de_urls; }

// Operador == de Host
bool Host::operator==(Host &h) { return (nome_host == h.nome_host); }

// Compara se os ponteiros apontam para o mesmo objeto
bool host_points_to_equal_object(Host *a, Host *b) {
  if (a == nullptr || b == nullptr) {
    return false;
  }
  return (*a == *b);
}

// Retorna o nome do host
std::string Host::GetNome() { return nome_host; }

// Retorna o ponteiro next
Host *Host::GetNext() { return next_host; }

// Retorna o ponteiro pra lista
ListaURL *Host::GetPonteiroPraLista() { return lista_de_urls; }

// Seta o ponteiro da lista de urls do host
void Host::SetPonteiroPraLista(ListaURL *u) { lista_de_urls = u; }

// Seta o ponteiro nex
void Host::SetNext(Host *h) { next_host = h; }

void Host::InsereURL(URL *u) {
  /* - A lista de urls de um host nunca esta vazia, pois o construtor de host
   * ja coloca uma url na lista, por isso nao precisa verificar se esta vazia
   *
   *  - O metodo deve percorrer a lista comparando a profundidade da url que
   * sera adicionada e a das urls da lista
   *  - o ponteiro de_tras sempre ficara uma posicao atras que o ponteiro p
   */
  if (u == nullptr) {
    return;
  }

  if (!u->URL_valida()) {
    return;
  }

  URL *p = lista_de_urls->GetPrimeiro();
  URL *de_tras = lista_de_urls->GetPrimeiro();
  bool primeiro_elemento = true;
  while (p != nullptr) {
    // Nao permite adicionar URLs replicadas
    if (p->GetNome() == u->GetNome()) {
      break;
    }

    // Se a URL deve ser adicionada na primeira posicao, atualizar o
    // ponteiro primeiro
    if (*u < *p && primeiro_elemento) {
      lista_de_urls->SetPrimeiro(u);
      u->SetNext(p);
      break;
    }

    /* Se a URL nao sera adicionada na primeira posicao:
     *  - o ponteiro de_tras que esta na posicao anterior a p deve apontar
     * pra nova url
     *  - a nova url deve apontar para p
     */
    if (*u < *p && !primeiro_elemento) {
      de_tras->SetNext(u);
      u->SetNext(p);
      break;
    }
    primeiro_elemento = false;
    de_tras = p;
    p = p->GetNextURL();
  }
  /* Se percorreu a lista toda e nao foi menor que nenhum, eh porque ele eh
   * maior que todos Entao deve-se colocar ele na ultima posicao E atualizar o
   * ponteiro ultimo
   */
  if (p == nullptr) {
    de_tras->SetNext(u);
    lista_de_urls->SetUltimo(u);
  }
}

// Remove todas as URLs da ListaUrl
void Host::RemoveTodasURLS() { lista_de_urls->EsvaziaLista(); }

// Imprime o nome do Host
void Host::ImprimeHost() { std::cout << GetNome() << std::endl; }
