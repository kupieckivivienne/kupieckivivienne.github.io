import java.util.Random; 
class Test 
{ 
	public static void main(String[] args) 
	{ 

 		
		// size 
		int size = Integer.parseInt(args[1]); 
		int v[] = new int[size]; 
		// initialize random class 
		Random rand = new Random(); 

		// make a for loop for randomization 
		for (int i = 0; i<v.length; i++) 
		{ 
			// create random integers 
			v[i] = rand.nextInt(); 
		} 
		String algorithm = args[0]; 
		if (algorithm.equals("selection")) 
			SelectionSort.Sort(v); 
		else if(algorithm.equals("merge")) 
			SelectionSort.Sort(v); 
		else 
			System.out.println("Invalid sorting method."); 
	} 


} 
