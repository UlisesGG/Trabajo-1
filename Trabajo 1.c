#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

typedef struct nodeP{						
/*
	Estructura linked list que permite almacenar coeficiente
	grado y signo de un elemento de un polinomio
*/
	long coef;
	long grd;
	int sg;
	struct nodeP *next;
}node;

void push(node **head, long coef, long grd, int sg){
	/*
		Inserta el elemento al inicio de la linkedList
	*/
	node *nNode=malloc(sizeof(node));
	nNode->coef=coef;
	nNode->grd=grd;
	nNode->sg=sg;
	nNode->next=*head;
	*head=nNode;
}
void display(node **head){
	/*
		Funcion que muestra el polinomio
		PD: Debe ser correjida, no se porque, pero funciona de forma extraña
	*/
	node *temp;
	temp=*head;
	while(temp!=NULL){
		if(temp->sg){
			printf("+%ldx%ld", temp->coef, temp->grd);
		}else{
			printf("-%ldx%ld", temp->coef, temp->grd);
		}
		temp=temp->next;
	}
	printf("\n");
}
node *generator(long grado){
	/*
		Funcion que genera un polinomio de grado G de forma aleatorea.
		Hay que corregir el numero maximo que puede tener el coeficiente
		(2^63); (funcion en c para escribir un exponente (pow(base, exponente)))
	*/
	node *head=NULL;
	srand(time(NULL));
	int i=0;
	long nGenerado=0;
	int sign=0;
	for(i=0; i<grado; i++){
		nGenerado=rand()*100;
		if(nGenerado!=0){
			sign=rand()*grado;
			if(sign%2==0){
				push(&head, nGenerado, i, 1);
			}else{
				push(&head, nGenerado, i, 0);
			}
		}
	}
	return head;
}
int main(){
	node *head;
	head=generator(10);
	display(&head);
	return 0;
}
