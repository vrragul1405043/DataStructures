#include <bits/stdc++.h> 
using namespace std; 
  
// Max # of persons in the party 
#define N 8 
  
// Person with 2 is celebrity 
bool MATRIX[N][N] = {{0, 0, 1, 0}, 
                     {0, 0, 1, 0}, 
                     {0, 0, 0, 0}, 
                     {0, 0, 1, 0} 
}; 
  
bool knows(int a, int b) 
{ 
    return MATRIX[a][b]; 
} 
    

int main()
{
    
int celeb = 0;
for(int i=0;i<4;i++)
{
    if(MATRIX[celeb][i])
        celeb = i;
}

for(int i=0;i<4;i++)
{
    if(i!=celeb && (!knows(i,celeb) || knows(celeb,i)))
        {
            celeb = INT_MAX;
            break;
        }    
}
    (celeb==INT_MAX)?cout<<"No celebrities are there " : cout<< "The celebrity is :: "<<celeb;
    return 0;
}