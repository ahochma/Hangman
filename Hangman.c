

#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define Tries 10

const char *words[] = {
	"apple",
	"banana",
	"home"
};
//function decleration
char get_letter();
int letter_in_str(char letter,const char str[]);
const char * pick_word_from_list(const char *words[]);
void switch_word(char ch,const char * p1,char *word_guess);
void add_to_array_of_guesses(char ch,char *guesses, int num_of_guesses);
////////////////////

//main
int main()
{	
	
	const char *p1=pick_word_from_list(words);//randomly choose word for player 1 
	int num_guess=Tries;
	char guesses[]="11111111111111";//str of guess initialized to 14 times 1
	int len=strlen(p1);
	char word_guess[len];
	for (size_t i = 0;i<len;i++)
			word_guess[i]='?';
	word_guess[len]='\0';
	while (num_guess!=0)
	{
		printf("%s (%d guesses remaining)\n", word_guess, num_guess);
		char ch =get_letter();
		while (!isalpha(ch))
		{
			printf("Your guess '%c' is not a letter.\n", ch);
			ch=get_letter();
		}
		while(letter_in_str(ch,guesses))
		{
			printf("You already guessed '%c'.\n", ch);
			ch=get_letter();
		}
		
		if (letter_in_str(ch,p1))
		{
			printf("Good guess!\n");
			switch_word(ch,p1,word_guess);
		}
		else
			printf("No appearances of '%c'...\n", ch);

		if (!letter_in_str('?',word_guess))
		{
			printf("You win! the word is: %s\n", p1);
			return 1;
		}

		add_to_array_of_guesses(ch,guesses,num_guess);
		num_guess--;
		
	}

	printf("No more guesses remaining....you lost!\n");

}
//functions
char get_letter()//get letter from the user
{
	char ch='0';
	printf("Please enter a letter: ");
	scanf(" %c", &ch); //letter
	ch=tolower(ch);
	return ch;	
}

int letter_in_str(char ch, const char str[])//check if the letter is in the str
{
	for(size_t i=0; str[i]!='\0';i++)
	{  
		if (str[i]==ch)
		{
			return 1;
		}
		
	}
	return 0;
}

const char *pick_word_from_list(const char *words[]) //generate a random word from the words list
{ 
    srand(time(NULL));
	int generated_num=(rand() % 3);
    return words[generated_num];

}

void switch_word(char ch,const char * p1,char *word_guess)
{
	for (size_t i = 0; i < strlen(p1); i++)
		if(p1[i]==ch)
			word_guess[i]=ch;
	
}

void add_to_array_of_guesses(char ch,char *guesses,int num_of_guesses)
{
	guesses[Tries-num_of_guesses]=ch;
}


/*
printf("Please enter a letter: ");		

printf("Your guess '%c' is not a letter.\n", ch);
		
printf("You already guessed '%c'.\n", ch);
			
printf("%s (%d guesses remaining)\n", word_guess, num_guess);
		
printf("Good guess!\n");
			
printf("You win! the word is: %s\n", word);
			
printf("No appearances of '%c'...\n", ch);
			
printf("No more guesses remaining....you lost!\n");
*/