package educationalharbour;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.List;

public class Solution {
    public static PrintWriter out;

    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        new Solution();
        run(sc, out);
        out.close();
    }

    public static void run(MyScanner sc, PrintWriter out) {

    }

    public static void runB(MyScanner sc, PrintWriter out) {
        int n = sc.nextInt();
        while(n-->0) {
            boolean done = false;
            String s = sc.nextLine();
            char[] str = s.toCharArray();
            for(int i=s.length()-1; i >0; i--) {
                int sum = str[i] + str[i - 1] - 2 * '0';
                if(sum > 9) {
                    done = true;
                    str[i-1]='1';
                    str[i]=(char)((sum - 10) + '0');
                    break;
                }
            }
            if(done) {
                System.out.println(new String(str));
            } else {
                System.out.print((char)(s.charAt(0) + s.charAt(1) - '0'));
                for(int i=2; i<s.length(); i++) {
                    System.out.print(s.charAt(i));
                }
                System.out.print("\n");
            }
        }
    }

    public static void runA(MyScanner sc, PrintWriter out) {
        int n = sc.nextInt();
        while(n-->0) {
            String s = sc.nextLine();
            char[] chars = s.toCharArray();
            Arrays.sort(chars);
            System.out.println(new String(chars));
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
