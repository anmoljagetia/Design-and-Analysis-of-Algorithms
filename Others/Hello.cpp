#include <iostream>
#include <stdio.h>

using namespace std;

int main(void)
{
	int n, p;
	n = 3;
	p = 9;
	cin>>p;
	printf("%d\n", max(p,3));
	//cout<<"Hello World"<<endl;
	return 0;
}

/*
Hash Map Implementation
*/

// #include <map> 
// #include <iostream> 
// using namespace std; 		
// int main( )
// { 
//       map<int, int> m;
//       map <int, int> :: value_type value1;
//       map <int, int> :: iterator it;
//       // value_type can be used to pass the correct type 
//       // explicitly to avoid implicit type conversion 
// 	  m.insert ( map <int, int> :: value_type( 1, 10 ) ); 
// 	  m.insert ( pair<const int, int> ( 2, 20 ) );
// 	  m[ 3 ] = 30;
//       // The following line would cause an error because
//       // the value_type is not assignable
//       // value1 = pair<const int, int> ( 4, 40 ); 
//       cout  << "Keys of Mapped elements :";
//       for(it = m.begin( ); it != m.end( ); it++) { 
//             cout << " " << it -> first; 
//       } 
//       cout << endl;  
//       cout  << "Values of the Mapped elements :"; 
//       for (it = m.begin( ); it != m.end( ); it++ ) { 
//             cout << " " << it -> second; 
//       } 
//       cout << endl; 
//       return 0; 
// }



