#ifndef Task3_H
#define Task3_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <vector>
#include <cstring>
#include <limits>
#include <pthread.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>

#define LETTER 3
#define LENGTH 13
#define INDEX 0

pthread_mutex_t Mutex;
std::string uncleaned_File;
std::string cleaned_File;
std::vector<std::string> g_array;
std::vector<std::vector<int>> i_array;

int main(int argc, char* argv[]); 
void* map3(void* arg);
void* reduce3(void* arg);
void* sort(void* arg);
bool comp_Str(const int &V1, const int &V2);
void TaskFilter(std::string uncleaned_File);

#endif 
