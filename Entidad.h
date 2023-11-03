#ifndef _ENTIDAD_
#define _ENTIDAD_ 1

#include <iostream>
#include "INodo.h"

using namespace std;

class Entidad : public INodo {
    public:
        Entidad(int pId, string pEntidad) {
            this->setId(pId);
            this->setNombre(pEntidad);
        }

        string getNombre() {
            return this->entidad;
        }

        void setNombre(string pNombre) {
            this->entidad = pNombre;
        }

    private:
        string entidad;
};

#endif