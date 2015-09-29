#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_FRAME 23
#define MIN_FRAME 0
#define FILE_NAME "frame/frame%d.txt"
#define REST_NANO 100000

void skelframe(int fn);
void printFile(char* file);
void clear();

#ifdef _WIN32
void clear()
{
	system("cls");
}
#else
void clear()
{
	system("clear");
}
#endif

int main(int argc, char const *argv[]){
	int frame = 0;
	//printFile("frame0.txt");
	while(true){
		skelframe(frame);
		printf("%d\n", frame);
		usleep(REST_NANO);
		frame++;
		if(frame > MAX_FRAME){
			frame = 0;
		}
		clear();
	}
	return 0;
}

// display a frame
void skelframe(int fn){
	char* file;
	asprintf(&file, FILE_NAME, fn);
	printFile(file);
}

void printFile(char* filepath){
	int c;
	FILE *file;
	file = fopen(filepath, "r");
	if(file){
		while((c=getc(file)) != EOF){
			putchar(c);
		}
		fclose(file);
	}
}
