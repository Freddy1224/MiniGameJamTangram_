#pragma once
#include "GameController.h"

namespace MiniGameJamTangram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class GameForm : public System::Windows::Forms::Form
	{
	public:
		GameForm(int figureID)
		{
			InitializeComponent();
			controlador = gcnew GameController();
			controlador->InicializarFigura(figureID);

			temporizador_desintegracion = gcnew System::Windows::Forms::Timer();
			temporizador_desintegracion->Interval = 500; // 0.5 segundos entre piezas
			temporizador_desintegracion->Tick += gcnew EventHandler(this, &GameForm::temporizador_tictac);
			this->Paint += gcnew PaintEventHandler(this, &GameForm::GameForm_Pintar);
		}

	protected:
		~GameForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		GameController^ controlador;
		System::Windows::Forms::Timer^ temporizador_desintegracion;
		// botones de colores (uno por pieza)
		System::Windows::Forms::Button^ boton0;
		System::Windows::Forms::Button^ boton1;
		System::Windows::Forms::Button^ boton2;
		System::Windows::Forms::Button^ boton3;
		System::Windows::Forms::Button^ boton4;
		System::Windows::Forms::Button^ boton5;
		System::Windows::Forms::Button^ boton6;
		System::Windows::Forms::Button^ btnEliminar;
		System::Windows::Forms::Label^  lblInfo;
		System::ComponentModel::IContainer^ components;

		void InitializeComponent(void)
		{
			this->boton0 = (gcnew System::Windows::Forms::Button());
			this->boton1 = (gcnew System::Windows::Forms::Button());
			this->boton2 = (gcnew System::Windows::Forms::Button());
			this->boton3 = (gcnew System::Windows::Forms::Button());
			this->boton4 = (gcnew System::Windows::Forms::Button());
			this->boton5 = (gcnew System::Windows::Forms::Button());
			this->boton6 = (gcnew System::Windows::Forms::Button());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
			this->lblInfo = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// boton0
			// 
			this->boton0->BackColor = System::Drawing::Color::Yellow;
			this->boton0->Location = System::Drawing::Point(600, 50);
			this->boton0->Name = L"boton0";
			this->boton0->Size = System::Drawing::Size(100, 30);
			this->boton0->TabIndex = 0;
			this->boton0->Tag = 0;
			this->boton0->UseVisualStyleBackColor = false;
			this->boton0->Click += gcnew System::EventHandler(this, &GameForm::BotonPieza_Clic);
			// 
			// boton1
			// 
			this->boton1->BackColor = System::Drawing::Color::Purple;
			this->boton1->Location = System::Drawing::Point(600, 90);
			this->boton1->Name = L"boton1";
			this->boton1->Size = System::Drawing::Size(100, 30);
			this->boton1->TabIndex = 1;
			this->boton1->Tag = 1;
			this->boton1->UseVisualStyleBackColor = false;
			this->boton1->Click += gcnew System::EventHandler(this, &GameForm::BotonPieza_Clic);
			// 
			// boton2
			// 
			this->boton2->BackColor = System::Drawing::Color::LightGreen;
			this->boton2->Location = System::Drawing::Point(600, 130);
			this->boton2->Name = L"boton2";
			this->boton2->Size = System::Drawing::Size(100, 30);
			this->boton2->TabIndex = 2;
			this->boton2->Tag = 2;
			this->boton2->UseVisualStyleBackColor = false;
			this->boton2->Click += gcnew System::EventHandler(this, &GameForm::BotonPieza_Clic);
			// 
			// boton3
			// 
			this->boton3->BackColor = System::Drawing::Color::Red;
			this->boton3->Location = System::Drawing::Point(600, 170);
			this->boton3->Name = L"boton3";
			this->boton3->Size = System::Drawing::Size(100, 30);
			this->boton3->TabIndex = 3;
			this->boton3->Tag = 3;
			this->boton3->UseVisualStyleBackColor = false;
			this->boton3->Click += gcnew System::EventHandler(this, &GameForm::BotonPieza_Clic);
			// 
			// boton4
			// 
			this->boton4->BackColor = System::Drawing::Color::Pink;
			this->boton4->Location = System::Drawing::Point(600, 210);
			this->boton4->Name = L"boton4";
			this->boton4->Size = System::Drawing::Size(100, 30);
			this->boton4->TabIndex = 4;
			this->boton4->Tag = 4;
			this->boton4->UseVisualStyleBackColor = false;
			this->boton4->Click += gcnew System::EventHandler(this, &GameForm::BotonPieza_Clic);
			// 
			// boton5
			// 
			this->boton5->BackColor = System::Drawing::Color::Cyan;
			this->boton5->Location = System::Drawing::Point(600, 250);
			this->boton5->Name = L"boton5";
			this->boton5->Size = System::Drawing::Size(100, 30);
			this->boton5->TabIndex = 5;
			this->boton5->Tag = 5;
			this->boton5->UseVisualStyleBackColor = false;
			this->boton5->Click += gcnew System::EventHandler(this, &GameForm::BotonPieza_Clic);
			// 
			// boton6
			// 
			this->boton6->BackColor = System::Drawing::Color::Orange;
			this->boton6->Location = System::Drawing::Point(600, 290);
			this->boton6->Name = L"boton6";
			this->boton6->Size = System::Drawing::Size(100, 30);
			this->boton6->TabIndex = 6;
			this->boton6->Tag = 6;
			this->boton6->UseVisualStyleBackColor = false;
			this->boton6->Click += gcnew System::EventHandler(this, &GameForm::BotonPieza_Clic);
			// 
			// btnEliminar
			// 
			this->btnEliminar->Location = System::Drawing::Point(591, 344);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(120, 40);
			this->btnEliminar->TabIndex = 7;
			this->btnEliminar->Text = L"ELIMINAR FIGURA";
			this->btnEliminar->Enabled = false;
			this->btnEliminar->Click += gcnew System::EventHandler(this, &GameForm::btnEliminar_Clic);
			// 
			// lblInfo
			// 
			this->lblInfo->AutoSize = true;
			this->lblInfo->Location = System::Drawing::Point(50, 20);
			this->lblInfo->Name = L"lblInfo";
			this->lblInfo->Size = System::Drawing::Size(373, 13);
			this->lblInfo->TabIndex = 8;
			this->lblInfo->Text = L"Usa los botones para armar. Eliminar inicia la desintegracion en orden inverso.";
			this->lblInfo->Click += gcnew System::EventHandler(this, &GameForm::lblInfo_Click);
			// 
			// GameForm
			// 
			this->ClientSize = System::Drawing::Size(800, 500);
			this->Controls->Add(this->boton0);
			this->Controls->Add(this->boton1);
			this->Controls->Add(this->boton2);
			this->Controls->Add(this->boton3);
			this->Controls->Add(this->boton4);
			this->Controls->Add(this->boton5);
			this->Controls->Add(this->boton6);
			this->Controls->Add(this->btnEliminar);
			this->Controls->Add(this->lblInfo);
			this->DoubleBuffered = true;
			this->Name = L"GameForm";
			this->Text = L"Tangram - Armando Figura";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		// evento de dibujo dibuja la figura
		void GameForm_Pintar(Object^ sender, PaintEventArgs^ e) {
			controlador->dibujar(e->Graphics);
		}

		// agrega la pieza del boton presionado orden inverso guarda orden de activacion
		void BotonPieza_Clic(Object^ sender, EventArgs^ e) {
			if (temporizador_desintegracion->Enabled) return; // no agregar mientras se anima
			Button^ btn = safe_cast<Button^>(sender);
			int indice = safe_cast<int>(btn->Tag); // unboxing seguro del indice
			controlador->mostrar_pieza(indice);
			
			// verifica si la figura esta completa para habilitar el boton
			if (controlador->es_completa()) {
				btnEliminar->Enabled = true;
			}

			this->Invalidate(); // redibuja
		}

		// inicia la animacion de eliminacion si hay piezas visibles
		void btnEliminar_Clic(Object^ sender, EventArgs^ e) {
			if (controlador->tiene_piezas_visibles()) {
				btnEliminar->Enabled = false; // bloquea mientras se limpia
				temporizador_desintegracion->Start();
			}
		}

		// elimina una pieza por tick del temporizador orden inverso ultima en entrar es primera en salir
		void temporizador_tictac(Object^ sender, EventArgs^ e) {
			if (controlador->tiene_piezas_visibles()) {
				controlador->eliminar_pieza();
				this->Invalidate();
			}
			else {
				temporizador_desintegracion->Stop();
			}
		}
	private: System::Void lblInfo_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
