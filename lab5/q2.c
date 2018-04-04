#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void sort_str(char *strs[], int n);

int main(int argc, char *argv[])
{
  char str_copy[argc][20];
 
  for(int i = 0; i < argc; i++)
    strcpy(str_copy[i], argv[i]);

  pid_t p_1;
  p_1 = fork();

  if(p_1 == 0) //child
  {
   sort_str(argv, argc);

   for(int i = 0; i < argc; i++)
     fprintf(stdout, "%s ", argv[i]);
  }
  else if(p_1 > 0) //parent
  {
    wait(NULL);
    fprintf(stdout, "\n");
    for( int i = 0; i < argc; i++)
      fprintf(stdout, "%s ", str_copy[i]);

  }
  return 0;
}

void sort_str(char *argv[], int argc)
{
   for(int i = 0; i < argc; i++)
    {
      for(int j = 0; j < (argc - i - 1); j++)
      {
        if(strcmp(argv[j], argv[j+1]) > 0)
        {
          char temp[20];
          strcpy(temp, argv[j]);
          strcpy(argv[j], argv[j+1]);
          strcpy(argv[j+1], temp);
        }
      }
    }
}
