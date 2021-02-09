#include "malloc.h"
#include "stdio.h"
#include "stddef.h"
#include "stdlib.h"
//#include "conio.h"
#include "time.h"
#include "graphics.h"
#define MAX 25000

/* 	Progetto Skyline Moroni GianLuca matricola 581148 */

struct nodoEdificio {
	int  x;
	int  Dx;
	int  Dy;
	struct nodoEdificio* prox;
};

struct nodoSkyline {
	long int  x;
	long int  y;
	struct nodoSkyline* prox;
};

#define clrscr(); system("cls");
typedef struct nodoEdificio  NODOEDIFICIO;
typedef struct nodoSkyline* PUNTSKYLINE;
typedef struct nodoSkyline   NODOSKYLINE;
typedef struct nodoEdificio* PUNTEDIFICIO;

void Esperimento(int  n, int  M, int  H, int  B, int  k, int  a[]);
void VisualizzaCitta(PUNTEDIFICIO edificio, int  n);
void VisualizzaSkyline(PUNTSKYLINE skyline, int  n);
PUNTEDIFICIO InserimentoEdificio(PUNTEDIFICIO, int n, int pos, int bas, int alt);
PUNTEDIFICIO EliminazioneEdificio(PUNTEDIFICIO, int pos, int bas, int alt);
PUNTSKYLINE NuovoNodo(PUNTSKYLINE p, long int x, long int y);
PUNTSKYLINE CalcolaSkyline(int a[], int n);
void InserisciCoordinate(int a[], int n, PUNTEDIFICIO punt_lista);
int CostruisciCitta(int n, PUNTSKYLINE puntskyline, PUNTEDIFICIO punt_lista, int a[]);
long int LunghezzaSkyline(PUNTSKYLINE puntskyline, int  n);
PUNTEDIFICIO CittaRandom(PUNTEDIFICIO, int M, int n, int H, int B);

char modo, cittaSi;
int scelta = -1;
//extern unsigned _stklen = 10000;  /* aumento lo stack individuato dalla variabile globale _stklen */
											 /* perche' se no ho problemi con il buffer grafico              */

