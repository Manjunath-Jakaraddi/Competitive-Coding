package codeforces.div3713;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class B {
    public static PrintWriter out;

    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        new B().run(sc, out);
        out.close();
    }

    public static void run(MyScanner sc, PrintWriter out) {
        int t = sc.nextInt(), n;
        int[] x = new int[4];
        int[] y = new int[4];
        while(t-- > 0) {
            n = sc.nextInt();
            x[0] = -1; y[0] = -1;
            String[] grid = new String[n];
            for(int i=0; i<n; i++) {
                grid[i]=sc.nextLine();
                for(int j=0; j<n; j++) {
                    if(grid[i].charAt(j) == '*') {
                        if(x[0] == -1) {
                            x[0] = i;
                            y[0] = j;
                        } else {
                            x[1] = i;
                            y[1] = j;
                        }
                    }
                }
            }
            if(x[0] == x[1] || y[0] == y[1]) {
                // same row or column
                if(y[0] == y[1]) {
                    x[2] = x[0];
                    x[3] = x[1];
                    y[3] = y[2] = y[0] + 1 < n ? y[0] + 1 : y[0] - 1;
                } else {
                    y[2] = y[0];
                    y[3] = y[1];
                    x[3] = x[2] = x[0] + 1 < n ? x[0] + 1 : x[0] - 1;
                }
            } else {
                x[2] = x[0]; y[2] = y[1];
                x[3] = x[1]; y[3] = y[0];
            }

            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    boolean isStar = false;
                    for(int k=0; k<4; k++) {
                        if(i == x[k] && j == y[k]) {
                            out.print("*");
                            isStar = true;
                            break;
                        }
                    }
                    if(!isStar) {
                        out.print(".");
                    }
                }
                out.print("\n");
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
