#ifndef _ARCO_
#define _ARCO_ 1

#include "INodo.h"

using namespace std;

class Arco
{
private:
    void *origen;
    void *destino;
    int peso;
    int evaluacion;
    string comentarios;

public:
    Arco(void *pOrigen, void *pDestino, int pPeso, int pEvaluacion, string pComentarios)
    {
        this->origen = pOrigen;
        this->destino = pDestino;
        this->peso = pPeso;
        evaluacion = pEvaluacion;
        comentarios = pComentarios;
    }

    void *getOrigen()
    {
        return this->origen;
    }

    void *getDestino()
    {
        return this->destino;
    }

    int getPeso()
    {
        return this->peso;
    }

    int getEvaluacion()
    {
        return this->evaluacion;
    }

    string getComentarios()
    {
        return this->comentarios;
    }
};

#endif