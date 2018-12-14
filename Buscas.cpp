/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Buscas.cpp
 * Author: snoopy
 * 
 
 */

#include <iostream>
#include "Buscas.h"
#include <stack>
#include <vector>
#include <algorithm>
#include <queue> 
 
using namespace std;

Buscas::Buscas(Estrutura* inicio, Estrutura* fim) {

    this->inicio=inicio;
    this->fim=fim;
    this->todasPossibilidades = new ConjuntoDePossibilidades();
    this->insereEstChave( inicio);
    this->insereEstChave(fim);
    this->infoBusca.custoSolucao =0;
    this->infoBusca.profundidade =0;
    this->infoBusca.tempoDecorrido =0;
    this->infoBusca.totalNosExpandidos =0;
    this->infoBusca.totalNosVisitados =0;
    this->infoBusca.valorMedioRamArv =0;
        cout<<"construi a busca"<<endl;
   
}

Buscas::~Buscas() {
    delete this->todasPossibilidades;
    this->todasPossibilidades = NULL;
}

bool Buscas::encontrouSolucao(Estrutura* e) {
//    cout<<"estou no encontrou Solucao oic oic"<<endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) {
            
//            cout << (int)this->fim->getMatriz()[i][j] <<" "<< (int)e->getMatriz()[i][j]<<", ";
            
            if(this->fim->getMatriz()[i][j] != e->getMatriz()[i][j]){
                return false;
            }
        }
//        cout<<endl;
    }
    return true;
}

void verificaMovimento(stack<Estrutura*>* s,Estrutura* p){
    if(p!=NULL){
        s->push(p);
    }
}


void Buscas::imprimeArray(char *a, int n){
//    cout << "oi";
    for (int i = 0; i < n; i++)
    {
        cout << (int) a[i] ;        
    }
    cout << " ";
}



void Buscas::insereEstChave(Estrutura* filho){
    string chave;
//    cout << "Quero inserir" << endl;

    if (filho!= NULL){
        chave = filho->getChave();
//        cout << "estou no insereEstruturaChave" << endl;
//        imprimeArray(chave, 9);
//        cout << endl;
        if(!this->todasPossibilidades->temEstruturaNaChave(chave)){
//            cout<<"inseri a estrutura no mapa"<<endl;
            this->todasPossibilidades->colocaEstruturaChave(chave, filho);

        }
    }
}

unsigned Buscas::distManhattan(Estrutura* e) {
    unsigned dist = 0;//e->getCusto();// tirar depois
    for(int i=0;i<3;i++)
    {
            for(int j=0;j<3;j++)
            {
                    if(e->getMatriz()[i][j]!=0)
                    {
                            for(int k=0;k<3;k++)
                            {
                                    for(int l=0;l<3;l++)
                                    {
                                            if( e->getMatriz()[i][j]==fim->getMatriz()[k][l] )
                                                    dist+=abs(i-k)+abs(j-l);
                                    }
                            }
                    }
            }
    }

    return dist;
}

