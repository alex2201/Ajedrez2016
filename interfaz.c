#include "interfaz.h"
void
setUp (void)
{
  char confirmacion = ' ';
  char buffer[4];
  system ("clear");
  printf
    ("Para mostrar las animaciones\n  necesitamos que instales un programa por nosotros,\n  su nombre es figlet, puedes instalarlo usando:\n\n  sudo apt-get install figlet\n\n  o bien podemos hacerlo por ti, presiona s para instalar(se te pedira tu contraseña)\n  o cualquier otra para no hacerlo, podras hacerlo despues. :)\n");
  fgets (buffer, 4, stdin);
  sscanf (buffer, "%c", &confirmacion);
  system ("clear");
  if (confirmacion == 's' || confirmacion == 'S')
    {
      printf ("Gracias, se isntalara a continuacion");
      system ("sudo apt-get install figlet");
    }
  system ("clear");
  printf ("Gracias por elegir este juego, disfrutalo");
  sleep (3);
}

void
animaciones (int n)
{
  switch (n)
    {
    case 1:
      system ("clear");
      system ("figlet 'Jaque!!'");
      sleep (2);
      system ("clear");
      break;
    case 2:
      system ("clear");
      system ("figlet 'JaqueMate!!'");
      sleep (2);
      system ("clear");
      break;
    case 3:
      system ("clear");
      system ("figlet 'Jugador 1 Gano!!'");
      sleep (2);
      system ("clear");
      break;
    case 4:
      system ("clear");
      system ("figlet 'Jugador 2 Gano!!'");
      sleep (2);
      system ("clear");
      break;
    case 5:
      system ("clear");
      system ("figlet 'Bienvenido'");
      sleep (2);
      system ("clear");
      break;
    case 6:
      system ("clear");
      system ("figlet 'Adios :)'");
      sleep (2);
      system ("clear");
      break;
    case 7:
      system ("clear");
      system ("figlet '.:Bienvenido:.'");
      sleep (2);
      system ("clear");
      break;
    default:
      break;
    }
}

void
letreros (int n)
{
  switch (n)
    {
    case 1:
      printf ("\n");
      system ("figlet '.:Ajedrez:.'");
      printf ("\n");
      break;
    default:
      break;
    }
}

void
menu ()
{
  /*hola aqui pondremos el menu, si ven que faltan opciones agreguenlas, por cierto, verifiquen que su editor no agregue nada más, en otras palabras, verifiquen que compile, el editor del ultimo que lo subio incerto diagonales de mas para que se visualizara el salto de linea, pero evitaba que compilara, ademas hay que pedir a los de archivos que nos creen persistencia para no ejecutar todo el tiempo el setup */
  char o = ' ';
  char buffer[4];
  system ("clear");
  animaciones (7);
  letreros (1);
  printf ("Escoge el numero de opcion\n");
  printf
    ("1) Nueva Partida\n2) Cargar Partida\n3) Configuracion\n4) Salir\n");
  fgets (buffer, 4, stdin);
  sscanf (buffer, "%c", &o);
  switch (o)
    {
    case '1':
      setUp ();
      system ("clear");
      break;
    case '4':
      animaciones (6);
      system ("clear");
      break;
    default:
      break;
    }

}

/*Esta función imprime el tablero en pantalla*/
void
imprimir_tablero (char tablero[8][8])
{

  int i = 0;
  int j = 8;
  char aux = 'A';

  printf ("\n\n");

  while (j > 0)
    {
      if (i == 0)
	{
	  printf (" %c ||", (aux + (j - 1)));
	}
      printf ("  %c  |", ajedrez->tablero[j - 1][i]);
      i = i + 1;

      if (i == 8)
	{
	  if (j != 1)
	    {
	      printf ("\n");
	      printf ("----");
	      i = 0;

	      while (i < 8)
		{
		  printf ("------");
		  i = i + 1;
		}
	    }
	  if (j == 1)
	    {
	      printf ("\n");
	      printf ("=====");
	      i = 0;

	      while (i < 8)
		{
		  printf ("======");

		  i = i + 1;
		}
	    }
	  printf ("\n");
	  i = 0;
	  j = j - 1;
	}
    }
  j = 8;
  i = 0;
  printf (">:v|| ");
  while (j > 0)
    {
      aux = '1';
      printf (" %c  | ", (aux + i));

      j = j - 1;
      i = i + 1;
    }
  printf ("\n\n");
}


int
main (int c, char **arg)
{
  menu ();
  return 0;
}
