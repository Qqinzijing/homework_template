import java.util.Scanner;
public class c{
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        System.out.print("���������鳤�ȣ�");
        int n=input.nextInt();
        // System.out.println("����������������ֵ")
		int []arr=gennerateArray(n, 10000);
        System.out.println("����ǰ�����飺");
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i]+" ");
		}
        BubbleSortAlgorithm(arr);
        System.out.println("\n���������飺");
        for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i]+" ");
		}
	}
		public static int[]  gennerateArray(int len,int max){
			int[] arr=new int[len];
			for(int i=0;i<arr.length;i++){
				arr[i]=(int)(Math.random()*max);
			}
			return arr;
	}
    public static void BubbleSortAlgorithm(int[] arr){
        //int temp;
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
        }
    }
}