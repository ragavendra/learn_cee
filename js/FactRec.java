
/*
Online Java - IDE, Code Editor, Compiler

Online Java is a quick and easy tool that helps you to build, compile, test your programs online.
*/

public class FactRec
{
    public static void main(String[] args) {
        System.out.println("Welcome to Online IDE!! Happy Coding :) " + factorial(6, 1, 1));
        
        
    }
    
    public static int factorial(int no, int i, int res){
        
        if(i > no)
            return res;
            
        // res = res * (no - 1); 
        return factorial(no, i + 1, res * i);
        //(5, 2, 30)
        
    }
}
