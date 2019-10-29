#include <stdio.h>

void* my_memmove(void* dest, const void* src, size_t count)
{
	void* ret = dest;

	if (dest < (char*)src || dest >= ((char*)src+count)) // µÍµØÖ·->¸ßµØÖ· Ë³Ðò¿½±´
	{
		while (count--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}

	}
	else  // ¸ßµØÖ·->µÍµØÖ· Ë³Ðò¿½±´
	{
		dest = (char*)dest + count - 1;
		src = (char*)src + count - 1;

		while (count--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest - 1;
			src = (char*)src - 1;
		}
	}


	return ret;
}

int main()
{
	char dest[] = "hello";
	char src[] = "12345";
	char* ret = (char*)my_memmove(dest, src, sizeof(src) * 1);
	printf("%s\n", ret);

	system("pause");
	return 0;
}