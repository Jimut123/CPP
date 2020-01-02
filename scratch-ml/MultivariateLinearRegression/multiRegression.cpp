/* 
 * 
 * A multiple linear Regression program
 * 
 * $ g++ -o multiRegression.cpp.o multiRegression.cpp
 * $ ./multiRegression.cpp.o < in.in
 * 
 * Created on: Dec-31-2019
 * Author: Jimut Bahan Pal
 * 
 *
 * 

 _______________________________________________________
 Sample Input :: 
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++

# of data points: 5
# of features: 5

------------------------
x1   x2  x3  x4  x5  y
------------------------
2    2    1  3   5   13
3    4    1  4   5   17
1    1    1  5   5   13
5    2    2  6   5   20
1    1    1  1   1   5


 _______________________________________________________
 Sample Output :: 
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++

Input N (#of data points)=> 
Input #of features => 
Input x => 
2 2 1 3 5 
3 4 1 4 5 
1 1 1 5 5 
5 2 2 6 5 
1 1 1 1 1 
Input y => 

13 17 13 20 5 

 Transpose [x]::
2 3 1 5 1 
2 4 1 2 1 
1 1 1 2 1 
3 4 5 6 1 
5 5 5 5 1 

 mult matrix [x_t * x] :: 
40 28 17 54 56 
28 26 12 40 46 
17 12 8 25 26 
54 40 25 87 91 
56 46 26 91 101 

 assigned matrix [a]::
40 28 17 54 56 
28 26 12 40 46 
17 12 8 25 26 
54 40 25 87 91 
56 46 26 91 101 

 Full matrix [a]::
40 28 17 54 56 1 0 0 0 0 
28 26 12 40 46 0 1 0 0 0 
17 12 8 25 26 0 0 1 0 0 
54 40 25 87 91 0 0 0 1 0 
56 46 26 91 101 0 0 0 0 1 

1 0 0 0 0 0.418457 -0.2417 -0.575196 -0.185059 0.192872 
0 1 0 0 0 -0.2417 0.379395 0.151367 0.232911 -0.287598 
0 0 1 0 0 -0.575196 0.151368 2.1582 -0.227538 -0.100587 
0 0 0 1 0 -0.185059 0.232911 -0.227539 0.469239 -0.367676 
0 0 0 0 1 0.192871 -0.287598 -0.100586 -0.367677 0.391114 

 Extracted inverse matrix [inv] :: 
0.418457 -0.2417 -0.575196 -0.185059 0.192872 
-0.2417 0.379395 0.151367 0.232911 -0.287598 
-0.575196 0.151368 2.1582 -0.227538 -0.100587 
-0.185059 0.232911 -0.227539 0.469239 -0.367676 
0.192871 -0.287598 -0.100586 -0.367677 0.391114 

 mult matrix [x_t * y] :: 
195 
152 
88 
297 
320 
Weights calculated p => 
1
1.00001
1.00002
0.999985
1
 actual [y] values :: 
13 17 13 20 5 
 predicted [y] values from given x :: 
13 17 12.9999 20 5.00001 


 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * Doesn't work for noninvertable matrices, i.e. input feautre and #of data points 
 * needs to be same for now.
 * 
 * 
*/






#include <bits/stdc++.h>
#define N_define 100
using namespace std;

int N,n;
float x[N_define][N_define];
float x_t[N_define][N_define];
float x_t_x[N_define][N_define];
float inv[N_define][N_define];
float x_t_y[N_define][1];
float p[N_define][1];   // contains the weights
float y[N_define];

float p_0,p_1; // p_0 => bias, p_1 => slope or m
//float p[N_define];


class multiRegression
{
    float a[N_define][N_define];
    public:
        multiRegression();
        void do_x_t();
        void calc_x_t_x();
        void calc_inv_x_t_x();
        void calc_x_t_y();
        void calc_p();
        void compare_y_p();
};


void multiRegression::compare_y_p()
{
    float yy;
    cout<<" actual [y] values :: "<<endl;
    for(int i=0;i<N;i++)
        cout<<y[i]<<" ";
    cout<<endl;
    cout<<" predicted [y] values from given x :: "<<endl;
    for(int i=0;i<N;i++)
    {
        yy=0.0f;
        for(int j=0;j<n;j++)
        {
            yy+=x[i][j]*p[j][0];
        }
        cout<<yy<<" ";
    }
    cout<<endl;
}

