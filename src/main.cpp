#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include "huffman.h"

using namespace std;

int main()
{
	string str;
	cout << "entrez un texte : ";
	// recupere le texte passé en ligne de commande
	getline(cin, str);
    // applique le code de huffman 
	Huffman(str);
}