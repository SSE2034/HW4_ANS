/* ***************************************************************************************************
 * Copyright (c) 2021 Donghun-Jeong, Seokin-Hong, Sungkyunkwan Universit All Right Reserved
 *
 * - File Name : main.cc
 * - File Type : c++ source code
 * - File Version(Last Update Date) : 1.0 (Sep. 9, 2021.)
 * - Date : Sep. 9, 2021.
 * - Description : This code is provided main function code for SSE2034-41(SKKU, 2021) class HW4.
 *                 Do not modify this code! Do not distribute this code without permission.
 * **************************************************************************************************/

//!DO NOT MODIFY THIS CODE. IF THIS CODE IS MODIFIED, YOU WILL GET LOW GRADE!

#include <iostream>
#include "ppm.h" //ppm.h for declaration of needed variables or functions.
#include <string> //STL string header, do not use this function in your own hw code. (you have not yet studied about STL or c++ string)

using namespace std;

int main(int argc, char*argv[]){

    //Input Argument Check
    if (argc != 5){
        cout << "Argument Error!" << endl;
        cout << "./main.out in_file_name out_pbm_file_name out_pgm_file_name out_ppm_file_name" << endl;
        cout << "Exit The Program!" << endl;
        exit(1);
    }

    //Input Arguments
    string in_file_name = argv[1];
    string out_pbm_file_name = argv[2];
    string out_pgm_file_name = argv[3];
    string out_ppm_file_name = argv[4];

    PROCESS_RESULT result; //ppm processing results

    if (out_pbm_file_name.find(".pbm") == string::npos) {
        result = OUTPUT_ERROR;
    } else if (out_pgm_file_name.find(".pgm") == string::npos) {
        result = OUTPUT_ERROR;
    } else if (out_ppm_file_name.find(".ppm") == string::npos) {
        result = OUTPUT_ERROR;
    } else if (in_file_name.find(".ppm") != string::npos) { //check file type is ".ppm"
        //running ppm processing and return processing results
        result = process_ppm((char*)in_file_name.c_str(), (char*)out_pbm_file_name.c_str(), (char*)out_pgm_file_name.c_str(), (char*)out_ppm_file_name.c_str()); 
    } else {
        result = INPUT_ERROR;
    }
    
    //Print Processing Results
    switch (result) {
        
        case (SUCCESS):
            cout << "SUCCESS";
            break;
        case (INPUT_ERROR):
            cout << "INPUT_ERROR";
            break;
        case (OUTPUT_ERROR):
            cout << "OUTPUT_ERROR";
            break;
        default:
            cout << "UNKNOWN_ERROR";
            break;
    }

    return 0;
}
