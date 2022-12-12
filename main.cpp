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

	

	void Draw(int phase);
	//近接
	void Proximity();
	//射撃
	void Shooting();
	//離脱
	void Secession();

private:

	static void (Enemy::* spFuncTable[])();

};


void (Enemy::* Enemy::spFuncTable[])()
{
	&Enemy::Proximity,
	&Enemy::Shooting,
	&Enemy::Secession
};

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Draw(int phase)
{

	(this->*spFuncTable[phase])();

}



void Enemy::Proximity()
{
	std::cout << "近接" << '\n';
}

void Enemy::Shooting()
{
	std::cout << "射撃" << '\n';
}

void Enemy::Secession()
{
	std::cout << "離脱" << '\n';
}

int main()
{

	int selectmenu = 0;
	int enemyPhase = 0;

	Enemy enemy;

	while (true)
	{

		std::cout << "[操作]" << '\n';
		std::cout << "敵の行動" << '\n';
		std::cout << "その他:終了" << '\n';

		std::cout << "\n------------------------------------------" << '\n';
		std::cout << "操作を選択してください" << '\n';

		std::cin >> selectmenu;
		std::cin.ignore(1024, '\n');

		if (selectmenu == 0)
		{

			enemy.Draw(enemyPhase);

			enemyPhase++;

		}
		else
		{
			break;
		}

		if (enemyPhase > 2)
		{
			break;
		}

	}


	system("pause");
	return 0;

}