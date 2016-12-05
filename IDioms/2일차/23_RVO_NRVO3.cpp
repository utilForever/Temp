
// without NRVO
Point foo()
{
	Point p;
	p.x = 10;
	p.y = 20;
	return p;
}

int main()
{
	Point p;
	p = foo();  
	
	// Point temp; // 생성자 없이 메모리만 할당.
	// foo( temp )
	// p.Point::Point(temp)
	// temp.Point::~Point()
}


// with VRVO
Point foo()
{
	Point p;
	p.x = 10;
	p.y = 20;
	return p; 
}
