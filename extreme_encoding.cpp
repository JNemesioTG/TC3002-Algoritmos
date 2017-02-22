#include <stdio.h>

int main(void)
{
	char wait;
	int T = 0;		//Numero de "Tests"
	int n = 0;		//Tamaño del Arreglo
//  int a,b;

	int a[10000];		// (1<= a <= 10,000)
	int b[10000];		// (1<= b <= 10,000)

	int i = 0;      //Integer para iterar
	int j = 0;		//Integer para iterar

	scanf_s("%d", &T);

	for (i = 0; i < T; i++) {  //Por cada test hacer "T" repeticiones
		scanf_s("%d", &n);		//Escanea el tamaño del array ("n" espacios en el array)

		for (j = 0; j < n; j++) {	//Por cada espacio en el array...
			scanf_s("%d", &a[j]);		//Escanea los enteros que debe meter en el espacio "j" del array "a"

			b[j] = a[j] >> 16;		//El numero en el espacio "j" de "a" se introduce en el espacio "j" de "b" pero recorriendo bits al lado derecho
									// a[j] >> 16  == a[j] >>1 >>1 >>1 >>1
			a[j] = a[j] - (b[j] << 16);	  //Como "a" esta aun intacta, y "b" fue desplazada a la derecha 
										  //se deshace de los bits menos significativos 
										  // es decir _ _ _ _ 1 0 0 1 1 0 1 0 _ _ _ _ seria el contenido en bits haciendo cada _ un 0
										  // por lo que la diferencia al restar es el arreglo "a"
//			printf("%d",b[j]);
		}

		printf("Case %d:\n", i + 1);		//Impresion con formato
		for (j = 0; j < n; j++) {
			printf("%d ", a[j]);			//Imprime a[j]
		}

		printf("\n");
		for (j = 0; j < n; j++) {			//Imprime b[j]
			printf("%d ", b[j]);
		}

		printf("\n");
	}

	scanf_s("%d", &wait);		// Espera un momento para ver el resultado

	return 0;
}
