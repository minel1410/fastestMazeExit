// Funkcije.cpp

#include "Funkcije.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <iomanip>
#include <algorithm>

// Implementacije funkcija iz Funkcije.h

using namespace std;

vector<vector<int>> napraviMatricu(const string& filename, vector<pair<char, int>>& slovo_broj) {

    vector<vector<int>>matrica;
    ifstream file(filename);

    //U slucaju da se fajl ne moze otvoriti ispisuje se greska.
    if (!file.is_open()) {
        cout << "Ne moze se otvoriti fajl: " << filename << endl;
        return {};
    }

    string line;

    //U ovom dijelu pravimo matricu identicnog izgleda kao fajl
    //Na osnovu te matrice pravimo binarni labirint
    while (getline(file, line)) {
        istringstream iss(line);
        vector<int> red;
        string broj;

        while (getline(iss, broj, ','))
            red.push_back(stoi(broj));


        matrica.push_back(red);
    }


    if(matrica[0][0] % 2 != 0){
        cout << "Prvi broj u fajlu mora biti paran"<<endl;
        return {};
    }
    if(matrica[2][0] < 1){
        cout<<"Broj kolona mora biti minimalno 1"<<endl;
        return {};
    }
    if(matrica[0][0] < 1 || matrica[0][0] > 26){
        cout<<"Labirint moze imati maksimalno 26, a minimalno 1 red."<<endl;
        return {};
    }
    if(matrica.size()-2 != (matrica[0][0]-2)/2){
        cout << "Svaki zid mora imati barem jedan prolaz i ne smije biti vise prolaza nego zidova"<<endl;
        return {};
    }
    for(int i = 2; i < matrica.size(); i++){
        if(matrica[i].size() > matrica[1][0]){
            cout<<"Zid moze imati prolaza koliko ima kolona maksimalno."<<endl;
            return {};
        }
    }
    for(int i = 2; i <matrica.size(); i++){
        for(int j = 0; j < matrica[i].size(); j++)
        if(matrica[i][j] > matrica[1][0]){
            cout<<"Prolaz ne moze biti u nepostojecoj koloni"<<endl;
            return {};
        }

    }

    //Petlja koja sluzi za pravljenje vektora konverzije iz slova u broj reda
    slovo_broj.push_back(make_pair('A', 0));
    char trenutno_slovo = 'B';
    int trenutni_red = 3;
    while (trenutno_slovo != 'Z') {
        slovo_broj.push_back(make_pair(trenutno_slovo, trenutni_red));
        trenutno_slovo++;
        trenutni_red++;
        slovo_broj.push_back(make_pair(trenutno_slovo , trenutni_red));
        trenutno_slovo++;
        trenutni_red+=3;
    }
    slovo_broj.push_back(make_pair(trenutno_slovo , trenutni_red));

    //Rezultujuca matrica kao binarni labirint
    vector<vector<int>>rez;

    int broj_redova = matrica[0][0]*2;
    int broj_kolona = matrica[1][0];
    int brojac_praznih_redova = 0;

    vector<int>prvi;
    prvi.resize(broj_kolona);
    rez.push_back(prvi);

    //Ovdje je napravljeno pomocu dva brojaca da se naizmjnicno ubacuju dva prazna, dva puna reda
    //Ova petlja pravi samo zidove bez prolaza
    for(int i = 1; i < broj_redova - 1; i++){

        vector<int>red;
        if(brojac_praznih_redova == 0 || brojac_praznih_redova == 1){
            red.resize(broj_kolona, 1);
            brojac_praznih_redova++;
        }
        else if (brojac_praznih_redova == 2) {
            brojac_praznih_redova = -2;
        }
        if (brojac_praznih_redova == -2 || brojac_praznih_redova == -1){
            red.resize(broj_kolona);
            brojac_praznih_redova++;
        }
        rez.push_back(red);
    }


    int indeksX = 3;
    rez.push_back(prvi);

    //Sada na osnovu podataka koje smo dobili iz fajla dodajemo prolaze u matricu
    for(size_t i = 2; i < matrica.size(); i++){
        for(size_t j = 0; j < matrica[i].size(); j++){

                rez[indeksX][matrica[i][j]-1] = 1;
                rez[indeksX+1][matrica[i][j]-1] = 1;
            }
        indeksX += 4;
    }

    return rez;
}

