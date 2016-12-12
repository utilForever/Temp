
// without NRVO
Point foo(Point& temp)	// main이 만들어 준 임시 객체를 받은 후
{
	Point p;
	p.x = 10;
	p.y = 20;
	return p;	//temp를 p에 복사 생성자로 복사해준다.
				// temp.Point::Point(p);
}

int main()
{
	Point p;
	p = foo();  // 임시 객체를 메모리만 할당해서 foo의 인자로 전달
	
	// Point temp; // 생성자 없이 메모리만 할당.
	// foo( temp )
	// p.Point::Point(temp)
	// temp.Point::~Point()
}


// with VRVO
Point foo(Point& temp)
{
	// Point p;
	p.x = 10;	// 이 순간 진짜 p는 없고 main이 보내준 temp에 넣는다.
	p.y = 20;	// temp.y = 20
	return p;	// return temp
}

int main()
{
	Point p;
	p = foo();  // 임시 객체를 메모리만 할당해서 foo의 인자로 전달

	// Point temp; // 생성자 없이 메모리만 할당.
	// foo( temp )
	// p.Point::Point(temp)
	// temp.Point::~Point()
}