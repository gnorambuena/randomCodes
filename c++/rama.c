#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
	int v;
	struct nodo *izq,*der;
} Nodo;

Nodo **rama(Nodo *a,int v, int *p){
	if(a==NULL)return NULL;
	else{
		Nodo** res = (Nodo**)malloc(100*sizeof(Nodo*));
		int** pointer = res;
		while(a!=NULL){
			if(a->v==v){
				return res;
			}
			else if(a->v < v){
				*pointer = a;
				pointer++;
				a = a->der;
			}
			else{
				*pointer = a;
				pointer++;
				a = a->izq;
			}
			*p++;
		}
		return NULL;
	}
}