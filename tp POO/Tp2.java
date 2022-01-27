

import java.util.Arrays;
import java.util.Scanner;


/**
 *
 * @author Houssam
 */
public class Tp2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int x;
        Scanner key = new Scanner(System.in);
        boolean bool=true;
        principale:
        
        while(bool){
        
        System.out.println("Veuillez Choisir ce que vous voulez faire:");
        System.out.println("1- Permutation ");
        System.out.println("2- Chercher dans un Tableau ");
        System.out.println("3- Quitter ");
         
            x = key.nextInt();
            switch (x){
                case 1:
                    permutation();
                    clear();
                    continue principale;
                     // break;
                    
                case 2:
                    Va_chercher();
                    clear();
                    continue  principale;
                   
                case 3:
                    bool=false;
                    break ;
                default:
                   System.out.println("             Erreur: Saisie Incorrect, recommencer");
                   clear();
                   continue  principale;
              } 
        }     
        key.close(); 
        }
// les methodes 
    private static void permutation() {
       String[] chaine = new String[]{"a", "b", "c", "2", "e", "f", "g", "nn", "i", "j", "k"};
	System.out.println("Les elements du tableau " + Arrays.toString(chaine));
	int longueure =chaine.length;
        String x;
        x = chaine[longueure-1];
        chaine[longueure-1]=chaine[0];
        chaine[0]=x;
        System.out.println("Mon Tableau Permuter :"+Arrays.toString(chaine));
    }

    private static void Va_chercher() {
        int valrech;
        System.out.println("Quel Valeurs vous chercher? "); 
        Scanner key = new Scanner(System.in);
        
        valrech=key.nextInt(); // Leture valeur cherché

  int T[]={1, 5, 2, 2, 14, 3, 18, 22, 40, 88, 73, 27};// init tableau
  
  int position = trouve(T, valrech);
  if(position!=0)
     System.out.println(valrech+" se trouve dans la position "+position);
  
  };

 static int trouve(int T[], int val){ //chercher dans le tableau
  for(int i = 0 ; i<T.length;i++){
   if(val==T[i])
      return i;//retourner la position dans le tableau
  }
  System.out.println("La valeur recherchée n'existe pas");
  return 0;
    }

    private static void clear() {
       try{
         final String os=System.getProperty("os.name");
         if(os.contains("Windows")){
             Runtime.getRuntime().exec("cls");
         }
        }catch(final Exception e){
            e.printStackTrace();
        }
    }
    }
   
   
    

