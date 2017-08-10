#include <fstream>
#include "encryptor.h"
#include "primegenerator.h"
#include <algorithm>

using namespace std;

void createValues(long int, long int, long int, long int, long int, char *, long long int *, int);
long int primegenerator();

int main()
{
 string inputMessage;
 ifstream myfile("log.txt");

 if (myfile.is_open())
  {
   getline(myfile, inputMessage);
   myfile.close();
  }
   else cout<<"Unable to open file";
 remove("log.txt");

 int i;
 for (i = 0; i < inputMessage.length(); i++)
    {
    if(isspace(inputMessage[i])){
     inputMessage[i] = 32;
    }
    };

 long int prime1, prime2;
 prime1 = primegenerator();
 prime2 = primegenerator();
 ofstream newfile;
 newfile.open ("primes.txt");

 newfile<<prime1;
 newfile<<"\n";
 newfile<<prime2;
 newfile.close();

 char array[100];


    long int msg[100];
    long int n = prime1*prime2;
    long int phi = (prime1-1) * (prime2-1);
    int length = inputMessage.length();
    long long int *en[100];

    for (i = 0; i <= length; i++)
    {
        msg[i] = inputMessage[i];
    }


    createValues(phi, prime1,prime2, msg, n, array, *en, length);

    }
