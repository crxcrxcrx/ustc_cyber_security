#include "ultity.h"

using namespace std;

vector<struct CSVDATA> dataload() {
    std::ifstream inFile("../data_100000.csv", std::ios::in);
    std::string lineStr;
    std::vector<struct CSVDATA> csvData;
    std::getline(inFile, lineStr); // ������һ��(����������)
    while (std::getline(inFile, lineStr)) {
        std::stringstream ss(lineStr); // string��������
        std::string str;
        struct CSVDATA csvdata;
        std::getline(ss, str, ','); // ��ȡ index
        csvdata.index = std::stoi(str);
        std::getline(ss, str, ','); // ��ȡ mac
        csvdata.mac = str;

        csvData.push_back(csvdata);
    }
    return csvData;
}
