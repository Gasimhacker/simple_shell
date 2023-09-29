#ifndef MAIN_H
#define MAIN_H

/* "File inclusions" */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <stddef.h>
#include <limits.h>
#include <errno.h>

/* "Environment variable" */
extern char **environ;


/* "structs and typedefs" */
/**
 * struct dir_s - A new type called dir_t for struct dir_s
 * @directory: The directory name
 * @next: A ponter to the next node
 */
typedef struct dir_s
{
	char *directory;
	struct dir_s *next;
} dir_t;
/**
 * struct alias_s - A new type called alias_t for struct alias_s
 * @name: The alias name
 * @value: The value of the alias
 * @next: A ponter to the next node
 */
typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
} alias_t;


/* "Aliases" */
/**
 * add_alias_end - Add a new alias at the end of an aliases linked list
 * @head: A pointer to a pointer to the first node in the linked list
 * @name: The name of the alias to put inside the node
 * @value: The value of the alias to put inside the node
 *
 * Return: A pointer to the new node in the linked list
 */
alias_t *add_alias_end(alias_t **head, const char *name, const char *value);
/**
 * search_alias - search if the alias is in the aliases list
 * @alias: The alias to find
 * @head: The head of the linked list
 *
 * Return: If the alias is found - pointer to the alias
 *	   otherwise - NULL
 */
alias_t *search_alias(alias_t **head, char *alias);
/**
 * create_alias - Add the new alias to the aliases linked list
 * @alias: The alias to add
 * @head: The head of the linked list
 *
 * Return: void
 */
void create_alias(alias_t **head, char *alias);
/**
 * print_alias - Print the passed alias
 * @alias: The alias to be printed
 *
 * Return: void
 */
void print_alias(const alias_t *alias);
/**
 * print_specific_alias - Search for an alias and print it
 * @alias: The alias to print
 * @head: A double pointer to the linked list to be freed
 *
 * Return: void
 */
void print_specific_alias(alias_t **head, char *alias);
/**
 * print_list - Print the data stored in the nodes of a linked list
 * @h: A double pointer to the linked list to be freed
 *
 * Return: The number of nodes
 */
size_t print_aliases(alias_t **h);
/**
 * free_list - Free a list_t list
 * @head: A pointer to the linked list to be freed
 *
 * Return: void
 */
void free_list(alias_t *head);
/**
 * get_head - Get the head of the aliases linked list
 *
 * Return: A pointer to the head of the linked list
 */
alias_t *get_head(void);


/* "Directories" */
/**
 * add_node_end - Add a new node at the end of a linked list
 * @head: A pointer to a pointer to the first node in the linked list
 * @str: The string to put inside the node
 *
 * Return: A pointer to the new node in the linked list
 */
dir_t *add_node_end(dir_t **head, const char *str);
/**
 * print_list - Print the data stored in the nodes of a linked list
 * @h: A pointer to the first node in the linked list
 *
 * Return: The number of nodes
 */
size_t print_list(const dir_t *h);


/* "String helpers" */
/**
 * cat_with_delimiter - Create an absolute path
 * @first_name: The first nam
 * @delim: The delimiter between the two names
 * @second_name: The second name
 *
 * Return: A duplicate containing the concatenated word
 */
char *cat_with_delimiter(const char *first_name,
		char *delim, const char *second_name);
/**
 * _strlen - Returns the length of the string
 * @s: The string to calculate its length
 *
 * Return: The length of the string
 */
int _strlen(const char *s);
/**
 * _strcpy - Copy a string in one variable into another variable
 * @src: The string to be copied
 * @dest: The destination of the copied string
 *
 * Return: The pointer to the destination.
 */
char *_strcpy(char *dest, const char *src);
/**
 * _strdup - Copy a string given as a parameter into
 *		  a newly allocated memory space
 * @str: The string to be copied
 *
 * Return: A pointer to the duplicated string, NULL otherwise
 */
char *_strdup(const char *str);
/**
 * _strcmp - Compare two strings
 * @s1: The first string
 * @s2: The string to compare with the first
 * Return: Zero if both strings are identical,
 *	   greater than zero when the matching
 *	   character of left string has greater
 *	   ASCII value than the character of
 *	   the right string, less than zero
 *	   when the left character has a smaller
 *	   value.
 */
