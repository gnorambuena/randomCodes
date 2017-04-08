import java.util.Random;

public class QuicksortMedian implements Ordenacion{
	public void ordenar(int[] a){
		sort( a, 0, a.length-1);
	}
	private void sort(int[] arr, int i,int j){
		if(j < i)return;
		int piv = pivot(arr,i,j);
		int p = partition(piv,i,j,arr);
		sort(arr , i, p-1);
		sort(arr, p+1, j);
	}
	private int pivot(int[] arr , int i , int j){
		Random randomGenerator = new Random();
		int a = randomGenerator.nextInt(j-i+1) + i;
		int b = randomGenerator.nextInt(j-i+1) + i;
		int c = randomGenerator.nextInt(j-i+1) + i;
		int med = arr[a] + arr[b] + arr[c] - Math.max( arr[a], Math.max(arr[b],arr[c]))
		- Math.min(arr[a] , Math.min(arr[b] , arr[c]));
		if(arr[a] == med) return a;
		if(arr[b] == med) return b;
		return c;
	}
	private int partition(int pivot, int lo, int hi, int[] arr){
		int aux = arr[pivot];
		arr[pivot] = arr[hi];
		arr[hi] = aux;
		int i = lo;
		for(int j = lo ; j < hi ; j++){
			if(arr[j] <= aux){
				int s = arr[i];
				arr[i] = arr[j];
				arr[j] = s;
				i++;
			}
		}
		int s = arr[i];
		arr[i] = arr[hi];
		arr[hi] = s;
		return i;
	}
}