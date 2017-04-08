#include <iostream>
#include <string>

//arreglo para transformar 4 bits en hexadecimal
char h[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

//transforma un entero a su representacion en hexadecimal sin los cero al principio
std::string aux(unsigned int y){
	std::string s ="";
	unsigned int bitmask = 15;
	int n = 28;
	bool flag = false;
	while(n>=0){
		bitmask<<=n;
		int ans = y & bitmask;
		bitmask>>=n;
		ans>>=n;
		if(h[ans]!='0' || flag){
			s.push_back(h[ans]);
			flag =true;
		}
		n-=4;
	}
	return s;
}

//funcion que toma 3 enteros y devuelve la representacion en hexadecimal como un solo string
std::string tohex(unsigned int year, unsigned int month, unsigned int day){
	std::string sy = aux(year),sm = aux(month),sd = aux(day);
	std::string ans = "";
	ans.append(sy);ans.append(sm);ans.append(sd);
	return ans;
}

int main(){
	std::cout<<tohex(2016,10,17)<<std::endl;
	return 0;
}