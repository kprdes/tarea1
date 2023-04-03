#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main() {
	int vueltas;
	string code;
	string palabra;
	string print;
	int contador;
	cin >> vueltas;
	cin.ignore();
	string morse[] = {".-","-...", "-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","-----",".----","..---","...--","....-",".....","-....","--...","---..","----.",".-.-.-","--..--","..--..",".----.","-.-.--","-..-.","-.--.","-.--.-",".-...","---...","-.-.-.","-...-",".-.-.","-....-","..--.-",".-..-.",".--.-.", "-.-.--"};
    string letras[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", ".", ",", "?", "'", "!", "/","(",")","&",":",";","=","+","-","_","\"","@"};

	vector<string> codigo_morse_matriz(morse, morse + 53);
	vector<string> letras_matriz(letras, letras + 53);
	for(int i = 0; i<vueltas;i++){
		print = "";
		getline(cin, code);
		code += " ";
		for(int k = 0; k < code.size(); k++){
			contador = 0;
			if(code[k]!= ' '){
				palabra += code[k];
				if(k == (code.size()-1)){
					for(int j = 0; j<codigo_morse_matriz.size() && contador == 0; j++){
						if(palabra == codigo_morse_matriz[j]){
							print += letras_matriz[j];
							palabra = "";
							contador = 1;
						}
					}
				}
			}
			else if(code[k] == ' '){
				
				for(int j = 0; j<codigo_morse_matriz.size() && contador == 0; j++){
					if(palabra == codigo_morse_matriz[j]){
						print += letras_matriz[j];
						palabra = "";
						contador = 1;
					}
				}
				if(code[k + 1] == ' ' && k != code.size() - 1){
					print += ' ';
					k += 1;
				}	
			}
		}
		cout<< "Message #"<<i + 1<<endl;
		cout << print << "\n" << endl;
	}
	return 0;
}