vector<Estrutura*>* Buscas::geraFilhos(Estrutura* e) {
    //regra
    vector<Estrutura*>* aux = new vector<Estrutura*>();
    Estrutura* est = e->moveEsq();
    string chave ;
    //regra do teste prof e larg
//    Estrutura* regra[4] = {e->moveDir(), e->moveBaixo(),e->moveCima(),e->moveEsq()};
//regra do backt
    Estrutura* regra[4] = {e->moveEsq(), e->moveCima(), e->moveDir(), e->moveBaixo()};
    est = regra[0];
    if(est != NULL){//se deu certo o movimento        
        chave = est->getChave(); // pego a chave
        if(!this->todasPossibilidades->temEstruturaNaChave(chave)) {//nao existe no hash
            aux->push_back(est); // coloca no vector de filhos o novo
            this->todasPossibilidades->colocaEstruturaChave(chave, est);// acrescenta novo ao hash            
            this->getEstrutura(chave)->setPai(e);            
        } else {// existia no hash já
            if( est->getCusto() < this->getEstrutura(chave)->getCusto() ){// confere custo
                this->getEstrutura(chave)->setCusto(est->getCusto());
                this->getEstrutura(chave)->setPai(e);
            }                
            aux->push_back(this->getEstrutura(chave)); // coloca no vetor de filhos            
        }
    }
    
    est = regra[1];
    if(est != NULL){//se deu certo o movimento        
        chave = est->getChave(); // pego a chave
        if(!this->todasPossibilidades->temEstruturaNaChave(chave)) {//nao existe no hash
            aux->push_back(est); // coloca no vector de filhos o novo
            this->todasPossibilidades->colocaEstruturaChave(chave, est);// acrescenta novo ao hash            
            this->getEstrutura(chave)->setPai(e);            
        } else {// existia no hash já
            if( est->getCusto() < this->getEstrutura(chave)->getCusto() ){// confere custo
                this->getEstrutura(chave)->setCusto(est->getCusto());
                this->getEstrutura(chave)->setPai(e);
            }                
            aux->push_back(this->getEstrutura(chave)); // coloca no vetor de filhos            
        }
    }
    
    est = regra[2];
    if(est != NULL){//se deu certo o movimento        
        chave = est->getChave(); // pego a chave
        if(!this->todasPossibilidades->temEstruturaNaChave(chave)) {//nao existe no hash
            aux->push_back(est); // coloca no vector de filhos o novo
            this->todasPossibilidades->colocaEstruturaChave(chave, est);// acrescenta novo ao hash            
            this->getEstrutura(chave)->setPai(e);            
        } else {// existia no hash já
            if( est->getCusto() < this->getEstrutura(chave)->getCusto() ){// confere custo
                this->getEstrutura(chave)->setCusto(est->getCusto());
                this->getEstrutura(chave)->setPai(e);
            }                
            aux->push_back(this->getEstrutura(chave)); // coloca no vetor de filhos            
        }
    }
    
    est = regra[3];
    if(est != NULL){//se deu certo o movimento        
        chave = est->getChave(); // pego a chave
        if(!this->todasPossibilidades->temEstruturaNaChave(chave)) {//nao existe no hash
            aux->push_back(est); // coloca no vector de filhos o novo
            this->todasPossibilidades->colocaEstruturaChave(chave, est);// acrescenta novo ao hash            
            this->getEstrutura(chave)->setPai(e);            
        } else {// existia no hash já
            if( est->getCusto() < this->getEstrutura(chave)->getCusto() ){// confere custo
                this->getEstrutura(chave)->setCusto(est->getCusto());
                this->getEstrutura(chave)->setPai(e);
            }                
            aux->push_back(this->getEstrutura(chave)); // coloca no vetor de filhos            
        }
    }
    
    return aux;
}

void printFilhos(vector<Estrutura*>* aux){
    cout <<"filhos"<< endl;
    for (Estrutura* L: *aux){
//        insereEstChave(L);
        cout << "estrutura" << endl;
         L->printEstrutura() ;
//        cout << "---------------------------------" << endl;
    }
}

ConjuntoDePossibilidades* Buscas::getConjPossibilidades() {
    return this->todasPossibilidades;
}

Estrutura* Buscas::getEstrutura(string chave) {
    return this->todasPossibilidades->getEstrutura(chave);
}

void Buscas::printSolucao(Estrutura* e){
    if (e == NULL){
        cout << "null" << endl;
        exit(31);
    }
   cout << "encontrei a solucao" << endl;
    this->infoBusca.custoSolucao = e->getCusto();
    this->infoBusca.profundidade = e->getCusto();
    cout<< "custo da solucao :"<<endl;
    cout << this->infoBusca.custoSolucao << endl ;
    cout<< "profundidade :"<<endl;
    cout <<  this->infoBusca.profundidade<< endl;
    cout<< "total de nos expandidos :"<<endl;
    cout << this->infoBusca.totalNosExpandidos<< endl;
    cout<< "total de nos visitados :"<<endl;
    cout << this->infoBusca.totalNosVisitados<< endl;
    cout<< "fator de ramificação :"<<endl;
    cout << this->infoBusca.totalNosVisitados/this->infoBusca.totalNosVisitados<< endl;
    cout<< "caminho :"<<endl;
    for( Estrutura* aux = e; aux != NULL; aux=aux->getPai()){
        aux->printEstrutura();
    }
    
}


