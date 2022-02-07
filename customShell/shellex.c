// ************************************************************
// Author: Nicole Tome
// Last Edit: December 1, 2021
// ***********************************************************


/* $begin shellmain */
#include "csapp.h"
#define MAXARGS   128

/* Function prototypes */
void eval(char *cmdline);
int parseline(char *buf, char **argv);
int builtin_command(char **argv); 

char *globalPrompt= "nicoletome";

void quit() //Function for built-in exit command
{
    fflush(stdout);
    raise(SIGTERM);
}

void pid() //Function for built-in pid command
{
    printf("%d \n", getpid());
    fflush(stdout);
    return;
}

void ppid() //Function for built-in ppid command
{
    printf("%d \n", getppid());
    fflush(stdout);
    return;
}

void currentdir() //Function for built-in currentdir command
{
    char s[100];
    printf("%s \n", getcwd(s,100));
    fflush(stdout);
    return;
}

void help()  //Function for built-in help command
{
    printf("********************************************************************* \n");
    printf("A Custom Shell \n");
    printf("  - Created by Nicole Tome! :) \n");
    printf("Usage:\n");
    printf("  - This was made to practice making a custom CLI \n");
    printf(" To change shell prompt: use option -p followed by user-defined prompt\n");
    printf("********************************************************************* \n\n");
    printf("BUILTIN COMMANDS:\n");
    printf("exit : exits the shell\n");
    printf("pid : prints the process id of the shell\n");
    printf("ppid : prints the parent process id of the shell \n");
    printf("cd : prints current working directory\n");
    printf("cd <path> : changes current working directory \n");
    printf("help : help manual for custom shell\n\n");
    printf("SYSTEM COMMANDS:\n");
    printf("all system commands can be found by using man pages \n");
    printf("search man pages by command: man followed by user-defined search\n");
    printf("\n\n");
    fflush(stdout);
    return;
}

void handler(int sig)
{
    printf("\n%s> ", globalPrompt);
    fflush(stdout);
    return;
}



int main(int argc, char*argv[]) 
{
    char cmdline[MAXLINE]; /* Command line */

    if (argc==3)
    {
	if(strcmp(argv[1], "-p"))
	{
	    printf("%s -p <prompt> \n", argv[0]);
	    exit(0);
	}
	globalPrompt=argv[2];
    }
 
signal(SIGINT, handler); 
 
while (1) 
    { /* Read */
    printf("%s> ", globalPrompt);                   
    Fgets(cmdline, MAXLINE, stdin); 
    if (feof(stdin))
	exit(0);						/* Evaluate */
    eval(cmdline);
    } 
}
/* $end shellmain */
  
  /* $begin eval */
  /* eval - Evaluate a command line */
void eval(char *cmdline) 
{
    char *argv[MAXARGS]; /* Argument list execve() */
    char buf[MAXLINE];   /* Holds modified command line */
    int bg;              /* Should the job run in bg or fg? */
    pid_t pid;           /* Process id */
		          
    strcpy(buf, cmdline);
    bg = parseline(buf, argv); 
    
    if (argv[0] == NULL)  
        return;   /* Ignore empty lines */

    if (!builtin_command(argv)) 
    { 
        if ((pid = Fork()) == 0)
	{   /* Child runs user job */
            if (execvp(argv[0], argv) < 0) 
	    {
	       printf("Execution failed (in fork) \n %s: Command not found.\n", argv[0]); //Command not found output
               fflush(stdout);
	       exit(1);
            }
        }
	/* Parent waits for foreground job to terminate */
    if (!bg)
    {
        int status;
        if (waitpid(pid, &status, 0) < 0)
	    unix_error("waitfg: waitpid error");
	    fflush(stdout);

    int exitStat = WEXITSTATUS(status);
    if(WIFEXITED(status))
    {
        if (exitStat==0) //Output for exit status code 0
	{
	    printf("Process exited with status code 0 \n");
	    fflush(stdout);
	}
	if(exitStat==1) //Output for exit status code 1
        {
	   printf("Process exited with status code 1 \n");
	   fflush(stdout);
        }	
    }
   }
    else
    {
        printf("%d %s", pid, cmdline);
	fflush(stdout);
    }
        return;
  }
}

  /* If first arg is a builtin command, run it and return true */
int builtin_command(char **argv) 
{
    if (!strcmp(argv[0], "exit"))  //Built-in for exit
    {	
	quit();
    }
    if (!strcmp(argv[0], "&"))  // Ignore singleton & */
    {
	return 1;
    }
    if (!strcmp(argv[0], "help")) //Built-in for help
    {
	help();
	return 1;
    }
    if (!strcmp(argv[0], "pid")) //Built-in for pid
    {
	pid();
	return 1;
    }
    if (!strcmp(argv[0], "ppid")) //Built-in for ppid
    {
	ppid();
	return 1;
    }
    if (!strcmp(argv[0], "cd")) //Built-in for directories: adjusts current directory if prompt is given, prints out the current working directory
    {
	char *newdir = argv[1];
	chdir(newdir);
	printf("Current working directory is: "); 
	currentdir();
	printf("\n");
	fflush(stdout);
	return 1;
    }
    
    return 0;           
}


  /* $end eval */

  /* $begin parseline */
  /* parseline - Parse the command line and build the argv array */
int parseline(char *buf, char **argv) 
{
    char *delim;         /* Points to first space delimiter */
    int argc;            /* Number of args */
    int bg;              /* Background job? */

    buf[strlen(buf)-1] = ' ';  /* Replace trailing '\n' with space */
    while (*buf && (*buf == ' ')) /* Ignore leading spaces */
	buf++;

				    /* Build the argv list */
	argc = 0;   
    while ((delim = strchr(buf, ' '))) {
	argv[argc++] = buf;
	*delim = '\0';
	buf = delim + 1;
	while (*buf && (*buf == ' ')) /* Ignore spaces */
	    buf++;
    }
    
    argv[argc] = NULL;
			    
    if (argc == 0)  /* Ignore blank line */
	return 1;
    if ((bg = (*argv[argc-1] == '&')) != 0)						    
	argv[--argc] = NULL;
	return bg;
}
  /* $end parseline */


