# [TC3002] - Project Management Dynamic

## Algoritmo #1: Packaging Cupcakes

Link de Codechef:
https://www.codechef.com/problems/MUFFINS3

### Descripción

El problema es el siguiente: Un chef termina de cocinar uns panqués pero ahora debe decidir cuantos guardar en cada paquete, y todos los paquetes deben de tener el mismo número de panqués. Al chef también le encanta comer sus panqués, entonces debe de hacer tantos paquetes como le sea posible del número que haya escogido previamente de producto por paquete para poder comerse los que sobran. ¿Qué tamaño de paquete deja que el chef coma la mayor cantidad de panqués?

### Input y Output

##### Input:
  - En la primera lines va el número de casos ***t***
  - Por cada caso habra una linea que diga el número de panques hechos
##### Output:
  - Una linea por cada caso que te de el número de panqués por paquete que te deja el mayor número de panques de sobra
##### Ejemplo:
**Input:**
```
2
2
5
```
**Output:**
```
2
3
```

### Solución
La solución es sencilla, como el chef quiere comer la mayor cantidad de panqués se puede hacer un paquete que sea la mitad de los panques más uno, así ya se tienen más de la mitad y por lo tanto no se puede hacer un paquete nuevo, y de esta manera el cheff se queda con la mitad de los panqués que hizo menos uno. En el código ponemos hacerlo con dos lineas para cada caso:
```c
scanf("%ld", &n);
printf("%ld\n", n / 2 + 1);
```
Donde ***n*** es la cantidad total de panqués hechos.

Para poder correr todos los casos que se piden en el input, solo se hace una función ***for()*** que lea el input e imprima output en cada iteración (que representa el número de casos).


---


## Algoritmo #2: Chef Under Pressure

Link de Codechef:
https://www.codechef.com/problems/CHEFPRES

### Descripción

El chef llega a vivir a un reino que contiene ***N*** número de ciudades, donde todas están conectadas por carretereas bidireccionales de manera que cada ciudad tiene un camino con cada otra ciudad. El rey tienen un monopolio sobre el comercio y sus reglas dicen que cada ciudadano de una ciudad dada no puede vender más de un producto, haciendo que se vendan ***K*** productos diferentes en el reino.

Se pueden numerar el número de ciudades de ***1*** a ***N*** y los producgtos de ***1*** a ***K***. El rey vive en la ciudad capital, ciudad ***B***. Por cada ciudad ***i***, producto vendido ahí se denota ***F(i)***.

El chef se establece en la ciudad ***A*** quiere crear una nueva receta que utilizara el producto ***P***, el cual puede no estar disponible en la ciudad en la que él vive. El chef tendrá que viajar a la ciudad en la que se encuentra el producto, llamada ciudad ***C***, pero no quiere tratar con el rey, entonces intetara evitar la ciudad ***B*** a toda costa.

Para cada ciudad ***i***, ***G(i)*** es la distancia mínima entre ***B*** y cualquier otra ciudad en el camino único conectando las ciudades ***A*** e ***i***. El chef quiere viajar a la ciudad ***C*** tal que:
  - ***F(C)=P***
  - No haya otra ciudad ***D*** que tenga ***F(D)=P*** y ***G(D) > G(C)***

Si hay varias ciudades con esta propieda, el chef escogera la de menor número. Existe la posibilidad de que ***C = A*** y que el chef no tenga que viajar.

Como chef aun no decide en que ciudad vivir ni que receta nueva crear, se requiere contestar varias interrogantes de: si el vive en la ciudad ***A*** y necesita el producto ***P***, ¿A que ciudad debe ir a comprarlo?


### Input y Output

