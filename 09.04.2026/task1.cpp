#include <iostream>
#include <vector>

using namespace std;
int main(){
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int n = matrix.size();


    for (int  i = 0; i < n; i++){
        for(int j = i;j<n;j++){         //revers elemets
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    //toxy --> syun
    //syuny -->tox


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {  //amen toxy kesn enq hasnum
            swap(matrix[i][j], matrix[i][n - 1 - j]);  //[n - 1 - j] --> last element
        }
    }    


    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){  
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }    
}