/*
   ð������javaʵ��
   ѧ�ţ�20201050470
   ʱ�临�Ӷȣ�O(n^2)
*/
import java.util.Scanner;

public class BubbleSort{
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        System.out.print("���������鳤�ȣ�");
        int n=input.nextInt();
		int []arr=RandomArray(n, 10000);
        System.out.println("����ǰ�����飺");
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i]+" ");
		}
        BubbleSortAlgorithm(arr);
        // System.out.println("\n���������飺");
        // for (int i = 0; i < arr.length; i++) {
		// 	System.out.print(arr[i]+" ");
		// }
	}
    //����������� 
	public static int[]  RandomArray(int len,int max){
		int[] arr=new int[len];
		for(int i=0;i<arr.length;i++){
			arr[i]=(int)(Math.random()*max);
		}
		return arr;
	}
    // ð�������㷨
    public static void BubbleSortAlgorithm(int[] arr){
        //int temp;
        int sum=0;
        for (int i = 1; i < arr.length; i++) {
            // �趨һ����ǣ���Ϊtrue�����ʾ�˴�ѭ��û�н��н�����Ҳ���Ǵ��������Ѿ����������Ѿ���ɡ�
            boolean flag = true;
            for (int j = 0; j < arr.length - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    int tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                    flag = false;
                }
            }
            if (flag) {
                break;
            }
            sum=sum+arr.length-i;
        }
         System.out.println("\n���������飺");
        for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i]+" ");
    }
    System.out.println("\n���������"+sum);
    }
}