##### Input:
  - En la primera lines van dos número ***N*** y ***K*** que representan las ciudades y productos respectivamente.
  - La segunda linea tendra un número que representa la ciudad ***B***, en otras palabras, la capital
  - Despues de esto habrá ***N-1*** lineas que contengan número enteros representando a dos ciudades, ***X*** y ***Y***, que indica que hay un camino entre estas dos ciudades
  - Las siguientes ***N*** es un número que representa el producto que la ciudad ***i*** vende.
  - La linea que sigue contiene el número de queries ***Q***
  - Habra ***Q*** lineas que contienen dos números enteros, ***A*** y ***P***, la ciudad en la que vive el chef y producto que requiere
##### Output:
  - Habrá ***Q*** número de lineas cada una con el número de la ciudad donde el chef debe comprar el próducto, en caso de no haya, el output sera **-1**
##### Ejemplo:
**Input:**
```
8 4
8
3 2
2 1
1 8
8 6
8 7
7 4
4 5
3
2
3
4
1
1
4
4
8
2 1
2 2
2 3
2 4
8 1
8 2
8 3
8 4
```
**Output:**
```
5
2
3
4
5
2
1
4
```

### Solución
Para poder asignar a cada ciudad, se creo primero una estructura que pudiera representarlas con su número y un apuntador a la siguiente ciudad.
```c
struct node
{
  int z;
  struct node *poin;
};
```
El resto del codigo ya corre dentro del main, donde primero inicializamos todas las variables y leemos el número de ciudades y productos y la ciudad capital. Así como también declaramos los arrays que contendrán a las ciudades y una estructura para las adyacencias.
```c
  /*
  * integers
  * n : represents the number of cities
  * k : represents the products
  * b : represents the city where the king lives
  * i : just a interger iterator
  * a and c : represents two cities indicaiting there is a bidirectional road bwtween city a and c
  * q : represents the number of queries
  * j : just another integer iterator
  */
  int n,k,b,i,a,c,q,j;
  scanf("%d %d",&n,&k);
  scanf("%d",&b);
  --b;
  /**
  * stack : array of integers of the cities in the kingdom
  * prev : array of integers of the cities in the kingdom
  * d : bidimensional array of the cities to find what product is in the city
  * prod : array of integers of the cities in the kingdom
  */
  int stack[n],prev[n],d[n][k+1],prod[n];

  /**
  * adj : array adjacent citie
  * end : array previous citie
  * v : a temp node to pass in to the nodes
  */
  struct node *adj[n],*end[n],*v;
```
Despues de esto inicializamos los nodos de ***end[]*** y las ciudades junto con sus adyacencias.
```c
  for(i=0;i<n;i++)
  end[i]=NULL;

  for(i=1;i<n;i++)
  {
    scanf("%d %d",&a,&c);
    --a;--c;
    if(end[a]==NULL)
    {
      adj[a]=(struct node*)malloc(sizeof(struct node));
      (adj[a])->z=c;
      (adj[a])->poin=NULL;
      end[a]=adj[a];
    }
    else
    {
      (end[a])->poin=(struct node*)malloc(sizeof(struct node));
      ((end[a])->poin)->z=c;
      ((end[a])->poin)->poin=NULL;
      end[a]=(end[a])->poin;
    }
    if(end[c]==NULL)
    {
      adj[c]=(struct node*)malloc(sizeof(struct node));
      (adj[c])->z=a;
      (adj[c])->poin=NULL;
      end[c]=adj[c];
    }
    else
    {
      (end[c])->poin=(struct node*)malloc(sizeof(struct node));
      ((end[c])->poin)->z=a;
      ((end[c])->poin)->poin=NULL;
      end[c]=(end[c])->poin;
    }
  }
```
Se añaden los productos que de cada ciudad
```c
  for(i=0;i<n;i++)
  for(j=0;j<=k;j++)
  d[i][j]=n+1;
  stack[0]=b;prev[b]=-1;
  for(i=0;i<n;i++)
  scanf("%d",prod+i);
  d[b][prod[b]]=b;
  v=adj[b];i=-1;

  while(v!=NULL)
  {
    a=stack[++i]=v->z;
    prev[a]=b;
    d[a][prod[a]]=a;
    c=prev[a];
    while(c!=-1)
    {
      if(a<d[c][prod[a]])
      d[c][prod[a]]=a;
      c=prev[c];
    }
    v=v->poin;
  }

  while(i!=-1)
  {
    a=stack[i--];
    d[a][prod[a]]=a;
    c=prev[a];
    while(c!=-1)
    {
      if(a<d[c][prod[a]])
      d[c][prod[a]]=a;
      c=prev[c];
    }
    v=adj[a];
    while(v!=NULL)
    {
      if(v->z!=prev[a]){
        stack[++i]=v->z;
        prev[v->z]=a;
      }
      v=v->poin;
    }
  }
```
Y finalmente, se lee el número de queries y se encuentra el mejor camino al producto.
```c
  scanf("%d",&q);
  while(q--)
  {
    scanf("%d %d",&a,&c);
    --a;
    i=a;
    while(i!=-1)
    {
      if(d[i][c]<n+1)
      {printf("%d\n",d[i][c]+1);
      d[a][c]=d[i][c];
      break;
    }
    i=prev[i];
  }
  if(i==-1)
  printf("-1\n");
}
```


