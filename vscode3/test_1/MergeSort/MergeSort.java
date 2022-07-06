/*
   �鲢����Javaʵ��
   ѧ�ţ�20201050470
   ʱ�临�Ӷȣ�O(nlog2n)
*/
import java.util.Scanner;
public class MergeSort {
    public static void main(String[] args) {
        MergeSort_1 p = new MergeSort_1();
        p.InitMerage();
       
    }

}

class MergeSort_1{
    int sum=0;//��¼�Ƚϴ���
    public void Merge(int[] list,int p,int q,int r){
        int[] tmp = new int[r-p+1];//����һ����ʱ���飬����ΪҪ�鲢����ĳ���
        int i = p;   //��ס��������һ��Ԫ�ص��±�
        int j = q+1; //��ס�ұ������һ��Ԫ�ص��±�
        int k = 0;     
        
        while(i <= q && j <= r){
            //�������Ԫ�غ��ұ�����Ԫ�رȽϣ���С��Ԫ�ظ�����ʱ����
            if(list[i] <=list[j]){               
                tmp[k++] = list[i++];
            }
            else{               
                tmp[k++] =list[j++];
            }
        }
        //�����ʣ�������Ԫ�ظ�����ʱ����
        while(i <= q){          
            tmp[k++] = list[i++];
        }
        //���ұ�ʣ�������Ԫ�ظ�����ʱ����
        while(j <= r){          
            tmp[k++] = list[j++];
        }
        //����ʱ����Ԫ�ظ���ԭ����Ԫ��
        for(int k2 = 0;k2 < tmp.length;k2++){           
           list[k2+p] = tmp[k2]; 
        }
        sum=sum+q-p+1;
        // System.out.println("\n�Ƚϴ�����"+sum);
    }
    public void Merge_sort(int[]list,int p,int r){//pΪ��ʼλ�ã�rΪ����λ��
        int q = (p+r)/2;//qΪ����λ��
        if(p < r){
            //�ݹ����          
            Merge_sort(list,p,q);//�ݹ���ǰ�벿��
            Merge_sort(list,q + 1,r);//�ݹ�����벿��
            //�鲢��������Ԫ��
            Merge(list,p,q,r);//�����������������ɹ鲢
        }
    }
   public int[]  RandomArray(int len,int max){
			int[] arr=new int[len];
			for(int i=0;i<arr.length;i++){
				arr[i]=(int)(Math.random()*max);
			}
			return arr;
	}
    public void InitMerage(){
        Scanner input=new Scanner(System.in);
        System.out.print("���������鳤�ȣ�");
        int n=input.nextInt();
        //int sum=0;
		int []arr=RandomArray(n, 10000);
        System.out.println("����ǰ�����飺");
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i]+" ");
		}
        Merge_sort(arr,0,arr.length -1);//������A��0λ��A.length-1λ����
        System.out.println("\n�ϲ������Ľ���� ");
        for(int i = 0;i < arr.length;i++){
            System.out.print(arr[i] + " ");
        }
        System.out.println("\n�Ƚϴ�����"+sum);
    }

}