#include <math.h>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <random>
#include <functional>
#include "matrix.h"
#include "matrix_helpers.h"

using std::vector;
using std::deque;

/*
A Matrix of width w and height h has w columns and h rows. 
*/
class Matrix {
	public:
		/*** CONSTRUCTORS ***/

		Matrix() : height(0), width(0) {}
		// construct n x n Matrix 
		Matrix(size_t n) : height(n), width(n) { 
			matrix=vector<vector<double>>(n, vector<double>(n));
		}
		// construct rows x cols Matrix
		Matrix(size_t rows, size_t cols) : height(rows), width(cols) {
			matrix=vector<vector<double>>(rows, vector<double>(cols));
		}
		// construct from a vector
		Matrix(vector<vector<double>> data) : matrix(data), height(data.size()), width(data[0].size()) {}
		// copy constructor
		// TODO: implement this with std::copy after iterator is implemented
		Matrix(Matrix& m) : height(m.rows()), width(m.cols()) {
			if (&m == this) return;
			matrix = *(m.getData());
		}

		/*** BASIC OPERATORS ****/

		// assignment operator
		Matrix& operator=(Matrix& m) {
			if (&m == this) return *this;
			matrix = *(m.getData());
			return *this;
		}
		// equivalence operator
		bool operator==(Matrix& m) {
			if (height!=m.rows() && width!=m.cols())
				return false;
			for (size_t row=0;row<height;++row) {
				for (size_t col=0;col<width;++col) {
					if (matrix[row][col]!=m[row][col]) return false;
				}
			}
			return true;
		}
		// inequality operator
		bool operator!=(Matrix& m) {
			if (height!=m.rows() && width!=m.cols())
				return true;
			for (size_t row=0;row<height;++row) {
				for (size_t col=0;col<width;++col) {
					if (matrix[row][col]!=m[row][col]) return true;
				}
			}
			return false;
		}

		/*** MULTIPLICATION OPERATORS ***/

		// multiply scalar by Matrix
		friend Matrix& operator*(const double a, Matrix& b) {
			size_t h=b.rows(), w=b.cols();
			Matrix* tmp = new Matrix(b);
			for (size_t row=0;row<h;++row) {
				for (size_t col=0;col<w;++col) {
					(*tmp)[row][col] = a * b[row][col];
				}
			}
			return *tmp;
		}
		// multiply Matrix by scalar
		friend Matrix& operator*(Matrix& a, const double b) {
			size_t h=a.rows(), w=a.cols();
			Matrix* tmp = new Matrix(a);
			for (size_t row=0;row<h;++row) {
				for (size_t col=0;col<w;++col) {
					(*tmp)[row][col] = b*a[row][col];
				}
			}
			return *tmp;
		}
		
		// compute matrix multiplication
		friend Matrix& operator*(Matrix& a, Matrix& b) {
			size_t ah=a.rows(), aw=a.cols(), bh=b.rows(), bw=b.cols();
			// TODO implement size check for algorithm
			if (aw != bh) {
				std::cout << "CANNOT MATRIX MULTIPLICATION\n";
				Matrix* tmp = new Matrix(); 
				return *tmp;
			}
			size_t tmph=ah, tmpw=bh;
			Matrix* tmp = new Matrix(tmph,tmpw);
			for (size_t row=0;row<tmph;++row) {
				for (size_t col=0;col<tmpw;++col) {
					size_t product=0;
					for (size_t i=0;i<aw;++i) {
						product+=a[row][i]*b[i][col];
						//std::cout << " " << a[row][i] << " * " << b[i][col] << " \n";
					}
					(*tmp)[row][col]=product;
				}
			}
			// TODO implement using Kahan Sum
			return *tmp;
		}

		// returns true if is a square matrix
		bool isSquare() { return height == width; }

		// compute determinant of a matrix if there is one
		double determinant() {
			// TODO implement a determinant algorithm
			if (!isSquare()) {
				std::cout << "CANNOT CALCULATE DETERMINANT OF NONSQUARE MATRIX.\n";
				return false;
			}
			deque<double> matCols(width);
			double colNum = -1;
			std::generate(matCols.begin(), matCols.end(), [colNum]() mutable {return ++colNum;});
			calculateDeterminant(matCols, 0);
		}
		
		// print matrix
		void print(std::string message = "") {
			if (message != "") std::cout << message << "\n";
			for (size_t row=0;row<height;++row) {
				std::cout << "[";
				for (size_t col=0;col<width;++col) {
					std::cout << " " << matrix[row][col];
				}
				std::cout << " ]\n";
			}
		}

	protected:
		vector<vector<double>> matrix;
		size_t width;
		size_t height;

		// TODO: better solution: only pass in vector of columns to exclude and row that we are starting on

		double calculateDeterminant(deque<double> matCols, size_t rowStart) {
			// handle case of 2x2
			if ((width - matCols.size()) == 2) {
				return matrix[rowStart][matCols[0]] * matrix[rowStart + 1][matCols[1]] + 
					matrix[rowStart][matCols[1]] * matrix[rowStart + 1][matCols[0]];
			}
			double det = 0;
			for (size_t col = 0; col < matCols.size(); ++col) {
				deque<double> tmpCols = matCols;
				tmpCols.erase(tmpCols.begin() + col, tmpCols.begin() + col + 1);
				if (col % 2 == 0)
					det += matrix[rowStart][matCols[col]] * calculateDeterminant(tmpCols, rowStart + 1);
				else
					det -= matrix[rowStart][matCols[col]] * calculateDeterminant(tmpCols, rowStart + 1);
			}
			return det;
			// if (detMatrix.size() == 2) {
			// 	return detMatrix[0][0] * detMatrix[1][1] + detMatrix[0][1] * detMatrix[1][0];
			// }
			// double det = 0;
			// vector<double> cols = detMatrix[0]
			// detMatrix.pop_front();
			// for (size_t col = 0; col < detMatrix.size(); ++col) {
			// 	// subtract odd cols
			// 	if (col % 2 == 0) {
			// 		det += detMatrix[0][col] * calculateDeterminant(

			// 		);
			// 	}
			// 	else {
			// 		det -= detMatrix[0][col] * calculateDeterminant(

			// 		);
			// 	}
			// }
			// return det;
		}
};

