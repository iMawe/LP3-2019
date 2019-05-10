#include <iostream>
#include <string>

using namespace std;

class VRam{
    public:
        int c;
};

class Procesador{
    public:
        string nom;
};

class Ram{
    public:
        int c;
};

class PC{
public:
    Procesador* pro;
    VRam*  vr;
    Ram* rm;
    
    void caracteristicas(){
        cout << "Procesador:" << pro->nom << endl;
        cout << "VRam:" << vr->c << endl;
        cout << "Ram:" << rm->c << endl;
    }
};

class builder{
public:
    virtual Procesador* get_Procesador() = 0;
    virtual VRam* get_VRam() = 0;
    virtual Ram* get_Ram() = 0;
};

class director{
private:
    builder* buil;
public:
    void setbuilder(builder* b){
        buil = b;
    }

    PC* get_PC(){
        PC* comp = new PC();
        comp->pro = buil->get_Procesador();
        comp->vr = buil->get_VRam();
        comp->rm = buil->get_Ram();
        return comp;
    }
};


class expensive : public builder{
public:
    VRam* get_VRam(){
        VRam* v = new VRam();
        v->c = 6;
        return v;
    }

    Procesador* get_Procesador(){
        Procesador* pro = new Procesador();
        pro->nom = "Core i9";
        return pro;
    }

    Ram* get_Ram(){
        Ram* r = new Ram();
        r->c = 16;
        return r;
    }
};


class standard : public builder{
public:
    VRam* get_VRam(){
        VRam* v = new VRam();
        v->c = 2;
        return v;
    }

    Procesador* get_Procesador(){
        Procesador* pro = new Procesador();
        pro->nom = "core i5 8va generacion";
        return pro;
    }

    Ram* get_Ram(){
        Ram* r = new Ram();
        r->c = 8;
        return r;
    }
};


int main(){
    PC* comp; 
    director dire;
    expensive MSI;
    standard Lenovo;
    cout << "MSI" << endl;

    dire.setbuilder(&MSI); 
    comp = dire.get_PC();
    comp->caracteristicas();
    cout << endl;
    cout << "Lenovo" << endl;

    dire.setbuilder(&Lenovo);
    comp = dire.get_PC();
    comp->caracteristicas();

    return 0;
}