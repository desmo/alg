#include <stdio.h>
#include <string.h>
char *mystrcpy(char *dest,const char *src){
	char *dest1 = dest;
	while( *src!= '\0')
		*dest1++ = *src++;
	//*dest1 = '\0';

	return dest;

}

int 
main(){
	
	char dest[0];
	char *src = "string2";
	mystrcpy(dest,src);
	printf("dest is %s\n",dest);
	printf("src is %s\n",src);
}
