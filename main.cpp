/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: snoopy
 *
 */

#include <cstdlib>
#include "Estrutura.h"
#include "ConjuntoDePossibilidades.h"
#include "Buscas.h"
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    cout << "amada linda" << endl;
    //jogo do teste prof e largura
//    char inicio[3][3] = {{1,2,3},{0,7,5},{4,6,8}};
//    char fim[3][3] = {{1,2,3},{4,0,5},{6,7,8}};
    
//    char inicio[3][3] = {{8,1,3},{2,4,5},{0,7,6}};
//    char fim[3][3] = {{1,2,3},{8,0,4},{7,6,5}};
    //jogo do  teste backtracking
    char inicio[3][3] = {{2,8,3},{1,6,4},{7,0,5}};
    char fim[3][3] = {{2,8,3},{6,0,4},{1,7,5}};
    
    char **inicioDinamico = new char*[3];
    char **fimDinamico = new char*[3];
    for(int i =0; i<3; i++){
        inicioDinamico[i] = new char[3];
        fimDinamico[i]= new char[3];
        for(int j= 0; j< 3; j++){
            inicioDinamico[i][j] = inicio[i][j];
            fimDinamico[i][j] = fim[i][j];
        }
    }
    Estrutura* e = new Estrutura(inicioDinamico,2,1,0);
    e->printEstrutura();
    Estrutura* f = new Estrutura(fimDinamico,1,1,INT64_MAX);
    f->printEstrutura();
    
    Buscas* b = new Buscas(e, f);
//    b->getConjPossibilidades()->colocaEstruturaChave(e->getChave(), e);
//    string aux = {0,2,3,1,7,5,4,6,8};
    clock_t t;
    t = clock();
//    b->profundidade();
//    b->largura();
//    b->backtrack();
//    b->ordenada();
//    b->AEstrela();
    b->idaEstrela();
    t = clock() - t;
    printf ("a busca demorou %f s\n",((float)t)/CLOCKS_PER_SEC);
//    cout << "print" << b->getConjPossibilidades()->temEstruturaNaChave(e->getChave()) << endl;
    
//    for ( Estrutura* k: *(b->geraFilhos(e))) {
//        k->printEstrutura();
//    }
    
//    for( int i=0; i< 9; i++){
//        cout << (int) e->getChave()[i];
//    }
//    ConjuntoDePossibilidades *p = new ConjuntoDePossibilidades();
//    p->geraTodasPossibilidades();
   
    return 0;
}

