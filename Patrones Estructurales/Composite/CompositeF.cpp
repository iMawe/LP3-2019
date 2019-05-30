#include <iostream>
#include <vector>
using namespace std;

class Fileabstract{
    public:
        virtual void listar() = 0;
        virtual void dibujar() = 0;
};


class File: public Fileabstract{
private:
	string nombre;
	
public:
    File(string nom=""){
    	nombre=nom;
    }

    ~File(){}
    void listar(){
    	cout<<nombre<<'\t';
    }
    void set_name(string nom){
    	nombre=nom;
    }
    string get_nombre(){
    	return nombre;
    }
    void dibujar(){}
};



class directory: public Fileabstract{
private:
	string nombre;
	vector<Fileabstract*> Files;

public:
    directory(string nom=""){
    	nombre=nom;
    }
    ~directory(){}
    void add(Fileabstract* Fi){
    	Files.push_back(Fi);
    }

    void listar(){
    	cout<<nombre<<'\t';
    }
    void set_name(string nom){
    	nombre=nom;
    }
    string get_nombre(){
    	return nombre;
    }
    void dibujar(){
    	for(int i=0; i<Files.size();i++){
    			cout<<nombre;
        		cout<<" -> ";
        		Files[i]->listar();
        		cout<<endl;
        }
       	for(int i=0; i<Files.size();i++){

					Files[i]->dibujar();	
        } 
    }
    
    void dibujararbol(){
    	dibujar();
    }
};


int main(){

	directory direc[4];
	File files[6];

	files[0].set_name("file0");
	files[1].set_name("file 1");
	files[2].set_name("file 2");
	files[3].set_name("file 3");
	files[4].set_name("file 4");
	files[5].set_name("file 5");

	direc[0].set_name("directory 0");
	direc[1].set_name("directory 1");
	direc[2].set_name("directory 2");
	direc[3].set_name("directory 3");

	direc[0].add(&files[0]);
	direc[0].add(&files[1]);
	direc[0].add(&direc[1]);
	direc[1].add(&files[2]);
	direc[1].add(&direc[2]);
	direc[1].add(&direc[3]);
	direc[3].add(&files[3]);
	direc[3].add(&files[4]);

	direc[0].dibujararbol();

	return 0;
}