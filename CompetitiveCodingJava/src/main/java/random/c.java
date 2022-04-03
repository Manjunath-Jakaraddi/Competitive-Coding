import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class c {
    public static void main(String[] args) {
        try(Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)))) {
            int testCases = sc.nextInt();
            while(testCases-- > 0) {
                String str = sc.next();
                int maxDiff = -1;
                int prev=-1, curr=0;
                boolean allR = true;
                while(curr < str.length()) {
                    if(str.charAt(curr) != 'R') {
                        allR = false;
                    }
                    if(str.charAt(curr) == 'R') {
                        maxDiff = Math.max(maxDiff, curr-prev);
                        prev=curr;
                    }
                    curr++;
                }
                maxDiff = Math.max(maxDiff, str.length() - prev);
                if(allR) {
                    System.out.println(1);
                } else if (maxDiff == -1) {
                    System.out.println(str.length() + 1);
                } else {
                    System.out.println(maxDiff);
                }
            }
        }
    }
}
