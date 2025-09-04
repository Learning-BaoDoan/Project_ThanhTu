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

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
char read_json_file();
/**********************
 *  STATIC VARIABLES
 **********************/
int main() {
    char data = read_json_file("data.json");
    if (data) {
        printf("%s \n", data);
        // free(data);
    }
    return 0;
}
/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**********************
 *   STATIC FUNCTIONS
 **********************/
char* read_json_file(path_file)
{
    FILE *f;
    f = fopen(path_file, "r");
    if (f == NULL){
        printf("Can't not access file\n");
    }
    fseek(f, 0, SEEK_END);
    long l_size_f = ftell(f);
    fseek(f, 0, SEEK_SET);

    char* f_buff = malloc(l_size_f + 1);
    if(f_buff == NULL)
    {
        fclose(f);
    }

    fread(f_buff, 1, l_size_f, f);
    fclose(f);
    return* f_buff;
}