#include<math.h>
#include<vector>

class Matrix {
	public:
		Matrix(int size) {
			this.width = size;
			this.height = size;
		}		
	private:
		std::vector<vector<double> matrix;
		int width;
		int height;
};
