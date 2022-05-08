#include "MyForm.h"
#include "AuthorInfo.h"
#include "ProgramInfo.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Matrix::MyForm form;
	Application::Run(% form);
}

System::Void Matrix::MyForm::Exit_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("Вы действительно хотите завершить работу программы?", "Предупреждение", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
		Application::Exit();
	}
}

System::Void Matrix::MyForm::Calculate_Click(System::Object^ sender, System::EventArgs^ e)
{
	StatusBar->Hide();
	int sizeOfMatrix;	// установка размера матрицы, реализована через else if, потому что switch не поддерживает строки
	int precision = Convert::ToInt32(Precision->Text);
	if (MatrixSize->Text == "1x1") {
		sizeOfMatrix = 1;
	} else if (MatrixSize->Text == "2x2") {
		sizeOfMatrix = 2;
	} else if (MatrixSize->Text == "3x3") {
		sizeOfMatrix = 3;
	} else if (MatrixSize->Text == "4x4") {
		sizeOfMatrix = 4;
	} else if (MatrixSize->Text == "5x5") {
		sizeOfMatrix = 5;
	} else if (MatrixSize->Text == "6x6") {
		sizeOfMatrix = 6;
	} else {
		MessageBox::Show("В поле Размер матрицы введено некорректное значение. Выберите пожалуйста значение из списка.", "Ошибка качества данных");
		return System::Void();
	}
	// создание массива данными получеными из формы
	double** pData = new double*[sizeOfMatrix];
	for (int i = 0; i < sizeOfMatrix; i++) {
		pData[i] = new double[sizeOfMatrix];
	}
	try {
		if (sizeOfMatrix >= 1) {
			pData[0][0] = Convert::ToDouble(Value00->Text);
		}
		if (sizeOfMatrix >= 2) {
			pData[0][1] = Convert::ToDouble(Value01->Text);
			pData[1][0] = Convert::ToDouble(Value10->Text);
			pData[1][1] = Convert::ToDouble(Value11->Text);
		}
		if (sizeOfMatrix >= 3) {
			pData[0][2] = Convert::ToDouble(Value02->Text);
			pData[1][2] = Convert::ToDouble(Value12->Text);
			pData[2][0] = Convert::ToDouble(Value20->Text);
			pData[2][1] = Convert::ToDouble(Value21->Text);
			pData[2][2] = Convert::ToDouble(Value22->Text);
		}
		if (sizeOfMatrix >= 4) {
			pData[0][3] = Convert::ToDouble(Value03->Text);
			pData[1][3] = Convert::ToDouble(Value13->Text);
			pData[2][3] = Convert::ToDouble(Value23->Text);
			pData[3][0] = Convert::ToDouble(Value30->Text);
			pData[3][1] = Convert::ToDouble(Value31->Text);
			pData[3][2] = Convert::ToDouble(Value32->Text);
			pData[3][3] = Convert::ToDouble(Value33->Text);
		}
		if (sizeOfMatrix >= 5) {
			pData[0][4] = Convert::ToDouble(Value04->Text);
			pData[1][4] = Convert::ToDouble(Value14->Text);
			pData[2][4] = Convert::ToDouble(Value24->Text);
			pData[3][4] = Convert::ToDouble(Value34->Text);
			pData[4][0] = Convert::ToDouble(Value40->Text);
			pData[4][1] = Convert::ToDouble(Value41->Text);
			pData[4][2] = Convert::ToDouble(Value42->Text);
			pData[4][3] = Convert::ToDouble(Value43->Text);
			pData[4][4] = Convert::ToDouble(Value44->Text);
		}
		if (sizeOfMatrix == 6) {
			pData[0][5] = Convert::ToDouble(Value05->Text);
			pData[1][5] = Convert::ToDouble(Value15->Text);
			pData[2][5] = Convert::ToDouble(Value25->Text);
			pData[3][5] = Convert::ToDouble(Value35->Text);
			pData[4][5] = Convert::ToDouble(Value45->Text);
			pData[5][0] = Convert::ToDouble(Value50->Text);
			pData[5][1] = Convert::ToDouble(Value51->Text);
			pData[5][2] = Convert::ToDouble(Value52->Text);
			pData[5][3] = Convert::ToDouble(Value53->Text);
			pData[5][4] = Convert::ToDouble(Value54->Text);
			pData[5][5] = Convert::ToDouble(Value55->Text);
		}
	}
	catch (Exception^ e) {
		MessageBox::Show("В одном из элементов введены данные не типа double. Числа double вводятся с использованием запятой. Исправьте это пожалуйста и повторите вычисления.", "Ошибка качества данных");
		HideOptionalElements();
		for (int i = 0; i < sizeOfMatrix; i++) {
			delete[] pData[i];
		}
		delete[] pData;
		return System::Void();
	}
	MatrixDet currentItem(sizeOfMatrix, pData, precision);
	String^ showDet;
	showDet += currentItem.getDet();
	Determinant->Text = showDet;
	internData = currentItem.getStr();
	for (int i = 0; i < sizeOfMatrix; i++) {
		delete[] pData[i];
	}
	delete[] pData;
	ShowOptionalElements();
	return System::Void();
}

System::Void Matrix::MyForm::Save_Click(System::Object^ sender, System::EventArgs^ e)
{
	StreamWriter^ sw = gcnew StreamWriter("Result.txt");
	sw->Write(internData);
	sw->Close();
	StatusBar->Show();
	return System::Void();
}

