#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>

using namespace std;
void print_matrix(int** matrix,int dimes) {
  for (int i = 0; i < dimes; i++){
    for (int j = 0; j < dimes; j++){
      cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
  }
}


int main(int argc, char** argv) {
  // check command line arguments number
  if (argc != 5) {
    cerr << "Usage: ./rainfall <M> <A> <N> <elevation_file>\n";
    return EXIT_FAILURE;
  }

  // read in arguments
  size_t simu_time = 0; 
  float abs_rate = 0.0;
  int N = 0;  
  ifstream elev_file (argv[4]);
  simu_time = stoi(argv[1]);
  abs_rate = strtof(argv[2], NULL);
  N = stoi(argv[3]);
  
  // initialize the matrix
  int** matrix = (int**) malloc(N * sizeof(int*));
  for (int i = 0; i < N; i++) {
    matrix[i] = (int*) malloc(N * sizeof(int));
  }

  // check open file  
  if (!elev_file.is_open()) {
    cerr <<"CAN NOT OPEN FILE" <<endl;
    return EXIT_FAILURE;
  }
 

  // check open file  
  if (!elev_file.is_open()) {
    cerr <<"CAN NOT OPEN FILE" <<endl;
    return EXIT_FAILURE;
  }
 
  
  //read file and check if the dimension is right
  int num_row = 0;
  int num_col = 0;
  string line;
  
  while (getline(elev_file, line)){
    if (line.empty()){
      continue;
    }
    num_col = 0;

    string buf;
    stringstream stream(line);
    while (stream >> buf){
      matrix[num_row][num_col] = stoi(buf);
      num_col++;
    }

    if (num_col != N){
      cout<<"Row "<<num_row 
	  << " has " << num_col
	  << "numbers, it is suppose to be "
	  << N <<endl;
      return EXIT_FAILURE;
    }
    num_row += 1;
  }
  
  if (num_row != N){
    cout << "The number of rows of input matrix is not N\n";
    return EXIT_FAILURE;
  }
  
  elev_file.close();
  print_matrix(matrix,N);

  return 0;
}