void main(void)
{
	initwindow(640, 480);
	PUNTSKYLINE puntskyline = NULL, daDeallocare = NULL;
	PUNTEDIFICIO punt_lista = NULL, DaDeallocare;
	int  ind = 0, n = MAX, pos, bas, alt, H, B, M, k;
	long int lung;
	static int a[MAX + 1];
	char pausa;

	setbkcolor(YELLOW);
	srand(time(NULL));	/* Inizializzazzione rand */
	while (scelta != 0) {
		clrscr();
		printf("\n");
		printf("\nPROGETTO SKYLINE");
		printf("\n\n\nMoroni Gianluca matricola 581148\n");
		printf("\n\n\n 1. Costruisci Citta");
		printf("\n 2. Visualizza Citta");
		printf("\n 3. Inserisci Edificio");
		printf("\n 4. Elimina Edificio");
		printf("\n 5. Citta Random");
		printf("\n 6. Calcola skyline");
		printf("\n 7. Visualizza Skyline");
		printf("\n 8. Lunghezza Skyline");
		printf("\n 9. Esperimento");
		printf("\n 0. Per finire");
		printf("\n\n Scegliere una opzione: ");
		scanf("%d", &scelta);

		switch (scelta) {
		case 1:
			clrscr();
			printf("\nImmetti dimensione citta max %d: ", MAX);
			scanf("%d", &n);
			n = CostruisciCitta(n, puntskyline, punt_lista, a);
			punt_lista = NULL;
			puntskyline = NULL;
			break;
		case 2:
			clrscr();
			VisualizzaCitta(punt_lista, n);
			break;
		case 3:
			clrscr();
			printf("\nLa citta ha diametro %d l'edificio non viene inserito se le sue dimensioni", n);
			printf("\nsono incompatibili (posizione + base) <= diametro citta");
			printf("\n\nInserisci posizione, base, altezza:");
			scanf("%d,%d,%d", &pos, &bas, &alt);
			punt_lista = InserimentoEdificio(punt_lista, n, pos, bas, alt);
			break;
		case 4:
			clrscr();
			printf("\nInserisci l'informazione da eliminare: ");
			printf("\nPosizione, base, altezza:");
			scanf("%d,%d,%d", &pos, &bas, &alt);
			punt_lista = EliminazioneEdificio(punt_lista, pos, bas, alt);
			break;
		case 5:
			clrscr();
			printf("\nImmetti la dimensione della citta' max %d:", MAX);
			scanf("%d", &n);
			n = CostruisciCitta(n, puntskyline, punt_lista, a);
			punt_lista = NULL;
			puntskyline = NULL;
			printf("\nImmetti numero edifici:");
			scanf("%d", &M);
			printf("\nImmetti altezza massima degli edifici: ");
			scanf("%d", &H);
			do {
				printf("\nImmetti massima base degli edifici (base <= %d)", n);
				scanf("%d", &B);
			} while (!(B <= n));
			printf("\nSto creando la citta");
			punt_lista = CittaRandom(punt_lista, M, n, H, B);
			break;
		case 6:
			while (puntskyline != NULL)           /* ad ogni ricalcolo della skyline */
			{                                   /* dealloco tutti i nodi della     */
				daDeallocare = puntskyline;     /* vecchia skyline                 */
				puntskyline = puntskyline->prox;
				free(daDeallocare);
			}
			for (ind = 0; ind <= n; ind = ind + 1) a[ind] = 0; /* azzero l'array con le ordinate  */
			InserisciCoordinate(a, n, punt_lista);       /* lancio la procedura che calcola */
			puntskyline = CalcolaSkyline(a, n);         /* le nuove ordinate e poi quella  */
			break;                                     /* che calcola la skyline          */
		case 7:
			clrscr();
			printf("\nVisualizzazzione a Punti o Grafica :");
			modo = getch();
			if (modo == 'g') {
				printf("\n\nVuoi vedere anche la citta sotto la skyline (s/n): ");
				cittaSi = getch();
				if (cittaSi == 's')
					VisualizzaCitta(punt_lista, n);
			}
			VisualizzaSkyline(puntskyline, n);
			break;
		case 8:
			clrscr();
			lung = LunghezzaSkyline(puntskyline, n);
			printf("\nLa Skyline e' lunga: %ld  unita'", lung);
			scanf("%c%c", &pausa, &pausa);
			break;
		case 9:
			clrscr();
			printf("\nQuante iterazioni: ");
			scanf("%d", &k);
			printf("\nImmetti la dimensione della citta' max %d:", MAX);
			scanf("%d", &n);
			printf("\nImmetti numero edifici:");
			scanf("%d", &M);
			printf("\nImmetti altezza massima degli edifici: ");
			scanf("%d", &H);
			do {
				printf("\nImmetti massima base degli edifici (base <= %d)", n);
				scanf("%d", &B);
			} while (!(B <= n));
			Esperimento(n, M, H, B, k, a);
			printf("\n\nPremi un tasto");
			scanf("%c", &pausa);
			break;
		} /* end switch */
	} /* end while */
	while (puntskyline != NULL)
	{                               /* dealloco tutti i nodi della vecchia */
		daDeallocare = puntskyline;    /* skyline e della lista edifici       */
		puntskyline = puntskyline->prox;
		free(daDeallocare);
	}
	while (punt_lista != NULL)
	{
		DaDeallocare = punt_lista;
		punt_lista = punt_lista->prox;
		free(DaDeallocare);
	}
} /* end main */

/* Inserimento del valore passato dall'utente nella lista degli edifici */
/* mantenendo l'ordinamento                                             */

