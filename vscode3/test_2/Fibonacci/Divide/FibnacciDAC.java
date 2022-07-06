/*
    java쳲��������з��η�(Divide and Conquer)
    ���η��Ļ���˼���ǣ�
    ������ֽ�Ϊ�����⣬Ȼ��ݹ��������⣬���ϲ����������õ�ԭ����Ľ⡣
    ѧ�ţ�20201050470
*/

import java.util.Scanner;

public class FibnacciDAC{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("������쳲��������е�������");
        int n = sc.nextInt();
        DACF dp=new DACF();
        System.out.print("���η����Ϊ��");
        System.out.println(dp.fib(n));
    }
}

class DACF{
    public int fib(int n){
        if(n==1||n==2){
            return 1;
        }
        else{
            return fib(n-1)+fib(n-2);
        }
    }
}