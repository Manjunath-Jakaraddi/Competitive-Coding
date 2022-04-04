package codeforces.div31673;

import java.io.*;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.List;

public class ProblemA {
    public static PrintWriter out;

    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        new ProblemA();
        run(sc, out);
        out.close();
    }

    public static void run(MyScanner sc, PrintWriter out) {
        int t = sc.nextInt();
        String str = null, c = null;
        boolean found = false;
        while(t-- > 0 ) {
            found = false;
            str = sc.nextLine();
            c = sc.nextLine();
            for (int i = 0; i < str.length(); i+=2) {
                if (str.charAt(i) == c.charAt(0)) {
                    System.out.println("YES");
                    found = true;
                    break;
                }
            }
            if (!found) {
                System.out.println("NO");
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

