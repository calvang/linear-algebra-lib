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
		// assignment operator
		Matrix& operator=(Matrix& m) {
			std::cout << "GETTING DATA\n";
			if (&m == this) return *this;
			std::cout << "GETTING DATA\n";
			matrix = *(m.getData());
			std::cout << "GETTING DATA\n";
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
		// index operator
		vector<double>& operator[](size_t index) {
			return matrix[index];
		}

		
		size_t size() { return width * height; }
		size_t rows() { return height; }
		size_t cols() { return width; }

		// multiply scalar by Matrix
		friend Matrix operator*(const double a, Matrix& b) {
			size_t h=b.rows(), w=b.cols();
			Matrix tmp(b);
			for (size_t row=0;row<h;++row) {
				for (size_t col=0;col<w;++col) {
					tmp[row][col] = a*b[row][col];
				}
			}
			return tmp;
		}
		// multiply Matrix by scalar
		friend Matrix operator*(Matrix& a, const double b) {
			size_t h=a.rows(), w=a.cols();
			Matrix tmp(a);
			for (size_t row=0;row<h;++row) {
				for (size_t col=0;col<w;++col) {
					tmp[row][col] = b*a[row][col];
				}
			}
			return tmp;
		}
		
		// compute dot product
		friend Matrix operator*(Matrix& a, Matrix& b) {
			size_t ah=a.rows(), aw=a.cols(), bh=b.rows(), bw=b.cols();
			// TODO implement check to see if matrices are valid
			size_t tmph=ah, tmpw=bh;
			Matrix tmp(tmph,tmpw);
			for (size_t row=0;row<tmph;++row) {
				for (size_t col=0;col<tmpw;++col) {
					size_t product=0;
					for (size_t i=0;i<aw;++i) product+=a[row][i]*b[col][i];
					tmp[row][col]=product;
				}
			}
			return tmp;
		}
		
		// PUBLIC UTILITIES
		vector<vector<double>>* getData() {
			return &matrix;
		}
		
		// prsize_t matrix
		void print() {
			for (size_t row=0;row<height;++row) {
				std::cout << "[";
				for (size_t col=0;col<width;++col) {
					std::cout << " " << matrix[row][col];
				}
				std::cout << " ]\n";
			}
		}
		// prsize_t with header message
		void print(std::string message) {
			std::cout << message << "\n";
			for (size_t row=0;row<height;++row) {
				std::cout << "[";
				for (size_t col=0;col<width;++col) {
					std::cout << " " << matrix[row][col];
				}
				std::cout << " ]\n";
			}
		}

	private:
		vector<vector<double>> matrix;
		size_t width;
		size_t height;
};

// Matrix& cross(Matrix& a, Matrix& b) {
// 	return 
// }