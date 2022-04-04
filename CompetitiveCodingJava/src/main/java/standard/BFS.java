package standard;

import java.io.*;
import java.util.*;

public class BFS {
    public static PrintWriter out;

    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        new BFS().run(sc, out);
        out.close();
    }

    void run(MyScanner sc, PrintWriter out) {
        int[][][] parts = {
                {},
                {},
                {{2}},
                {{3}, {2, 1}},
                {{4}, {3, 1}, {2, 2}, {2, 1, 1}},
                {{5}, {4, 1}, {3, 2}, {3, 1, 1}, {2, 2, 1}, {2, 1, 1, 1}},
                {{6}, {5, 1}, {4, 2}, {4, 1, 1}, {3, 3}, {3, 2, 1}, {3, 1, 1, 1}, {2, 2, 2}, {2, 2, 1, 1}, {2, 1, 1, 1, 1}},
                {{7}, {6, 1}, {5, 2}, {5, 1, 1}, {4, 3}, {4, 2, 1}, {4, 1, 1, 1}, {3, 3, 1}, {3, 2, 2}, {3, 2, 1, 1}, {3, 1, 1, 1, 1}, {2, 2, 2, 1}, {2, 2, 1, 1, 1}, {2, 1, 1, 1, 1, 1}},
                {{8}, {7, 1}, {6, 2}, {6, 1, 1}, {5, 3}, {5, 2, 1}, {5, 1, 1, 1}, {4, 4}, {4, 3, 1}, {4, 2, 2}, {4, 2, 1, 1}, {4, 1, 1, 1, 1}, {3, 3, 2}, {3, 3, 1, 1}, {3, 2, 2, 1}, {3, 2, 1, 1, 1}, {3, 1, 1, 1, 1, 1}, {2, 2, 2, 2}, {2, 2, 2, 1, 1}, {2, 2, 1, 1, 1, 1}, {2, 1, 1, 1, 1, 1, 1}},
                {{9}, {8, 1}, {7, 2}, {7, 1, 1}, {6, 3}, {6, 2, 1}, {6, 1, 1, 1}, {5, 4}, {5, 3, 1}, {5, 2, 2}, {5, 2, 1, 1}, {5, 1, 1, 1, 1}, {4, 4, 1}, {4, 3, 2}, {4, 3, 1, 1}, {4, 2, 2, 1}, {4, 2, 1, 1, 1}, {4, 1, 1, 1, 1, 1}, {3, 3, 3}, {3, 3, 2, 1}, {3, 3, 1, 1, 1}, {3, 2, 2, 2}, {3, 2, 2, 1, 1}, {3, 2, 1, 1, 1, 1}, {3, 1, 1, 1, 1, 1, 1}, {2, 2, 2, 2, 1}, {2, 2, 2, 1, 1, 1}, {2, 2, 1, 1, 1, 1, 1}, {2, 1, 1, 1, 1, 1, 1, 1}}
        };
        long c = sc.nextLong();
        int tempvar = sc.nextInt();
        double d = tempvar * 1.0F;
        double cNum = d;
        List<Set<Double>> res = new ArrayList<>();
        Set<Double> st = new TreeSet<>();
        st.add(cNum);
        st.add(-cNum);
        res.add(st);
        for(int i=1; i<c; i++) {
            Set<Double> newst = new TreeSet<>();
            for(double val : res.get(i-1)) {
                double addNewVal = val + d;
                double subNewVal = val - d;
                double mulNewVal = val * d;
                double divNewVal = val / d;
                newst.add(addNewVal);
                newst.add(-addNewVal);
                newst.add(subNewVal);
                newst.add(-subNewVal);
                newst.add(mulNewVal);
                newst.add(-mulNewVal);
                newst.add(divNewVal);
                newst.add(-divNewVal);
                if(val != 0) {
                    double divrevval = d / val;
                    newst.add(divrevval);
                    newst.add(-divrevval);
                }
            }
            cNum = (cNum*10)+d;
            newst.add(cNum);
            newst.add(-cNum);
            res.add(newst);
        }
        Set<Long> finalList = new TreeSet<>();
        for(int[] arr: parts[(int)c]) {
            Set<Double> tempst = new TreeSet<>();
            for(int arr2: arr) {
                Set<Double> temp = new TreeSet<>();
                for(double ele : res.get(arr2-1)) {
                    if(tempst.size() != 0) {
                        for(double tmpEle: tempst) {
                            double addNewVal = ele + tmpEle;
                            double subNewVal = ele - tmpEle;
                            double mulNewVal = ele * tmpEle;
                            double divNewVal = ele / tmpEle;
                            temp.add(addNewVal);
                            temp.add(-addNewVal);
                            temp.add(subNewVal);
                            temp.add(-subNewVal);
                            temp.add(mulNewVal);
                            temp.add(-mulNewVal);
                            temp.add(divNewVal);
                            temp.add(-divNewVal);
                            if(ele != 0) {
                                double divrevval = (tmpEle / ele);
                                temp.add(divrevval);
                                temp.add(-divrevval);
                            }
                        }
                    } else {
                        temp.add(ele);
                    }
                }
                tempst.clear();
                tempst.addAll(temp);
            }
            for(Double ele: tempst) {
                if(Math.round(ele) == ele) {
                    finalList.add((long)Math.round(ele));
                }
            }
        }
        int answer = 1;
        for(long ele: finalList) {
            if(ele<=0) continue;
            if(ele!= answer) break;
            answer++;
        }
        out.println(answer + " cannot be computed in " + c + " " + (long)d+ "s");
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