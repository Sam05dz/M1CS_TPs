#ifndef GRAPHE_H
#define GRAPHE_H
#include <iostream>
using namespace std;
class Graphe
{
private:
	int noeud;
	int ** g;
public:
	Graphe();
	void arete(int x, int y); //Fonction de Creation d'arete 
	void repre_graphe();     // la representation de la matrice d'adjacence
	void Deg_Sommet();       // Afficher le degre d'un sommet saisi 
	void Test_Sommet_Adj();  // Verifier l'adjacence entre deux sommets quelconque
	void Test_Isole();       // Test sommet saisi isole ou pas 
	void Liste_Arc();        // Lister tout les arcs d'un sommet saisi
	void nomb_chaine();      // Calcul de la matrice M 2, et recherche nombre de chaine entre deux sommet , puis verifier si conexe oupas
	void Nbr_Comp_con();     // La recherche de composante connexe et l'afficher
	void Stable();           // Verifier la stabilite d'un sommet
	void Clique();

	

};

#endif

