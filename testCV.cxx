#include <iostream>
#include <fstream>

int main() 
{
  std::ofstream myfile;
  myfile.open ("/home/abdullahshafin/Desktop/Work/HiwiFZI/temp/myPoint.txt");
  myfile << "Writing this to a file.\n";
  myfile.close();
  return 0;
}
