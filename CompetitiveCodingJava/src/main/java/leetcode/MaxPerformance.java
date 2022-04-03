package leetcode;

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class MaxPerformance {
    static class Pair {
        int spd;
        int eff;
        Pair(int s, int e) {
            this.spd = s;
            this.eff = e;
        }
    }

    public static void main(String[] args) {
        int n = 6;
        int k=2;
        int[] speed = {2,10,3,1,5,8};
        int[] efficiency = {5,4,3,9,7,2};
        Pair[] prs = new Pair[n];
        for(int i=0; i<n; i++) {
            prs[i] = new Pair(speed[i], efficiency[i]);
        }
        Arrays.sort(prs, (pr1, pr2) -> pr2.eff - pr1.eff);
        TreeSet<Integer> set = new TreeSet<>();
        int res = Integer.MIN_VALUE;
        int sum = 0;
        for(int i=1; i<n; i++) {
            if(set.size() == k) {
                int lowestSpeed = set.pollFirst();
                sum-=lowestSpeed;
            }
            res = Math.max(res, (sum+prs[i].spd) * prs[i].eff);
            if(set.size() < k) {
                set.add(prs[i].spd);
                sum+=prs[i].spd;
            }
        }
        System.out.println(res);
    }
}