PUNTEDIFICIO InserimentoEdificio(PUNTEDIFICIO p, int n, int pos, int bas, int alt)
{
	PUNTEDIFICIO p0, p1;
	int  posizione;

	/* Creazione nodoEdificio */

	p0 = (PUNTEDIFICIO)malloc(sizeof(NODOEDIFICIO));

	if ((pos + bas) <= n) {
		p0->x = pos;
		p0->Dx = bas;
		p0->Dy = alt;

		if (p == NULL) {	/* Se la lista e' vuota, il nodoEdificio diventa il primo */
			p = p0;		/* e unico della lista                                    */
			p->prox = NULL;
		}
		else {
			if (p->x > p0->x) {     /* Se il valore dell'nodoEdificio e' */
				p0->prox = p;	     /* inferiore al primo l'nodoEdificio */
				p = p0;             /* diventa il primo della lista  */
			}
			else {                 /* Ricerca della posizioe di inserimento */
				p1 = p;
				posizione = 0;
				while (p1->prox != NULL && posizione != 1) {
					if (p1->prox->x < p0->x)
						p1 = p1->prox;	/* scorre avanti p1	*/
					else
						posizione = 1;	/* interrompe lo scorrimento */
				}/* end while */
				p0->prox = p1->prox; /* connessione al nodoEdificio successivo   */
				p1->prox = p0; 	   /* connessione dal nodoEdificio precedente  */
			}
		}
	}
	return(p);	/* Ritorno del puntatore all'inizio della lista */
}

/* Eliminazione dell'Edificio richiesto dalla lista ordinata degli edifici */

PUNTEDIFICIO EliminazioneEdificio(PUNTEDIFICIO p, int  pos, int  bas, int  alt)
{
	PUNTEDIFICIO p1 = p, p2;
	NODOEDIFICIO elim;
	int  posizione = 0;
	char pausa;

	elim.x = pos;
	elim.Dx = bas;
	elim.Dy = alt;

	if (p1 != NULL) { /* Se la lista e' vuota fine */
		if ((p1->x == elim.x) && (p1->Dx == elim.Dx) && (p1->Dy == elim.Dy)) {
			p2 = p1;     /* Se e' il primo da eliminare         */
			p = p->prox; /* si modifica il puntatore alla testa */
			free(p2);
			return(p);
		}
		else {	      /* Ricerca dell'nodoEdificio da eliminare */
			while (p1->prox != NULL && posizione != 1) {
				if (p1->prox->x != elim.x) /* se non hanno la stessa posizione */
					p1 = p1->prox; 				/* scorre in avanti p1 */
				else {
					if ((p1->prox->Dy == elim.Dy) && (p1->prox->x == elim.x))
					{     /* hanno la stessa posizione allora controlla     */
							/* se sono uguali in altezza e in base,cancellalo */
						posizione = 1; 			   /* interrompe lo scorrimento */
						p2 = p1->prox;
						p1->prox = p1->prox->prox;  /* eliminazione nodoEdificio */
						free(p2);					    /* libera la memoria         */
						return(p);
					}
					else
						p1 = p1->prox;                /* scorri in avanti p1 */
				}
			}
		}
	}

	if (!posizione) {
		printf("\nEdificio non presente ");
		scanf("%c%c", &pausa, &pausa);
	}
	return(p);
}

/* Costruisce una citta di dimensione n */

int CostruisciCitta(int n, PUNTSKYLINE puntskyline, PUNTEDIFICIO punt_lista, int a[])
{
	int  ind;
	PUNTSKYLINE daDeallocare;
	PUNTEDIFICIO DaDeallocare;

	for (ind = 0; ind <= n; ind = ind + 1) a[ind] = 0;
	while (puntskyline != NULL)         /* ad ogni nuova generazione di una citta' */
	{                                 /* dealloco tutti i nodi della vecchia     */
		daDeallocare = puntskyline;      /* skyline e della lista edifici e azzero  */
		puntskyline = puntskyline->prox; /* l'array con le ordinate                 */
		free(daDeallocare);
	}
	while (punt_lista != NULL)
	{
		DaDeallocare = punt_lista;
		punt_lista = punt_lista->prox;
		free(DaDeallocare);
	}
	return n;
}

