#include <iostream>
#include <vector>
using namespace std;

template<class T> vector<vector<T> > matmul(const vector<vector<T> > &a, const vector<vector<T> > &b){
	vector<vector<T> > mult (a.size(), vector<T>(b[0].size(),0));
	for(size_t i = 0; i < a.size(); ++i)
        for(size_t j = 0; j < b[0].size(); ++j)
            for(size_t k = 0; k < b.size(); ++k)
                mult[i][j] += a[i][k] * b[k][j];
    return mult;
}

template<class T> vector<vector<T> > transpose(const vector<vector<T> > &v){
	vector<vector<T>> trans(v[0].size(),vector<T>(v.size()));
    for (size_t i = 0; i < v.size(); ++i)
        for (size_t j = 0; j < v[0].size(); ++j)
            trans[j][i] = v[i][j];
    return trans;
}

//fancyness
template<class T> vector<vector<T>> operator*(const vector<vector<T>> &a, const vector<vector<T>> &b){
	return matmul(a,b);
}

template<class T>ostream& operator<<(ostream& out, vector<vector<T> > &a){
	for(auto v:a){
		for(auto e:v)
			out<<e<<" ";
		out<<"\n";
	}
	return out;
}
int main(){
	vector<vector<int> > a = {{1,2,3}};

	vector<vector<int> > b = {{1},{2},{3}};

	auto c = a*b;
	cout<<c;
	auto d = transpose(a);
	cout<<d;
	return 0;
}