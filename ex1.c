//ido zeira 322607177
#define MAX_INPUT 100
#define MAX_PATH 100
#define TOKEN_DELIMITERS " \t\r\n\a"
#define ARGS_NAME_POS 1 //position of program name in arg list

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char *str;
    int state;
} job;

job *history;
int history_entry_count = 0;
int run = 1;

int launch(char **args)
{
    char *prog_name = args[ARGS_NAME_POS];
    if (strcmp(prog_name, "cd") == 0)
    {
        if (args[3])
            printf("Too many argument");
        else
        {
        }
    }
    else if (strcmp(prog_name, "xxx") == 0)
    {
    }
    else if (strcmp(prog_name, "xxx") == 0)
    {
    }
    else if (strcmp(prog_name, "xxx") == 0)
    {
    }
    else /* default: */
    {
    }
    pid_t pid, wpid;
    int status;
    if ((pid = fork()) == 0)
    {
        execvp(args[ARGS_NAME_POS], args);
    }
    else if (pid < 0)
    {
        printf("fork failed"); // Error forking
        fflush(stdout);
    }
    else // Parent process
    {
        if (!args[0][0])
            do
            {
                wpid = wait(&status);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

char **parse(char *in)
{
    int pos = ARGS_NAME_POS;
    char **tokens = malloc(BUFSIZ * sizeof(char *));
    char *token = strtok(in, TOKEN_DELIMITERS);
    while (token != NULL)
    {
        tokens[pos++] = token;
        token = strtok(NULL, TOKEN_DELIMITERS);
    }
    return tokens;
}

int input()
{
    char in[MAX_INPUT];
    printf("$ ");
    fflush(stdout);
    fgets(in, sizeof(in), stdin);
    char **args = parse(in);
    return launch(args);
}

int main()
{
    while (run)
    {
        input();
    }
}
