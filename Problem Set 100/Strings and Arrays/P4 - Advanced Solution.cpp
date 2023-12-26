//
// Created by Stephen Ni on 2023-12-21.
//

#include<iostream>
#include<string>

using namespace std;

int main(){
    string str1,str2;
    int flag=23;
    cin>>str1 >>str2;


    std::transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    std::transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    for(int i =0;i<= str1.size(); i++)
    {
        if(str1[i]>str2[i])
        {
            cout<<1<<endl;
            flag=16;
            break;
        }
        else if(str2[i]>str1[i]){
            cout<<-1<<endl;
            flag=16;
            break;
        }
    }
    if(flag ==23){
        cout<<0<<endl;
    }
}