#include <iostream>
using namespace std;

class Laberinto{
private:

public:
	Laberinto(){
		for(int i = 0; i < 100; i++)
			for(int j = 0; j < 100; j++)
				labe[i][j] = " ";
	}
	void createLaberito();
	void addPuerta();
	void addObstaculo();
}

class Factory{
public:
	virtual Laberinto *createLaberito();
	virtual Laberinto *addPuerta();
	virtual Laberinto *addObstaculo();
}

class Encantado{
private:
	
}
class Bomba{

}