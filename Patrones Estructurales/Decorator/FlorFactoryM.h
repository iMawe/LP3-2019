/** @file Turtle.h
@author iMawe
@version Revision 1.1
@brief implementacion de la clase FlorFactoryM con el uso de OpenGl en C++.
*/

/**
@mainpage
Se demuestra como se implemento el patron de diseño Builder para poder
dar inumerables combinaciones a nuestro arbol al momento de ser
dibujado

- Haciendo uso de OpenGL
- Incluyendo la libreria Turtle para poer realizar estos graficos.

*/

#ifndef FLORFACTORYM_H
#define FLORFACTORYM_H
#include <iostream>
#include <string>
#include "Trutle.h"
using namespace std;

/**
* @class   Flower
* @brief   La clase tronco contiene tla funcion drawn para poder visualizarlo
* @detail  Se instancia el dato miembro 
*/
class Flower{
protected:
    int petalos;

public:
    virtual void drawn(Trutle T,int x,int y) = 0;
};

/**
* @class   Bonita
* @brief   La clase Bonita contiene la funcion drawn para poder visualizarlo, hereda de la clase Flower
* @detail  Se tiene constructor y destructor
*/
class Bonita:public Flower{
public:
/** Constructor.
 *  @param petal es la cantidad de petalos que tiene la flor.
 */
    Bonita(int petal);
/** Destructor
 */
    ~Bonita();
/** La funcion drawn recibe la tortuga y el tamano.
 *  @param T, nos permite hacer uso de la tortuga y x, y coordinan el tamano del tronco.
 */
    void drawn(Trutle T,int x,int y);
    
};

/**
* @class   Mala
* @brief   La clase tronco contiene tla funcion drawn para poder visualizarlo, hereda de la clase Flower
* @detail  Se instancia el dato miembro 
*/
class Mala :public Flower{
public:
/** Constructor.
 *  @param petal es la cantidad de petalos que tiene la flor.
 */
    Mala(int petal);
/** Destructor
 */
    ~Mala();
/** La funcion drawn recibe la tortuga y el tamano.
 *  @param T, nos permite hacer uso de la tortuga y x, y coordinan el tamano del tronco.
 */
    void drawn(Trutle T,int x,int y);
    
};

/**
* @class   Normal
* @brief   La clase tronco contiene tla funcion drawn para poder visualizarlo, hereda de la clase Flower
* @detail  Se instancia el dato miembro 
*/
class Normal:public Flower{
public:
/** Constructor.
 *  @param petal es la cantidad de petalos que tiene la flor.
 */
    Normal(int petal);
/** Destructor
 */
    ~Normal();
/** La funcion drawn recibe la tortuga y el tamano.
 *  @param T, nos permite hacer uso de la tortuga y x, y coordinan el tamano del tronco.
 */
    void drawn(Trutle p,int x,int y);
    
};

/*
int main(int argc, char **argv){
    Trutle T(500,500);
    T.display(argc,argv);
    Bonita b(6);
    Normal r(6);
    Mala f(6);
    b.drawn(p,100,100);
    r.drawn(p,200,100);
    f.drawn(p,300,100);
    while(1);
    glutMainLoop();
    
    return 0;
}*/


#endif // FLORFACTORYM_H