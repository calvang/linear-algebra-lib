#include<math.h>
#include<vector>

using namespace std::vector;

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
		// copy constructor
		// TODO: implement this with std::copy after iterator is implemented
		Matrix(const Matrix& m) : height(m.rows()), width(m.cols()) {
			if (&m == this) return *this;
			if (height!=m.rows() && width!=m.cols())
				matrix=vector<vector<double>>(height, vector<double>(width));
			for (int row=0;row<height;row++) {
				for (int col=0;col<width;col++) {
					matrix[row][col]=m[row][col];
				}
			}
		}
		// assignment operator
		Matrix& operator=(const Matrix& m) {
			if (&m == this) return *this;
			if (height!=m.rows() && width!=m.cols())
				matrix=vector<vector<double>>(height, vector<double>(width));
			for (int row=0;row<height;row++) {
				for (int col=0;col<width;col++) {
					matrix[row][col]=m[row][col];
				}
			}
			return *this;
		}
		// equivalence operator
		bool operator==(const Matrix& m) {
			if (height!=m.rows() && width!=m.cols())
				return false;
			for (int row=0;row<height;row++) {
				for (int col=0;col<width;col++) {
					if (matrix[row][col]!=m[row][col]) return false;
				}
			}
			return true;
		}
		
		int size() { return width * height; }
		int rows() { return height; }
		int cols() { return width; }

		// Multiply scalar by Matrix
		Matrix operator*(const Matrix& a, const Matrix& b) {
			for (int i = 0; i < a.size)
			return
		}
		// Multiply Matrix by scalar
		Matrix operator*(const Matrix& a, const Matrix& b) {
			return
		}
		
		// Multiply Matrix by another Matrix
		Matrix operator*(const Matrix& a, const Matrix& b) {
			return
		}

	private:
		vector<vector<double> matrix;
		int width;
		int height;
};
