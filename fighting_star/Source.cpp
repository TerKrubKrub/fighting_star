#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct person
{
	char name[31];
	int score;
};

struct person p[10];
struct person vote[10000];

void inputName()
{
	for (int i = 1; i <= 8; i++)
	{
		scanf("%s", p[i].name);
		p[i].score = 0;
	}
}
void inputScore(int n)
{
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &vote[i].score);
	}
}
void countScore(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			if (vote[i].score == j)
			{
				p[j].score++;
			}
		}
	}
}

int main()
{
	inputName();
	int n;
	scanf("%d", &n);
	inputScore(n);
	countScore(n);
	int min = 10000;
	for (int i = 1; i <= 8; i++)
	{
		if (p[i].score <= min) min = p[i].score;
	}
	for (int i = 1; i <= 8; i++)
	{
		if (p[i].score > min) printf("%s\n",p[i].name);
	}

	return 0;
}