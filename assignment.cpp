#include <fstream>
#include <iostream>
#include <memory>
#include <vector>
#include<stack>
#include<stdio.h>
#include <bits/stdc++.h>
using namespace std;

//Note: Do not change any part of the existing code.
int main(int argc, char *argv[]) {
    std::vector<int> numVec;
    int nextNum;
    ifstream inFile;
    inFile.open("input");
    ofstream outfile;
    outfile.open("output");

    while(inFile >> nextNum){

        numVec.push_back(nextNum);
    }

    // Write your code to remove all occurences 3 contiguous numbers that add up to 0 from the vector numVec
    // Note that the output vector should not have any occurances where 3 contiguous numbers sum to 0

    stack<int> arr;
    for(int i=0;i<numVec.size();i++)
    {
    	arr.push(numVec[i]);
        if(arr.size()>=3)
        {
            int x=arr.top();
            arr.pop();
            int y=arr.top();
            arr.pop();
            int z=arr.top();
            arr.pop();
            int sum=x+y+z;
            if(sum!=0)
            {
                arr.push(z);
                arr.push(y);
                arr.push(x);
            }
        }
    }
    vector<int> answer;
    while(!(arr.empty()))
    {
        answer.push_back(arr.top());
        arr.pop();
    }
    reverse(answer.begin(),answer.end());
    numVec.clear();
    for (int i=0;i<answer.size();i++){
        numVec.push_back(answer[i]);
    }

   for(int i = 0;i<numVec.size();i++) {
      outfile << numVec[i] << endl;
   }
}
