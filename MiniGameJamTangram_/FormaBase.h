#pragma once
using namespace System;
using namespace System::Drawing;

namespace MiniGameJamTangram {
    public ref class FormaBase abstract {
    protected:
        Color color;
        array<Point>^ puntos;
        bool esta_visible;

    public:
        FormaBase(Color color) {
            this->color = color;
            this->esta_visible = false;
        }

        virtual void dibujar(Graphics^ g) abstract;
        
        void establecer_visible(bool estado) { this->esta_visible = estado; }
        bool es_visible() { return this->esta_visible; }
        Color obtener_color() { return this->color; }
    };
}
