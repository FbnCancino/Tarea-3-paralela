#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <string.h>
#include <vector> 

using namespace std;

bool verificar(string n){
	if(n.length()>1){
		return false;
	}
	else{
		if(n[0]>47 && n[0]<58 || n[0]==91 || n[0]==93 || n[0]==59){
			return true;
		}
		else{
			return false;
		}
	}
}


int Convierte (string valor){   
	int n = atoi(valor.c_str()); 
    return n; 
}

void faltantes(int matriz[][3], int n[], int a){
    int aux =1;
    for(int i=0; i<3;i++){
        for(int j=0;j<3;j++){
            if(matriz[i][j]==0){
                matriz[i][j]=aux;                            
                n[a++]=aux;
                i=0;
                j=0;
            }         
            aux++;           
        }
    }
}

void mostrar(int matriz[][3]){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<matriz[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(int argc, string* argv[]){

     //variables necesarias
    int  matriz[3][3];
    int ct=0 ,ct_usa=0;
    int n[3], n_usa[9],  
    string soap = argv[1];
    string rest;  
    for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			matriz[i][j]=0;
		}
    }
	//Para ingresar datos, se ingresa con el siguiente formato: ./ejecutable "[1;2;3]" "[4;5;6]" "[7;8;9]"

	if (argc >2){
		if(verificar(argv[1])== true){ // comprobamos que el argumento sean validos            
            // recorremos para guardar el valor en la posicion indicada
            for(int i=0; i< soap.length(); i++){ 
                json= soap[i];
                if(verificar(json)== true){
                    n[ct]= convierte (json) - 48;
                    ct++;
                }
                if(ct==3) {
                    matriz[n[0]][n[1]]=n[2]; // se agrega el valor a la matriz
                    ct=0;
                    n_usa[ct_usa]=n[2]; // guardamos valor para no volver a utilizarlo
                    ct_usa++;
                }
            }
            
            faltantes (matriz,n_usa,ct_usa);
            mostrar(matriz); 
        }
        else
        {
            cout<<"Datos mal ingresados"<<endl;
        }
	}
    return 0;
}