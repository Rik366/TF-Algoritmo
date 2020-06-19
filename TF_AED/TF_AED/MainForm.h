#pragma once

namespace TF_AED {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  archivoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  abrirToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  guardarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  guardarComoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  editarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  buscarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  filtrarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  seleccionarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  salirToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ordenarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  insertarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  acercaDeToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^  dataGridView1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->archivoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->abrirToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->guardarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->guardarComoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->salirToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->buscarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->filtrarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->seleccionarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ordenarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->insertarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->acercaDeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->archivoToolStripMenuItem,
					this->editarToolStripMenuItem, this->acercaDeToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(516, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// archivoToolStripMenuItem
			// 
			this->archivoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->abrirToolStripMenuItem,
					this->guardarToolStripMenuItem, this->guardarComoToolStripMenuItem, this->salirToolStripMenuItem
			});
			this->archivoToolStripMenuItem->Name = L"archivoToolStripMenuItem";
			this->archivoToolStripMenuItem->Size = System::Drawing::Size(60, 20);
			this->archivoToolStripMenuItem->Text = L"Archivo";
			// 
			// abrirToolStripMenuItem
			// 
			this->abrirToolStripMenuItem->Name = L"abrirToolStripMenuItem";
			this->abrirToolStripMenuItem->Size = System::Drawing::Size(159, 22);
			this->abrirToolStripMenuItem->Text = L"Abrir";
			// 
			// guardarToolStripMenuItem
			// 
			this->guardarToolStripMenuItem->Name = L"guardarToolStripMenuItem";
			this->guardarToolStripMenuItem->Size = System::Drawing::Size(159, 22);
			this->guardarToolStripMenuItem->Text = L"Guardar";
			// 
			// guardarComoToolStripMenuItem
			// 
			this->guardarComoToolStripMenuItem->Name = L"guardarComoToolStripMenuItem";
			this->guardarComoToolStripMenuItem->Size = System::Drawing::Size(159, 22);
			this->guardarComoToolStripMenuItem->Text = L"Guardar como...";
			// 
			// salirToolStripMenuItem
			// 
			this->salirToolStripMenuItem->Name = L"salirToolStripMenuItem";
			this->salirToolStripMenuItem->Size = System::Drawing::Size(159, 22);
			this->salirToolStripMenuItem->Text = L"Salir";
			// 
			// editarToolStripMenuItem
			// 
			this->editarToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->buscarToolStripMenuItem,
					this->filtrarToolStripMenuItem, this->seleccionarToolStripMenuItem, this->ordenarToolStripMenuItem, this->insertarToolStripMenuItem
			});
			this->editarToolStripMenuItem->Name = L"editarToolStripMenuItem";
			this->editarToolStripMenuItem->Size = System::Drawing::Size(58, 20);
			this->editarToolStripMenuItem->Text = L"Edición";
			// 
			// buscarToolStripMenuItem
			// 
			this->buscarToolStripMenuItem->Name = L"buscarToolStripMenuItem";
			this->buscarToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->buscarToolStripMenuItem->Text = L"Buscar";
			this->buscarToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::buscarToolStripMenuItem_Click);
			// 
			// filtrarToolStripMenuItem
			// 
			this->filtrarToolStripMenuItem->Name = L"filtrarToolStripMenuItem";
			this->filtrarToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->filtrarToolStripMenuItem->Text = L"Filtrar por";
			// 
			// seleccionarToolStripMenuItem
			// 
			this->seleccionarToolStripMenuItem->Name = L"seleccionarToolStripMenuItem";
			this->seleccionarToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->seleccionarToolStripMenuItem->Text = L"Seleccionar";
			// 
			// ordenarToolStripMenuItem
			// 
			this->ordenarToolStripMenuItem->Name = L"ordenarToolStripMenuItem";
			this->ordenarToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->ordenarToolStripMenuItem->Text = L"Ordenar";
			// 
			// insertarToolStripMenuItem
			// 
			this->insertarToolStripMenuItem->Name = L"insertarToolStripMenuItem";
			this->insertarToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->insertarToolStripMenuItem->Text = L"Insertar";
			// 
			// acercaDeToolStripMenuItem
			// 
			this->acercaDeToolStripMenuItem->Name = L"acercaDeToolStripMenuItem";
			this->acercaDeToolStripMenuItem->Size = System::Drawing::Size(80, 20);
			this->acercaDeToolStripMenuItem->Text = L"Acerca de...";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(0, 24);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(516, 311);
			this->dataGridView1->TabIndex = 1;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(516, 335);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Trabajo Final - AED";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buscarToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	}
};
}
