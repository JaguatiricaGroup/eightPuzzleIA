/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   estrutura.h
 * Author: snoopy

 */
//using namespace std;

#include <string>
#ifndef ESTRUTURA_H
#define ESTRUTURA_H
using namespace std;
class Estrutura {
    char xBranco, yBranco; // x, y do branco
    char **matriz; // tabuleiro do jogo
    unsigned custo;
    bool visitado;
    unsigned heuristica;
    Estrutura* pai;
    
public:
    Estrutura();
    Estrutura(char **matriz, char xBranco, char yBranco , unsigned custo);
    ~Estrutura();
    void printEstrutura();
    void geraInstanciaAleatoria();
    Estrutura* moveEsq();
    Estrutura* moveDir();
    Estrutura* moveCima();
    Estrutura* moveBaixo();
    char** getMatriz();
    string getChave();
    bool foiVisitado();
    void setVisitado(bool visitado);
    unsigned getCusto();
    void setCusto(unsigned custo );
    unsigned getHeuristica();
    void setHeuristica(unsigned heuristica);
    Estrutura* getPai();
    void setPai(Estrutura* pai);
   
    
private:
    void swapMatriz(Estrutura* filho);
    
};

#endif /* ESTRUTURA_H */
