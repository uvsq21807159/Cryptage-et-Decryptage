
#ifndef H_HUFFMAN
#define H_HUFFMAN
#include <string>
#include "Sommet.h"
#include <unordered_map>
using namespace std;


Sommet* getSommet(char c, int freq, Sommet* left, Sommet* right);

void encoder(Sommet* root, string str, unordered_map<char , string> &huffmancode);

void decoder(Sommet* racine, int &index, string str);

void Huffman(string text);

#endif //PROJET_HuFFMAN_H
