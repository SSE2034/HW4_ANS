/* ***************************************************************************************************
 * Copyright (c) 2021 Donghun-Jeong, Seokin-Hong, Sungkyunkwan Universit All Right Reserved
 *
 * - File Name : ppm.h
 * - File Type : c++ header code
 * - File Version(Last Update Date) : 1.0 (Sep. 9, 2021.)
 * - Date : Sep. 9, 2021.
 * - Description : This code is provided declaration header code for SSE2034-41(SKKU, 2021) class HW4.
 *                 Do not modify this code! Do not distribute this code without permission.
 * **************************************************************************************************/

//DO NOT MODIFY THIS CODE! IF THIS CODE IS MODIFIED, YOU WILL GET LOW GRADE!

//enumuarete PROCESS_REUSLT : presents ppm processing results
enum PROCESS_RESULT {
    SUCCESS,          //Both input & output file processing success
    INPUT_ERROR,      //Error with input file processing (ex. not P3 header, width and height not correct, ...)
    OUTPUT_ERROR,     //Error with generationg output files
};


/* ************************************************************************************************************
 * - Function Name : process_ppm
 *
 * - Input Variables
 *   (1) char *in_file_name : input ppm file name
 *   (2) char *out_pbm_name : out pbm file(white/black image file) name
 *   (3) char *out_pgm_name : out pbm file(grayscale image file) name
 *   (4) char *out_ppm_name : out ppm file(color processed rgm image file) name
 *
 * - Output Variable
 *   (1) PROCESS_RESULT enumuaret type variable : which presents ppm processing results
 *
 * - Roles of this function
 *   (1) Read input ascii ppm file(P3 header) using in_file_name
 *   (2) Generate Gray Scale Image from input ppm file -> save it as out_pbm_name
 *   (3) Generate White/Blaock Bitmap image from gray scale results -> save it as out_pgm_name
 *   (4) Generate Inverted Color Image from input ppm file -> save it as out_ppm_name
 *   (5) According to processing results return PROCESS_RESULTS enumaerate type variable
 *   *********************************************************************************************************/
PROCESS_RESULT process_ppm(char *in_file_name, char *out_pbm_name, char *out_pgm_name, char *out_ppm_name);


