public class Mergesort implements Ordenacion{
	public void ordenar(int[] a){
		sort(a,0,a.length);
	}
	private void sort(int[] arr, int i,int j){
		if(j-i < 2)return;
		int mid = (j+i)/2;
		sort(arr,i,mid);
		sort(arr,mid,j);
		merge(arr,i,mid,j);
	}
	private void merge(int[] arr,int i,int mid,int j){
		int left = i,right = mid,k;
		int[] aux = new int[j-i];
		for(k = 0; k < aux.length && (left < mid && right < j); k++){
			if(arr[left] <= arr[right]){
				aux[k] = arr[left++];
			}
			else{
				aux[k] = arr[right++];
			}
		}
		if(k<aux.length){
			if(left == mid){
				for(; k < aux.length ; k++){
					aux[k] = arr[right++];
				}
			}
			else if(right == j){
				for(; k < aux.length ; k++){
					aux[k] = arr[left++];
				}
			}
		}
		k=0;
		for(; i < j ; i++){
			arr[i]=aux[k++];
		}
	}
}