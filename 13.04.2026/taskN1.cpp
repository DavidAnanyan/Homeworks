#include<iostream>
#include <algorithm>
#include <string>
using namespace std;


//(Tarberak 1,  used stoll() and to_string() functions)
string strSums(string a,string b){
    long long num1 = stoll(a);  //stoll() --> string to long long ;
    long long num2 = stoll(b);

    long long summ = num1 + num2;

    return to_string(summ);  //long long to string;
}



//(tarberak 2)    
string addString(string a,string b){
    string result = "";
    int i = a.length() - 1; //last symboll;
    int j = b.length() - 1;
    int carry = 0; //mnacord,mtapahac tiv;

    while (i >= 0 || j >= 0 || carry > 0){  // || trabanakan kam;
        int sum = carry;
        if(i >= 0){
            sum += a[i] - '0';
            i--;  //qani vor verjic enq sksum nvazum enq;
        }

        if(j >= 0){
            sum += b[j] - '0';
            j--;
        }
        carry = sum /10; //tasnavory;
        result += (sum % 10) + '0'; //miavory darnum e nish;
    }
    
     reverse(result.begin(), result.end());
     return result;
}


int main(){
    string a = "1545";
    string b = "5448";


    cout<<strSums(a,b)<<endl;
    cout<<addString(a,b);
}