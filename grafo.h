#ifndef _GRAFO_
#define _GRAFO_ 1
#include <vector>
#include "NodoGrafo.h"
#include "INodo.h"
#include <map>
#include <queue>
#include "Arco.h"

using namespace std;

class Grafo
{
private:
    vector<NodoGrafo *> listaNodos;
    bool esDirigido = true;
    std::map<int, NodoGrafo *> hashNodos;

    void resetNodes()
    {
        for (std::vector<NodoGrafo *>::iterator current = listaNodos.begin(); current != listaNodos.end(); ++current)
        {
            NodoGrafo *actual = (*current);
            actual->procesado = false;
            actual->visitado = false;
        }
    }

    NodoGrafo *findNotVisited()
    {
        NodoGrafo *result = nullptr;
        for (std::vector<NodoGrafo *>::iterator current = listaNodos.begin(); current != listaNodos.end(); ++current)
        {
            NodoGrafo *actual = (*current);
            if (!actual->visitado)
            {
                result = actual;
                break;
            }
        }
        return result;
    }

    //metodo utilizado para poder recorrer cada nodo y llenar los vectores que se introducen cuando se llama la funcion
    void dfs(NodoGrafo* nodo, vector<INodo*>& componente) {
        nodo->visitado = true;
        componente.push_back(nodo->getInfo());

        vector<Arco*> *adyacentes = nodo->getArcs();
        for (Arco* arco : *adyacentes) {
            NodoGrafo* adyacente = (NodoGrafo*)arco->getDestino();
            if (!adyacente->visitado) {
                dfs(adyacente, componente);
            }
        }
    }

public:
    Grafo(bool pesDirigido){
        this->esDirigido = pesDirigido;
    }

    int getSize()
    {
        return this->listaNodos.size();
    }

    void addNode(INodo *pNodo)
    {
        NodoGrafo *nuevoNodo = new NodoGrafo(pNodo);
        this->listaNodos.push_back(nuevoNodo);
        hashNodos.insert(pair<int, NodoGrafo *>(pNodo->getId(), nuevoNodo));
    }
    /*
    void addArc(NodoGrafo *pOrigen, NodoGrafo *pDestino)
    {
        this->addArc(pOrigen, pDestino, 0);
    }
    */
    void addArc(NodoGrafo *pOrigen, NodoGrafo *pDestino, int pPeso, int pEvaluacion, string pComentarios)
    {
        Arco *newArc = new Arco(pOrigen, pDestino, pPeso, pEvaluacion, pComentarios);
        pOrigen->addArc(newArc);
    }

    void addArc(INodo *pOrigen, INodo *pDestino, int pPeso, int pEvaluacion, string pComentarios)
    {
        this->addArc(this->getNodo(pOrigen->getId()), this->getNodo(pDestino->getId()), pPeso, pEvaluacion, pComentarios);
    }

    void addArc(int pOrigen, int pDestino, int pPeso, int pEvaluacion, string pComentarios)
    {
        this->addArc(this->getNodo(pOrigen), this->getNodo(pDestino), pPeso, pEvaluacion, pComentarios);
    }
    /*
    void addArc(INodo *pOrigen, INodo *pDestino)
    {
        this->addArc(pOrigen->getId(), pDestino->getId(), 0);
    }

    void addArc(INodo *pOrigen, INodo *pDestino, int pPeso)
    {
        this->addArc(pOrigen->getId(), pDestino->getId(), pPeso);
    }

    void addArc(int pOrigen, int pDestino)
    {
        this->addArc(pOrigen, pDestino, 0);
    }

    void addArc(int pOrigen, int pDestino, int pPeso)
    {
        this->addArc(this->getNodo(pOrigen), this->getNodo(pDestino), pPeso);
    }
*/
    NodoGrafo *getNodo(int pId)
    {
        return hashNodos.at(pId);
    }

    vector<INodo> deepPath(INodo *pOrigen)
    { // recorrido en profundidad
        vector<INodo> result;

        return result;
    }

    vector<INodo *> broadPath(INodo *pOrigen)
    {
        vector<INodo *> result;
        queue<NodoGrafo *> nodosProcesados;
        int visitados = 0;

        resetNodes();

        NodoGrafo *puntoPartida = this->getNodo(pOrigen->getId());
        nodosProcesados.push(puntoPartida);
        puntoPartida->procesado = true;

        do
        {
            while (!nodosProcesados.empty())
            {
                NodoGrafo *actual = nodosProcesados.front();
                nodosProcesados.pop();

                actual->visitado = true;
                visitados++;
                result.push_back(actual->getInfo());

                vector<Arco *> *adyacentes = actual->getArcs();

                for (int indiceArcos = 0; indiceArcos < adyacentes->size(); ++indiceArcos)
                {
                    Arco *arco = adyacentes->at(indiceArcos);
                    NodoGrafo *adyacente = (NodoGrafo *)arco->getDestino();
                    if (!adyacente->procesado)
                    {
                        nodosProcesados.push(adyacente);
                        adyacente->procesado = true;
                    }
                }
            }

            if (visitados < this->getSize())
            {
                puntoPartida = this->findNotVisited();
                nodosProcesados.push(puntoPartida);
                puntoPartida->procesado = true;
            }
        } while (visitados < this->getSize());

        return result;
    }

    vector<INodo> path(INodo *pOrigen, INodo *pDestino)
    { // debe retornar un camino, el primero que encuentre estre el nodo oriegn y destino
        // en caso de que no haya camino, result se retorna vacío
        vector<INodo> result;

        return result;
    }

    void printCounters()
    {
        for (std::vector<NodoGrafo *>::iterator current = listaNodos.begin(); current != listaNodos.end(); ++current)
        {
            NodoGrafo *actual = (*current);
            cout << actual->getInfo()->getId() << " tiene " << actual->getArcs()->size() << endl;
        }
    }





    vector<vector<INodo*>> encontrarComponentesConectados() {
        resetNodes(); // Antes de empezar hay que asegurarse que todos los nodos estén marcados como no visitados
        vector<vector<INodo*>> componentes;

        for (NodoGrafo* nodo : listaNodos) {
            if (!nodo->visitado) {
                vector<INodo*> componente;
                dfs(nodo, componente);
                componentes.push_back(componente);
            }
        }

        return componentes;
    }
};

#endif