#include "TaskFilter.h"
#include "Utils.h"


int main(int argc, char* argv[]){

    std::string uncleaned_File = argv[1];
    std::string cleaned_File = argv[2];
    TaskFilter(uncleaned_File, cleaned_File);

    return 0;
}; 

void TaskFilter(std::string uncleaned_File, std::string cleaned_File){
    std::ofstream clean;
    std::ifstream dirty;
    std::string word;

    std::cout << "Open and clean" << uncleaned_File << "\n";
    dirty.open(uncleaned_File);
    
    std::cout << "Open and write clean version of dirty file in " << cleaned_File << "\n";
    clean.open(cleaned_File);

    std::cout << "Writing to " << cleaned_File << "\n";

    if(dirty && clean){
        while(!dirty.eof()){ 
            getline(dirty,word);
              if ((word.length() >= 3)){
                 if (word.length() <= 15){
                    if (Alphabets(word)){
                       clean << word << '\n'; 
                    }
                }
            }
        }
    }
    
    //close dirty file
    std::cout << "Close " << uncleaned_File << '\n';
    dirty.close();

    //close clean file
    std::cout << "Close " << cleaned_File << '\n';
    clean.close();
}