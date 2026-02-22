#pragma once
#include "Figura.h"

namespace MiniGameJamTangram {
    public ref class GameController {
    private:
        Figura^ figura_actual;
        int id_figura_seleccionada;

    public:
        GameController() {
            figura_actual = nullptr;
            id_figura_seleccionada = 0;
        }

        void InicializarFigura(int id) {
            id_figura_seleccionada = id;
            figura_actual = gcnew Figura();
            CargarDatos(id);
        }

        void CargarDatos(int id) {
            // colores: amarillo morado verde rojo rosa cyan naranja
            array<Color>^ colores = { Color::Yellow, Color::Purple, Color::LightGreen, Color::Red, Color::Pink, Color::Cyan, Color::Orange };

            if (id == 1) { // Figura 1 Helicopter
                array<array<Point>^>^ puntos = gcnew array<array<Point>^>(7);
                // 0: Yellow trapecio
                puntos[0] = gcnew array<Point>{ Point(250, 150), Point(350, 150), Point(300, 100), Point(200, 100) };
                // 1: Purple triangulo peque
                puntos[1] = gcnew array<Point>{ Point(200, 300), Point(250, 250), Point(150, 250) };
                // 2: Green cuadrado
                puntos[2] = gcnew array<Point>{ Point(75, 225), Point(125, 175), Point(175, 225), Point(125, 275) };
                // 3: Red triangulo peque
                puntos[3] = gcnew array<Point>{ Point(200, 300), Point(300, 300), Point(250, 250) };
                // 4: Pink triangulo medio
                puntos[4] = gcnew array<Point>{ Point(350, 150), Point(500, 150), Point(425, 75) };
                // 5: Cyan triangulo grande
                puntos[5] = gcnew array<Point>{ Point(350, 150), Point(450, 250), Point(350, 350) };
                // 6: Orange triangulo grande
                puntos[6] = gcnew array<Point>{ Point(350, 150), Point(350, 350), Point(250, 250) };

                for (int i = 0; i < 7; i++) figura_actual->agregar_pieza(gcnew FormaPoligono(colores[i], puntos[i]));
            }
            else if (id == 2) { // Figura 2 cisne
                array<array<Point>^>^ puntos = gcnew array<array<Point>^>(7);
                // 0: Yellow Trapecio
                puntos[0] = gcnew array<Point>{ Point(200, 100), Point(200, 200), Point(250, 150), Point(250, 50) };
                // 1: Purple triangulo peque
                puntos[1] = gcnew array<Point>{ Point(300, 100), Point(250, 50), Point(250, 100) }; 
                // 2: Green Cuadrado
                puntos[2] = gcnew array<Point>{ Point(200, 200), Point(250, 250), Point(300, 200), Point(250, 150) };
                // 3: Red Triangulo peque
                puntos[3] = gcnew array<Point>{ Point(250, 250), Point(300, 300), Point(300, 200) };
                // 4: Pink triangulo medio
                puntos[4] = gcnew array<Point>{ Point(225, 225), Point(300, 300), Point(225, 375) };
                // 5: Cyan Triangulo grande
                puntos[5] = gcnew array<Point>{ Point(75, 375), Point(225, 375),  Point(225, 225) };
                // 6: Orange Triangulo grande
                puntos[6] = gcnew array<Point>{ Point(25, 225), Point(225, 225), Point(125, 325) };

                for (int i = 0; i < 7; i++) figura_actual->agregar_pieza(gcnew FormaPoligono(colores[i], puntos[i]));
            }
            else if (id == 3) { // Figura 3 casita
                array<array<Point>^>^ puntos = gcnew array<array<Point>^>(7);
                // 0: Yellow Trapecio
                puntos[0] = gcnew array<Point>{ Point(50, 300), Point(150, 300), Point(250, 200), Point(150, 200) };
                // 1: Purple Triangulo peque
                puntos[1] = gcnew array<Point>{ Point(325, 375), Point(250, 300), Point(400, 300) };
                // 2: Green Cuadrado Verde
                puntos[2] = gcnew array<Point>{ Point(150, 100), Point(250, 100), Point(250, 200), Point(150, 200) };
                // 3: Red Triangulo Peque
                puntos[3] = gcnew array<Point>{ Point(325, 375), Point(400, 450), Point(400, 300) };
                // 4: Pink Triangulo Medio
                puntos[4] = gcnew array<Point>{ Point(100, 450), Point(250, 300), Point(100, 300) };
                // 5: Cyan Traingulo Grande
                puntos[5] = gcnew array<Point>{  Point(100, 450), Point(250, 300), Point(400, 450) };
                // 6: Orange Triangulo Grande
                puntos[6] = gcnew array<Point>{  Point(150, 300), Point(300, 150), Point(450, 300) };

                for (int i = 0; i < 7; i++) figura_actual->agregar_pieza(gcnew FormaPoligono(colores[i], puntos[i]));
            }
        }

        // dibuja la figura actual en pantalla
        void dibujar(Graphics^ g) {
            if (figura_actual != nullptr) {
                figura_actual->dibujar(g);
            }
        }

        // muestra la pieza en el indice dado
        void mostrar_pieza(int indice) {
            if (figura_actual != nullptr) figura_actual->mostrar_pieza(indice);
        }

        // elimina la ultima pieza agregada
        int eliminar_pieza() {
            if (figura_actual != nullptr) return figura_actual->sacar_orden_activacion();
            return -1;
        }

        // verifica si todas las piezas estan puestas
        bool es_completa() {
            if (figura_actual != nullptr) return figura_actual->esta_completa();
            return false;
        }

        // verifica si hay piezas visibles
        bool tiene_piezas_visibles() {
            if (figura_actual != nullptr) return figura_actual->tiene_piezas_visibles();
            return false;
        }
    };
}
