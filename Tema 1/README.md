Problema 1: Alimentare Servere
------------------------------

Am considerat operatia modul matematic ca fiind:
    P - |prag - C| = (P - C) + prag, daca prag < C
                   = (P + C) - prag, daca prag >=C

Am parcurs fiecare duplet (Pi, Ci), alegand minimul pentru semnele 
    minus Pi - Ci si plus Pi + Ci.Alegem minimele, pentru a afla pragul optim,
    unde ecuatia de mai sus este cat mai mare pentru orice pereche (P, C).

Astfel, din ecuatia pe ramuri de mai sus, rezulta
    prag = [(P + C) - (P - C)] / 2, adica fix minimele
    calculate mai sus.

Pentru pragul aflat, calculam cea mai mica putere, adica plus - prag
    sau prag - minus.

Complexitatea temporala a algoritmului este O(3n + 1), 2n + 1 pt citire si n
    pentru gasirea minimelor, iar cea spatiala este O(2n+2), 2n pt vecotrii
    cititi si 2 pentru valorile minime.



Problema 2: Colorare
--------------------

Am folosit elemente ce tin de combinatorica si numarare.
Daca sirul nostru de blocuri incepe cu un spatiu vertical, avem 3 posibilitati
    de colorare.

Daca sirul nostru incepe cu bloc orizontal, avem aranjamente de 3 luate cate 2.

Pentru a calcula mai departe osibilitatile de colorare, putem inmulti
    probabilitatile de colorare pentru fiecare bloc, intre ele astfel:
        -Daca avem bloc vertical dupa bloc vertical, avem 2 posibilitati de
            colorare (2),pentru ca primul bloc are o culoare, si (1) raman 2.
        -Daca avem bloc vertical, dupa bloc orizontal, ramane ca blocul sa aiba
            o singura culoare (1), deoarece celelalte 2 sigur au fost folosite
            fix inainte.
        -Daca avem bloc orizontal, dupa bloc vertical, avem doar 2 posibilitati
            de colorare, pentru ca avem doar 2 culori (2), adica permutari de 2.
        -Daca avem bloc orizontal dupa bloc orizontal, avem 3 posibilitati (3),
            adica combinari de 3 luate cate 2.

Astfel, conform celor prezentate mai sus, folosim formula de putere in functie
    de cum arata sirul nostru de blocuri.

Complexitatea temporala a algoritmului este O(k + k*log(k)), k pentru
    parcurgere si log(k) pt fuctia putere. Complexitatea spatiala a
    algoritmului este O(2*k + 2), 2*k + 1 pt datele de intrare si 1 pt rezultat.

Problema 3: Compresie
---------------------

Consideram 2 contoare care sa tina minte parcurgerea pe fiecare vector.
Atunci cand observam ca elementul la care ne aflam pe primul vector este mai
    mare decat elementul din al doilea vector, punem valoarea scaderii pe
    pozitia la care ne aflam in primul vector si ne deplasam cu o pozitie.La
    fel facem si in cazul invers.Cand elementele sunt egale, ne deplasam cu
    ambele contoare.Daca contoarele nu sunt egale, inseamna ca nu putem ajunge
    la vectori identici si returnam -1.In caz contrar, intoarecem unul din cele
    2 contoare.

Complexitatea temporala a algorimtmului este O(3n + 2), 2n + 1 pt citire si 
    n+1 pt parcurgere si if-ul final.Complexitatea spatiala este O(2n+4), 2n + 2
    pt datele de intrare si 2 pt contori.

Problema 4: Criptat
-------------------

Impresii personale:
- problema merge rezolvata de 19 pct si cu metoda greedy de ghiozdan, sortand
    elementele dupa raportul nr.aparitiilor_literei_analizate/nr.total_de_litere
    (am incercat asta prima oara)


Rezolvare:
Am considerat structuri de date ajutatoare, astfel incat sa am o evidenta 
    a tuturor literelor care apar in toate cuvintele, si pt fiecare litera
    analizata am o evidenta a numarului de litere analizate care se afla in
    compozitia fiecarui cuvant.

Luam fiecare litera in parte, o sortam dupa raportul mentionat mai sus, si 
    efectuam PD de tip SCMAX din laboratorul 3.

Pt PD, consideram 2 vectori separati, dp1 (pt numarul total de litere) si 
    dp2 (pt numarul aparitiilor literei analizate).Efectuam PD de tip SCMAX,
    unde avem conditie ca actualizam vectorii dp, doar daca noul element adaugat
    respecta conditia ca dupa adaugare, litera analizata sa fie inca dominanta.

De asemenea, trebuie sa consideram si faptul ca din 2 varinate valide,trebuie
    sa o alegem pe cea care ne confera cuvantul cel mai lung (vezi al doilea if
    din PD).
    
Actualizam cei doi vectori si la final, alegem cel mai mare elemnent din dp1,
    din toate analizele de litere.

Complexitatea temporala a algoritmului este O(n^2) pt for-urile din programarea
    dinamica, iar ce spatiala este dominata de vectorul strings, adica O(n).

Problema 5: Oferta
------------------

Impresii personale:
- cazul k=1 nu e atat de greu de implementat, dar testele bonus sunt altceva;
- ma gandam ca as fi putut sa face o matrice in care sa simulez urmatorii 3
    pasi posibili si sa retin pe coloana respectiva cele 3 valori, adaugand
    practic inca 2 linii pe langa varianta cea mai buna, dar asta e destul de
    greu de implemntat;
- pt k=1, recurenta chiar era usoara.

Rezolvare:
Pt primele 3 elemente ale vectorului, am incercat sa luam in dp cele mai bune
    variante.Adica pt prima pozitie este doar prima suma pt ca nu am cum sa
    aplic o oferta.Pt primele 2 elemente, am considera oferta de 2 produse, pt
    ca aceasta este cea mai buna(mai buna decat luate individual).Pt primele 3
    produse, am testat sa vedem care din varinate este mai buna: primele 2
    2 produse cu oferta si al treilea singur, ultimele 2 produse luate cu oferta
    si primul singur, sau toate 3 cu oferta de 3.Acesta este cazul de baza.

Practic, recurenta se bazeaza tot pe principiul de mai sus.Incercam sa vedem
    care din cazuri este mai bun:
    - suma produselor luate la pasul precedent peste care adaugam produsul
        curent;
    - suma produselor luate cu 2 pasi in urma, peste care adaugam ulimele 2
        produse luate ca oferta;
    - suma produselor luate cu 3 pasi in urma, peste care adaugam ultimele 3
        produse luate ca oferta de 3.

Rezultaul cautat este ultimul element din dp.

Complexitatea temporala a algoritmului este O(n), avem doar parcurgeri liniare.
    Complexitatea spatiala este de asemenea O(n) pt ca avem doar un vector dp 
    unde stocam rezultatele.