#include "matrix_helpers.h"

using std::vector;

double KahanSum(vector<double> input) {
    double sum = 0, compensation = 0;
    for (int i = 0; i < input.size(); ++i) {
        double y = input[i] - compensation;
        double t = sum + y;
        compensation = (t - sum) - y;
        sum = t;
    }
    return sum;
}