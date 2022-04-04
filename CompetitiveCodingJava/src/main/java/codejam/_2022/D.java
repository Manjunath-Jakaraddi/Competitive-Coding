package codejam._2022;

import com.sun.org.apache.xpath.internal.operations.Bool;
import jdk.internal.util.xml.impl.Pair;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class D {
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int T = sc.nextInt(), t = 0;
        while(t++ < T) {
            System.out.print("Case #" + t + ": ");
            int ans = Integer.MIN_VALUE;
            int N = sc.nextInt();
            int[] fun = new int[N], dir = new int[N];
            List<Integer> startingPoints = new ArrayList<>();
            for (int i = 0; i < N; i++) {
                fun[i] = sc.nextInt();
            }
            Map<Integer, Boolean> hmap = new HashMap<>();
            for (int i = 0; i < N; i++) {
                dir[i] = sc.nextInt();
                hmap.putIfAbsent(dir[i], true);
            }
            for (int i = 1; i <= N; i++) {
                if (!hmap.containsKey(i)) {
                    startingPoints.add(i);
                }
            }
            List<List<Pair>> adj = new ArrayList<>();
            System.out.println(ans);
        }
    }
}
