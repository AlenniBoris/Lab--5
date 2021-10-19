#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void OpenFiles(ifstream& file1, ofstream& file2, ofstream& file3) {
    if (file1.is_open() && file2.is_open() && file3.is_open()) {
        cout << "\nAll files are opened" << endl << endl;
    }
    else {
        cout << "Some file isn't opened" << endl;
    }
}
void closeFiles(ifstream& file1, ofstream& file2, ofstream& file3) {
    file3.close();
    file2.close();
    file1.close();
    if (file1.is_open() || file2.is_open() || file3.is_open())
        cout << "some file isn't closed" << endl << "ERROR" << endl;
    else
        cout << "Programm finished" << endl;
}
bool isNumber(char a) {
if (a == '0' || a == '1' || a == '2' || a == '3' || a == '4' || a == '5' || a == '6' || a == '7' || a == '8' || a == '9'){
        return true;
    }
    return false;
}
bool LettersLatin(char StringInput) {
    if (StringInput < 'a' || StringInput > 'z'){
        if (StringInput < 'A' || StringInput > 'Z'){
            return false;
        }
    }
    return true;
}
int strlength(string StringInput) {
    int i = 0;
    while (StringInput[i] != '\0') { i++; }
    return i + 1;
}
void Answer(string StringInput, ofstream& File_with_Letters, ofstream& File_with_Numbers) {
    int length = strlength(StringInput);
    string numbers;
    string letters;
    for(int i = 0; i < length; ++i) {
        if (isNumber(StringInput[i])) {
            numbers.push_back(StringInput[i]);
        } else if (LettersLatin(StringInput[i])){
            letters.push_back(StringInput[i]);
        }
    }
    File_with_Letters << letters;
    File_with_Numbers << numbers;
}
int main() {
    ifstream InputFile("InputFile.txt");
    ofstream File_with_Letters("file_with_letters.txt");
    ofstream File_with_Numbers("file_with_numbers.txt");
    string StringInput;
    OpenFiles(InputFile, File_with_Letters, File_with_Numbers);
    while (getline(InputFile, StringInput)){
        Answer( StringInput,File_with_Letters, File_with_Numbers);
    }
    closeFiles(InputFile, File_with_Letters, File_with_Numbers);
    return 0;
}
