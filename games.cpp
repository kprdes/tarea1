#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void Evaluar(string nombre1, string nombre2);
string Evaluar2(string nombre1, string nombre2, string print);
void Evaluar(string nombre1, string nombre2){
	string letras[27] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
	int puesto, tam;
	vector<string> casos_menores_final;
	string print = "",  comprobar = nombre1, comparar2 = "", palabra = "";	
	bool encontro = false, salida = false, iguales = false, menor_posible = false;
	
	
	for(int i = 0; i < 27 && encontro == false; i++){
		if(letras[i] > nombre1 && letras[i] < nombre2){
			print = letras[i];
			encontro = true;
		}
	}
	if(encontro == false){
		for(int i = 0; i < nombre1.size(); i++){
			if(nombre1[i] == nombre2[i]){
				print += nombre1[i];
				iguales = true;
			}
		}
	}	
	if(print >= nombre1 && print < nombre2){
		casos_menores_final.push_back(print);	
	}
	if(encontro == false && iguales == true){
		if(Evaluar2(nombre1, nombre2, print) != print){
			casos_menores_final.push_back(Evaluar2(nombre1, nombre2, print));
		}	
	}
	
	comprobar = nombre1;
	tam = comprobar.size();
	while(encontro == false && iguales == false && tam != 1){
			
			for(int i = 0; i < tam; i++){
				palabra += comprobar[i];
			}
			comparar2 = Evaluar2(nombre1, nombre2, palabra);
			if(comparar2 >= nombre1 && comparar2 < nombre2){
				casos_menores_final.push_back(comparar2);
			}
		tam --;
		if(tam == 1){
			palabra = "";
			palabra = comprobar[0];
			
			comparar2 = Evaluar2(nombre1, nombre2, palabra);
			if(comparar2 >= nombre1 && comparar2 < nombre2){
				casos_menores_final.push_back(comparar2);
			}
		}
		palabra = "";
	}
	puesto = 0;
	for(int k = 0; k < casos_menores_final.size(); k++){
		if(casos_menores_final[k].size() < casos_menores_final[puesto].size()){		
			puesto = k;
		}
	}
	print = casos_menores_final[puesto];		
	cout << print << endl;
}
string Evaluar2(string nombre1, string nombre2, string print){
	string letras[27] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
	bool salida = false;
	for(int i = 0; i < 27 && salida == false; i++){
		print += letras[i];
		if(print >= nombre1 && print < nombre2){
			salida = true;
		}
		else{
			print.erase(print.end() - 1);
		}
	}
	return print;	
}
int main(){
	int num_nombres = 1, position_mitad;
	string nombre1, nombre2, print;
	while(num_nombres != 0){
		cin >> num_nombres;
		vector<string> invitados(num_nombres);
		if(num_nombres != 0){
			nombre1 = ""; nombre2 = "";
			position_mitad = (num_nombres - 1)/2;
			for(int i = 0; i < num_nombres; i++){
				cin >> invitados[i];
			}
			sort(invitados.begin(), invitados.end());
			
			nombre1 = invitados[position_mitad];
			nombre2 = invitados[position_mitad + 1];
			
			Evaluar(nombre1, nombre2);
		}
		
	}
}
