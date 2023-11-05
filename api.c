#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
#include <math.h>
#include <Config.h>


int  init(){
    return 0;
}


void uninit(){
    return;
}


int getVersion(char* version){
    return 0；
}


int open(const int32_t* vecChannelID , int32_t* vecHandle){
    return 0;
}


int close(const int32_t* vecHandle){
    return 0;
} 


int  start (const int32_t* vecHandle){
    return 0;
}


int stop(const int32_t* vecHandle){
    return 0;
}


int getCurrentSize(const int32_t* vecHandle , uint64_t* vecCurrentSize){
    return 0;
}


int getHandleInfo(const int32_t* vecHandle , string* vecFileName , uint64_t* vecCurrentSize , int64_t* vecCurrentDuration){
    return 0;
}


int  getState(const int32_t* vecHandle , int32_t* vecState){
    return 0;
}


int setOption(int32_t handle , int32_t optName , void *optVal , uint32_t optLen){
    return 0;
}


int getOption(int32_t handle , int32_t optName , void *optVal , uint32_t optLen){
    return 0;
}


