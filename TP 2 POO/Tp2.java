import java.util.Arrays;
import java.util.Scanner;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Tp2 {

   
    public static void main(String[] args)throws IOException, InterruptedException {
        int x;
        try (Scanner key = new Scanner(System.in)) {
            boolean bool=true;
		clear();  
		System.out.println("  ");
		System.out.println("       ------------------------------------------------------------- ");
		System.out.println("      | Tp POO - M1 CS - Permutation et Recherche dans un tableau   |");
		System.out.println("      |                                                             |");
		System.out.println("      | Par :  Houssam HAMOUDA                                      |"); 
		System.out.println("       ------------------------------------------------------------- ");

            principale:
            while(bool){
                
                try {
                    System.out.println("");
                    System.out.println("  Menu Principale:");
                    System.out.println("");
                    System.out.println("              1. Permutation du premier element avec le derniers ");
                    System.out.println("              2. Chercher dans un Tableau  et donner la position si existe");
                    System.out.println("              3. Quitter ");
                    System.out.println("              			 ");
		    System.out.print("  Votre Choix : ");
                   
                    x = key.nextInt();
                    switch (x){
                        case 1:
                            permutation();
			    clear();
                            continue ;
                                                        
                        case 2:
                            Va_chercher();
			    clear();
                            continue;
                        case 3:
                            bool=false;
                            break ;
                        default:
	                    
                            System.out.println("             Erreur: Saisie Incorrect, recommencer");
			    pause();
                            {
                                try {
                                    clear();
                                } catch (IOException | InterruptedException ex) {
                                    Logger.getLogger(Tp2.class.getName()).log(Level.SEVERE, null, ex);
                                }
                            }
                    }
                } catch (IOException | InterruptedException ex) {
                    Logger.getLogger(Tp2.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        } 
        }


// les methodes 

private static void clear() throws IOException, InterruptedException {
     
       new ProcessBuilder("cmd","/c","cls").inheritIO().start().waitFor();
    }


private static void pause() throws IOException, InterruptedException {
     new ProcessBuilder("cmd","/c","pause").inheritIO().start().waitFor();
    
    }

 
// Permutation entre le premier et le dernier élément du tableau 
   
    private static void permutation()throws IOException, InterruptedException {
       String[] chaine = new String[]{"HaMouDa", "etudiant", "nabil", "said", "5", "6", "7", "8", "9", "10", "houssam"};
        System.out.println("");
	System.out.println("       Les elements du tableau " + Arrays.toString(chaine));
        System.out.println("");
        pause();
	int longueure =chaine.length;
        String x;
        x = chaine[longueure-1];
        chaine[longueure-1]=chaine[0];
        chaine[0]=x;
        System.out.println("              			 ");
        System.out.println("       Mon Tableau Permuter :"+Arrays.toString(chaine));
        System.out.println("  ");
	pause();
    }

//Rechercher dans un tableau d'entier une valeur si elle existe (donner sa position) ou pas 

    private static void Va_chercher() throws IOException, InterruptedException{
        int valrech;
	String clef;
  	int T[]={1, 5, 2, 2, 14, 3, 18, 22, 40, 88, 73, 27};// init tableau

        System.out.println("  ");
        System.out.println("       Les elements du tableau " + Arrays.toString(T));
        System.out.println("  ");
        System.out.print("       Quel Valeurs vous chercher? : "); 
        Scanner key = new Scanner(System.in);
        
        valrech=key.nextInt(); // Lecture valeur cherché

  int position = trouve(T, valrech);
  if(position!=-1){
     System.out.println("  ");
     System.out.println("       "+valrech+" se trouve dans la position "+position);
     System.out.println("  ");
  }
System.out.print("Rechercher de nouveau? O/N : ");
   //Scanner y = new Scanner(System.in);
   clef= new Scanner(System.in).next();
   switch (clef.charAt(0)){
                        case 'o':
			case 'O':
                            clear();
                            Va_chercher() ;
                        case 'n':
			case 'N':
			   break;
 			 }

  };

 static int trouve(int T[], int val){ //chercher dans le tableau
  for(int i = 0 ; i<T.length;i++){
   if(val==T[i])
      return i+1;//retourner la position dans le tableau
  }
  System.out.println("   ");
  System.out.println("       La valeur n'existe pas");
  System.out.println("   ");
   return -1;

    }

    
   
}   
    

