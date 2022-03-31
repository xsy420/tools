#ifndef TOOLS_PYTHONFT_H
#define TOOLS_PYTHONFT_H
char ** parse_tool( char * tool_name );
int check_arg( int argc , char * argv[], char * tool_name );
void help( char * tool_name );
#endif
