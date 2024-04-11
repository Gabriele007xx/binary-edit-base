
#include<stdlib.h>
#include<stdio.h>

int main() {
  FILE *fd;
  int x=12;

			/* apre il file */
  fd=fopen("test.dat", "w");
  if( fd==NULL ) {
    perror("Errore in apertura del file");
    exit(1);
  }


			/* scrive il numero */
  fwrite(&x, sizeof(int), 1, fd);


			/* incrementa e scrive */
  x++;
  fwrite(&x, sizeof(int), 1, fd);



			/* decrementa e scrive */
  x-=2;
  fwrite(&x, sizeof(int), 1, fd);


			/* chiude il file */
  fclose(fd);

  return 0;
}
