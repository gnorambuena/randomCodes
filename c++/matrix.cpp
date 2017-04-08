#include "matrix.h"
#include <tuple>
#include <string>
using namespace std;

template <class T> Matrix<T>::Matrix(size_t m,size_t n){
	mat.resize(m);
	mat[0].resize(n);
}

template <class T> T& Matrix<T>::operator[](pair<size_t,size_t> p){
	return mat[p.first][p.second];
}

int main(){
	Matrix<int> mat(5,5);
	mat[{0,0}] = 50;
	cout<<mat[{0,0}]<<"\n";
	tuple<char,int,string,int> tup('a',150,"hola",567);
	printTuple(tup);
	return 0;
}