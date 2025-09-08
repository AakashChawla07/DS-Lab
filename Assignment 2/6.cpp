#include <iostream>
using namespace std;

void input(int mat[10][3], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cout<<"enter element ("<<i<<","<<j<<") \n";
            cin>>mat[i][j];
        }       
    }
    cout<<"-----------------------------------"<<endl;

}
void display(int mat[10][3], int n){
    cout<<"Row  Column Value \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cout<<mat[i][j]<<"   ";
        } 
        cout<<endl;      
    }
}

void transpose(int mat[10][3], int n){
    for(int i=0;i<n;i++){
        int temp = mat[i][0];
        mat[i][0]=mat[i][1];
        mat[i][1]=temp;
    }
    cout<<"TRANSPOSE: \n";
    cout<<"Row  Column Value \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cout<<mat[i][j]<<"   ";
        } 
        cout<<endl;      
    }
}
void add(int a[10][3],int b[10][3],int n1,int n2){
    int c[20][3]; 
    int k = 0;   
    for(int i=0;i<n1;i++){
        c[k][0]=a[i][0];
        c[k][1]=a[i][1];
        c[k][2]=a[i][2];
        k++;
    }
    for(int i=0;i<n2;i++){
        bool added=false;
        for(int j=0;j<k;j++) {
            if(c[j][0]==b[i][0]&&c[j][1]==b[i][1]) {
                c[j][2]+=b[i][2]; 
                added=true;
                break;
            }
        }
        if(!added){ 
            c[k][0]=b[i][0];
            c[k][1]=b[i][1];
            c[k][2]=b[i][2];
            k++;
        }
    }
    cout << "Sum of matrices (Row Column Value):\n";
    for(int i = 0; i < k; i++) {
        cout<<c[i][0]<<"   "<<c[i][1]<<"   "<<c[i][2]<<endl;
    }
}


void multiply(int a[10][3],int b[10][3],int n1,int n2){
    int c[100][3];
    int k=0;
    for(int i=0;i<n1;i++){
        int r=a[i][0];
        int colA=a[i][1];
        int valA=a[i][2];
        for(int j=0;j<n2;j++){
            if(b[j][0]==colA){
                int cRow=r;
                int cCol=b[j][1];
                int cVal=valA*b[j][2];
                bool found=false;
                for(int l=0;l<k;l++){
                    if(c[l][0]==cRow&&c[l][1]==cCol){
                        c[l][2]+=cVal;
                        found=true;
                        break;
                    }
                }
                if(!found){
                    c[k][0]=cRow;
                    c[k][1]=cCol;
                    c[k][2]=cVal;
                    k++;
                }
            }
        }
    }

    cout << "Product of matrices (Row Column Value):\n";
    for(int i = 0; i < k; i++) {
        cout << c[i][0] << "   " << c[i][1] << "   " << c[i][2] << endl;
    }
}



int main(){
    int n1;
    int n2;
    cout<<"How many values in 1st matrix? : \n";
    cin>>n1;
    cout<<"How many values in 2nd matrix? : \n";
    cin>>n2;
    int m1[10][3];
    int m2[10][3];
    input(m1,n1);
    display(m1,n1);
    input(m2,n2);
    display(m2,n2);
    transpose(m1,n1);
    add(m1,m2,n1,n2);
    multiply(m1,m2,n1,n2);
}