#include <iostream>

using namespace std;

class polygon{

protected:
	int width, height;

public:
	void setValues(int width, int height){
		this->width = width;
		this->height = height;
	}

};

class output1{
public:
	void output(int i);
};


void output1::output(int i){
	cout << i << endl;
}

class rectangle: public polygon, public output1{

public:
	int area(){;
	return width*height;
	}
};

int main()
{

	rectangle rec1;
	rec1.setValues(4, 5);
	rec1.output(rec1.area());


   return 0;
}


