public class Solution {


	public static void main(String[] args) {
		
		/* Your class should be named Solution.
	 	* Read input as specified in the question.
	 	* Print output as specified in the question.
		*/

		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		if(n == 1 || n == 2) {
			System.out.println(1);
			return;
		}

		int f1 = 1;
		int f2 = 1;
        int fn = 2;

		for(int idx=0; idx<n-2; idx++){
			fn = f1 + f2;
			f1 = f2;
			f2 = fn;
		}

        System.out.println(fn);
		
	}

}
