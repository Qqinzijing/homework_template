/* 
    0-1������̬�滮Javaʵ��
    ѧ�ţ�20201050470
    ʱ�临�Ӷȣ�O(nW)
 */
import java.util.Scanner;
public class KnapsackDP {
    public static void main(String[] args) {
        package01_1 p = new package01_1();
        p.initPackage();
    }
}
class package01_1{
    public int max(int a,int b){
        if(a>b)
            return a;
        else
            return b;
    }
    //0-1������̬�滮
    public int[][] knapsack(int n,int C,int weight[],int value[]){
        int[][] F=new int[n+1][C+1];
        for(int i=0;i<=n;i++){
            F[i][0]=0;
        }
        for(int j=0;j<=C;j++){
            F[0][j]=0;
        }
        System.out.printf("\n��� ���� ��ֵ\n");
        for(int i=1;i<=n;i++){
            System.out.printf("%d\t%d\t%d\n",i,weight[i-1],value[i-1]);
        }
        System.out.println("\n0��1������̬�滮��");
        for(int i=0;i<=C;i++){
            System.out.printf("%d ",i);
        }
        System.out.println();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=C;j++){
                if(weight[i-1]<=j){
                    F[i][j]=max(F[i-1][j],F[i-1][j-weight[i-1]]+value[i-1]);
                    System.out.print(F[i][j]+" ");
                }
                else {
                    F[i][j] = F[i - 1][j];
                    System.out.print(F[i][j] + " ");
                }
            }
            System.out.println();
        }
        return F;
    }
    //�����Ž�
    public void Judge(int n,int C,int weight[],int F[][]){
        int state[]=new int[n];
        int j=C;
        for(int i=n-1;i>=1;i--){
            if(F[i][j]>F[i-1][j]){
                state[i]=1;
                j=j-weight[i-1];
            }
            else
                state[i]=0;
        }
        System.out.println("ѡ�е���Ʒ�����:");
        for(int i=0;i<n;i++) {
            if (state[i] == 1)
                System.out.print(i+" ");
        }
       //System.out.println(" ");
    }
    //���������Ʒ����
    public void RandomWeight(int weight[], int len, int max) {
        for (int i = 0; i < weight.length; i++) {
            weight[i] = (int) (Math.random() * max + 1);
        }
        System.out.println("��Ʒ�����������");
        for (int i = 0; i < weight.length; i++) {
            System.out.print(weight[i] + " ");
        }
    }
    //���������Ʒ��ֵ
    public void RandomValue(int value[], int len, int max) {
        for (int i = 0; i < value.length; i++) {
            value[i] = (int) (Math.random() * max + 1);
        }
        System.out.println("��Ʒ�������ֵ��");
        for (int i = 0; i < value.length; i++) {
            System.out.print(value[i] + " ");
        }
    }
    //��ʼ��
    public void initPackage(){
        Scanner sc = new Scanner(System.in);
        System.out.print("��������Ʒ������");
        int N = sc.nextInt();
        System.out.print("�����뱳�������������");
        int C = sc.nextInt();
        int[] weight = new int[N];
        int[] value = new int[N];
        RandomWeight(weight,N,100);
        System.out.println();
        RandomValue(value,N,100);
        //int F[][] = knapsack(N,C,weight,value);
        long startTime = System.currentTimeMillis();//��ʼʱ��
        int F[][] = knapsack(N,C,weight,value);
        Judge(N,C,weight,F);

        System.out.println("\n����ֵΪ��"+F[N][C]);
        long endTime = System.currentTimeMillis();//����ʱ��
        System.out.println("\n��������ʱ�䣺 " + (endTime - startTime ) + "ms");
    }
}








































// //0��1������̬�滮javaʵ��
// import java.util.Scanner;
// public class KnapsackDP {
// //    N��ʾ����ĸ�����V��ʾ����������
// //    ���ڴ洢ÿ��������������±��1��ʼ
// //    weight[];�洢ÿ������ļ�ֵ���±��1��ʼ
// //    value[];
// //    F[][]��ά���飬��������ÿ��״̬�µ��������

//     //ʹ�÷ǵݹ鷽ʽ�����F[0 .. N][0 .. V]����forѭ�������������

	
//     public static void ZeroOnePackNonRecursive(int N, int V, int weight[], int value[], int F[][]) {
//         //�Զ�ά����F���г�ʼ��
//         for(int j = 0; j <= V; j++) {
//             F[0][j] = 0;
//         }
//         System.out.println("\n���   ����   ����");
//         for(int i=0;i<N;i++){
//             System.out.println(i+"\t  "+weight[i]+"     \t"+value[i]);
//         }
//         //ע��߽����⣬i�Ǵ�1��ʼ�ģ�j�Ǵ�0��ʼ��
//         //��ΪF[i - 1][j]��iҪ��1
//         for(int i = 1; i <= N; i++) {
//             for(int j = 0; j <= V; j++) {
//                 //�������Ϊj�ı����ŵ��µ�i������
//                 if(j >= weight[i]) {
//                     F[i][j] = Math.max(F[i - 1][j - weight[i]] + value[i], F[i - 1][j]);
//                 }else {
//                     //�Ų��£�ֻ��ѡ�񲻷ŵ�i������
//                     F[i][j] = F[i - 1][j];
//                 }
//             }
//         }

