#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define MAX_CHOICE 10
#define MAX_COSTUME 3
#define MAX_COTE 10
#define MAX_COUPON 10

int nb_choice = 0;
int nb_cote = 0;
int nb_coupon = 0;

typedef struct Costume Costume;
struct Costume{
	char name[25];
	int price;
	char description[250];
	char url[250];
};

Costume costume_arr[MAX_COSTUME];

int cote_arr[MAX_COTE] = {0};

char coupon_arr[MAX_COUPON][4];

void init(){
	strcpy(costume_arr[0].name, "pikachu costume\n\0");
	costume_arr[0].price = 100;
	strcpy(costume_arr[0].description, "Good gift for your girlfriend or your sister but she will be very irritating when she will run around you shouting PIKA PIKA!\n\0");
	strcpy(costume_arr[0].url, "https://www.amazon.ca/JINGCHENG-Pajamas-Cosplay-Cartoon-Costume/dp/B07792L76S/\n\0");
	
	strcpy(costume_arr[1].name, "unicorn costume\n\0");
	costume_arr[1].price = 1000;
	strcpy(costume_arr[1].description, "A classic!\n\0");
	strcpy(costume_arr[1].url, "https://www.amazon.ca/Rasta-Imposta-Mens-Unicorn-Multi/dp/B00K0HQLME/\n\0");
	
	strcpy(costume_arr[2].name, "poop costume\n\0");
	costume_arr[2].price = 10000000;
	strcpy(costume_arr[2].description, "The best gift to humiliate your friend who lost a bet! Yes, I try to sell you shit at a gold price but humiliate your friend have no price!\n\0");
	strcpy(costume_arr[2].url, "https://www.amazon.ca/Emoji-Inflatable-Poop-Costume-Halloween/dp/B076DKKHJY/\n\0");

	cote_arr[0] = 1;
	nb_cote++;
	cote_arr[1] = 2;
	nb_cote++;
	cote_arr[2] = 3;
	nb_cote++;
}

void print_menu(){
	printf("|------------ Services Menu ------------|\n"
	       "| 1. Costume list                       |\n"
	       "| 2. Make your choice                   |\n"
	       "| 3. See your bill                      |\n"
	       "| 4. Edit your choice                   |\n"
	       "| 5. Give a feedback                    |\n"
	       "| 6. Give a coupon                      |\n"
	       "| 7. Quit                               |\n"
	       "|---------------------------------------|\n");
}

void print_costume(){
	printf("---- Our costume ----\n\n");

	for (int i = 0; i < MAX_COSTUME; i++)
	{
		if(costume_arr[i].name[0] == '\0'){
			break;
		}

		printf("---------------Costume number %d ---------------\n", i);
		printf("name: %s", costume_arr[i].name);
		printf("price: %d$\n", costume_arr[i].price);
		printf("description: %s", costume_arr[i].description);
		printf("URL: %s", costume_arr[i].url);
		printf("---------------------------------------------\n\n", i);
	}
}

void make_choice(unsigned int * choices_arr){
	int id = 0;
	int quantity = 0;

	if(nb_choice >= MAX_CHOICE){
		printf("You can't choose more than 10 costumes!\n");
	}
	else{
		printf("---- Make your choice ----\n");
		printf("ID of the costume: ");
		scanf("%d", &id);

		if(id >= MAX_COSTUME){
			printf("Invalid ID!\n");
		}
		else{

			choices_arr[nb_choice] = id;
			nb_choice++;
			printf("Your choice is registered!\n");
		}
	}
}

void edit_choice(unsigned int * choices_arr){
	int id = 0;
	int choice = 0;
	if(nb_choice == 0){
		printf("You have no costume in your bill!\n");
	}
	else{
		printf("Number of your choice: ");
		scanf("%d", &choice);
		
		choice = choice - 1;
		
		if(choice > nb_choice){
			printf("This number does not exist!\n");
		}
		else{
			printf("---- Edit your choice ----\n");
			printf("ID of the costume: ");
			scanf("%d", &id);

			choices_arr[choice] = id;
			
			printf("Your choice is registered!\n");
		}
	}
}