int _strcmp(const char *s1, const char *s2);
/**
 * _atoi - Converts a string to an integer.
 * @s: The string to be converted.
 *
 * Return: The integer value of the converted string.
 */
int _atoi(char *s);
/**
 * _itoa - Convert a positive integer to string
 * @num: The number to convert
 *
 * Return: A pointer to the string created, or NULL on failure
 */
char *_itoa(int num);
/**
 * is_atoi - Check if a string is convertable to digit
 * @str: The string to check
 *
 * Return: If the string is convertable - 1
 *	   otherwise - 0
 */
int is_atoi(char *str);
/**
 * _strchr - Locate a character in a string
 * @s: The string to be searched
 * @c: The character to find
 *
 * Return: A pointer to the first occurrence of the character c
 *	   in the string s, or NULL if the character is
 *	   not found
 */
char *_strchr(char *s, char c);
/**
 * is_equal_found - Search for the equal sign inside the name
 * @name: The variable to check its name
 *
 * Return: If the '=' is found - 1
 *	   otherwise - 0
 */
int is_equal_found(const char *name);
/**
 * _strtok - Split the string into tokens
 * @str: The string to split
 * @delim: The string containing delimiters that
 *	   indicate an end of a word(token)
 *
 * Return: A pointer to the next token everytime it is called
 *	   On failure - NULL
 */
char *_strtok(char *str, const char *delim);
/**
 * split_string - Split the string into an array of tokens
 * @str: The string to split
 * @delimiter: A string containing all the posibble delimiters
 *
 * Return: An array of splitted words
 *	   Or "NULL" on failure
 */
char **split_string(const char *str, const char *delimiter);



/* "Memory helpers" */
/**
 * copy_to_heap - Copy the environment variable array to the heap
 *
 * Return: On success - 1
 *	   On error - 0
 */
int copy_to_heap(void);
/**
 * _realloc - Reallocate memory block using malloc and free
 *	      and copy the content of ptr to the newly allocated space,
 *	      in the range from the start of ptr up to
 *	      the minimum of the old and new sizes.
 *	      If new_size > old_size, the "added" memory
 *	      should not be initialized
 * @ptr: A pointer to the memory previously allocated with a call to malloc:
 *	 "malloc(old_size)"
 * @old_size: The size, in bytes, of the allocated space for ptr
 * @new_size: The size, in bytes, of the new memory block
 *
 * Return: A pointer to the allocated memory,
 *	   if new_size == old_size,do not do anything and return ptr
 *	   If new_size is equal to zero, and ptr is not NULL,
 *	   then the call is equivalent to free(ptr). Return NULL
 *	   If malloc fails, then _realloc returns NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
/**
 * get_exit_status - Save the last exit code
 *
 * Return: A pointer to the last saved exit code
 */
int *get_exit_status(void);
/**
 * clean - Free the allocations created by [un]setenv
 * @array: The array to be freed
 *
 * Return: void
 */
void clean(char **array);


/* "Environment manipulation" */
/**
 * _getenv - Get an invironment variable
 * @name: The name of the variable
 * @offset: If "name" is found this member will be
 *	    updated to contain the offset of the
 *	    variable inside the environmet array
 *
 * Return: The address of the variable
 *	   or NULL if the variable is not found
 */
char *_getenv(const char *name, int *offset);
/**
 * _setenv - Add or modify an environment variable
 * @name: The name of the variable to add or modify
 * @value: The value to assign to the variable
 * @overwrite: If the variable is present in the environment variable
 *	       and this member is not zero the variable will be updated
 *
 * Return: On success - 0
 *	   On error - -1
 */
int _setenv(const char *name, const char *value, int overwrite);
/**
 * _unsetenv - Delete a a variable from the environment variable
 * @name: The name of the variable to delete
 *
 * Return: On success - 0
 *	   On error - -1
 */
int _unsetenv(const char *name);
/**
 * print_env - print the current environment
 *
 * Return: void
 */
void print_env(void);


/* "Input proccessing" */

/**
 * create_args - Create the arguments list
 * @buff: The buffer to be handled
 * Return: The arguments list
 */
