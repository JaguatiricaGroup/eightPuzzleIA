/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConjuntoDePossibilidades.cpp
 * Author: snoopy
 * 
 
 */
#include <string>
#include "ConjuntoDePossibilidades.h"
#include <iostream>
using namespace std;

ConjuntoDePossibilidades::ConjuntoDePossibilidades() {
    possibilidades = new unordered_map<string, Estrutura*>();
    geraTodasPossibilidades();
    cout << "terminei de construir as possibilidades" << endl;
}

ConjuntoDePossibilidades::ConjuntoDePossibilidades(const ConjuntoDePossibilidades& orig) {
}

ConjuntoDePossibilidades::~ConjuntoDePossibilidades() {
}

// CPP program to print all permutations using
// Johnson and Trotter algorithm.
#include <bits/stdc++.h>

 
bool LEFT_TO_RIGHT = true;
bool RIGHT_TO_LEFT = false;
 
// Utility functions for finding the
// position of largest mobile integer in a[].
int searchArr(int a[], int n, int mobile)
{
    for (int i = 0; i < n; i++)
        if ((int)a[i] == mobile)
           return i + 1;
    
}
 
// To carry out step 1 of the algorithm i.e.
// to find the largest mobile integer.
int getMobile(int a[], bool dir[], int n)
{
    int mobile_prev = 0, mobile = 0;
    for (int i = 0; i < n; i++)
    {
        // direction 0 represents RIGHT TO LEFT.
        if (dir[a[i]-1] == RIGHT_TO_LEFT && i!=0)
        {
            if (a[i] > a[i-1] && (int) a[i] > mobile_prev)
            {
                mobile = (int) a[i];
                mobile_prev = mobile;
            }
        }
 
        // direction 1 represents LEFT TO RIGHT.
        if (dir[(int)a[i]-1] == LEFT_TO_RIGHT && i!=n-1)
        {
            if (a[i] > a[i+1] && (int) a[i] > mobile_prev)
            {
                mobile = (int) a[i];
                mobile_prev = mobile;
            }
        }
    }
 
    if (mobile == 0 && mobile_prev == 0)
        return 0;
    else
        return mobile;
}
 
void imprimeArray(string a, int n){
//    cout << "oi";
    for (int i = 0; i < n; i++)
    {
        cout << (int) a[i] ;        
    }
    cout << " ";
}


// Prints a single permutation
int* printOnePerm(int a[], bool dir[], int n){
    int mobile = getMobile(a, dir, n);
    int pos = searchArr(a, n, mobile);
 
    // swapping the elements according to the
    // direction i.e. dir[].
    if (dir[a[pos - 1] - 1] ==  RIGHT_TO_LEFT)
       swap( a[pos-1], a[pos-2]);
 
    else if (dir[a[pos - 1] - 1] == LEFT_TO_RIGHT)
       swap(a[pos], a[pos-1]);
 
    // changing the directions for elements
    // greater than largest mobile integer.
    for (int i = 0; i < n; i++)
    {
        if ( a[i] > mobile)
        {
            if ( dir[a[i] - 1] == LEFT_TO_RIGHT)
                 dir[a[i] - 1] = RIGHT_TO_LEFT;
            else if ( dir[a[i] - 1] == RIGHT_TO_LEFT)
                dir[a[i] - 1] = LEFT_TO_RIGHT;
        }
    }
//    cout<<" vou printar" << endl;
//     for (int i = 0; i < n; i++)
//        cout << (int) a[i];
//    cout << " ";
//    imprimeArray(a, n);
    return a;
//    for (int i = 0; i < n; i++)
//        cout << (int) a[i];
//    cout << " ";
}
 


// To end the algorithm for efficiency it ends
// at the factorial of n because number of
// permutations possible is just n!.
int fact(int n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
        res = res * i;
    return res;
}
 
// This function mainly calls printOnePerm()
// one by one to print all permutations.
void ConjuntoDePossibilidades::printPermutation(int n)
{
    // To store current permutation
//    char a[n];
    int *a = new int[n];
    int *possibilidade;
    // To store current directions
    bool *dir= new bool[n];
 
    // storing the elements from 1 to n and
    // printing first permutation.
    for (int i = 0; i < n; i++)
    {
        a[i] = (i + 1);
//        cout << (int) a[i];
    }
//    cout << endl;
//    imprimeArray(a, n);
    inserePossibilidade(a, n);
//    this->possibilidades->insert(pair<char*, Estrutura*>(a, NULL));
 
    // initially all directions are set
    // to RIGHT TO LEFT i.e. 0.
    for (int i = 0; i < n; i++)
        dir[i] =  RIGHT_TO_LEFT;
 
    // for generating permutations in the order.
    for (int i = 1; i < fact(n); i++){
        possibilidade = printOnePerm(a, dir, n);
//        imprimeArray(possibilidade, n);
        inserePossibilidade(possibilidade, n);
//        imprimeArray(a, n);
//        cout<<"permutei";
//        this->possibilidades->insert(pair<char*, Estrutura*>(possibilidade, NULL));
    }
}

void ConjuntoDePossibilidades::inserePossibilidade(int *a, int tam){
//    imprimeArray(a, tam);
    string b ;//= new string();
    for(int i=0; i< tam; i++){
        
        b.push_back((char) (a[i]-1));
    }
    // aqui garante que se nao foi usado está Null
    this->possibilidades->insert(pair<string, Estrutura*>(b, NULL));
}


void ConjuntoDePossibilidades::geraTodasPossibilidades() {
    int tam = 9;
    printPermutation(tam);
    int permutacoes = 0;
//    for (pair<char*,Estrutura*> p : *possibilidades) {
////        cout <<  p.first << " ";
////        imprimeArray(p.first, tam);
//        permutacoes++;
//        }
//    cout <<endl<< permutacoes << endl;

}

void ConjuntoDePossibilidades::colocaEstruturaChave(string chave, Estrutura* e) {
//    cout << "estou no coloca EstruturaChave" << endl;
    this->possibilidades->at(chave) = e;
}

bool ConjuntoDePossibilidades::temEstruturaNaChave(string chave) {
//    cout << "estruturaaa" << endl;
//    cout << this->possibilidades->at(chave) << endl;
    if(this->possibilidades->at(chave) != NULL){
        return true;
    }else
        return false;
}

Estrutura* ConjuntoDePossibilidades::getEstrutura(string chave) {
    cout << chave << endl;
    return this->possibilidades->at(chave);
}
