
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;

/**
 *
 * @author Adel
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        
        String[] precalc = new String[1001];
        
        BigInteger a = new BigInteger("1");
        
        precalc[0] = precalc[1] = "1";
        
        for(int i = 2; i < 1001; i++){
            a = a.multiply(new BigInteger(String.valueOf(i)));
            precalc[i] = a.toString();
        }
        
        
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        
        String line;
        
        while( (line = bf.readLine()) != null ){
            System.out.println(line + "!");
            System.out.println(precalc[Integer.parseInt(line)]);
        }
        
    }
}
