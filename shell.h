#ifndef SHELL_H
#define SHELL_H

/*Header files*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>

/*Prototypes*/
void interactive_mode(char *str);
void non_interactive_mode(void);
void print(char *string);
void display_prompt(void);
void read_input(char *buff);
void tokenizer(char *string);
void execute_command(const char *str);


#endif /*  _SHELL_H_  */
