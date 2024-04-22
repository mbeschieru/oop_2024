#include <iostream>
#include <fstream>
#include <string>
#include <map>

bool isSeparator(char ch) {
    if (ch == ' ' || ch == ',' || ch == '?' || ch == '!' || ch == '.' || ch == '\n')
        return true;
    return false;
}

bool cmp(std::pair<std::string, int> &a,
         std::pair<std::string, int> &b) {
   if (a.second == b.second)
       return a.first < b.first;
   return a.second > b.second;
}

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file!";
        return 1;
    }
    std::string line;
    std::map<std::string, int> myMap;
    while (std::getline(inputFile, line)) {
        int i = 0;
        while (line[i] != '\0') {
            while (isSeparator(line[i]) && line[i] != '\0')
                i++;
            std::string newWord;
            while (!isSeparator(line[i]) && line[i] != '\0')
                newWord += tolower(line[i]), i++;
            if (!newWord.empty()) {
                myMap[newWord]++;
            }
        }
    }
    inputFile.close();
    std::cout<<"\nMap before sorting : \n\n";
    for (const auto& pair: myMap) {
        std::cout << pair.first << " => " << pair.second << '\n';
    }
    std::cout<<"\nMap after sorting : \n\n";
    std::vector<std::pair<std::string , int > > pairs;
    pairs.reserve(myMap.size());
    for (auto& it : myMap) {
        pairs.push_back(it);
    }

    std::sort(pairs.begin(),pairs.end(),cmp);
    for(const auto& it : pairs ) {
        std::cout<<it.first<<" => "<<it.second<<'\n';
    }

    return 0;
}