int Buscas::profundidade() {
    cout <<"estou na profundidade"<< endl;
    stack<string> pilha;
    string chaveAtual;
    Estrutura* estAtual = NULL;
    pilha.push(this->inicio->getChave());
    int i = 0 ;
    do{
        chaveAtual = pilha.top();
        
        estAtual = this->getEstrutura(chaveAtual);
        cout<<"escolhi"<<endl;
        estAtual->printEstrutura();
        pilha.pop();
        if(this->encontrouSolucao(estAtual)){
            printSolucao(estAtual);
            return 10;
        }
        cout << "movimentou" << endl;
        vector<Estrutura*>* v = this->geraFilhos(estAtual);
        reverse(v->begin(),v->end());
        for (std::vector<Estrutura*>::iterator filho=v->begin(); filho!=v->end(); ++filho){
//        for ( Estrutura* filho: *(v)) {            
                if( !( (*filho)->foiVisitado() ) ){
                    this->infoBusca.totalNosExpandidos++;
                    pilha.push((*filho)->getChave());                
            }
        }
        this->infoBusca.totalNosVisitados++;
        estAtual->setVisitado(true);
        delete v;
        v=NULL;
    }while(!pilha.empty());
    cout<<"nao achei :("<<endl;    
    return 1;
}

int Buscas::largura() {    
    cout <<"estou na profundidade"<< endl;
    queue<string> fila;
    string chaveAtual;
    Estrutura* estAtual = NULL;
    fila.push(this->inicio->getChave());
    int i = 0 ;
    do{
        chaveAtual = fila.front();
        estAtual = this->getEstrutura(chaveAtual);
        cout<<"escolhi"<<endl;
        estAtual->printEstrutura();
        fila.pop();
        if(this->encontrouSolucao(estAtual)){
            cout << "encontrou de fato" << endl;
            this->printSolucao(estAtual);
            return 10;
        }
        cout << "movimentou" << endl;
        vector<Estrutura*>* v = this->geraFilhos(estAtual);
//        reverse(v->begin(),v->end());
        for (std::vector<Estrutura*>::iterator filho=v->begin(); filho!=v->end(); ++filho){
//        for ( Estrutura* filho: *(v)) {
                if( !( (*filho)->foiVisitado()) ){
                    fila.push((*filho)->getChave());                
            }
        }
        estAtual->setVisitado(true);
        delete v;
        v=NULL;
    }while(!fila.empty());
    cout<<"nao achei :("<<endl;    
    return 1;
}

int Buscas::auxBackTrack(string chave ){
    Estrutura *estAtual = this->todasPossibilidades->getEstrutura(chave);
//    cout<<"escolhi"<<endl;
//    estAtual->printEstrutura();
    if(this->encontrouSolucao(estAtual)){
            cout << "encontrou de fato" << endl;
            this->printSolucao(estAtual);
            return 1;
    } else {
        vector<Estrutura*>* v = this->geraFilhos(estAtual);
        for (std::vector<Estrutura*>::iterator filho=v->begin(); filho!=v->end(); ++filho){
            if(!(*filho)->foiVisitado() ){
                (*filho)->setVisitado(true);
                string chaveFilho = (*filho)->getChave();
                if(auxBackTrack(chaveFilho)){
                    return 1;
                }
            }
        }
    }
    /*printf("backTrack (%u)\n",cidadeAtual);*/
    /*infos->profundidade--;*/
    /*L->distancias[cidadeAtual][cidadeAtual] = 0;*/
//    pais[cidadeAtual] = L->numeroCidades;
    estAtual->setVisitado(false);
    return 0;
}

int Buscas::backtrack() {
    cout << "Iniciando Busca Backtrack \n " ;
    cout << "inicio ";
    if(auxBackTrack(inicio->getChave()))
        cout << "sucesso" << endl;
    else
        cout << "falha" << endl;
    return 1;
}

//bool Buscas::ordemOrdenada(const string& i, const string& j){     
//    return this->getEstrutura(i)->getCusto() > this->getEstrutura(j)->getCusto(); 
//}
//
//bool ordenaPeso(const Estrutura& i,const Estrutura& j){ 
//    /*ordena os pesos das Arestas da Árvore Geradora Mínima*/
//    return (i.getCusto() < j.getCusto()); 
//};

