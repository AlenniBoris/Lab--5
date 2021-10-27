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
    if (a >= '0' && a <= '9'){
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
void Answer(const string& StringInput, ofstream& File_with_Letters, ofstream& File_with_Numbers) {
    string numbers;
    string letters;
    for(char i : StringInput) {
        if (isNumber(i)) {
            numbers.push_back(i);
            numbers.push_back(' ');
        } else if (LettersLatin(i)){
            letters.push_back(i);
            letters.push_back(' ');
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