// Funkcija za provjeru da li je pozicija validna unutar labirinta
// Provjeravamo da li je pozicija unutar granica labirinta, i da li je vrijednost 1
bool jeValidna(Pozicija& p, const vector<vector<int>>& labirint) {
    int broj_redova = labirint.size();
    int broj_kolona = labirint[0].size();

    return (p.x >= 0 && p.x < broj_redova && p.y >= 0 && p.y < broj_kolona && labirint[p.x][p.y] == 1);
}



int udaljenost(char prviZid, int pozicijaPrvog, char drugiZid, int pozicijaDrugog) {



    // Argumenti koje prosljedjujemo funkciji za pravljenje matrice
    vector<pair<char, int>> k;
    vector<vector<int>> labirint = napraviMatricu("labirint.txt", k);
    if(labirint.size() == 0){
        cout<<"Neispravan fajl.";
        return 0;
    }

    int pozicijaxPrvog;
    int pozicijaxDrugog;

    // Ovde na osnovu vektora parova, za zadano slovo trazimo red u kojem se nalazi
    // pocetak i kraj
    for (size_t i = 0; i < k.size(); i++) {
        if (k[i].first == prviZid)
            pozicijaxPrvog = k[i].second;
        if (k[i].first == drugiZid)
            pozicijaxDrugog = k[i].second;
    }

    Pozicija pocetak(pozicijaxPrvog, pozicijaPrvog - 1);
    Pozicija kraj(pozicijaxDrugog, pozicijaDrugog - 1);

    //Provjera da li su pocetna i krajnja pozicija unutar labirinta
    if(pocetak.x < 0 || pocetak.x > labirint.size() || pocetak.y < 0 || pocetak.y > labirint[0].size() ||
       kraj.x < 0 || kraj.x > labirint.size() || kraj.y < 0 || kraj.y > labirint[0].size() ||
       prviZid > k[k.size() - 1].first || drugiZid > k[k.size() - 1].first ||
       prviZid < k[0].first || drugiZid < k[0].first){

        cout<<"Pocetna i krajnja pozicija moraju biti u granicama labirinta.";
        return 0;
       }

    // Postavljammo poziciju pocetak na koordinate pocetka a kraj na koordinate kraja
    // Takodjer postavljamo njihove vrijednosti u matrici na 1
    labirint[pozicijaxPrvog][pozicijaPrvog - 1] = 1;
    labirint[pozicijaxDrugog][pozicijaDrugog - 1] = 1;

    if(pocetak == kraj)
        return 0;

    int broj_redova = labirint.size();
    int broj_kolona = labirint[0].size();

    //Matrica koja cuva udaljenosti od pocetka do svake pozicije
    //Sve pozicije postavljamo na -1, kao indiaktor da mjesta nisu posjecena
    vector<vector<int>> udaljenost(broj_redova, vector<int>(broj_kolona, -1));

    // Matrica koja sluzi za rekonstrukciju najkraceg puta od pocetka do kraja
    vector<vector<Pozicija>> roditelj(broj_redova, vector<Pozicija>(broj_kolona, Pozicija(-1, -1)));

    //S obzirom da se algoritam zasniva na BFS potreban nam je red
    queue<Pozicija> red;

    //Krecemo od pocetne pozicije
    red.push(pocetak);
    udaljenost[pocetak.x][pocetak.y] = 0;

    // Ova dva reda sluze da generisemo sve moguce kombinacije
    // Iz jedne pozicije mozemo ici gore, dole, lijevo desno, odnosno
    // iz pozicije (i, j) u (i-1, j), (i+1, j), (i, j-1), (i, j+1)
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!red.empty()) {

        //Trenutna pozicija je prvi element reda
        Pozicija trenutna = red.front();
        red.pop();

        // Prekid petlje ako je dostignuta krajnja pozicija
        if (trenutna == kraj) {
            break;
        }

        //Za svaku poziciju posmatramo sve 4 okolne pozicije
        for (size_t i = 0; i < 4; i++) {
            int noviX = trenutna.x + dx[i];
            int noviY = trenutna.y + dy[i];
            Pozicija nova(noviX, noviY);
            //Prvojeravamo da li je nova pozicija u granicama labirinta
            // i da li je njena vrijednost u matrici udaljenosti -1, posto
            // je to indikatro da nije posjecena
            if (jeValidna(nova, labirint) && udaljenost[noviX][noviY] == -1) {

                //Ako je pozicija unutar labirinta i nije posjecena,
                // u red dodajemo tu poziciju
                red.push(nova);

                //Udaljenost od pocetka do nove pozicije je udaljenost do stare pozicije plus 1
                udaljenost[noviX][noviY] = udaljenost[trenutna.x][trenutna.y] + 1;

                // Pamćenje roditeljske pozicije za trenutnu poziciju
                roditelj[noviX][noviY] = trenutna;
            }
        }
    }

    // Rekonstrukcija puta unazad
    vector<Pozicija> put;
    Pozicija trenutna = kraj;

    //krecemo od kraja i za svaku poziciju idemo na roditelja
    while (trenutna.x != -1 && trenutna.y != -1) {
        put.push_back(trenutna);
        trenutna = roditelj[trenutna.x][trenutna.y];
    }
    reverse(put.begin(), put.end());
    // Sada u vektoru put imamo sve pozicije koje su dio najkraceg puta u pravom redoslijedu

    //Ovde obilazimo sve pozicije koje su dio najkraceg puta, te za svaku povecavamo brojac
    //te u matricin na toj poziciji upisujemo trenutnu vrijednost brojaca
    //Ja sam upisivao negativnu vrijednost brojaca, radi vece preglednosti
    int trenutni_korak = 0;
    for(size_t i = 0; i < put.size(); i++){
        labirint[put[i].x][put[i].y] = trenutni_korak*(-1);
        trenutni_korak++;
    }

    vector<pair<char, int>>k2;
    k2.push_back(k[0]);
    k2.push_back(make_pair(' ', 1));
    k2.push_back(make_pair(' ', 2));
    for(int i = 2; i < k.size() - 1; i++){
        k2.push_back(k[i-1]);
        k2.push_back(k[i]);
        k2.push_back(make_pair(' ', i+1));
        k2.push_back(make_pair(' ', i+2));
        i++;
    }
    //Ovdje ispisujemo trenutno stanje labirinta, s tim da je pocetna pozicija oznacena sa P
    //a krajnja sa K
    cout<<" ";
    for(int i = 0; i < labirint[0].size(); i++)
        cout<<setw(5)<<i+1;
    cout<<endl<<endl;
    for(int i = 0; i < labirint.size(); i++){
            cout<<k2[i].first;
        for(int j = 0; j <labirint[i].size(); j++){
            if(i == pocetak.x && j == pocetak.y)
                cout<<setw(5)<<"P";
            else if(i == kraj.x && j == kraj.y)
                cout<<setw(5)<<"K";
            else if(labirint[i][j] == 1)
                cout<<setw(5)<<" ";
            else
                cout<<setw(5)<<labirint[i][j]*(-1);
        }

        cout<<endl;
    }

    //Takodje ispisujemo i minimalnu udaljenost
    cout<<endl<<"Duzina najkraceg puta je: "<<udaljenost[kraj.x][kraj.y] - 1<<endl;
    return udaljenost[kraj.x][kraj.y] - 1;
}
