/**
 * @file    main.c
 * @brief   Read bin convert to json file
 *
 * @date    2025-09-24
 */

/*********************
 *      INCLUDES
 *********************/
#include <Stdio.h>
#include <stdint.h>
/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
typedef struct
{
    uint32_t id_file;
    uint32_t number_record;
    uint16_t version;
} s_header_t;
// 12byte (4 4 2 + 2padding)

typedef struct
{
    //8byte
    double lati;
    double longi;
    //4 byte
    uint32_t sensor_id;
    uint32_t timestamp;
    float rain_fall;
    float uv;
    float light;
    float temp;
    float hump;
    float press;
    float wind_speed;
    //2 byte
    uint16_t co2;
    uint16_t wind_direction;
    //1 byte
    uint8_t baterry;
} s_weatherRecord_t;
//64byte: 57+1+7padding

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
int main()
{
    return 0;
}
/**********************
 *   STATIC FUNCTIONS
 **********************/