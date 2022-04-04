package codejam._2022;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class C {
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int T = sc.nextInt(), t = 0;
        while (t++ < T) {
            System.out.print("Case #" + t + ": ");
            int res = 1;
            int N = sc.nextInt();
            int[] arr = new int[N];
            for (int i = 0; i < N; i++) {
                arr[i] = sc.nextInt();
            }
            Arrays.sort(arr);
            int currNum = arr[N-1] - 1;
            for (int i = N-2; i >= 0; i--) {
                if (arr[i] != arr[i+1]) {
                    res++;
                    if (currNum > arr[i]) currNum = arr[i] - 1;
                    else currNum--;
                } else if (arr[i] == arr[i+1]) {
                    currNum--;
                    res++;
                }
                if (currNum <= 0) {
                    break;
                }
            }
            System.out.println(res);
        }
    }
}
