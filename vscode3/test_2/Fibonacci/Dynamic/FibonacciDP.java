/*  
     Java쳲��������ж�̬�滮(Dynamic Programming)
     ѧ�ţ�20201050470
     ʱ�临�Ӷȣ�O(n)
*/
import java.util.Scanner;

public class FibonacciDP {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("������쳲��������е�������");
        int n = sc.nextInt();
        DPF dp=new DPF();
        System.out.print("��̬�滮���Ϊ��");
        for(int i=1;i<=n;i++){
            System.out.print(dp.fib(i)+" ");
        }
        // System.out.println(dp.fib(n));
        // int[] dp = new int[n + 1];
        // dp[0] = 0;
        // dp[1] = 1;
        // for (int i = 2; i <= n; i++) {
        //     dp[i] = dp[i - 1] + dp[i - 2];
        // }
        // System.out.println(dp[n]);
    }
}

class DPF{
    public int fib(int n){
        int[] dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
}