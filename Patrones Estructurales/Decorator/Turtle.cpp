/** @file Turtle.cpp
@author iMawe
@version Revision 1.1
@brief implementacion de la clase tortuga.cpp con el uso de OpenGl en C++.
*/

#include "Turtle.h"
/** Constructor.
 *  se establecen todos los datos miembro de la
    tortuga.
 */
Turtle::Turtle(int w1,int h1){
    x1 = Turt.x;
    y1 = Turt.y;
    w = w1;
    h = h1;
}
/** Funcion para avanzar.
 *  se reciben grados los cuales se aplican a la
    rotacion, tambien se recibe la distancia que
    va a recorrer.
 */
void Turtle::forward(int di,double de){
    de = de * (PI/  180);
    Turt.de += de;
    glBegin(GL_LINES);
        glVertex2f(Turt.x, Turt.y);

        Turt.y = Turt.y + (di * sin(Turt.de));
        Turt.x = Turt.x + (di * cos(Turt.de));

        glVertex2f(Turt.x, Turt.y);
    glEnd();
    glFlush();
}
/** Funcion para elegir color.
 *  permite elegir el color con el que se va
    a realizar el trazo.
 */
void Turtle::set_color(int R,int G, int B){
    Turt.R = R;
    Turt.G = G;
    Turt.B = B;
    glColor3f(R, G, B);
}
/** Funcion para no pintar.
 *  le damos color 0, lo cual causa que
    no pinte en lo absoluto al moverse.
 */
void Turtle::penup(){
    glColor3f(0, 0, 0);
}
/** Funcion para pintar.
 *  Le da color al trazo que se va a realizar.
 */
void Turtle::pendow(){
    set_color(Turt.R, Turt.G, Turt.B);
}
/** Funcion para mover la tortuga.
 *  mueve la tortuga sin pintar al punto de 
    coordenadas indicado por el usuario.
 */
void Turtle::move(double x, double y){
    Turt.x = x1 + x;
    Turt.y = y1 + y;
}
/** Funcion para mostrar.
 *  se utilizan distintas funciones del OpenGL para
    poder visualizar todo en uan ventana.
 */
void Turtle::display(int argc, char **argv){
    
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(200, 100);
    
    glutInitWindowSize(w,h);

    glutCreateWindow("window1");
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, w-1, 0, h-1);
    set_color(Turt.R, Turt.G, Turt.B);
    
}