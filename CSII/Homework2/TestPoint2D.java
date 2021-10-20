import java.util.Scanner; 
class TestPoint2D 
{ 
	public static void main(String[] args) 
	{ 
		Scanner sc = new Scanner(System.in); 
		Point2D a = new Point2D();
		a.Read(sc);
		a.Print();  
		System.out.println("Number of coordinates: " + a.GetNumCoordinates()); 

		Point2D b = new Point2D();
		b.Read(sc); 
		b.Print();  
		System.out.println("Number of coordinates : " + b.GetNumCoordinates()); 
	
		double d = a.GetDistance(b);
		System.out.println("Distance: " + d);  
	} 
} 
