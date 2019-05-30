#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Shape{
public:
	virtual void draw() = 0;
	virtual void eraser() = 0;
};

class Circle: public Shape{
private:
	string nombre;
	string tamano;
	string color;
public:
	Circle(){
		nombre = "Circulo";
		tamano = "4 cm.";
		color = "rojo";
	}
	void draw(){
		cout<< "Se dibuja un circulo"<< endl;
	}
	void eraser(){
		cout<< "Se borra el circulo"<< endl;
	}
};

class Square: public Shape{
private:
	string nombre;
	string tamano;
	string color;
public:
	Square(){
		nombre = "Cuadrado";
		tamano = "3 cm.";
		color = "azul";
	}
	void draw(){
		cout<< "Se dibuja un cuadrado"<< endl;
	}
	void eraser(){
		cout<< "Se borra el cuadrado"<< endl;
	}

};

class Rectangle: public Shape{
private:
	string nombre;
	string tamano;
	string color;
public:
	Rectangle(){
		nombre = "Rectangulo";
		tamano = "2 cm.";
		color = "amarillo";
	}
	void draw(){
		cout<< "Se dibuja un rectangulo"<< endl;
	}
	void eraser(){
		cout<< "Se borra el rectangulo"<< endl;
	}
};

class Vacio: public Shape{
public:
	void draw(){
		cout<< "Se dibuja un rectangulo"<< endl;
	}
	void eraser(){
		cout<< "Se borra el rectangulo"<< endl;
	}
};

class GUIShapeFactory{
public:
	virtual Shape *getShape(char *) = 0;
};

class ShapeFactory: public GUIShapeFactory{
public:
	Shape *getShape(char *type){
		if(strcmp(type,"Circulo") == 0) return new Circle();
		else if(strcmp(type,"Cuadrado") == 0) return new Square();
		else if(strcmp(type,"Rectangulo") == 0) return new Rectangle();
		else return new Vacio();
	}
};

int main(){
	GUIShapeFactory* GUIfig;
	Shape *fig;
	GUIfig = new ShapeFactory;

	fig = GUIfig->getShape("Circulo");
	fig->draw();
	fig->eraser();
	fig = GUIfig->getShape("Cuadrado");
	fig->draw();
	fig->eraser();
	fig = GUIfig->getShape("Rectangulo");
	fig->draw();
	fig->eraser();

	return 0;
}