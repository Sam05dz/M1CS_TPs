#include "Graphe.h"
#include <stdlib.h>
#include <windows.h>
#include <WinCon.h>
using std::cout;
using std::endl;

using namespace std;
int main(){
			
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	Graphe G;
	G.arete(1,2);
	G.arete(1,3);
	G.arete(1,4);
	G.arete(1,6);
	G.arete(2,3);
	G.arete(2,4);
	G.arete(2,5);
	G.arete(2,6);
	G.arete(3,4);
	G.arete(4,5);
	
SetConsoleTextAttribute(hConsole, 6);
	cout<<"\n\n\n";
	cout<<"\t\t\t\t******************************************************************"<<endl;
	cout<<"\t\t\t\t*                                                                *"<<endl;
	cout<<"\t\t\t\t*                      Batna2 University                         *"<<endl;
	cout<<"\t\t\t\t*                                                                *"<<endl;
	cout<<"\t\t\t\t*                  Faculty Of Computer Sciences                  *"<<endl;
	cout<<"\t\t\t\t*                                                                *"<<endl;
	cout<<"\t\t\t\t*                Solution TP Element Combinatoire                *"<<endl;
	cout<<"\t\t\t\t*                                                                *"<<endl;
	cout<<"\t\t\t\t*                        (Graph Theory)                          *"<<endl;
	cout<<"\t\t\t\t*                                                                *"<<endl;
	cout<<"\t\t\t\t*     Houssam HAMOUDA                    SAMIR Harbi             *"<<endl;
	cout<<"\t\t\t\t*                                                                *"<<endl;
	cout<<"\t\t\t\t*                                                                *"<<endl;
	cout<<"\t\t\t\t*              Crypto & Security - Master 1 Degree               *"<<endl;
	cout<<"\t\t\t\t*                                                                *"<<endl;
	cout<<"\t\t\t\t*                                                      2021-2022 *"<<endl;
	cout<<"\t\t\t\t*                                                                *"<<endl;
	cout<<"\t\t\t\t******************************************************************"<<endl;
	cout<<"\n\n\n\n\n";
	system("pause");
	system("cls");
Menu:
	SetConsoleTextAttribute(hConsole, 2);
	cout<<"\n\n\tMenu Principale:"<<endl;
	cout<<"\t'''''''''''''''\n"<<endl;
	SetConsoleTextAttribute(hConsole, 7);
	cout<<"\t\t1. Repre_Graphe()"<<endl;
	cout<<"\t\t2. Deg_Sommet()"<<endl;   
	cout<<"\t\t3. Test_Sommet_Adj()"<<endl;   
	cout<<"\t\t4. Test_Isole()"<<endl; 
	cout<<"\t\t5. Liste_Arc()"<<endl;
	cout<<"\t\t6. nomb_chaine()"<<endl;
	cout<<"\t\t7. Nbr_Comp_con()"<<endl;
	cout<<"\t\t8. Stable()"<<endl;
	cout<<"\t\t9. Clique()"<<endl;
	cout<<"\t\t0. Quitter\n\n"<<endl;
	SetConsoleTextAttribute(hConsole, 12);
	cout<<"- Faites Votre Choix : ";
	SetConsoleTextAttribute(hConsole, 7);
	int choix;
	cin >> choix;
	cin.ignore(INT_MAX, '\n'); 
	switch (choix) { 
	case 1:
		system("CLS");
		G.repre_graphe();
		goto Menu;
	case 2:
		system("CLS");
		G.Deg_Sommet();
		goto Menu;
	case 3:
		system("CLS");
    	G.Test_Sommet_Adj();
    	goto Menu;
    case 4:
    	system("CLS");
    	G.Test_Isole();
    	goto Menu;
    case 5:
    	system("CLS");
    	G.Liste_Arc();
		goto Menu;
    case 6:
    	system("CLS");
    	G.nomb_chaine();
    	goto Menu;
    case 7:
    	system("CLS");
		G.Nbr_Comp_con();
		system("CLS");
    	goto Menu;
    case 8:
    	system("CLS");
    	G.Stable();
    	goto Menu;
    case 9:
    	system("CLS");
    	G.Clique();
    	goto Menu;
    case 0:
    	system("exit");
    	break;     
	default:
        cout << "Error, Choix Invalid"<<endl;
        system("pause");
	    system("CLS");
        goto Menu;
        break;
	}
	}

