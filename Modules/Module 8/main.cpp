#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <ctime>

clock_t start, finish;

using namespace std;

int array[500000];

void fillArray(int x)
{
  for (int i = 0; i < x; i++)
  {
    array[i] = rand() % 1000;
  }
}

void swap(int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void insersionSort(int x)
{
  int i, key, j;
  for (i = 1; i < x; i++)
  {
    key = array[i];
    j = i - 1;
    while (j >= 0 && array[j] > key)
    {
      array[j + 1] = array[j];
      j = j - 1;
    }
    array[j + 1] = key;
  }
}

void bubbleSort(int x)
{
  for (int i = 0; i < x - 1; i++)
  {
    for (int j = 0; j < x - i - 1; j++)
    {
      if (array[j] > array[j+1])
      {
        swap(&array[j], &array[j+1]);
      }
    }
  }
}

void selectionSort(int x)
{
  for (int i = 0; i < x - 1; i++)
  {
    int minIndex = i;
    for (int j = i + 1; j < x; j++)
    {
      if (array[j] < array[minIndex])
      {
        minIndex = j;
      }
    }
    swap(&array[minIndex], &array[i]);
  }
}



int main()
{
  double duration;
  ofstream of;
  srand (time(NULL));



  //INSERSION SORT
  fillArray(10000);

  of.open("unsorted.txt");
  for (int i = 0; i < 10000; i++) of << array[i] << ", ";
  of.close();

  of.open("log.txt");

  start = clock();
  insersionSort(10000);
  finish = clock();
  duration = (double)(finish-start);
  of << "Insersion sort: 0.00" << duration << " seconds." << endl;

  //BUBBLE SORT
  fillArray(10000);
  start = clock();
  bubbleSort(10000);
  finish = clock();
  duration = (double)(finish-start);
  of << "Bubble sort: 0.00" << duration << " seconds." << endl;

  //SELECTION SORT
  fillArray(10000);
  start = clock();
  selectionSort(10000);
  finish = clock();
  duration = (double)(finish-start);
  of << "Selection sort: 0.00" << duration << " seconds." << endl;



  //HEAP SORT

  //Close the file
  of.close();

  of.open("sorted.txt");
  for (int i = 0; i < 10000; i++) of << array[i] << ", ";
  of.close();

}
