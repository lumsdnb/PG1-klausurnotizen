//dreistellige zahl in einzelteile zerlegen

#include <iostream>
using namespace std;

int main()
{
    int zahlMitDreiStellen;
    cout << "Enter a 3 digit number: ";
    cin >> zahlMitDreiStellen;

    int stelleEins = zahlMitDreiStellen / 100;
    int stelleZwei = (zahlMitDreiStellen / 10) % 10;
    int stelleDrei = zahlMitDreiStellen % 10;

    cout << "1: " << stelleEins << endl
         << "2: " << stelleZwei << endl
         << "3: " << stelleDrei << endl << endl;
    return 0;
}

//kapital berechnen
int anfangskapitalmain()
{
    float anfangsKapital;
    float prozentSatz;
    int laufZeitJahre;
    float endKapital;

    cout << "Was ist das Startkapital? ";
    cin >> anfangsKapital;
    cout << "Zu welchem Zinssatz? (in Prozent) ";
    cin >> prozentSatz;
    cout << "Wie viele Jahre soll angelegt werden? ";
    cin >> laufZeitJahre;
    cout << endl << "Jahr 0: " << anfangsKapital << endl;
    for (int i = 0; i < laufZeitJahre; ++i) {
        endKapital = anfangsKapital + ((anfangsKapital / 100) * prozentSatz);
        anfangsKapital = endKapital;
        cout << "Jahr " << i+1 << ": " << endKapital << endl;
    }
    cout << endl;
    return 0;
}


// datentypen
unsigned int tempNumber;
//zeiger
Typbezeichnung * name;

//zeiger auf addressen referenz von x setzen 
int *p; //zeiger erstellen
int x = 420;
p = &x; //addresse von 
// mit * kann auch dereferenziert werden, bissl weird aber naja
*p = 420;

//zeiger auf strukturen
tupel *ps;
ps = &wert;
ps->setValue(23); // methode mit zeiger aufgerufen
this->val; // verweis auf objekt was aufgerufen wurde
return *this; // kann als objektrückgabe verwendet werden

//zeiger in funktionsrückgabe
int * max(int *a, int *b) {
    if (*a > *b)
        return a;
    else
        return b;
}
int main() {
    int x,y;
    int *pi;
    cout << "Zwei Integer eingeben: ";
    cin >> x >> y;
    pi = max(&x, &y);
    cout << *pi << endl;
}

//speicher in heap legen (muss am end wieder gelöscht werden)
int *p;
p = new int;

//array dynamisch erzeugen <---------- wichtig
int *pa;
pa = new int[3];
pa[1] = 42;
//array löschen (auch wichtig am ende)
delete [] pa;



//ist array sortiert?

    bool isItSorted(int length, int array[]){
        bool isSorted=true;
        for (int i = 0; i < length; i++) {
            if (i!=length-1){ //ignore last number, should be fine if loop gets this far
                //if the next value is equal or bigger than the current one
                if(array[i+1] >= array[i]){
                    isSorted=true;
                }
                else {
                    isSorted=false;
                    break;
                }
            }
        }
        return isSorted;
    }


    int main()
    {
        int randomNumbers [5] = {1,200,3,4,10};

        //show array
        cout << "array: ";
        for (int a:randomNumbers){
            cout << a << " ";
        }
        cout << endl <<endl;

        //check sort state and respond accordingly
        if (isItSorted(5,randomNumbers)){
            cout << "is sorted :)";
        } else cout << "is unsorted :(";
        cout << endl << endl;
        return 0;
    }


//a) Implementieren Sie eine Funktion, die einen Wert vom Typ Block auf den zugehörigen Wochentag vom Typ Tag abbildet!
//b) Implementieren Sie eine Funktion, die überprüft, ob ein Block auf einen Dienstagnachmittag fällt!

// ---------- header ----------

#ifndef BLOCKBEZEICHNUNGEN_H
#define BLOCKBEZEICHNUNGEN_H

enum class Block {
 Mo1, Mo2, Mo3, Mo4, Mo5, Mo6, Mo7,
 Di1, Di2, Di3, Di4, Di5, Di6, Di7,
 Mi1, Mi2, Mi3, Mi4, Mi5, Mi6, Mi7,
 Do1, Do2, Do3, Do4, Do5, Do6, Do7,
 Fr1, Fr2, Fr3, Fr4, Fr5, Fr6, Fr7,
 Sa1, Sa2, Sa3, Sa4, Sa5, Sa6, Sa7
};
enum class Tag {
 MO, DI, MI, DO, FR, SA
};

#endif // BLOCKBEZEICHNUNGEN_H

// ---------- main ----------

Tag welcherWochentag (Block b){
    
    int t = static_cast<int>(b)%7;
    // day/7
    // static_cast<Tag>(day)
    // (Tag) day

    return static_cast<Tag>(t);
}

bool istAmDienstagNachmittag(Block b){
    int temp = static_cast<int>(b); //von block enum zu int nur für
    if (temp >=10 && temp <=13){    //interne berechnung in funktion
        return true;
    }
    else return false;
}

int main()
{
    Block testBlock = Block::Di6;
    Tag testWochentag = welcherWochentag(testBlock);

    if (istAmDienstagNachmittag(testBlock)){
        cout << "test ist am dienstagnachmittag!" << endl;
    }

    if (testWochentag == welcherWochentag(testBlock)){
        cout << "test ist am dienstag!" << endl;
    }

    return 0;
}







