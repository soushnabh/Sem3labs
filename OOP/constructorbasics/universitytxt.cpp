#include <iostream>
#include <fstream>
#include <limits>
#include <string>

using namespace std;

class UniversityFile {
  string name;
  int roll;
  string dept;
  public:
    UniversityFile(string file) {
      ifstream inputfile (file);
      getline(inputfile, name);
      inputfile >> roll;
      inputfile.ignore(numeric_limits<streamsize>::max(), '\n');
      getline(inputfile, dept);
    }
    UniversityFile(const UniversityFile& other) {
      name = other.name;
      roll = other.roll;
      dept = other.dept;
    }

    void write(string file) {
      ofstream outfile(file);
      if (outfile.is_open()) {
        outfile << name << endl;
        outfile << roll << endl;
        outfile << dept << endl;
        outfile.close();
      } else cout << "Unable to open file";
    }    
};

int main() {
  string oldfile, newfile;
  cout<<"Enter the filename to read: ";
  cin>>oldfile;
  cout<<"Enter the filename to write: ";
  cin>>newfile;
  
  UniversityFile infile(oldfile);
  UniversityFile outfile = infile;
  
  outfile.write(newfile);
  
  return 0;
}
