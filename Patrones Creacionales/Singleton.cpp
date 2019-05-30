#include <iostream>

using namespace std;

class Particula{
private:
	static Particula* Instancia;
	Particula(){}
public:
	static Particula *getInstancia(){
		if(Instancia == NULL){
			Instancia = new Particula();
		}
		return Instancia;
	}
	void creada(){
		cout<< "Fue creada"<< endl;
	}
	void noCreada(){
		cout<< "No fue creada"<< endl;
	}
};

Particula *Particula::Instancia = 0;

int main(){
	Particula *p = p->getInstancia();

	p->creada();
	p->noCreada();
	
	return 0;
}
