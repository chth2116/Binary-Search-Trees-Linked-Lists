#include <iostream>
#include <fstream>
#include <sstream>
#include "MovieTree.hpp"
using namespace std;

int main(int argc, char *argv[]) {
  MovieTree object;
  //open file for input
  ifstream myFile;
  myFile.open(argv[1]);

  //check to see file opens
  if(!myFile){
    cout << "file did not open" << endl;
  }

  string line;

  while(getline(myFile,line)){
    //cout << line << endl;
    stringstream ss;
    ss << line;
    string item;

    int rank;
    string title;
    int year;
    int quantity;

    getline(ss, item, ',');
    rank = stoi(item);

    getline(ss, item, ',');
    title = item;
    //cout << title << endl;

    getline(ss, item, ',');
    year = stoi(item);

    getline(ss, item, ',');
    quantity = stoi(item);

    char letter = title[0];

    object.addMovieNode(rank, title, year, quantity);
  }


  int choice = 0;
while(choice!=6){
  cout << "======Main Menu======" << endl;
  cout << "1. Find a movie" << endl;
  cout << "2. Rent a movie" << endl;
  cout << "3. Print the inventory" << endl;
  cout << "4. Delete a movie" << endl;
  cout << "5. Count the movies" << endl;
  cout << "6. Quit" << endl;

  cin>>choice;

  if (choice==1){
    string title;
    cin.ignore(1,'\n');
    cout << "Enter title:" << endl;
    getline(cin, title);
    object.findMovie(title);
  }

  if (choice==2){
    string title;
    cin.ignore(1,'\n');
    cout << "Enter title:" << endl;
    getline(cin, title);
    object.rentMovie(title);
  }

  if(choice == 3){
    object.printMovieInventory();
  }

  if (choice == 4){
    string title;
    cin.ignore(1,'\n');
    cout << "Enter title:" << endl;
    getline(cin, title);
    object.deleteMovieNode(title);
    //If movie not found in tree
  }
  if(choice == 5){
  cout<<"Tree contains: "<<object.countMovieNodes()<<" movies." << endl;
  }
}
cout << "Goodbye!" << endl;

  return 0;
}
