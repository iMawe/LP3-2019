#include "FlorFactoryM.h"

Bonita::Bonita(int petal){
    petalos = petal;
}
Bonita::~Bonita(){

}
void Bonita::drawn(Trutle T,int x,int y){
    T.move(x, y);
    for(int i = 0; i < petalos; i++){
        T.forward(90);
        T.forward(30);
        T.forward(30,30);
        T.forward(30);
        T.forward(30,30);
        T.forward(30);
        T.forward(30,30);
        T.forward(30);
        T.forward(30,30);
    }
}


Mala::Mala(int petal){
    petalos = petal;
}
Mala::~Mala(){

}
    
void Mala::drawn(Trutle T,int x,int y){
    T.move(x, y);
    for(int i = 0; i < petalos; i++){
        T.forward(25,60);
        T.forward(50);
        T.forward(30,30);
        T.forward(50);
        T.forward(30,30);
        T.forward(50);
        T.forward(30,30);
        T.forward(50);
        T.forward(30,30);
    }
}


Normal::Normal(int petal){
    petalos = petal;
}
Normal::~Normal(){

}
void Normal::drawn(Trutle T,int x,int y){
    T.move(x, y);
    for(int i = 0; i < petalos; i++){
        T.forward(25,60);
        T.forward(10);
        T.forward(30,30);
        T.forward(10);
        T.forward(30,30);
        T.forward(10);
        T.forward(30,30);
        T.forward(10);
        T.forward(30,30);
    }
}
