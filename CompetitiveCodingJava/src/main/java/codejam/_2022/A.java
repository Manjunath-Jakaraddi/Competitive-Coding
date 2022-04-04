package codejam._2022;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class A {

    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int T = sc.nextInt(), cnt = 0;
        while (cnt++ < T) {
            System.out.println("Case #" + cnt + ":");
            int R = sc.nextInt(), C = sc.nextInt();
            R = R * 2 + 1;
            C = C * 2 + 1;
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    if (i == 0 && j == 0) {
                        System.out.print(".");
                    } else if (i == 1 && j == 0) {
                        System.out.print(".");
                    }else if (i == 0 && j == 1) {
                        System.out.print(".");
                    } else if (i%2 == 0) {
                        if (j %2 == 0) {
                            System.out.print("+");
                        } else {
                            System.out.print("-");
                        }
                    } else {
                        if (j%2 == 0) {
                            System.out.print("|");
                        } else {
                            System.out.print(".");
                        }
                    }
                }
                System.out.println();
            }
        }
    }
}
