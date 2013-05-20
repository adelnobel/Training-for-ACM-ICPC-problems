
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author Adel
 */
public class JavaApplication5 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args){
        // TODO code application logic here
        
        
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        
        String s;
        try{
            s = bf.readLine();
            while(s != null){
                BigInteger b, p, m;

                b = new BigInteger(s);

                p = new BigInteger(bf.readLine());
                m = new BigInteger(bf.readLine());

                System.out.println( b.modPow(p, m).toString() );
                s = bf.readLine();
                s = bf.readLine();

            }
        }
        catch(Exception ex){};
    }
}