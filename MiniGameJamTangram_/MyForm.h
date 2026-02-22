#pragma once
#include "GameForm.h"

namespace MiniGameJamTangram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			// inicializar controladores para las previsualizaciones
			previa1 = gcnew GameController();
			previa2 = gcnew GameController();
			previa3 = gcnew GameController();

			previa1->InicializarFigura(1);
			previa2->InicializarFigura(2);
			previa3->InicializarFigura(3);

			// mostrar todas las piezas para la previsualizacion
			for (int i = 0; i < 7; i++) {
				previa1->mostrar_pieza(i);
				previa2->mostrar_pieza(i);
				previa3->mostrar_pieza(i);
			}

			// suscribir eventos pintar
			this->pictureBox1->Paint += gcnew PaintEventHandler(this, &MyForm::PintarPictureBox);
			this->pictureBox2->Paint += gcnew PaintEventHandler(this, &MyForm::PintarPictureBox);
			this->pictureBox3->Paint += gcnew PaintEventHandler(this, &MyForm::PintarPictureBox);
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnFig1;
	private: System::Windows::Forms::Button^ btnFig2;
	private: System::Windows::Forms::Button^ btnFig3;
	private: System::Windows::Forms::Label^ lblTitle;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;

	// controladores para las vistas previas
	private: GameController^ previa1;
	private: GameController^ previa2;
	private: GameController^ previa3;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->btnFig1 = (gcnew System::Windows::Forms::Button());
			this->btnFig2 = (gcnew System::Windows::Forms::Button());
			this->btnFig3 = (gcnew System::Windows::Forms::Button());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// btnFig1
			// 
			this->btnFig1->Location = System::Drawing::Point(55, 237);
			this->btnFig1->Name = L"btnFig1";
			this->btnFig1->Size = System::Drawing::Size(100, 50);
			this->btnFig1->TabIndex = 1;
			this->btnFig1->Text = L"FIGURA 1";
			this->btnFig1->UseVisualStyleBackColor = true;
			this->btnFig1->Click += gcnew System::EventHandler(this, &MyForm::btnFig1_Click);
			// 
			// btnFig2
			// 
			this->btnFig2->Location = System::Drawing::Point(278, 237);
			this->btnFig2->Name = L"btnFig2";
			this->btnFig2->Size = System::Drawing::Size(100, 50);
			this->btnFig2->TabIndex = 2;
			this->btnFig2->Text = L"FIGURA 2";
			this->btnFig2->UseVisualStyleBackColor = true;
			this->btnFig2->Click += gcnew System::EventHandler(this, &MyForm::btnFig2_Click);
			// 
			// btnFig3
			// 
			this->btnFig3->Location = System::Drawing::Point(503, 237);
			this->btnFig3->Name = L"btnFig3";
			this->btnFig3->Size = System::Drawing::Size(100, 50);
			this->btnFig3->TabIndex = 3;
			this->btnFig3->Text = L"FIGURA 3";
			this->btnFig3->UseVisualStyleBackColor = true;
			this->btnFig3->Click += gcnew System::EventHandler(this, &MyForm::btnFig3_Click);
			// 
			// lblTitle
			// 
			this->lblTitle->AutoSize = true;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Arial", 16, System::Drawing::FontStyle::Bold));
			this->lblTitle->Location = System::Drawing::Point(50, 30);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(237, 26);
			this->lblTitle->TabIndex = 0;
			this->lblTitle->Text = L"Selecciona una Figura";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(35, 99);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(146, 123);
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(267, 99);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(146, 123);
			this->pictureBox2->TabIndex = 4;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(485, 99);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(146, 123);
			this->pictureBox3->TabIndex = 5;
			this->pictureBox3->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(728, 425);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btnFig3);
			this->Controls->Add(this->btnFig2);
			this->Controls->Add(this->btnFig1);
			this->Controls->Add(this->lblTitle);
			this->Name = L"MyForm";
			this->Text = L"Tangram - Menú Principal";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		System::Void btnFig1_Click(System::Object^ sender, System::EventArgs^ e) { AbrirJuego(1); }
		System::Void btnFig2_Click(System::Object^ sender, System::EventArgs^ e) { AbrirJuego(2); }
		System::Void btnFig3_Click(System::Object^ sender, System::EventArgs^ e) { AbrirJuego(3); }

		// abre la ventana del juego con la figura seleccionada
		void AbrirJuego(int id) {
			GameForm^ game = gcnew GameForm(id);
			this->Hide();
			game->ShowDialog();
			this->Show();
		}

		// manejador de dibujo para los picturebox de previsualizacion
		void PintarPictureBox(Object^ sender, PaintEventArgs^ e) {
			Graphics^ g = e->Graphics;
			g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

			PictureBox^ pb = safe_cast<PictureBox^>(sender);
			GameController^ ctrl = nullptr;

			if (pb == pictureBox1) ctrl = previa1;
			else if (pb == pictureBox2) ctrl = previa2;
			else if (pb == pictureBox3) ctrl = previa3;

			if (ctrl != nullptr) {
				// ajustar escala y posicion para que quepan en el cuadro 
				
				g->ScaleTransform(0.25f, 0.25f);
				g->TranslateTransform(20, 20); 
				ctrl->dibujar(g);
			}
		}
	};
}
