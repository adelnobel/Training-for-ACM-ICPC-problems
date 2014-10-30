/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication5;


import java.math.BigInteger;
import java.util.ArrayList;
import java.util.GregorianCalendar;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author Adel
 */
public class JavaApplication5 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        while(sc.hasNextInt()){
            List< Integer > v = new ArrayList<>();
            int x;
            while( (x = sc.nextInt()) != -999999){
                v.add(x);
            };
            
            BigInteger best = new BigInteger("-100000000000");
            for(int i = 0; i < v.size(); i++){
                BigInteger cur = BigInteger.ONE;
                for(int j = i; j < v.size(); j++){
                    cur = cur.multiply(new BigInteger(String.valueOf(v.get(j))));
                    if(best.compareTo(cur) == -1){
                        best = cur;
                    }
                }
            }
            
            System.out.println(best);
            
        }
        
        
        
    }
}