void see_bill(unsigned int * choices_arr){
	int total_price = 0;
	int id = 0;

	for(int i = 0; i < nb_choice; i++){
		id = choices_arr[i];

		printf("%d\n", id);
		if(id < 0 || id >= MAX_COSTUME){
			printf("An invalid ID has been detected in your bill!\n");
			printf("We will close the program.\n");
			printf("Try again plz!\n");
			exit(0);
		}
		else{
			total_price = total_price + costume_arr[id].price;
		}
	}

	printf("Your bill is %d$\n", total_price);
}

int feedback(){
	char cote[8];
	int verygood = 0, good = 0, bad = 0, verybad = 0;

	printf("|&&&&&&&& Total of feedbacks &&&&&&&&|\n");

	for (int i = 0; i < nb_cote; i++){
		if(cote_arr[i] == 1){
			verygood++;
		}
		else if(cote_arr[i] == 2){
			good++;
		}
		else if(cote_arr[i] == 3){
			bad++;
		}
		else{
			verybad++;
		}

	}

	printf("Very good: %d\n", verygood);
	printf("Good: %d\n", good);
	printf("Bad: %d\n", bad);
	printf("Very Bad: %d\n", verybad);

	printf("--------------------------------------\n\n");

	if(nb_cote >= MAX_COTE){
		printf("Sorry, no more feedback is accepted!\n");
	}
	else{
		printf("Give us a feedback!\n");
		printf("Type VG for very good.\n");
		printf("Type G for good.\n");
		printf("Type B for bad.\n");
		printf("Type VB for very bad.\n");

		getchar();
		fgets(cote, 8, stdin);

		if(cote[0] == 'V'){
			if(cote[1] == 'G'){
				cote_arr[nb_cote] = 1;
				nb_cote++;
			}
			else if(cote[1] == 'B'){
				cote_arr[nb_cote] = 4;
				nb_cote++;
			}
			else{
				printf("Invalid code!\n");
				return 0;
			}
		}
		else if(cote[0] == 'G'){
			cote_arr[nb_cote] = 2;
			nb_cote++;
		}
		else if(cote[0] == 'B'){
			cote_arr[nb_cote] = 3;
			nb_cote++;
		}
		else{
				printf("Invalid code!\n");
				return 0;
		}

		printf("You're feedback is: ");
		printf(cote);
		printf("\nThanks!\n");
	}
}

int give_coupon()
{
	char coupon[5];

	if(nb_coupon >= MAX_COUPON){
		printf("Sorry, no more coupon is accepted!\n");
	}
	else{
		printf("Give us a valid coupon and you can get a promotion in your buy!\n");
		printf("Enter the coupon:");

		getchar();
		fgets(coupon, 5, stdin);
		if(strchr(coupon, 'h') != NULL){
			printf("Invalid coupon!\n");
		}
		else{
			coupon[4] = 0;
			strcpy(coupon_arr[nb_coupon],coupon);
			printf("Your coupon is registered!\n");
			nb_coupon++;
		}
	}
	
	return 0;
}

int main()
{
	setvbuf(stdin, NULL, _IONBF, 0); //turn off buffering
	setvbuf(stdout, NULL, _IONBF, 0); //turn off buffering

	int input = 0;
	unsigned int choices_arr[MAX_CHOICE] = {3};

	init();

	printf("Welcome to the Costume shop!\n");

	while(input !=7){
		print_menu();

		scanf("%d", &input);

		if(input == 1){
			print_costume();
		}else if(input == 2){
			make_choice(choices_arr);
		}else if(input == 3){
			see_bill(choices_arr);
		}
		else if(input == 4){
			edit_choice(choices_arr);
		}
		else if(input == 5){
			feedback();
		}
		else if(input == 6){
			give_coupon();
		}
	}
	printf("Bye!\n");
	return 0;
}