int Buscas::ordenada(){
    cout << "Iniciando Busca Ordenada" << endl;    
    priority_queue<Estrutura*, vector<Estrutura*>, CompareOrdenada> filaPrio;
    filaPrio.push(inicio);
    string chaveAtual;
    string chaveFilho;
    Estrutura* estAtual;
    Estrutura* estFilho;
    while(!filaPrio.empty()){
        estAtual = filaPrio.top();
        chaveAtual = estAtual->getChave();
        filaPrio.pop();
        if (this->getEstrutura(chaveAtual)->foiVisitado() ){// retira elementos duplicados            
            cout << "descartado" << endl;
            continue;
        }        
        cout << "escolhi o ..." << endl;
        estAtual->printEstrutura();
        if(this->encontrouSolucao(estAtual)){
            cout << "sucesso" << endl;
            this->printSolucao(estAtual);
            return 10;
        }else{
            vector<Estrutura*>* v = this->geraFilhos(estAtual);
            for (std::vector<Estrutura*>::iterator filho=v->begin(); filho!=v->end(); ++filho){                
                chaveFilho = (*filho)->getChave();
                estFilho = this->getEstrutura(chaveFilho);
                if( !(estFilho->foiVisitado()) ) {                    
                    filaPrio.push(estFilho);
                }
            }
            estAtual->setVisitado(true);
        // L->distanciastual][atual] = 1;
            delete v;
            v = NULL;
        }
    }
    //dentro do for dos filhos dentro do fim do else ta dando set true
    cout << "fracasso" << endl;
    return 1;
}


int Buscas::gulosa(){
    cout << "Iniciando Busca Gulosa" << endl;    
    priority_queue<Estrutura*, vector<Estrutura*>, CompareGulosa> filaPrio;
    inicio->setHeuristica(this->distManhattan(inicio));
    filaPrio.push(inicio);
    string chaveAtual;
    string chaveFilho;
    Estrutura* estAtual;
    Estrutura* estFilho;
    while(!filaPrio.empty()){
        estAtual = filaPrio.top();
        chaveAtual = estAtual->getChave();
        filaPrio.pop();
        if (this->getEstrutura(chaveAtual)->foiVisitado() ){// retira elementos duplicados            
            cout << "descartado" << endl;
            continue;
        }        
        cout << "escolhi o ..." << endl;
        estAtual->printEstrutura();
        if(this->encontrouSolucao(estAtual)){
            cout << "sucesso" << endl;
            this->printSolucao(estAtual);
            return 10;
        }else{
            vector<Estrutura*>* v = this->geraFilhos(estAtual);
            for (std::vector<Estrutura*>::iterator filho=v->begin(); filho!=v->end(); ++filho){
                cout << "filhos" << endl;
                chaveFilho = (*filho)->getChave();                
                estFilho = this->getEstrutura(chaveFilho);                
                if( !(estFilho->foiVisitado()) ) {                    
                    estFilho->setHeuristica(this->distManhattan(estFilho));
                    estFilho->printEstrutura();
                    filaPrio.push(estFilho);
                }
            }
            estAtual->setVisitado(true);
        // L->distanciastual][atual] = 1;
            delete v;
            v = NULL;
        }
    }
    //dentro do for dos filhos dentro do fim do else ta dando set true
    cout << "fracasso" << endl;
    return 1;
}


int Buscas::AEstrela(){
    cout << "Iniciando Busca Gulosa" << endl;    
    priority_queue<Estrutura*, vector<Estrutura*>, CompareAEstrela> filaPrio;
    inicio->setHeuristica(this->distManhattan(inicio));
    filaPrio.push(inicio);
    string chaveAtual;
    string chaveFilho;
    Estrutura* estAtual;
    Estrutura* estFilho;
    while(!filaPrio.empty()){
        estAtual = filaPrio.top();
        chaveAtual = estAtual->getChave();
        filaPrio.pop();
        if (this->getEstrutura(chaveAtual)->foiVisitado() ){// retira elementos duplicados            
            cout << "descartado" << endl;
            continue;
        }        
        cout << "escolhi o ..." << endl;
        estAtual->printEstrutura();
        if(this->encontrouSolucao(estAtual)){
            cout << "sucesso" << endl;
            this->printSolucao(estAtual);
            return 10;
        }else{
            vector<Estrutura*>* v = this->geraFilhos(estAtual);
            for (std::vector<Estrutura*>::iterator filho=v->begin(); filho!=v->end(); ++filho){
                cout << "filhos" << endl;
                chaveFilho = (*filho)->getChave();                
                estFilho = this->getEstrutura(chaveFilho);                
                if( !(estFilho->foiVisitado()) ) {                    
                    estFilho->setHeuristica(this->distManhattan(estFilho));
                    estFilho->printEstrutura();
                    filaPrio.push(estFilho);
                }
            }
            estAtual->setVisitado(true);
        // L->distanciastual][atual] = 1;
            delete v;
            v = NULL;
        }
    }
    //dentro do for dos filhos dentro do fim do else ta dando set true
    cout << "fracasso" << endl;
    return 1;
}


