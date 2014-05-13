#include <iostream>
using namespace std;
void tower (int n, char source, char destination, char auxiliary)
{
	//Base Condition
	//when no more disks are left stop
	if (n == 0) {
		return;
	}

	//move the top n-1 disks from source to auxiliary
	tower (n - 1, source, auxiliary, destination);
	
	// move the nth disk from source to destination
	cout << "Move the disk " << n << " from " << source << " to " << destination << endl; 
	
	//move the remaining n-1 disks from auxiliary pole to the destination pole
	tower(n - 1, auxiliary, destination, source);//

}

int main()
{
	/*
	*	  source     Auxiliary       Destination
	*		|		   	|			     |
	*	   -|-		   	|			     |
	*	  --|--		   	|			     |
	*    ---|---	   	|			     |
	*_______|___________|________________|____
	*
	*
	*/
	int n;
	cout << "Enter the no of disks" << endl;;
	cin >> n;
   // Assuming n-th disk is bottom disk (count down)
   tower(n, 'S', 'D', 'A');
   return 0;
}

