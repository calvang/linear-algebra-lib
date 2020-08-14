#include<math.h>
#include<vector>
#include<iostream>

using std::vector;

/*
A Matrix of width w and height h has w columns and h rows. 
*/
class Matrix {
	public:
		Matrix() : height(0), width(0) {}
		// construct n x n Matrix 
		Matrix(int n) : height(n), width(n) { 
			matrix=vector<vector<double>>(n, vector<double>(n));
		}
		// construct rows x cols Matrix
		Matrix(int rows, int cols) : height(rows), width(cols) {
			matrix=vector<vector<double>>(rows, vector<double>(cols));
		}
		// construct from a vector
		Matrix(vector<vector<double>> data) : matrix(data), height(data.size()), width(data[0].size()) {}
		// copy constructor
		// TODO: implement this with std::copy after iterator is implemented
		Matrix(Matrix& m) : height(m.rows()), width(m.cols()) {
			if (&m == this) return;
			// if (height!=m.rows() && width!=m.cols())
			// 	matrix=vector<vector<double>>(height, vector<double>(width));
			// for (int row=0;row<height;++row) {
			// 	for (int col=0;col<width;++col) {
			// 		matrix[row][col]=m[row][col];
			// 	}
			// }
			matrix = *(m.getData());
		}
		// assignment operator
		Matrix& operator=(Matrix& m) {
			std::cout << "GETTING DATA\n";
			if (&m == this) return *this;
			// if (height!=m.rows() && width!=m.cols())
			// 	matrix=vector<vector<double>>(height, vector<double>(width));
			// for (int row=0;row<height;++row) {
			// 	for (int col=0;col<width;++col) {
			// 		matrix[row][col]=m[row][col];
			// 	}
			// }
			std::cout << "GETTING DATA\n";
			matrix = *(m.getData());
			std::cout << "GETTING DATA\n";
			return *this;
		}
		// equivalence operator
		bool operator==(Matrix& m) {
			if (height!=m.rows() && width!=m.cols())
				return false;
			for (int row=0;row<height;++row) {
				for (int col=0;col<width;++col) {
					if (matrix[row][col]!=m[row][col]) return false;
				}
			}
			return true;
		}
		// index operator
		vector<double>& operator[](int index) {
			return matrix[index];
		}

		
		int size() { return width * height; }
		int rows() { return height; }
		int cols() { return width; }

		// multiply scalar by Matrix
		friend Matrix operator*(const double a, Matrix& b) {
			int h=b.rows(), w=b.cols();
			Matrix tmp(b);
			for (int row=0;row<h;++row) {
				for (int col=0;col<w;++col) {
					tmp[row][col] = a*b[row][col];
				}
			}
			return tmp;
		}
		// multiply Matrix by scalar
		friend Matrix operator*(Matrix& a, const double b) {
			int h=a.rows(), w=a.cols();
			Matrix tmp(a);
			for (int row=0;row<h;++row) {
				for (int col=0;col<w;++col) {
					tmp[row][col] = b*a[row][col];
				}
			}
			return tmp;
		}
		
		// compute dot product
		friend Matrix operator*(Matrix& a, Matrix& b) {
			int ah=a.rows(), aw=a.cols(), bh=b.rows(), bw=b.cols();
			// TODO implement check to see if matrices are valid
			int tmph=ah, tmpw=bh;
			Matrix tmp(tmph,tmpw);
			for (int row=0;row<tmph;++row) {
				for (int col=0;col<tmpw;++col) {
					int product=0;
					for (int i=0;i<aw;++i) product+=a[row][i]*b[col][i];
					tmp[row][col]=product;
				}
			}
			return tmp;
		}
		
		// PUBLIC UTILITIES
		vector<vector<double>>* getData() {
			return &matrix;
		}

		void print() {
			for (int row=0;row<height;++row) {
				std::cout << "|";
				for (int col=0;col<width;++col) {
					std::cout << " " << matrix[row][col];
				}
				std::cout << " |\n";
			}
		}

	private:
		vector<vector<double>> matrix;
		int width;
		int height;
};

// Matrix& cross(Matrix& a, Matrix& b) {
// 	return 
// }