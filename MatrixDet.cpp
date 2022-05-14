#include "MatrixDet.h"

MatrixDet::MatrixDet(int size, double** pData, int precision) {
	str = "";
	this->size = size;
	this->precision = precision;
	this->pData = new double*[size];
	// Выделение памяти под массив который будет хранить данные об элементах матрицы
	for (int i = 0; i < size; i++) {
		this->pData[i] = new double[size];
	}
	// Инициализация массива данными из формы
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			this->pData[i][j] = pData[i][j];
		}
	}
	calcDet();	// вычисляем определитель и формируем строку для временных вычислений
}

MatrixDet::~MatrixDet()
{
	for (int i = 0; i < size; i++) {
		delete[] pData[i];
	}
	delete[] pData;
}

double MatrixDet::getDet() {	// точность настраивается при помощи приведения к int
	long long tempDet;			// используем тип long long, чтобы иметь возможность работы с большими числами
	double tempDoubleDet;
	if (precision == 0) {
		tempDet = (long long)det;
		return (double)tempDet;

	} else {					// округление
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
	if (size == 1) {		// проверка если у нас матрица из одного элемента
		det = pData[0][0];
		str += "Определитель матрицы " + pData[0][0] + " равен: " + getDet() + ". Точность равна: " + precision;	// формирование строки для записи в файл
		return;
	}
	if (zeroColumn()) {	// проверка на нулевую строку или нулевой столбец
		str += "Определитель равен: " + getDet() + ". Точность равна: " + precision;	// добавляем вычисленный определитель матрицы
		return;
	}
	
	// нахождение определителя матрицы будет через перемножение элементов главной диагонали, матрицы приведенной к треугольному виду
	// приведение матрицы к треугольному виду будет выполнено методом Гаусса
	int rowNumber;		// номер строки где элемент соответствующий диогональному не равен 0
	bool operWasDone;	// проверка что под диагональным элементом есть элемент отличный от нуля
	double tempMultiple;// временный множитель где мы будем хранить число для обнуления столбца
	writeSimpleMatrix();	// распечатка изначальной матрицы
	for (int i = 0; i < size-1; i++) {	// последнюю строчку проверять не надо
//*****************************************************************************************		
		for (int j = 0; j < i; j++) {	// добавлению в строку строк матрицы которые уже не нужно изменять
			for (int k = 0; k < size; k++) {
				str += pData[j][k] + "\t";
			}
			str += "\n";
		}
//*****************************************************************************************
		if (pData[i][i] == 0) {		// проверка что элемент главной диагонали не равен нулю
			operWasDone = false;
			for (int j = i + 1; j < size; j++) {	// выбор элемента под элементом главной диаганали не равного нулю
				if (pData[j][i] != 0) {
					rowNumber = j;
					operWasDone = true;
					break;
				}
			}
			if (operWasDone) {	// при найденом элементе складываем эти две строки, чтобы элемент главной был не равен нулю
				for (int k = 0; k < size; k++) {
					pData[i][k] += pData[rowNumber][k];
					str += pData[i][k] + "\t";
				}
				str += "\t| плюс " + (rowNumber + 1) + " строка" + "\n";
			} else {		// элемент не был найден, значит один из элементов главной диагонали будет равен, следовательно и определитель матрицы будет равен нулю
				for (int j = i; j < size; j++) {
					for (int k = 0; k < size; k++) {
						str += pData[j][k] + "\t";
					}
					str += "\n";
				}
				str += "Действий не было, потому что все элементы в столбце включая диогональный равный нулю\n";
				str += "\n";
				continue;
			}
		} else { // элемент главной диагонали не равен нулю, соответственно просмто записываем эту строку
			for (int k = 0; k < size; k++) {
				str += pData[i][k] + "\t";
			}
			str += "\n";
		}
//*****************************************************************************************
		for (int j = i + 1; j < size; j++) { // вычитание из нижних строк текущей строки умноженной на коэффициент, чтобы элементы под главной диагональю становились равными нулями
			tempMultiple = pData[j][i] / pData[i][i];
			pData[j][i] = 0;		// ноль всегда присваеваем явно, не полагаясь на вычисление с типом double
			for (int k = i + 1; k < size; k++) {
				pData[j][k] -= pData[i][k] * tempMultiple;
			}
			for (int k = 0; k < size; k++) {
				str += pData[j][k] + "\t";
			}
			str += "\t" + "| минус " + (i+1) + " строка умноженная на: " + tempMultiple + "\n";
		}
//*****************************************************************************************
		str += "\n";	// оставляем растояние между вычислениями
	}
	det = 1;
	str += "\nОпределитель равен: ";
	for (int i = 0; i < size; i++) {
		det *= pData[i][i];
		if (i != size - 1) {
			str += pData[i][i] + " * ";
		} else {
			str += pData[i][i];
		}
	}
	str += " = " + getDet() + ". Точность равна: " + precision;
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
	str += "Матрица: \n";
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			str += pData[i][j] + "\t";
		}
		str += "\n";
	}
	str += "\n";
}
