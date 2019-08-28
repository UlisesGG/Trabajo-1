#include stdio.h
#include stdlib.h
#include math.h
#include time.h /*clock() */

struct node{
    double coeficiente;
    double grado;
    bool sign;
    *node next;
    *node parent;
};

*node node.iniciar(*node n){
    n.coeficiente = 0;
    n.grado = 0;
    n.sign = true;
    n->next = NULL;
    n->parent = NULL;
};

struct poly{
    long long int gradoMayor;
    *node tupla[2];
};

*poly poly.iniciar(*poly n){
    n.gradoMayor = 0;
    n->tupla[0] = NULL;
    n->tupla[1] = NULL;
};

*poly poly.ingresar(*poly n, double gr, double coef, bool sig){
    if (n->tupla[0] == NULL){
        n->tupla[0] = n->tupla[1] = n->tupla[0].iniciar()
    }
};