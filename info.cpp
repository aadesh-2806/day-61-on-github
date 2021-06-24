int a = 1;      // 0001b 
int b = a << 1; // 0010b
C-style bit-manipulation 
template <typename T> 
T rightmostSetBitRemoved(T n) 
{   
	// static_assert(std::is_integral<T>::value && !std::is_signed<T>::value, "type should be unsigned");
	// For c++11 and later    
	return n & (n - 1); 
}

///////////////////////////////////////////////////////////////////////////
Explanation
if n is zero, we have 0 & 0xFF..FF which is zero 
else n can be written 0bxxxxxx10..00 and n - 1 is 0bxxxxxx011..11, so n & (n - 1) is 0bxxxxxx000..00. 

 +---+---+---+---+---+---+---+ 
 |   | 1 | 2 | 3 | 4 | 5 |   | 
 +---+---+---+---+---+---+---+ 
   ^   ^                ^   ^   
   |   |                |   | 
rend() |         rbegin()  end()      
       |                   rbegin().base()
	  begin()     
	  rend().base()

In the visualization where iterators mark positions between elements, the relationship is simpler:
  +---+---+---+---+---+ 
  | 1 | 2 | 3 | 4 | 5 | 
  +---+---+---+---+---+ 
  ^                   ^ 
  |                   | 
  |                 end() 
  |                 rbegin() 
  begin()           rbegin().base() 
  rend() 
  rend().base()

///////////////////////////////////////////////////////////////////////////
for (std::vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)  

///////////////////////////////////////////////////////////////////////////
Mode   Meaning   For            Description 
app    append   Output        Appends data at the end of the ?le. 
binary binary Input/Output    Input and output is done in binary. 
in     input    Input         Opens the ?le for reading. 
out    output   Output        Opens the ?le for writing. 
trunc truncate Input/Output   Removes contents of the ?le when opening. 
ate    at end     Input       Goes to the end of the ?le when opening.

///////////////////////////////////////////////////////////////////////////
#include <sstream> 
#include <string>
using namespace std;
int main() 
{  
	ostringstream ss;    
	ss << "the answer to everything is " << 42;
	const string result = ss.str(); 
} 
(the string result will be equal to "the answer to everything is 42").

///////////////////////////////////////////////////////////////////////////
std::vector<int> v = {1,2,3,4}; 
std::copy(v.begin(), v.end(), std::ostream_iterator<float>(std::cout, " ! "));
1.000 ! 2.000 ! 3.000 ! 4.000 !

///////////////////////////////////////////////////////////////////////////
decltype
Yields the type of its operand, which is not evaluated.
If the operand e is a name without any additional
parentheses, then decltype(e) is the declared type of e.

int x = 42;
std::vector<decltype(x)> v(100, x); 
// v is a vector<int>

If the operand e is a class member access without 
any additional parentheses, then decltype(e) is 
the declared type of the member accessed.

struct S 
{ int x = 42; };
const S s; 
decltype(s.x) y; 
// y has type int, even though s.x is const

In all other cases, decltype(e) yields both the 
type and the value category of the expression e,
as follows:
	a  If e is an lvalue of type T, then decltype(e) is T&.
	b  If e is an xvalue of type T, then decltype(e) is T&&.
	c  If e is a prvalue of type T, then decltype(e) is T.

This includes the case with extraneous parentheses.

int f() 
	return 42; 

int& g() 
{ 
	static int x = 42; 
	return x; 
} 
int x = 42; decltype(f()) 
a = f();   // a has type int decltype(g()) 
b = g();   // b has type int& decltype((x)) 
c = x;     // c has type int&, since x is an lvalue

///////////////////////////////////////////////////////////////////////////
Version >= C++14
The special form decltype(auto) deduces the type
of a variable from its initializer or the return 
type of a function from the return statements in 
its de?nition, using the type deduction rules of 
decltype rather than those of auto.

const int x = 123; 
auto y = x;   // y has type int decltype(auto) 
z = x;       // z has type const int, the declared type of x 

