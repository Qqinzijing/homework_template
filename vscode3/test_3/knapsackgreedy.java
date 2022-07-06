/*
    ��������̰���㷨javaʵ��
    ѧ�ţ�20201050470
    ʱ�临�Ӷȣ�O(n^2)

*/
import java.util.*;

//[1..n]�� w[1..n]�ֱ��а� vi/wi>v(i+1)(i+1)����� n����Ʒ�ļ�ֵ��������M �Ǳ�����������С���� x[1..n]�ǽ�����
class knapsackgreedy {
    public static void main(String[] args) {
        KnapsackGr kp = new KnapsackGr();
        kp.initPackage();
    }
}

class KnapsackGr{
    public void Knapsack(double P[], double W[], int M, int n) {
        int i;
        double X[] = new double[n]; //����������
        for (i = 0; i < X.length; i++) {
            X[i] = 0;
        }
        double cu = M; //cu�Ǳ���ʣ������
        for (i = 0; i < n; i++) {
            if (W[i] > cu) {
                break;
            }
            X[i] = 1;
            cu = cu - W[i];
        }
        System.out.println("��0��ʼ����װ���ǰn+1����Ʒ:"+i);
        if (i < n) {
            X[i] = cu / W[i];
        }
        System.out.println("����Ľ�Ϊ��");
        for (int k = 0; k < X.length; k++) {
            System.out.print(X[k] + " ");
        }
        float sum = 0;
        for (int j = 0; j < X.length; j++) {
            sum += X[j] * P[j];
        }
        System.out.println("\n�ܼ�ֵΪ��" + sum);
    }
    public void sortkp(double PW[], int index[], int n, double P[], double W[],int M) {
        for (int i = 0; i < n; i++) {
            PW[i] = P[i] / W[i];
            index[i] = i;
        }
        double temp = 0;
        for (int i = 0; i < n ; i++) {
            for (int j = i + 1; j < n; j++) {
                if (PW[i] < PW[j])       //��Ч��/�������鰴������������
                {
                    temp = PW[i];
                    PW[i] = PW[j];
                    PW[j] = temp;
                    int x = index[i];       //������Ӧ�������±�
                    index[i] = index[j];
                    index[j] = x;
                }
            }
        }
        double[] w1 = new double[n];
        double[] p1 = new double[n];
        for (int i = 0; i < n; i++) {
            w1[i] = W[index[i]];     //�������������ͼ�ֵ����ֱ𸳸�w1[]��p1[]
            p1[i] = P[index[i]];
        }
        System.out.println("\n����ƷЧ��/������ֵΪ��");
        for (int i = 0; i < n; i++) {
            System.out.print(PW[i] + " ");
        }
        System.out.println("\n\t\tv[1..n]�� w[1..n]�ֱ��а� vi/wi>v(i+1)(i+1)�����n ����Ʒ�ļ�ֵ������\n" );
        System.out.println("��Ӧ����������Ϊ��" + Arrays.toString(w1));
        System.out.println("��Ӧ��Ч������Ϊ��" + Arrays.toString(p1));
        KnapsackGr kg = new KnapsackGr();
        kg.Knapsack(p1,w1,M,n);
    }
    public void RandomWeight(double weight[], int len, int max) {
        for (int i = 0; i < weight.length; i++) {
            weight[i] = (double) (Math.random() * max + 1);
        }
        System.out.println("��Ʒ�����������");
        for (int i = 0; i < weight.length; i++) {
            System.out.print(weight[i] + " ");
        }
    }
    public void RandomValue(double value[], int len, int max) {
        for (int i = 0; i < value.length; i++) {
            value[i] = (double) (Math.random() * max + 1);
        }
        System.out.println("��Ʒ�������ֵ��");
        for (int i = 0; i < value.length; i++) {
            System.out.print(value[i] + " ");
        }
    }
    public void initPackage(){
        Scanner sc = new Scanner(System.in);
        System.out.print("��������Ʒ������");
        int N = sc.nextInt();
        System.out.print("�����뱳�������������");
        int C = sc.nextInt();
        double[] weight = new double[N];
        double[] value = new double[N];
        RandomWeight(weight,N,100);
        System.out.println();
        RandomValue(value,N,100);
        double PW[] = new double[value.length];
        int[] index = new int[N];
        long startTime = System.currentTimeMillis();//��ʼʱ��
        sortkp(PW,index,N,value,weight,C);
        long endTime = System.currentTimeMillis();//����ʱ��
        System.out.println("\n��������ʱ�䣺 " + (endTime - startTime ) + "ms");
    }
}

























































































// package knpgdy;
// import java.util.*;
// public class kDD {

//     public void Knapsack(double P[],double W[],int M,int n)

//     {

//         int i ;

//         double X[] = new double[n]; //����������

//         for(i=0;i<X.length;i++)

//             X[i] = 0;

//         double cu = M; //cu�Ǳ���ʣ������

//         for(i=0;i<n;i++)

//         { if(W[i]>cu)

//             break;

//             X[i] = 1;

//             cu = cu-W[i];

//         }

// // System.out.println(i);

//         if(i<n)

//             X[i] = cu/W[i];

//         System.out.println("����Ľ�Ϊ��");

//         for(int k=0;k<X.length;k++)

//             System.out.print(X[k] + " ");

//     }



//     public static void main(String[] args){

//         double P[] = {10,5,15,7,6,18,3}; //Ч������

//         double W[] = {2,3,5,7,1,4,1};

//         int M = 15,n = 7;

//         double PW[] = new double[P.length];

//         int[] index = new int[n];

//         for(int i= 0;i<n;i++){

//             PW[i] = P[i] / W[i];

//             index[i] =i;

//         }

