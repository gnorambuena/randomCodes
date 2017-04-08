package hello;

import java.util.Scanner;

public class AuxP2 {

	private static Scanner s;
	public static void main(String[] args) {
		s = new Scanner(System.in);
		String str=s.nextLine();
		System.out.println(esPalindrome(borrar(' ',str.toLowerCase())));
	}
	public static boolean esPalindrome(String s){
		for (int i=0;i<s.length()/2;i++){
			if(s.charAt(i)!=s.charAt(s.length()-i-1)){
				return false;
			}
		}
		return true;
	}
	public static String borrar(char c, String s){
		String res="";
		for(int i=0;i<s.length();i++){
			if(s.charAt(i)!=c){
				res+=s.charAt(i);
			}
		}
		return res;
	}
}
