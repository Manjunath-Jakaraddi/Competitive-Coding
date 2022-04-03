import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class a {
   public static void main(String[] args) {
        try(Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)))) {
            int testCases = sc.nextInt();
            for(int t=0; t<testCases; t++) {
                int n = sc.nextInt();
                int min = Integer.MAX_VALUE;
                int[] nums = new int[n];
                for(int i=0; i<n; i++) {
                    nums[i] = sc.nextInt();
                    min = Math.min(min, nums[i]);
                }
                boolean possible = true;
                for(int i=0; i<n; i++) {
                    if((nums[i] - min)%2 != 0) {
                        possible=false;
                        break;
                    }
                }
                if(!possible) {
                    System.out.println("NO");
                } else {
                    System.out.println("YES");
                }
            }
        }

   }
}
