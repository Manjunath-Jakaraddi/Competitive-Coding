package div3;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class ProblemC {
    public static PrintWriter out;

    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));

        int t = sc.nextInt();
        while(t-- > 0) {
            int n = sc.nextInt();
            int mx = Integer.MIN_VALUE;
            List<Integer> arr = new ArrayList<>();
            for(int i=0; i<n; i++) {
                arr.add(sc.nextInt());
                mx = Math.max(mx, arr.get(i));
            }

            int dom=-1;
            for(int i=0; i<n; i++) {
                if(arr.get(i) == mx && ((i!=0 && arr.get(i-1) != mx) || (i!=n-1 && arr.get(i+1) != mx))) {
                    dom=i;
                    break;
                }
            }
            out.println(dom==-1 ? dom: dom+1);
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