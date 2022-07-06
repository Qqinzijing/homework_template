import java.util.Arrays;
import java.util.Random;

public class MyRandom {
	public static void main(String[] args) {
		
		Random myRandom = new Random();		
		int[] luckNums = new int[16];
			
		//生成16个不同的随机数
		for(int i=0; i<16; i++) {
			//在1到44之间取随机数
			int randomNum = myRandom.nextInt(44) + 1;
			while(existed(randomNum, luckNums, i)) {
				randomNum = myRandom.nextInt(44) + 1;
			}
			luckNums[i] = randomNum;
		}
		
		//进行排序
		//Arrays.sort(luckNums);
		for(int i=0;i<luckNums.length-1;i++) {
			for(int j=0;j<luckNums.length-i-1;j++) {
				if(luckNums[j]>luckNums[j+1]) {
					int temp=luckNums[j];
					luckNums[j]=luckNums[j+1];
					luckNums[j+1]=temp;
				}
				
			}
		}

		//输出抽取情况
		System.out.println("排序后的随机数数组:");
		for(int item : luckNums) {
			System.out.print(item + " ");
		}
	}
}