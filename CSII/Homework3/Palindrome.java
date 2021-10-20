import java.util.Scanner; 
class Palindrome 
{ 

	public static boolean IsPalindrome(String string) 
	{
		// checking the base case  
		if(string.length() == 0 || string.length() == 1) 
			return true;
		// chesk if the character at the beginning of the string is the same as the character at the end of the string 
		 if(string.charAt(0) == string.charAt(string.length()-1)) 
			// using recursion to check the middle of the string 
			return IsPalindrome(string.substring(1, string.length()-1)); 	
		
		return false; 
	} 
	public static void main(String[] args) 
	{ 
		Scanner sc = new Scanner(System.in); 
		System.out.println("Enter a string: "); 
		String stringInput = sc.nextLine(); 

		// invoke function 
		if(IsPalindrome(stringInput) == true) 
			System.out.println("The string, " + stringInput + " is a palindrome."); 
		else 
			System.out.println("The string, " + stringInput + " is not a palindrome.");

 
	}
} 
