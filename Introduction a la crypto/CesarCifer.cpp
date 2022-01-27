#include <iostream>
#include <string>
#include <climits>
#include <cstdlib>
#include <windows.h>
#include <WinCon.h>
#include <regex>
#include<locale>
using std::cout;
using std::endl;
using namespace std;


inline int modulo (int m, int n)
{
    return m >= 0 ? m % n : ( n - abs ( m % n ) ) % n;
}
string getNumberLocation(string keyword, string kywrdNumListStr) {

    int kywrdNumList[keyword.length()];
    //cout << taille de (ky wrd Num List);
    for (int i = 0; i < sizeof(kywrdNumList)/sizeof(kywrdNumList[0]); i++){
        // using ASCII code '0' is 48, '1' 49 and so on until '9' as 57
        kywrdNumList[i] = kywrdNumListStr[i] - 48;
//        cout << kywrdNumList[i] << endl;
    }

    string numLoc = "";
    for (int i = 1; i < keyword.length() + 1; i++) {
        for (int j = 0; j < keyword.length(); j++) {
            if (kywrdNumList[j] == i){
                numLoc += to_string(j);
            }
        }
    }
    return numLoc;
} // obtenir la fonction de localisation du numéro


string keywordNumAssign(string keyword){
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int kywrdNumList[keyword.length()];

    int init = 0;
    for (int i = 0; i < alpha.length(); i ++){
        for (int j = 0; j < keyword.length(); j++) {
            if (alpha[i] == keyword[j]){
                init++;
                kywrdNumList[j] = init;
//                cout << kywrdNumList[j];
            }
        } // inner for
    } // for

    string str = "";
    for (int i = 0; i < sizeof(kywrdNumList)/sizeof(kywrdNumList[0]); i++){
//        cout << kywrdNumList[i] << " ";
        str += to_string(kywrdNumList[i]);
    }
//    string str = to_string(kywrdNumList);
//    cout << str;
    return str;
}

void TranspositionCryptage(){
    string msg;
    cout << "Enter Plain Text: ";
    getline(cin, msg);

    string keyword;
    cout << "Enter Keyword: ";
    getline(cin, keyword);

    // texte brut en majuscule

    for (int i = 0; i < msg.length(); i++){
        msg[i] = toupper(msg[i]);
    }

    // remplacer les espaces en texte brut

    msg = regex_replace(msg,regex("\\s+"), "");

    // mot-clé en majuscule

    for (int i = 0; i < keyword.length(); i++){
        keyword[i] = toupper(keyword[i]);
    }

    for (int i = 0; i < keyword.length(); i++){
        cout << keyword[i] << " ";
    }
    cout << endl;

    // attribuer des numéros aux mots-clés

    string kywrdNumListStr = keywordNumAssign(keyword);

    int kywrdNumList[keyword.length()];
    //cout << taille de(kywrdNumList);
    for (int i = 0; i < sizeof(kywrdNumList)/sizeof(kywrdNumList[0]); i++){
        // en utilisant le code ASCII '0' est 48, '1' 49 et ainsi de suite jusqu'à '9' comme 57

        kywrdNumList[i] = kywrdNumListStr[i] - 48;
//        cout << kywrdNumList[i] << endl;
    }
    for (int i: kywrdNumList){
        cout << i << " ";
    }

    // au cas où les caractères ne s'adapteraient pas parfaitement à toute la grille.
    int extraLetters = msg.length() % keyword.length();
//    cout << endl << lettres supplémentaires << endl;
    int dummyCharacters = keyword.length() - extraLetters;
//    cout << endl << personnages factices << endl;

    if (extraLetters != 0){
        for (int i = 0; i < dummyCharacters; i++) {
            msg += ".";
        }
    }

    int numOfRows = msg.length() / keyword.length();
    // Conversion d'un message en grille

    char arr[numOfRows][keyword.length()];

    int z = 0;
    for (int i = 0; i < numOfRows; i++) {
        for (int j = 0; j < keyword.length(); j++) {
            arr[i][j] = msg[z];
            z++;
        }
    }

    cout << endl;
    for (int i = 0; i < numOfRows; i++) {
        for (int j = 0; j < keyword.length(); j++) {
            cout << arr[i][j] << " ";
        } // boucle intérieure pour

        cout << endl;
    } // for loop

    // génération de texte chiffré

    string cipherText = "";
    // getting locations of numbers
    string numLoc = getNumberLocation(keyword, kywrdNumListStr);
    cout << numLoc << endl;
    cout << endl;

    for (int i = 0, k = 0; i < numOfRows; i++, k++) {
        int d;
        if (k == keyword.length()){
            break;
        } else {
//            d = Character.getNumericValue(numLoc.charAt(k));
            d = numLoc[k];
            d = d- '0';
        }
        for (int j = 0; j < numOfRows; j++) {
            cipherText += arr[j][d];
        }
    }

    cout << cipherText;

}

