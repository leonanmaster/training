#include "bits/stdc++.h"
#include <thread>
#include <chrono>
using namespace std;

int main(){
    int n;
    int ultimoUm , cont = 0 ;

    cin >> n;

    vector<int> vet(n+1);
    
    for (int i = n; i >= 0; i--){
        cin >> vet[i];
    }

    while(true){

        for (int i = 0; i < vet.size(); i++){
            if (vet[i] == 1){
                ultimoUm = i;
            }
        }
        if(ultimoUm == 0){
            break;
        }
        if (vet[0] == 0){
            for (int i = 0; i < vet.size(); i++){
                if (i == vet.size() - 1){
                    vet[i] = 0;
                }else{
                    vet[i] = vet[i+1];
                }
            }
        } else if (vet[0] == 1) {  
            vector<int> tempVet(vet.size(), 0);
            
            //realizar a mult por x
            for (int i = 0; i < vet.size(); i++) {
                if (vet[i] == 1 && i < vet.size()-1 ){
                    tempVet[i+1] = 1;
                    if (i == 0){
                        tempVet[i] = 0;
                    }
                }else if (vet[i] == 1 && i == vet.size()-1){
                    tempVet.push_back(1);
                }
            }
            //realizar soma com vetor antigo
            for (int i = 0; i < vet.size(); i++){
                tempVet[i] = (tempVet[i] + vet[i]) % 2;
            }

            tempVet[0] = (tempVet[0] + 1) % 2;
                
                /*for (int i = 0; i < tempVet.size(); i++) {
                    cout<< tempVet[i];
                }
                cout << "\n";*/
            
            vet = tempVet;

        } 
        cont++;
    }
    cout << cont;
}