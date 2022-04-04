package codejam._2022;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int T = sc.nextInt(), cnt = 0;
        while (cnt++ < T) {
            System.out.print("Case #" + cnt + ": ");
            int[][] printers = new int[3][4];
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 4; j++) {
                    printers[i][j] = sc.nextInt();
                }
            }
            int[] minInks = new int[4];
            Arrays.fill(minInks, Integer.MAX_VALUE);
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                    minInks[i] =  Math.min(minInks[i], printers[j][i]);
                }
            }
            int sum = 0;
            for (int i = 0; i < 4; i++) {
                sum += minInks[i];
            }
            if (sum < 1e6) {
                System.out.print("IMPOSSIBLE");
            } else {
                int extra = sum - (int) 1e6;
                for (int i = 0; i < 4; i++) {
                    int subExtra = Math.min(minInks[i], extra);
                    extra -= subExtra;
                    minInks[i] -= subExtra;
                    System.out.print(minInks[i] + " ");
                }
            }

            System.out.println();
        }
    }
}
