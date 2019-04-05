#include <iostream>
#include <string>
#include "Cripto2.h"

using namespace std;

int main(){
	Cripto ce(3);
	string str = "From fairest creatures we desire increase";

	str = ce.encriptar(str);
	cout<< str<< endl;
	str = ce.desencriptar(str);
	cout<< str<< endl;
	
	return 0;
}