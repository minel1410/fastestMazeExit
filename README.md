Analiza i sinteza algoritama

Prirodno-matematički fakultet

Univerzitet u Sarajevu

Projekat – tema 2

Minel Salihagić

Opis projekta

Ovaj projekat predstavlja implementaciju programa za pronalaženje najkraće udaljenosti između dvije 
tačke unutar labirinta. Labirint je definiran putem tekstualnog fajla koji sadrži informacije o strukturi 
labirinta, a zatim se koristi Lee algoritam za računanje udaljenosti između tačaka. Program također može 
iscrtati najkraći put unutar labirinta.

Funkcionalnosti
1. Učitavanje labirinta: Program omogućava učitavanje labirinta iz tekstualnog fajla. Struktura 
labirinta je definisana putem broja redova i pozicija prolaza unutar svakog reda. Zidovi su označeni 
s nulom (0), dok su prolazi označeni jedinicom (1).
2. Pronalaženje najkraće udaljenosti: Nakon učitavanja labirinta, program koristi Lee algoritam za 
pronalaženje najkraće udaljenosti između dvije tačke unutar labirinta. Korisnik može specificirati 
početnu i krajnju poziciju putem karaktera i pozicija unutar labirinta.
3. Rekonstrukcija najkraćeg puta: Program može rekonstruisati najkraći put između početne i krajnje 
pozicije unutar labirinta.
4. Ispis labirinta: Nakon pronalaženja najkraće udaljenosti i rekonstrukcije puta, program ispisuje 
stanje labirinta, pri čemu je početna pozicija označena kao 'P', a krajnja pozicija kao 'K'. 
5. Validacija unosa: Program vrši validaciju unosa kako bi se osiguralo da su početna i krajnja pozicija 
unutar granica labirinta, te da je fajl u ispravnom obliku.

Zaključak

Ovaj program omogućava učitavanje labirinta iz tekstualnog fajla i da pronalazak najkraće udaljenosti
između tačaka unutar labirinta koristeći Lee algoritam. Rezultati se jasno ispisuju na ekranu, a najkraći put 
se označava unutar labirinta radi lakše interpretacije. Program također vrši validaciju unosa kako bi se 
osiguralo da su početna i krajnja pozicija unutar granica labirinta.

Dokumentacija

Funkcija napraviMatricu

vector<vector<int>> napraviMatricu(const string& filename, vector<pair<char, int>>& slovo_broj); 
Ova funkcija učitava labirint iz tekstualnog fajla čije ime se proslijeđuje kao parametar. Labirint je definisan 
putem broja redova i pozicija prolaza unutar svakog reda.
• filename: Ime fajla sa definicijom labirinta.
• slovo_broj: Referenca na vektor parova koji mapira slova redova u odgovarajuće brojeve redova.
Funkcija vraća matricu koja predstavlja binarni labirint, gdje je svaka pozicija označena sa 0 za zidove i 1 za 
prolaze.

Funkcija udaljenost

int udaljenost(char prviZid, int pozicijaPrvog, char drugiZid, int pozicijaDrugog); 
Ova funkcija koristi Lee algoritam za pronalaženje najkraće udaljenosti između dvije tačke unutar labirinta.
• prviZid: Karakter koji označava red u kojem se nalazi početna pozicija.
• pozicijaPrvog: Pozicija unutar reda za početnu tačku.
• drugiZid: Karakter koji označava red u kojem se nalazi krajnja pozicija.
• pozicijaDrugog: Pozicija unutar reda za krajnju tačku.
Funkcija radi tako što za svaku poziciju u labirintu koja je validna dodaje u red, počevši sa početnom 
pozicijom. Za svaku poziciju u matrici bilježi udaljenost od početne pozicije. Ovo je urađeno tako što je na 
početku udaljenost 0, te se svakim korakom povećava za 1. Također, formira se matrica pozicija zvana 
roditelj, koja za svaku poziciju unutar labirinta čuva njenog roditelja, odnosno poziciju iz koje se došlo do 
te pozicije. Ovo služi za čuvanje najkraćeg puta od početka do kraja, tako što krenemo od krajnje pozicije 
te za svaku poziciju tražimo roditelja dok ne dođemo do početne pozicije.

Funkcija jeLiValidna

Ova funkcija, za prosljeđenu poziciju, te vektor vektora, vraća da li se pozicija nalazi u matrici, te također 
da li je vrijednost matrice u toj koordinati označena sa 1, jer je to znak da je taj potez dozvoljen, odnosno 
da je na tom mjestu prolaz.

Struktura pozicija

Ova struktura predstavlja zapravo jednu tačku, odnosno položaj u matrici. Ima atribute x i y, što predstavlja 
broj reda i kolone u kojoj se nalazi. Implementiraj ne konstruktor, te operator == koji vraća da li dvije 
pozicije imaju iste koordinate. Ostale funkcije u programu se koriste za validaciju unosa, rekonstrukciju 
najkraćeg puta, ispis labirinta i druge pomoćne zadatke.