// Implementieren Sie das folgende Menü, indem Sie jedem Menü-Punkt eine TemplateFunktion zuordnen:
// Werte verwalten- Auswahl
//  (1) Werte per Hand eingeben
//  (2) Werte generieren lassen
//  (3) Werte ausgeben
//  (4) Wert suchen
//  (5) Auf Sortierung prüfen
//  (x) Ende

// Benutzen Sie Referenz-Übergabe und Read-Only-Parameter an den Stellen, wo es Sinn
// macht. Sorgen Sie dafür, dass man mit int, float und string arbeiten kann. (konvertierungs konstruktor?)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
vector<T> input (vector<T> &vector) {
    T input;
    cout << "Geben Sie einen Wert ein: " << endl;
    cin >> input;
    cout << endl;
    vector.push_back (input);
    return vector;
}

template <typename T>
void generate(vector<T> &vector) {
    T random;
    random = rand()%100;
//    if (typeid(T) == typeid(int) || typeid(T) == typeid(float)){
        vector.push_back (random);
//    }
//    else if (typeid(T) == typeid(string)){
//        cout << "es kann nichts generiert werden." << endl;
//    }
}

template <typename T>
void output (vector<T> &vector) {
    cout << "Ihre Werte: " << endl;
    for (int i = 0; i < (int) vector.size(); i++) {
        cout << vector [i] << endl;
    }
}

template <typename T>
int search (vector<T> vector) {
    T searched;
    cout << "Wonach suchen Sie?" << endl;
    cin >> searched;
    cout << endl;
    int Index = -1;
    for (int j = 0; j < (int) vector.size(); j++) {
        if (vector [j] == searched){
            Index = j;
            cout << "Der gesuchte Wert ist an Stelle " << Index << endl;
            break;
        }
        cout << "wert nicht gefunden"<< endl;
        return -1;
    }
    return Index;
}

template <typename T>
bool Sorted (vector<T> vector) {
    for (int k = 0; k < (int) vector.size() - 1; k++){
        if (vector[k] > vector[k+1]) {
            return false;
        }
    }
    return true;
}

int main(){
    char menuSelection;
    vector<string> vector;
    while(true){
        cout << "Werte verwalten - Auswahl" << endl
             << "(1) Werte per Hand eingeben" << endl
             << "(2) Werte generieren lassen" << endl
             << "(3) Werte ausgeben" << endl
             << "(4) Wert suchen" << endl
             << "(5) Auf Sortierung pruefen" << endl
             << "(x) Ende" << endl;
        cin >> menuSelection;
        switch (menuSelection){
        case '1':
            input (vector);
            break;
        case '2':
            generate(vector);
            break;
        case '3':
            output (vector);
            break;
        case '4':
            search (vector);
            break;
        case '5':
            if (Sorted (vector)){
                cout << "Die Werte sind sortiert." << endl;
            }
            else {
                cout << "Die Werte sind nicht sortiert." << endl;
            }
            break;
        case 'x':
            cout << "bis bald" << endl;
            return 0;
        default:
            cout << "hier ist ein Fehler aufgetreten." << endl;
        }
    }
}



// ------------- objektvererbung ------------- 

class Geschenk
{
public:
    Geschenk();
    ~Geschenk();
    void getPrice();
    void setPrice(float p);
    virtual void einpacken() =0;
private:
    float price;
};

//kugel erbt, da ist auch virtuelle fn definiert

class Kugel : public Geschenk
{
public:
    Kugel();
    Kugel(float rad);
    void einpacken();
private:
    float radius;
};

//eindeutig zuweisbare gezählte objekte

class Kunde
{
    static int kundenCount;       //trackt, wie viele es gibt
    static int freieKundenNummer; //trackt, welche noch nicht benutzt wurden
    const int kundenNummer;       //nummer, die objekt zugewiesen wird
public:
    Kunde();
    ~Kunde();
    int getKundenNummer() const;
    void setName(const std::string n);
    const std::string getName();
private:
    std::string name;
};

//cpp (wichtig: nummern müssen vor funktionsdefinitionen initialisiert werden)

    #include "kunde.h"

    int Kunde::kundenCount=0;
    int Kunde::freieKundenNummer=1;
    Kunde::Kunde(): kundenNummer(freieKundenNummer++){ //initialisierungsliste
        kundenCount++;
    }


    Kunde::~Kunde()
    {
        kundenCount--;
    }
    //kein setter, system bestimmt kd nr automatisch

    int Kunde::getKundenNummer() const 
    {
        return kundenNummer;
    }

    void Kunde::setName(const std::string n)
    {
        name=n;
    }



//ablage mit zeigern

    //header
        class Ablage
        {
            int cnt=0;
        public:
            Ablage();
            void drauflegen(int x);
            void runternehmen();
            int top();
            Element *oben;
        private:

        };

        class Element
        {
        public:
            Element(int inhalt);
            int getInfo();
            Element *next;
        private:
            int info;
        };

    //cpp
        void Ablage::drauflegen(int x){
            // erzeuge neues Element
            Element *p = new Element(x);
            p->next = oben; // next-Wert wird initialisiert mit Positionszeiger
            // es wird also VOR dem aktuellen Element eingefügt
            oben = p;
            // Positionszeiger zeigt nun auf das neue Element
            // Zähler erhöhen
            cnt++;
        }

        void Ablage::runternehmen()
        {
            Element * tempEl;
            if (cnt == 0) tempEl = nullptr;
            else {
                tempEl = oben-> next;
                cnt --;
            }
            delete oben;
            oben = tempEl;
        }

        int Ablage::top()
        {
            return oben->getInfo();
        }

    //cpp element hat fast nix, ablage regelt struktur
        Element::Element(int inhalt)
        {
            info = inhalt;
        }

        int Element::getInfo(){
            return info;
        }