/* Inserisce le coordinate dell'edificio nell'array citta */
/* per la calcola skyline */

void InserisciCoordinate(int a[], int n, PUNTEDIFICIO p)
{
	int  x;
	PUNTEDIFICIO punt = p;
	while (punt != NULL) {
		for (x = punt->x; (x <= (punt->x + punt->Dx)) && (x <= n); ++x)
			if (a[x] < punt->Dy)
				a[x] = punt->Dy;
		punt = punt->prox;
	}
}

/* Inserisce un nuovo nodo della skyline in fondo ai precedenti */

PUNTSKYLINE NuovoNodo(PUNTSKYLINE p, long int x, long int y)
{
	PUNTSKYLINE p0, p1;

	/* Creazione elemento */

	p0 = (PUNTSKYLINE)malloc(sizeof(NODOSKYLINE));
	p0->x = x;
	p0->y = y;
	p0->prox = NULL;

	if (p == NULL) {	/* Se la lista e' vuota, l'elemento diventa il primo */
		p = p0;     /* e unico della lista */
		p->prox = NULL;
	}
	else {
		p1 = p;
		while (p1->prox != NULL)
			p1 = p1->prox;	    /* scorre avanti p1	*/
		p1->prox = p0; 	    /*connessione dall'elemento precedente */
	}

	return(p);	                /* Ritorno del puntatore all'inizio della lista */
}

/* Calcola la skyline della citta */

PUNTSKYLINE CalcolaSkyline(int a[], int n)
{
	int  x = 0; /* indice array */
	PUNTSKYLINE sky = NULL;
	sky = NuovoNodo(sky, 0, 0);
	if (a[0] != 0)
		sky = NuovoNodo(sky, 0, a[0]);
	for (x = 1; x <= n; ++x) {
		if (a[x - 1] < a[x]) {/* se l'ordinata precedente era < di quella attuale */
			sky = NuovoNodo(sky, x, a[x - 1]);
			sky = NuovoNodo(sky, x, a[x]);
		}
		else                /* se l'ordinata precedente era > di quella attuale */
			if (a[x - 1] > a[x]) {
				sky = NuovoNodo(sky, (x - 1), a[x - 1]);
				sky = NuovoNodo(sky, (x - 1), a[x]);
			}
	}
	if (((x - 1) == n) && (a[x - 1] != 0))             /* se e' finita la citta con un */
		sky = NuovoNodo(sky, (x - 1), a[x - 1]);      /* edificio sul bordo */
	sky = NuovoNodo(sky, (x - 1), 0);

	return sky;
}

void VisualizzaSkyline(PUNTSKYLINE skyline, int n)
{
	PUNTSKYLINE vis = skyline;
	char pausa;
	int  x, y;

	/* Richiedi individuazione automatica dell'adattatore grafico */
	int gdriver = DETECT, gmode, errorcode;

	if (modo == 'p') {
		printf("\nStampa della skyline");
		printf("\n\n");
		while (vis != NULL) {
			printf("%ld,%ld\t", vis->x, vis->y);
			vis = vis->prox;
		}
		scanf("%c%c", &pausa, &pausa);
	}
	else {
		if (modo == 'g') {
			if (!(cittaSi == 's')) {
				//initwindow(640, 480);
				setcolor(YELLOW);
				/* Inizializza il modo grafico */
				/* e cerca il driver video nella directory corrente */
				//initgraph(&gdriver, &gmode, "");
				/* Controlla se ci sono errori */
				errorcode = graphresult();
				if (errorcode != grOk) { /* C'e' un errore */
					printf("\nErrore grafico: %s\n", grapherrormsg(errorcode));
					printf("Premi un tasto per finire.");
					getch();
					exit(1);
				}
			}

			setcolor(8);
			x = 0; y = 0;             /* si suppone una risoluzione di 640*480 */
			line(x, 479, n, 479); /* linea di terra */
			setcolor(14);
			x = skyline->x;
			y = skyline->y;
			while (skyline != NULL)  /* traccia i nodi della skyline */
			{                      /* invertendo l'asse y della modalita grafica */
				line(x, (-y + 479), skyline->x, (-(skyline->y) + 479));
				x = skyline->x;
				y = skyline->y;
				skyline = skyline->prox;
			}
			/* Chiudi tutto */
			getch();
			closegraph();
		}
	}
}

