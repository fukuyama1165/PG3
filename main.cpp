#include <stdio.h>
#include <string>
#include <stdexcept>
#include <iostream>
#include <iomanip>

class IShape
{
public:
	IShape();
	~IShape();

	virtual void Size() = 0;
	virtual void Draw() = 0;

private:

};

IShape::IShape()
{
}

IShape::~IShape()
{
}

class Circle:public IShape
{
public:
	Circle();
	~Circle();

	void Size() override;
	void Draw() override;

	void SetR(float r) { this->r = r; };

private:

	float r = 1;
	float area = 3.14159f;
};

Circle::Circle()
{
}

Circle::~Circle()
{
}

void Circle::Size()
{

	area = r * r * 3.14159f;

}

void Circle::Draw()
{

	std::cout << "�~�̖ʐ� : " << area << '\n';

}

class Rectangle :public IShape
{
public:
	Rectangle();
	~Rectangle();

	void Size() override;
	void Draw() override;

	void SetW(float w) { this->w = w; };
	void SetH(float h) { this->h = h; };

private:

	float w = 1;
	float h = 1;

	float area = 1;

};

Rectangle::Rectangle()
{
}

Rectangle::~Rectangle()
{
}

void Rectangle::Size()
{

	area = h * w;

}

void Rectangle::Draw()
{

	std::cout << "��`�̖ʐ� : " << area << '\n';

}

int main()
{

	int selectmenu = 0;
	
	float setNum = 0;

	bool isEnd = false;

	Circle circle;
	Rectangle rect;
	

	while (true)
	{

		std::cout << "[����]" << '\n';
		std::cout << "1.�~�̔��a�C��" << '\n';
		std::cout << "2.��`�̏C��" << '\n';
		std::cout << "3.�ʐς̌v�Z" << '\n';
		std::cout << "4.�ʐϕ`��" << '\n';
		std::cout << "���̑�:�I��" << '\n';

		std::cout << "\n------------------------------------------" << '\n';
		std::cout << "�����I�����Ă�������" << '\n';

		std::cin >> selectmenu;
		std::cin.ignore(1024, '\n');

		switch (selectmenu)
		{
		case 1:

			std::cout << "�ύX���锼�a�̒l����͂��Ă�������" << '\n';
			std::cin >> std::setw(256) >> setNum;
			circle.SetR(setNum);
			std::cin.ignore(1024, '\n');

			std::cout << "�ʐς��v�Z���܂�" << '\n';
			circle.Size();

			break;

		case 2:

			std::cout << "�ύX���鉡���̒l����͂��Ă�������" << '\n';
			std::cin >> std::setw(256) >> setNum;
			rect.SetW(setNum);
			std::cin.ignore(1024, '\n');

			std::cout << "�ύX����c���̒l����͂��Ă�������" << '\n';
			std::cin >> std::setw(256) >> setNum;
			rect.SetH(setNum);
			std::cin.ignore(1024, '\n');

			std::cout << "�ʐς��v�Z���܂�" << '\n';
			rect.Size();
			
			break;
		case 3:

			std::cout << "�~�Ƌ�`�̖ʐς��v�Z���܂�" << '\n';
			circle.Size();
			rect.Size();
			
			break;
		case 4:
			
			circle.Draw();
			rect.Draw();

			break;
		default:
			std::cout << "�I�����܂�" << '\n';
			isEnd = true;
			break;
		}
		if (isEnd)
		{
			break;
		}

		

	}


	system("pause");
	return 0;

}