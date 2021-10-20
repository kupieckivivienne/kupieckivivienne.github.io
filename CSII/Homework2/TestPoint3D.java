import java.util.*; 

class TestPoint3D 
{ 
	public static void main (String[] args) 
	{ 
		Scanner sc = new Scanner(System.in); 
		Point3D p1 = new Point3D(); 
		p1.Read(sc); 
		p1.Print(); 
		System.out.println("Num of coordinates: "+ p1.GetNumCoordinates()); 

		Point3D p2 = new Point3D(); 
		p2.Read(sc);
		p2.Print();  
		System.out.println("Number of coord: " + p2.GetNumCoordinates()); 


		double distance = p1.GetDistance(p2); 
		System.out.println(distance);  

	} 

} 
