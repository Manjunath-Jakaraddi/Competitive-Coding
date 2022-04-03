package leetcode.weekly;


import java.io.*;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.List;

import static java.util.Collections.swap;

public class Problem278 {
    public static PrintWriter out;

    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        new Problem278().run(sc, out);
        out.close();
    }

    int[] par = new int[20004];
    int[] rank = new int[20004];
    int[] setSize = new int[20004];
    Map<Integer, Integer> hmap = new HashMap<>();
    int n, numSets;
    int maxSetSize = 1;

    int findP(int i) {
        return (par[i] == i) ? i : (par[i] = findP(par[i]));
    }

    boolean isSameSet(int i, int j) {
        return findP(i) == findP(j);
    }

    void union(int i, int j) {
        if(isSameSet(i, j)) return;
        int x = findP(i), y = findP(j);
        if(rank[x] > rank[y]) {
            int tmp = y;
            y=x; x=tmp;
        }
        par[x] = y;
        if(rank[x] == rank[y]) ++rank[y];
        setSize[y] += setSize[x];
        maxSetSize = Math.max(maxSetSize, setSize[y]);
        --numSets;
    }

    int getMask(String word) {
        int mask = 0;
        for(int i=0; i<word.length(); i++) {
            mask |= (1 << (word.charAt(i) - 'a'));
        }
        return mask;
    }

    public int[] groupStrings(String[] words) {
        n = words.length;
        numSets = words.length;
        // init par, rank, setsize
        for(int i=0; i<n; i++) par[i]=i;
        Arrays.fill(rank, 0);
        Arrays.fill(setSize, 1);

        int mask = 0;
        for(int i=0; i<n; i++) {
            mask = getMask(words[i]);
            if(hmap.containsKey(mask)) {
                union(i, hmap.get(mask));
            }
            hmap.putIfAbsent(mask, i);
        }

        for(int i=0; i<n; i++) {
            runOperation(words[i], i);
        }
        return new int[] {numSets, maxSetSize};
    }

    private void runOperation(String word, int ind) {
        // adding a letter
        int mask = getMask(word);
        for(int i=0; i<26; i++) {
            if((mask & (1<<i)) == 0 && hmap.containsKey(mask | (1<<i))) {
                union(ind, hmap.get((mask | (1<<i))));
            }
        }
        // deleting a letter -> and then adding a letter
        for(int i=0; i<26; i++) {
            if((mask | (1<<i)) != 0) {
                int turnedOffMask = (mask & ~(1 << i-1));
                if(hmap.containsKey(turnedOffMask)) {
                    union(ind, hmap.get(turnedOffMask));
                }
                // adding a letter
                for(int j=0; j<26; j++) {
                    if((turnedOffMask & (1<<j)) == 0 && hmap.containsKey(turnedOffMask | (1<<j))) {
                        union(ind, hmap.get((turnedOffMask | (1<<j))));
                    }
                }
            }
        }
    }

    public void run(MyScanner sc, PrintWriter out) {
        int n = sc.nextInt();
        String[] words = new String[n];
        for(int i=0; i<n; i++) {
            words[i] = sc.nextLine();
        }
        int[] res = groupStrings(words);
        System.out.println(res[0] + " " + res[1]);
    }

    class Pair<T> extends Pair2<T, T> {
        public Pair(T x, T y) {
            super(x, y);
        }
    }

    class Pair2<T,U> {
        T x;
        U y;

        public Pair2(T x, U y) {
            this.x = x;
            this.y = y;
        }
    }

    class Triple<T> {
        T x;
        T y;
        T z;

        public Triple(T x, T y, T z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }
    }

    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while(st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException ex) {
                    ex.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        List<Integer> nextIntList(int n) {
            List<Integer> arr = new ArrayList<>();
            for(int i=0; i<n; i++) {
                arr.add(nextInt());
            }
            return arr;
        }

        int[] nextIntArray(int n) {
            int[] arr = new int[n];
            for(int i=0; i<n; i++)
                arr[i]=nextInt();
            return arr;
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException ex) {
                ex.printStackTrace();
            }
            return str;
        }
    }
}
