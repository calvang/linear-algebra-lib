testMatrix: tests/testMatrix.cpp
	g++ -o tests/testMatrix -I /src/matrix.h src/matrix.cpp src/matrix_helpers.h src/matrix_helpers.cpp  tests/testMatrix.cpp