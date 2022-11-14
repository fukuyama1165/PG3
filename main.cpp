#include <stdio.h>

template <typename Type>

Type Min(Type a, Type b)
{
	if (a < b)
	{
		return static_cast<Type>(a);
	}

	return static_cast<Type>(b);

}

template<>

char Min<char>(char a, char b)
{
	printf("”š‚Í‘ã“ü‚Å‚«‚Ü‚¹‚ñ\n");
	return '\0';
}

int main()
{
	int a1 = 0;
	int b1 = 1;

	float a2 = 2;
	float b2 = 1;

	double a3 = 3;
	double b3 = 2;

	char a4 = 'a';
	char b4 = 'b';

	printf("%d\n", Min<int>(a1, b1));
	printf("%f\n", Min<float>(a2, b2));
	printf("%lf\n", Min<double>(a3, b3));
	printf("%c\n", Min<char>(a4, b4));
	return 0;
}

