#pragma once
#include "FormaBase.h"

namespace MiniGameJamTangram {
    
    public ref class FormaPoligono : public FormaBase {
    public:
        FormaPoligono(Color color, array<Point>^ pts) : FormaBase(color) {
            this->puntos = pts;
        }

        virtual void dibujar(Graphics^ g) override {
            if (!esta_visible) return;
            // relleno de la pieza
            SolidBrush^ relleno = gcnew SolidBrush(color);
            g->FillPolygon(relleno, puntos);
            delete relleno;
            // borde negro de la pieza
            Pen^ borde = gcnew Pen(Color::Black, 2);
            g->DrawPolygon(borde, puntos);
            delete borde;
        }
    };
}