unsigned Buscas::idaEstrelaAux(string chaveAtual, unsigned limiteCusto){
    Estrutura* estAtual = this->getEstrutura(chaveAtual);
    cout << "escolhi o ..."<< endl;
    estAtual->printEstrutura();
    unsigned f = estAtual->getCusto() + estAtual->getHeuristica();    
//    cout << "custoCaminho mais heuristica " << f;
    string chaveFilho;
    unsigned  custoAux;
    Estrutura* estFilho;
    // printf("-> %u ", cidadeAtual);
//    infos->nosVisitados++;
    if(f > limiteCusto){
        cout << "quebrei a recursao" << endl;
        estAtual->setVisitado(false);
//        pais[cidadeAtual] = L->numeroCidades;
        return f;
      }
    if(this->encontrouSolucao(estAtual)){
//        empilha(infos->caminho,cidadeAtual);
        this->printSolucao(estAtual);
        return 0;
    }
    unsigned custoMin = INT64_MAX;
    vector<Estrutura*>* v = this->geraFilhos(estAtual);
    for (std::vector<Estrutura*>::iterator filho=v->begin(); filho!=v->end(); ++filho){
        cout << "filhos" << endl;
        chaveFilho = (*filho)->getChave();
        estFilho = this->getEstrutura(chaveFilho);
        if( !(estFilho->foiVisitado()) ) {
            estFilho->setHeuristica(this->distManhattan(estFilho));
            estFilho->printEstrutura();
//            filaPrio.push(estFilho);distancia(L,cidadeAtual,i)
            custoAux = idaEstrelaAux(chaveFilho,limiteCusto);
            if(custoAux == 0){
//                empilha(infos->caminho, cidadeAtual);;;;;;;;;;;;;;;;;;;;;;
                return 0;
              }
            if( custoAux < custoMin )
                custoMin = custoAux;
        }
    }
    estAtual->setVisitado(true);
//    for(unsigned i= 0 ; i < L->numeroCidades ; i++){
//        if(distancia(L,cidadeAtual,i) > 0 && pais[i] == L->numeroCidades){//!L->distancias[i][i])
//          // printf("(%u)", i);
//            infos->nosExpandidos++;
//            pais[i] = cidadeAtual;
//            double custoAux = idaEstrelaAux(L,i,custoCaminho + distancia(L,cidadeAtual,i),limiteCusto,fim,pais,infos);
//            if(custoAux == -1){
//                empilha(infos->caminho, cidadeAtual);
//                return -1;
//              }
//            if( custoAux < custoMin )
//                custoMin = custoAux;
//        }
//    }
////    pais[cidadeAtual] = L->numeroCidades;
    return custoMin;
}

int Buscas::idaEstrela(){
    cout << "Iniciando Busca IDA" << endl;
//    unsigned *pais =iniPai(L->numeroCidades,L->numeroCidades);
    inicio->setHeuristica(this->distManhattan(inicio));
    unsigned limiteCusto = inicio->getHeuristica();
    unsigned custoEncontrado;
    while(true){
        cout << "patamar: "<< limiteCusto<< endl;
        custoEncontrado= idaEstrelaAux(inicio->getChave(), limiteCusto);
//        cout << "patamar encontrado: "<< custoEncontrado<< endl;
        if(custoEncontrado == 0){
            cout << "Sucesso"<< endl;
            return 10;
        }
        if(custoEncontrado == INT64_MAX){
            cout << "Fracasso"<< endl;
            return 1;
        }
        /*if(custoEncontrado == -1)*/

        // if(noEncontrado == ∞)
            //  return;
        limiteCusto = custoEncontrado;
        // printf("\niterei limite:  %lf\n",limiteCusto);
    }
    return 10;
}