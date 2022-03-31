#include <stdio.h>
#include "string.h"
#include "pythonFT.h"
#include "cjson/cJSON.h"

int main( int argc, char * argv[] )
{
  char * tool_name = NULL;
  int tool;
  while (tool_name == NULL) {
    show_tools();
    scanf("%d", &tool);
    fflush(stdin);
    getchar();
    tool_name = get_tool(tool);
  }
  char * source_file = get_source_file();
  cJSON * test = NULL;
//  if (argc == 1) {
//    return check_arg( argc, argv, tool_name );
//  }
//  if (strcmp(argv[1], "--help") == 0) {
//    help( tool_name );
//  }
  printf("%s and %s\n", split_toolname(tool_name)[0], split_toolname(tool_name)[1]);
  return 0;
}
