#pragma once

using namespace System;
using namespace System::IO;

ref class MatrixDet {
public:
	MatrixDet(int size, double** pData, int precision);	// переопределенный конструктор класса
	~MatrixDet();	// деструктор для освобождения данных в pData
	double getDet();	// геттер для детерминанта, с заданной точностью без округления
	String^ getStr();	// геттер для строки которую будем сохранять в файл
private:
	double** pData;
	int size;
	int precision;
	double det;
	String^ str;

	void calcDet();				// основная функция для расчета определителя матрицы и формирования строки для промежуточных расчетов.
	bool zeroColumn();			// проверка на пустые строки или колонки в матрице
	void writeSimpleMatrix();	// запись простой матрицы без вычислений.
};

