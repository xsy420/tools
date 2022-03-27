#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "cJSON.h"

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		printf("Please add a py file to convert or \"--help\" option to show help\n");
		return 1;
	}
	if (strcmp(argv[1], "--help") == 0)
	{
		printf("\033[43;30mThis is file type convertor written by xsy420\033[0m\n\n");
		printf("Usage for py2ipynb tool:\n\n");
		printf("\t./py2ipynb [Option] /any/path/file.py\n\n");
		printf("\033[1mOption\033[m:\n");
		printf("\t--help\n");
		printf("\t\tShow this help and exit\n");
		printf("\033[1mTips\033[m:\n");
		printf("\tWith a \033[3m*.py\033[m file path added and executed, you will get a new \033[3m*.ipynb\033[m file.\n");
		printf("\tAnd the new file will be in the same path and has same name but \033[1msuffix\033[m.\n");
		printf("\n");
		return 0;
	}
	if (strlen(strstr(argv[1], ".py")) != 3)
	{
		printf("Wrong file type, the py file is supported.\n");
		return 2;
	}
	char *py_file = NULL;
	py_file = argv[1];
	FILE *py = NULL;
	py = fopen(py_file, "r");
	if (py == NULL)
	{
		printf("The file %s doesn't exist.\n", py_file);
		return 3;
	}
	char ipynb_file[strlen(py_file)];
	strcpy(ipynb_file, py_file);
	ipynb_file[strlen(py_file) - 2] = 'i';
	ipynb_file[strlen(py_file) - 1] = 'p';
	ipynb_file[strlen(py_file)] = 'y';	
	ipynb_file[strlen(py_file) + 1] = 'n';
	ipynb_file[strlen(py_file) + 2] = 'b';
	ipynb_file[strlen(py_file) + 3] = '\0';
	cJSON *root = cJSON_CreateObject();
	cJSON *cells = cJSON_CreateArray();
	cJSON *cell = cJSON_CreateObject();
	cJSON *source = cJSON_CreateArray();
	cJSON *metadata = cJSON_CreateObject();
	cJSON *kernelspec = cJSON_CreateObject();
	cJSON *language_info = cJSON_CreateObject();
	cJSON *codemirror_mode = cJSON_CreateObject();

	cJSON_AddItemToObject(cell, "cell_type", cJSON_CreateString("code"));
	cJSON_AddItemToObject(cell, "execution_count", cJSON_CreateNumber(1));
	cJSON_AddItemToObject(cell, "id", cJSON_CreateString("12345678"));
	cJSON_AddItemToObject(cell, "metadata", cJSON_CreateObject());
	cJSON_AddItemToObject(cell, "outputs", cJSON_CreateArray());
	cJSON_AddItemToObject(cell, "source", source);	
	cJSON_AddItemToObject(cells, "", cell);
	cJSON_AddItemToObject(kernelspec, "display_name", cJSON_CreateString("Python 3 (ipykernel)"));
	cJSON_AddItemToObject(kernelspec, "language", cJSON_CreateString("python"));
	cJSON_AddItemToObject(kernelspec, "name", cJSON_CreateString("python3"));
	cJSON_AddItemToObject(codemirror_mode, "name", cJSON_CreateString("ipython"));
	cJSON_AddItemToObject(codemirror_mode, "version", cJSON_CreateNumber(3));
	cJSON_AddItemToObject(language_info, "codemirror_mode", codemirror_mode);
	cJSON_AddItemToObject(metadata, "kernelspec", kernelspec);
	cJSON_AddItemToObject(metadata, "language_info", language_info);
	cJSON_AddItemToObject(metadata, "file_extension", cJSON_CreateString(".py"));
	cJSON_AddItemToObject(metadata, "mimetype", cJSON_CreateString("text/x-python"));
	cJSON_AddItemToObject(metadata, "name", cJSON_CreateString("python"));
	cJSON_AddItemToObject(metadata, "nbconvert_exporter", cJSON_CreateString("python"));
	cJSON_AddItemToObject(metadata, "pygments_lexer", cJSON_CreateString("ipython3"));
	cJSON_AddItemToObject(metadata, "version", cJSON_CreateString("3.7.6"));	
	cJSON_AddItemToObject(root, "cells", cells);
	cJSON_AddItemToObject(root, "metadata", metadata);
	cJSON_AddItemToObject(root, "nbformat", cJSON_CreateNumber(4));
	cJSON_AddItemToObject(root, "nbformat_minor", cJSON_CreateNumber(5));
	
	py = fopen(py_file, "r");
	fseek(py, 0L, 2);
	int py_size = ftell(py);
	char line[py_size];
	char py_str[py_size];
	py = fopen(py_file, "r");
	fgets(line, py_size, py);
	strcpy(py_str, line);
	while(1)
	{
		if(fgets(line, py_size, py) == NULL)
		{
			break;
		}
		else
		{
			strcat(py_str, line);
		}
	}
	cJSON_AddItemToArray(source, cJSON_CreateString(py_str));
	fclose(py);
	FILE *ipynb = fopen(ipynb_file, "w");
	fputs(cJSON_Print(root), ipynb);
	fclose(ipynb);
	return 0;
}
