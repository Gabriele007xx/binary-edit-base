
#include<stdlib.h>
#include<stdio.h>

int main() {
  FILE *fd;
  int x=12;

/* apre un file di testo già esistente per l’aggiornamento
(lettura e scrittura). */
	
  fp = fopen ("dati.bin", "rb+")
  if( fd==NULL ) {
    perror("Errore in apertura del file");
    exit(1);
  }


			/*Restituisce un valore maggiore di zero (valore Booleano true)
nel caso in cui l’indicatore di posizione si è portato in
corrispondenza del marcatore finale end-of-file, e 0 altrimenti
(valore Booleano false). */
	feof(fp);
	/*
 size_t fwrite (void *buffer, size_t n_byte, size_t num, FILE *pf);
 buffer rappresenta l’indirizzo iniziale della regione di memoria che
contiene i dati da scrivere sullo stream binario riferito da pf.
• Il valore di num determina il numero di oggetti di ampiezza n_byte
byte da scrivere sullo stream. Dunque, la regione di memoria allocata
puntata da buffer deve avere un’ampiezza di almeno n_byte * num
byte.
• In caso di successo, il valore di ritorno indica il numero di oggetti
effettivamente inviati allo stream. Altrimenti, il valore restituito è un
numero negativo. 
 	*/
  fwrite(&x, sizeof(int), 1, fd);
/*
size_t fread (void *buffer, size_t n_byte, size_t num, FILE *pf);
• buffer rappresenta l’indirizzo iniziale della regione di memoria su cui
scrivere i dati letti dallo stream binario riferito da pf.
• Il valore di num determina il numero di oggetti di ampiezza n_byte
byte da leggere dallo stream. Dunque, la regione di memoria allocata
puntata da buffer deve avere un’ampiezza di almeno n_byte * num
byte.
• In caso di successo, il valore di ritorno indica il numero di oggetti
effettivamente letti dallo stream. Altrimenti, il valore restituito è un
numero negativo. 
*/
	int cont=0;
	fread(&cont, sizeof(int), 1, fd);

	/*
 int fseek(FILE *pf, long offset, int origine);
• Imposta l’indicatore di posizione dello stream associato a pf (in termini
di numero di byte dall’inizio dello stream). La prossima operazione di
I/O sullo stream verrà eseguita dalla nuova posizione impostata.
• La posizione è calcolata aggiungendo offset (che può assumere anche
valori negativi) a origine. Il parametro origine può assumere i seguenti
valori:
• SEEK_SET: indica l’inizio del file.
• SEEK_CUR: indica la posizione corrente.
• SEEK_END: indica la fine del file.
• In caso di successo, restituisce 0 e viene cancellato l'indicatore di
fine file. Altrimenti, restituisce -1. 
 */
	fseek(fp, 10, 0);
	/*
 	int ftell(FILE *pf);
Restituisce il valore corrente dell'indicatore di posizione dello stream
associato a pf (posizione corrente rispetto all’inizio del file, espressa come
numero di byte).
 	*/
int pos = ftell(fp);

			/* chiude il file */
  fclose(fd);

  return 0;
}