/* Calcola la lunghezza della skyline */

long int  LunghezzaSkyline(PUNTSKYLINE puntskyline, int n)
{
	long int  lung = 0;

	PUNTSKYLINE p = puntskyline;
	while (p->prox != NULL) {
		if ((p->prox->x) == (p->x)) {               /* se hano la stessa ascissa */
			if ((p->prox->y) > (p->y))				     /* se l'ordinata successiva e maggiore */
				lung = lung + ((p->prox->y) - (p->y));  /* calcola il segmento y successivo - y corrente */
			else									           /* altrimenti */
				lung = lung + ((p->y) - (p->prox->y));  /* calcola il segmento y corrente - y successivo */
		}
		else {										        /* analogo per le ordinate */
			if ((p->prox->y) == (p->y)) {
				if ((p->prox->x) > (p->x))
					lung = lung + ((p->prox->x) - (p->x));
				else
					lung = lung + ((p->x) - (p->prox->x));
			}
		}
		p = p->prox;
	}
	lung = lung + (n - (p->x)); /* perche' considero anche l'ultimo pezzo di terreno */
	return lung;
}

/* Visualizza gli edifici a video oppure come lista */

void VisualizzaCitta(PUNTEDIFICIO edificio, int  n)
{
	PUNTEDIFICIO puntedificio = edificio;
	char pausa;
	int  num = 1;
	/* Richiedi individuazione automatica dell'adattatore grafico */
	int gdriver = DETECT, gmode, errorcode;

	if (scelta != 7) {
		printf("\nVisualizzazzione a Elenco o Grafica :");
		modo = getch();
	}

	if (modo == 'e')
	{
		clrscr();
		printf("\nElenco edifici presenti nella citta :");
		printf("\n\n");
		while (puntedificio != NULL) {
			printf("\nEdificio%7d: ", num);
			printf("     Posizione:%7d", puntedificio->x);
			printf("     Base: %7d", puntedificio->Dx);
			printf("     Altezza: %7d", puntedificio->Dy);
			++num;
			puntedificio = puntedificio->prox;
		}
		scanf("%c%c", &pausa, &pausa);
	}
	else {						  /* per ogni edificio si calcola le coordinate e */
		if (modo == 'g')		  /* poi ne traccia i lati                        */
		{
			setcolor(YELLOW);
			/* Inizializza il modo grafico e */
			/* cerca il driver video nella directory corrente */
			//initgraph(&gdriver, &gmode, "");
			/* Controlla se ci sono errori */
			errorcode = graphresult();
			if (errorcode != grOk) { /* C'e' un errore */
				printf("\nErrore grafico: %s\n", grapherrormsg(errorcode));
				printf("Premi un tasto per finire.");
				getch();
				exit(1);
			}
			setcolor(8);             /* si suppone una risoluzione di 640*480 */
			line(0, 479, n, 479);
			setcolor(7);
			while (edificio != NULL) {
				line(edificio->x, 479, edificio->x, (-edificio->Dy + 479));
				line(edificio->x, (-edificio->Dy + 479), (edificio->x + edificio->Dx), (-edificio->Dy + 479));
				line((edificio->x + edificio->Dx), (-edificio->Dy + 479), (edificio->x + edificio->Dx), 479);
				edificio = edificio->prox;
			}
			/* Chiudi tutto */
			if (scelta != 7) {
				getch();
				closegraph();
			}
		}
	}
}