//         //��ӡ���н��������Ҫ�����F[N][V]
//         System.out.println("\n0��1������̬�滮��");
//         for(int i=0;i<=V;i++){
//             System.out.print(i+" ");
//         }
//         System.out.println();
//         for(int i = 0; i <= N; i++) {
//             for(int j = 0; j <= V; j++) {
//                 System.out.print(F[i][j] + " ");
//             }
//             System.out.println();
//         }
//     }


//     /**
//      ���F[n][m]�������ֵ����ѡȡ�ļ�����Ʒ�ܻ������ֵ����ֻ�����һ�����
//      ��ʾǰn�����壬n <= N;��ʾ������������v <= V
//      */
//     public static void printResult(int n, int v, int weight[], int F[][]) {
//         boolean[] isAdd = new boolean[n + 1];

//         for(int i = n; i >= 1; i--) {
//             if (F[i][v] ==F[i - 1][v]) {
//                 isAdd[i] = false;
//         }
//             else {
//                 isAdd[i] = true;
//                 v -= weight[i];
//             }
//         }
//         System.out.println("ѡ����Ʒ��");
//         for(int i = 1; i <= n; i++) {
//                 //System.out.print(i + " ");
//             System.out.print(isAdd[i] + " ");
//         }
//         System.out.println();
//     }

//     public static void  RandomWeight(int weight[],int len,int max){
//         //int[] arr=new int[len];
//         for(int i=0;i<weight.length;i++){
//             weight[i]=(int)(Math.random()*max+1);
//         }
//         System.out.println("��Ʒ�����������");
//         for(int i=0;i<weight.length;i++) {
//             System.out.print(weight[i] + " ");
//         }
//     }
//     public static void  RandomValue(int value[], int len,int max){
//         //int[] arr=new int[len];
//         for(int i=0;i<value.length;i++){
//             value[i]=(int)(Math.random()*max+1);
//         }
//         System.out.println("��Ʒ�������ֵ��");
//         for(int i=0;i<value.length;i++) {
//             System.out.print(value[i] + " ");
//         }
//     }

//     public static void main(String[] args) {
//         Scanner sc = new Scanner(System.in);
//         System.out.print("��������Ʒ������");
//         int N = sc.nextInt();
//         System.out.print("�����뱳�������������");
//         int V = sc.nextInt();
//         //�±��1��ʼ����ʾ��1����Ʒ
//         int weight[] = new int[N + 1];
//         int value[] = new int[N + 1];
//         int  F[][]= new int[N + 1][V + 1];//ע���� N + 1����Ϊ��Ҫһ����ʼ״̬F[0][0]����ʾǰ0����Ʒ�Ž��ռ�Ϊ0�ı������������
//         //long startTime = System.currentTimeMillis();//��ʼʱ��
//         RandomWeight(weight,N,V);
//         System.out.println();
//         RandomValue(value,N,V);
//         long startTime = System.currentTimeMillis();//��ʼʱ��
//         ZeroOnePackNonRecursive(N,V,weight,value,F);
//         printResult(N,V,weight,F);
//         long endTime = System.currentTimeMillis();//����ʱ��
//         System.out.println("\n�㷨����ʱ�䣺 " + (endTime - startTime ) + "ms");
//     }
// }

















 
// //0-1��������
// public class Knapsack {
	
// 	public static int knapsack(int[] weight, int[] value, int maxweight){
 
// 		int n = weight.length;
// 		//����ֵ����Ϊmaxvalue[N+1][maxWeight+1]����Ϊ����Ҫ��0��ʼ����
// 		int[][] maxvalue = new int[n+1][maxweight + 1];
		
// 		//��������ƷΪ0ʱ����ֵΪ0
// 		for (int i = 0; i < maxweight + 1; i++) {
// 			maxvalue[0][i] = 0;
			
// 		}
// 		for (int i = 0; i < n + 1; i++) {
// 			maxvalue[i][0] = 0;
			
// 		}
		
// 		//i��ֻ��ǰi����Ʒ�������i��Ϊȡ��0�����Զ�Ӧ��weight��value���涼��i-1��λ�ã�      
// 		//j��������ȡ��������Ϊj
// 		//n����Ʒ����
// 		for (int i = 1; i <= n ; i++) {
// 			for (int j = 1; j <= maxweight; j++) {
// 				//��ǰ����ֵ���ڷ���һ��������ֵ
// 				maxvalue[i][j] = maxvalue[i-1][j];
// 				//�����ǰ��������С�������������ԷŽ�ȥ�����ó���Ķ����ٷŽ�ȥ
// 				if (weight[i-1] <= j) {
// 					//�Ƚϣ����������Ʒ�ļ�ֵ����
// 					//�������Ʒ�ļ�ֵ ���� ��ǰ�ܷŵ���������ȥ��ǰ��Ʒ����ʱȡǰi-1����Ʒʱ�Ķ�Ӧ����ʱ�����߼�ֵ��
// 					if(maxvalue[i-1][j - weight[i-1]] + value[i-1]>maxvalue[i-1][j]) {
// 						maxvalue[i][j] = maxvalue[i-1][j - weight[i-1]] + value[i-1];
// 					}
// 				}
// 			}
// 		}
// 		return maxvalue[n][maxweight];
// 	}
// 	public static void main(String[] args) {
// 		// TODO �Զ����ɵķ������
// 		int weight[] = {2,3,4,5};
// 		int value[] = {3,4,5,7};
// 		int maxweight = 9;
// 		System.out.println(knapsack(weight, value, maxweight));
// 	}
 
// }