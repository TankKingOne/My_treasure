#include <stdio.h>
#include <assert.h>

char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);

	char* ret = (char*)str1;
	char* tmp = NULL;
	char* substr = (char*)str2;

	if (*str2 == '\0')
		return NULL;

	while (*ret)
	{
		tmp = ret;
		substr = str2;
		while (*tmp != '\0' && (*tmp == *substr))
		{
			tmp++;
			substr++;
		}
		if (*substr == '\0')
			return ret;
		ret++;
	}
	return NULL;
}

int main()
{
	char dest[] = "hello";
	char src[] = "llo";

	printf("%s\n", my_strstr(dest, src));

	system("pause");
	return 0;
}