#include <stdio.h>
#include "string.h"
#include "pythonFT.h"

void show_tools()
{
  printf("\033[43;30mThis is file type convertor written by xsy420\033[0m\n");
  printf("Please choose a tool_name\n");
  printf("1: change ipynb to py\n");
  printf("2: change py to ipynb\n");
}

char * get_tool(int tool)
{
  switch (tool) {
    case 1: {
      return "ipynb py";
    }
    case 2: {
      return "py ipynb";
    }
    default: {
      printf("Wrong Index\n");
      return NULL;
    }
  }
}

char ** split_toolname( char * tool_name )
{
  static char* split[2];
  split[0] = (char *) malloc(5);
  split[1] = (char *) malloc(5);
  sscanf(tool_name, "%s %s", split[0], split[1]);
  return split;
}

int check_source_file( char * source_file )
{
  return 1;
}

char * get_source_file()
{
  char * source_file = NULL;
  if (check_source_file(source_file)) {
    return "";
  }
  return "";
}

int check_arg( int argc , char * argv[], char * tool_name )
{
  if ( argc == 1 )
  {
    printf("Please add a %s file to convert or \"--help\" option to show help\n", split_toolname(tool_name)[0]);
  }
  return 1;
}

void help( char * tool_name )
{
  char** parse = split_toolname(tool_name);
  printf("\033[43;30mThis is file type convertor written by xsy420\033[0m\n\n");
  printf("Usage for %s tool:\n\n", tool_name);
  printf("\t./%s [Option] /any/path/file.%s\n\n", tool_name, parse[0]);
  printf("\033[1mOption\033[m:\n");
  printf("\t--help:\n");
  printf("\t\tShow this help and exit\n");
  printf("\033[1mTips\033[m:\n");
  printf("\tWith a \033[3m*.%s\033[m file path added and executed, you will get a new \033[3m*.%s\033[m file.\n", parse[0], parse[1]);
  printf("\tAnd the new file will be in the same path and has same name but different \033[1msuffix\033[m.\n");
  printf("\n");
}