void multiRegression::calc_p()
{
    int i,j,k;


    for (i = 0; i < N; i++) 
    { 
        p[i][0] = 0; 
        for (k = 0; k < n; k++) 
            p[i][0] += inv[i][k] * x_t_y[k][0]; 
        
    } 
    cout<<"Weights calculated p => "<<endl;
    for(int i=0;i<N;i++)
    {
        cout<<p[i][0];
        cout<<endl;
    }
}

void multiRegression::calc_x_t_y()
{
    // Calculate x_t * y and result dim => n*1
    int i,j,k;
    for (i = 0; i < n; i++) 
    { 
        x_t_y[i][0] = 0;
        // if(i==N-1) 
        // cout<<x_t[i][0]<<endl;
        for (k = 0; k < N; k++) 
            x_t_y[i][0] += x_t[i][k] *  
                             y[k];   
    } 
    cout<<"\n mult matrix [x_t * y] :: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<x_t_y[i][0]<<" ";
        cout<<endl;
    }
}

void multiRegression::calc_x_t_x()
{
    int i,j,k;
    for (i = 0; i < N; i++) 
    { 
        for (j = 0; j < n; j++) 
        { 
            x_t_x[i][j] = 0; 
            for (k = 0; k < n; k++) 
                x_t_x[i][j] += x_t[i][k] *  
                             x[k][j]; 
        } 
    } 
    cout<<"\n mult matrix [x_t * x] :: "<<endl;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<x_t_x[i][j]<<" ";
        }
        cout<<endl;
    }
}

void multiRegression::calc_inv_x_t_x()
{
    float t;
    // calculate inverse using Gauss Jordan method
    for(int i=0;i<N;i++)
        for(int j=0;j<n;j++)
        {
            a[i][j]=x_t_x[i][j];
        }
    cout<<"\n assigned matrix [a]::"<<endl;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0;i<N;i++)
    {
        for(int j=n;j<2*n;j++)
        {
            if(i==j-n)
                a[i][j]=1;
            else
                a[i][j]=0;
        }
    }
    cout<<"\n Full matrix [a]::"<<endl;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<2*n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0;i<N;i++)
    {
        t=a[i][i];
        for(int j=i;j<2*n;j++)
            a[i][j]=a[i][j]/t;
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                t=a[j][i];
                for(int k=0;k<2*n;k++)
                    a[j][k]=a[j][k]-t*a[i][k];
            }
        }
    }
    cout<<endl;
    int dum=0;

    for(int i=0;i<N;i++)
    {
        dum=0;
        for(int j=0;j<2*n;j++)
        {
            cout<<a[i][j]<<" ";
            // extract the inverse of the matrix
            if(j>=min(N,n))
            {
                inv[i][dum]=a[i][j];
                dum++;
            }
        }
        cout<<endl;
    }
    cout<<"\n Extracted inverse matrix [inv] :: "<<endl;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<inv[i][j]<<" ";
        }
        cout<<endl;
    }
}

void multiRegression::do_x_t()
{
    // a function to only transpose x
    for(int i=0;i<N;i++)
        for(int j=0;j<n;j++)
        {
            x_t[j][i]=x[i][j];
        }
    cout<<"\n Transpose [x]::"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<x_t[i][j]<<" ";
        }
        cout<<endl;
    }
}


multiRegression::multiRegression()
{
    cout<<"Input N (#of data points)=> "<<endl;
    cin>>N;
    cout<<"Input #of features => "<<endl;
    cin>>n;
    cout<<"Input x => "<<endl;

    for(int i=0;i<N;i++)
        for(int j=0;j<n;j++)
            cin>>x[i][j];
    for(int i=0;i<N;i++)
    {
            for(int j=0;j<n;j++)
                cout<<x[i][j]<<" ";
            cout<<endl;
    }

    cout<<"Input y => "<<endl;
    for(int i=0;i<N;i++)
        cin>>y[i];
    cout<<endl;

    for(int i=0;i<N;i++)
     cout<<y[i]<<" ";

    cout<<endl;
}

int main()
{
    multiRegression m;
    m.do_x_t();
    m.calc_x_t_x();
    m.calc_inv_x_t_x();
    m.calc_x_t_y();
    m.calc_p();
    m.compare_y_p();
    return 0;
}