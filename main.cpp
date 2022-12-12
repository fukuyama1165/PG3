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
	//‹ßÚ
	void Proximity();
	//ŽËŒ‚
	void Shooting();
	//—£’E
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
	std::cout << "‹ßÚ" << '\n';
}

void Enemy::Shooting()
{
	std::cout << "ŽËŒ‚" << '\n';
}

void Enemy::Secession()
{
	std::cout << "—£’E" << '\n';
}

int main()
{

	int selectmenu = 0;
	int enemyPhase = 0;

	Enemy enemy;

	while (true)
	{

		std::cout << "[‘€ì]" << '\n';
		std::cout << "“G‚Ìs“®" << '\n';
		std::cout << "‚»‚Ì‘¼:I—¹" << '\n';

		std::cout << "\n------------------------------------------" << '\n';
		std::cout << "‘€ì‚ð‘I‘ð‚µ‚Ä‚­‚¾‚³‚¢" << '\n';

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