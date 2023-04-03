#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void Evaluar(string& nombre1, string& nombre2);
string Evaluar2(string& nombre1, string& nombre2, string& print);
void Evaluar(string& nombre1, string& nombre2){
	string letras[27] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
	int puesto, tam;
	string casos_menores_final = "";
	string provisional = "", print = "",  comprobar = nombre1, comparar2 = "", palabra = "";	
	bool encontro = false, salida = false, iguales = false, menor_posible = false;
	
	for(int i = 0; i < 27 && encontro == false; i++){
		if(letras[i] >= nombre1 && letras[i] < nombre2){
			print = letras[i];
			casos_menores_final = print;
			encontro = true;
		}
	}
	if(encontro == false){
		for(int i = 0; i < nombre1.size(); i++){
			if(nombre1[i] == nombre2[i]){
				print += nombre1[i];
				iguales = true;
			}
			casos_menores_final = print;
		}
	}	

	if(encontro == false && iguales == true){
	//	cout << "comprobar 4 " << print << " " << casos_menores_final <<endl;
		provisional = Evaluar2(nombre1, nombre2, print);
		//cout << "comprobar 4.1 " << casos_menores_final << " " << provisional << endl;
		if(provisional != print){
			if(casos_menores_final >= nombre1 && casos_menores_final < nombre2 && casos_menores_final.size() < provisional.size()){
				//cout << "comprobar 5 " << casos_menores_final <<endl;
			}
			else{
				casos_menores_final = provisional;
			}	
			//cout << "comprobar 5.1 " << casos_menores_final <<endl;
		}	
	}
	
	if(casos_menores_final.size() == 0){
		casos_menores_final = nombre1;
	}
	comprobar = nombre1;
	tam = comprobar.size();
	while(encontro == false && iguales == false && tam != 1){
			for(int i = 0; i < tam; i++){
				palabra += comprobar[i];
			}
			comparar2 = Evaluar2(nombre1, nombre2, palabra);
			if(comparar2 >= nombre1 && comparar2 < nombre2 && comparar2.size() < casos_menores_final.size()){
				casos_menores_final = comparar2;
			}
		tam --;
		if(tam == 1){
			palabra = "";
			palabra = comprobar[0];
			comparar2 = Evaluar2(nombre1, nombre2, palabra);
			if(comparar2 >= nombre1 && comparar2 < nombre2){
				casos_menores_final = comparar2;
			}
		}
		palabra = "";
	}
	puesto = 0;
	
	comparar2 = Evaluar2(nombre1, nombre2, casos_menores_final);
	if(comparar2 >= nombre1 && comparar2 < nombre2 && comparar2.size() < casos_menores_final.size()){
		casos_menores_final = comparar2;
	}
	if(casos_menores_final >= nombre1 && casos_menores_final < nombre2){
	}
	else{
		palabra = Evaluar2(nombre1, nombre2, casos_menores_final);
		casos_menores_final = palabra;
	}
	print = casos_menores_final;		
	cout << print << endl;
}
string Evaluar2(string& nombre1, string& nombre2, string& print){
	string letras[27] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
	string print2 = print;
	bool salida = false;
	for(int i = 0; i < 27 && salida == false; i++){
		print2 += letras[i];
		if(print2 >= nombre1 && print2 < nombre2){
			salida = true;
		}
		else{
			print2.erase(print2.end() - 1);
		}
	}
	return print2;	
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
