# Problema 1: Numarare

Impresii personale:
    -la prima vedere am incercat o simpla parcurgere cu dfs pe unul din cele 2
        grafuri, unde retineam drumul pana la nodul unde am ajuns si atunci
        cand ajungeam la nodul final salvam path-ul intr-un vector de path-uri;
    -am inceput sa eficientizez dfs-ul prin verificarea fiecarei muchii daca se
        afla in celalalt graf(pentru a nu ma cara cu path-urile), apoi prin
        renuntarea la asta prin crearea unui singur graf comun unde se afla
        doar muchiile comune;
    -cand m-am prins de programarea dinamica am avut o revelatie.

Implementare:
    -parcurg lista de adiacenta si pt fiecare muchie (u, v), adaug la dp[v],
        numarul de drumuri pana la u;
    -astfel pt fiecare nod v, voi avea toate drumurile posibile pana la acesta;
    -pe scurt, aflu pentru fiecare nod, numarul de drumuri pana la acesta, 
        pornind de la cazul de baza dp[1] = 1.

Complexitati:
    -complexitatea spatiala este O(m+m), din cauza listei de adiacenta, unde n
        este numarul de noduri si m numarul de muchii;
    -complexitatea temporala este O():
        -citirea muchiilor este O(2*m);
        -functia sort are O((2m) * log(2m)), din cauza muchiilor;
        -adaugarea in graful comun are O(2m);
        -partea de programare dinamica are O(n+m), exact ca graful, deoarece se
            parcurge graful.

# Problema 2: Trenuri

Impresii personale:
    -in prima instanta, am dorit sa-mi construiesc propriul meu alfabet, dar e
        clar ca un hashmap este mult mai eficient, deoarece adaugarea are
        complexitatea O(1);

Implementare:
    -am folosit un hashmap in care am atribuit un index fiecarui oras;
    -am salvat un vector de muchii, pentru a le putea pune in lista de
        adiacenta, dupa ce am atribuit tuturor oraselor un index;
    -folosim o sortare topologica pentru a putea lucra doar cu noduri ale carui
        vecini care au muchii spre nodul respectiv, sa fi fost deja prelucrati;
    -in functie de ordinea topologica, luam lista de adiacenta, si pentru
        fiecare muchie (u, v), vedem daca distanta pe care o aflam din u este
        mai mare decat ce avem deja in v;
    -astfel ajungem ca in final sa avem cea mai mare distanta posibila.

Complexitati:
    -complexitatea spatiala este O(n+m), datorata listei de adiacenta,
        hashmap-ul si vectorii au O(n), deci per total ramane O(n+m);
    -consideram n numarul de orase si m numarul de muchii, chiar daca in cerinta
        n este numarul de muchii furnizate;
    -complexitatea temporala este O(n+m):
        -avem citirea muchiilor care este O(m), unde m este numarul de muchii
        -adaugarea oraselor in hashmap care este O(n), unde n este numarul de
            orase(nu este oferit);
        -complexitatea la sortarea topologica este O(n+m), cu n si m care au 
            aceleasi semnificatii;
        -tot O(n+m) avem si in actualizarea distantelor din functia de drum.

# Problema 3: Drumuri

Impresii personale:
    -din cauza faptului ca nu am folosit long long din prima, am pierdut minim
        2 ore degeaba;
    -am observat ca se poate efectua si o singura parcurgere Dijkstra cu care
        iau 32pct, dar pt 5pct in plus am folosit de 2 ori Dijkstra;
    -inteleg de ce pica ultimele 3pct, dar mi se pare foarte complicat de
        rezolvat fara sa folosesc brute force care nu e o optiune (cazul in care
        nodul intermediar nu exista pe niciunul din drumurile de baza ale lui
        start1 sau start2 la finish);
    -dupa ce am combinat solutiile cu graf normal si graf inversat, au trecut
        toate testele.
    
Implementarea:
    -am folosit 2 grafuri, unul normal si unul inversat;
    -am apelat functia de 3 ori pentru a putea afla distanta de la nodurile
        start1, start2 si final la oricare nod din graf;
    -aflam minimul acestei sume formate din 3 elemente, care este si rezultatul
        cautat (testam toate nodurile si vedem care ofera suma cea mai
        convenabila).

Complexitati:
    -complexitatea spatiala este O(n+m), din cauza listei de adiacenta, restul
        vectorilor, si coada de prioritate sunt sub O(n);
    -complexitatea temporala a algoritmului Dijkstra este O((n+m)log(n)),
        restul parcurgerilor de drum sunt O(n).
    
# Problema 4: Scandal

Impresii personale:
    -destul de grea problema, cel mai mult am stat la ea;
    -am inteles ca se putea face si cu kosaraju, dar eu am implementat cu
        Tarjan ca sa pot prelua functiile de la laborator;
    -am folosit foarte multe functii pe care le aveam implementate dinainte cum
        ar fi sortarea topologica sau Tarjan.

Implementare:
    -ca punct de plecare am pornit de la problema 2-sat, daca avem un nod x,
        valoarea pozitiva a participarii la petrecere ramane x, iar pentru
        valoarea negativa am considerat n+x;
    -am folosit algoritmul Tarjan implementat la laborator pentru a gasi
        componentele tare conexe din graf;
    -am notat toate nodurile care se afla intr o componenta tare conexa cu un
        index;
    -construim un graf condensat in care fiecare componenta tare conexa este
        reprezentata de un singur nod, adica un graf restrans;
    -efectuam o sortare topologica pe graful condensat;
    -intr-un final determinam solutia prin asignarea de valori fiecarui nod,
        luam fiecare componenta conexa in parte si pentru nodurile dinauntru
        asignam valori (daca indexul e mai mare decat n, inseamna ca e negatie,
        altfel e nod original);
    -daca mai intai apar negatiile nodurilor, le selectam pe acestea deoarece
        le-am notat cu 1;
    -rezultatul final e reprezentat de valorile pozitive ale nodurilor de
        negatie selectate.

Comlexitati:
    -complexitatea spatiala este O(n+m), din cauza listei de adiacenta, in rest
        avem doar O(n) din vectori;
    -complexitatea temporala este O(n+m), sortarea topologica si algoritmul lui 
        taljan au O(n+m), in timp ce restul parcurgerilor au cel mult O(n+m)
        deoarece parcurg intreaga lista de adiacenta.
    