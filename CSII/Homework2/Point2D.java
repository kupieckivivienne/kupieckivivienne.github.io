import java.lang.*; 
import java.util.Scanner; 
class Point2D extends Point 
{ 
	private double x; 
	private double y; 
	

	public void Read(Scanner sc) 
	{ 
		
		super.Read(sc);  
		System.out.println("Enter X:"); 
		x = sc.nextDouble(); 
		System.out.println("Enter Y:"); 
		y = sc.nextDouble(); 
	}
	
	public void Print()
	{ 	
		super.Print(); 
		System.out.println("X: " + x); 
		System.out.println("X: " + y); 
	}
	
	public int GetNumCoordinates() 
	{ 
		return 2; 
	}

	public double GetDistance(Point2D other) 
	{   
		double d; 
		d = Math.sqrt((other.x -x) *(other.x-x) + (other.y - y)*(other.y - y)) ; 
		return d; 
	} 

} 