char **create_args(char *buff);
/**
 * find_file - check if the file is in the current path
 * @file_name: The file name
 *
 * Return: If the file is found - 1
 *	   Otherwise - 0
 */
char *find_file(char *file_name);
/**
 * execute - Execute the passed command
 * @args: The arguments passed to the command
 * @program_path: The path to the program to be executed
 *
 * Return: On success - 0
 *	   On error - 1
 */
int execute(char **args, char *program_path);


/* "Builtin handling" */
/**
 * search_builtins - Check if the command passed is a builtin
 *		     and if it is a builtin execute it
 * @head: The head of the linked list that needs to be freed
 * @shell_name: The name of the shell is used for printing error messages
 * @cmd_name: The name of the command
 * @args: The arguments list to pass to the handler functions
 *
 * Return: If builtin found - 1
 *	   Otherwise - 0
 */
int search_builtins(alias_t **head, char *shell_name,
		char *cmd_name, char **args);
/**
 * changeDirectory - Change the current directory
 * @newpwd: The path of the new Directory
 * Return: Nothing
 */
void change_directory(const char *newpwd);


/* "Shell modes" */
/**
 * run_interactive - Execute the shell commands in the interactive mode
 * @head: The head of the linked list that needs to be freed
 * @shell_name: The name of the shell is used for printing error messages
 *
 * Return: void
 */
void run_interactive(alias_t **head, char *shell_name);
/**
 * run_non_interactive - Execute the shell commands in
 *			 the non interactive mode
 * @head: The head of the linked list that needs to be freed
 * @shell_name: The name of the shell is used for printing error messages
 *
 * Return: void
 */
void run_non_interactive(alias_t **head, char *shell_name);


/* "Error messages" */
/**
 * cmd_not_found_msg - Print an error if the command is not found
 * @shell_name: The name of the shell
 * @cmd: The command that we didn't find
 *
 * Return: void
 */
void cmd_not_found_msg(char *shell_name, char *cmd);
/**
 * wrong_exit_code_msg - Print an error if the command is not found
 * @shell_name: The name of the shell
 * @exit_code: The wrong exit code
 *
 * Return: void
 */
void wrong_exit_code_msg(char *shell_name, char *exit_code);

/*New Functions*/
/**
 * check_separator - Searh a buffer for some seprator
 * @buff: Buffer to be searched for a seprator
 * @head: The head of the linked list that needs to be freed
 * @shell_name: The name of the shell is used for printing error messages
 * Return: Returns the seperator
 */
int check_separator(char *buff, alias_t **head, char *shell_name);

/**
 * handle_anding - handles and Executes the command seperated by '&&'
 * @commands: List of command to be separated
 * @head: The head of the linked list that needs to be freed
 * @shell_name: The name of the shell is used for printing error messages
 * Return: void
 */
void handle_anding(char **commands, alias_t **head, char *shell_name);

/**
 * handle_oring - handles and Executes the command seperated by '||'
 * @commands: List of command to be separated
 * @head: The head of the linked list that needs to be freed
 * @shell_name: The name of the shell is used for printing error messages
 * Return: void
 */
void handle_oring(char **commands, alias_t **head, char *shell_name);

/**
 * handle_colon - handles and Executes the command seperated by ';'
 * @commands: List of command to be separated
 * @head: The head of the linked list that needs to be freed
 * @shell_name: The name of the shell is used for printing error messages
 * Return: void
 */
void handle_colon(char **commands, alias_t **head, char *shell_name);

/**
 * _strstr - Locate a substring
 * @haystack: The string to be searched
 * @needle: The substring that should be located
 *
 * Return: A pointer to the beginning of the located
 *	   substring, or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle);

/**
 * search_execute - Serach for the command and execute it if found
 *@command: The command tobe executed
 *@head: The head of the linked list that needs to be freed
 *@shell_name: The name of the shell is used for printing error messages
 *
 * Return: void
 */
void search_execute(char *command, alias_t **head, char *shell_name);

/**
 * _getlines - Super simple shell
 * @commands: The list were commands will be stored
 * Return: Always number of commands
 */
int _getlines(char **commands);

#endif /* MAIN_H */
