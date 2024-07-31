#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> myvector;
    
    myvector.push_back(1);
    myvector.push_back(2);
    myvector.push_back(3);
    myvector.push_back(4);
    
    cout<<"element int my vector:"<<endl;
    for(int element : myvector){
        cout<<element<<' ';
    }
    cout<<endl;
    
    cout<<"the first is : "<<myvector.at(0)<<endl;
    cout<<"the 2th is : "<<myvector[1]<<endl;
    cout<<"the size is : "<<myvector.size()<<endl;
    
    myvector.erase(myvector.begin()+2);
    for(int num : myvector){
        cout<<num<<' ';
    }
    cout<<endl;
    
    myvector.clear();
    cout<<"the size is: "<< myvector.size()<<endl;
}