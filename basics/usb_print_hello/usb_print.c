/*
Testing the USB serial functionality using the tinyUSB
*/

#include <stdio.h>
#include "pico/stdlib.h"

int main() {

	stdio_init_all();
	sleep_ms(5000);
	printf("Hello from USB serial\n");
	printf("From now on everything will be echoed.\n");
	printf(">");
	char readChar = '\r';
	char buffer[1024];
	int i = 0;
	while (true) {
		if (scanf("%c", &readChar) == -1){
			printf("EOF error!");
		}
		else if (readChar == '\r'){
			buffer[i++] ='\0'; 
			printf("\n%s\n", buffer);
			i=0;
			printf(">");
		}
		else if (i < 1024){
			printf("%c", readChar);
			buffer[i++] = readChar;
		}
		else printf("Buffer Filled");
		//sleep_ms (1000);
	}
}
