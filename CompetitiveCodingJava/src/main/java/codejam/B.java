package codejam;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class B {
    public static PrintWriter out;

    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        run(sc, out);
        out.close();
    }

    public static void run(MyScanner sc, PrintWriter out) {
        int tests = sc.nextInt();
        for(int testNumber=1; testNumber<=tests; testNumber++) {
            int x = sc.nextInt(), y = sc.nextInt();
            String tempstr = sc.next();
            StringBuilder stringBuilder = new StringBuilder();
            for(int i=0; i< tempstr.length(); i++) {
                if(tempstr.charAt(i) != '?') {
                    stringBuilder.append(tempstr.charAt(i));
                }
            }
            int cost = 0;
            String str = stringBuilder.toString();
            for(int i=0; i<str.length()-1; i++) {
                if(str.charAt(i)=='C' && str.charAt(i+1) == 'J') {
                    cost+=x;
                }
                else if(str.charAt(i) == 'J' && str.charAt(i+1) == 'C') {
                    cost+=y;
                }
            }
            out.println("Case #" + testNumber + ": " + cost);
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