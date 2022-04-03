import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class b {
    public static void main(String[] args) {
       try(Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)))) {
           int testCases = sc.nextInt();
           while(testCases-- > 0) {
               int n = sc.nextInt();
               int[] arr = new int[n];
               int[] cnt = new int[5005];
               int[] ind = new int[5005];
               int maxNumber = -1;
               for(int i=0; i<n; i++) {
                   arr[i] = sc.nextInt();
                   cnt[arr[i]] += 1;
                   ind[arr[i]] = i;
                   maxNumber = Math.max(maxNumber, cnt[arr[i]]);
               }
               if (maxNumber > 2) {
                   System.out.println("YES");
               } else if(maxNumber == 2) {
                   boolean possible = false;
                   for(int i=0; i<5005; i++) {
                       if(cnt[i] == 2) {
                           int idx = ind[i];
                           if(idx > 0 && arr[idx-1] != i && idx<n-1 && arr[idx+1] != i) {
                               possible = true;
                               break;
                           }
                           if(idx == 0 && arr[idx+1] != i) {
                               possible=true;
                               break;
                           }
                           if(idx == n-1 && arr[idx-1] != i) {
                               possible = true;
                               break;
                           }
                       }
                   }
                   System.out.println(possible ? "YES" : "NO");
               } else {
                   System.out.println("NO");
               }
           }
       }
    }
}
