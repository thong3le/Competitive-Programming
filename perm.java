import java.util.*;

public class perm {
	
	int[] numbers;

	public perm(int n){
		numbers = new int[n];

		for (int i = 1; i <= n; i++){
			numbers[i-1] = i;
		}


	}

	

	public static void main(String[] args){

	}


}