package probs;

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

public class ModifiedPathFind {
    int m, n, numCoins;
    int[][][] vis;
    int[][] grid;
    List<Pair<Integer>> coins = new ArrayList<>();
    Pair<Integer> currCoinPos;
    Pair<Integer> src, dst;
    Pair<Integer>[] dirs = new Pair[4];
    public static PrintWriter out;

    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        new ModifiedPathFind().run(sc, out);
    }

    boolean isValidPos(Pair<Integer> pos) {
        return pos.x >=0 && pos.x <m && pos.y>=0 && pos.y<n && grid[pos.x][pos.y] !=1;
    }

    void bfs(Pair<Integer> src, int ind) {
        vis[src.x][src.y][ind] = 0;
        LinkedList<Pair<Integer>> queue = new LinkedList<>();
        queue.add(src);
        while(!queue.isEmpty()) {
            src = queue.poll();
            for(Pair<Integer> dir : dirs) {
                Pair<Integer> pos = new Pair<>(src.x + dir.x, src.y+dir.y);
                if(isValidPos(pos) && vis[pos.x][pos.y][ind] == -1) {
                    queue.add(pos);
                    vis[pos.x][pos.y][ind] = vis[src.x][src.y][ind] + 1;
                }
            }
        }
    }

    void run(MyScanner sc, PrintWriter out) {
        m = sc.nextInt();
        n = sc.nextInt();
        numCoins = sc.nextInt();
        grid = new int[m][n];
        vis = new int[m][n][numCoins+1];
        src = new Pair<>(sc.nextInt(), sc.nextInt());
        dst = new Pair<>(sc.nextInt(), sc.nextInt());

        dirs[0] = new Pair<>(-1,0);
        dirs[1] = new Pair<>(1, 0);
        dirs[2] = new Pair<>(0, -1);
        dirs[3] = new Pair<>(0, 1);

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int inp = sc.nextInt();
                grid[i][j]=inp;
                if(inp == 2) {
                    coins.add(new Pair<>(i, j));
                }
                for(int k=0; k<=numCoins; k++) {
                    vis[i][j][k]=-1;
                }
            }
        }

        bfs(src, 0);
        for(Pair<Integer> coin : coins) {
            if(vis[coin.x][coin.y][0] == -1 || vis[dst.x][dst.y][0] == -1) {
                System.out.println(-1);
                System.exit(0);
            }
        }
        printPath(0);
        System.out.println("==============");
        for(int i=0; i<coins.size(); i++) {
            bfs(coins.get(i), i+1);
            printPath(i+1);
            System.out.println("==============");
        }

        int minDist = 0;
        int currCoin = 0, nextCoin=0;
        boolean[] coinPicked = new boolean[numCoins+1];
        for(int i=0; i<numCoins; i++) {
            int nearestCoinDist = Integer.MAX_VALUE;
            for(int j=0; j<numCoins; j++) {
                if(!coinPicked[j+1] && vis[coins.get(j).x][coins.get(j).y][currCoin] < nearestCoinDist) {
                    nearestCoinDist = vis[coins.get(j).x][coins.get(j).y][currCoin];
                    nextCoin = j+1;
                }
            }
            minDist += nearestCoinDist;
            coinPicked[nextCoin] = true;
            currCoin = nextCoin;
        }
        minDist+=vis[dst.x][dst.y][currCoin];
        System.out.println(minDist);
    }

    void printPath(int ind) {
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                System.out.print(vis[i][j][ind] + " ");
            }
            System.out.print("\n");
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

//3 3
//2
//0 0
//2 2
//0 2 1
//1 2 0
//1 0 0
//. . . 0 . . .
//. . . 1 . . .
//2 . . 1 . . 0


//3 7
//3
//0 3
//2 6
//0 0 0 0 0 0 0
//0 0 0 1 0 2 0
//2 0 0 1 2 0 0