#include <vector>
#include <deque>

using std::vector;
using std::deque;

/*
A Matrix of width w and height h has w columns and h rows. 
*/
class Matrix {
	public:
		/*** CONSTRUCTORS ***/

		Matrix();
		// construct n x n Matrix 
		Matrix(size_t n);
		// construct rows x cols Matrix
		Matrix(size_t rows, size_t cols);
		// construct from a vector
		Matrix(vector<vector<double>> data);
		// copy constructor
		Matrix(Matrix& m);

		/*** BASIC OPERATORS ****/

		// assignment operator
		Matrix& operator=(Matrix& m);
		// equivalence operator
		bool operator==(Matrix& m);
		// inequality operator
		bool operator!=(Matrix& m);
		// index operator
		// index operator
		vector<double>& operator[](size_t index) {
			return matrix[index];
		}

		/*** MEMBER DATA ACCESS ****/

		size_t size() { return width * height; }
		size_t rows() { return height; }
		size_t cols() { return width; }
		// access the matrix vector
		vector<vector<double>>* getData() {
			return &matrix;
		}

		/*** MULTIPLICATION OPERATORS ***/

		// multiply scalar by Matrix
		friend Matrix& operator*(const double a, Matrix& b);
		// multiply Matrix by scalar
		friend Matrix& operator*(Matrix& a, const double b);
		
		// compute matrix multiplication
		friend Matrix& operator*(Matrix& a, Matrix& b);

		// returns true if is a square matrix
		bool isSquare() { return height == width; }

		// compute determinant of a matrix if there is one
		double determinant();
		
		// print matrix
		void print(std::string message = "");

	protected:
		vector<vector<double>> matrix;
		size_t width;
		size_t height;

		// TODO: better solution: only pass in vector of columns to exclude and row that we are starting on

		double calculateDeterminant(deque<double> matCols, size_t rowStart);
};

class Identity : public Matrix {
	public:
		Identity(size_t size);
};

// calculate hadamard product of two matrices
Matrix& hadamardProduct(Matrix &a, Matrix &b);

// print dot product of two matrices in the format: a * b = c
void printProduct(Matrix &a, Matrix &b, Matrix &c, std::string message = "");

// generate pseurandom double
double randomDouble(int max = 100, bool useInt = false);

// generate pseurandom vector of random length
vector<double> randomVector(int maxLength = 12, int maxVal = 100, bool useInt = false);

// generate pseurandom vector of set length
vector<double> randomDefinedVector(int length, int maxVal = 100, bool useInt = false);
// generate pseurandom matrix with random dimensions
Matrix& randomMatrix(int maxRows = 12, int maxCols = 12, int maxVal = 100, bool useInt = false);

// generate pseudorandom matrix with set dimensions
Matrix& randomDefinedMatrix(int rows = 12, int cols = 12, int maxVal = 100, bool useInt = false);