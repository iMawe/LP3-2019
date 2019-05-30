#include <iostream>
#include <vector>
using namespace std;

// 2. Create an "interface" (lowest common denominator)

class Componente{
public:
    virtual void print() = 0;
};

class Simple: public Componente{
private:
  string name;
  int tam;
  int num;

public:
  Simple(string na, int t, int n){
    name = na;
    tam = t;
    num = n;
  }
  void print(){
    cout<< name<< " "<< num<< " Size: "<< tam<< " --- ";
  }
};

class Compuesto: public Componente{
private:
    vector < Componente * > children;
public:
  void add(Componente *ele){
    children.push_back(ele);
  }
  
  void print(){
    for (int i = 0; i < children.size(); i++){
      children[i]->print();
    }
  }
};

int main(){
  Compuesto containers[4];

  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 3; j++)
      containers[i].add(new Simple("File", 20, i *3+j));
  }

  for (int i = 1; i < 4; i++)
    containers[0].add(&(containers[i]));

  for (int i = 0; i < 4; i++){
    containers[i].print();
    cout<< endl;
  }
  return 0;
}