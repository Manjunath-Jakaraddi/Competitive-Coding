import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

class TestClass {
    public static void main(String args[] ) throws Exception {
        try(Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)))) {
            int q = sc.nextInt();
            while(q-- > 0) {
                long num = sc.nextLong();
                if (num == 1 || num == 2 || (num - 1)%2 != 0) {
                    System.out.println(0);
                }else {
                    long power = (num - 3) / 2;
                    System.out.println(powmod(2, power));
                }
            }
        }
    }

    private static long powmod(int base, long power) {
        if(power == 0)  {
            return 1;
        }
        long res = powmod(base, power/2);
        if(power%2 != 0) {
            return ((((res*res)%10000007)*base)%10000007);
        }
        return (res*res)%10000007;
    }
}