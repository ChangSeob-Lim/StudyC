/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.12
  writer - Lim Chang Seob.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef enum _TOKEN_TYPE
{
    TOKEN_STRING,
    TOKEN_NUMBER
} TOKEN_TYPE;

typedef struct _TOKEN
{
    TOKEN_TYPE type;
    
    union
    {
        char* string;
        double number;
    };
    
    bool isArray;

} TOKEN;

#define TOKEN_COUNT  20

typedef struct _JSON
{
    TOKEN tokens[TOKEN_COUNT];
} JSON;

char* readFile(char* filename, int* readsize);
void parseJSON(char* doc, int size, JSON* json);
void freeJSON(JSON* json);


// 메인함수
int main(void) 
{
    int size;
    char* doc = readFile("example.json", &size);

    if (doc == NULL)
    {
        return EXIT_FAILURE;
    }

    JSON json = { 0, };
    parseJSON(doc, size, &json);

    int i = 0;
    while (true)
    {
        if (json.tokens[i].string == 0)
        {
            break;
        }

        printf("%s: %s\n", json.tokens[i].string, json.tokens[i + 1].string);
        i += 2;
    }

    freeJSON(&json);
    free(doc);
    
	system("pause");
	return EXIT_SUCCESS;
}

char* readFile(char* filename, int* readsize)
{
    FILE* fp = fopen(filename, "rb");

    if (fp == NULL)
    {
        return NULL;
    }

    int size;
    char* buffer;

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    buffer = calloc(1, size + 1);

    if (fread(buffer, size, 1, fp) < 1)
    {
        *readsize = 0;
        free(buffer);
        fclose(fp);
        return NULL;
    }

    *readsize = size;
    fclose(fp);
    return buffer;
}

void parseJSON(char* doc, int size, JSON* json)
{
    int tokenIndex = 0;
    int pos = 0;

    if (doc[pos] != '{')
    {
        return;
    }

    pos++;

    while (pos < size)
    {
        switch (doc[pos])
        {
        case '"':;
            char* begin = doc + pos + 1;
            char* end = strchr(begin, '"');

            if (end == NULL)
            {
                break;
            }

            int stringLength = end - begin;
            json->tokens[tokenIndex].type = TOKEN_STRING;
            json->tokens[tokenIndex].string = calloc(1, stringLength + 1);
            memcpy(json->tokens[tokenIndex].string, begin, stringLength);
            tokenIndex++;
            pos = pos + stringLength + 1;
            break;
        }

        pos++;
    }
}

void freeJSON(JSON* json)
{
    for (int i = 0; i < TOKEN_COUNT; i++)
    {
        if (json->tokens[i].type == TOKEN_STRING)
        {
            free(json->tokens[i].string);
        }
    }
}
