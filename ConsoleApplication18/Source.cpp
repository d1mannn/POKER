#include <stdio.h>
#include <iostream>
#include <math.h>
#include <locale>
#include <time.h>
using namespace std;

enum mastiEnum
{
	piki = 100,
	kresti = 200,
	bubny = 300,
	chervi = 400
};

enum kartyEnum
{
	two = 2,
	three,
	four,
	five,
	six,
	seven,
	eight,
	nine,
	ten,
	valet,
	dama,
	karol,
	tuz
};
void printmast(mastiEnum n)
{
	switch (n)
	{
	case piki:
		cout << "piki" << endl;
		break;
	case kresti:
		cout << "kresti" << endl;
		break;
	case bubny:
		cout << "bubny" << endl;
		break;
	case chervi:
		cout << "chervi" << endl;
		break;
	}
}

void main()
{

	{
		/*Программа псевдослучайным образом выбирает из колоды в 54 карты(2–10, валет,
		дама, король, туз в мастях пики, трефы, бубны, червы + 2 джокера) пять карт и отображает свой выбор.
			После этого определяется, есть ли в сданных картах одна из комбинаций :
		(a)Пара : две карты одного значения;
		(b)Сет : три карты одного значения;
		(c)Флэш : пять карт одной масти*/


		enum mastiEnum masti;

		enum kartyEnum karty;

		int karta0, karta, karta1, karta2, karta3, karta4, karta5;
		int mast;
		for (int i = 1; i <= 5; i++)
		{
			karta = 2 + rand() % 12;//2.4.8.3.12.14
			mast = (1 + rand() % 4) * 100;//100.200.300.400

			cout << karta << " ";
			printmast((mastiEnum)mast);
			cout << endl;

			switch (i)
			{
			case 1:
				karta1 = mast + karta;//108.413
				break;
			case 2:
				karta2 = mast + karta;
				break;
			case 3:
				karta3 = mast + karta;
				break;
			case 4:
				karta4 = mast + karta;
				break;
			case 5:
				karta5 = mast + karta;
				break;
			}
		}
		//(a)Пара : две карты одного значения;
		int para = 0, res0, res1;
		for (int i = 1; i <= 5; i++)
		{
			switch (i)
			{
			case 1:
				karta = karta1;
				break;
			case 2:
				karta = karta2;
				break;
			case 3:
				karta = karta3;
				break;
			case 4:
				karta = karta4;
				break;
			case 5:
				karta = karta5;
				break;
			}

			for (int j = i + 1; j <= 5; j++)
			{
				switch (j)
				{
				case 2:
					karta0 = karta2;
					break;
				case 3:
					karta0 = karta3;
					break;
				case 4:
					karta0 = karta4;
					break;
				case 5:
					karta0 = karta5;
					break;
				}

				res0 = (karta0 - ((karta0 / 100) * 100));
				res1 = (karta - ((karta / 100) * 100));

				cout << karta0 << " = " << res0 << endl;
				cout << karta << " = " << res1 << endl;
				cout << endl;
				if (res0 == res1)
				{
					para++;
					cout << "PARA" << endl;
					break;
				}

			}

			if (para > 0) break;
		}
	}
}