PUNTEDIFICIO CittaRandom(PUNTEDIFICIO punt_lista, int  M, int  n, int  H, int  B)
{
	int  i, x, y, z;

	for (i = 0; i < M; ++i)
	{
		x = ((rand() % B) + 1); /* genero la base tra 1 e B */
		y = ((rand() % H) + 1); /* genero l'altezza tra 1 e H */
		z = ((rand() % ((n + 1) - x))); /* genero la posizione considerando la */
											 /* base e il diametro tra 0 e n        */
		punt_lista = InserimentoEdificio(punt_lista, n, z, x, y);
	}
	return (punt_lista);
}

void Esperimento(int n, int M, int H, int B, int k, int a[])
{
	char pausa;
	int i, ind;
	long int lung, TotLung = 0;
	double r, s, t, TempTotRand = 0.0, TempTotCalc = 0.0;
	PUNTSKYLINE daDeallocare, puntskyline;
	PUNTEDIFICIO punt_lista, DaDeallocare;

	punt_lista = NULL;
	puntskyline = NULL;
	for (i = 0; i < k; ++i)
	{
		r = 0.0;
		s = 0.0;
		t = 0.0;
		lung = 0;
		r = clock();
		n = CostruisciCitta(n, puntskyline, punt_lista, a);
		punt_lista = NULL;
		puntskyline = NULL;
		printf("\n\nSto creando la citta");
		punt_lista = CittaRandom(punt_lista, M, n, H, B);
		s = clock();
		while (puntskyline != NULL)         /* ad ogni ricalcolo della skyline */
		{                                 /* dealloco tutti i nodi della     */
			daDeallocare = puntskyline;    /* vecchia skyline                 */
			puntskyline = (puntskyline)->prox;
			free(daDeallocare);
		}
		for (ind = 0; ind <= n; ind = ind + 1) a[ind] = 0; /* azzero l'array con le ordinate  */
		InserisciCoordinate(a, n, punt_lista);       /* lancio la procedura che calcola */
		puntskyline = CalcolaSkyline(a, n);         /* le nuove ordinate e poi quella  */
		t = clock();
		printf("\n\nIterazione n %d", i + 1);
		printf("\nTempo per l'esecuzione di CittaRandom    %.3lf secondi", ((s - r) / CLOCKS_PER_SEC));
		printf("\nTempo per l'esecuzione di CalcolaSkyline %.3lf secondi", ((t - s) / CLOCKS_PER_SEC));
		lung = LunghezzaSkyline(puntskyline, n);
		printf("\nLa skyline e' lunga: %ld", lung);
		TempTotRand += ((s - r) / CLOCKS_PER_SEC);
		TempTotCalc += ((t - s) / CLOCKS_PER_SEC);
		TotLung += lung;
	}
	printf("\n\nPremi un tasto");
	scanf("%c%c", &pausa, &pausa);
	clrscr();
	printf("\n\nRapporto finale");
	printf("\n\nLa media dei tempi di esecuzione per CittaRandom    e':%.3lf", (TempTotRand / k));
	printf("\nLa media dei tempi di esecuzione per CalcolaSkyline e':%.3lf", (TempTotCalc / k));
	printf("\nLa lunghezza media delle Skyline e'                   :%ld unita'", (TotLung / k));
	for (ind = 0; ind <= n; ind = ind + 1) a[ind] = 0;
	while (puntskyline != NULL)           /* alla fine dell'esperimento dealloco */
	{                                   /* tutti i nodi della vecchia skyline e*/
		daDeallocare = puntskyline;      /* della lista edifici e azzero        */
		puntskyline = puntskyline->prox;	/* l'array con le ordinate             */
		free(daDeallocare);
	}
	while (punt_lista != NULL)
	{
		DaDeallocare = punt_lista;
		punt_lista = punt_lista->prox;
		free(DaDeallocare);
	}
}