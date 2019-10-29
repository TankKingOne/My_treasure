#include <stdio.h>
#include <assert.h>

char* my_strcat(char* dest, const char* src)
{
	char* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	while (*dest)
		dest++;
	while (*dest++ = *src++)
	{

	}
	return ret;
}

int main()
{
	char dest[] = "hello";
	char src[] = " world";
	printf("%s\n", my_strcat(dest, src));

	system("pause");
	return 0;
}