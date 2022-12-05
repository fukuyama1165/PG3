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
		std::cout << "生存" << '\n';
	}
	else
	{

		std::cout << "no生存" << '\n';

	}

}
void Enemy::dead()
{

	std::cout << "殺害!!!!" << '\n';
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

		std::cout << "[操作]" << '\n';
		std::cout << "0:生存描画" << '\n';
		std::cout << "1:殺害" << '\n';
		std::cout << "その他:終了" << '\n';

		std::cout << "\n------------------------------------------" << '\n';
		std::cout << "操作を選択してください" << '\n';

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