package codeforces.div3;
import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class ProblemB {
    public static PrintWriter out;

    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));

        int t = sc.nextInt();
        while(t-- > 0) {
            int n = sc.nextInt();
            List<Integer> arr = new ArrayList<>();
            for(int i=0; i<n; i++) {
                arr.add(sc.nextInt());
            }
            int res = 0;
            int l=0, r=n-1;
            while(arr.get(l) == 0) l++;
            while(arr.get(r) == 0) r--;
            while(l<r) {
                if(arr.get(l) == 0) res++;
                l++;
            }
            out.println(res);
        }
        out.close();
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