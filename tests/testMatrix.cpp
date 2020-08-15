#include <cassert>
#include <iomanip>
#include "../src/matrix.h"

void printVector();
void test_print();
void test_copy_constructor();
void test_assignment();
void test_comparison();
void test_indexing();
void test_random_matrix();
void test_scalar_product();
void test_multiplication_simple();
void test_multiplication_fail();

int main(int argc, char** argv) {
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    std::cout << "Running test suite...\n";
    test_print();
    test_copy_constructor();
    test_assignment();
    test_comparison();
    test_indexing();
    test_random_matrix();
    test_scalar_product();
    test_multiplication_simple();
    test_multiplication_fail();
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

void test_comparison() {
    std::cout << "\n------test_comparison------\n";
    vector<vector<double>> matVec;
    for (size_t i = 0; i < 4; ++i) {
        vector<double> tmp = { 2, 3, 5, 4, 7, 8 };
        matVec.push_back(tmp);
    }
    Matrix mat1(matVec);
    mat1.print("mat1:");
    Matrix mat2 = mat1;
    mat2.print("mat2");
    assert(mat1 == mat2);
    assert(!(mat1 != mat2));
    vector<vector<double>> matVec2;
    for (size_t i = 0; i < 4; ++i) {
        vector<double> tmp = { 1, 3, 5, 4, 7, 8 };
        matVec2.push_back(tmp);
    }
    Matrix mat3(matVec2);
    assert(mat1 != mat3);
    assert(!(mat2 == mat3));
}

void test_indexing() {
    std::cout << "\n------test_indexing------\n";
    vector<vector<double>> matVec;
    for (size_t i = 0; i < 4; ++i) {
        vector<double> tmp = { 2, 3, 5, 4, 7, 8 };
        matVec.push_back(tmp);
    }
    Matrix mat1(matVec);
    mat1.print("mat1:");
    for (size_t i = 0; i < mat1.rows(); ++i) {
        for (size_t j = 0; j < mat1.cols(); ++j) {
            std::cout << " " << mat1[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void test_random_matrix() {
    std::cout << "\n------test_random_matrix------\n";
    Matrix mat1 = randomDefinedMatrix(4,4);
    mat1.print("mat1:");
    Matrix mat2 = randomMatrix();
    mat2.print("mat2:");
    Matrix mat3 = randomMatrix(10,10,10,true);
    mat3.print("mat3:");
}

void test_scalar_product() {
    std::cout << "\n------test_scalar_product------\n";
    vector<vector<double>> matVec1;
    for (size_t i = 0; i < 4; ++i) {
        vector<double> tmp = { 2, 3, 5, 4 };
        matVec1.push_back(tmp);
    }
    Matrix mat1(matVec1);
    mat1.print();
    mat1 = mat1 * 2;
    mat1.print("multiplied by 2:");
    mat1 = 3.1 * mat1;
    mat1.print("multiplied by 3.1:");
}

void test_multiplication_simple() {
    std::cout << "\n------test_multiplication_simple------\n";
    vector<vector<double>> matVec1;
    for (size_t i = 0; i < 4; ++i) {
        vector<double> tmp = { 2, 3, 5, 4 };
        matVec1.push_back(tmp);
    }
    Matrix mat1(matVec1);
    Matrix mat2(mat1);
    Matrix mat3 = mat1 * mat2;
    printProduct(mat1, mat2, mat3);
}

void test_multiplication_fail() {
    std::cout << "\n------test_multiplication_fail------\n";
    Matrix mat1 = randomDefinedMatrix(4,3);
    Matrix mat2 = randomDefinedMatrix(4,5);
    Matrix mat3 = mat1 * mat2;
    printProduct(mat1, mat2, mat3);
    mat3.print();
}