/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Buscas.h
 * Author: snoopy
 *
 
 */

#include <vector>

#include "Estrutura.h"
#include "ConjuntoDePossibilidades.h"
#include <time.h>
#ifndef BUSCAS_H
#define BUSCAS_H
using namespace std;


struct CompareOrdenada
{
  bool operator()( Estrutura* lhs, Estrutura* rhs) 
  {
    return lhs->getCusto() > rhs->getCusto();
  }
};/*Estrutura para ordenar os sorts de dijkstra*/

struct CompareGulosa
{
  bool operator()( Estrutura* lhs, Estrutura* rhs) 
  {
    return lhs->getHeuristica() > rhs->getHeuristica();
  }
};


struct CompareAEstrela
{
  bool operator()( Estrutura* lhs, Estrutura* rhs) 
  {
    return (lhs->getHeuristica() + lhs->getCusto()) > (rhs->getHeuristica() + rhs->getCusto()) ;
  }
};

struct info{
    unsigned totalNosExpandidos;
    unsigned totalNosVisitados;
    unsigned profundidade;
    unsigned custoSolucao;
    double valorMedioRamArv;
    double tempoDecorrido;
};


class Buscas {
    Estrutura* inicio;
    Estrutura* fim;
    ConjuntoDePossibilidades* todasPossibilidades;
    info infoBusca;
    
public:
    Buscas(Estrutura *inicio, Estrutura *fim);
    ~Buscas();
    int profundidade();
    bool encontrouSolucao(Estrutura* e);
    vector<Estrutura*>* geraFilhos(Estrutura* e);
    ConjuntoDePossibilidades* getConjPossibilidades();
    Estrutura* getEstrutura(string chave);
    int largura();
    int backtrack();
    int ordenada();
    int gulosa();
    int AEstrela();
    int idaEstrela();
    unsigned distManhattan(Estrutura* e);
     void printSolucao(Estrutura* e);
private:
    void insereEstChave(Estrutura* filho);
    
    void imprimeArray(char* a, int tam);
    int auxBackTrack(string chave );
    bool ordemOrdenada(const string& i,const string& j);
    unsigned idaEstrelaAux(string, unsigned limiteCusto);
    
};

#endif /* BUSCAS_H */

