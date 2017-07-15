#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

#define FIELD_SIZE 3 // How many fields per line in this case it is 3

// This is just a custom data structure to hold the data for student want
struct myInfo
{
    myInfo() {} // Default ctor
    myInfo(std::string name1, std::string name2, int n1) // Ctor accepting all data
        : first(name1), last(name2), score(n1) {}
    std::string first, last;
    int score;
};

struct compare_method
{
    inline bool operator() (const myInfo& struct1, const myInfo& struct2)
    {
        bool ret = false;

        if (struct1.score == struct2.score)
        {
            //Ascending order in case scores are same
            if(struct1.last == struct2.last)
            {
                ret = struct1.first < struct2.first;
            }
            else
            {
                ret =  struct1.last < struct2.last;
            }
        }
        else
        {
            //Descending order REQ
            ret = struct1.score > struct2.score;
        }

        return ret;
    }
};

// Convert string to int
int convertStringToInt(const std::string& input)
{
    std::stringstream ss(input);
    int retval;
    ss >> retval;
    return retval;
}

vector<myInfo> readFileToVector(const std::string& filename)
{
    std::ifstream source;
    source.open(filename);
    vector<myInfo> data;
    std::string line;
    std::string delimiter = ",";
    while (std::getline(source, line))
    {
        // Add error checks here.
        // Get first name.
        unsigned long start_pos = 0;
        unsigned long length = line.find(delimiter);
        unsigned long end_pos = line.find(delimiter);
        std::string first = line.substr(start_pos, length);
        first.erase(std::remove(first.begin(), first.end(),' '), first.end());

        // Get last name.
        start_pos = end_pos + 1;
        end_pos = line.find(delimiter, start_pos);
        length =  end_pos - start_pos;
        std::string last = line.substr(start_pos, length);
        last.erase(std::remove(last.begin(), last.end(),' '), last.end());

        // Get score.
        start_pos = end_pos + 1;
        end_pos = line.find(delimiter, start_pos);
        length = end_pos - start_pos;
        std::string score = line.substr(start_pos, length);
        data.push_back(myInfo(first, last, convertStringToInt(score)));
    }

    return data;
}


int main(int argc, const char * argv[])
{
    if(argc == 2)
    {
        // Read your input file
        std::string inputFileName(argv[1]);
        std::vector<myInfo> data = readFileToVector(inputFileName);
        std::cout << "\nUNSORTED\n";
        for (int i(0); i != data.size(); ++i)
        {
            std::cout << "\n" << data[i].last << " " << data[i].first << " " << data[i].score << "\n";
        }

        std::sort(data.begin(), data.end(), compare_method());

        std::string outputFilename = inputFileName;
        std::string::size_type extensionPos = outputFilename.find(".txt");
        if(std::string::npos != extensionPos)
        {
            std::string filenameNoExt = outputFilename.substr(0,extensionPos);
            outputFilename = filenameNoExt;
        }

        outputFilename = outputFilename + std::string("-graded.txt");
        ofstream outputFile;
        outputFile.open(outputFilename);

        bool isFileOpen = outputFile.is_open();

        std::cout << "\nSORTED\n";
        for (int i(0); i != data.size(); ++i)
        {
            std::cout << "\n" << data[i].last << " " << data[i].first << " " << data[i].score << "\n";

            if(isFileOpen)
            {
                outputFile<<data[i].last<<","<<data[i].first<<","<<data[i].score<<std::endl;
            }
        }

        std::cout<<"\nWrote output to file - "<<outputFilename<<std::endl;
        outputFile.close();

    }
    else
    {
        std::cout<<"Usage: grade_scores.exe <grade_fil>"<<std::endl;
    }

    return 0;
}
