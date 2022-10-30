#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <chrono>
#include <math.h>
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

using namespace std;

//funcion para obtener uso de memoria sacada de stack overflow
int parseLine(char* line){
    int i = strlen(line);
    const char* p = line;
    while (*p <'0' || *p > '9') p++;
    line[i-3] = '\0';
    i = atoi(p);
    return i;
}

int getValue(){ 
    FILE* file = fopen("/proc/self/status", "r");
    int result = -1;
    char line[128];

    while (fgets(line, 128, file) != NULL){
        if (strncmp(line, "VmRSS:", 6) == 0){
            result = parseLine(line);
            break;
        }
    }
    fclose(file);
    return result;
}
//implementacion geeks for geeks suffix array
// la unica diferencia en comparacion a la implemetacion hecha en geeks for geeks es que la
//funcion search cuenta la cantidad de veces que encuentra la palabra en vez de devolver si se encuentra 
//en el texto

//estructura de sufijo la cual almacena el indice de inicio y 
//el sufijo contenido 
struct suffix
{
    int index;
    char *suff;
};
  
// Acomparador que se ultilizara para comparar los sufijos,
// este comparador se usa cuando debemos buscar si el sufijo esta contenido, este nos ayuda para hacer una busqueda binaria
int cmp(struct suffix a, struct suffix b)
{
    return strcmp(a.suff, b.suff) < 0? 1 : 0;
}
  
//con esta funcion construimos el suffix array
int *buildSuffixArray(char *txt, int n)
{
    struct suffix suffixes[n];
  
    //con este for llenamos el arreglo sufijos, con lo cual guardaremos todos los sufijos, 
    //y guardamos las cadenas para porder ordenarlas en orden alfabetico
    for (int i = 0; i < n; i++)
    {
        suffixes[i].index = i;
        suffixes[i].suff = (txt+i);
    }
  
    // ordenamos el arreglo
    sort(suffixes, suffixes+n, cmp);
  
    // guardamos los indices del arreglo
    int *suffixArr = new int[n];
    for (int i = 0; i < n; i++)
        suffixArr[i] = suffixes[i].index;
  
    return  suffixArr;
}


int search(char *pat, char *txt, int *suffArr, int n)
{
    int rep =0;
    int m = strlen(pat);  // obtenemos el largo del patron para usarlo en la funcion strncmp
    int left = 0,right = n-1, middle, comparator, l, r;
    bool found_letter = false;
    // este bucle encuentra la primera repeticion del patron en el suffix array

    while (left <= right)
    {
        middle = (right + left)/2;
        comparator = strncmp(pat, txt+suffArr[middle], m);

        if(comparator == 0){
            found_letter = true;
        }
        if(comparator< 0){
            right = middle+1;
        }
        if(comparator>0){
            left = middle-1;
        }
    }
    //bucle para encontrar todas las repeticiones a la izquierda
    l = middle-1;
    while (strncmp(pat,txt+suffArr[l],m) == 0)
    {
        rep++;
        l-1;
    }
    //bucle para encontrar todas las repeticiones a la derecha
    r = middle +1;
    while (strncmp(pat,txt+suffArr[r],m) == 0)
    {
        rep++;
        r+1;
    }
    
    return rep;
}
int main(){
    string text;
    getline(cin,text);
    string Pat = "rhoncus";

    char pat[Pat.length()];
    strcpy(pat,Pat.c_str());
    char txt[text.length()];
    strcpy(txt,text.c_str());        

    int* suffArr = buildSuffixArray(txt,text.length());
    int rep = search(pat,txt,suffArr,text.length());

    /*
    auto start = chrono::high_resolution_clock::now();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;


    int *suffArr = buildSuffixArray(txt,text.length());
    int kb_usage = getValue();
    int rep;
    vector<double> resultSufArr;
    for (int i = 0; i < 30; i++)
    {
        start =chrono::high_resolution_clock::now();
        rep = search(pat,txt,suffArr,text.length());
        end = chrono::high_resolution_clock::now();
        diff = end-start;
        resultSufArr.push_back(diff.count());

        
    }
    cout<< rep<< endl;
    double  promedioSufArr = 0,varianzaSufArr = 0;

    //resultados Suffix array
    for(vector<double>::iterator it = resultSufArr.begin();it != resultSufArr.end();it++){
        promedioSufArr += *it;
    }
    promedioSufArr /= resultSufArr.size();
    for(vector<double>::iterator it = resultSufArr.begin();it != resultSufArr.end();it++){
        varianzaSufArr += pow((*it-promedioSufArr), 2.0); 
    }
    cout<<Pat<< ","<< promedioSufArr<< ","<< varianzaSufArr<<","<<kb_usage<< endl;
    */
    return 0;

}