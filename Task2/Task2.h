#ifndef Task2_H
#define Task2_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <vector>
#include <set>
#include <cstring>
#include <limits>

#define LETTER 3
#define LENGTH 13

std::vector<std::string> g_array;

int main(int argc, char* argv[]);
void reduce2(std::string cleaned_File);
void TaskFilter(std::string uncleaned_File);
pid_t Map2();

#endif 