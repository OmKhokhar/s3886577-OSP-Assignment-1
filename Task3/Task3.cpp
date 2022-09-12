#include "Task3.h"
#include "Utils.h"

const char* fifo_Name[13] = {"fifo_length3","fifo_length4","fifo_length5","fifo_length6","fifo_length7","fifo_length8","fifo_length9","fifo_length10","fifo_length11","fifo_length12","fifo_length13","fifo_length14","fifo_length15"};

int main(int argc, char* argv[]){
    
    uncleaned_File = argv[1];
    cleaned_File = argv[2];

    TaskFilter(argv[1]);

    pthread_t thread[2];
    for(int i = 0; i < LENGTH; i++){
        if(mkfifo(fifo_Name[i], 0777) == -1){
            perror("Already created");
        }
    }

    if(pthread_create(&thread[1], NULL, &reduce3, NULL) != 0) 
    {
        perror("Create thread: Failed");
    }
    if(pthread_create(&thread[0], NULL, &map3, NULL) != 0) 
    {
        perror("Create thread: Failed");
    }
    if (pthread_join(thread[1], NULL) != 0) {
        perror("Join thread: Failed");
    }
    if (pthread_join(thread[0], NULL) != 0) {
        perror("Join thread: Failed");
    }
    return 0;
}; 

void* reduce3(void* arg){
    std::vector<std::vector<std::string>> finaList;
    std::vector<std::string> Sortwords;
    std::string word;
    int fd[LENGTH];
    uint i;

    fd[0] = open(fifo_Name[0], O_RDWR);
    if(fd[0] == -1){
        perror("Can't open");
    }
    finaList.push_back(std::vector<std::string>());

    fd[1] = open(fifo_Name[1], O_RDWR);
    if(fd[1] == -1){
        perror("Can't open");
    }
    finaList.push_back(std::vector<std::string>());

    fd[2] = open(fifo_Name[2], O_RDWR);
    if(fd[2] == -1){
        perror("Can't open");
    }
    finaList.push_back(std::vector<std::string>());

    fd[3] = open(fifo_Name[3], O_RDWR);
    if(fd[3] == -1){
        perror("Can't open");
    }
    finaList.push_back(std::vector<std::string>());

    fd[4] = open(fifo_Name[4], O_RDWR);
    if(fd[4] == -1){
        perror("Can't open");
    }
    finaList.push_back(std::vector<std::string>());

    fd[5] = open(fifo_Name[5], O_RDWR);
    if(fd[5] == -1){
        perror("Can't open");
    }
    finaList.push_back(std::vector<std::string>());

    fd[6] = open(fifo_Name[6], O_RDWR);
    if(fd[6] == -1){
        perror("Can't open");
    }
    finaList.push_back(std::vector<std::string>());

    fd[7] = open(fifo_Name[7], O_RDWR);
    if(fd[7] == -1){
        perror("Can't open");
    }
    finaList.push_back(std::vector<std::string>());

    fd[8] = open(fifo_Name[8], O_RDWR);
    if(fd[8] == -1){
        perror("Can't open");
    }
    finaList.push_back(std::vector<std::string>());

    fd[9] = open(fifo_Name[9], O_RDWR);
    if(fd[9] == -1){
        perror("Can't open");
    }
    finaList.push_back(std::vector<std::string>());

    fd[10] = open(fifo_Name[10], O_RDWR);
    if(fd[10] == -1){
        perror("Can't open");
    }
    finaList.push_back(std::vector<std::string>());

    fd[11] = open(fifo_Name[11], O_RDWR);
    if(fd[11] == -1){
        perror("Can't open");
    }
    finaList.push_back(std::vector<std::string>());

    fd[12] = open(fifo_Name[12], O_RDWR);
    if(fd[5] == -1){
        perror("Can't open");
    }
    finaList.push_back(std::vector<std::string>());


    for(i = 0;i < LENGTH; i++){
        for( uint p = 0; p < i_array[i].size(); p++){
            if(read(fd[i], &word, sizeof(std::string)) == -1){
                perror("Can't read");
            }else {
                finaList[i].push_back(word);
            }
        }
        Sortwords.push_back(finaList[i][0]);
        close(fd[i]);
    }
    std::ofstream out;
    out.open(cleaned_File);
    int arr_index[LENGTH] = {INDEX,INDEX,INDEX,INDEX,INDEX,INDEX,
    INDEX,INDEX,INDEX,INDEX,INDEX,INDEX};

    while(!Sortwords.empty())
    {
        std::sort(Sortwords.begin(), Sortwords.end(), comp);
        std::string& smallest_Word = Sortwords[0];
        int length =smallest_Word.length();
        out << smallest_Word << '\n';
        arr_index[length-LETTER] += 1;

        Sortwords.erase(Sortwords.begin());
        while(arr_index[length-LETTER] != (int)finaList[length-LETTER].size())
        {
            word = finaList[length-LETTER][arr_index[length-LETTER]];
            if(!word.empty())
            {
                Sortwords.push_back(word);
                break;
            }
        }
    }

    out.close();
    double totalWords = g_array.size();
    for(i = 0;i < LENGTH; i++){
        std::cout << "Total words of length " << i + LETTER <<  " = " << finaList[i].size() <<'\n';
        std::cout << "Percentage of the words of length " << i + LETTER << " = " << ((double)finaList[i].size() / totalWords) *100 << '\n';
    }
    pthread_exit(arg);
}

void* map3(void* arg){
    i_array.push_back(std::vector<int>());
    i_array.push_back(std::vector<int>());
    i_array.push_back(std::vector<int>());
    i_array.push_back(std::vector<int>());
    i_array.push_back(std::vector<int>());
    i_array.push_back(std::vector<int>());
    i_array.push_back(std::vector<int>());
    i_array.push_back(std::vector<int>());
    i_array.push_back(std::vector<int>());
    i_array.push_back(std::vector<int>());
    i_array.push_back(std::vector<int>());
    i_array.push_back(std::vector<int>());
    i_array.push_back(std::vector<int>());
    
    for(size_t i = 0; i < g_array.size(); i++ ) {
        i_array[g_array[i].length() - LETTER].push_back(i);
    }
    pthread_t th[LENGTH];
    int i;
    for (i = LETTER; i < LENGTH + LETTER; i++) {
        int* a = (int*)malloc(sizeof(int)); 
        *a = i - 3;
        if(pthread_create(&th[*a], NULL, &sort, a) != 0) {
            perror("Failed to create thread");
        }
    }
    for (i = LETTER; i < LENGTH + LETTER; i++) {
        if (pthread_join(th[i-LETTER], NULL) != 0) {
            perror("Failed to join thread");
        }
    }
    
    pthread_exit(arg);
} 

void* sort(void* arg){
    int wordLength = *(int*)arg;
    std::vector<std::string> Sortwords;
    std::sort(i_array[wordLength].begin(), i_array[wordLength].end(), comp_Str);
    int fd = open(fifo_Name[wordLength], O_RDWR);
    std::string* word = new std::string;
    for(uint i = 0; i < i_array[wordLength].size(); i++){
        word = &g_array[i_array[wordLength][i]];
        int writeF = write(fd, word, sizeof(std::string));
        if(writeF == -1){ //sizeof(std::string))
            perror("Unable to write");
            //break;
        }
    }
    close(fd);
    free(arg);
    pthread_exit(arg);
}

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



bool comp_Str(const int &V1, const int &V2) {
    return strcmp(g_array[V1].data() + 2, g_array[V2].data() + 2) < 0;


}


