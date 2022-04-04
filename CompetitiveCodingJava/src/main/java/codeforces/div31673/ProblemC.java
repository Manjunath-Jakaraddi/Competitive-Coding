package codeforces.div31673;

import java.io.*;
import java.util.*;

public class ProblemC {
    public static PrintWriter out;

    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        new ProblemC().run(sc, out);
        out.close();
    }

    public void run(MyScanner sc, PrintWriter out) {
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt(), m = sc.nextInt();
            long ans=0, x, y;
            HashMap<Long, Integer> origInd = new HashMap<>();
            List<Pair<Long>> arr = new ArrayList<>(m), ind = new ArrayList<>(m);
            for (int i = 0; i < m; i++) {
                x = sc.nextLong();
                y = sc.nextLong();
                origInd.put(x, i+1);
                arr.add(new Pair<>(x, y));
                ind.add(new Pair<>(y, x));
            }
            arr.sort(Comparator.comparingLong(p -> p.x));
            ind.sort(Comparator.comparingLong(p -> p.x));
            HashMap<Long, Boolean> hmap = new HashMap<>();
            for (int i = 0; i < m-2*n; i++) {
                hmap.put(ind.get(m-1-i).y, true);
            }
            List<Pair<Integer>> res = new ArrayList<>();
            int l=0, r=m-1, cnt=0;
            while (cnt<n) {
                while(hmap.containsKey(arr.get(l).x) && hmap.get(arr.get(l).x)) l++;
                while(hmap.containsKey(arr.get(r).x) && hmap.get(arr.get(r).x)) r--;
                res.add(new Pair<>(origInd.get(arr.get(l).x), origInd.get(arr.get(r).x)));
                ans+=arr.get(l).y + arr.get(r).y;
                cnt++;
                l++;
                r--;
            }
            System.out.println(ans);
            res.forEach(pr -> System.out.println(pr.x + " " + pr.y));
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