//         double temp =0;

//         for(int i=0;i<n;i++)

//         {

//             for(int j=i+1;j<n;j++)

//             {

//                 if(PW[i]<PW[j])       //��Ч��/�������鰴������������

//                 {

//                     temp = PW[i];

//                     PW[i] = PW[j];

//                     PW[j] = temp;

//                     int x=index[i];       //������Ӧ�������±�

//                     index[i] = index[j];

//                     index[j] = x;

//                 }

//             }

//         }

//         double[] w1 = new double[n];

//         double[] p1 = new double[n];

//         for(int i=0;i<n;i++)

//         {

//             w1[i]=W[index[i]];     //�������������ͼ�ֵ����ֱ𸳸�w1[]��p1[]

//             p1[i]=P[index[i]];

//         }

//         System.out.println("����ƷЧ��/������ֵΪ��");

//         for(int i=0;i<n;i++)

//             System.out.print(PW[i]+" ");

//         System.out.println();

//         System.out.println ("��Ӧ����������Ϊ��"+Arrays.toString(w1));

//         System.out.println ("��Ӧ��Ч������Ϊ��"+Arrays.toString(p1));

//         kDD gk = new kDD();

//         gk.Knapsack(p1,w1,M,n);

//     }

// }

















// //��������̰���㷨javaʵ��
// import java.util.*;

// //v[1..n]�� w[1..n]�ֱ��а� vi/wi>v(i+1)/v(i+1)����� n
// //����Ʒ�ļ�ֵ��������M �Ǳ�����������С���� x[1..n]�ǽ�����
// public class knapsackgreedy {
//     public void Knapsack(double P[], double W[], int M, int n) {
//         int i;
//         double X[] = new double[n]; //����������
//         for (i = 0; i < X.length; i++) {
//             X[i] = 0;
//         }
//         double cu = M; //cu�Ǳ���ʣ������
//         for (i = 0; i < n; i++) {
//             if (W[i] > cu) {
//                 break;
//             }
//             X[i] = 1;
//             cu = cu - W[i];
//         }

//         System.out.println("��0��ʼ����װ���ǰn+1����Ʒ:"+i);
       
//         if (i < n) {
//             X[i] = cu / W[i];
//         }
//         System.out.println("����Ľ�Ϊ��");

//         for (int k = 0; k < X.length; k++) {
//             System.out.print(X[k] + " ");
//         }
//     }

// public static void sortkp(double PW[], int index[], int n, double P[], double W[],int M) {
//         for (int i = 0; i < n; i++) {
//             PW[i] = P[i] / W[i];
//             index[i] = i;
//         }

//         double temp = 0;
//         for (int i = 0; i < n - 1; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 if (PW[i] < PW[j])       //��Ч��/�������鰴������������
//                 {
//                     temp = PW[i];
//                     PW[i] = PW[j];
//                     PW[j] = temp;
//                     int x = index[i];       //������Ӧ�������±�
//                     index[i] = index[j];
//                     index[j] = x;
//                 }
//             }
//         }

//         double[] w1 = new double[n];
//         double[] p1 = new double[n];
//         for (int i = 0; i < n; i++) {
//             w1[i] = W[index[i]];     //�������������ͼ�ֵ����ֱ𸳸�w1[]��p1[]
//             p1[i] = P[index[i]];
//         }

//         System.out.println("\n����ƷЧ��/������ֵΪ��");

//         for (int i = 0; i < n; i++) {
//             System.out.print(PW[i] + " ");
//         }
//         System.out.println("\n\t\tv[1..n]�� w[1..n]�ֱ��а� vi/wi>v(i+1)/v(i+1)�����n ����Ʒ�ļ�ֵ��������\n" );

//         System.out.println("��Ӧ����������Ϊ��" + Arrays.toString(w1));

//         System.out.println("��Ӧ��Ч������Ϊ��" + Arrays.toString(p1));
//         knapsackgreedy kg = new knapsackgreedy();
//         kg.Knapsack(p1,w1,M,n);
//     }

// public static void RandomWeight(double weight[], int len, int max) {
//         for (int i = 0; i < weight.length; i++) {
//             weight[i] = (double) (Math.random() * max + 1);
//         }
//         System.out.println("��Ʒ�����������");
//         for (int i = 0; i < weight.length; i++) {
//             System.out.print(weight[i] + " ");
//         }
//     }

// public static void RandomValue(double value[], int len, int max) {
//         for (int i = 0; i < value.length; i++) {
//             value[i] = (double) (Math.random() * max + 1);
//         }
//         System.out.println("��Ʒ�������ֵ��");
//         for (int i = 0; i < value.length; i++) {
//             System.out.print(value[i] + " ");
//         }
//     }

// public static void main(String[] args) {
//         //initPackage();
//         Scanner sc = new Scanner(System.in);
//         System.out.print("��������Ʒ������");
//         int N = sc.nextInt();
//         System.out.print("�����뱳�������������");
//         int C = sc.nextInt();
//         double[] weight = new double[N];
//         double[] value = new double[N];
//         //long startTime = System.currentTimeMillis();//��ʼʱ��
//         RandomWeight(weight,N,100);
//         System.out.println();
//         RandomValue(value,N,100);
//         double PW[] = new double[value.length];

//         int[] index = new int[N];
//         long startTime = System.currentTimeMillis();//��ʼʱ��
//         sortkp(PW,index,N,value,weight,C);
//         // knapsackgreedy kg = new knapsackgreedy();
//         // kg.Knapsack(value,value,C,N);

//         long endTime = System.currentTimeMillis();//����ʱ��
//         System.out.println("\n��������ʱ�䣺 " + (endTime - startTime ) + "ms");
//     }

// }