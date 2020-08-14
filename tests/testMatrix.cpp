#include "../src/matrix.h"

void printVector();
void test_print();
void test_copy_constructor();
void test_assignment();
void test_dot_prod();

int main(int argc, char** argv) {
    test_print();
    return 0;
}

void printVector(vector<double> vec) {
    for (size_t i; i < vec.size(); ++i) {
        std::cout << " " << vec[i] << "\n";
    }
}

void test_print() {
    Matrix mat1(4, 4);
    mat1.print();
    vector<vector<double>> matVec;
    for (size_t i = 0; i < 4; ++i) {
        std:: cout <<  "new vec \n";
        vector<double> tmp;
        for (size_t j = 0; j < 4; ++j) {
            std:: cout <<  " " << j << "\n";
            tmp.push_back(j);
        }
        matVec.push_back(tmp);
    }
    Matrix mat2(matVec);
    mat2.print();
    Matrix mat3(mat2);
    mat3.print();
}

void test_copy_constructor() {
    vector<vector<double>> matVec;
    for (size_t i = 0; i < 4; ++i) {
        std:: cout <<  "new vec \n";
        vector<double> tmp;
        for (size_t j = 0; j < 4; ++j) {
            std:: cout <<  " " << j << "\n";
            tmp.push_back(j);
        }
        matVec.push_back(tmp);
    }
    Matrix mat2(matVec);
    mat2.print();
    Matrix mat3(mat2);
    mat3.print();
}