#include <stdio.h>
#include <iostream>
#include <list>


int main()
{
	std::list<const char*> yamanote;

	yamanote.emplace_back("Tokyo");
	yamanote.emplace_back("Kanda");
	yamanote.emplace_back("Akihabara");
	yamanote.emplace_back("Okachimachi");
	yamanote.emplace_back("Ueno");
	yamanote.emplace_back("Uguisudani");
	yamanote.emplace_back("Nippori");
	yamanote.emplace_back("Tabata");
	yamanote.emplace_back("Komagome");
	yamanote.emplace_back("Sugamo");
	yamanote.emplace_back("Otsuka");
	yamanote.emplace_back("Ikebukuro");
	yamanote.emplace_back("Mejiro");
	yamanote.emplace_back("Takadanobaba");
	yamanote.emplace_back("Shin-Okubo");
	yamanote.emplace_back("Shinjuku");
	yamanote.emplace_back("Yoyogi");
	yamanote.emplace_back("Harajuku");
	yamanote.emplace_back("Shibuya");
	yamanote.emplace_back("Ebisu");
	yamanote.emplace_back("Meguro");
	yamanote.emplace_back("Gotanda");
	yamanote.emplace_back("Osaki");
	yamanote.emplace_back("Shinagawa");
	yamanote.emplace_back("Tamachi");
	yamanote.emplace_back("Hamamatsucho");
	yamanote.emplace_back("Hamamatsucho");
	yamanote.emplace_back("Shimbashi");
	yamanote.emplace_back("Yurakucho");

	printf("1970”N\n");
	for (std::list<const char*>::iterator itr = yamanote.begin(); itr != yamanote.end(); ++itr)
	{

		std::cout << *itr << "\n";

	}

	for (std::list<const char*>::iterator itr = yamanote.begin(); itr != yamanote.end(); ++itr)
	{

		if (*itr == "Tabata")
		{
			itr = yamanote.insert(itr, "Nishi-Nippori");

			++itr;
		}

	}

	printf("\n2019”N\n");

	for (std::list<const char*>::iterator itr = yamanote.begin(); itr != yamanote.end(); ++itr)
	{

		std::cout << *itr << "\n";

	}

	for (std::list<const char*>::iterator itr = yamanote.begin(); itr != yamanote.end(); ++itr)
	{

		if (*itr == "Tamachi")
		{
			itr = yamanote.insert(itr, "Takanawa Gateway");

			++itr;
		}

	}

	printf("\n2020”N\n");

	for (std::list<const char*>::iterator itr = yamanote.begin(); itr != yamanote.end(); ++itr)
	{

		std::cout << *itr << "\n";

	}

	return 0;
}