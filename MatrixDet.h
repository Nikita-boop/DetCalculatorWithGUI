#pragma once

using namespace System;
using namespace System::IO;

ref class MatrixDet {
public:
	MatrixDet(int size, double** pData, int precision);	// ���������������� ����������� ������
	~MatrixDet();	// ���������� ��� ������������ ������ � pData
	double getDet();	// ������ ��� ������������, � �������� ��������� ��� ����������
	String^ getStr();	// ������ ��� ������ ������� ����� ��������� � ����
private:
	double** pData;
	int size;
	int precision;
	double det;
	String^ str;

	void calcDet();				// �������� ������� ��� ������� ������������ ������� � ������������ ������ ��� ������������� ��������.
	bool zeroColumn();			// �������� �� ������ ������ ��� ������� � �������
	void writeSimpleMatrix();	// ������ ������� ������� ��� ����������.
};

