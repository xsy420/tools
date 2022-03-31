#include <stdio.h>
#include "string.h"
#include "pythonFT.h"
#include "std_extend.h"

char ** parse_tool( char * tool_name )
{
  char** split = (char **)malloc(sizeof(char*) * 2);
  *split = "py";
  *(split + 1) = "ipy";
  return split;
}

int check_arg( int argc , char * argv[], char * tool_name )
{
  if ( argc == 1 )
  {
    printf("Please add a %s file to convert or \"--help\" option to show help\n", tool_name);
  }
  return 0;
}

void help( char * tool_name )
{
    printf("\033[43;30mThis is file type convertor written by xsy420\033[0m\n\n");
    printf("Usage for %s tool:\n\n", tool_name);
    printf("\t./%s [Option] /any/path/file.ipynb\n\n", tool_name);
    printf("\033[1mOption\033[m:\n");
    printf("\t--help:\n");
    printf("\t\tShow this help and exit\n");
    printf("\033[1mTips\033[m:\n");
    printf("\tWith a \033[3m*.ipynb\033[m file path added and executed, you will get a new \033[3m*.py\033[m file.\n");
    printf("\tAnd the new file will be in the same path and has same name but different \033[1msuffix\033[m.\n");
    printf("\n");
}
