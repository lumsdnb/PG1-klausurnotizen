#include "buch.h"

Buch::Buch()
{

}

Buch::Buch(string isbn){
    this->isbn = isbn;
}

void Buch::print(){
    cout << "ISBN: " << this->isbn << endl;
    for(int i = 0; i < exemplare.size(); i++){
        exemplare[i].print();
    }
}

void Buch::addExemplar(Exemplar newExemplar){
    this->exemplare.push_back(newExemplar);
}

int Buch::getAnzahlExemplare(){
    return this->exemplare.size();
}

string Buch::getISBN(){
    return this->isbn;
}

bool Buch::tryDeleteExemplar(int id){
    for(int i = 0; i < exemplare.size(); i++){
        if(exemplare[i].getID() == id){
            exemplare.erase(exemplare.begin() + i);
            return true;
        }
    }
    return false;
}

bool Buch::tryAusleihenExemplar(int id, string name){
    for(int i = 0; i < exemplare.size(); i++){
        if(exemplare[i].getID() == id){
            if(exemplare[i].ausleihen(name)){
                cout << "Exemplar ausgeliehen" << endl;
                return true;
            }else{
                cout << "Exemplar bereits ausgeliehen" << endl;
                return true;
            }
        }
    }
    return false;
}


bool Buch::tryZurueckgebenExemplar(int id){
    for(int i = 0; i < exemplare.size(); i++){
        if(exemplare[i].getID() == id){
            exemplare[i].zurueckgeben();
            return true;
        }
    }
    return false;
}
