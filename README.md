# Skyline
Laboratorio di Algoritmi e Strutture Dati
Docenti: M. Goldwurm, S. Aguzzoli
Appello del 5 settembre 2003
Progetto “Skyline”
Consegna entro il 23 settembre 2003
Il problema
La skyline di una città e il profilo che i suoi palazzi ed edifici delineano quando essa è osservata da una
qualche angolazione.
Obiettivo del progetto è studiare i profili originati dalla disposizione di edifici di forma semplificata
(parallelepipedi) nell’area piana di una città.
Formalmente la città è rappresentata dal piano P di equazione z = 0 in uno spazio euclideo tridimensionale:
P = {(x, y, 0) | x, y ∈ R}.
Un edificio è un parallelepipedo la cui base poggia sul piano P della città, ed è completamente specificato
dai parametri:
• Coordinate del vertice inferiore sinistro della base: (x0, y0) ∈ Z2:
• x-estensione della base: 0 < lx ∈ Z.
• y-estensione della base: 0 < ly ∈ Z.
• Altezza: 0 < h ∈ Z.
Dunque, denoteremo con E(x0, y0, lx, ly, h) l’edificio descritto dal seguente sottoinsieme di R3:
E(x0, y0, lx, ly, h) = {(x, y, z) | x0 ≤ x ≤ x0 + lx, y0 ≤ y ≤ y0 + ly, 0 ≤ z ≤ h}.
La x-proiezione dell’edificio E(x0, y0, lx, ly, h) è l’insieme {(x, 0, z) | (x, y0, z) ∈ E(x0, y0, lx, ly, h)}.
La y-proiezione dell’edificio E(x0, y0, lx, ly, h) è l’insieme {(0, y, z) | (x0, y, z) ∈ E(x0, y0, lx, ly, h)}.
L’x-profilo di una città è dato dalla unione delle x-proiezioni degli edifici presenti in citt`a unita alla retta
delle ascisse {(x, 0, 0) | x ∈ R}. L’y-profilo di una città è dato dalla unione delle y-proiezioni degli edifici
presenti in città unita alla retta delle ordinate {(0, y, 0) | y ∈ R}.
La città nasce inizialmente vuota. La costruzione di un nuovo edificio avverrà specificandone i parametri
nell’operazione di introduzione.
E possibile sovrapporre edifici, tali sovrapposizioni contribuiscono a definire un isolato (nota che la 
sovrapposizione di due o più edifici va pensata come la “fusione” degli edifici in questione, vale a dire le
parti in sovrapposizione costituiscono l’intersezione insiemistica degli edifici suddetti).
Un isolato è un’unione di edifici connessa e massimale: Un’unione U di edifici è connessa se ogni due
punti appartenenti ad U sono congiungibili da una spezzata completamente giacente in U (ricordiamo che
una spezzata è una curva continua costituita da una successione finita di segmenti). Un’unione connessa
1 di edifici è massimale se non è possibile aggiungervi alcun edificio già presente in cittè senza perdere la
connessione.
Il volume di un isolato è il volume geometrico dell’isolato inteso come sottoinsieme di R3.
Dunque un punto (x, y, z) può appartenere a nessuno o a uno o a più edifici, ed appartiene ad almeno un
edificio se e solo se appartiene ad un unico isolato.
Nella città possono essere costruite delle strade che a volte richiedono la demolizione di parti di edifici.
Una y-strada è specificata dalla sua ampiezza (a, b) ∈ Z2.
Formalmente: yS(a, b) = {(x, y, 0) | a < y < b, x ∈ R}.
Una x-strada è specificata dalla sua ampiezza (c, d) ∈ Z2. 
Formalmente: xS(c, d) = {(x, y, 0) | c < x < d, y ∈ R}.
La costruzione della y-strada yS(a, b) prevede la demolizione di tutte le parti di edifici che occupano
lo spazio per cui deve passare la strada: tali demolizioni comportano la modifica degli edifici stessi in
accordo con la procedura seguente.
Sia E(x0, y0, lx, ly, h) un generico edificio presente al momento della costruzione della strada yS(a, b). Si
consideri l’insieme E0: E0 = E(x0, y0, lx, ly, h) \ {(x, y, z) | (x, y, 0) ∈ yS(a, b), z ∈ R}.
Si noti che E0 può in genere non essere esprimibile come un unico parallelepipedo, ma sempre come l’unione
di un numero finito di parallelepipedi e di un numero finito di rettangoli: tali rettangoli rappresentano
facciate “residue” di edifici per il resto demoliti (ad esempio la y-strada ys(8, 15) demolisce tutto l’edificio
E(25, 8, 10, 3, 7) tranne la sua facciata {(x, 8, z) | 25 ≤ x ≤ 35, 0 ≤ z ≤ 7}). 
Possiamo dunque ritenere E0 un’unione finita (e in genere non connessa) di edifici e di facciate “residue”. 
Per terminare l’opera di demolizione, consideriamo ora l’insieme E00 ottenuto sottraendo a E0 ogni facciata “residua”. 
Al termine della costruzione della strada, ogni edificio E(x0, y0, lx, ly, h) sarà stato rimpiazzato da un numero finito
di edifici, precisamente quelli la cui unione costituisce l’insieme E00.
Analoghe considerazioni si applicano alla costruzione di x-strade xS(c, d). Oxy2
Nell’esempio raffigurato sono presenti i seguenti edifici: E(3, 7, 3, 4, 4), E(5, 6, 6, 3, 5), E(6, 11, 1, 1, 7),
E(10, 0, 3, 2, 2), E(13, 3, 1, 5, 3), E(13, 4, 1, 2, 4). 
Essi danno origine a 3 isolati, di seguito listati: 1) E(3, 7, 3, 4, 4) ∪ E(5, 6, 6, 3, 5) ∪ E(6, 11, 1, 1, 7), 2) 
E(10, 0, 3, 2, 2), 3) E(13, 3, 1, 5, 3) ∪ E(13, 4, 1, 2, 4). Il volume dell’isolato 1) è
(3 × 4 × 4) + (6 × 3 × 5) − (1 × 2 × 4) + (1 × 1 × 7) = 137.
I profili sono riportati in figura, dove l’x-profilo per comodità è mostrato sullo sfondo della città. 
Usando la specifica data nel seguito sul formato di output dei profili, i profili sono identificati dalle seguenti liste
di vertici:
x − profilo y − profilo
3 0 0 0
3 4 0 2
5 4 2 2
5 5 2 0
6 5 3 0
6 7 3 3
7 7 4 3
7 5 4 4
11 5 6 4
11 2 6 5
13 2 9 5
13 4 9 4
14 4 11 4
14 0 11 7
12 7
12 0
Si noti che per definizione ai profili appartengono sempre le rette corrispondenti agli assi cartesiani
x, y, dunque il segmento di estremi (0, 2, 0),(0, 3, 0) appartiene all’y-profilo della città. 
La costruzione della y-strada yS(5, 7) determina la parziale demolizione dei tre edifici E(5, 6, 6, 3, 5), E(13, 3, 1, 5, 3) e
E(13, 4, 1, 2, 4). In particolare l’edificio E(5, 6, 6, 3, 5) viene rimpiazzato dall’unico edificio E(5, 7, 6, 2, 5),
mentre l’edificio E(13, 3, 1, 5, 3) viene rimpiazzato dai due edifici E(13, 3, 1, 2, 3) e 
E(13, 7, 1, 1, 3) e l’edificio E(13, 4, 1, 2, 4) dall’edificio E(13, 4, 1, 1, 4). 
L’y-profilo viene alterato dalla costruzione di yS(5, 7) eliminando da esso tutti i punti della forma (0, y, z) per 5 < y < 7, 
mentre in questo caso l’x-profilo rimane inalterato. 
La costruzione della y-strada yS(4, 7) determina invece la completa demolizione dell’edificio 
E(13, 4, 1, 2, 4) (che viene rimpiazzato da ∅) e l’alterazione anche dell’x-profilo che in tal modo perde tutti
i punti (x, 0, z) con 13 < x < 14, 3 < z ≤ 4.
Si richiede di implementare una struttura dati efficiente che permetta di eseguire le operazioni seguenti
(si tenga presente che la minima porzione rettangolare di piano contenente tutte le basi di edifici è in
genere molto grande rispetto al numero di edifici, quindi non è sicuramente efficiente rappresentare il
piano mediante una matrice).
- crea()
Crea una città inizialmente vuota, distruggendo tutti gli edifici attualmente presenti.
- inserisci(x0, y0, lx, ly, h)
Inserisce nella città l’edificio E(x0, y0, lx, ly, h).
- elimina(x, y)
Elimina dalla città ogni edificio la cui base contiene il punto (x, y, 0).
- isolati()
Restituisce il numero di isolati presenti in città.
- volume(x, y)
Restituisce il volume dell’isolato contenente il punto (x, y, 0). Restituisce 0 se (x, y, 0) non appartiene ad alcun edificio.
- x-profilo()
Restituisce l’x-profilo della città secondo il formato specificato nell’apposita sezione.
- y-profilo()
Restituisce l’y-profilo della città secondo il formato specificato nell’apposita sezione.
- y-strada(y0, y1)
Costruisce la y-strada yS(y0, y1).
- x-strada(x0, x1)
Costruisce la x-strada xS(x0, x1).
Specifiche di implementazione
Il programma deve leggere dallo standard input (stdin) una sequenza di linee (separate da \n), ciascuna
delle quali corrisponde a una linea della prima colonna della Tabella 1, dove x, y, l, m, h sono numeri naturali
e i vari elementi sulla linea sono separati da uno o più spazi. Quando una linea è letta viene eseguita
l’operazione ad essa associata e viene stampato l’eventuale output prodotto dall’esecuzione dell’operazione
associata; tutte le operazioni di stampa sono effettuate sullo standard output (stdout) e ogni operazione
deve iniziare su una nuova linea.
Formato per l’output di profili di città
Siano xmin e xmax rispettivamente le ascisse minima e massima dei punti appartenenti alle x-proiezioni
degli edifici della città. Sia H il sottoinsieme dell’x-profilo della città costituito dai punti (x, 0, z)
per i quali vale xmin ≤ x ≤ xmax. H è l’unione di un numero finito di rettangoli e del segmento
{(x, 0, 0) | xmin ≤ x ≤ xmax}: H è connesso e il suo contorno è dunque una successione finita di segmenti,
alternatamente orizzontali (aventi z costante) e verticali (aventi x costante).
L’intersezione di ogni coppia di segmenti consecutivi origina un vertice (x, 0, z) ∈ Z3.
Sia (x1, 0, z1) il primo di tali vertici secondo l’ordine lessicografico: (x, 0, z) < (x0, 0, z0) se e solo se
(x < x0) o (x = x0e z < z0).
Necessariamente z1 = 0 e x1 = xmin. Il vertice (x1, 0, z1) sarà il primo vertice della nostra presentazione di H.
Dato l’i-esimo vertice (xi, 0, zi), l’(i + 1)-esimo vertice sarà il vertice immediantamente successivo a (xi, 0, zi)
nella visita dei vertici di H in ordine orario. L’ultimo vertice (xu, 0, zu) di H è (xmax, 0, 0).
Avendo costruito la successione (x1, 0, z1),(x2, 0, z2), . . . ,(xi, 0, zi), . . . ,(xu, 0, zu) dei vertici di H,
la si 4 Linea di input Operazione c crea () i x y l m h inserisci (x, y, l, m, h) e x y elimina (x, y)
I isolati ()
v x y volume (x, y)
x x-profilo ()
y y-profilo ()
Y x y y-strada (x, y)
X x y x-strada (x, y)
f Termina l’esecuzione del programma
Tabella 1: Specifiche del programma
emetta in output secondo il formato seguente:
x1 z1
x2 z2
.
.
.
.
.
.
xi zi
.
.
.
.
.
.
xu zu
Analoghe specifiche si applicano all’output di y-profili considerando vertici della forma (0, y, z) al posto
di (x, 0, z) ed adattando le precedenti definizioni in modo naturale.
Nota: Non devono essere presenti vincoli sulla dimensione del piano, degli edifici e delle strade e sul
numero di edifici (se non quelli determinati dal tipo di dato intero). Non si richiede – anzi si sconsiglia –
l’uso di grafica, se non per test personali: in modo particolare, non si usi conio.h e neppure clrscr().
Nota: Per semplicità si suppone che l’input sia sempre conforme alle specifiche di Tabella 1, per cui non
è necessario controllare la correttezza dell’input.
Esempio
Si supponga che le linee di input siano:
c
i 4 6 5 6 2
i 2 8 14 2 4
i 13 4 2 7 7
I
i 11 13 2 2 7
5
I
v 2 10
x
y
X 6 8
I
v 5 10
e 5 10
I
Y 13 15
I
x
f
L’output prodotto dal programma deve essere:
1
2
234
2 0
2 4
11 4
11 7
15 7
15 4
16 4
16 0
4 0
4 7
11 7
11 2
12 2
12 0
13 0
13 7
15 7
15 0
3
48
2
1
8 0
8 4
13 4
13 7
15 7
15 4
16 4
16 0
