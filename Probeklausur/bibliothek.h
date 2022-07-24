#ifndef BIBLIOTHEK_H
#define BIBLIOTHEK_H
#include "buch.h"
#include <string>
#include <vector>

using namespace std;

class Bibliothek
{
private:
    vector<Buch> buecher;
    bool isStorageFree(int newExemplareCount);
public:
    Bibliothek();
    void addBuch(string isbn, int anzahlExemplare);
    void addExemplar(string isbn);
    void print();
    static int idCounter;
    void deleteExemplar(int id);
    void exemplarAusleihen(int id, string name);
    void exemplarZurueckgeben(int id);
};

#endif // BIBLIOTHEK_H
