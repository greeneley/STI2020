#include <stdio.h>
int main(int argc, char *argv[])
{
	FILE *fi, *fo;
	char *cp;
	int c;

	if (cp = argv[1])	
	{
		/* code */
		if ((fi = fopen(argv[2], "rb")) != NULL)
		{
			/* code */
			if ((fo = fopen(argv[3], "wb")) != NULL)
			{
				/* code */
				while(( c = getc(fi)) != EOF){
					if (*cp == '\0') cp = argv[1];
					printf("%d\n", *cp );
					c += *cp - 65;
					putc(c,fo);
				}
				fclose(fo);
			}
			fclose(fi);
		}
	}
	return 1;
}