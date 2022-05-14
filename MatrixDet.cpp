#include "MatrixDet.h"

MatrixDet::MatrixDet(int size, double** pData, int precision) {
	str = "";
	this->size = size;
	this->precision = precision;
	this->pData = new double*[size];
	// ��������� ������ ��� ������ ������� ����� ������� ������ �� ��������� �������
	for (int i = 0; i < size; i++) {
		this->pData[i] = new double[size];
	}
	// ������������� ������� ������� �� �����
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			this->pData[i][j] = pData[i][j];
		}
	}
	calcDet();	// ��������� ������������ � ��������� ������ ��� ��������� ����������
}

MatrixDet::~MatrixDet()
{
	for (int i = 0; i < size; i++) {
		delete[] pData[i];
	}
	delete[] pData;
}

double MatrixDet::getDet() {	// �������� ������������� ��� ������ ���������� � int
	long long tempDet;			// ���������� ��� long long, ����� ����� ����������� ������ � �������� �������
	double tempDoubleDet;
	if (precision == 0) {
		tempDet = (long long)det;
		return (double)tempDet;

	} else {					// ����������
		tempDet = 1;
		for (int i = 0; i < precision; i++) {
			tempDet *= 10;
		}
		if (det > 0) {
			tempDoubleDet = (((long long)(det * tempDet * 10) + 5) / (long long)10) / (double)tempDet;
		} 
		else if (det < 0) {
			tempDoubleDet = (((long long)(det * tempDet * 10) - 5) / (long long)10) / (double)tempDet;
		}
		else {
			return 0;
		}
		return tempDoubleDet;
	}
}

String^ MatrixDet::getStr()
{
	return str;
}



void MatrixDet::calcDet() {
	if (size == 1) {		// �������� ���� � ��� ������� �� ������ ��������
		det = pData[0][0];
		str += "������������ ������� " + pData[0][0] + " �����: " + getDet() + ". �������� �����: " + precision;	// ������������ ������ ��� ������ � ����
		return;
	}
	if (zeroColumn()) {	// �������� �� ������� ������ ��� ������� �������
		str += "������������ �����: " + getDet() + ". �������� �����: " + precision;	// ��������� ����������� ������������ �������
		return;
	}
	
	// ���������� ������������ ������� ����� ����� ������������ ��������� ������� ���������, ������� ����������� � ������������ ����
	// ���������� ������� � ������������ ���� ����� ��������� ������� ������
	int rowNumber;		// ����� ������ ��� ������� ��������������� ������������� �� ����� 0
	bool operWasDone;	// �������� ��� ��� ������������ ��������� ���� ������� �������� �� ����
	double tempMultiple;// ��������� ��������� ��� �� ����� ������� ����� ��� ��������� �������
	writeSimpleMatrix();	// ���������� ����������� �������
	for (int i = 0; i < size-1; i++) {	// ��������� ������� ��������� �� ����
//*****************************************************************************************		
		for (int j = 0; j < i; j++) {	// ���������� � ������ ����� ������� ������� ��� �� ����� ��������
			for (int k = 0; k < size; k++) {
				str += pData[j][k] + "\t";
			}
			str += "\n";
		}
//*****************************************************************************************
		if (pData[i][i] == 0) {		// �������� ��� ������� ������� ��������� �� ����� ����
			operWasDone = false;
			for (int j = i + 1; j < size; j++) {	// ����� �������� ��� ��������� ������� ��������� �� ������� ����
				if (pData[j][i] != 0) {
					rowNumber = j;
					operWasDone = true;
					break;
				}
			}
			if (operWasDone) {	// ��� �������� �������� ���������� ��� ��� ������, ����� ������� ������� ��� �� ����� ����
				for (int k = 0; k < size; k++) {
					pData[i][k] += pData[rowNumber][k];
					str += pData[i][k] + "\t";
				}
				str += "\t| ���� " + (rowNumber + 1) + " ������" + "\n";
			} else {		// ������� �� ��� ������, ������ ���� �� ��������� ������� ��������� ����� �����, ������������� � ������������ ������� ����� ����� ����
				for (int j = i; j < size; j++) {
					for (int k = 0; k < size; k++) {
						str += pData[j][k] + "\t";
					}
					str += "\n";
				}
				str += "�������� �� ����, ������ ��� ��� �������� � ������� ������� ������������ ������ ����\n";
				str += "\n";
				continue;
			}
		} else { // ������� ������� ��������� �� ����� ����, �������������� ������� ���������� ��� ������
			for (int k = 0; k < size; k++) {
				str += pData[i][k] + "\t";
			}
			str += "\n";
		}
//*****************************************************************************************
		for (int j = i + 1; j < size; j++) { // ��������� �� ������ ����� ������� ������ ���������� �� �����������, ����� �������� ��� ������� ���������� ����������� ������� ������
			tempMultiple = pData[j][i] / pData[i][i];
			pData[j][i] = 0;		// ���� ������ ����������� ����, �� ��������� �� ���������� � ����� double
			for (int k = i + 1; k < size; k++) {
				pData[j][k] -= pData[i][k] * tempMultiple;
			}
			for (int k = 0; k < size; k++) {
				str += pData[j][k] + "\t";
			}
			str += "\t" + "| ����� " + (i+1) + " ������ ���������� ��: " + tempMultiple + "\n";
		}
//*****************************************************************************************
		str += "\n";	// ��������� ��������� ����� ������������
	}
	det = 1;
	str += "\n������������ �����: ";
	for (int i = 0; i < size; i++) {
		det *= pData[i][i];
		if (i != size - 1) {
			str += pData[i][i] + " * ";
		} else {
			str += pData[i][i];
		}
	}
	str += " = " + getDet() + ". �������� �����: " + precision;
}

bool MatrixDet::zeroColumn() {
	bool zeroRowColumn;
	for (int i = 0; i < size; i++) {
		zeroRowColumn = true;
		for (int j = 0; j < size; j++) {
			if (pData[i][j] != 0) {
				zeroRowColumn = false;
				break;
			}
		}
		if (zeroRowColumn) {
			det = 0;
			writeSimpleMatrix();
			return true;
		}
		zeroRowColumn = true;
		for (int j = 0; j < size; j++) {
			if (pData[j][i] != 0) {
				zeroRowColumn = false;
				break;
			}
		}
		if (zeroRowColumn) {
			det = 0;
			writeSimpleMatrix();
			return true;
		}
	}
	return false;
}

void MatrixDet::writeSimpleMatrix()
{
	str += "�������: \n";
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			str += pData[i][j] + "\t";
		}
		str += "\n";
	}
	str += "\n";
}
