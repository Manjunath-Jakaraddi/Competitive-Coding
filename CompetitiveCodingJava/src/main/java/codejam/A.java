package codejam;

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;


public class A {
    public static PrintWriter out;

    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        runb(sc, out);
        out.close();
    }

    private static int findMinIndex(int[] elements, int begin, int end) {
        int minIndex = begin;
        for(int i=begin; i<end; i++) {
            if(elements[minIndex] > elements[i]) {
                minIndex = i;
            }
        }
        return minIndex;
    }
    private static void reverse(int[] elements, int start, int count) {
        for(int i=start; i<count/2; i++) {
            int temp = elements[start + i];
            elements[start + i] = elements[count-i-1+start];
        }
    }
    private static void solve(int testNumber, int[] elements) {
        int cost = 0;
        for(int i=0; i< elements.length-1; i++) {
            int minInd = findMinIndex(elements, i, elements.length);
            cost+= (minInd - i + 1);
            reverse(elements, i, minInd - i + 1);
        }
    }
    public static void runb(MyScanner sc, PrintWriter out) {
        int totalTests = sc.nextInt();
        for(int testNumber=1; testNumber<=totalTests; testNumber++) {
            int elementCount = sc.nextInt();
            int[] elements = new int[elementCount];
            for(int i=0; i< elementCount; i++) {
                elements[i] = sc.nextInt();
            }
            solve(testNumber, elements);
        }
    }
    public static void runa(MyScanner sc, PrintWriter out) {
        int t = sc.nextInt();
        int cse = 1;
        while(cse <= t) {
            int n = sc.nextInt();
            List<Integer> arr = new ArrayList<>();
            for(int i=0; i< n; i++) {
                arr.add(sc.nextInt());
            }

            int cost = 0;
            for(int i=0; i<n-1; i++) {
                int min_ele = Integer.MAX_VALUE, min_ele_ind = -1;
                for(int j=i; j<n; j++) {
                    if(min_ele > arr.get(j)) {
                        min_ele = arr.get(j);
                        min_ele_ind = j;
                    }
                }
                for(int j=0; j<(min_ele_ind-i+1)/2; j++) {
                    int temp = arr.get(i+j);
                    arr.set(i+j, arr.get(min_ele_ind-j));
                    arr.set(min_ele_ind-j, temp);
                }
                cost+=(min_ele_ind - i + 1);
            }
            out.println("Case #" + cse + ": " + cost);
            cse++;
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
