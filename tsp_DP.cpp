//travelling salesman using dp
//https://www.youtube.com/watch?v=JE0JE8ce1V0

#include <iostream>
#include <algorithm>
#define v 4
int int_max = 9999;
using namespace std;
int dp[16][4];     //there are 2^n distinct states for mask, goes from 0000 to 1111 in this eg. therefore 16 states. and 4 cities are therefore
                            // therefore, [16][4]

 
 int dist1[][v] = { { 0, 10, 15, 20 },
                       { 10, 0, 35, 25 },
                       { 15, 35, 0, 30 },
                       { 20, 25, 30, 0 } };         //answer:80

int dist[][v] = { { 0, 10, 15, 20 },
                       { 5, 0, 9, 10 },
                       { 6, 13, 0, 12 },
                       { 8, 8, 9, 0 } };           //answer:35
    
                       
int visited_all = (1<<v)-1;    //this will return 1111 i.e all cities are visited

int tsp(int mask, int pos) {
    
int ans = int_max;

if(mask == visited_all) return dist[pos][0];    //if all cities are visited, return the answer from the current city to the first city

if(dp[mask][pos] !=-1)
{   
    cout<<"called"<<endl;
    return dp[mask][pos];
}

for(int city=0;city<v;city++) {     //check for all cities
    if((mask&(1<<city)) == 0)  { //if that city is not visited
         int newans = dist[pos][city] + tsp((mask|(1<<city)),city);  //distance of visiting that city + the recursive cost of going from that city to all the remaining cities to first city
         ans = min(ans,newans);  //update the new minimum;
    }
}
return (dp[mask][pos]=ans);     //save the answer in dp and return;
}

int main()
{
for(int i = 0;i<16;i++)
for(int j = 0;j<4;j++)
dp[i][j] = -1;                      //intialising dp array to -1;

cout<<tsp(1,0);    //vising the first city(city 0) and setting the mask to 00001 because the first city is already visited
    return 0;
}