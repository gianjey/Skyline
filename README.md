# Skyline
<b>Laboratorio di Algoritmi e Strutture Dati</br>
Docenti: M. Goldwurm, S. Aguzzoli</br>
Appello del 5 settembre 2003</br>
Progetto “Skyline”</br>
Consegna entro il 23 settembre 2003</b></br></br>
<b>Il problema</b></br>
La skyline di una città e il profilo che i suoi palazzi ed edifici delineano quando essa è osservata da una
qualche angolazione.</br>
Obiettivo del progetto è studiare i profili originati dalla disposizione di edifici di forma semplificata
(parallelepipedi) nell’area piana di una città.</br>
Formalmente la città è rappresentata dal piano P di equazione z = 0 in uno spazio euclideo tridimensionale:</br>
P = {(x, y, 0) | x, y ∈ R}.</br>
Un edificio è un parallelepipedo la cui base poggia sul piano P della città, ed è completamente specificato
dai parametri:</br>
• Coordinate del vertice inferiore sinistro della base: (x0, y0) ∈ Z2:</br>
• x-estensione della base: 0 < lx ∈ Z.</br>
• y-estensione della base: 0 < ly ∈ Z.</br>
• Altezza: 0 < h ∈ Z.</br></br>
Dunque, denoteremo con E(x0, y0, lx, ly, h) l’edificio descritto dal seguente sottoinsieme di R3:
E(x0, y0, lx, ly, h) = {(x, y, z) | x0 ≤ x ≤ x0 + lx, y0 ≤ y ≤ y0 + ly, 0 ≤ z ≤ h}.</br>
La x-proiezione dell’edificio E(x0, y0, lx, ly, h) è l’insieme {(x, 0, z) | (x, y0, z) ∈ E(x0, y0, lx, ly, h)}.</br>
La y-proiezione dell’edificio E(x0, y0, lx, ly, h) è l’insieme {(0, y, z) | (x0, y, z) ∈ E(x0, y0, lx, ly, h)}.</br></br>
L’x-profilo di una città è dato dalla unione delle x-proiezioni degli edifici presenti in citt`a unita alla retta
delle ascisse {(x, 0, 0) | x ∈ R}. L’y-profilo di una città è dato dalla unione delle y-proiezioni degli edifici
presenti in città unita alla retta delle ordinate {(0, y, 0) | y ∈ R}.</br></br>
La città nasce inizialmente vuota. La costruzione di un nuovo edificio avverrà specificandone i parametri
nell’operazione di introduzione.</br></br>
E possibile sovrapporre edifici, tali sovrapposizioni contribuiscono a definire un isolato (nota che la 
sovrapposizione di due o più edifici va pensata come la “fusione” degli edifici in questione, vale a dire le
parti in sovrapposizione costituiscono l’intersezione insiemistica degli edifici suddetti).</br></br>
Un isolato è un’unione di edifici connessa e massimale:</br>
Un’unione U di edifici è connessa se ogni due punti appartenenti ad U sono congiungibili da una spezzata completamente giacente in U (ricordiamo che
una spezzata è una curva continua costituita da una successione finita di segmenti).</br>
Un’unione connessa 1 di edifici è massimale se non è possibile aggiungervi alcun edificio già presente in cittè senza perdere la
connessione.</br></br>
Il volume di un isolato è il volume geometrico dell’isolato inteso come sottoinsieme di R3.</br></br>
Dunque un punto (x, y, z) può appartenere a nessuno o a uno o a più edifici, ed appartiene ad almeno un
edificio se e solo se appartiene ad un unico isolato.</br></br>
Nella città possono essere costruite delle strade che a volte richiedono la demolizione di parti di edifici.</br></br>
Una y-strada è specificata dalla sua ampiezza (a, b) ∈ Z2.</br></br>
Formalmente: yS(a, b) = {(x, y, 0) | a < y < b, x ∈ R}.</br>
Una x-strada è specificata dalla sua ampiezza (c, d) ∈ Z2.</br></br>
Formalmente: xS(c, d) = {(x, y, 0) | c < x < d, y ∈ R}.</br>
La costruzione della y-strada yS(a, b) prevede la demolizione di tutte le parti di edifici che occupano
lo spazio per cui deve passare la strada: tali demolizioni comportano la modifica degli edifici stessi in
accordo con la procedura seguente.</br></br>
Sia E(x0, y0, lx, ly, h) un generico edificio presente al momento della costruzione della strada yS(a, b).</br>
Si consideri l’insieme E0: E0 = E(x0, y0, lx, ly, h) \ {(x, y, z) | (x, y, 0) ∈ yS(a, b), z ∈ R}.</br>
Si noti che E0 può in genere non essere esprimibile come un unico parallelepipedo, ma sempre come l’unione
di un numero finito di parallelepipedi e di un numero finito di rettangoli: tali rettangoli rappresentano
facciate “residue” di edifici per il resto demoliti (ad esempio la y-strada ys(8, 15) demolisce tutto l’edificio
E(25, 8, 10, 3, 7) tranne la sua facciata {(x, 8, z) | 25 ≤ x ≤ 35, 0 ≤ z ≤ 7}).</br></br>
Possiamo dunque ritenere E0 un’unione finita (e in genere non connessa) di edifici e di facciate “residue”.</br></br> 
Per terminare l’opera di demolizione, consideriamo ora l’insieme E00 ottenuto sottraendo a E0 ogni facciata “residua”.</br> 
Al termine della costruzione della strada, ogni edificio E(x0, y0, lx, ly, h) sarà stato rimpiazzato da un numero finito
di edifici, precisamente quelli la cui unione costituisce l’insieme E00.</br>
Analoghe considerazioni si applicano alla costruzione di x-strade xS(c, d). Oxy2</br></br> 
Nell’esempio raffigurato sono presenti i seguenti edifici: E(3, 7, 3, 4, 4), E(5, 6, 6, 3, 5), E(6, 11, 1, 1, 7),
E(10, 0, 3, 2, 2), E(13, 3, 1, 5, 3), E(13, 4, 1, 2, 4).</br> 
Essi danno origine a 3 isolati, di seguito listati: 1) E(3, 7, 3, 4, 4) ∪ E(5, 6, 6, 3, 5) ∪ E(6, 11, 1, 1, 7), 2) 
E(10, 0, 3, 2, 2), 3) E(13, 3, 1, 5, 3) ∪ E(13, 4, 1, 2, 4).</br>
Il volume dell’isolato 1) è (3 × 4 × 4) + (6 × 3 × 5) − (1 × 2 × 4) + (1 × 1 × 7) = 137.</br> 
I profili sono riportati in figura, dove l’x-profilo per comodità è mostrato sullo sfondo della città.</br>
Usando la specifica data nel seguito sul formato di output dei profili, i profili sono identificati dalle seguenti liste
di vertici:</br>
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
12 0</br></br>
Si noti che per definizione ai profili appartengono sempre le rette corrispondenti agli assi cartesiani
x, y, dunque il segmento di estremi (0, 2, 0),(0, 3, 0) appartiene all’y-profilo della città.</br></br>
La costruzione della y-strada yS(5, 7) determina la parziale demolizione dei tre edifici E(5, 6, 6, 3, 5), E(13, 3, 1, 5, 3) e
E(13, 4, 1, 2, 4). In particolare l’edificio E(5, 6, 6, 3, 5) viene rimpiazzato dall’unico edificio E(5, 7, 6, 2, 5),
mentre l’edificio E(13, 3, 1, 5, 3) viene rimpiazzato dai due edifici E(13, 3, 1, 2, 3) e 
E(13, 7, 1, 1, 3) e l’edificio E(13, 4, 1, 2, 4) dall’edificio E(13, 4, 1, 1, 4).</br></br>
L’y-profilo viene alterato dalla costruzione di yS(5, 7) eliminando da esso tutti i punti della forma (0, y, z) per 5 < y < 7, 
mentre in questo caso l’x-profilo rimane inalterato.</br></br> 
La costruzione della y-strada yS(4, 7) determina invece la completa demolizione dell’edificio 
E(13, 4, 1, 2, 4) (che viene rimpiazzato da ∅) e l’alterazione anche dell’x-profilo che in tal modo perde tutti
i punti (x, 0, z) con 13 < x < 14, 3 < z ≤ 4.</br></br>
Si richiede di implementare una struttura dati efficiente che permetta di eseguire le operazioni seguenti
(si tenga presente che la minima porzione rettangolare di piano contenente tutte le basi di edifici è in
genere molto grande rispetto al numero di edifici, quindi non è sicuramente efficiente rappresentare il
piano mediante una matrice).</br></br>
- crea()</br>
Crea una città inizialmente vuota, distruggendo tutti gli edifici attualmente presenti.</br>
- inserisci(x0, y0, lx, ly, h)</br>
Inserisce nella città l’edificio E(x0, y0, lx, ly, h).</br>
- elimina(x, y)</br>
Elimina dalla città ogni edificio la cui base contiene il punto (x, y, 0).</br>
- isolati()</br>
Restituisce il numero di isolati presenti in città.</br>
- volume(x, y)</br>
Restituisce il volume dell’isolato contenente il punto (x, y, 0). Restituisce 0 se (x, y, 0) non appartiene ad alcun edificio.</br>
- x-profilo()</br>
Restituisce l’x-profilo della città secondo il formato specificato nell’apposita sezione.</br>
- y-profilo()</br>
Restituisce l’y-profilo della città secondo il formato specificato nell’apposita sezione.</br>
- y-strada(y0, y1)</br>
Costruisce la y-strada yS(y0, y1).</br>
- x-strada(x0, x1)</br>
Costruisce la x-strada xS(x0, x1).</br></br>
<b>Specifiche di implementazione</b></br></br>
Il programma deve leggere dallo standard input (stdin) una sequenza di linee (separate da \n), ciascuna
delle quali corrisponde a una linea della prima colonna della Tabella 1, dove x, y, l, m, h sono numeri naturali
e i vari elementi sulla linea sono separati da uno o più spazi. Quando una linea è letta viene eseguita
l’operazione ad essa associata e viene stampato l’eventuale output prodotto dall’esecuzione dell’operazione
associata; tutte le operazioni di stampa sono effettuate sullo standard output (stdout) e ogni operazione
deve iniziare su una nuova linea.</br></br>
Formato per l’output di profili di città</br>
Siano xmin e xmax rispettivamente le ascisse minima e massima dei punti appartenenti alle x-proiezioni
degli edifici della città. Sia H il sottoinsieme dell’x-profilo della città costituito dai punti (x, 0, z)
per i quali vale xmin ≤ x ≤ xmax. H è l’unione di un numero finito di rettangoli e del segmento
{(x, 0, 0) | xmin ≤ x ≤ xmax}: H è connesso e il suo contorno è dunque una successione finita di segmenti,
alternatamente orizzontali (aventi z costante) e verticali (aventi x costante).</br></br>
L’intersezione di ogni coppia di segmenti consecutivi origina un vertice (x, 0, z) ∈ Z3.</br></br>
Sia (x1, 0, z1) il primo di tali vertici secondo l’ordine lessicografico: (x, 0, z) < (x0, 0, z0) se e solo se
(x < x0) o (x = x0e z < z0).</br>
Necessariamente z1 = 0 e x1 = xmin. Il vertice (x1, 0, z1) sarà il primo vertice della nostra presentazione di H.</br>
Dato l’i-esimo vertice (xi, 0, zi), l’(i + 1)-esimo vertice sarà il vertice immediantamente successivo a (xi, 0, zi)
nella visita dei vertici di H in ordine orario. L’ultimo vertice (xu, 0, zu) di H è (xmax, 0, 0).</br></br>
Avendo costruito la successione (x1, 0, z1),(x2, 0, z2), . . . ,(xi, 0, zi), . . . ,(xu, 0, zu) dei vertici di H,
la si 4 Linea di input Operazione c crea () i x y l m h inserisci (x, y, l, m, h) e x y elimina (x, y)
I isolati ()</br>
v x y volume (x, y)</br>
x x-profilo ()</br>
y y-profilo ()</br>
Y x y y-strada (x, y)</br>
X x y x-strada (x, y)</br>
f Termina l’esecuzione del programma</br>
Tabella 1: Specifiche del programma</br>
emetta in output secondo il formato seguente:</br>
x1 z1</br>
x2 z2</br>
.</br>
.</br>
.</br>
.</br>
.</br>
.</br>
xi zi</br>
.</br>
.</br>
.</br>
.</br>
.</br>
.</br>
xu zu</br></br>
Analoghe specifiche si applicano all’output di y-profili considerando vertici della forma (0, y, z) al posto
di (x, 0, z) ed adattando le precedenti definizioni in modo naturale.</br></br>
<b>Nota:</b> Non devono essere presenti vincoli sulla dimensione del piano, degli edifici e delle strade e sul
numero di edifici (se non quelli determinati dal tipo di dato intero).</br></br>
Non si richiede – anzi si sconsiglia – l’uso di grafica, se non per test personali: in modo particolare, non si usi conio.h e neppure clrscr().</br>
Nota: Per semplicità si suppone che l’input sia sempre conforme alle specifiche di Tabella 1, per cui non è necessario controllare la correttezza dell’input.</br></br>
<b>Esempio</b></br>
Si supponga che le linee di input siano:</br>
c</br>
i 4 6 5 6 2</br>
i 2 8 14 2 4</br>
i 13 4 2 7 7</br>
I</br>
i 11 13 2 2 7</br>
5</br>
I</br>
v 2 10</br>
x</br>
y</br>
X 6 8</br>
I</br>
v 5 10</br>
e 5 10</br>
I</br>
Y 13 15</br>
I</br>
x</br>
f</br></br>
L’output prodotto dal programma deve essere:</br>
1</br>
2</br>
234</br>
2 0</br>
2 4</br>
11 4</br>
11 7</br>
15 7</br>
15 4</br>
16 4</br>
16 0</br>
4 0</br>
4 7</br>
11 7</br>
11 2</br>
12 2</br>
12 0</br>
13 0</br>
13 7</br>
15 7</br>
15 0</br>
3</br>
48</br>
2</br>
1</br>
8 0</br>
8 4</br>
13 4</br>
13 7</br>
15 7</br>
15 4</br>
16 4</br>
16 0</br>
