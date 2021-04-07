#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#define MAX 25

long int getsecret(){

	int i, count, secret = 0;
	int seed = time(NULL);

	srand(seed);
	int MAX_secret = 999999999;
	int MIN_secret = 100000000;
	int MAX_count = 999;
	int MIN_count = 100;

	count = (rand() % (MAX_count - MIN_count + 1)) + MIN_count;

	for (i = 0; i < count; ++i)
	{
		secret = (rand() % (MAX_secret - MIN_secret + 1)) + MIN_secret;
		
	}

	return secret;
}

int main()
{
	srand(100);
	setvbuf(stdin, NULL, _IONBF, 0); //turn off buffering
	setvbuf(stdout, NULL, _IONBF, 0); //turn off buffering

	int answer, end, secret, input = 0;
	time_t current_time;
	char* c_time_string;
	FILE* flagfile = NULL;
	char flag[MAX] = "";

	current_time = time(NULL);
	c_time_string = ctime(&current_time);
	printf("TIME: %s\n", c_time_string);

	secret = getsecret();

	printf("What is the secret?\n");
	fflush(stdin);
    scanf("%d",&answer);
    int c;
	//while ((c = fgetc(stdin)) != '\n' && c != EOF); /* Flush stdin */

	if(answer == secret){
		printf("Good job!\n");
	}
	else{
		printf("Wrong! Try again!\n");
		return 0;
	}

	end = (int)(time(NULL) - current_time);

	if(end > 1){
		printf("Too slow!\n");
	}
	else{
		printf("Weel done! This is your flag:\n");
		flagfile = fopen("flag1.txt", "r");
		if(flagfile != NULL){
			printf("This is your flag:\n");
			fgets(flag,MAX,flagfile);
		}
		else{
			printf("ERROR! The flag cannot be read! Try again and if the problem persists contact the designer!\n");
		}
		printf("%s\n", flag);
		fclose(flagfile);
	}

	return 0;
}