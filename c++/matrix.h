#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>

template <class T> class Matrix {
	private:
		std::vector<std::vector<T>>mat;
	public:
		Matrix(size_t m,size_t n);
		T& operator[](std::pair<size_t,size_t> p);
};
#endif
