#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		printf("Please add a ipynb file to convert or \"--help\" option to show help\n");
		return 1;
	}
	if (strcmp(argv[1], "--help") == 0)
	{
		printf("\033[43;30mThis is file type convertor written by xsy420\033[0m\n\n");
		printf("Usage for ipynb2py tool:\n\n");
		printf("\t./ipynb2py [Option] /any/path/file.ipynb\n\n");
		printf("\033[1mOption\033[m:\n");
		printf("\t--help:\n");
		printf("\t\tShow this help and exit\n");
		printf("\033[1mTips\033[m:\n");
		printf("\tWith a \033[3m*.ipynb\033[m file path added and executed, you will get a new \033[3m*.py\033[m file.\n");
		printf("\tAnd the new file will be in the same path and has same name but different \033[1msuffix\033[m.\n");
		printf("\n");
		return 0;
	}
	if (strlen(strstr(argv[1], ".ipynb")) != 6)
	{
		printf("Wrong file type, the ipynb file is supported.\n");
		return 2;
	}
	char *ipynb_file = NULL;
	ipynb_file = argv[1];
	FILE *ipynb = NULL;
	ipynb = fopen(ipynb_file, "r");
	if (ipynb == NULL)
	{
		printf("The file %s doesn't exist.\n", ipynb_file);
		return 3;
	}
	int temp_length = strlen(ipynb_file) + 5;
	char temp_file[temp_length];
	strcpy(temp_file, ipynb_file);
	strcat(temp_file, ".temp");
	int py_length = strlen(ipynb_file);
	char py_file[py_length];
	strcpy(py_file, ipynb_file);
	py_file[py_length - 5] = 'p';
	py_file[py_length - 4] = 'y';
	py_file[py_length - 3] = '\0';
	int command_length = 30 + 2 * strlen(ipynb_file);
	char command[command_length];
	strcpy(command, "sed \":a;N;s/\\n//g;ta\" ");
	strcat(command, ipynb_file);
	strcat(command, " > ");
	strcat(command, temp_file);
	system(command);
	ipynb = fopen(temp_file, "r");
	fseek(ipynb, 0L, 2);
	int file_size = ftell(ipynb);
	ipynb = fopen(temp_file, "r");
	cJSON *ipynb_json = NULL;
	cJSON *arrayItem = NULL;
	cJSON *object = NULL;
	cJSON *item = NULL;
	cJSON *source = NULL;
	int cell_index = 0;
	int source_index;
	char line[file_size];
	char py_str[file_size];
	fgets(line, file_size, ipynb);
	ipynb_json = cJSON_Parse(line);
	arrayItem = cJSON_GetObjectItem(ipynb_json, "cells");
	while(1)
	{
		source_index = 0;
		object = cJSON_GetArrayItem(arrayItem, cell_index);
		if (NULL == object)
		{
			break;
		}
		item = cJSON_GetObjectItem(object, "source");
		source = cJSON_GetArrayItem(item, source_index);
		if (NULL == source)
		{
			cell_index++;
			strcat(py_str, "\n");
			continue;
		}
		strcat(py_str, source -> valuestring);
		if (!strstr(source -> valuestring, "\n"))
		{
			strcat(py_str, "\n");
		}
		while (NULL != source -> next)
		{
			source = cJSON_GetArrayItem(item, ++source_index);
			strcat(py_str, source->valuestring);
			if (!strstr(source -> valuestring, "\n"))
			{
				strcat(py_str, "\n");
			}
		}
		cell_index++;
	}
	cJSON_Delete(ipynb_json);
	fclose(ipynb);
	strcpy(command, "rm -f ");
	strcat(command, temp_file);
	system(command);
	FILE *py = fopen(py_file, "w");
	fwrite(py_str, 1, strlen(py_str), py);
	fclose(py);
	return 0;
}
