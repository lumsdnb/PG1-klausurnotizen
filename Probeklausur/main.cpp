#include <iostream>
#include "bibliothek.h"
#include <string>
using namespace std;

int parse_digit(char digit) {
    return digit - '0';
}

int main()
{
    Bibliothek bib;
    bib.addBuch("TEST", 3);
    bib.print();
    char menuInput;
    while(menuInput != 'x'){
        cout << "(b) Neues Buch hinzufügen" << endl;
        cout << "(a) Anzeigen aller Bücher" << endl;
        cout << "(e) Neues Exemplar hinzufügen" << endl;
        cout << "(l) Exemplar löschen" << endl;
        cout << "(r) Exemplar ausleihen" << endl;
        cout << "(z) Exemplar zurueckgeben" << endl;
        cout << "(x) Beenden" << endl;
        cin >> menuInput;
        switch(menuInput){
        case 'b':{
            cout << "ISBN eingeben: " ;
            string isbn;
            cin >> isbn;
            cout << "Anzahl Exemplare eingeben: ";
            int anzahl;
            cin >> anzahl;
            bib.addBuch(isbn, anzahl);
            break;
        };
        case 'a':{
            bib.print();
            break;
        };
        case 'e':{
          cout << "ISBN eingeben: ";
          string isbn;
          cin >> isbn;
          bib.addExemplar(isbn);
          break;
        };
        case 'l':{
            cout << "ID eingeben: ";
            int id;
            cin >> id;
            bib.deleteExemplar(id);
            break;
        };
        case 'r':{
            cout << "ID einegen: ";
            int id;
            cin >> id;
            cout << "Name eingeben: ";
            string name = "";
            cin >> name;
            bib.exemplarAusleihen(id, name);
            break;
        };
        case 'z':{
            cout << "ID einegen: ";
            int id;
            cin >> id;
            bib.exemplarZurueckgeben(id);
            break;
        }
        case 'X':{
            menuInput = 'x';
            break;
        }
        }
    }
    return 0;
}
