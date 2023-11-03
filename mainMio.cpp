#include <iostream>
#include "grafo.h"
#include "NodoGrafo.h"
#include "INodo.h"
#include "Entidad.h"
#include <vector>

using namespace std;

int main() {

    //En el caso mio, el tema es de empleos
    /*
        Grafo de Evaluaciones y Comentarios Laborales:
        Crea un grafo donde los nodos representen empresas y 
        los empleados que han trabajado allí, y las aristas
        representen las evaluaciones y comentarios laborales
        de los empleados.
        Puedes utilizar este grafo para analizar la satisfacción
        laboral en diferentes empresas y sectores, y proporcionar
        a los usuarios información sobre el ambiente laboral en diferentes
        organizaciones.
    */
    Grafo grafoEmpleos(true);



    Entidad *TrabajadorPedro = new Entidad(3, "Trabajador");
    Entidad *TrabajadorAna = new Entidad(6, "Trabajador");
    Entidad *TrabajadorJuan = new Entidad(5, "Trabajador");
    Entidad *TrabajadorPepe = new Entidad(9, "Trabajador");
    Entidad *TrabajadorAlicia = new Entidad(8, "Trabajador");
    Entidad *TrabajadorMorelia = new Entidad(2, "Trabajador");
    Entidad *Empresax1 = new Entidad(1, "Empresa");
    Entidad *TrabajadorSaul = new Entidad(15, "Trabajador");
    Entidad *TrabajadorMoraes = new Entidad(17, "Trabajador");
    Entidad *TrabajadorFlor = new Entidad(13, "Trabajador");
    Entidad *TrabajadorGael = new Entidad(10, "Trabajador");
    Entidad *TrabajadorAnonimoo = new Entidad(12, "Trabajador");
    Entidad *Empresax2 = new Entidad(4, "Empresa");
    Entidad *Empresax3 = new Entidad(7, "Empresa");
    Entidad *Empresax4 = new Entidad(11, "Empresa");
    Entidad *Empresax5 = new Entidad(14, "Empresa");
    Entidad *Empresax6 = new Entidad(16, "Empresa");
    Entidad *Empresax7 = new Entidad(18, "Empresa");

    //Se ingresan al grafo
    grafoEmpleos.addNode(TrabajadorAlicia);
    grafoEmpleos.addNode(TrabajadorAna);
    grafoEmpleos.addNode(TrabajadorAnonimoo);
    grafoEmpleos.addNode(TrabajadorFlor);
    grafoEmpleos.addNode(TrabajadorGael);
    grafoEmpleos.addNode(TrabajadorJuan);
    grafoEmpleos.addNode(TrabajadorMoraes);
    grafoEmpleos.addNode(TrabajadorMorelia);
    grafoEmpleos.addNode(TrabajadorPedro);
    grafoEmpleos.addNode(TrabajadorPepe);
    grafoEmpleos.addNode(TrabajadorSaul);
    grafoEmpleos.addNode(Empresax1);
    grafoEmpleos.addNode(Empresax2);
    grafoEmpleos.addNode(Empresax3);
    grafoEmpleos.addNode(Empresax4);
    grafoEmpleos.addNode(Empresax5);
    grafoEmpleos.addNode(Empresax6);
    grafoEmpleos.addNode(Empresax7);

    //Se crean los valores iniciales y finales para crear las relaciones

    NodoGrafo* origen = grafoEmpleos.getNodo(3);
    NodoGrafo* destino = grafoEmpleos.getNodo(9);

    //relaciones
    grafoEmpleos.addArc(TrabajadorAlicia, Empresax1, 3, 65, "Mala recepcion");
    grafoEmpleos.addArc(Empresax1, TrabajadorAna, 6, 98, "Excelente servicio");
    grafoEmpleos.addArc(TrabajadorAna, Empresax5, 9, 12, "Malas mañas");
    grafoEmpleos.addArc(TrabajadorAnonimoo, Empresax7, 7, 45, "No higiene");
    grafoEmpleos.addArc(Empresax5, TrabajadorJuan, 6, 55, "Mala atencion");
    grafoEmpleos.addArc(TrabajadorJuan, Empresax7, 2, 65, "No seguridad");
    grafoEmpleos.addArc(TrabajadorMoraes, Empresax7, 4, 85, "Buen servicio");
    grafoEmpleos.addArc(Empresax7, TrabajadorMoraes, 1, 35, "Mal trato");
    grafoEmpleos.addArc(TrabajadorMorelia, Empresax2, 8, 26, "Abuso");
    grafoEmpleos.addArc(Empresax2, TrabajadorPedro, 5, 78, "Buen ambiente");
    grafoEmpleos.addArc(TrabajadorPedro, Empresax4, 10, 16, "Malas personas");
    grafoEmpleos.addArc(TrabajadorAlicia, Empresax6, 13, 23, "Malas capacitaciones");
    grafoEmpleos.addArc(TrabajadorPepe, Empresax2, 17, 18, "Mal ingreso");
    grafoEmpleos.addArc(Empresax6, TrabajadorAnonimoo, 14, 96, "Excelente capacitacion");
    grafoEmpleos.addArc(TrabajadorSaul, Empresax1, 12, 97, "Excelentes personas");
    grafoEmpleos.addArc(TrabajadorFlor, Empresax4, 18, 26, "Mal ambiente");
    grafoEmpleos.addArc(TrabajadorGael, Empresax6, 11, 90, "Buen trato");
    grafoEmpleos.addArc(TrabajadorMorelia, Empresax2, 15, 85, "Buen ambiente");



    vector<vector<INodo*>> componentesConectados = grafoEmpleos.encontrarComponentesConectados();

    // Imprimir la información de los componentes conectados
    for (size_t i = 0; i < componentesConectados.size(); ++i) {
        cout << "Componente Conectado " << (i + 1) << ": ";
        for (size_t j = 0; j < componentesConectados[i].size(); ++j) {
            cout << componentesConectados[i][j]->getId() << " ";
            // Puedes imprimir otros atributos de los nodos según tu implementación
        }
        cout << endl;
   

    
    }
    cout << "termino bien" << endl;

}