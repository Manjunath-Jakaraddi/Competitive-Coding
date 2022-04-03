package codejam;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class C {
    public static PrintWriter out;

    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        run(sc, out);
        out.close();
    }
    public static void reverse(int[] elements, int start, int count) {
        for(int i=0; i<count/2; i++) {
            int temp = elements[start+i];
            elements[start+i] = elements[start+count-i-1];
            elements[start+count-i-1]=temp;
        }
    }

    public static void costApply(int[] elements, int currentInd, int remCost) {
        int mxCostCanApply = elements.length - currentInd;
        if(remCost <= 0) return;
        int costToApply = 0;
        if(remCost >= mxCostCanApply) {
            costToApply=mxCostCanApply;
        } else {
            costToApply = remCost;
        }
        reverse(elements, currentInd-1, costToApply+1);
        costApply(elements, currentInd-1, remCost-costToApply);
    }

    public static void run(MyScanner sc, PrintWriter out) {
        int tests = sc.nextInt();
        for(int testNumber=1; testNumber<=tests; testNumber++) {
            int n=sc.nextInt(), cost=sc.nextInt();
            int mxcost=(n*(n+1))/2-1;
            if(cost > mxcost || cost < n-1) {
                out.println("Case #" + testNumber + ": IMPOSSIBLE");
                continue;
            }
            int[] elements = new int[n];
            for(int i=1; i<=n; i++)
                elements[i-1]=i;
            costApply(elements, n-1, cost-n+1);
            out.print("Case #" + testNumber + ": ");
            for(int i=0; i< elements.length; i++)
                out.print(elements[i] + " ");
            if(testNumber != tests) out.print("\n");
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