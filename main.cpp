#include <stdio.h>
#include <string>
#include <stdexcept>
#include <iostream>
#include <iomanip>

class Enemy
{
public:
	Enemy();
	~Enemy();

	static bool isdead;

	void draw();
	void dead();

private:

	

};

bool Enemy::isdead = false;

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::draw()
{

	if (isdead == false)
	{
		std::cout << "����" << '\n';
	}
	else
	{

		std::cout << "no����" << '\n';

	}

}
void Enemy::dead()
{

	std::cout << "�E�Q!!!!" << '\n';
	isdead = true;

}

int main()
{

	int selectmenu = 0;

	Enemy enemy1;
	Enemy enemy2;
	Enemy enemy3;

	while (true)
	{

		std::cout << "[����]" << '\n';
		std::cout << "0:�����`��" << '\n';
		std::cout << "1:�E�Q" << '\n';
		std::cout << "���̑�:�I��" << '\n';

		std::cout << "\n------------------------------------------" << '\n';
		std::cout << "�����I�����Ă�������" << '\n';

		std::cin >> selectmenu;
		std::cin.ignore(1024, '\n');

		if (selectmenu == 0)
		{

			enemy1.draw();
			enemy2.draw();
			enemy3.draw();

		}
		else if (selectmenu == 1)
		{

			enemy1.dead();

		}
		else
		{
			break;
		}

	}


	system("pause");
	return 0;

}