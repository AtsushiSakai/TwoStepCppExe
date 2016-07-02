#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class ValueNotFoundException : public std::exception{
};

int SearchOnONN(int target, const vector<int> &datalist){
  cout<<"SearchOnONN"<<endl;
  for (int d1 : datalist) {
    for (int d2 : datalist) {
      if((d1+d2) == target){
        cout<<d1<<","<<d2<<","<<target<<endl;
        return(d1);
      }
    }
  }
  throw ValueNotFoundException();
}

int SearchOnONlogN(int target, vector<int> datalist){
  cout<<"SearchOnONlogN"<<endl;
  int i=0;
  int j=datalist.size()-1;

  sort(datalist.begin(),datalist.end());

  while(i!=j){
    int sumdata=datalist[i]+datalist[j];
    if(sumdata>target){
      j--;
    }
    else if(sumdata<target){
      i++;
    }
    else{
      cout<<datalist[i]<<","<<datalist[j]<<","<<target<<endl;
      return datalist[i];
    }
  }

  throw ValueNotFoundException();
}

int SearchOnON(int target, vector<int> datalist){
  cout<<"SearchOnON"<<endl;
  unordered_map<int, int> mp;
  for(int data : datalist){
    int d=target-data;
    auto itr = mp.find(d);
    if( itr != mp.end() ) {
      cout<<data<<","<<itr->first<<","<<target<<endl;
      return data;
    }
    else{
      mp[data]=data;
    }
  }
  throw ValueNotFoundException();
}

int main(void){
  int target=70;
  vector<int> datalist;
  for(int i=0;i<50;i++) datalist.push_back(i);
  random_shuffle(datalist.begin(), datalist.end());
  cout<<SearchOnONN(target,datalist)<<endl;
  cout<<SearchOnONlogN(target,datalist)<<endl;
  cout<<SearchOnON(target,datalist)<<endl;
}