///////////////////////////////////////////////////////////////////////////
try 
	{  
	  std::vector<int> v(N);    // do something 
	} 
	catch (const std::bad_alloc&) 
	{    
		std::cout << "failed to allocate memory for vector!" << std::endl; 
	} 
	catch (const std::runtime_error& e) 
	{    
		std::cout << "runtime error: " << e.what() << std::endl; 
	} 
	catch (...) //catch all from throw;
	{    
		std::cout << "unexpected exception!" << std::endl;   
		throw; 
	} 

///////////////////////////////////////////////////////////////////////////
#include<fstream>		//scan from  file //each word unique
{	
	ifstream file;	//file("hello.txt",ios::app);//for retaining previous data;
	file.open("helldo.txt");
	
	//file.is_open  if file is open or running
	
	string input;
	while(file>>input)		//place vector
	{
		cout<<input<<endl;
	}
	
	string line;
	char t = file.get();
	cout<<t<<endl;//first char of file printd
	getline(file,line);
	cout<<line<<endl;
	//first line of text till \n;
	//.c_string optional like cin<<fi  ofstream file(fi.c_string())
	file.close();
}

///////////////////////////////////////////////////////////////////////////
#include<fstream>	//print in file

{	
	ofstream file;//file("hello.txt",ios::app);//for retaining previous data;
	file.open("helldo.txt");
	//file.is_open  if file is open or running
	file<<"heyyysfsf"<<endl;
	file<<"heyyysfsf"<<endl;
	file<<"heyyysfsf"<<endl;
	//.c_string optional like cin<<fi  ofstream file(fi.c_string())
	file.close();
}

///////////////////////////////////////////////////////////////////////////
const char16_t message[] = u"??,??\\n";
//1->2 more 1 ++2
cout << sizeof(message)/sizeof(char16_t) << "\\n"; 
			^				^
			16				2
// prints 7 

const char32_t full_house[] = U" ";
// non-BMP characters 
//1->4 more 1 ++4
cout << sizeof(full_house)/sizeof(char32_t) << "\\n"; 
				^				^
				8				4
// prints 6 

///////////////////////////////////////////////////////////////////////////
Foo foo2 = foo; // Copy Constructor called
Foo foo2(42);
foo = foo2; // Assignment Operator Called

///////////////////////////////////////////////////////////////////////////
v.assign(4, 100); //v becomes {100, 100, 100, 100}

vector<int> v{ 1, 2, 3 };
v.pop_back();// v becomes {1, 2} 
//delete elements from last

v.clear();//v becomes an empty vector

v{ 1, 2, 3, 4, 5, 6 };
v.erase(v.begin() + 3);v becomes {1, 2, 3, 5, 6}

v.erase(v.begin() + 1, v.begin() + 5);// v becomes {1, 6}

v.erase(std::remove(v.begin(), v.end(), v_remove), v.end());
// v becomes {1, 1, 3, 3}

///////////////////////////////////////////////////////////////////////////
//lambda expression
bool _predicate(const int& element)
{    
	return (element > 3); 
	// This will cause all elements to be deleted that are larger than 3 
}

v{ 1, 2, 3, 4, 5, 6 };
v.erase(remove_if(v.begin(), v.end(), _predicate), v.end()); 
// v becomes {1, 2, 3} 

///////////////////////////////////////////////////////////////////////////
for(auto it=begin(v);it!=end(v); ++it)
	cout << *it << "\n"; 

///////////////////////////////////////////////////////////////////////////
inline int add(int x, int y) 
   return x + y;

int main() 
{    
	int a = 1, b = 2;
	int c = add(a, b); 
}
//look like-
int main() 
{
	int a = 1, b = 2;    
	int c = a + b; //inlined
}

///////////////////////////////////////////////////////////////////////////
int values[5] = { 1, 2, 3, 4, 5 }; // source array
vector<int> v(begin(values),end(values));
// copy array to new vector
for(auto &x: v)
    cout << x << " ";

