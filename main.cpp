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
	//�ߐ�
	void Proximity();
	//�ˌ�
	void Shooting();
	//���E
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
	std::cout << "�ߐ�" << '\n';
}

void Enemy::Shooting()
{
	std::cout << "�ˌ�" << '\n';
}

void Enemy::Secession()
{
	std::cout << "���E" << '\n';
}

int main()
{

	int selectmenu = 0;
	int enemyPhase = 0;

	Enemy enemy;

	while (true)
	{

		std::cout << "[����]" << '\n';
		std::cout << "�G�̍s��" << '\n';
		std::cout << "���̑�:�I��" << '\n';

		std::cout << "\n------------------------------------------" << '\n';
		std::cout << "�����I�����Ă�������" << '\n';

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