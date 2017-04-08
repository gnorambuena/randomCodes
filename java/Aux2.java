package hello;

public class Aux2 {
	public static void invertirArreglo(int[]arr){
		int temp;
		int l=arr.length;
		for(int i=0;i<l/2;i++){
			temp=arr[i];
			arr[i]=arr[l-i-1];
			arr[l-i-1]=temp;
		}
	}
	public static void main(){
		int[] arr={1,2,3,4,5};
		invertirArreglo(arr);
		for(int i=0;i<arr.length;i++){
			System.out.print(arr[i]);
		}
	}
}
