/*
    ��������Javaʵ��
    ѧ�ţ�20201050470
    ʱ�临�Ӷȣ�O(nlog(n))
*/
import java.util.Scanner;

public class QuickSort {
    public static void main(String[] args) {
        QuickSortAlgorithm qs = new QuickSortAlgorithm();
        Scanner sc = new Scanner(System.in);
        System.out.print("����������ĳ��ȣ�");
        int n = sc.nextInt();
        int [] a=qs.RandomArray(n,100000);   //�����������
        System.out.println("�������");
        for (int j : a) {
            System.out.print(j+" ");
        }
        System.out.println();
        qs.quickSort(a,0,a.length-1);
        System.out.println("�����������ɵķǽ�������");
        for (int j : a) {
            System.out.print(j+" ");
        }
    }
}
class QuickSortAlgorithm {
    int[]  RandomArray(int len,int max) {
        int[] arr = new int[len];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = (int) (Math.random() * max);
        }
         return arr;
 }
    //��������
    void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pivot = partition(arr, low, high);
            quickSort(arr, low, pivot - 1);
            quickSort(arr, pivot + 1, high);
        }
    }
    //����
    int partition(int[] arr, int low, int high) {
        int pivotkey = arr[low];
        while (low < high) {
            while (low < high && arr[high] >= pivotkey) {
                high--;
            }
            arr[low] = arr[high];
            while (low < high && arr[low] <= pivotkey) {
                low++;
            }
            arr[high] = arr[low];
        }
        arr[low] = pivotkey;
        return low;
    }
}














// import java.util.Scanner;
// public class QuickSort {
//     public static void main(String[] args) {
//         QuickSortAlgorithm qs = new QuickSortAlgorithm();
//         int[] a = qs.randlist(10,2,3,1,10);
//         System.out.println("�������");
//         for (int j : a) System.out.print(j);
//         System.out.println();
//         qs.quickSort(a,0,a.length-1);
//         System.out.println("�ǽ�������");
//         for (int j : a) System.out.print(j);
//     }
// }
// class QuickSortAlgorithm {
//     int[] randlist(int m, int a, int c, int x0, int n) {   //��������ͬ������
//         int[] x = new int[n];
//         x[0] = x0;
//         for (int i = 1; i < n; i++) {
//             x[i] = (a * x[i - 1] + c) % m;
//         }
//         return x;
//     }
//     //��������
//     void quickSort(int[] arr, int low, int high) {
//         if (low < high) {
//             int pivot = partition(arr, low, high);
//             quickSort(arr, low, pivot - 1);
//             quickSort(arr, pivot + 1, high);
//         }
//     }
//     //����
//     int partition(int[] arr, int low, int high) {
//         int pivotkey = arr[low];
//         while (low < high) {
//             while (low < high && arr[high] >= pivotkey) {
//                 high--;
//             }
//             arr[low] = arr[high];
//             while (low < high && arr[low] <= pivotkey) {
//                 low++;
//             }
//             arr[high] = arr[low];
//         }
//         arr[low] = pivotkey;
//         return low;
//     }
// }