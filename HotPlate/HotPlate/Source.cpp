#include <iostream>
#include <iomanip>
#include<cmath>
#include <fstream>
using namespace std;

int main() {
	double temperatures[10][10]{ 0.0000 };
	double oldValues[10][10]{ 0 };
	const int ROW_COL_SIZE = 10;
	const int DIGITS = 4;
	int hundredRStart = 0;
	int hundredREnd = ROW_COL_SIZE;
	int hundredCStart = 1;
	int hundredCEnd = ROW_COL_SIZE - 1;
	double nonZeroStart = 100.0000;
	int rowIncrement = ROW_COL_SIZE - 1;
	int rowStart = 1;
	int colStart = 1;
	int rowEnd = ROW_COL_SIZE - 1;
	int colEnd = ROW_COL_SIZE - 1;
	const int TOTAL_SIZE = 10;
	const int DIVIDER = 4;
	double newValues[10][10];
	ifstream inFS;
	ofstream outFS;
	const int SPACING = 10;
	double maxChange = 100;
	const double changeReset = 0.0;

	inFS.open("Inputplate.txt");
	

	for (int i = 0; i < TOTAL_SIZE; ++i) {
		for (int j = 0; j < TOTAL_SIZE; ++j) {
			inFS >> newValues[i][j];
		}
	}
	inFS.close();

	setprecision(DIGITS);

	cout << "Hotplate simulator" << endl;
	cout << endl;
	cout << "Printing initial plate..." << endl;

	for (int i = hundredRStart; i < hundredREnd; i += rowIncrement) {
		for (int j = hundredCStart; j < hundredCEnd; ++j) {
			temperatures[i][j] = nonZeroStart;
		}
	}

	for (int i = 0; i < TOTAL_SIZE; ++i) {
		for (int j = 0; j < TOTAL_SIZE; ++j) {
			if (j != (TOTAL_SIZE - 1)) {
				cout << fixed << setprecision(DIGITS) << setw(SPACING) << right << temperatures[i][j] << ",";
			}
			else {
				cout << fixed << setprecision(DIGITS) << setw(SPACING)<< right << temperatures[i][j];
			}
		}
		cout << endl;
	}
	cout << endl;


	cout << "Printing plate after one iteration..." << endl;

	for (int i = 0; i < TOTAL_SIZE; ++i) {
		for (int j = 0; j < TOTAL_SIZE; ++j) {
			oldValues[i][j] = temperatures[i][j];
		}
	}
	
	for (int i = rowStart; i < rowEnd; ++i) {
		for (int j = colStart; j < colEnd; ++j) {
			temperatures[i][j] = (oldValues[i + 1][j] + oldValues[i - 1][j] + 
				oldValues[i][j - 1] + oldValues[i][j + 1]) / DIVIDER;
		}
	}

	for (int i = 0; i < TOTAL_SIZE; ++i) {
		for (int j = 0; j < TOTAL_SIZE; ++j) {
			if (j != (TOTAL_SIZE - 1)) {
				cout << fixed << setprecision(DIGITS) << setw(SPACING) << right << temperatures[i][j] << ",";
			}
			else {
				cout << fixed << setprecision(DIGITS) << setw(SPACING) << right << temperatures[i][j];
			}
		}
		cout << endl;
	}
	cout << endl;

	cout << "Printing final plate..." << endl;

	while (maxChange > 0.1) {
		maxChange = changeReset;
		for (int i = 0; i < TOTAL_SIZE; ++i) {
			for (int j = 0; j < TOTAL_SIZE; ++j) {
				oldValues[i][j] = temperatures[i][j];
			}
		}


		for (int i = rowStart; i < rowEnd; ++i) {
			for (int j = colStart; j < colEnd; ++j) {
				temperatures[i][j] = (oldValues[i + 1][j] + oldValues[i - 1][j] +
					oldValues[i][j - 1] + oldValues[i][j + 1]) / DIVIDER;
				if (abs(temperatures[i][j] - oldValues[i][j]) > maxChange) {
					maxChange = abs(temperatures[i][j] - oldValues[i][j]);
				}
			}
		}
	}

	for (int i = 0; i < TOTAL_SIZE; ++i) {
		for (int j = 0; j < TOTAL_SIZE; ++j) {
			if (j != (TOTAL_SIZE - 1)) {
				cout << fixed << setprecision(DIGITS) << setw(SPACING) << right << temperatures[i][j] << ",";
			}
			else {
				cout << fixed << setprecision(DIGITS) << setw(SPACING) << right << temperatures[i][j];
			}
		}
		cout << endl;
	}
	cout << endl;

	cout << "Outputting final plate to file \"Hotplate.csv\"..." << endl;
	outFS.open("Hotplate.csv");
	for (int i = 0; i < TOTAL_SIZE; ++i) {
		for (int j = 0; j < TOTAL_SIZE; ++j) {
			if (j != (TOTAL_SIZE - 1)) {
				outFS << fixed << setprecision(DIGITS) << setw(SPACING) << right << temperatures[i][j] << ",";
			}
			else {
				outFS << fixed << setprecision(DIGITS) << setw(SPACING) << right << temperatures[i][j];
			}
		}
		outFS << endl;
	}
	
	outFS.close();
	cout << endl;

	for (int i = 0; i < TOTAL_SIZE; ++i) {
		for (int j = 0; j < TOTAL_SIZE; ++j) {
			temperatures[i][j] = newValues[i][j];
		}
	}

	for (int i = 0; i < TOTAL_SIZE; ++i) {
		for (int j = 0; j < TOTAL_SIZE; ++j) {
			oldValues[i][j] = temperatures[i][j];
		}
	}


	for (int i = rowStart; i < rowEnd; ++i) {
		for (int j = colStart; j < colEnd; ++j) {
			temperatures[i][j] = (oldValues[i + 1][j] + oldValues[i - 1][j] +
				oldValues[i][j - 1] + oldValues[i][j + 1]) / DIVIDER;
		}
	}



	for (int i = 0; i < TOTAL_SIZE; ++i) {
		for (int j = 0; j < TOTAL_SIZE; ++j) {
			oldValues[i][j] = temperatures[i][j];
		}
	}


	for (int i = rowStart; i < rowEnd; ++i) {
		for (int j = colStart; j < colEnd; ++j) {
			temperatures[i][j] = (oldValues[i + 1][j] + oldValues[i - 1][j] +
				oldValues[i][j - 1] + oldValues[i][j + 1]) / DIVIDER;
		}
	}
	for (int i = 0; i < TOTAL_SIZE; ++i) {
		for (int j = 0; j < TOTAL_SIZE; ++j) {
			oldValues[i][j] = temperatures[i][j];
		}
	}


	for (int i = rowStart; i < rowEnd; ++i) {
		for (int j = colStart; j < colEnd; ++j) {
			temperatures[i][j] = (oldValues[i + 1][j] + oldValues[i - 1][j] +
				oldValues[i][j - 1] + oldValues[i][j + 1]) / DIVIDER;
		}
	}
	cout << "Printing input plate after 3 updates..." << endl;
	cout << endl;

	for (int i = 0; i < TOTAL_SIZE; ++i) {
		for (int j = 0; j < TOTAL_SIZE; ++j) {
			if (j != (TOTAL_SIZE - 1)) {
				cout << fixed << setprecision(DIGITS) << setw(SPACING) << right << temperatures[i][j] << ",";
			}
			else {
				cout << fixed << setprecision(DIGITS) << setw(SPACING) << right << temperatures[i][j];
			}
		}
		cout << endl;
	}
	cout << endl;






	system("pause");
	return 0;
}