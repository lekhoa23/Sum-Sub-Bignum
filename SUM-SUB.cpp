#include<bits/stdc++.h>

using namespace std;

bool SWAP(string &a, string &b){
    string st="";
    bool ch=false;
    if(a.length() < b.length()){
        swap(a,b);
        ch=true;
        
    }
    for(int i=0;i<a.length()-b.length();++i){
            st+="0";
        }   
    st+=b;
    b=st;
    return ch;
}

void Sum(string a, string b){
    SWAP(a,b);
    vector<int> res;
    int nho=0;
    for(int i=a.length()-1;i>=0;--i){
        int tmp = (a[i]-'0') + (b[i]-'0');
        tmp += nho;
        nho = tmp/10;
        tmp %= 10;
        res.push_back(tmp);
    }
    if(nho != 0) res.push_back(nho);
    reverse(res.begin(),res.end());
    int pos;
    for(int i=0; i<res.size();++i){
        if( res[i] != 0){
            pos=i;
            break;
        }
    }
    for(auto i=pos; i < res.size(); ++i)
        cout<< res[i];
}

void sub(string a, string b){
    bool check=false;
    if(SWAP(a,b)) check=true;
    for(int i=0;i<a.length();++i){
        if(a[i] > b[i])
            break;
        if(a[i] < b[i]){
            swap(a,b);
            check=true;
            break;
        }
    }
    vector<int> res;
    int nho=0;
    for(int i=a.length()-1; i>=0;--i){
        int x =a[i]-'0';
        int y = (b[i]-'0') + nho;
        nho=0;
        if( x < y ){
            x+=10;
            nho=1;
        }
        int tmp = x-y;
        res.push_back(tmp);
        if(i==0 && tmp == 0)
            res.pop_back();
    }
     if(check)
        cout<<"-";
    reverse(res.begin(), res.end());
    int pos;
    for(int i=0; i<res.size();++i){
        if( res[i] != 0){
            pos=i;
            break;
        }
    }
    for(auto i=pos; i < res.size(); ++i)
        cout<< res[i];
}

int main(){
    string a,b;
    cin>>a>>b;
    Sum(a,b);
    cout<<"\n";
    sub(a,b);
}