#include "Graphe.h"
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <WinCon.h>
using std::cout;
using std::endl;
using namespace std;

Graphe::Graphe(){
	
    noeud = 6; // Nombre de Sommets
	int i,j;
	
	g = new int * [noeud];
	
	for (i=0; i<noeud;i++)
	{
		g[i]=new int [noeud];

		for (j=0;j<noeud;j++)
		  g[i][j]=0;

	}
}
void Graphe::arete(int x,int y){
	g[x-1][y-1]=1;
	g[y-1][x-1]=1;

}
void Graphe::repre_graphe(){
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 2);
	cout<<"\t*****************************************************"<<endl;
	cout<<"\t*   La Representation de la Matrice d'adjacence :   *"<<endl;
	cout<<"\t*****************************************************"<<endl;
	SetConsoleTextAttribute(hConsole, 7);
   
	int i,j;
	// un petit tweak pour afficher les lettres dans les lignes et colonnes de notre matrice
	char chaine[]="ABCDEF";
	char chains[]="FEDCBA-";
	
			for (j=noeud;j>=0;j--)
			{
				cout<<"\t("<<chains[j]<<")";
			}
	
	cout<<endl;
	
	for (i=0;i<noeud;i++)
	{
		cout<<"\n\t("<<chaine[i]<<")";
			for (j=0;j<noeud;j++)
				cout<<"\t "<<g[i][j]; 
				cout<<endl;
	}
		cout<<"\n";
	system("pause");
	system("CLS");
}
void Graphe::Deg_Sommet(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
Menu:
	int i,j,k;
	char chaine[]="ABCDEF";
	k=0;
    cout << "\n\tIntroduire le sommet a verifier :" ;
    char resi;
    cin >> resi;
    switch (resi) {
    case 'A':
    case 'a':
    	i=0;
        break;
    case 'B':
    case 'b':
      	i=1;
        break;
    case 'C':
    case 'c':
      	i=2;
        break;
    case 'D':
    case 'd':
      	i=3;
        break;
    case 'E':
    case 'e':
      	i=4;
        break;
    case 'F':
    case 'f':
      	i=5;
        break;
    
	default:
        cout << "\n\tErreurr, Sommet Inexistant .\n"<<endl;
        system("pause");
        system("CLS");
        goto Menu;
        break;
    	}
    	

		cout<<endl;
		cout<<"\tLe degre du sommet '"<<chaine[i]<<"' est :  ";
		
		for (j=0;j<noeud;j++)
		{
			if (g[i][j]!=0){
				k=k+1;
			}
					
		}
		cout<<k<<"\n"<<endl;
		
	err:
		cout << "\nTester d'autre Sommets?[";
		SetConsoleTextAttribute(hConsole, 2);cout<<"O";
		SetConsoleTextAttribute(hConsole, 7);cout<<"]ui/[";
		SetConsoleTextAttribute(hConsole, 12);cout<<"N";
		SetConsoleTextAttribute(hConsole, 7);cout<<"]on: ";	
			char o;
			cin >>o;
			cin.ignore(INT_MAX, '\n');
			switch (o) {
    case 'O':
    case 'o':
       system("CLS");	
       goto Menu;
	   break;
    case 'n':
    case 'N':
    system("CLS");
        break;
    default:
        cout << "\nError, Choix indisponible .\n"<<endl;
        goto err ;
        break;
    	} 
		
}
void Graphe::Test_Sommet_Adj(){
	
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

Menu:	
cout<<"\nQuel Sommets voulez Vous tester?\n"<<endl;
int i ;
int j ;
char  som[]="ABCDEF";
errr:
    cout << "\nIntroduire le Sommet ";
	SetConsoleTextAttribute(hConsole, 2);cout<<"U :";
	SetConsoleTextAttribute(hConsole, 7);
    char resi;
    cin >> resi;
    switch (resi) {
    case 'A':
    case 'a':
    	i=1;
        break;
    case 'B':
    case 'b':
      	i=2;
        break;
    case 'C':
    case 'c':
      	i=3;
        break;
    case 'D':
    case 'd':
      	i=4;
        break;
    case 'E':
    case 'e':
      	i=5;
        break;
    case 'F':
    case 'f':
      	i=6;
        break;
    
	default:
        cout << "\n\tErreurr, Sommet Inexistant ."<<endl;
        system("CLS");
        goto errr;
        break;
    	}
errb:
    cout << "\nIntroduire le Sommet ";
	SetConsoleTextAttribute(hConsole, 2);
	cout<<"V :";
	SetConsoleTextAttribute(hConsole, 7) ;
    char resj;
    cin >> resj;
    switch (resj) {
    case 'A':
    case 'a':
    	j=1;
        break;
    case 'B':
    case 'b':
      	j=2;
        break;
    case 'C':
    case 'c':
      	j=3;
        break;
    case 'D':
    case 'd':
      	j=4;
        break;
    case 'E':
    case 'e':
      	j=5;
        break;
    case 'F':
    case 'f':
      	j=6;
        break;
    
	default:
        cout << "\n\tErreurr, Sommet Inexistant .\n"<<endl;
        system("CLS");
        goto errb;
        break;
    	}
	cout<<endl;
    
	if (i>0 and j<7)
	{
			if (g[i-1][j-1]!=0)
			{
				SetConsoleTextAttribute(hConsole, 2);
				cout<<"\n\t '1'   ";
				SetConsoleTextAttribute(hConsole, 7);
				cout<<"les sommets :("<<som[i-1]<<","<<som[j-1]<<") Sont ";
				SetConsoleTextAttribute(hConsole, 2);
				cout<<"adjascent\n"<<endl;
				SetConsoleTextAttribute(hConsole, 7);
			}else
				{
					SetConsoleTextAttribute(hConsole, 12);
					cout<<"\n\t '0'   ";
					SetConsoleTextAttribute(hConsole, 7);
					cout<<"les sommets :("<<som[i-1]<<","<<som[j-1]<<") Sont ";
					SetConsoleTextAttribute(hConsole, 12);
					cout<<"Non-adjascent\n"<<endl;
					SetConsoleTextAttribute(hConsole, 7);
				}
brr:
				cout << "\nTester d'autre Sommets? [";
					SetConsoleTextAttribute(hConsole, 2);cout<<"O";
					SetConsoleTextAttribute(hConsole, 7);cout<<"]ui/[";
					SetConsoleTextAttribute(hConsole, 12);cout<<"N";
					SetConsoleTextAttribute(hConsole, 7);cout<<"]on: ";	
				char o;
				cin >>o;
				cin.ignore(INT_MAX, '\n');
				switch (o) {
   				case 'O':
    			case 'o':
      				 system("CLS");	
      				 goto Menu;
	  				 break;
    			case 'n':
    			case 'N':
    				system("CLS");
       				break;
    			default:
        			cout << "\n\tError, Choix indisponible .\n"<<endl;
        			goto brr;
        			break;
    			} 
	}else
	{cout << "Erreur, Verifier le nombre de sommets Svp\n"<<endl;
        system("CLS");
		goto Menu;
	}
	
}
void Graphe::Liste_Arc(){
	
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		
	int i,j;
	char chaine[]="ABCDEF";

	for (i=0;i<noeud;i++)
	{
		cout<<endl;
		cout<<"\nLes arcs du sommet "<<chaine[i]<<" sont :";
		
		for (j=0;j<noeud;j++)
		{
			if (g[i][j]!=0)
			cout<<"  ("<<chaine[i]<<"-"<<chaine[j]<<")";
		}
		cout<<endl;
	}
	cout<<"\n";
	system("pause");
	system("CLS");
}
void Graphe::Test_Isole(){
	
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		
Menu:
	int i,j,k;
	char chaine[]="ABCDEF";
	k=0;
    cout << "\n\tIntroduire le sommet a verifier :" ;
    char resi;
    cin >> resi;
    switch (resi) {
    case 'A':
    case 'a':
    	i=0;
        break;
    case 'B':
    case 'b':
      	i=1;
        break;
    case 'C':
    case 'c':
      	i=2;
        break;
    case 'D':
    case 'd':
      	i=3;
        break;
    case 'E':
    case 'e':
      	i=4;
        break;
    case 'F':
    case 'f':
      	i=5;
        break;
    
	default:
        cout << "\nErreurr, Sommet Inexistant ."<<endl;
        goto Menu;
        break;
    	}
    	

		cout<<endl;
		k=0;
		for (j=0;j<noeud;j++)
		{
			if (g[i][j]!=0){
				k=k+1;
				
			}
				
		}
		if (k==0){
				cout<<"\t-->>>>";
				SetConsoleTextAttribute(hConsole, 2);
				cout<<" 1 ";
				SetConsoleTextAttribute(hConsole, 7);
				cout<<": Le Sommet ("<<chaine[i]<<") est isole'\n"<<endl;
		}else
		{
			cout<<"\t-->>>>";
			SetConsoleTextAttribute(hConsole, 12);
			cout<<" 0 ";
			SetConsoleTextAttribute(hConsole, 7);
			cout<<": Le Sommet: ("<<chaine[i]<<") n'est pas isole'\n"<<endl;	
		}
	err:
			cout << "\nTester d'autre Sommets? [";
					SetConsoleTextAttribute(hConsole, 2);cout<<"O";
					SetConsoleTextAttribute(hConsole, 7);cout<<"]ui/[";
					SetConsoleTextAttribute(hConsole, 12);cout<<"N";
					SetConsoleTextAttribute(hConsole, 7);cout<<"]on: ";
			
			char o;
			cin >>o;
			cin.ignore(INT_MAX, '\n');
			switch (o) {
    case 'O':
    case 'o':
    	
       goto Menu;
	   break;
    case 'n':
    case 'N':
    system("CLS");
        break;
    default:
        cout << "Error, Choix indisponible .\n"<<endl;
        goto err ;
        break;
    	} 
		
}
void Graphe::nomb_chaine(){
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
int mul[10][10];
int i,j,k,lng;

char chaine[]="ABCDEF";
char chains[]="FEDCBA-";
cout<<("\n\t*La premiere des chose le calcul de la matrice M2 (puissance M)\n\n");
SetConsoleTextAttribute(hConsole, 2);
cout<<("Le resultat : La matrice M2\n\n");
SetConsoleTextAttribute(hConsole, 7);
	
			for (j=noeud;j>=0;j--)
			{
				cout<<"\t("<<chains[j]<<")";
			}
	
	cout<<endl;

for(i = 0; i < noeud; i++)
  {
    for(j = 0; j < noeud; j++)
    {
      mul[i][j]=0;
      
      for(k = 0; k < noeud; k++)
      {
        mul[i][j] += g[i][k] * g[k][j];
      }
    }
  }
    for(i = 0; i < noeud; i++)
  {
  cout<<"\n\t("<<chaine[i]<<")";
    for(j = 0; j < noeud; j++) 
    {
      cout<<"\t "<<mul[i][j];
    }
    cout<<"\n\n";
  }
  system("pause");
  system("cls");
  //choix de sommets 
  
  char  som[]="ABCDEF";
errr:
    cout << "\nIntroduire le Sommet U :" ;
    char resi;
    cin >> resi;
    switch (resi) {
    case 'A':
    case 'a':
    	i=0;
        break;
    case 'B':
    case 'b':
      	i=1;
        break;
    case 'C':
    case 'c':
      	i=2;
        break;
    case 'D':
    case 'd':
      	i=3;
        break;
    case 'E':
    case 'e':
      	i=4;
        break;
    case 'F':
    case 'f':
      	i=5;
        break;
    
	default:
        cout << "\n\tErreurr, Sommet Inexistant ."<<endl;
        system("CLS");
        goto errr;
        break;
    	}
errb:
    cout << "\nIntroduire le Sommet V :" ;
    char resj;
    cin >> resj;
    switch (resj) {
    case 'A':
    case 'a':
    	j=0;
        break;
    case 'B':
    case 'b':
      	j=1;
        break;
    case 'C':
    case 'c':
      	j=2;
        break;
    case 'D':
    case 'd':
      	j=3;
        break;
    case 'E':
    case 'e':
      	j=4;
        break;
    case 'F':
    case 'f':
      	j=5;
        break;
    
	default:
        cout << "\n\tErreurr, Sommet Inexistant .\n"<<endl;
        system("CLS");
        goto errb;
        break;
    	}
	cout<<endl;

  cout<<"Le nombre de  chaines de longueure 2 reliant les sommets ("<<chaine[i]<<") et ("<<chaine[j]<<") est: ";
  SetConsoleTextAttribute(hConsole, 2);
  cout<<mul[i][j]<<"\n"<<endl;
  SetConsoleTextAttribute(hConsole, 7);
  		
	system("pause");
	system("cls");
	cout<<"\n";
	SetConsoleTextAttribute(hConsole, 2);
	cout<<"\t\tToutes les chaines possible:\n\n";
	SetConsoleTextAttribute(hConsole, 7);
	bool conex=true;
	for (i=0;i<noeud;i++){
		for (j=0;j<noeud;j++){
			if(mul[i][j]==0){
				conex=false;
				SetConsoleTextAttribute(hConsole, 12);
				cout<<"\t("<<chaine[i]<<","<<chaine[j]<<") = "<<mul[i][j];
				
			
			}else{
	
		SetConsoleTextAttribute(hConsole, 7);
					cout<<"\t("<<chaine[i]<<","<<chaine[j]<<") = "<<mul[i][j];
	}
		}
	
	
		cout<<"\n\n";
	}
			if (conex){
			
			cout<<"\n\tLe Graphe est";SetConsoleTextAttribute(hConsole, 2);
			cout<<" CONEXE: ";
			SetConsoleTextAttribute(hConsole, 7);
			cout<<"quelque soit deux sommet quelconque,\n\tils sont relier au moin par une chaine\n"<<endl;
	}else{
		
			cout<<"\nle graphe n'est ";
			SetConsoleTextAttribute(hConsole, 12);
			cout<<"PAS CONEXE\n"<<endl;
			SetConsoleTextAttribute(hConsole, 7);
	}

			
system("pause");
	system("CLS");	

}
void Graphe::Nbr_Comp_con(){
int i,j,k,nb,t[10];
char chaine[]="ABCDEF";
 for(i=1;i<=noeud;i++)
	  t[i]=0;

///le marcage dans le tableaux
k=0;
for(i=1;i<=noeud;i++)
	  {
			for( j=1;j<=noeud;j++)
			{
			if (t[i]==0)
				{
				 k++;
				 t[i]=k;
				 }
			if(g[i][j]==1){
			
			 if (g[j][i]==1)
			 	t[j]=t[i];
			}
	  }
	  nb=t[1];
 for(i=1;i<=noeud;i++)
  {
  if(t[i]>nb)
  	nb=t[i];
  }
  system("cls");
  cout<<"\n\nle nombre de composnetes connexe est : "<<nb;
  cout<<"\n\n";
  for(int i=1;i<=nb;i++)
		{
			cout<<"La composnete connexe CC={";
			  for(int j=0;j<=noeud;j++)
			 {
			 if(t[j]==i)
			 cout<<chaine[j-1];

			 }
			 cout<<"}\n\n";
  }
 system("pause");
}
}
void Graphe::Stable(){
	
}
void Graphe::Clique(){
char chaine[]="ABCDEF";
int tab[10];
char res[]="      ";
int i,j,k,n;


	for(i=0;i<noeud;i++){
		k=0;
		for (j=0;j<noeud;j++)
		{
			if (g[i][j]!=0){
				k++;
			}
			
		}
		
			tab[i]=k;
	
		 if(k>2){
		 	res[i]=chaine[i];
		 }	
		}
	n=0;
	for (i=0;i<noeud;i++){
		if (res[i]!=' ')
		n++;
	}
		
		cout<<"\n\n\tLa clique se compose des sommets suivant :{";
		for (i=0;i<n;i++){
			
				cout<<" "<<res[i]<<" ";
			}
		cout<<"}\n\n";
		
system("pause");
	}
	




