/*
Enunciado: Realizar un programa C++ que permita determinar la cantidad de veces que se repite una consonante o vocal en un 
archivo de texto, y establecer el procentaje de su repeticion.

Participantes:
Hamlet Daniel Santana Cruz 1099895
Frederick Fermín Guzman 1100364
Cesar Portillo 1100268

Fecha: 23/03/2022
*/

#include <iostream>
#include <fstream>
#include <algorithm> 
#include <string>
#include <cstring>
#include <cstring>
#include <stdio.h>
#include <cstdio>

using namespace std;



void counters(char text[]){
    char alphabet[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int counters[26] = {0}; 
    // string a1[] = {"À", "Á", "Â", "Ä", "Å"};
    // string e1[] = {"È", "É", "Ê", "Ë"};
    // string i1[] = {"Ì", "Í", "Î", "Ï"};
    // string o1[] = {"Ò", "Ó", "Ô", "Ö"};
    // string u1[] = {"Ù", "Ú", "Û", "Ü"};
    char newText[strlen(text)];
    int strLength = 0;
    for(int i =0; i< strlen(text); i++) {
        newText[i] = toupper(text[i]);
    }
    cout<< text << endl;
    string s = newText;
    for(int i = 0; i < strlen(newText); i++){
        switch (newText[i]) {
            case 'A':
                counters[0]++;
                strLength++;
                break;
            case 'B':
                counters[1]++;
                strLength++;
                break;
            case 'C':
                counters[2]++;
                strLength++;
                break;
            case 'D':
                counters[3]++;
                strLength++;
                break;
            case 'E':
                counters[4]++;
                strLength++;
                break;
            case 'F':
                counters[5]++;
                strLength++;
                break;
            case 'G':
                counters[6]++;
                strLength++;
                break;
            case 'H':
                counters[7]++;
                strLength++;
                break;
            case 'I':  
                counters[8]++;
                strLength++;
                break;
            case 'J':
                counters[9]++;
                strLength++;
                break;
            case 'K':
                counters[10]++;
                strLength++;
                break;
            case 'L':
                counters[11]++;
                strLength++;
                break;
            case 'M':
                counters[12]++;
                strLength++;
                break;
            case 'N':
                counters[13]++;
                strLength++;
                break;
            case 'O':  
                counters[14]++;
                strLength++;
                break;
            case 'P':  
                counters[15]++;
                strLength++;
                break;
            case 'Q':
                counters[16]++;
                strLength++;
                break;
            case 'R':
                counters[17]++;
                strLength++;
                break;
            case 'S':
                counters[18]++;
                strLength++;
                break;
            case 'T':
                counters[19]++;
                strLength++;
                break;
            case 'U':
                counters[20]++;
                strLength++;
                break;
            case 'V':
                counters[21]++;
                strLength++;
                break;
            case 'W':  
                counters[22]++;
                strLength++;
                break;
            case 'X':
                counters[23]++;
                strLength++;
                break;
            case 'Y':
                counters[24]++;
                strLength++;
                break;
            case 'Z':
                counters[25]++;
                strLength++;
                break;
            default:
                break;
        }
        
    }
    
   
//    for(int j = 0; j < 4; j++){
    
//         for (int i = 0; i<s.length(); i++){
//             if(s.find(a1[j], i) > -1){
//                 counters[0]++;
//                 strLength++;
//                 i+=a1[j].length();
//             }
//         }
//         for (int i = 0; i<s.length(); i++){
//             if(s.find(e1[j], i) > -1){
//                 counters[0]++;
//                 strLength++;
//                 i+=e1[j].length();
//             }
//         }
//         for (int i = 0; i<s.length(); i++){
//             if(s.find(i1[j], i) > -1){
//                 counters[0]++;
//                 strLength++;
//                 i+=i1[j].length();
//             }
//         }
//         for (int i = 0; i<s.length(); i++){
//             if(s.find(o1[j], i) > -1){
//                 counters[0]++;
//                 strLength++;
//                 i+=o1[j].length();
//             }
//         }
//         for (int i = 0; i<s.length(); i++){
//             if(s.find(u1[j], i) > -1){
//                 counters[0]++;
//                 strLength++;
//                 i+=u1[j].length();
//             }
//         }
//     }
   
    // for (int i = 0; i<s.length(); i++){
    //         if(s.find(a1[4], i) > -1){
    //             counters[0]++;
    //             strLength++;
    //             i+=a1[4].length();
    //         }
    //     }
        
    
    float porcentaje = 0;
    
    for (int i = 0; i < 26; i++) {
        if(counters[i] != 0){
            porcentaje = (float(counters[i]*100))/strLength;
            cout << "Hay "<<  counters[i] << " " << alphabet[i] << "'s en el texto. Lo cual es "<< porcentaje << "%" << " de todas las letras en el texto" << endl;

        }
    }
}

int main(){
 ifstream archivo;
 string texto;


 archivo.open("prueba.txt" , ios::in);
 if(archivo.fail()){
     cout << "No se pudo abrir el archivo" << endl;
     exit(1);
 }

char chars;
while(!archivo.eof()){
    archivo >> chars;
    texto += chars; 
}
cout << texto << endl;

    int n = texto.length();
    char char_array[n + 1];
    strcpy(char_array, texto.c_str());
    counters(char_array);
    
    cout <<"Hay "<< strlen(char_array) << " caracteres en el archivo" <<endl;
}