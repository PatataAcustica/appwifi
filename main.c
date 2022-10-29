#include "appwifi.h"
#include "menu.h"
#include <stdbool.h>
#include <stdlib.h>

int main()
{
  int** arraycollect; //Array que contendrá el contenido de los archivos tras usar wificollector_collect()
  arraycollect = malloc(sizeof(int*)*21); //Reservamos espacio en memoria equivalente a 21 punteros a ints, uno por celda
  for(int it = 0; it < 21; it++)
  {
    arraycollect[it] = malloc(sizeof(int*)*500); //Reservamos espacio suficiente como para que quepa el texto de la celda entero
    *(arraycollect[it]) = 0; //Primer elemento de cada celda será 0 hasta que sea modificado, para identificar celdas vacías
    arraycollect[0][it] = 0; //arraycollect[0] reservado para identificar celdas vacías, ya que no corresponde a ningún archivo
  }
  while(true)
  {
    switch(printmenu())
    {
     case 1:
       if(wificollector_quit()) {goto exit;} //Termina el programa
       break;
      case 2:
       arraycollect = wificollector_collect();
       break;
      case 4:
       wificollector_select_best(arraycollect);
       break;
      /*case 5:
       wificollector_select_worst();
       break;*/
      case 10:
       wificollector_display(arraycollect);
       break;
      case 11:
       wificollector_display_all(arraycollect);
       break;
    }
  } 
  exit:
  freearraymem(arraycollect);
  return 0;
}
