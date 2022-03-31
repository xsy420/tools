#ifndef TOOLS_PYTHONFT_H
#define TOOLS_PYTHONFT_H
void * malloc(unsigned long length);
void show_tools();
char * get_tool(int tool);
char * get_source_file();
int check_source_file( char * source_file );
char ** split_toolname( char * tool_name );
int check_arg( int argc , char * argv[], char * tool_name );
void help( char * tool_name );
#endif
