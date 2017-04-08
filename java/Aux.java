
public class Aux{
		public static void main(String[] args){
			int[] arr={1,2,3,4,5,6,7};
			int dist_max=0;
			int max,min;
			max=min=arr[0];
			for(int i=0;i<arr.length;i++){
				if(arr[i]<min){
					min=arr[i];
				}
				if(arr[i]>max){
					max=arr[i];
				}
				dist_max=max-min;
			}
			System.out.println(dist_max);
		}
	}


