import java.util.*; 
abstract class Point 
{ 
	private String name; 
	
	public void Print() 
	{ 
		System.out.println("Point name: " + name); 
	}

	public void Read(Scanner sc) 
	{  	
		System.out.println("ENTER NAME: " ); 
		name = sc.nextLine();  
	}
	
	public int GetNumCoordinates() 
	{ 
		int i = 1; 
		return i;   
	} 


} 
