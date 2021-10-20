import java.util.Scanner; 
import java.lang.Math; 
 class Point3D extends Point 
{ 
	private double x; 
	private double y; 
	private double z; 

	public void Read(Scanner sc) 
	{ 
		super.Read(sc);
		System.out.println("Enter X: "); 
		x = sc.nextDouble(); 
		System.out.println("Enter Y: "); 
		y = sc.nextDouble(); 
		System.out.println("Enter Z: "); 
		z = sc.nextDouble(); 
	} 

	public void Print() 
	{ 
		super.Print(); 
		System.out.println("X: " + x); 
		System.out.println("Y: " + y); 
		System.out.println("Z: " + z); 
	} 
	public int GetNumCoordinates() 
	{ 
		return 3; 

	} 
	public double GetDistance(Point3D other) 
	{ 
		double d; 
		d = Math.sqrt((other.x - x) *(other.x - x) + (other.y - y)* (other.y - y) + (other.z - z)); 
		return d; 
	} 
} 
