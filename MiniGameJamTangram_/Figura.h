#pragma once
#include "Formas.h"
#include <cliext/vector>

using namespace System::Collections::Generic;

namespace MiniGameJamTangram {
    public ref class Figura {
    private:
        cliext::vector<FormaPoligono^>^ piezas;
        Stack<int>^ pilaActivacion; // pila para gestionar el orden de activacion de las piezas

    public:
        Figura() {
            piezas = gcnew cliext::vector<FormaPoligono^>();
            pilaActivacion = gcnew Stack<int>();
        }

        void agregar_pieza(FormaPoligono^ pieza) {
            piezas->push_back(pieza);
        }

        // agrega la pieza al stack registrando el orden de activacion
        void mostrar_pieza(int indice) {
            if (indice >= 0 && indice < (int)piezas->size()) {
                if (!piezas->at(indice)->es_visible()) {
                    piezas->at(indice)->establecer_visible(true);
                    pilaActivacion->Push(indice); // apila el indice
                }
            }
        }

        // elimina la ultima pieza activada orden inverso al que se colocaron
        int sacar_orden_activacion() {
            if (pilaActivacion->Count == 0) return -1;
            int ultimoIndice = pilaActivacion->Pop(); // desapila el ultimo
            piezas->at(ultimoIndice)->establecer_visible(false);
            return ultimoIndice;
        }

        // verifica si hay piezas en la pila
        bool tiene_piezas_visibles() {
            return pilaActivacion->Count > 0;
        }

        // dibuja todas las piezas visibles
        void dibujar(Graphics^ g) {
            for (int i = 0; i < (int)piezas->size(); i++) {
                piezas->at(i)->dibujar(g);
            }
        }

        // verifica si la figura esta con todas sus piezas
        bool esta_completa() {
            return pilaActivacion->Count == (int)piezas->size();
        }

        int obtener_piezas_visibles() {
            return pilaActivacion->Count;
        }
    };
}
