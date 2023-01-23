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

	std::cout << "円の面積 : " << area << '\n';

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

	std::cout << "矩形の面積 : " << area << '\n';

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

		std::cout << "[操作]" << '\n';
		std::cout << "1.円の半径修正" << '\n';
		std::cout << "2.矩形の修正" << '\n';
		std::cout << "3.面積の計算" << '\n';
		std::cout << "4.面積描画" << '\n';
		std::cout << "その他:終了" << '\n';

		std::cout << "\n------------------------------------------" << '\n';
		std::cout << "操作を選択してください" << '\n';

		std::cin >> selectmenu;
		std::cin.ignore(1024, '\n');

		switch (selectmenu)
		{
		case 1:

			std::cout << "変更する半径の値を入力してください" << '\n';
			std::cin >> std::setw(256) >> setNum;
			circle.SetR(setNum);
			std::cin.ignore(1024, '\n');

			std::cout << "面積を計算します" << '\n';
			circle.Size();

			break;

		case 2:

			std::cout << "変更する横幅の値を入力してください" << '\n';
			std::cin >> std::setw(256) >> setNum;
			rect.SetW(setNum);
			std::cin.ignore(1024, '\n');

			std::cout << "変更する縦幅の値を入力してください" << '\n';
			std::cin >> std::setw(256) >> setNum;
			rect.SetH(setNum);
			std::cin.ignore(1024, '\n');

			std::cout << "面積を計算します" << '\n';
			rect.Size();
			
			break;
		case 3:

			std::cout << "円と矩形の面積を計算します" << '\n';
			circle.Size();
			rect.Size();
			
			break;
		case 4:
			
			circle.Draw();
			rect.Draw();

			break;
		default:
			std::cout << "終了します" << '\n';
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