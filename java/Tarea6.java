import java.util.Random;
import java.util.Arrays;
import java.util.Scanner;

public class Tarea6{
	public static void main(String[] args){
		System.out.println("Number of elements to be sorted: ");
		Scanner in = new Scanner(System.in);
		int num = in.nextInt();

		int a[] = permutacion(num);
		int b[] =  Arrays.copyOf(a, a.length);

		Mergesort m = new Mergesort();
		QuicksortClassic q1 = new QuicksortClassic();
		QuicksortMedian q2 = new QuicksortMedian();
		QuicksortMedianInsert q3 = new QuicksortMedianInsert();

		long t = System.nanoTime();
		m.ordenar(a);
		long t1 = System.nanoTime()-t;

		a = Arrays.copyOf(b, b.length);
		t = System.nanoTime();
		q1.ordenar(a);
		long t2 = System.nanoTime()-t;

		a = Arrays.copyOf(b, b.length);
		t = System.nanoTime();
		q2.ordenar(a);
		long t3 = System.nanoTime()-t;

		a = Arrays.copyOf(b, b.length);
		t = System.nanoTime();
		q3.ordenar(a);
		long t4 = System.nanoTime()-t;
		
		System.out.println("t1 = "+t1);
		System.out.println("t2 = "+t2);
		System.out.println("t3 = "+t3);
		System.out.println("t4 = "+t4);
	}
	static public int[] permutacion(int n){
		int[] a = new int[n];
		for(int i = 0 ; i < n; ++i){
			a[i]=i+1;
		}
		Random rnd = new Random();
		for(int i = 0; i < n; i++){
			int r = i + rnd.nextInt(n-i);
			int temp = a[i];
			a[i] = a[r];
			a[r] = temp;
		}
		return a;
	}
}