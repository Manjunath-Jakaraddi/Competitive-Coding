package codeforces.div3;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class ProblemD {
    public static PrintWriter out;

    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        new ProblemD().run(sc, out);
    }

    void run(MyScanner sc, PrintWriter out) {
        int t = sc.nextInt();
        while(t-- > 0) {
            int n = sc.nextInt();
            int[] arr = sc.nextIntArray(n);
            solve(arr,n);
        }
//        while(t-- > 0) {
//            int n = sc.nextInt();
//            List<Integer> arr = new ArrayList<>();
//            Map<Integer, Integer> mmap = new TreeMap<>();
//            for(int i=0; i<n; i++) {
//                arr.add(sc.nextInt());
//                if(!mmap.containsKey(arr.get(i))) {
//                    mmap.put(arr.get(i), 1);
//                } else {
//                    mmap.put(arr.get(i), mmap.get(arr.get(i)) + 1);
//                }
//            }
//            if(mmap.size() == 1) {
//                out.println("NO");
//
//            } else {
//                out.println("YES");
//                int root = arr.get(0), nonrootInd=-1;
//                List<Integer> rootInds = new ArrayList<>();
//                for(int i=1; i<n; i++) {
//                    if(arr.get(i) == root) {
//                        rootInds.add(i+1);
//                    } else {
//                        if(nonrootInd == -1) nonrootInd = i+1;
//                        out.println("1 " + (i+1));
//                    }
//                }
//                for(int rem : rootInds) {
//                    out.println(nonrootInd + " " + rem);
//                }
//            }
//        }
        out.close();
    }
    void solve(int[] arr, int n) {
        List<Pair<Integer>> res = new ArrayList<>();
        dfs(0, arr, new int[n], res);
        if(res.size() != n-1) {
            out.println("NO");
            return;
        }
        out.println("YES");
        for(Pair<Integer> pair: res) {
            out.println(pair.x + " " + pair.y);
        }
    }

    void dfs(int root, int[] arr, int[] vis, List<Pair<Integer>> res) {
        vis[root] = 1;
        for(int i=0; i<arr.length; i++) {
            if(vis[i] == 0 && arr[root] != arr[i]) {
                res.add(new Pair<>(root+1, i+1));
                dfs(i, arr, vis, res);
            }
        }
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