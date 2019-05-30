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



class Color{
public:
	virtual void fill() = 0;
};

class Red: public Color{
private:
	string nombre;
public:
	Red(){
		nombre = "Rojo";
	}
	void fill(){
		cout<< "Se pinta color rojo"<< endl;
	}
};

class Blue: public Color{
private:
	string nombre;
public:
	Blue(){
		nombre = "Azul";
	}
	void fill(){
		cout<< "Se pinta color azul"<< endl;
	}

};

class White: public Color{
private:
	string nombre;
public:
	White(){
		nombre = "Blanco";
	}
	void fill(){
		cout<< "Se pinta color blanco"<< endl;
	}
};



class FabricaAbstracta{
public:
	virtual Shape getShape(char *type) = 0;
	virtual Color getColor(char *type) = 0;
};

class GUIShapeFactory{
public:
	virtual Shape *getShape(char *) = 0;
};

class ShapeFactory: public GUIShapeFactory, FabricaAbstracta{
public:
	Shape *getShape(char *type){
		if(strcmp(type,"Circulo") == 0) return new Circle();
		else if(strcmp(type,"Cuadrado") == 0) return new Square();
		else if(strcmp(type,"Rectangulo") == 0) return new Rectangle();
	}
	Color *getColor(char* type){
		return NULL;
	}
};


class GUIColorFactory{
public:
	virtual Color *getColor(char *) = 0;
};

class ColorFactory: public GUIColorFactory, FabricaAbstracta{
public:
	Color *getColor(char *type){
		if(strcmp(type,"Rojo") == 0) return new Red();
		else if(strcmp(type,"Azul") == 0) return new Blue();
		else if(strcmp(type,"Blanco") == 0) return new White();
	}
	Shape *getShape(char* type){
		return NULL;
	}
};

class FabricaProduct{
	FabricaAbstracta *getFactory(char* type){
		if(strcmp(type, "Shape") == 0) return new ShapeFactory();
		else if(strcmp(typw, "Color") == 0) return new ColorFactory();
		return NULL;
	}
}

int main(){
	/*GUIShapeFactory* GUIfig;
	GUIColorFactory* GUIcol;
	Shape *fig;
	Color *col;
	GUIfig = new ShapeFactory;*/
	FabricaAbstracta *fabricaShp = FabricaProduct->getFactory("Shape");
	Shape *fig = fabricaShp->getShape("Cuadrado");

	fig->draw();
	fig->eraser();
	

	return 0;
}