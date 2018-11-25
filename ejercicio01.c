#include <stdio.h>
#include <stdlib.h>

//void insertar(int x);
//void imprimier();
//int extraer();
//void liberar();

int contador;

struct nodo{
  int info;
  struct nodo *sig;
};

struct nodo *raiz=NULL;

//Aqui en insertar es donde hago la primera mitad de el conteo de nodos, esto se logra con una variable contador de tipo entero,
//ya que cada vez que se agregue un nodo, a contador se le sumara 1

void insertar(int x){
  struct nodo *nuevo;
  nuevo = malloc(sizeof(struct nodo));
  nuevo->info = x;
  contador++;
  if(raiz == NULL){
    raiz = nuevo;
    nuevo->sig = NULL;
  }else{
    nuevo->sig = raiz;
    raiz = nuevo;
  }
}

//Aqui en el metodo imprimir determino si la pila se encuentra vacia, y eso se logra validando con un if, ya que si raiz == NULL, quiere
//decir que ningun elemnto ha sido agregado

void imprimir(){
  struct nodo *reco = raiz;
  if(raiz != NULL){
  printf("Lista completa.\n");
  while(reco != NULL){
    printf("%i ", reco->info);
    reco = reco->sig;
  }
  printf("\n");
}else{
  printf("La pila esta vacia\n");
}
}

//Aqui en extraer se lleva a cabo la segunda mitad del conteo de nodos, y es que cada vez que se extraiga un nodo, a contador se
//le restara 1

int extraer(){
  if(raiz != NULL){
    int informacion = raiz->info;
    struct nodo *bor = raiz;
    raiz = raiz->sig;
    free(bor);
    contador--;
    return informacion;
  }else{
    return -1;
  }
}

void liberar(){
  struct nodo *reco = raiz;
  struct nodo *bor;
  while(reco != NULL){
    bor = reco;
    reco = reco->sig;
    free(bor);
  }
}

int main(){
  insertar(10);
  insertar(40);
  insertar(3);
  imprimir();
  printf("Extraemos de la pila: %i\n", extraer());
  imprimir();
  liberar();
  printf("\nEl numero de nodos es: %i", contador);
  printf("\n");
  return 0;
}
