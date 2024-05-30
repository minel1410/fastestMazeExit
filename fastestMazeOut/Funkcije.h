// Funkcije.h

#ifndef FUNKCIJE_H
#define FUNKCIJE_H

#include <string>
#include <vector>
#include <utility>

using namespace std;

// Struktura koja predstavlja jednu poziciju u matrici sa x i y koordinatom
struct Pozicija {
    int x, y;
    Pozicija(int x1, int y1) : x(x1), y(y1) {}
    bool operator == (Pozicija& p){ return (x == p.x && y == p.y); }
};

//  Funkcija koja ucitava fajl i pravi binarni labirint na osnovu ucitanih podataka
vector<vector<int>> napraviMatricu(const string& filename, vector<pair<char, int>>& slovo_broj);

//  Funkcija koja za datu poziciju i labirint provjerava da li pozicija dozvoljena
bool jeValidna(Pozicija& p, const vector<vector<int>>& labirint);


//  Funkcija koja prima koordinate pocetne i krajnje pozicije te vraca najkracu udaljenost izmedju njih
int udaljenost(char prviZid, int pozicijaPrvog, char drugiZid, int pozicijaDrugog);

#endif // FUNKCIJE_H
