#include <iostream> //console input and output
#include <cmath> //to calculate total # of moves
using namespace std;

void hanoi(int disks, char curr, char temp, char dest) //disks = number of disks
                                                       //curr = current position
                                                       //temp = open position
                                                       //dest = destination position
{
  //catch the program when it hits the last disk to avoid going negative
  if (disks == 1) cout << "Shift disk " << disks << " from " << curr << " to " << dest << endl;
  else
  {
    //this calls the hanoi function itself (hence recursion) but flips some variables
    //first, temporary and destination are flipped to move the disk to the open slot
    hanoi(disks - 1, curr, dest, temp);
    //the move is outputted to the user
    cout << "Shift disk " << disks << " from " << curr << " to " << dest << endl;
    //the function is recurred once more when the disk is now moved onto the slot
    //where it fits on the disk one size up from it, i.e. disk 3 moving onto disk 4
    //these functions repeat over and over until it hits the last disk meaning that,
    //on the first call of this function, it is only called once by main as it will
    //do the rest and call itself until the last disk is moved onto the correct pillar
    hanoi(disks - 1, temp, curr, dest);
  }
}

int getInput() //function to get number of disks (and verify it)
{
  int x;
  do {
    cout << "The number of disks: ";
    cin >> x;
    if (x <= 0) cout << "Not big enough number of disks..." << endl;
  } while(x <= 0);
}

void draw(int x)
{
  cout << endl << endl;
  cout << "Here is your beautiful stack:" << endl << endl;
  for (int i = 0; i < x; i++) //one line for each disk
  {
    cout << "  |";
    for (int j = i; j < x; j++)
    {
      cout << " ";
    }
    cout << "(";
    for (int j = 0; j < i; j++)
    {
      cout << "..";
    }
    cout << ")";
    for (int j = i; j < x; j++)
    {
      cout << " ";
    }
    cout << "|";
    cout << endl;
  }
  cout << endl << endl;
}

int main()
{
  cout << endl;
  cout << "--- H A N O I ---" << endl << endl;
  cout << "This is a game of moving disks." << endl;
  cout << "Each disk must not be on a disk smaller than itself." << endl;
  cout << "I will move all of the disks from pillar A to B." << endl;
  cout << "I will also do this in the least moves possible." << endl;
  cout << "All you need to do is provide the number of disks." << endl << endl;
  int x = getInput();
  cout << endl;
  hanoi(x, 'A', 'C', 'B');
  draw(x);
  cout << "Total moves: " << pow(2,x) - 1 << endl;
}
