import java.util.Scanner;

public class Impaire {
    public static void main(String[] variables) {
        Scanner key = new Scanner(System.in);
 
        int x,y;

        System.out.print("Veuillez Saisir l'intervale , entre  : ");

        x = key.nextInt();


	System.out.print("et  : ");

	y =key.nextInt();

	if (y<=x){

			System.out.println("Intervale erronée");

	 }else{

			System.out.println("Liste des impaires entre "+x+" et "+y+" sont:");
			
				for (int i=x+1;i<y;i++){
		
        				switch (i % 2) {
        	
       						case 0:
          						break;
        					case 1:
            						System.out.println("|   "+i+"    |");
							break;
        				}
				}
		}
        key.close();
    	}
}