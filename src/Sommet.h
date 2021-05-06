//
// Created by ochaabani on 14/11/2020.
//

#ifndef PROJET_SOMMET_H
#define PROJET_SOMMET_H
using namespace std;
class Sommet {
public:
    int freq;
    Sommet *left;
    Sommet *right;
    char c;
public:
    Sommet(Sommet* left, int freq, Sommet* right,char c) ;
    Sommet();
    ~Sommet();



};


#endif //PROJET_SOMMET_H
