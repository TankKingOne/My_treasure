#include <stdio.h>

int my_strlen_1(const char* str)
{
	int count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return count;
}

int my_strlen_2(const char* str)
{
	if (*str == '\0')
		return 0;
	else
		return 1 + my_strlen_2(str + 1);
}

int my_strlen_3(char* str)
{
	char *tmp = str;
	while (*tmp)
		*tmp++;
	return tmp - str;
}

int main()
{
	char str[] = "hello";
	printf("%d\n", my_strlen_1(str));
	printf("%d\n", my_strlen_2(str));
	printf("%d\n", my_strlen_3(str));

	system("pause");
	return 0;
}