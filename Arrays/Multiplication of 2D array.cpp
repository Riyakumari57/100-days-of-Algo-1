#include<iostream>
using namespace std;
int main()
{
        int arr1[3][3], arr2[3][3], arr[3][3], sum=0, i, j, k;
        cout<<" Enter First array Elements : \n";
        for(i=0; i<3; i++)
        {
                for(j=0; j<3; j++)
                {
                        cout<<" ";
                        cin>>arr1[i][j];
                }
        }
        cout<<"\n Enter Second array Elements : \n";
        for(i=0; i<3; i++)
        {
                for(j=0; j<3; j++)
                {
                        cout<<" ";
                        cin>>arr2[i][j];
                }
        }
        cout<<"\n\n Multiplication of Two arrays : \n";
        for(i=0; i<3; i++)
        {
                for(j=0; j<3; j++)
                {
                        sum=0;
                        for(k=0; k<3; k++)
                        {
                                sum = sum + arr1[i][k] * arr2[k][j];
                        }
                        arr[i][j] = sum;
                }
        }
        for(i=0; i<3; i++)
        {
                for(j=0; j<3; j++)
                {
                        cout<<" ";
                        cout<<arr[i][j]<<"\t";
                }
                cout<<"\n";
        }
        return 0;
}
