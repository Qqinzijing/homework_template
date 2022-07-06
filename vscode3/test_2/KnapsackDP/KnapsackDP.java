/* 
    0-1背包动态规划Java实现
    学号：20201050470
    时间复杂度：O(nW)
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
    //0-1背包动态规划
    public int[][] knapsack(int n,int C,int weight[],int value[]){
        int[][] F=new int[n+1][C+1];
        for(int i=0;i<=n;i++){
            F[i][0]=0;
        }
        for(int j=0;j<=C;j++){
            F[0][j]=0;
        }
        System.out.printf("\n编号 重量 价值\n");
        for(int i=1;i<=n;i++){
            System.out.printf("%d\t%d\t%d\n",i,weight[i-1],value[i-1]);
        }
        System.out.println("\n0—1背包动态规划表：");
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
    //求最优解
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
        System.out.println("选中的物品编号是:");
        for(int i=0;i<n;i++) {
            if (state[i] == 1)
                System.out.print(i+" ");
        }
       //System.out.println(" ");
    }
    //随机生成物品重量
    public void RandomWeight(int weight[], int len, int max) {
        for (int i = 0; i < weight.length; i++) {
            weight[i] = (int) (Math.random() * max + 1);
        }
        System.out.println("物品的随机重量：");
        for (int i = 0; i < weight.length; i++) {
            System.out.print(weight[i] + " ");
        }
    }
    //随机生成物品价值
    public void RandomValue(int value[], int len, int max) {
        for (int i = 0; i < value.length; i++) {
            value[i] = (int) (Math.random() * max + 1);
        }
        System.out.println("物品的随机价值：");
        for (int i = 0; i < value.length; i++) {
            System.out.print(value[i] + " ");
        }
    }
    //初始化
    public void initPackage(){
        Scanner sc = new Scanner(System.in);
        System.out.print("请输入物品个数：");
        int N = sc.nextInt();
        System.out.print("请输入背包的最大容量：");
        int C = sc.nextInt();
        int[] weight = new int[N];
        int[] value = new int[N];
        RandomWeight(weight,N,100);
        System.out.println();
        RandomValue(value,N,100);
        //int F[][] = knapsack(N,C,weight,value);
        long startTime = System.currentTimeMillis();//起始时间
        int F[][] = knapsack(N,C,weight,value);
        Judge(N,C,weight,F);

        System.out.println("\n最大价值为："+F[N][C]);
        long endTime = System.currentTimeMillis();//结束时间
        System.out.println("\n程序运行时间： " + (endTime - startTime ) + "ms");
    }
}








































// //0—1背包动态规划java实现
// import java.util.Scanner;
// public class KnapsackDP {
// //    N表示物体的个数，V表示背包的载重
// //    用于存储每个物体的重量，下标从1开始
// //    weight[];存储每个物体的价值，下标从1开始
// //    value[];
// //    F[][]二维数组，用来保存每种状态下的最大收益

//     //使用非递归方式，求解F[0 .. N][0 .. V]，即for循环从下至上求解

	
//     public static void ZeroOnePackNonRecursive(int N, int V, int weight[], int value[], int F[][]) {
//         //对二维数组F进行初始化
//         for(int j = 0; j <= V; j++) {
//             F[0][j] = 0;
//         }
//         System.out.println("\n编号   重量   收益");
//         for(int i=0;i<N;i++){
//             System.out.println(i+"\t  "+weight[i]+"     \t"+value[i]);
//         }
//         //注意边界问题，i是从1开始的，j是从0开始的
//         //因为F[i - 1][j]中i要减1
//         for(int i = 1; i <= N; i++) {
//             for(int j = 0; j <= V; j++) {
//                 //如果容量为j的背包放得下第i个物体
//                 if(j >= weight[i]) {
//                     F[i][j] = Math.max(F[i - 1][j - weight[i]] + value[i], F[i - 1][j]);
//                 }else {
//                     //放不下，只能选择不放第i个物体
//                     F[i][j] = F[i - 1][j];
//                 }
//             }
//         }

//         //打印所有结果，我们要求的是F[N][V]
//         System.out.println("\n0—1背包动态规划表：");
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
//      求解F[n][m]这个最优值具体选取哪几样物品能获得最大价值，但只会输出一种情况
//      表示前n个物体，n <= N;表示背包的容量，v <= V
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
//         System.out.println("选中物品：");
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
//         System.out.println("物品的随机重量：");
//         for(int i=0;i<weight.length;i++) {
//             System.out.print(weight[i] + " ");
//         }
//     }
//     public static void  RandomValue(int value[], int len,int max){
//         //int[] arr=new int[len];
//         for(int i=0;i<value.length;i++){
//             value[i]=(int)(Math.random()*max+1);
//         }
//         System.out.println("物品的随机价值：");
//         for(int i=0;i<value.length;i++) {
//             System.out.print(value[i] + " ");
//         }
//     }

//     public static void main(String[] args) {
//         Scanner sc = new Scanner(System.in);
//         System.out.print("请输入物品个数：");
//         int N = sc.nextInt();
//         System.out.print("请输入背包的最大容量：");
//         int V = sc.nextInt();
//         //下标从1开始，表示第1个物品
//         int weight[] = new int[N + 1];
//         int value[] = new int[N + 1];
//         int  F[][]= new int[N + 1][V + 1];//注意是 N + 1，因为需要一个初始状态F[0][0]，表示前0个物品放进空间为0的背包的最大收益
//         //long startTime = System.currentTimeMillis();//起始时间
//         RandomWeight(weight,N,V);
//         System.out.println();
//         RandomValue(value,N,V);
//         long startTime = System.currentTimeMillis();//起始时间
//         ZeroOnePackNonRecursive(N,V,weight,value,F);
//         printResult(N,V,weight,F);
//         long endTime = System.currentTimeMillis();//结束时间
//         System.out.println("\n算法运行时间： " + (endTime - startTime ) + "ms");
//     }
// }

















 
// //0-1背包问题
// public class Knapsack {
	
// 	public static int knapsack(int[] weight, int[] value, int maxweight){
 
// 		int n = weight.length;
// 		//最大价值数组为maxvalue[N+1][maxWeight+1]，因为我们要从0开始保存
// 		int[][] maxvalue = new int[n+1][maxweight + 1];
		
// 		//重量和物品为0时，价值为0
// 		for (int i = 0; i < maxweight + 1; i++) {
// 			maxvalue[0][i] = 0;
			
// 		}
// 		for (int i = 0; i < n + 1; i++) {
// 			maxvalue[i][0] = 0;
			
// 		}
		
// 		//i：只拿前i件物品（这里的i因为取了0，所以对应到weight和value里面都是i-1号位置）      
// 		//j：假设能取的总重量为j
// 		//n是物品件数
// 		for (int i = 1; i <= n ; i++) {
// 			for (int j = 1; j <= maxweight; j++) {
// 				//当前最大价值等于放上一件的最大价值
// 				maxvalue[i][j] = maxvalue[i-1][j];
// 				//如果当前件的重量小于总重量，可以放进去或者拿出别的东西再放进去
// 				if (weight[i-1] <= j) {
// 					//比较（不放这个物品的价值）和
// 					//（这个物品的价值 加上 当前能放的总重量减去当前物品重量时取前i-1个物品时的对应重量时候的最高价值）
// 					if(maxvalue[i-1][j - weight[i-1]] + value[i-1]>maxvalue[i-1][j]) {
// 						maxvalue[i][j] = maxvalue[i-1][j - weight[i-1]] + value[i-1];
// 					}
// 				}
// 			}
// 		}
// 		return maxvalue[n][maxweight];
// 	}
// 	public static void main(String[] args) {
// 		// TODO 自动生成的方法存根
// 		int weight[] = {2,3,4,5};
// 		int value[] = {3,4,5,7};
// 		int maxweight = 9;
// 		System.out.println(knapsack(weight, value, maxweight));
// 	}
 
// }