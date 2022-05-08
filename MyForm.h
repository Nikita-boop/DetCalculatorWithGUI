#pragma once
#include "MatrixDet.h";

namespace Matrix {

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
			//
			//TODO: Add the constructor code here
			//
			HideMatrixElements();
			HideOptionalElements();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ MainMenu;
	private: System::Windows::Forms::ToolStripMenuItem^ ClearData;
	private: System::Windows::Forms::ToolStripMenuItem^ Exit;
	private: System::Windows::Forms::ToolStripMenuItem^ Help;

	private: System::Windows::Forms::ToolStripMenuItem^ AboutProgram;
	private: System::Windows::Forms::ToolStripMenuItem^ AboutAuthor;
	protected:

	private: System::Windows::Forms::GroupBox^ MatrixData;
	
	private: System::Windows::Forms::TextBox^ Value55;
	private: System::Windows::Forms::TextBox^ Value54;
	private: System::Windows::Forms::TextBox^ Value53;
	private: System::Windows::Forms::TextBox^ Value52;
	private: System::Windows::Forms::TextBox^ Value51;
	private: System::Windows::Forms::TextBox^ Value50;
	private: System::Windows::Forms::TextBox^ Value45;
	private: System::Windows::Forms::TextBox^ Value44;
	private: System::Windows::Forms::TextBox^ Value43;
	private: System::Windows::Forms::TextBox^ Value42;
	private: System::Windows::Forms::TextBox^ Value41;
	private: System::Windows::Forms::TextBox^ Value40;
	private: System::Windows::Forms::TextBox^ Value35;
	private: System::Windows::Forms::TextBox^ Value34;
	private: System::Windows::Forms::TextBox^ Value33;
	private: System::Windows::Forms::TextBox^ Value32;
	private: System::Windows::Forms::TextBox^ Value31;
	private: System::Windows::Forms::TextBox^ Value30;
	private: System::Windows::Forms::TextBox^ Value25;
	private: System::Windows::Forms::TextBox^ Value24;
	private: System::Windows::Forms::TextBox^ Value23;
	private: System::Windows::Forms::TextBox^ Value22;
	private: System::Windows::Forms::TextBox^ Value21;
	private: System::Windows::Forms::TextBox^ Value20;
	private: System::Windows::Forms::TextBox^ Value15;
	private: System::Windows::Forms::TextBox^ Value14;
	private: System::Windows::Forms::TextBox^ Value13;
	private: System::Windows::Forms::TextBox^ Value12;
	private: System::Windows::Forms::TextBox^ Value11;
	private: System::Windows::Forms::TextBox^ Value10;
	private: System::Windows::Forms::TextBox^ Value05;
	private: System::Windows::Forms::TextBox^ Value04;
	private: System::Windows::Forms::TextBox^ Value03;
	private: System::Windows::Forms::TextBox^ Value02;
	private: System::Windows::Forms::TextBox^ Value01;

	private: System::Windows::Forms::TextBox^ Value00;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ MatrixSize;
	private: System::Windows::Forms::Button^ Calculate;
	private: System::Windows::Forms::Button^ Save;
	private: System::Windows::Forms::TextBox^ Determinant;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DomainUpDown^ Precision;
	private: System::Windows::Forms::Label^ Detlabel;
	private: System::Windows::Forms::Label^ StatusBar;

