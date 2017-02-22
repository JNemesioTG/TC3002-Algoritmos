#include <stdio.h>

int main()
{
	int t;
	long n;

	scanf_s("%d", &t); //Numero de pruebas que se haran para empaquetar.

	while (t != 0)  //Mientras aun haya pruebas por hacer...
	{
		scanf_s("%ld", &n); //Recibir el numero de cupcakes que hay hehcos por parte del usuario a travez de consola.
		printf("%ld\n", n / 2 + 1); //Regresa el numero de cupcakes que puede comer el cheff
									              //Dado que siempre tiene que comer la mayoria de cupcakes hechos
									              //La mayoria siempre sera la mitad de el total +1
									              //y puede empaquetar N cupcakes mientras sean iguales los paquetes
									              //Hace solo 1 paquete de N/2 -1 cupcakes.
		t--; //Reducir T para saber cuantas pruebas se han hecho.
	}
	return 0;
}
