class SelectionSort 
{ 
	//  identify sub problems 
	static int GetMinIndex(int v[], int left, int right) 
	{ 
		// asume left is min value 
		int min_index = left;

		for (int i = left+1 ; i<= right; i ++ ) 
	 	{
			if (v[i] < v[min_index]) 
				min_index = i;
		}  
		return min_index; 
	} 

	static void Swap(int v[], int index1,int index2) 
	{ 
		int temp = v[index1]; 
		v[index1] = v[index2]; 
		v[index2] = temp; 
	} 

	public static void Sort(int v[]) 
	{ 
		// runs n - 1 iteratitons 
		for(int i = 0; i< v.length - 1; i ++ ) 
		{ 
			// find position of minimum value in unsorted region 
			int min_index = GetMinIndex(v, i, v.length - 1); 
			
			// swap with first element of unsorted region. 
			Swap(v, min_index, i );
		} 
	} 

} 
