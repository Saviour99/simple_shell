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
void tokenizer(char *string);
void execute_command(const char *str);


void print(char *string);
void display_prompt(void);
void get_command(char *buff, size_t buff_size);
void exec_command(char *str);

/*int (*get_builtin(char *cmd))(data_shell *);*/

#endif /*  _SHELL_H_  */
