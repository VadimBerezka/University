#include <iostream>
#include <fstream>
#include <clocale>
#include <string>

using namespace std;

// ������� ������ ������ � ����
void writeToFile(const string& filename, const string& content) {
    ofstream file(filename);
    if (file.is_open()) {
        file << content;
        file.close();
    }
}

// ������� ������ ������ �� ����� � ������ ���� � ������ ����
void readFromFile(const string& filename, const string& outputFilename) {
    ifstream file(filename);
    ofstream outputFile(outputFilename);
    if (file.is_open() && outputFile.is_open()) {
        string word;
        while (file >> word) {
            if (!isdigit(word[0])) {
                outputFile << word << ' ';
            }
        }
        file.close();
        outputFile.close();
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    string input;
    cout << "������� ������ ��������: ";
    getline(cin, input);

    string filename = "input.txt";
    writeToFile(filename, input);

    string outputFilename = "output.txt";
    readFromFile(filename, outputFilename);

    return 0;
}