class Identity : public Matrix {
	public:
		Identity(size_t size) : Matrix(size) {
			for (size_t i = 0; i < size; ++i) {
				matrix[i][i] = 1;
			}
		}
};

// calculate hadamard product of two matrices
Matrix& hadamardProduct(Matrix &a, Matrix &b) {
	size_t ah=a.rows(), aw=a.cols(), bh=b.rows(), bw=b.cols();
	if (aw != bw || ah != bh) {
		std::cout << "CANNOT APPLY HADAMARD PRODUCT\n";
		Matrix* tmp = new Matrix(); 
		return *tmp;
	}
	Matrix* tmp = new Matrix(ah,aw);
	for (size_t row=0;row<ah;++row) {
		for (size_t col=0;col<aw;++col) {
			(*tmp)[row][col] = a[row][col] * b[row][col];
		}
	}
	return *tmp;
}

// print dot product of two matrices in the format: a * b = c
void printProduct(Matrix &a, Matrix &b, Matrix &c, std::string message = "") {
	if (message != "") std::cout << message << "\n";
	size_t height = a.rows();
	if (b.rows() > height) height = b.rows();
	if (c.rows() > height) height = c.rows();
	for (size_t row=0;row<height;++row) {
		if (row < a.rows()) {
			std::cout << "[";
			for (size_t col=0;col<a.cols();++col) {
				std::cout << " " << a[row][col];
			}
			std::cout << " ]";
		}
		else {
			std::cout << "";
			for (size_t col=0;col<a.cols();++col) {
				std::cout << "   ";
			}
			std::cout << " ";
		}
		
		if (row == (height - 1) / 2) {
			std::cout << "  *  ";
		}
		else {
			std::cout << "     ";
		}

		if (row < b.rows()) {
			std::cout << "[";
			for (size_t col=0;col<b.cols();++col) {
				std::cout << " " << a[row][col];
			}
			std::cout << " ]";
		}
		else {
			std::cout << "";
			for (size_t col=0;col<b.cols();++col) {
				std::cout << "   ";
			}
			std::cout << " ";
		}

		if (row == (height - 1) / 2) {
			std::cout << "  =  ";
			if (c.size() == 0) std::cout << "IMPOSSIBLE";
		}
		else {
			std::cout << "     ";
		}

		if (row < c.rows()) {
			std::cout << "[";
			for (size_t col=0;col<c.cols();++col) {
				std::cout << " " << a[row][col];
			}
			std::cout << " ]\n";
		}
		else {
			std::cout << "";
			for (size_t col=0;col<c.cols();++col) {
				std::cout << "   ";
			}
			std::cout << " \n";
		}
	}
}

// generate pseurandom double
double randomDouble(int max = 100, bool useInt = false) { 
	if (useInt)
		return std::rand() % max;
	else
		return ((double)(std::rand() % (max*max))) / (double)max;
}

// generate pseurandom vector of random length
vector<double> randomVector(int maxLength = 12, int maxVal = 100, bool useInt = false) {
	int length = std::rand() % maxLength;
	while (length == 0) length = std::rand() % maxLength;
	vector<double> vec(length);
	std::generate(vec.begin(), vec.end(), [maxVal, useInt]() {return randomDouble(maxVal, useInt);});
	return vec;
}

// generate pseurandom vector of set length
vector<double> randomDefinedVector(int length, int maxVal = 100, bool useInt = false) {
	vector<double> vec(length);
	std::generate(vec.begin(), vec.end(), [maxVal, useInt]() {return randomDouble(maxVal, useInt);});
	return vec;
}

// generate pseurandom matrix with random dimensions
Matrix& randomMatrix(int maxRows = 12, int maxCols = 12, int maxVal = 100, bool useInt = false) {
	int numRows = std::rand() % maxRows;
	int numCols = std::rand() % maxCols;
	while (numRows == 0) numRows = std::rand() % maxRows;
	while (numCols == 0) numCols = std::rand() % maxCols;
	vector<vector<double>> matVec(numRows);
	std::generate(matVec.begin(), matVec.end(), 
		[numCols, maxVal, useInt]() {
			return randomDefinedVector(numCols, maxVal, useInt);
		});
	Matrix* mat = new Matrix(matVec);
	return *mat;
}

// generate pseudorandom matrix with set dimensions
Matrix& randomDefinedMatrix(int rows = 12, int cols = 12, int maxVal = 100, bool useInt = false) {
	vector<vector<double>> matVec(rows);
	std::generate(matVec.begin(), matVec.end(), 
		[cols, maxVal, useInt]() {
			return randomDefinedVector(cols, maxVal, useInt);
		});
	Matrix* mat = new Matrix(matVec);
	return *mat;
}

// Matrix& cross(Matrix& a, Matrix& b) {
// 	return 
// }