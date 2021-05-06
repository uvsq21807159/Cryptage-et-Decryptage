Projet C++ : Cryptage et décryptage



 * Dossier src qui contient les fichiers sources suivant :
 		-> main.cpp : qui contient le programme principal
 		-> huffman.cpp et huffman.h : qui contiennet les fonctions de codage de Huffman
 		-> Sommet.cpp et Sommet.h : qui definissent un noeud dans un arbre binaire
 		-> ArbreB.cpp et ArbreB.h : qui definissent un arbre dans la partie1
 		-> Makefile : qui permet de compiler les fichiers du projet 

#Compilation et exécution du projet:
 *La compilation  et exécution du projet se fait à l'aide de la commande suivante :
 		->Ouvrir le terminal dans src/
		->taper la commande : make
		->taper la commande :./run
		->Rentrer le texte que vous voulez encoder ou decoder 
 *Pour suppprimer les fichiers generé lors de la compilation taper : make clean
 
#Sommet.cpp et Sommet.h :
		*Cette classe contient :
				-> un constructeur par defaut 
				-> un constructeur avec comme argument un Sommet gauche et droite , un caractére ainsi que sa fréquence 
				-> un destructeur 
#huffman.cpp huffman.h :
		*Ce fichier contient :
				-> La fonction getSommet : qui permet d'allouer les sommets d'un arbre et le renvoie 
				-> Struct cmp : qui permet de comparer entre la frequence des elements , elle contient bool oprator() .
				-> La fonction encoder : qui permet de faire l'encodage , elle utilise une map qui stocke les string 
				-> La fonction decoder : qui permet de decoder le texte que nous avons encodé 
				-> La fonction Huffman : qui permet d'abord de calculer la frequence d'apparition de chaque caractere on les stocke dans la map pour pouvoir les ecoder selon l'algorithme d'huffman et on affiche le exte encodé. Pour le decodage, on utilise la fonction 'decoder' puis on l'affiche.
#main.cpp :
	   *Ce fichier contient :
	   			-> l'utilisateur rentre un texte, on le recupere puis on applique l'algo d'encodage et decodage d'huffman sur ce texte.


#Exemple : 

entrez un texte : langage
Huffman codes are : 

e110
n111
a10
g01
l00

Le texte entré est la suivante : 
langage

L'encodage du texte entré est le suivant : 
0010111011001110

Le texte decodé est le suivant : 
langage