void TranspositionDecryptage(){
    string msg;
    cout << "Enter Cipher Text: ";
    getline(cin, msg);

    string keyword;
    cout << "Enter Keyword: ";
    getline(cin, keyword);

    // mot-clé en majuscule

    for (int i = 0; i < keyword.length(); i++){
        keyword[i] = toupper(keyword[i]);
    }

    // attribuer des numéros aux mots-clés

    string kywrdNumListStr = keywordNumAssign(keyword);
    int kywrdNumList[keyword.length()];
    //cout << sizeof(kywrdNumList);
    for (int i = 0; i < sizeof(kywrdNumList)/sizeof(kywrdNumList[0]); i++){
        // en utilisant le code ASCII '0' est 48, '1' 49 et ainsi de suite jusqu'à '9' comme 57

        kywrdNumList[i] = kywrdNumListStr[i] - 48;
//        cout << kywrdNumList[i] << endl;
    }

    int numOfRows = msg.length() / keyword.length();
    // Conversion d'un message en grille

    char arr[numOfRows][keyword.length()];

    // obtenir l'emplacement des nombres

    string numLoc = getNumberLocation(keyword, kywrdNumListStr);

    for (int i = 0, k = 0; i < msg.length(); i++, k++) {
        int d;
        if (k == keyword.length()){
            k = 0;
        } else {
            d = numLoc[k];
            d = d- '0';
        }
        for (int j = 0; j < numOfRows; j++, i++) {
            arr[j][d] = msg[i];
//            cout << arr[j][d];
        }
        i--;

    }

    cout << endl;

    string plainText = "";

    for (int i = 0; i < numOfRows; i++) {
        for (int j = 0; j < keyword.length(); j++) {
            plainText += arr[i][j];

        } // boucle intérieure pour

    } // for loop

    cout << "Plain Text: " << plainText << endl;


}
void transposition(boolean crypt){
	if (crypt){
		TranspositionCryptage();
	}else{
		TranspositionDecryptage();
	}
}
void cesarCryptage(boolean crypt){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(hConsole, 7);
    string message;
    const string alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; 
   
    cout << "\nVotre message a " << (crypt?"Crypter":"Décrypter" ) << ": ";
    SetConsoleTextAttribute(hConsole, 2);
    getline(cin, message);
    if (message.empty()) {
        cout << "Message Vide, réessayer";
        system("cls");
        //goto Menu;
    }
    string key;
	keys:
		SetConsoleTextAttribute(hConsole, 7);
	cout << "\nLa Clé de " << (crypt?"Cryptage":"Décryptage")<< " : ";
	SetConsoleTextAttribute(hConsole, 2);
    getline(cin, key);
    SetConsoleTextAttribute(hConsole, 7);
    if (key.empty()) {
    	SetConsoleTextAttribute(hConsole, 12);
        cout << "Clé Vide, réessayer";
     	system("cls");
     	SetConsoleTextAttribute(hConsole, 7);
        goto keys;
		}
    string::iterator itc = key.begin();
    for (string::iterator itm = message.begin(); itm < message.end(); ++itm) {
        if (isupper(*itm) || islower(*itm) || isdigit(*itm) ) { //|| issign(*itm)
           *itm = alphabet[modulo(alphabet.find(*itm) + (crypt?*itc:-*itc), 62)];
        }
        if (++itc == key.end()) {
            itc = key.begin();
        }    
    }
    cout <<"\n\t\t\t\tLe Message "<<(crypt?"Crypté":"Décrypté")<< " est :" ;SetConsoleTextAttribute(hConsole, 2);cout<< message << endl;
    SetConsoleTextAttribute(hConsole, 7);
       }


int main()
{
	setlocale(LC_CTYPE, "fra");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 2);
	cout<<"\t\t***************************"<<endl;
	cout<<"\t\t*   Chiffrement de César  *"<<endl;
	cout<<"\t\t*   Par Houssam HAMOUDA   *"<<endl;
	cout<<"\t\t***************************"<<endl;
	SetConsoleTextAttribute(hConsole, 7);
	
    
    bool crypt;
    SetConsoleTextAttribute(hConsole, 7);
    cout << "\n\t\t\t[C]rypter ou [D]écrypter  :";
    SetConsoleTextAttribute(hConsole, 2);
    char c;
    cin >> c;
    //cin.ignore(INT_MAX, '\n'); 	
    switch (c) {
    case 'C':
    case 'c':
    	cout << "\n\t\t\t[C]esar ou [T]ransposition  :";
    	char f;
    	cin >> f;
    	switch (f) {
    			case 'C':
    			case 'c':
        			crypt = true;
        			cesarCryptage(crypt);
        			break;
        		case 'T':
    			case 't':
    				crypt = true;
    				txransposition(crypt);
    				break;
    			defaut:
    				SetConsoleTextAttribute(hConsole, 12);
    				cout << "Erreur, saisie incorrect"<<endl;
         			system("pause");
        			system("cls");
        			//goto Menu;
        			break;
    case 'D':
    case 'd':
    		cout << "\n\t\t\t[C]esar ou [T]ransposition  :";
    		char t;
    		cin >> t;
    		switch (t) {
    			case 'C':
    			case 'c':
        			crypt = false;
        			cesarCryptage(crypt);
        			break;
        		case 'T':
    			case 't':
    				TranspositionDecryptage();
    				break;
    			default:
    				SetConsoleTextAttribute(hConsole, 12);
    				cout << "Erreur, saisie incorrect"<<endl;
         			system("pause");
        			system("cls");
        			//goto Menu;
        			break;
             }
    default:
    	SetConsoleTextAttribute(hConsole, 12);
         cout << "Erreur, saisie incorrect"<<endl;
         system("pause");
        system("cls");
        //goto Menu;
        break;
         
    }
    

}
}

