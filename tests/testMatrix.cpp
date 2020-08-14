#include "../src/matrix.h"

void printVector();
void test_print();
void test_copy_constructor();
void test_assignment();
void test_dot_prod();

int main(int argc, char** argv) {
    std::cout << "Running test suite...\n";
    test_print();
    test_copy_constructor();
    test_assignment();
    return 0;
}

void printVector(vector<double> vec) {
    for (size_t i; i < vec.size(); ++i) {
        std::cout << " " << vec[i] << "\n";
    }
}

void test_print() {
    std::cout << "\n------test_print------\n";
    Matrix mat1(4, 4);
    mat1.print("mat1:");
}

void test_copy_constructor() {
    std::cout << "\n------test_copy_constructor------\n";
    vector<vector<double>> matVec;
    for (size_t i = 0; i < 4; ++i) {
        vector<double> tmp;
        for (size_t j = 0; j < 4; ++j) {
            tmp.push_back(j);
        }
        matVec.push_back(tmp);
    }
    Matrix mat2(matVec);
    mat2.print("mat1:");
    Matrix mat3(mat2);
    mat3.print("mat2:");
}

void test_assignment() {
    std::cout << "\n------test_assignment------\n";
    vector<vector<double>> matVec;
    for (size_t i = 0; i < 4; ++i) {
        vector<double> tmp = { 2, 3, 5, 4, 7, 8 };
        matVec.push_back(tmp);
    }
    Matrix mat1(matVec);
    mat1.print("mat1:");
    Matrix mat2 = mat1;
    mat2.print("mat2");
}