/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConjuntoDePossibilidades.h
 * Author: snoopy
 *
 */
#include <unordered_map>
#include "Estrutura.h"
#include <string>
#ifndef CONJUNTODEPOSSIBILIDADES_H
#define CONJUNTODEPOSSIBILIDADES_H
using namespace std;
class ConjuntoDePossibilidades {
    unordered_map<string, Estrutura*> *possibilidades;
    
public:
    ConjuntoDePossibilidades();
    void geraTodasPossibilidades();
    ConjuntoDePossibilidades(const ConjuntoDePossibilidades& orig);
    virtual ~ConjuntoDePossibilidades();
    bool temEstruturaNaChave(string chave);
    void colocaEstruturaChave(string chave, Estrutura* e);
    Estrutura* getEstrutura(string chave);
private:
    void printPermutation(int n);
    void inserePossibilidade(int *a, int tam);
};

#endif /* CONJUNTODEPOSSIBILIDADES_H */

