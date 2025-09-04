/**
 * @file    main.h
 * @brief   Brief description
 * @details Detailed description
 *
 * @date    2025-08-28
 * @copyright Copyright (c) 2025 [Company Name]
 */

#ifndef MAIN_H
#define MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
/*********************
 *      DEFINES
 *********************/
#define NAME_MAX_SIZE 32
#define ADDRESS_MAX_SIZE 256
/**********************
 *      TYPEDEFS
 **********************/
typedef enum{
    e_AGE_18 = 0,
    e_AGE_19, e_AGE_20, e_AGE_21, e_AGE_22,
    e_AGE_23, e_AGE_24, e_AGE_25, e_AGE_26,
    e_AGE_27, e_AGE_28, e_AGE_29, e_AGE_30,
    e_AGE_31, e_AGE_32, e_AGE_33, e_AGE_34,
    e_AGE_35, e_AGE_36, e_AGE_37, e_AGE_38, 
    e_AGE_39, e_AGE_40,
} e_age_t;
// typedef uint8_t e_age_t;

typedef struct{
    e_age_t age;
    char address[ADDRESS_MAX_SIZE];
    char name[NAME_MAX_SIZE];
    bool is_online;
} s_person;


/**********************
 * GLOBAL PROTOTYPES
 **********************/
char* read_json_file();
/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*MAIN_H*/
