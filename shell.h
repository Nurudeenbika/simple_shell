#ifndef _SHELL_H_
#define _SHELL_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>


/*global variables*/

char **create_env(char *envp[]);
void _updateoldpwd(char *buf, char **myenv);
void _updatepwd(char *buf, char **myenv);

/*setenv*/
int _issetenv(char **p, char ***myenv, int *e, int loop, char *v[]);
void _setenv(char **p, char ***myenv, int *e, int loop, char *v[]);
void _setenvcreat(char ***myenv, int *e, char *entirenv);

/* unsetenv*/
int _isunsetenv(char **p, char **myenv, int *e, int loop, char *v[]);
void _unsetenv(char **p, char **myenv, int *e, int loop, char *v[]);
void _errorenv(char **p);

/* shell functions*/
void _noargv(char *argv[], char *envp[]);
void _yesargv(char *argv[], char *envp[]);
void functions(char *line, int loop, char *argv[], char ***m, int *e, char *f);
int rev(char **p, int L, char *li, char **v, char ***m, int *e, char *f);
char *str_concat(char *s1, char *s2);
int _strlen(char *s);
void *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
char *_getline(int *a, char **m, int e);
char  *_getlineav(int *a, char **m, int e, char **av);
char **parsing(char *line);
char *_comments(char *line);
int semicolon(char *line, int loop, char **argv);
int currentstatus(int *status);

/*char _getline_av(char *buffer);*/
void free_grid(char **grid, int height);
void _frk(char **p, char *l, int a, int L, char **v, int e, char **m, char *f);
void *_calloc(unsigned int nmemb, unsigned int size);
char **checkbin(char **b, char **m);
void *_realloc2(char *a, char *p, unsigned int old, unsigned int new_size);
int  _isexit(char **p, int L, char *l, char **v, char **m, char *f);
void _signal(int s);
int _isenv(char **p, char **myenv);
void _env(char **myenv);
void _cd(char **a, int loop, char *v[], char **myenv);
int _iscd(char **p, int loop, char *v[], char **myenv);
char *_gethome(char **m);
char *_changepwd(void);
char *_changeoldpwd(void);
char *_getpwd(char **m);
int _atoi(char *s);
char *_strtoky(char *s, char *d);
char *_strtoky2(char *s, char *d);

#define SIZE 1024

/* help files*/
int _ishelp(char **p, int loop, char *v[], char **m);
void _help_builtin(char **p, int loop, char *v[], char **m);
void _help(char **p, int loop, char *v[], char **m);
ssize_t read_help(char **m);
ssize_t read_cdhelp(char **m);
ssize_t read_exithelp(char **m);
ssize_t read_helphelp(char **m);

/* errors */
void _put_err(char **p, int loop, int sig, char *v[]);
void _builtinerr(char **p);
void _builtinerr2(char **p);
void _errorcd(char **p);
void _errorexit(char **p);
void _errorhelp(char **p);
void _errorgarbage(char **p);
void print_number(int n);

#endif

