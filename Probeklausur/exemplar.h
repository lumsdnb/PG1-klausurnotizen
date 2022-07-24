#ifndef EXEMPLAR_H
#define EXEMPLAR_H
#include<iostream>
using namespace std;

class Exemplar
{
private:
    int id;
    bool ausgeliehen;
    string ausgeliehenVon;

public:
    Exemplar();
    Exemplar(int id);
    void print();
    int getID();
    bool ausleihen(string name);
    void zurueckgeben();
};

#endif // EXEMPLAR_H
