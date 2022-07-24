#include "bibliothek.h"
#include "buch.h"
#include "exemplar.h"

Bibliothek::Bibliothek()
{

}

void Bibliothek::addBuch(string isbn, int anzahlExemplare)
{
    if(!isStorageFree(anzahlExemplare)){
        cout << "Vorgang nicht möglich. Zu viele Exemplare" << endl;
        return;
    }
    Buch newBook = Buch(isbn);
    for(int i= 0; i < anzahlExemplare; i++){
        Exemplar newExemplar = Exemplar(this->idCounter);
        newBook.addExemplar(newExemplar);
        this->idCounter++;
    }
    this->buecher.push_back(newBook);
}

void Bibliothek::addExemplar(string isbn){
    if(!isStorageFree(1)){
        cout << "Vorgang nicht möglich. Zu viele Exemplare" << endl;
        return;
    }
    Exemplar newExemplar = Exemplar(this->idCounter); // Create the new Exemplar
    this->idCounter++;
    for(int i = 0; i < buecher.size(); i++){
        if(buecher[i].getISBN() == isbn){
            buecher[i].addExemplar(newExemplar);
            return;
        }
    }
    Buch newBook = Buch(isbn);
    newBook.addExemplar(newExemplar);
    this->buecher.push_back(newBook);
}

void Bibliothek::deleteExemplar(int id){
    for(int i = 0; i < buecher.size(); i++){
        if(buecher[i].tryDeleteExemplar(id)){
            if(buecher[i].getAnzahlExemplare() <= 0){
                buecher.erase(buecher.begin() + i);

            }
            return;
        }
    }
    cout << "Kein Exemplar mit dieser ID gefunden" << endl;
}

void Bibliothek::exemplarAusleihen(int id, string name){
       for(int i = 0; i < buecher.size(); i++){
           if(buecher[i].tryAusleihenExemplar(id, name)){
               return;
           }
       }
       cout << "ID existiert nicht" << endl;
}

void Bibliothek::exemplarZurueckgeben(int id){
    for(int i = 0; i < buecher.size(); i++){
        if(buecher[i].tryZurueckgebenExemplar(id)){
            return;
        }
    }
    cout << "ID existiert nicht" << endl;
}

void Bibliothek::print(){
    for(int i = 0; i < buecher.size(); i++){
        buecher[i].print();
    }
}



bool Bibliothek::isStorageFree(int newExemplareCount){
    // Gesamtanzahl Exemplare die bereits vorhanden sind
    int anzahl = 0;
    for(int i = 0; i < buecher.size(); i++){
        anzahl += buecher[i].getAnzahlExemplare();
    }
    if((anzahl + newExemplareCount) > 10){
        return false;
    }else{
        return true;
    }

}

int Bibliothek::idCounter = 1000;
