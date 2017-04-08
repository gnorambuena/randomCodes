#include <vector>
#include <iostream>
#include <set>
#include <stack>
#include <stdio.h>
using namespace std;

int c = 0, Mx;
vector <int> LOG;

int log(int N){
	if(LOG[N] != 0){
		return LOG[N];
	}
	if(N == 0){
		return -1;
	}
	int k = -1, a = 1;
	while(a <= N){
		k++;
		a *= 2;
	}
	LOG[N] = k;
	return k;
}

struct SparceTable{

	vector<vector<int> > SP,Hijos;
	vector<int> Nivel;
	int MAX_LOG;
	SparceTable(int, vector <vector <int> >, vector <int>); 
	void Build(int);
	int LCA(int, int);
	int ANiv(int,int);
};

SparceTable::SparceTable(int P, vector<vector <int> > Hij, vector <int> Niv){
	Hijos = Hij;
	Nivel = Niv;
	MAX_LOG = log(Mx) + 1;
	SP.resize(Nivel.size(), vector<int> (MAX_LOG, 1) );

	Build(P);

}

void SparceTable::Build(int i){
	int k = 0, lg, a = 2;
	if(Nivel[i] == 0){
		SP[1][0] = 1;
		a++;
		for(int j = 1; j <= MAX_LOG; j++){
			SP[i][j] = 1;
			//c++;
		}
	}else{	
		for(int j = 1; j <= MAX_LOG; j++){
			SP[i][j] = SP[ SP[i][j-1] ][j-1];
			//c++;
		}
	}

	if(Hijos[i][0] != -1){
		for(int k = 0; k < a; k++){
			SP[ Hijos[i][k] ][0] = i;
			Build(Hijos[i][k]);
			//c++;
		}
	}
}

int SparceTable::ANiv(int nodo, int aux){
	for(int i = 0; i < MAX_LOG; i++){
		if (((1 << i) & aux) != 0){
            nodo = SP[nodo][i];
            //cout << nodo << " soy" << endl;
        }
	}
	return nodo;
}

int SparceTable::LCA(int i, int j){
	int a = 1, aux, k = 0;
	//cout << "i = " << i << " j = " << j << endl;
	if(i == j){
		return i;
	}
	if(SP[i][0] == SP[j][0]){
		return SP[i][0];
	}

	if(Nivel[i] != Nivel[j]){
		if(Nivel[i] > Nivel[j]){
			aux = Nivel[i] - Nivel[j];
			return LCA(ANiv(j, aux), j);
			
		}else{
			aux = Nivel[j] - Nivel[i];
			return LCA(i, ANiv(j, aux));
		}
	}
	k = SP[i].size() - 1;
	while(SP[i][k] == SP[j][k]){
		//c++;
		k--;
	}
	//c++;
	return LCA(SP[i][k], SP[j][k]);
	//*/
}

int main(){
		int n,m,a,b;
		scanf("%d", &n);
		vector <int> Nivel(n * 2 + 5);
		vector <vector<int> > Hijos(n * 2 + 5, vector <int> (2, -1));
		vector <int> llamados(n,0);
		LOG.resize(2 * n + 5,0);
		Hijos[1][0] = 2;
		Hijos[1][1] = 3;
		Hijos[1].push_back(4);
		int k = 5;
		Nivel[1] = 0;
		Nivel[2] = 1; Nivel[3] = 1; Nivel[4] = 1;
		Mx = 0;
		for(int i = 0; i < n; i++){
			scanf("%d", &a);
			Hijos[a][0] = k;
			Nivel[k] = Nivel[a] + 1;
			k++;
			Hijos[a][1] = k;
			Nivel[k] = Nivel[a] + 1;
			llamados[i] = a;
			if(Nivel[k] > Mx){
				Mx = Nivel[k];
			}
			k++;
		}

		SparceTable ST(1, Hijos, Nivel);		
		
		/*/muestrame los ancestros
		for(int i = 1; i < ST.SP.size(); i++){
			cout << "ancestros de " << i << " : ";
			for(int j = 0; j < ST.SP[i].size(); j++){
				cout << ST.SP[i][j] << " ";
			}
			cout << endl;
		}
		//fin del mostramiento*/

		//Simlar el crecimiento
		int Dia = 2, Bor1 = 2, Bor2 = 3, lca, dist, nodo, Min = 1;
		
		for(int i = 0; i < n; i++){
			nodo = Hijos[llamados[i]][0];

			if(llamados[i] == Bor1){
				Dia++;
				Bor1 = nodo;
			}else if(llamados[i] == Bor2){
				Dia++;
				Bor2 = nodo;
			}else if(Nivel[nodo] > Min){
				//para Bor1
				lca = ST.LCA(nodo, Bor1);
				dist = Nivel[nodo] + Nivel[Bor1] - 2 * Nivel[lca];
				//cout << "dist entre " << nodo << " y " << Bor1 << " : " << dist << endl;
				if(dist > Dia){
					Dia = dist;
					Bor2 = nodo;
					if(Nivel[Bor2] < Nivel[nodo]){
						Min++;
					}
				}

				//para Bor2
				lca = ST.LCA(nodo, Bor2);
				dist = Nivel[nodo] + Nivel[Bor2] - 2 * Nivel[lca];
				//cout << "dist entre " << nodo << " y " << Bor2 << " : " << dist << endl;
				if(dist > Dia){
					Dia = dist;
					Bor1 = nodo;
					if(Nivel[Bor1] < Nivel[nodo]){
						Min++;
					}
				}
			}
			//cout << Bor1 << " Bor1 " << Bor2 << " Bor2" << endl;
			printf("%d \n", Dia);

		}
	//cout << c << endl;
}