#include <iostream>
#include <string>
#include <vector>

using namespace std;


void Ganador_Gran_Prix(vector<vector<int> >& orden, vector<vector<int> >& sistemas, int tam_orden, int tam_system, int tam_people);
int find_help(vector<vector<int> >& matriz, int buscar, int fila);
void Mayor_que(vector<int>& vector);
void Ganador_Gran_Prix(vector<vector<int> >& orden, vector<vector<int> >& sistemas, int tam_orden, int tam_system, int tam_people){
	string Ganador;
	int puestos = 0, contador, puesto, fila;
	vector<int> puntaje (tam_people);
	
	for(int i = 0; i < sistemas.size(); i++){
		for(int j = 0; j < orden.size(); j++){
			contador = 1;
			for(int k = 0; k < sistemas[i].size(); k++){
				puesto = find_help(orden, contador, j);
				puntaje[puesto] += sistemas[i][contador - 1];
				contador ++;	
			}
		}
		Mayor_que(puntaje);
		for(int d = 0; d < puntaje.size(); d++){
			puntaje[d] = 0;
		}
	}
	
		
}
int find_help(vector<vector<int> >& matriz, int buscar, int fila){	
	int position = 0;
	for(int i = 0; i< matriz[fila].size(); i++){
		if(matriz[fila][i] == buscar){
			position = i;
		}
	}
	return position;
}
void Mayor_que(vector<int>& puntaje){
	
	vector<int> print;
	int position_mayor = 0, p;
	
	for(int i = 1; i<puntaje.size();i++){
		if(puntaje[i] > puntaje[position_mayor]){
			position_mayor = i;
		}
	}
	for(int i = 0; i<puntaje.size();i++){
		if(puntaje[i] == puntaje[position_mayor]){
			print.push_back(i);
		}
	}
	
	for(p = 0; p < print.size(); p++){
		cout << print[p] + 1 << " ";
	}
	cout << endl;
}

int main(){
	int contador = 0, contador2, score_system, system, j;
	string tamagno, ganador= "";
	vector<int> GP(2);
	vector<vector<int> > position_race, score_system_line;
	while(contador == 0){
		GP.clear();
		for(int i=0; i<2;i++){
			cin>>GP[i];
		}
		position_race.clear();
		score_system_line.clear();
		if(GP[0] == 0 && GP[1] == 0 ){
			contador = 1;
		}
		else{
			//Ciclo para guardar los respectivos orden de llegada en la matriz de vectores
			for(int i = 0; i < GP[0]; i++){
					position_race.push_back(vector<int>(GP[1]));			
					for(int j = 0; j < GP[1]; j++){
						cin >> position_race[i][j];
					}	
			}	
			cin >>score_system;
			for(int i = 0; i < score_system; i++){
				cin >> system;
				score_system_line.push_back(vector<int>(system));		
				for(int j = 0; j < system; j++){
					cin >> score_system_line[i][j];
				}	
			}
			Ganador_Gran_Prix(position_race, score_system_line, GP[0], score_system, GP[1]);
		}				
	}		
	return 0;
}
	


