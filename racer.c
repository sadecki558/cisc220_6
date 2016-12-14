/* Cisc 220 Assignment 6
Josh Burak - 10169785
Alexander Gadanidis - 10186175
Kat Pinto - 10168919
Matthew Sadecki - 10179995
December 13, 2016
*/
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define NUM_THREADS 6;

bool finishLine = false;
/* Thread for the computer AI racer */
void* raceAI(void *args){
	usleep(rand(100));
	char *newarr[];
	newarr[0] = "~";
	args = strcat(newarr, args);
	return args;
}

/* Thread for race user */
void* raceUser(void *args){
	getchar();
	char *newarr[];
        newarr[0] = "~";
        args = strcat(newarr, args);
        return args;
}
/* Prints the race */
void* printRace(void *args){
	usleep(20);
	system(clear);
	printf("%s \n%s \n%s \n%s \n%s", args[0], args[1], args[2], args[3], args[4]);
}


int main(void){
	char line1[] = "|->";
	char line2[] = "|->";
	char line3[] = "|->";
	char line4[] = "|->";
	char line5[] = "|->";
	pthread_t threads[NUM_THREADS];
	while (!finishLine) {
		if strlen(line1) >= 43{
			finishLine = true;
		}
		else if strlen(line2) >= 43{
                        finishLine = true;
                }
		else if strlen(line3) >= 43{
                        finishLine = true;
                }
                else if strlen(line4) >= 43{
                        finishLine = true;
                }
                else if strlen(line5) >= 43{
                        finishLine = true;
                }
		int pthread_create(threads+1, NULL, raceUser, (void *) line1);
        	int pthread_create(threads+2, NULL, raceAI, (void *) line2);
	        int pthread_create(threads+3, NULL, raceAI, (void *) line3);
        	int pthread_create(threads+4, NULL, raceAI, (void *) line4);
	        int pthread_create(threads+5, NULL, raceAI, (void *) line5);
		int pthread_create(threads+6, NULL, printRace, (void *) [line1, line2, line3, line4, line5]);
	}
