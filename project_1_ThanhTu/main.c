/**
 * @file    main.c
 * @brief   Brief description
 * @details Detailed description
 *
 * @date    2025-08-25
 * @copyright Copyright (c) 2025 [Company Name]
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
// #include ""
/*********************
 *      DEFINES
 *********************/
#define NUMBER 30
/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
char* read_json_file(const char* path_file);
int parse_person_info(const char *json, s_person* p);
/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
int main() {
    char* json = read_json_file("data.json");
    if (!json) return -1;
    
    s_person* person = malloc(sizeof(s_person) * NUMBER);
    memset(person, 0, sizeof(s_person) * NUMBER);

    const char* p_ptr = json;
    int count = 0;

    for (int i = 0; i < NUMBER; i++) {
        const char *p_name = strstr(p_ptr, "\"Name\"");
        if (!p_name) break;
        parse_person_info(p_name, &person[i]);
        printf("Name: %s\n", person[i].name);
        printf("Age: %d\n", person[i].age);
        printf("Address : %s\n", person[i].address);
        printf("Online: %s\n", person[i].is_online ? "true" : "false");
        count++;
        p_ptr = p_name + 1;
    }

    free(person);
    free(json);
    return 0;
}


/**********************
 *   STATIC FUNCTIONS
 **********************/
char* read_json_file(const char* path_file)
{
    long l_size_f;
    FILE* f;

    f = fopen(path_file, "r");
    if (f == NULL){
        printf("Can't not access file\n");
        return NULL;
    }
    fseek(f, 0, SEEK_END);
    l_size_f = ftell(f);
    fseek(f, 0, SEEK_SET);

    char* f_buff = malloc(l_size_f + 1);
    if(f_buff == NULL)
    {
        fclose(f);
        return NULL;
    }
    fread(f_buff, 1, l_size_f, f);

    f_buff[l_size_f] = '\0';
    fclose(f);
    return f_buff;
}

int parse_person_info(const char *json, s_person* person)
{
    int age;
    //syntas strstr: char* strstr(char a[], char b[])

    char* p_name = strstr(json, "\"Name\"");    //{ "Name": "abcd" }
    // printf(p_name);
    if(p_name)
    {
        sscanf(p_name, "\"Name\": \"%[^\"]\"", person->name);
    }

    char* p_age = strstr(json, "\"Age\"");  
    if(p_age)
    {
        sscanf(p_age, "\"Age\": %d", &age);
    }
    
    if (age >= 18 && age <= 40) 
    {
        person->age = (e_age_t)(age - 18);
    }
    else person->age = 0;   //default 0

    char* p_addr = strstr(json, "\"Address\"");
    if(p_addr)
    {
        sscanf(p_addr, "\"Address\": \"%[^\"]\"", person->address);
    }

    char* p_online = strstr(json, "\"Online\"");
    if (p_online) 
    {
        char val[] = {0};
        sscanf(p_online, "\"Online\": %s", val);
        person->is_online = (strcmp(val, "true") == 0);
    }

    return 0;
}