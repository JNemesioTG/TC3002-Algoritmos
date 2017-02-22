/**
* autor: Guillermo Garía Contreras
* Chef Under Pressure
*
* This code solve the problem Chef Uder Pressure
* can be found here: https://www.codechef.com/problems/CHEFPRES
*/

#include<stdio.h>
#include<stdlib.h>

/**
* Struc node
* This node represents each city of the kingdom
* z the product that the city sells
* node *poin a pointer to the adjacent city
*/
struct node
{
  int z;
  struct node *poin;
};

/**
* main
*
* Method that runs everything
*
*/
int main()
{
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

  /**
  *Initializing end[n] nodes
  */
  for(i=0;i<n;i++)
  end[i]=NULL;

  /**
  * Initializing the cities and their Adjacency
  *
  */
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

  /**
  * Adding the products that will be sold by each city
  *
  */
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

  /**
  * reading the number of queries
  * Finding the best path to buy the product
  */
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
return 0;
}
