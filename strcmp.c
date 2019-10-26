#include <stdio.h>
#include <assert.h>

int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);

	int ret;
	
	while (!(ret = *(unsigned char*)str1 - *(unsigned char*)str2) && *str1)  // ת����(unsigned char*)���ɱ�ʾ0-255���ַ���sign charֻ�ܱ�ʾ-126-125
	{
		str1++;
		str2++;
	}

	if (ret < 0)
		return -1;
	else if (ret > 0)
		return 1;

	return 0;
}

int main()
{
	char dest[] = "hello";
	char src[] = "hello";

	printf("%d\n", my_strcmp(dest, src));

	system("pause");
	return 0;
}