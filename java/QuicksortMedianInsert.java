import java.util.Random;

public class QuicksortMedianInsert implements Ordenacion{
	public void ordenar(int[] a){
		sort(a,0,a.length-1);
	}
	private void sort(int[] arr, int i,int j){
		if(j<i)return;
		//if size of range is less than 10, do a insertion sort
		if(j-i<10){
			insertionSort(arr,i,j);
			return;
		}
		int piv = pivot(arr,i,j);
		int p=partition(piv,i,j,arr);
		sort(arr , i, p-1);
		sort(arr, p+1, j);
	}

	private int pivot(int[] arr,int i , int j){
		Random randomGenerator = new Random();
		int a = randomGenerator.nextInt(j-i+1)+i;
		int b = randomGenerator.nextInt(j-i+1)+i;
		int c = randomGenerator.nextInt(j-i+1)+i;
		//pick median of arr[a],arr[b],arr[c]
		int med = arr[a] + arr[b] + arr[c] - Math.max( arr[a], Math.max(arr[b],arr[c]))
		- Math.min(arr[a] , Math.min(arr[b] , arr[c]));
		if(arr[a] == med) return a;
		if(arr[b] == med) return b;
		return c;
	}

	private int partition(int pivot, int lo, int hi, int[] arr){
		//put pivot at end of array
		int aux = arr[pivot];
		arr[pivot]=arr[hi];
		arr[hi]=aux;

		int i = lo;
		for(int j = lo ; j < hi ; j++){
			if(arr[j] <= aux){
				//swap of arr[i] and arr[j]
				int s = arr[i];
				arr[i] = arr[j];
				arr[j] = s;
				i++;
			}
		}
		int s = arr[i];
		arr[i] = arr[hi];
		arr[hi] = s;
		//return index of pivot
		return i;
	}

	private void insertionSort(int arr[],int lo,int hi){
		for(int i=lo+1;i<=hi;i++){
			int x = arr[i];
			int j = i-1;
			for(; j>=lo && arr[j] > x; j--){
				arr[j+1] = arr[j];
			}
			arr[j+1] = x;
		}
	}

}