---


## Algoritmo #3: Extreme Encoding

Link de Codechef:
https://www.codechef.com/problems/KOL16B

### Descripción

Lajuk es una niña a quien le encanta jugar con arrays, y para su cumpleaños, recibió dos arrays ***A*** y ***B*** de tamaño ***n*** y que puede incluir enteros desde **0** hasta **30000**. Como a Lajuk ya no le queda mucho espacio en su dico duro, usa la siguiente función para combinar sus dos arrays:
```c
int encodeInteger(int x, int n){
	n = n<<(1<<(1<<(1<<1)));
	x = x | n;
	return x;
}
void encodeArray(int *A, int *B, int n){
	for(int i=0;i<n;i++) {
    	    A[i] = encodeInteger(A[i], B[i]);
	}
}
```
De esta manera, Lajuk adjunta el array ***B*** al ***A** y se deshace del ***B***. Más tarde cuando Lajuk intenta usar ambos arrays, pero no recuerda como recuperar los arrays originales.

### Input y Output

##### Input:
  - En la primera lines va el número de casos ***T***
  - Por cada caso habra una linea que contenga ***n***, el tamaño del array
  - Las siguientes ***n*** lineas, son los contenidos del array modificado, ***A***
##### Output:
  - Para cada caso se imprimira lo siguiente
    - El número del caso en el que nos encontramos
    - Los números del array ***A*** orginal
    - Los números del array ***B***
##### Ejemplo:
**Input:**
```
1
4
196613
655370
196620
```
**Output:**
```
Case 1:
5 10 12 7
3 10 3 2
```

### Solución
Viendo la función que nos dan al inicio del problema, podemos ver que lo que hace es recorrer bits hacia la izquierda, entonces nosotros tendremos que recorrer los bits hacia la derecha. Entonces copiaremos el array ***A*** al ***B*** reocrriendonos los bits necesarios. Como ***A*** sigue con los números intactos, lo que debemos hacer es deshacernos de los bits no significativos con una resta que nos da el valor original de ***A***:
```c
for (j = 0; j < n; j++) {	//Por cada espacio en el array...
	scanf_s("%d", &a[j]);
	b[j] = a[j] >> 16;
	a[j] = a[j] - (b[j] << 16);
}
```
Despues de esto se imprimen ambos arrays con sus valores originales:
```c
printf("Case %d:\n", i + 1);		//Impresion con formato
for (j = 0; j < n; j++) {
	printf("%d ", a[j]);			//Imprime a[j]
}

printf("\n");
for (j = 0; j < n; j++) {			//Imprime b[j]
	printf("%d ", b[j]);
}
```

Para poder correr todos los casos que se piden en el input, solo se hace una función ***for()*** que lea el número de casos y lo vaya disminuyendo en cada iteración hasta que llega a **0**


