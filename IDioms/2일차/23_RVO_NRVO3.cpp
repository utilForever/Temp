
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
	
	// Point temp; // ������ ���� �޸𸮸� �Ҵ�.
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
