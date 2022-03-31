#include "pythonFT.h"
#include "std_extend.h"

int main( int argc, char * argv[] )
{
  char * tool_name = "ipynb2py";
  printf("%s and %s\n", *parse_tool(tool_name), *(parse_tool(tool_name) + 1));
  check_arg( argc, argv, tool_name );
  help( tool_name );
  return 0;
}
