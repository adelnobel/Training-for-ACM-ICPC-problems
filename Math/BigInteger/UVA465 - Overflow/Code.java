/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication5;


import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;


/**
 *
 * @author Adel
 */
public class JavaApplication5 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stTok;
        String s;
        
        BigInteger first;
        BigInteger second;
        BigInteger res = null;
        
        BigInteger max = new BigInteger("2147483647");
        
        String operation;
        
        while( (s = bf.readLine()) != null ){
            System.out.print(s + "\n");
            s = s.replace(" ", "");
            stTok = new StringTokenizer(s, "+-*/", true);
            first = new BigInteger(stTok.nextToken());
            if(first.compareTo(max) > 0){
                System.out.print("first number too big\n");
            }
            operation = stTok.nextToken();
            second = new BigInteger(stTok.nextToken());
            if(second.compareTo(max) > 0){
                System.out.print("second number too big\n");
            }
            if(operation.contentEquals("*")){
                    res = first.multiply(second);
                }
            else if(operation.contentEquals("+")){
                    res = first.add(second);
                }
            else if(operation.contentEquals("*")){
                    res = first.subtract(second);
                }
            else if(operation.contentEquals("/")){
                    res = first.divide(second);
                }
            
            if(res.compareTo(max) > 0){
                System.out.print("result too big\n");
            }
            
        }
        
        
    }
}
