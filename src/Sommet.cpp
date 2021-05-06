

using namespace std;

#include <iostream>
#include "Sommet.h"
//constructeur par defaut 
Sommet::Sommet(){};
Sommet::~Sommet()
{
    delete right;
    delete left;
    
}
Sommet::Sommet(Sommet* left, int freq, Sommet* right,char c) {
this->left =left ;
this->right =right ;
this->freq=freq;
this->c=c;
}