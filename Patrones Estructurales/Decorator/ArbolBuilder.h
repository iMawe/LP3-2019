/** @file Turtle.h
@author iMawe
@version Revision 1.1
@brief implementacion de la clase ArbolBuilder con el uso de OpenGl en C++.
*/

/**
@mainpage
Se demuestra como se implemento el patron de diseño Builder para poder
dar inumerables combinaciones a nuestro arbol al momento de ser
dibujado

- Haciendo uso de OpenGL
- Incluyendo la libreria Turtle para poer realizar estos graficos.

*/
#ifndef ARBOLBUILDER_H
#define ARBOLBUILDER_H
#include <iostream>
#include <string>
#include "Turtle.h"

using namespace std;

/**
* @class   Tronco
* @brief   La clase tronco contiene la funcion drawn para poder visualizarlo
* @detail  Se instancia el dato miembro 
*/
class Tronco{
public:
    int size;
/** La funcion drawn recibe la tortuga y el tamano.
 *  @param T, nos permite hacer uso de la tortuga y x, y coordinan el tamano del tronco.
 */
    void drawn(Turtle T,int x, int y);
};

/**
* @class   Hoja
* @brief   La clase Hoja contiene la funcion drawn para poder visualizarlo
* @detail  Se instancia el dato miembro 
*/
class Hoja{
public:
    int size;
/** La funcion drawn recibe la tortuga y el tamano.
 *  @param T, nos permite hacer uso de la tortuga y x, y coordinan el tamano de la hoja.
 */
    void drawn(Turtle T,int x, int y);
};

/**
* @class   Rama
* @brief   La clase Rama contiene la funcion drawn para poder visualizarlo
* @detail  Se instancia el dato miembro 
*/
class Rama{
public:
    int size;
/** La funcion drawn recibe la tortuga y el tamano.
 *  @param T, nos permite hacer uso de la tortuga y x, y coordinan el tamano de la rama.
 */
    void drawn(Turtle T,int x, int y);

/**
* @class   Tree
* @brief   La clase Tree contiene la funcion drawn para visualizar el arbol
* @detail  Se instancia los datos miembros que son punteros a las partes del arbol
*/
class Tree{
public:
    Tronco*   Troncos;
    Hoja* Hojas;
    Rama*   Ramas;
/** La funcion drawn recibe la tortuga y el tamano.
 *  @param T, nos permite hacer uso de la tortuga y x, y coordinan el tamano de cada objeto.
 */
    void drawn(Turtle T,int x, int y);};

/**
* @class   Builder
* @brief   La interfaz Builder contiene las funciones getTronco, getHojas, getRamas para obtener las caracteristicas del arbol
* @detail  Las funciones son virtual-puras y apuntan a las clases de las partes del arbol
*/
class Builder{
public:
/** La funcion getTronco es virtual pura para que pueda ser heredada, utilizada y sobrescrita por las demas clases.

 */
    virtual Tronco* getTronco() = 0;
/** La funcion getHojas es virtual pura para que pueda ser heredada, utilizada y sobrescrita por las demas clases.
 */
    virtual Hoja* getHojas() = 0;
/** La funcion getRamas es virtual pura para que pueda ser heredada, utilizada y sobrescrita por las demas clases.
 */
    virtual Rama* getRamas() = 0;
};

/**
* @class   NormalTree
* @brief   La clase NormalTree contiene las funciones getTronco, getHojas, getRamas; asi como loset sets de estas para obtener y generar las caracteristicas del arbol
* @detail  Las funciones apuntan a las clases de las partes del arbol, asi como tambien son void
*/
class NormalTree : public Builder{

public:
    Tronco* Troncos;
    Hoja* Hojas;
    Rama* Ramas;
/** La funcion setTronco recibe el tamano.
 *  @param size, nos permite definir el tamano pedido.
 */
    void setTronco(int size);
/** La funcion setHojas recibe el tamano.
 *  @param size, nos permite definir el tamano pedido.
 */
    void setHojas(int size);
/** La funcion setRamas recibe el tamano.
 *  @param size, nos permite definir el tamano pedido.
 */
    void setRamas(int size);
/** La funcion getTronco es un puntero a Tronco, nos permite obtener las caracteristicas de este.
 */
    Tronco* getTronco();
/** La funcion getHojas es un puntero a Tronco, nos permite obtener las caracteristicas de este.
 */
    Hoja* getHojas();
/** La funcion getRamas es un puntero a Tronco, nos permite obtener las caracteristicas de este.
 */
    Rama* getRamas();
};

/**
* @class   Director
* @brief   La clase Director cse encarga de recolectar todas las caracteristicas para poder formal lo pedido
* @detail  Utilizando punteros al arbol, se logra enviar la informacion para su elaboracion
*/
class Director{
private:
    Builder* builder;

public:
/** La funcion setBuilder envia las caracteristicas definidas.
 *  @param newBuilder es un puntor a Builder, para que las caracteristicas sean enviadas directamente.
 */
    void setBuilder(Builder* newBuilder);
/** La funcion getBuilder recibe tres tamanos para la creacion de los objetos y es un puntero a Tree.
 *  @param a, b y c crean un arbol base de la forma ramas, tronco y hojas respectivamente.
 */
    Tree* getBuilder(int a, int b, int c);
/** La funcion getTree es un puntero a Tree, la cual nos permite obtener la informacion para la creacion del arbol
 */
    Tree* getTree();
};


/*

int main(int argc, char **argv){
    Turtle T(700,500);
    T.display(argc,argv);
    Tree* Trees;
    Director director;
    
    Trees = director.getBuilder(20,10,5);
    Trees->drawn(T,100,100);


    
    Trees = director.getBuilder(20,18,16);
    Trees->drawn(T,200,200);
    while(1);
    glutMainLoop();
    
        
    return 0;
}*/


#endif // ARBOLBUILDER_H