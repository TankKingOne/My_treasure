#include <stdio.h>

void* my_memcpy(void* dest, const void* src, size_t count)
{
	void* ret = dest;

	while (count--)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}

	return ret;
}

int main()
{
	char dest[] = "hello";
	char src[] = "12345";
	char* ret = (char*)my_memcpy(dest, src, sizeof(src) * 1);
	printf("%s\n", ret);

	system("pause");
	return 0;
}