#ifndef BUCH_H
#define BUCH_H
#include<string>
#include<iostream>
#include <vector>
#include "exemplar.h"

using namespace std;

class Buch
{
private:
    string isbn;
    vector<Exemplar> exemplare;
public:
    Buch();
    Buch(string isbn);
    void addExemplar(Exemplar newExemplar);
    void print();
    int getAnzahlExemplare();
    string getISBN();
    bool tryDeleteExemplar(int id);
    bool tryAusleihenExemplar(int id, string name);
    bool tryZurueckgebenExemplar(int id);
};

#endif // BUCH_H
