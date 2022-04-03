import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

public class d {
    public static void main(String[] args) {
        try(Scanner scanner = new Scanner(new BufferedReader(new InputStreamReader(System.in)))) {
            int n = scanner.nextInt();
            int[] arrt = new int[n];
            int[] arrs = new int[n];
            int[] diff = new int[n];
            for(int i=0; i<n; i++) {
                arrt[i] = scanner.nextInt();
            }
            for(int i=0; i<n; i++) {
                arrs[i] = scanner.nextInt();
                diff[i] = arrt[i] - arrs[i];
            }
            sort(diff);
            long res = 0;
            int l=0,r=n-1;
            while(l<r) {
                if (diff[l] + diff[r] > 0) {
                    r--;
                } else {
                    l++;
                }
                res+= n - (r + 1);
            }
            System.out.println(res);
        }
    }

    static void sort(int[] arr) {
        PriorityQueue<Integer> queue = new PriorityQueue<>(arr.length);
        for(int i: arr) {
            queue.add(i);
        }
        for(int i=0; i<arr.length; i++) {
            arr[i] = queue.remove();
        }
    }
}
