import java.util.Scanner;
public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter first string");
        String str=sc.next();
        String test=sc.next();
        int index=-1;
        for(int i=0;i<=str.length()-test.length();i++){
            boolean match=true;
            for(int j=0;j<test.length();j++){
                if(str.charAt(i+j)!=test.charAt(j)){
                    match=false;
                    break;
                }
            }
            if(match){
                index=i;
                break;
            }


        }
        if(index!=-1){
            System.out.println("found at index "+index);
        }
        else{
            System.out.println("not found");

        }
    }
        

}