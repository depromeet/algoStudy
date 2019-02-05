import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for(int n = sc.nextInt(); n>0; n-- ){
            String s = sc.next();
            int a = 0;
            int b = s.length()-1;

            int result = -1;
            if(a == b){
                System.out.println(result);
            } else{
                while(a != b){
                    if (a == s.length()-1 || b == 0){
                        break;
                    }
                    if (s.charAt(a) == s.charAt(b)){
                        a +=1;
                        b-=1;
                    }else{
                        if (s.charAt(b-1) == s.charAt(a) && s.charAt(a+1) == s.charAt(b-2)){
                            result = b;
                            break;
                        }else{
                            result = a;
                            break;
                        }
                    }
                }
                System.out.println(result);

            }
        }
    }
}
