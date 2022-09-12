#include "Task2.h"
#include "Utils.h"


int main(int argc, char* argv[]){

    std::string uncleaned_File = argv[1];
    std::string cleaned_File = argv[2];

    std::cout << "Data Filteration\n";
    TaskFilter(uncleaned_File);

    std::cout << "Data Sorting \n";
    Map2();

    std::cout << "Merge sort (13 --> 1)\n";
    reduce2(cleaned_File);

    return 0;
}; 

void TaskFilter(std::string uncleaned_File){

    std::ifstream dirty;
    std::string word;

    std::cout << "Opening " << uncleaned_File << " to clean \n";
    dirty.open(uncleaned_File);
    if(dirty){
        while(!dirty.eof()){ 
            getline(dirty,word);
            if ((word.length() >= 3)){
                 if (word.length() <= 15){
                    if (Alphabets(word)){
                        g_array.push_back(word);
                    }
                }
            }
        }
    
    }
    
    std::cout << "Close " << uncleaned_File << "\n";
    dirty.close();
}


pid_t Map2(){
    std::vector<std::vector<std::string>> vec;
    vec.push_back(std::vector<std::string>());
    vec.push_back(std::vector<std::string>());
    vec.push_back(std::vector<std::string>());
    vec.push_back(std::vector<std::string>());
    vec.push_back(std::vector<std::string>());
    vec.push_back(std::vector<std::string>());
    vec.push_back(std::vector<std::string>());
    vec.push_back(std::vector<std::string>());
    vec.push_back(std::vector<std::string>());
    vec.push_back(std::vector<std::string>());
    vec.push_back(std::vector<std::string>());
    vec.push_back(std::vector<std::string>());
    vec.push_back(std::vector<std::string>());

    std::cout << "Separating words into lists\n";
    int index;
    for(uint i= 0; i < g_array.size(); i++){
        index = g_array[i].length() - LETTER;
        vec[index].push_back(g_array[i]);
    }
    
    std::cout << "Creating forks\n";
    for (int i = 0 ; i < LENGTH ; i++){
        if(fork() == 0) {
            std::sort(vec[i].begin(), vec[i].end(), comp);
            std::ofstream write;
            std::string f_name = std::string("wordLengthOf").append(std::to_string(i + LETTER).append(".txt"));
            write.open(f_name);
            if(write){
                for(uint e = 0; e < vec[i].size(); e++){
                    write<<vec[i][e]<<"\n";
                    
                }
            }       
            write.close();
           // std::cout<<"close"<<std::endl;
            exit(0);
            
        }
    }
    while(wait(NULL) != -1 || errno != ECHILD);
    return EXIT_SUCCESS;

}
    

void reduce2(std::string cleaned_File)
{
    std::ifstream w_list_all[LENGTH];
    std::ofstream clean_output = std::ofstream(cleaned_File);

    for(int i = LETTER; i < LETTER + LENGTH; i++)
    {
        std::string f_name = std::string("wordLengthOf").append(std::to_string(i).append(".txt"));
        w_list_all[i - LETTER] = std::ifstream(f_name);
    }

    std::vector<std::string> Sortwords;
    for(int i = 0; i < LENGTH; i++)
    {
        std::string word;
        std::getline(w_list_all[i], word);      
        Sortwords.push_back(word);
    }

    std::cout << "Sorting & writting words to the file as output" << std::endl;

    std::string word;
    std::cout << Sortwords.size() << '\n';
    while(!Sortwords.empty())
    {
        std::sort(Sortwords.begin(), Sortwords.end(), comp);
        std::string smallest_Word = Sortwords[0];
        int len = smallest_Word.length();
        clean_output << smallest_Word << '\n';
        Sortwords.erase(Sortwords.begin());

        
        if(!w_list_all[len - LETTER].eof())
        {
            std::getline(w_list_all[len - LETTER], word);
            if(!word.empty())
                {Sortwords.push_back(word);}
        }
    }

    for(std::ifstream& file : w_list_all){
        file.close();
        }
    clean_output.close();
}


