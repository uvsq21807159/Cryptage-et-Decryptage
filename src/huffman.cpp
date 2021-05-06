#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include "huffman.h"
#include "Sommet.h"

using namespace std;

/// fonction to allocate a new tree node
Sommet* getSommet(char c, int freq, Sommet* left, Sommet* right)
{
	Sommet* node = new Sommet();

	node->c = c;
	node->freq = freq;
	node->left = left;
	node->right = right;


	return node;	
}
// structure de comparaison 
struct cmp
{

	bool operator()(Sommet* left, Sommet* right)
	{   
	  // l'élément avec la plus basse frequence a la priorité la plus élevée

		return left->freq > right->freq;
	}
};
/*fonction qui fait l'encodage du text en utilisant une map
* elle traverse tous les noeuds de l'arbre et genere le code huffman qui correspond 
*/
void encoder(Sommet* root, string str, unordered_map<char , string> &huffmancode)
{
	// if root is null we don't do anything
	if( root == nullptr)
		return;

	//found a leaf node
	if(!root->left && !root->right)
	{
		huffmancode[root->c] = str;
	}

	// on utilise la recusion pour faire notre encodage 
	encoder(root->left, str + "0",huffmancode);
	encoder(root->right, str + "1",huffmancode);

}
/*
*cette fonction permet de traverser notre arbre encoder et de le decoder
*/
void decoder(Sommet* racine, int &index, string str)
{	
	// if root is null we don't do anything
	if(racine == nullptr)
		return;
	// found a leaf node
	if(!racine->left && !racine->right)
	{
		cout << racine-> c;
		return;
	}

	index++;

	if(str[index] == '0')
		decoder(racine->left, index, str);
	else
		decoder(racine->right, index, str);

}

void Huffman(string text)
{
	unordered_map<char, int> freq;
	/*
	*On compte la frequence d'apparition de chaque caractere du texte entré
	*On le stock dans la map freq.
	*/
	for(char c: text) 
	{
		freq[c]++;	
	}
    /*On créé une priority_queue pour stocker les sommet
    *C'est une sorte de file d'attente prioritaire
    */
	priority_queue<Sommet* , vector<Sommet*>, cmp> p;
    

    /*
    *Create a leaf node for each character and add it
    *to the priority queue 
    */
	for(auto i: freq)
	{
		p.push(getSommet(i.first, i.second, nullptr, nullptr));
	}

    
    //permet de parcourir tout les sommet qu'il y a dans p (priority_queue)
	while (p.size() != 1)
	{
		/*remove the two nodes of lowest frequency and highest priority 
		* from p (priority_queue)
		*/
		Sommet* left = p.top();
		p.pop();
		Sommet* right = p.top();
		p.pop();
 
        
		//the sum of the two nodes frequencies.
		int somme = left->freq + right->freq;

		/*
        *Create a new node with these two nodes
        *as children ad with frequency equal to the somme
        * add new node to p (priority_queue)
        */
		p.push(getSommet('\0', somme, left, right));
	}
    

	Sommet* racine = p.top();
    // on parcours l'arbre et on stocke huffman codes dans la map
	unordered_map<char, string> huffmancode;
	encoder(racine, "", huffmancode);
    
    // on l'affiche
	cout << "Huffman codes are : \n" << '\n';
	for(auto i:huffmancode)
	{
		cout << i.first << "" << i.second << '\n';
	}

	cout << "\nLe texte entré est la suivante : \n" << text << '\n';

    //on affiche l'encodage trouvé du texte
	string str = "";
	for(char c: text)
	{
		str += huffmancode[c];
	}

	cout << "\nL'encodage du texte entré est le suivant : \n" << str << '\n';
    
    //on traverse l'arbre et on decode la chaine encodée en haut
	int j = -1;
	// on affiche le decodage du string
	cout << "\nLe texte decodé est le suivant : \n";
	while (j < (int) str.size() - 2)
	{
		decoder(racine, j, str);
	}


}