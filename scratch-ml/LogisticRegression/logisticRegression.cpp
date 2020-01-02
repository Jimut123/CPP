
/* 
 * 
 * A simple logistic Regression program (0,1)
 * 
 * $ g++ -o logisticRegression.cpp.o logisticRegression.cpp
 * $ ./logisticRegression.cpp.o < in.in
 * 
 * Created on: Jan-01-2020
 * Author: Jimut Bahan Pal
 * 
 *
 _______________________________________________________
 Sample Output :: 
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++

epoc:: 0 cost = 0.6931 dw_0 = 0.0000 dw_1 = -19.2500 
slope = 0.0000 intercept = 0.0000

epoc:: 1000 cost = 0.3909 dw_0 = 0.2541 dw_1 = -0.0070 
slope = 0.0500 intercept = -0.0248

epoc:: 2000 cost = 0.3845 dw_0 = 0.2513 dw_1 = -0.0050 
slope = 0.0506 intercept = -0.0501

epoc:: 3000 cost = 0.3782 dw_0 = 0.2485 dw_1 = -0.0049 
slope = 0.0511 intercept = -0.0751

epoc:: 4000 cost = 0.3721 dw_0 = 0.2457 dw_1 = -0.0049 
slope = 0.0516 intercept = -0.0998

epoc:: 5000 cost = 0.3662 dw_0 = 0.2430 dw_1 = -0.0049 
slope = 0.0520 intercept = -0.1242
 y [actual]      y[calculated]
0 -0.0721835 treated as => 0
0 -0.0201378 treated as => 0
0 0.031908 treated as => 0
0 0.0839537 treated as => 0
0 0.135999 treated as => 0
1 2.99852 treated as => 1
1 3.51897 treated as => 1
1 4.03943 treated as => 1
1 4.55989 treated as => 1
1 5.08035 treated as => 1

 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * 
 * 
 * 
*/

#include <bits/stdc++.h>
#define N_define 100
using namespace std;

float x[N_define];      // for only 1 feature
float y[N_define];      // the output 
float w[2];              // contains the weights
float dw_0=0.0f,dw_1=0.0f;  // derivative of slope: dw_1, derivative of intercept: dw_0
int N;

class LogisticRegression
{
    public:
        LogisticRegression();
        float get_cost_sigma(float ,int );
        float getcost();
        void training(int,float);
        void calc_err();
};

float LogisticRegression::get_cost_sigma(float x,int y)
{
    float p = 1/(1+exp(-(w[1]*x+w[0])));
    if(y==1)
        return -log(p);
    
    return -log(1-p);
}

float LogisticRegression::getcost()
{
    float cost=0.0f;
    dw_0=0.0f;
    dw_1=0.0f;

    for(int i=0;i<N;i++)
    {
        cost += get_cost_sigma(x[i],y[i]);
        float eaxb = exp(w[1]*x[i]+w[0]);

        if(y[i]==1)
        {
            dw_0 += -1/(1+eaxb);
            dw_1 += -x[i]/(1+eaxb);
        }
        else
        {
            dw_0 += eaxb/(1+eaxb);
            dw_1 += x[i]*eaxb/(1+eaxb);
        }
    }
    cost /=N;
    dw_0 /=N;
    dw_1 /=N;
    return cost;

}


void LogisticRegression::calc_err()
{
    // to compare the errors from the weights obtained and the validations
    cout<<" y [actual]      y[calculated]"<<endl;
    for(int i=0;i<N;i++)
    {
        cout<<y[i]<<" ";
        // create a threshold value of 1, if greater than it treat it as 1 else treat it as 0...
        if(w[1]*x[i]+w[0]>=1)
            cout<<w[1]*x[i]+w[0]<<" treated as => "<<1<<endl;
        else
            cout<<w[1]*x[i]+w[0]<<" treated as => "<<0<<endl;
    }
}

void LogisticRegression::training(int epocs, float lr_alpha)
{
    // Update the weights accordingly
    for(int i=0;i<=epocs;i++)
    {
        dw_0 = 0.0f;
        dw_1 = 0.0f;
        float cost=getcost();
        if(i%1000==0)
        {
           printf("\nepoc:: %d cost = %.4f dw_0 = %.4f dw_1 = %.4f \n",i,cost,dw_0,dw_1);
           printf("slope = %.4f intercept = %.4f\n",w[1],w[0]);
        }
        w[0]-=lr_alpha*dw_0;
        w[1]-=lr_alpha*dw_1;
    }
}



LogisticRegression::LogisticRegression()
{
    cout<<"Input N => "<<endl;
    cin>>N;
    cout<<"x  y "<<endl;
    cout<<"_____"<<endl;
    for(int i=0;i<N;i++)
    {
        cin>>x[i]>>y[i];
        
    }
    for(int i=0;i<N;i++)
        cout<<x[i]<<" "<<y[i]<<"\n";
    w[0]=0.0f;      //initialising the weights, intercept
    w[1]=0.0f;      //initialising the weights, slope
    cout<<endl;
}

int main()
{
    LogisticRegression lor;
    lor.training(5000,0.0001);
    lor.calc_err();
    return 0;
}


