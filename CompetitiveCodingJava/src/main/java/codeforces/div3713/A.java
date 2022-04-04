package codeforces.div3713;
import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class A {
    public static PrintWriter out;

    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        new A().run(sc, out);
        out.close();
    }

    public void run(MyScanner sc, PrintWriter out) {
        int k, n;
        k = sc.nextInt();
        while(k-- > 0) {
            n = sc.nextInt();
            int[] arr = new int[n];
            for(int i=0; i<n; i++) {
                arr[i] = sc.nextInt();
            }
            for(int i=0; i<n-2; i++) {
                if((arr[i] != arr[i+1] || arr[i] != arr[i+2])) {
                    printOdd(arr[i], arr[i+1], arr[i+2], i+1, out);
                    break;
                }

            }
        }
    }
    private void printOdd(int a, int b, int c, int ind, PrintWriter out) {
        if(a == b) {
            out.println(ind+2);
        } else if(a == c) {
            out.println(ind+1);
        } else {
            out.println(ind);
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