#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

struct Gigliola{
	vector<string> frases;
	Gigliola(){
		srand(time(NULL));
		frases.push_back("argsss");
		frases.push_back("soy una princesa");
		frases.push_back("las pequeñas mandan");
		frases.push_back("tengo tutin");
		frases.push_back("pescame");
		frases.push_back("los ing no pueden ser comediantes");
		frases.push_back("ya pero estudia");
		frases.push_back("ya dejame");
		frases.push_back("kajaakaa");
	}
	string tirateUnaFrase(){
		int r=rand()%frases.size() + 1;
		return frases[r];
	}
};
int main(){
	Gigliola Gigi;
	while(true)
		cout<< Gigi.tirateUnaFrase() << endl;
	return 0;
}