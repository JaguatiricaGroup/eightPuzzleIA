/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   estrutura.cpp
 * Author: snoopy
 
 */

#include <iostream>
#include "ConjuntoDePossibilidades.h"


#include "Estrutura.h"

using namespace std;

Estrutura::Estrutura(){
    this->custo = -1;
    this->xBranco = 0;
    this->yBranco = 0;
    this->matriz = new char*[3];
    for (int i = 0; i < 3; i++){
        this->matriz[i] = new char[3];
        for (int j = 0; j < 3; j++) {
            this->matriz[i][j] = 0;
        }
    }
    this->visitado = false;
    this->pai = NULL;
}

Estrutura::Estrutura(char **matriz, char xBranco, char yBranco , unsigned custo){
//    cout << "construindo a matriz com configuracao Pre determinada"<< endl;    
    this->custo = custo;
    this->xBranco = xBranco;
    this->yBranco = yBranco;
    
    this->matriz = new char*[3];
    for (int i = 0; i < 3; i++){
        this->matriz[i] = new char[3];
        for (int j = 0; j < 3; j++) {
            this->matriz[i][j] = matriz[i][j];
        }
    }
    this->visitado = false;
    this->pai = NULL;
}


Estrutura::~Estrutura() {
    for (int i = 0; i < 3; ++i){
        delete [] matriz[i];
        this->matriz[i] = NULL;
    }
    delete [] matriz;
    this->matriz = NULL;    
}

char** Estrutura::getMatriz() {
        return this->matriz;
}

string Estrutura::getChave() {
    string str;
    for(int i=0; i< 3; i++){
        for(int j=0; j<3; j++){
            str.push_back(this->matriz[i][j]);
        }
    }
    return str;
}

void Estrutura::printEstrutura() {
    cout << "------------" << endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) {
            cout << (int)this->matriz[i][j] << ",";
        }
        cout << endl;
    }
    cout << "visitado = " << this->visitado<< endl;
    cout << "custo = " << this->custo << endl;
    cout << "Heuristica = " << this->heuristica << endl;
    cout << "AEstrela = " << this->heuristica+this->custo << endl;
    cout << "------------" << endl;
}


void Estrutura::swapMatriz(Estrutura* filho){
    char aux = filho->matriz[this->xBranco][this->yBranco];// guarda o caracter antigo
    filho->matriz[this->xBranco][this->yBranco] = filho->matriz[filho->xBranco][filho->yBranco];// coloca o novo no antigo
    filho->matriz[filho->xBranco][filho->yBranco] = aux;// coloca o antigo no lugar certo
//    filho->printEstrutura();
}


// Gera uma nova Estrutura com zero para baixo
Estrutura* Estrutura::moveBaixo() {
//    cout <<"baixo"<<endl;
    if(this->xBranco+1 < 3){// dá para mover?
        Estrutura* estruturaNova = new Estrutura(this->matriz, xBranco+1, yBranco, this->custo+1);
        swapMatriz(estruturaNova);        
        return estruturaNova;
    }
    cout << "deu erro movendo para baixo :0" << endl;
    return NULL;    
}

// Gera uma nova Estrutura com zero para Cima
Estrutura* Estrutura::moveCima() {
//    cout <<"cima"<<endl;
    if(this->xBranco-1 >= 0){// dá para mover?
        Estrutura* estruturaNova = new Estrutura(this->matriz, xBranco-1, yBranco, this->custo+1);
        swapMatriz(estruturaNova);        
        return estruturaNova;
    }
    cout << "deu erro movendo para Cima :0" << endl;
    return NULL;    
}

// Gera uma nova Estrutura com zero para a Direita
Estrutura* Estrutura::moveDir() {
//    cout <<"direita"<<endl;
    if(this->yBranco+1 < 3){// dá para mover?
        Estrutura* estruturaNova = new Estrutura(this->matriz, xBranco, yBranco+1, this->custo+1);
        swapMatriz(estruturaNova);
        return estruturaNova;
    }
    cout << "deu erro movendo para a direita :0" << endl;
    return NULL;    
}

// Gera uma nova Estrutura com zero para esq
Estrutura* Estrutura::moveEsq() {
//    cout <<"esquerda"<<endl;
    if(this->yBranco-1 >= 0){// dá para mover ?
//        if(!(possibilidades->temEstruturaNaChave(chave))){
            Estrutura* estruturaNova = new Estrutura(this->matriz, xBranco, yBranco-1, this->custo+1);
            swapMatriz(estruturaNova);        
            return estruturaNova;
//        }
    }
    cout << "deu erro movendo para a Esquerda:0" << endl;
    return NULL;    
}

bool Estrutura::foiVisitado() {
    return this->visitado;
}

void Estrutura::setVisitado(bool visitado) {
    this->visitado = visitado;
}

unsigned Estrutura::getCusto() {
    return custo;
}

void Estrutura::setCusto(unsigned custo){
    this->custo = custo;
}


unsigned Estrutura::getHeuristica() {
    return this->heuristica;
}

void Estrutura::setHeuristica(unsigned heuristica) {
    this->heuristica = heuristica;
}

Estrutura* Estrutura::getPai() {
    return this->pai;
}

void Estrutura::setPai(Estrutura* pai) {
    this->pai = pai;
}
