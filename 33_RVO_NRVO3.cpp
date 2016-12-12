
// without NRVO
Point foo(Point& temp)	// main�� ����� �� �ӽ� ��ü�� ���� ��
{
	Point p;
	p.x = 10;
	p.y = 20;
	return p;	//temp�� p�� ���� �����ڷ� �������ش�.
				// temp.Point::Point(p);
}

int main()
{
	Point p;
	p = foo();  // �ӽ� ��ü�� �޸𸮸� �Ҵ��ؼ� foo�� ���ڷ� ����
	
	// Point temp; // ������ ���� �޸𸮸� �Ҵ�.
	// foo( temp )
	// p.Point::Point(temp)
	// temp.Point::~Point()
}


// with VRVO
Point foo(Point& temp)
{
	// Point p;
	p.x = 10;	// �� ���� ��¥ p�� ���� main�� ������ temp�� �ִ´�.
	p.y = 20;	// temp.y = 20
	return p;	// return temp
}

int main()
{
	Point p;
	p = foo();  // �ӽ� ��ü�� �޸𸮸� �Ҵ��ؼ� foo�� ���ڷ� ����

	// Point temp; // ������ ���� �޸𸮸� �Ҵ�.
	// foo( temp )
	// p.Point::Point(temp)
	// temp.Point::~Point()
}