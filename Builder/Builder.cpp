#include <iostream>
#include <string>

using namespace std;

class VRam{
    public:
        string c;
};

class Procesador{
    public:
        string nom;
};

class Ram{
    public:
        string c;
};

class PC{
public:
    Procesador* pro;
    VRam*  vr;
    Ram* rm;

    PC(){
        rm = new Ram();
        rm->c = "vacio";
        pro = new Procesador();
        pro->nom ="vacio";
        vr = new VRam();
        vr->c = "vacio";
            
    }
    
    void Caracteristicas(){
        cout << "Procesador:" << pro->nom << endl;
        cout << "VRam:" << vr->c << endl;
        cout << "Ram:" << rm->c << endl;
    }
};

class Builder{
public:
    virtual Procesador* get_Procesador() = 0;
    virtual VRam* get_VRam() = 0;
    virtual Ram* get_Ram() = 0;
};

class Director{
private:
    Builder* buil;
public:
    void setBuilder(Builder* b){
        buil = b;
    }

    PC* set_PC(string A[], int n){
            
            
            PC* pc = new PC();
            for(int i = 0; i < n; i++){            
                if(A[i] == "core i5" or A[i] == "amd ryzen") pc->pro->nom = A[i];
                if(A[i] == "8gb ram" or A[i] == "16gb ram") pc->rm->c = A[i];
                if(A[i] == "4gb vram" or A[i] == "12gb ram") pc->vr->c = A[i];
            }
            return pc;
        }

    PC* get_PC(){
        PC* pc = new PC();
        pc->pro = buil->get_Procesador();
        pc->vr = buil->get_VRam();
        pc->rm = buil->get_Ram();
        return pc;
    }
};


class Standard : public Builder{
private:
    Procesador* pro;
    VRam*  vr;
    Ram* rm;
public:
    Standard(){
        pro = new Procesador();
        pro->nom ="core i5";
        vr = new VRam();
        vr->c = "4bg vram";
        rm = new Ram();
        rm->c = "4gb ram";
    }
    Procesador* get_Procesador(){
        return pro;
    }
    VRam* get_VRam(){
        return vr;
    }
    Ram* get_Ram(){
        return rm;
    }
    void set_Procesador(string pro1){
        pro->nom = pro1;
    }
    void set_vram(string c1){
        vr->c = c1;
    }
    void set_ram(string c1){
        rm->c = c1;
    }
};


class Expensive : public Builder{
private:
    Procesador* pro;
    VRam*  vr;
    Ram* rm;
public:
    Expensive(){
        pro = new Procesador();
        pro->nom ="amd ryzen";
        vr = new VRam();
        vr->c = "16gb ram";
        rm = new Ram();
        rm->c = "12gb ram";
    }
    Procesador* get_Procesador(){
        return pro;
    }
    VRam* get_VRam(){
        return vr;
    }
    Ram* get_Ram(){
        return rm;
    }
    void set_Procesador(string pro1){
        pro->nom = pro1;
    }
    void set_vram(string c1){
        vr->c = c1;
    }
    void set_ram(string c1){
        rm->c = c1;
    }
};


int main(){
    string arr[]={"AMD Ryzen", "intel inside", "4gb vram", "8gb ram"};

    PC* pc; 
    Director dire;

    Standard Lenovo;
    Expensive MSI;

    Lenovo.set_Procesador("intel i3");
    Lenovo.set_ram("6");
    Lenovo.set_vram("2");

    MSI.set_Procesador("intel i9");
    MSI.set_vram("16");
    MSI.set_ram("64");

    cout << "Lenovo" << endl;
    dire.setBuilder(&Lenovo); 
    pc = dire.get_PC();
    pc->Caracteristicas();
    cout << endl;
    cout << "MSI" << endl;
    dire.setBuilder(&MSI);
    pc = dire.get_PC();
    pc->Caracteristicas();

    cout<<endl<<endl;
    pc=dire.set_PC(arr,4);
    pc->Caracteristicas();

    return 0;
}