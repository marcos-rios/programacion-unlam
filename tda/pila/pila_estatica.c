#include <string.h>

#include "pila_estatica.h"

void crearPila(PilaEstatica *p)
{
    p->tope = 0;
}

int pilaLlena(const PilaEstatica *p, unsigned tamElem)
{
    return p->tope + tamElem + sizeof(unsigned) > TAM_PILA;
}

int pilaVacia(const PilaEstatica *p)
{
    return p->tope == 0;
}

int ponerEnPila(PilaEstatica *p, const void *d, unsigned tamElem)
{
    if(p->tope + tamElem + sizeof(unsigned) > TAM_PILA)
    {
        return FALSO;
    }

    // incremento por el tamaño del dato
    p->tope += tamElem;
    memcpy(p->pila + p->tope, d, tamElem);

    // incremento por el tamaño de la variable que almacena el tamaño del dato
    p->tope += sizeof(unsigned);
    memcpy(p->pila + p->tope, &tamElem, sizeof(unsigned));

    return VERDADERO;
}

int sacarDePila(PilaEstatica *p, void *d, unsigned tamElem)
{
    if(p->tope == 0)
    {
        return FALSO;
    }

    // retrocedo y leo el tamaño
    p->tope -= sizeof(unsigned);
    unsigned tamElemReal = *(unsigned *)(p->pila + p->tope);

    // retrocedo el tamaño
    p->tope -= tamElemReal;
    memcpy(d, p->pila + p->tope, minimo(tamElem, tamInfo));

    return VERDADERO;
}

int verTope(const PilaEstatica *p, void *d, unsigned tamElem)
{
    if(p->tope == 0)
    {
        return FALSO;
    }

    unsigned topeTmp = p->tope;

    topeTmp -= sizeof(unsigned);
    unsigned tamElemReal = *(unsigned *)(p->pila + topeTmp);

    topeTmp -= tamElemReal;
    memcpy(d, p->pila + topeTmp, minimo(tamElem, tamElemReal))
    return VERDADERO;
}

void vaciarPila(PilaEstatica *p)
{
    p->tope = 0;
}
