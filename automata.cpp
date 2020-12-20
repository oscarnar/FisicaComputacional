#include <iostream>
#include "CImg.h"
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
using namespace cimg_library;

int gen(){
    return rand()%2;
}

void automata(vector<bool>rules,int c){
    CImg<int> img(c,c,1,3);
    int j=c-1;

    srand(unsigned(time(nullptr)));
    vector<int> a(c);
    generate(a.begin(), a.end(), gen);
    vector<int> b(c,0);
    cout<<a[10]<<endl;

    while(j >= 0){
        for(int i=0; i<c; i++){
            int l = i-1;
            int r = i+1;
            if(l < 0)
                l = c-1;
            if(r > c-1)
                r = 0;
            int al = a[l];
            int ar = a[r];
            if(al == 1 && a[i] == 1 && ar == 1)
                b[i] = rules[0];
            if(al == 1 && a[i] == 1 && ar == 0)
                b[i] = rules[1];
            if(al == 1 && a[i] == 0 && ar == 1)
                b[i] = rules[2];
            if(al == 1 && a[i] == 0 && ar == 0)
                b[i] = rules[3];
            if(al == 0 && a[i] == 1 && ar == 1)
                b[i] = rules[4];
            if(al == 0 && a[i] == 1 && ar == 0)
                b[i] = rules[5];
            if(al == 0 && a[i] == 0 && ar == 1)
                b[i] = rules[6];
            if(al == 0 && a[i] == 0 && ar == 0)
                b[i] = rules[7];
        }
        for(int k=0; k<c; k++){
            if(b[k] == 1)
                img(k,j) = 240;
        }
        a = b;
        j = j - 1;
    }
    img.save("auto.png");
    img.display("Automata celular");
}

int main(){
    int tam;
    cin>>tam;
    vector<bool> rules;
    for(int i=0; i<8; i++){
        bool temp;
        cin>>temp;
        rules.push_back(temp);
    }
    automata(rules,tam);
    return 0;
}
