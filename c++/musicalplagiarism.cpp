#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

// para evitar escribir unsigned long long a cada rato, le llamaremos uintt
typedef unsigned long long uintt;

// los módulos para ambos hash (usar 2 hash minimiza las chances de colisión)
uintt mod[] = {(int)1e9+7, (int)1e9+9}; // dos primos grandes, caben en un int
//largo máximo que puede tener un string
int maxstrlen = 1e6;

// el hecho de que el Rolling Hashing sea una clase permitirá calcular
//   hash de substrings de varios strings distintos en un mismo problema
class RH {
	// nota: vector<uintt> asdf[2] declara dos vectores de uintt,
	//   o sea, tanto asdf[0] como asdf[1] son un vector<uintt> distinto.

	// precálculo de potencias (x elevado a i mod m) para ambos módulos
	static vector<uintt> x[2]; // es static pues es el mismo para todos los RH
	
	vector<uintt> h[2]; // precálculo de hashs parciales, para ambos hash
	string str; // string cuyos substrings pueden ser hasheados por este RH
	int n; // el tamaño de str

	// private: usar el método público para obtener el hash combinado
	// el parámetro “a” indica cuál de los dos hash se quiere calcular (0 o 1) 
	uintt hash(int a, int start, int len) {
		int end = start + len;
		uintt ans = h[a][start] - h[a][end]*x[a][len] %mod[a] + mod[a];
		// el “+ mod[a]” fue necesario pues lo anterior podría ser negativo
		return ans %mod[a]; // hacer módulo ahora que ans no es negativo
	}

public: RH() {}
	// str: string del cual se producen substrings a hashear
	RH(const string &str) { // complejidad: O(n)
		this->str = str;
		n = str.size();
		// hacer el precálculo de las potencias sólo una vez
		// (aumenta la eficiencia si se crean muchas instancias de RH)
		if (x[0].empty()) {
			// se itera por ambos hash (a = 0 o 1 según en cuál de los dos va)
			for (int a = 0; a < 2; ++a) {
				// rellenar con el caso base, que es que elevar a 0 da siempre 1
				x[a].assign(maxstrlen+1, 1);
				// rellenar el resto de las potencias con dp bottom up
				for (int i = 0; i < maxstrlen; ++i)
					x[a][i+1] = x[a][i]*127 %mod[a];
			}
		}
		// para ambos hash rellenar la dp de hash parciales
		for (int a = 0; a < 2; ++a) {
			h[a].assign(n+1, 0); // rellenar con un “caso base” conveniente
			for (int i = n-1; i >= 0; --i) // rellenar el resto en reversa!!
				h[a][i] = (h[a][i+1]*127 + str[i]) %mod[a];
			// usando 127 no hubo que preocuparse de mapear str[i] a int
		}
	}

	// obtiene el hash de un substring que comienza en el índice “start”
	//   y tiene largo “len”.
	uintt hash(int start, int len) { // complejidad: O(1)
		// como ambos módulos caben en un int, ambos hash también...
		//   luego, se usa operaciones de bits para combinar ambos en un uintt
		return hash(0, start, len) << 32 | hash(1, start, len);
		// (el hash final es la combinación de los hash 0 y 1)
	}


	// desde aquí métodos opcionales... pero útiles
	// (se omiten las explicaciones de cómo fueron implementados)

	// comparador: indica si el substring 1 es lexicográficamente menor al 2.
	// rh2 es el objeto que calculará el hash del substring 2.
	bool es_menor(int start1, int len1, RH &rh2, int start2, int len2) {
		int l = 1, r = min(len1, len2); // complejidad: O(lg n)
		if (hash(start1, r) == rh2.hash(start2, r))
			return len1 < len2;
		while (l < r) {
			int m = (l+r) >> 1;
			if (hash(start1, m) != rh2.hash(start2, m))
				r = m; else l = m+1;
		}
		int i = start1+l-1, j = start2+l-1;
		return str[i] < rh2.str[j];
	}

	// método auxiliar necesario para concatenación de strings, usar el de abajo
	uintt concat(int a, int start1, int len1, RH &rh2, int start2, int len2) {
		uintt ans = hash(a, start1, len1) +
				rh2.hash(a, start2, len2)*x[a][len1] %mod[a];
		return ans %mod[a];
	}

	// concatenación de (sub)strings: retorna el hash de la concatenación entre
	//   dos substrings, donde rh2 es quien contiene al substring 2.
	uintt concat(int start1, int len1, RH &rh2, int start2, int len2) {
		return concat(0, start1, len1, rh2, start2, len2) << 32
				| concat(1, start1, len1, rh2, start2, len2);
	}
};

// esta línea es importante para que el código compile !!
vector<uintt> RH::x[2];

map<string,int>mp = { {"C",0},{"B#",0},
				    {"C#",1},{"Db",1},
				    {"D",2},
				    {"Eb",3},{"D#",3},
				    {"E",4},{"Fb",4},
				    {"F",5},{"E#",5},
					{"Gb",6},{"F#",6},
					{"G",7},
					{"Ab",8},{"G#",8},
					{"A",9},
					{"Bb",10},{"A#",10},
					{"B",11},{"Cb",11}};
int main() {
	int m,t;
	while(cin>>m>>t){
		if(m==0 && t==0)break;
		string s;
		string first;
		cin>>s;
		int f = mp[s];

		for(int i = 1 ; i < m ; i++){
			cin>>s;
			int aux = 0;
			aux = mp[s];
			first.push_back(char((f-aux+12)%12+1+'A'));
			f = aux;
		}

		string second;
		cin>>s;
		f = mp[s];

		for(int i = 1 ; i < t ; i++){
			cin>>s;
			int aux =  mp[s];
			second.push_back(char((f-aux+12)%12+1+'A'));
			f = aux;
		}
		//cout<<first<<" "<<second<<"\n";
		RH rh1(first);RH rh2(second);
		bool flag = false;
		for(int i = 0 ; i <= first.size()-second.size(); i++){
			if(rh1.hash(i,second.size())==rh2.hash(0,second.size())){
				flag = true;
				break;
			}
		}
		cout<<(flag?"S":"N")<<"\n";
	}
	return 0;
}
/*
//comparar dos substrings
//     01234567890123
RH rh(“hola hola chao”);
rh.hash(0, 4) == rh.hash(5, 4) // true, pues “hola” == “hola”
rh.hash(5, 4) == rh.hash(10,4) //false, pues “hola” != “chao”
//en dos RH distintos
RH rh2(“chao hola”);
rh.hash(10, 4) == rh2.hash(0, 4)// true, pues “chao” == “chao”*/