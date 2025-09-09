#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    // first argument is -e or -d.
    // secound argument is the text.
    // third argument is the key.
    printf("the text is %s\n", argv[2]);
    int key = atoi(argv[3]);
    printf("the key is %d\n", key);

    // -h for help
    if (argv[1][0] == '-' && argv[1][1] == 'h')
    {
        printf("  ____ _       _                   ____\n");
        printf(" / ___(_)_ __ | |__   ___ _ __    / ___|\n");
        printf("| |   | | '_ \\| '_ \\ / _ \\ '__|___\\___ \\ \n");
        printf("| |___| | |_) | | | |  __/ | |_____|__) |\n");
        printf(" \\____|_| .__/|_| |_|\\___|_|      |____/ \n");
        printf("        |_|                              \n");
        printf("---------------------------------------------\n");
        printf("\tThis is the version 0.1\n");
        printf("---------------------------------------------\n");
        printf("Help:\n");
        printf("./cipher -h ---> for help\n");
        printf("./cipher -e text key ---> to encrypt a text with a key. for example:\n");
        printf("\t./chipher -e Helloworld 13\n");
        printf("./chipher -d text key ---> to decrypt an encrypted text with the key. for example:\n");
        printf("\t./cipher -d Uryy\\|d\\|\\yq 13\n");
        printf("---------------------------------------------\n");
        printf("Contact:\n");
        printf("mohammad.rajabi.ba@gmail.com\n");
        printf("---------------------------------------------\n");
    }

    // -e is for encrypting
    if (argv[1][0] == '-' && argv[1][1] == 'e')
    {
        printf("We are encrypting the text. the result is:\n");
        for (int i = 0; i < strlen(argv[2]); i++)
        {
            char final_value = argv[2][i] + key;
            if ('A' <= final_value && final_value <= 'z')
            {
                printf("%c", final_value);
            }
            else{
                // prevents to print |, &, etc by default.
                // because they are some key values in bash.
                // instead it prints one \ before that char.
                // for example '&' becomes '\&'.
                printf("\\");
                printf("%c", final_value);
            }
        }
    }

    // -d is for decryption.
    if (argv[1][0] == '-' && argv [1][1] == 'd')
    {
    	printf("We are decrypting the text. the result is:\n");
	for (int i = 0; i < strlen(argv[2]); i++)
	{
		printf("%c", argv[2][i] - key);
	}
    }
    
    // one final enter at the end
    printf("\n");
}
