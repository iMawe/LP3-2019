#include <iostream>
#include "Turtle.h"
using namespace std;

class Component{
public:
	virtual void Operation(Turtle T) = 0;
	virtual void drawMe(Turtle T) = 0;
};

class ConcreteComponent: public Component{
public:
	void Operation(Turtle T){
		cout<<" ConcreteComponent"<<endl;
		T.set_color(100,100,130);
    	T.forward(100);
    	T.forward(90);
    	T.forward(30);
	}
	void drawMe(Turtle T){
    	T.set_color(100,100,130);
    	T.forward(100);
    	T.forward(90);
    	T.forward(30);
    }
};

class Decorator : public Component{
private:
	Component *comp;
public:
	Decorator(Component *obj){
		comp = obj;
	}
	void Operation(Turtle T){
		comp->Operation(T);
	}
};

class ConcreteDecoratorA : public Decorator{
public:
	ConcreteDecoratorA(Component *obj) : Decorator(obj){
	}
	void Operation(Turtle T){
		Decorator::Operation(T);		
		cout << " ConcreteDecoratorA" << endl;
		T.set_color(200,130,130);
    	T.forward(100,100);
    	T.forward(90,45);
    	T.forward(30,95);
	}
	void drawMe(Turtle T){
		T.set_color(200,130,130);
    	T.forward(100,100);
    	T.forward(90,45);
    	T.forward(30,95);
    }
};

class ConcreteDecoratorB : public Decorator{
public:
	ConcreteDecoratorB(Component *obj) : Decorator(obj){
	}

	void Operation(Turtle T){
		Decorator::Operation(T);
		cout << " ConcreteDecoratorB" << endl;

		T.forward(100,100);
    	T.forward(90,45);
    	T.forward(30,95);
	}
	void drawMe(Turtle T){
    	T.forward(100,100);
    	T.forward(90,45);
    	T.forward(30,95);
	}
};

int main(int argc, char **argv){

	
	Turtle T(700,500);
	T.display(argc,argv);
	T.move(250,250);
	Component *myComponent = new ConcreteDecoratorA(new ConcreteDecoratorB(new ConcreteComponent ()));
	myComponent->Operation(T);
	

    glutMainLoop();	
    return 0;
}



/*#include <iostream>
#include "plano.h"
using namespace std;

class Component{
public:
	virtual void Operation(plano p) = 0;
	virtual void drawMe(plano p) = 0;
};

class ConcreteComponent:public Component{
public:
	void Operation(plano p){
		cout<<"pistola"<<endl;
		p.set_color(100,100,130);
      p.forward(100);
      p.left(90);
      p.forward(30);
	}
	void drawMe(plano p){
      p.set_color(100,100,130);
      p.forward(100);
      p.left(90);
      p.forward(30);
    }
};

class Decorator : public Component{
private:
	Component *comp;
public:
	Decorator(Component *obj){
		comp = obj;
	}
	void Operation(plano p){
		comp->Operation(p);
	}
};

class ConcreteDecoratorA : public Decorator{

public:
	ConcreteDecoratorA(Component *obj) : Decorator(obj){
		
	}
	void Operation(plano p){
		Decorator::Operation(p);
		cout << " elementa" << endl;
		p.set_color(200,130,130);
      p.forward(100);
      p.left(90);
      p.forward(30);
	}
	void drawMe(plano p){
	  p.set_color(200,130,130);
      p.forward(100);
      p.left(90);
      p.forward(30);
    }
};

class ConcreteDecoratorB : public Decorator{
public:
	ConcreteDecoratorB(Component *obj) : Decorator(obj){
	}
	void Operation(plano p){
		Decorator::Operation(p);
		cout << " elementb" << endl;
		p.forward(100);
	      p.left(90);
	      p.forward(30);
	}
	void drawMe(plano p){
      p.forward(100);
      p.left(90);
      p.forward(30);
    }
};

int main(int argc, char **argv){

	plano p(700,500);
	p.display(argc,argv);
	ConcreteComponent* po=new ConcreteComponent();
	Component *myComponent = new ConcreteDecoratorA(new ConcreteDecoratorB(po));
	myComponent->Operation(p);
	myComponent->drawMe(p);

	while(1);
    glutMainLoop();
return 0;
}*/