	protected:

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
			this->MainMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ClearData = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Exit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Help = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->AboutProgram = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->AboutAuthor = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MatrixData = (gcnew System::Windows::Forms::GroupBox());
			this->Value55 = (gcnew System::Windows::Forms::TextBox());
			this->Value54 = (gcnew System::Windows::Forms::TextBox());
			this->Value53 = (gcnew System::Windows::Forms::TextBox());
			this->Value52 = (gcnew System::Windows::Forms::TextBox());
			this->Value51 = (gcnew System::Windows::Forms::TextBox());
			this->Value50 = (gcnew System::Windows::Forms::TextBox());
			this->Value45 = (gcnew System::Windows::Forms::TextBox());
			this->Value44 = (gcnew System::Windows::Forms::TextBox());
			this->Value43 = (gcnew System::Windows::Forms::TextBox());
			this->Value42 = (gcnew System::Windows::Forms::TextBox());
			this->Value41 = (gcnew System::Windows::Forms::TextBox());
			this->Value40 = (gcnew System::Windows::Forms::TextBox());
			this->Value35 = (gcnew System::Windows::Forms::TextBox());
			this->Value34 = (gcnew System::Windows::Forms::TextBox());
			this->Value33 = (gcnew System::Windows::Forms::TextBox());
			this->Value32 = (gcnew System::Windows::Forms::TextBox());
			this->Value31 = (gcnew System::Windows::Forms::TextBox());
			this->Value30 = (gcnew System::Windows::Forms::TextBox());
			this->Value25 = (gcnew System::Windows::Forms::TextBox());
			this->Value24 = (gcnew System::Windows::Forms::TextBox());
			this->Value23 = (gcnew System::Windows::Forms::TextBox());
			this->Value22 = (gcnew System::Windows::Forms::TextBox());
			this->Value21 = (gcnew System::Windows::Forms::TextBox());
			this->Value20 = (gcnew System::Windows::Forms::TextBox());
			this->Value15 = (gcnew System::Windows::Forms::TextBox());
			this->Value14 = (gcnew System::Windows::Forms::TextBox());
			this->Value13 = (gcnew System::Windows::Forms::TextBox());
			this->Value12 = (gcnew System::Windows::Forms::TextBox());
			this->Value11 = (gcnew System::Windows::Forms::TextBox());
			this->Value10 = (gcnew System::Windows::Forms::TextBox());
			this->Value05 = (gcnew System::Windows::Forms::TextBox());
			this->Value04 = (gcnew System::Windows::Forms::TextBox());
			this->Value03 = (gcnew System::Windows::Forms::TextBox());
			this->Value02 = (gcnew System::Windows::Forms::TextBox());
			this->Value01 = (gcnew System::Windows::Forms::TextBox());
			this->Value00 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->MatrixSize = (gcnew System::Windows::Forms::ComboBox());
			this->Calculate = (gcnew System::Windows::Forms::Button());
			this->Save = (gcnew System::Windows::Forms::Button());
			this->Determinant = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Precision = (gcnew System::Windows::Forms::DomainUpDown());
			this->Detlabel = (gcnew System::Windows::Forms::Label());
			this->StatusBar = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->MatrixData->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->MainMenu, this->Help });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(684, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// MainMenu
			// 
			this->MainMenu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->ClearData,
					this->Exit
			});
			this->MainMenu->Name = L"MainMenu";
			this->MainMenu->Size = System::Drawing::Size(53, 20);
			this->MainMenu->Text = L"Меню";
			// 
			// ClearData
			// 
			this->ClearData->Name = L"ClearData";
			this->ClearData->Size = System::Drawing::Size(167, 22);
			this->ClearData->Text = L"Очистить форму";
			this->ClearData->Click += gcnew System::EventHandler(this, &MyForm::ClearData_Click);
			// 
			// Exit
			// 
			this->Exit->Name = L"Exit";
			this->Exit->Size = System::Drawing::Size(167, 22);
			this->Exit->Text = L"Выйти";
			this->Exit->Click += gcnew System::EventHandler(this, &MyForm::Exit_Click);
			// 
			// Help
			// 
			this->Help->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->AboutProgram, this->AboutAuthor });
			this->Help->Name = L"Help";
			this->Help->Size = System::Drawing::Size(68, 20);
			this->Help->Text = L"Помощь";
			// 
			// AboutProgram
			// 
			this->AboutProgram->Name = L"AboutProgram";
			this->AboutProgram->Size = System::Drawing::Size(180, 22);
			this->AboutProgram->Text = L"О программе";
			this->AboutProgram->Click += gcnew System::EventHandler(this, &MyForm::AboutProgram_Click);
			// 
			// AboutAuthor
			// 
			this->AboutAuthor->Name = L"AboutAuthor";
			this->AboutAuthor->Size = System::Drawing::Size(180, 22);
			this->AboutAuthor->Text = L"Об авторе";
			this->AboutAuthor->Click += gcnew System::EventHandler(this, &MyForm::AboutAuthor_Click);
			// 
			// MatrixData
			// 
			this->MatrixData->Controls->Add(this->Value55);
			this->MatrixData->Controls->Add(this->Value54);
			this->MatrixData->Controls->Add(this->Value53);
			this->MatrixData->Controls->Add(this->Value52);
			this->MatrixData->Controls->Add(this->Value51);
			this->MatrixData->Controls->Add(this->Value50);
			this->MatrixData->Controls->Add(this->Value45);
			this->MatrixData->Controls->Add(this->Value44);
			this->MatrixData->Controls->Add(this->Value43);
			this->MatrixData->Controls->Add(this->Value42);
			this->MatrixData->Controls->Add(this->Value41);
			this->MatrixData->Controls->Add(this->Value40);
			this->MatrixData->Controls->Add(this->Value35);
			this->MatrixData->Controls->Add(this->Value34);
			this->MatrixData->Controls->Add(this->Value33);
			this->MatrixData->Controls->Add(this->Value32);
			this->MatrixData->Controls->Add(this->Value31);
			this->MatrixData->Controls->Add(this->Value30);
			this->MatrixData->Controls->Add(this->Value25);
			this->MatrixData->Controls->Add(this->Value24);
			this->MatrixData->Controls->Add(this->Value23);
			this->MatrixData->Controls->Add(this->Value22);
			this->MatrixData->Controls->Add(this->Value21);
			this->MatrixData->Controls->Add(this->Value20);
			this->MatrixData->Controls->Add(this->Value15);
			this->MatrixData->Controls->Add(this->Value14);
			this->MatrixData->Controls->Add(this->Value13);
			this->MatrixData->Controls->Add(this->Value12);
			this->MatrixData->Controls->Add(this->Value11);
			this->MatrixData->Controls->Add(this->Value10);
			this->MatrixData->Controls->Add(this->Value05);
			this->MatrixData->Controls->Add(this->Value04);
			this->MatrixData->Controls->Add(this->Value03);
			this->MatrixData->Controls->Add(this->Value02);
			this->MatrixData->Controls->Add(this->Value01);
			this->MatrixData->Controls->Add(this->Value00);
			this->MatrixData->Location = System::Drawing::Point(15, 70);
			this->MatrixData->Name = L"MatrixData";
			this->MatrixData->Size = System::Drawing::Size(655, 190);
			this->MatrixData->TabIndex = 1;
			this->MatrixData->TabStop = false;
			this->MatrixData->Text = L"Матрица";
			// 
			// Value55
			// 
			this->Value55->Location = System::Drawing::Point(545, 155);
			this->Value55->Name = L"Value55";
			this->Value55->Size = System::Drawing::Size(100, 20);
			this->Value55->TabIndex = 35;
			// 
			// Value54
			// 
			this->Value54->Location = System::Drawing::Point(440, 155);
			this->Value54->Name = L"Value54";
			this->Value54->Size = System::Drawing::Size(100, 20);
			this->Value54->TabIndex = 34;
			// 
			// Value53
			// 
			this->Value53->Location = System::Drawing::Point(335, 155);
			this->Value53->Name = L"Value53";
			this->Value53->Size = System::Drawing::Size(100, 20);
			this->Value53->TabIndex = 33;
			// 
			// Value52
			// 
			this->Value52->Location = System::Drawing::Point(230, 155);
			this->Value52->Name = L"Value52";
			this->Value52->Size = System::Drawing::Size(100, 20);
			this->Value52->TabIndex = 32;
			// 
			// Value51
			// 
			this->Value51->Location = System::Drawing::Point(125, 155);
			this->Value51->Name = L"Value51";
			this->Value51->Size = System::Drawing::Size(100, 20);
			this->Value51->TabIndex = 31;
			// 
			// Value50
			// 
			this->Value50->Location = System::Drawing::Point(20, 155);
			this->Value50->Name = L"Value50";
			this->Value50->Size = System::Drawing::Size(100, 20);
			this->Value50->TabIndex = 30;
			// 
			// Value45
			// 
			this->Value45->Location = System::Drawing::Point(545, 130);
			this->Value45->Name = L"Value45";
			this->Value45->Size = System::Drawing::Size(100, 20);
			this->Value45->TabIndex = 29;
			// 
			// Value44
			// 
			this->Value44->Location = System::Drawing::Point(440, 130);
			this->Value44->Name = L"Value44";
			this->Value44->Size = System::Drawing::Size(100, 20);
			this->Value44->TabIndex = 28;
			// 
			// Value43
			// 
			this->Value43->Location = System::Drawing::Point(335, 130);
			this->Value43->Name = L"Value43";
			this->Value43->Size = System::Drawing::Size(100, 20);
			this->Value43->TabIndex = 27;
			// 
			// Value42
			// 
			this->Value42->Location = System::Drawing::Point(230, 130);
			this->Value42->Name = L"Value42";
			this->Value42->Size = System::Drawing::Size(100, 20);
			this->Value42->TabIndex = 26;
			// 
			// Value41
			// 
			this->Value41->Location = System::Drawing::Point(125, 130);
			this->Value41->Name = L"Value41";
			this->Value41->Size = System::Drawing::Size(100, 20);
			this->Value41->TabIndex = 25;
			// 
			// Value40
			// 
			this->Value40->Location = System::Drawing::Point(20, 130);
			this->Value40->Name = L"Value40";
			this->Value40->Size = System::Drawing::Size(100, 20);
			this->Value40->TabIndex = 24;
			// 
			// Value35
			// 
			this->Value35->Location = System::Drawing::Point(545, 105);
			this->Value35->Name = L"Value35";
			this->Value35->Size = System::Drawing::Size(100, 20);
			this->Value35->TabIndex = 23;
			// 
			// Value34
			// 
			this->Value34->Location = System::Drawing::Point(440, 105);
			this->Value34->Name = L"Value34";
			this->Value34->Size = System::Drawing::Size(100, 20);
			this->Value34->TabIndex = 22;
			// 
			// Value33
			// 
			this->Value33->Location = System::Drawing::Point(335, 105);
			this->Value33->Name = L"Value33";
			this->Value33->Size = System::Drawing::Size(100, 20);
			this->Value33->TabIndex = 21;
			// 
			// Value32
			// 
			this->Value32->Location = System::Drawing::Point(230, 105);
			this->Value32->Name = L"Value32";
			this->Value32->Size = System::Drawing::Size(100, 20);
			this->Value32->TabIndex = 20;
			// 
			// Value31
			// 
			this->Value31->Location = System::Drawing::Point(125, 105);
			this->Value31->Name = L"Value31";
			this->Value31->Size = System::Drawing::Size(100, 20);
			this->Value31->TabIndex = 19;
			// 
			// Value30
			// 
			this->Value30->Location = System::Drawing::Point(20, 105);
			this->Value30->Name = L"Value30";
			this->Value30->Size = System::Drawing::Size(100, 20);
			this->Value30->TabIndex = 18;
			// 
			// Value25
			// 
			this->Value25->Location = System::Drawing::Point(545, 80);
			this->Value25->Name = L"Value25";
			this->Value25->Size = System::Drawing::Size(100, 20);
			this->Value25->TabIndex = 17;
			// 
			// Value24
			// 
			this->Value24->Location = System::Drawing::Point(440, 80);
			this->Value24->Name = L"Value24";
			this->Value24->Size = System::Drawing::Size(100, 20);
			this->Value24->TabIndex = 16;
			// 
			// Value23
			// 
			this->Value23->Location = System::Drawing::Point(335, 80);
			this->Value23->Name = L"Value23";
			this->Value23->Size = System::Drawing::Size(100, 20);
			this->Value23->TabIndex = 15;
			// 
			// Value22
			// 
			this->Value22->Location = System::Drawing::Point(230, 80);
			this->Value22->Name = L"Value22";
			this->Value22->Size = System::Drawing::Size(100, 20);
			this->Value22->TabIndex = 14;
			// 
			// Value21
			// 
			this->Value21->Location = System::Drawing::Point(125, 80);
			this->Value21->Name = L"Value21";
			this->Value21->Size = System::Drawing::Size(100, 20);
			this->Value21->TabIndex = 13;
			// 
			// Value20
			// 
			this->Value20->Location = System::Drawing::Point(20, 80);
			this->Value20->Name = L"Value20";
			this->Value20->Size = System::Drawing::Size(100, 20);
			this->Value20->TabIndex = 12;
			// 
			// Value15
			// 
			this->Value15->Location = System::Drawing::Point(545, 55);
			this->Value15->Name = L"Value15";
			this->Value15->Size = System::Drawing::Size(100, 20);
			this->Value15->TabIndex = 11;
			// 
			// Value14
			// 
			this->Value14->Location = System::Drawing::Point(440, 55);
			this->Value14->Name = L"Value14";
			this->Value14->Size = System::Drawing::Size(100, 20);
			this->Value14->TabIndex = 10;
			// 
			// Value13
			// 
			this->Value13->Location = System::Drawing::Point(335, 55);
			this->Value13->Name = L"Value13";
			this->Value13->Size = System::Drawing::Size(100, 20);
			this->Value13->TabIndex = 9;
			// 
			// Value12
			// 
			this->Value12->Location = System::Drawing::Point(230, 55);
			this->Value12->Name = L"Value12";
			this->Value12->Size = System::Drawing::Size(100, 20);
			this->Value12->TabIndex = 8;
			// 
			// Value11
			// 
			this->Value11->Location = System::Drawing::Point(125, 55);
			this->Value11->Name = L"Value11";
			this->Value11->Size = System::Drawing::Size(100, 20);
			this->Value11->TabIndex = 7;
			// 
			// Value10
			// 
			this->Value10->Location = System::Drawing::Point(20, 55);
			this->Value10->Name = L"Value10";
			this->Value10->Size = System::Drawing::Size(100, 20);
			this->Value10->TabIndex = 6;
			// 
			// Value05
			// 
			this->Value05->Location = System::Drawing::Point(545, 30);
			this->Value05->Name = L"Value05";
			this->Value05->Size = System::Drawing::Size(100, 20);
			this->Value05->TabIndex = 5;
			// 
			// Value04
			// 
			this->Value04->Location = System::Drawing::Point(440, 30);
			this->Value04->Name = L"Value04";
			this->Value04->Size = System::Drawing::Size(100, 20);
			this->Value04->TabIndex = 4;
			// 
			// Value03
			// 
			this->Value03->Location = System::Drawing::Point(335, 30);
			this->Value03->Name = L"Value03";
			this->Value03->Size = System::Drawing::Size(100, 20);
			this->Value03->TabIndex = 3;
			// 
			// Value02
			// 
			this->Value02->Location = System::Drawing::Point(230, 30);
			this->Value02->Name = L"Value02";
			this->Value02->Size = System::Drawing::Size(100, 20);
			this->Value02->TabIndex = 2;
			// 
			// Value01
			// 
			this->Value01->Location = System::Drawing::Point(125, 30);
			this->Value01->Name = L"Value01";
			this->Value01->Size = System::Drawing::Size(100, 20);
			this->Value01->TabIndex = 1;
			// 
			// Value00
			// 
			this->Value00->Location = System::Drawing::Point(20, 30);
			this->Value00->Name = L"Value00";
			this->Value00->Size = System::Drawing::Size(100, 20);
			this->Value00->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(15, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(95, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Размер Матрицы";
			// 
			// MatrixSize
			// 
			this->MatrixSize->FormattingEnabled = true;
			this->MatrixSize->Items->AddRange(gcnew cli::array< System::Object^  >(6) { L"1x1", L"2x2", L"3x3", L"4x4", L"5x5", L"6x6" });
			this->MatrixSize->Location = System::Drawing::Point(120, 35);
			this->MatrixSize->Name = L"MatrixSize";
			this->MatrixSize->Size = System::Drawing::Size(121, 21);
			this->MatrixSize->TabIndex = 3;
			this->MatrixSize->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::MatrixSize_SelectedIndexChanged);
			// 
			// Calculate
			// 
			this->Calculate->Location = System::Drawing::Point(15, 305);
			this->Calculate->Name = L"Calculate";
			this->Calculate->Size = System::Drawing::Size(116, 23);
			this->Calculate->TabIndex = 4;
			this->Calculate->Text = L"Рассчитать";
			this->Calculate->UseVisualStyleBackColor = true;
			this->Calculate->Click += gcnew System::EventHandler(this, &MyForm::Calculate_Click);
			// 
			// Save
			// 
			this->Save->Location = System::Drawing::Point(15, 335);
			this->Save->Name = L"Save";
			this->Save->Size = System::Drawing::Size(116, 23);
			this->Save->TabIndex = 5;
			this->Save->Text = L"Сохранить в файл";
			this->Save->UseVisualStyleBackColor = true;
			this->Save->Click += gcnew System::EventHandler(this, &MyForm::Save_Click);
			// 
			// Determinant
			// 
			this->Determinant->Location = System::Drawing::Point(150, 305);
			this->Determinant->Name = L"Determinant";
			this->Determinant->ReadOnly = true;
			this->Determinant->Size = System::Drawing::Size(293, 20);
			this->Determinant->TabIndex = 6;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(255, 35);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(54, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Точность";
			// 
			// Precision
			// 
			this->Precision->Items->Add(L"6");
			this->Precision->Items->Add(L"5");
			this->Precision->Items->Add(L"4");
			this->Precision->Items->Add(L"3");
			this->Precision->Items->Add(L"2");
			this->Precision->Items->Add(L"1");
			this->Precision->Items->Add(L"0");
			this->Precision->Location = System::Drawing::Point(320, 35);
			this->Precision->Name = L"Precision";
			this->Precision->ReadOnly = true;
			this->Precision->Size = System::Drawing::Size(45, 20);
			this->Precision->TabIndex = 8;
			this->Precision->Text = L"0";
			this->Precision->SelectedItemChanged += gcnew System::EventHandler(this, &MyForm::Precision_SelectedItemChanged);
			// 
			// Detlabel
			// 
			this->Detlabel->AutoSize = true;
			this->Detlabel->Location = System::Drawing::Point(150, 285);
			this->Detlabel->Name = L"Detlabel";
			this->Detlabel->Size = System::Drawing::Size(128, 13);
			this->Detlabel->TabIndex = 9;
			this->Detlabel->Text = L"Определитель матрицы";
			// 
			// StatusBar
			// 
			this->StatusBar->AutoSize = true;
			this->StatusBar->Location = System::Drawing::Point(0, 378);
			this->StatusBar->Name = L"StatusBar";
			this->StatusBar->Size = System::Drawing::Size(162, 13);
			this->StatusBar->TabIndex = 10;
			this->StatusBar->Text = L"Данные сохранены в Result.txt";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(684, 392);
			this->Controls->Add(this->StatusBar);
			this->Controls->Add(this->Detlabel);
			this->Controls->Add(this->Precision);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->Determinant);
			this->Controls->Add(this->Save);
			this->Controls->Add(this->Calculate);
			this->Controls->Add(this->MatrixSize);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->MatrixData);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Программа для расчета определителя матрицы";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->MatrixData->ResumeLayout(false);
			this->MatrixData->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: String^ internData;
private: System::Void Exit_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Calculate_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Save_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void MatrixSize_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void HideMatrixElements();
private: System::Void HideOptionalElements();
private: System::Void ShowOptionalElements();
private: System::Void ClearData_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Information_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Precision_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void AboutAuthor_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void AboutProgram_Click(System::Object^ sender, System::EventArgs^ e);
};
}
