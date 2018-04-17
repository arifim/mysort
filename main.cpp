#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include "sort.cpp"


int main(int argc, char* argv[]) {

    if (argc < 2) { std::cout << "Requared file\n"; exit(1); }

    std::string fileName;
    std::string sort_by_numbers_flag;

    for (int i = 0; i < argc; i++) {
        if (std::regex_match(argv[i], std::regex("\\/(\\w+\\/)+\\w+\\.\\w{1,3}$")))
            fileName = argv[i];
        if (strcmp(argv[i], "-n") == 0)
            sort_by_numbers_flag = argv[i];
    }
    std::fstream *file = new std::fstream(fileName, std::ios::in);
    if (!file->is_open()) {
        std::cout << "Cannot open file. Be sure if file name is givven write.\n";
        delete file;
        exit(1);
    }
    if (!sort_by_numbers_flag.empty()) {
        std::vector<int> text;
        std::string temp;
        int num;
        while (getline(*file, temp)) {
            if (num = atoi(temp.c_str()))
                text.push_back(num);
        }
        quick_sort(text, 0 ,text.size());
        for(int i = 0; i < text.size(); i++)
            std::cout << text[i] << std::endl;
    }
    else {
        std::vector<std::string> text;
        std::string temp;
        while (getline(*file, temp))
            text.push_back(temp);
        quick_sort(text, 0 ,text.size());
        for(int i = 0; i < text.size(); i++)
            std::cout << text[i] << std::endl;
    }
    file->close();
    delete file;
    return 0;
}