System::Void Matrix::MyForm::MatrixSize_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	StatusBar->Hide();
	HideOptionalElements();
	int sizeOfMatrix;
	if (MatrixSize->Text == "1x1") {
		sizeOfMatrix = 1;
	}
	else if (MatrixSize->Text == "2x2") {
		sizeOfMatrix = 2;
	}
	else if (MatrixSize->Text == "3x3") {
		sizeOfMatrix = 3;
	}
	else if (MatrixSize->Text == "4x4") {
		sizeOfMatrix = 4;
	}
	else if (MatrixSize->Text == "5x5") {
		sizeOfMatrix = 5;
	}
	else if (MatrixSize->Text == "6x6") {
		sizeOfMatrix = 6;
	}
	else {
		MessageBox::Show("В поле Размер матрицы введено некорректное значение. Выберите пожалуйста значение из списка.", "Ошибка качества данных");
		return System::Void();
	}
	HideMatrixElements();
	if (sizeOfMatrix >= 1) {
		Value00->Show();
	}
	if (sizeOfMatrix >= 2) {
		Value01->Show();
		Value10->Show();
		Value11->Show();
	}
	if (sizeOfMatrix >= 3) {
		Value02->Show();
		Value12->Show();
		Value20->Show();
		Value21->Show();
		Value22->Show();
	}
	if (sizeOfMatrix >= 4) {
		Value03->Show();
		Value13->Show();
		Value23->Show();
		Value30->Show();
		Value31->Show();
		Value32->Show();
		Value33->Show();
	}
	if (sizeOfMatrix >= 5) {
		Value04->Show();
		Value14->Show();
		Value24->Show();
		Value34->Show();
		Value40->Show();
		Value41->Show();
		Value42->Show();
		Value43->Show();
		Value44->Show();
	}
	if (sizeOfMatrix == 6) {
		Value05->Show();
		Value15->Show();
		Value25->Show();
		Value35->Show();
		Value45->Show();
		Value50->Show();
		Value51->Show();
		Value52->Show();
		Value53->Show();
		Value54->Show();
		Value55->Show();
	}
}

System::Void Matrix::MyForm::HideMatrixElements()
{
	StatusBar->Hide();
	Value00->Hide();
	Value01->Hide();
	Value02->Hide();
	Value03->Hide();
	Value04->Hide();
	Value05->Hide();
	Value10->Hide();
	Value11->Hide();
	Value12->Hide();
	Value13->Hide();
	Value14->Hide();
	Value15->Hide();
	Value20->Hide();
	Value21->Hide();
	Value22->Hide();
	Value23->Hide();
	Value24->Hide();
	Value25->Hide();
	Value30->Hide();
	Value31->Hide();
	Value32->Hide();
	Value33->Hide();
	Value34->Hide();
	Value35->Hide();
	Value40->Hide();
	Value41->Hide();
	Value42->Hide();
	Value43->Hide();
	Value44->Hide();
	Value45->Hide();
	Value50->Hide();
	Value51->Hide();
	Value52->Hide();
	Value53->Hide();
	Value54->Hide();
	Value55->Hide();
}

System::Void Matrix::MyForm::HideOptionalElements()
{
	StatusBar->Hide();
	Detlabel->Hide();
	Determinant->Hide();
	Save->Hide();
}

System::Void Matrix::MyForm::ShowOptionalElements()
{
	Detlabel->Show();
	Determinant->Show();
	Save->Show();
}

System::Void Matrix::MyForm::ClearData_Click(System::Object^ sender, System::EventArgs^ e)
{
	Value00->Text = "";
	Value01->Text = "";
	Value02->Text = "";
	Value03->Text = "";
	Value04->Text = "";
	Value05->Text = "";
	Value10->Text = "";
	Value11->Text = "";
	Value12->Text = "";
	Value13->Text = "";
	Value14->Text = "";
	Value15->Text = "";
	Value20->Text = "";
	Value21->Text = "";
	Value22->Text = "";
	Value23->Text = "";
	Value24->Text = "";
	Value25->Text = "";
	Value30->Text = "";
	Value31->Text = "";
	Value32->Text = "";
	Value33->Text = "";
	Value34->Text = "";
	Value35->Text = "";
	Value40->Text = "";
	Value41->Text = "";
	Value42->Text = "";
	Value43->Text = "";
	Value44->Text = "";
	Value45->Text = "";
	Value50->Text = "";
	Value51->Text = "";
	Value52->Text = "";
	Value53->Text = "";
	Value54->Text = "";
	Value55->Text = "";
	MatrixSize->Text = "";
	Precision->Text = "0";
	HideMatrixElements();
	HideOptionalElements();
	internData = "";
	StatusBar->Hide();
	return System::Void();
}

System::Void Matrix::MyForm::Information_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void Matrix::MyForm::Precision_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e)
{
	HideOptionalElements();
	return System::Void();
}

System::Void Matrix::MyForm::AboutAuthor_Click(System::Object^ sender, System::EventArgs^ e)
{
	Matrix::AuthorInfo^ formAuInfo = gcnew AuthorInfo();
	formAuInfo->Show();
	return System::Void();
}

System::Void Matrix::MyForm::AboutProgram_Click(System::Object^ sender, System::EventArgs^ e)
{
	Matrix::ProgramInfo^ formProInfo = gcnew ProgramInfo();
	formProInfo->Show();
	return System::Void();
}
