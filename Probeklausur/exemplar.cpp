#include "exemplar.h"

Exemplar::Exemplar()
{

}

Exemplar::Exemplar(int id){
    this->id = id;
    this->ausgeliehen = false;
}

void Exemplar::print(){

    cout << "ID: " << this->id << " ";
    if(this->ausgeliehen){
       cout << "(ausgeliehen von: " << this->ausgeliehenVon << ")" << endl;
    }else{
        cout << endl;
    }
}

int Exemplar::getID(){
    return this->id;
}

bool Exemplar::ausleihen(string name){
    if(this->ausgeliehen == true){
        return false;
    }
    this->ausgeliehen = true;
    this->ausgeliehenVon = name;
    return true;
}

void Exemplar::zurueckgeben(){
    this->ausgeliehen = false;
    this->ausgeliehenVon = "";
}
