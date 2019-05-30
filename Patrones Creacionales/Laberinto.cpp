#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class Obstaculo{
protected:
	string tipoO;
	int x, y;
public:
	virtual void printObstaculo() = 0;
	static Obstaculo* createObstaculoBom(int x1, int y1);
	static Obstaculo* createObstaculoEn(int x1, int y1);
};

class ObstaculoBom: public Obstaculo{
public:
	ObstaculoBom(int x1, int y1){
		tipoO = "Obstaculo Bomba ";
		x = x1;
		y = y1;
	}
	void printObstaculo(){
		cout<< tipoO<< "X = "<< x<< " Y = "<< y<< endl;
	}
};

class ObstaculoEn: public Obstaculo{
public: 
	ObstaculoEn(int x1, int y1){
		tipoO = "Obstaculo Bomba ";
		x = x1;
		y = y1;
	}
	void printObstaculo(){
		cout<< tipoO<< "X = "<< x<< " Y = "<< y<< endl;
	}
};


class Puerta{
protected:
	string tipoP;
	int x, y;

public:
	virtual void printPuerta() = 0;
	static Puerta* createPuertaBom(int x1, int y1);
	static Puerta* createPuertaEn(int x1, int y1);
};

class PuertaEn : public Puerta{
public:
	PuertaEn(int x1, int y1){
		tipoP = "Puerta Encantada ";
		x = x1;
		y = y1;
	}
	void printPuerta(){
		cout<< tipoP<< "X = "<< x<< " Y = "<< y<< endl;
	}
};

class PuertaBom: public Puerta{
public:
	PuertaBom(int x1, int y1){
		tipoP = "Puerta Bomba ";
		x = x1;
		y = y1;
	}
	void printPuerta(){
		cout<< tipoP<< "X = "<< x<< " Y = "<< y<< endl;
	}
};


Obstaculo* Obstaculo::createObstaculoBom(int x1, int y1){
	return new ObstaculoBom(x1, y1);
}

Obstaculo* Obstaculo::createObstaculoEn(int x1, int y1){
	return new ObstaculoEn(x1, y1);
}

Puerta* Puerta::createPuertaBom(int x1, int y1){
	return new PuertaBom(x1, y1);
}

Puerta* Puerta::createPuertaEn(int x1, int y1){
	return new PuertaEn(x1, y1);
}




class Laberinto{
protected:
	vector<Obstaculo*> labObstaculo;
	vector<Puerta*> labPuerta;

public:
	virtual void createPuerta(int x1, int y1) = 0;
	virtual void createObstaculo(int x1, int y1) = 0;
	vector<Puerta*> getPuerta(){
		return labPuerta;
	}
	vector<Obstaculo*> getObstaculo(){
		return labObstaculo;
	}
	void print(){
		for(int i = 0; i < labObstaculo.size(); i++) labObstaculo[i] -> printObstaculo();
		for(int i = 0; i < labPuerta.size(); i++) labPuerta[i] -> printPuerta();
	}
};

class LaberintoEn:public Laberinto{
public:
	LaberintoEn(){}
	~LaberintoEn(){}
	void createPuerta(int x1, int y1){
		labPuerta.push_back(Puerta::createPuertaEn(x1, y1));
	}
	void createObstaculo(int x1, int y1){
		labObstaculo.push_back(Obstaculo::createObstaculoEn(x1, y1));
	}
};

class LaberintoBom: public Laberinto{
public:
	LaberintoBom(){}
	~LaberintoBom(){
	}
	void createPuerta(int x1, int y1){
		labPuerta.push_back(Puerta::createPuertaBom(x1, y1));
	}
	void createObstaculo(int x1, int y1){
		labObstaculo.push_back(Obstaculo::createObstaculoBom(x1, y1));
	}
};


int main() { 
    LaberintoEn lab;
    lab.createPuerta(10, 10);
    lab.createPuerta(15, 0);
    lab.createPuerta(12, 5);
    lab.createPuerta(11, 3);

    lab.createObstaculo(20, 20);
    lab.createObstaculo(25, 20);
    lab.createObstaculo(22,25);
    lab.createObstaculo(21,23);


    
    lab.print ();

    LaberintoBom lab1;
    lab1.createPuerta(10, 10);
    lab1.createPuerta(15, 0);
    lab1.createPuerta(12, 5);
    lab1.createPuerta(11, 3);

    lab1.createObstaculo(20, 20);
    lab1.createObstaculo(25, 20);
    lab1.createObstaculo(22,25);
    lab1.createObstaculo(21,23);
    lab1.print();
    return 0;
} 