#include <stdio.h>
#include <stdlib.h>

struct nodo{
  int dato;
  struct nodo *siguiente;
}nodo1;

nodo1 *ptrNodo;
nodo1 *prtPila;

void ingresar(ptrPila *pila, int x){
   ptrNodo nodo;
   nodo = (ptrNodo)malloc(sizeof(nodo1));
   if(nodo != NULL){
     nodo->dato = x;
     nodo->siguiente = *pila;
     *pila = nodo;
   }
}

int extraer(ptrPila *pila){
   ptrNodo nodo;
   int x=0;
   nodo = *pila;
   x = (*pila)->dato;
   *pila = (*pila)->siguiente;
   free(nodo);
   return x;
}

int pilaVacia(){
   return (*pila == NULL ? 1:0);
}

void invertirPila(ptrNodo nodo1, ptrNodo nodo2, ptrNodo nodo3){
   if(nodo1 == NULL){
     printf("\n La pila esta vacia");
   }else{
     while(nodo1 != NULL){
       ingresar(&nodo2, nodo1->dato);
       nodo1 = nodo1->siguiente;
     }
     while(nodo2 != NULL){
       ingresar(&nodo3, nodo2->dato);
       nodo2 = nodo2->siguiente;
     }
     while(nodo3 != NULL){
       ingresar(&nodo1, nodo3->dato);
       nodo3 = nodo3->siguiente;
     }
     while(nodo1 != NULL){
       printf("Dato: %i\n", nodo1->dato);
       nodo1 = nodo1->siguiente;
     }
   }
}

int main(){
  ptrPila pila1 = NULL, pila2 = NULL, pila3 = NULL;
  ingresar(&pila1, 23);
  ingresar(&pila2, 56);
  ingresar(&pila3, 36);

  if(!pilaVacia(&pila)){
    invertirPila(pila1, pila2, pila3);
    printf("\n Pila invertida: \n");
  }
  return 0;
}



















/*struct nodo{
      int dato;
      struct nodo *sig;
};

struct nodo *raiz;

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

void invertirCadena(int &cad )
{
     /* Copiando caracteres a la pila */
     for(int i=0; i<cad; i++)
          push(cad);

     /* Desapilando y remplanzando en la cadena */
     for(int i=0; i<cad; i++)
          cad[i] = extraer(cad);

}

int main()
{
    TPila pila = NULL;    // creando Pila

    insertar(15);
    insertar(34);
    insertar(76);
    insertar(33);
    imprimir();

    invertirCadena( pila, cad );


    return 0;
}*/
