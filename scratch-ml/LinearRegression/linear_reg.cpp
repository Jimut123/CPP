/* 
 * 
 * A simple linear Regression program
 * 
 * $ g++ -o linear_reg.cpp.o linear_reg.cpp 
 * $ ./linear_reg.cpp.o < inp.in
 * 
 * Created on: Dec-31-2019
 * Author: Jimut Bahan Pal
 * 
 *
 _______________________________________________________
 Sample Output :: 
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++

 epoc = 4960 ::  | [Derivatives] dp_0 :: 0.13753 dp_1 :: -0.01205 | [Updates] => p_0 :: 0.02939  p_1 :: 0.49744 | sqe = 0.00204 | [MSE] 0.00034 |
 epoc = 4970 ::  | [Derivatives] dp_0 :: 0.13743 dp_1 :: -0.01203 | [Updates] => p_0 :: 0.02937  p_1 :: 0.49744 | sqe = 0.00203 | [MSE] 0.00034 |
 epoc = 4980 ::  | [Derivatives] dp_0 :: 0.13732 dp_1 :: -0.01203 | [Updates] => p_0 :: 0.02935  p_1 :: 0.49744 | sqe = 0.00203 | [MSE] 0.00034 |
 epoc = 4990 ::  | [Derivatives] dp_0 :: 0.13721 dp_1 :: -0.01201 | [Updates] => p_0 :: 0.02933  p_1 :: 0.49744 | sqe = 0.00203 | [MSE] 0.00034 |
 epoc = 5000 ::  | [Derivatives] dp_0 :: 0.13711 dp_1 :: -0.01200 | [Updates] => p_0 :: 0.02930  p_1 :: 0.49744 | sqe = 0.00202 | [MSE] 0.00034 |
 Actual value => 
 0.00000 1.00000 2.00000 4.00000 6.00000 8.00000
 Predicted value => 
 0.02930  1.02419  2.01908  4.00886  5.99864  7.98842 

 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * Doesn't work for inp.in file, Cause need to be found yet!
 * 
 * 
*/



#include <bits/stdc++.h>
#define N_define 100
using namespace std;

int N;
float x[N_define];
float y[N_define];
float p_0,p_1; // p_0 => bias, p_1 => slope or m
//float p[N_define];

float get_random()
{
    std::mt19937_64 rng;
    // initialize the random number generator with time-dependent seed
    uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::seed_seq ss{uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed>>32)};
    rng.seed(ss);
    // initialize a uniform distribution between 0 and 1
    std::uniform_real_distribution<double> unif(0, 1);
    // ready to generate random numbers
    return  unif(rng);
}

class LinearRegressor
{
    public:
        LinearRegressor();
        void print_weights();           // not required helper function
        float predict(float);           // not required helper function
        float MeanSquaredError();       // not required helper function
        void updateWeights(float);
        void training(int,float);
        void print_predicted();         // not required helper function
};

void LinearRegressor::print_predicted()
{
    cout<<"\n Actual value => "<<endl;
    for(int i=0;i<N;i++)
    {
        printf(" %5.5f",y[i]);
    }
    cout<<"\n Predicted value => \n";
    for(int i=0;i<N;i++)
    {
        printf(" %5.5f ",(p_0+p_1*x[i]));
    }
    cout<<"\n";
}

LinearRegressor::LinearRegressor()
{
    cout<<"Input N => "<<endl;
    cin>>N;
    cout<<"Input x => "<<endl;
    for(int i=0;i<N;i++)
        cin>>x[i];
    for(int i=0;i<N;i++)
        cout<<x[i]<<" ";

    cout<<"Input y => "<<endl;
    for(int i=0;i<N;i++)
        cin>>y[i];
    cout<<endl;
    for(int i=0;i<N;i++)
     cout<<y[i]<<" ";
    cout<<endl;
    p_0=0.0f;
    p_1=0.0f;
}

void LinearRegressor::updateWeights(float lr_alpha)
{
    // this calculates the derivative of p_0 and p_1 and then changes the weights accordingly
    float dp_1=0.0f,dp_0=0.0f;
    for(int i=0;i<N;i++)
    {
        dp_1+=-2*float((x[i])*(y[i]-(float(p_1*x[i])+p_0)));
        dp_0+=-2*float(y[i]-(float(p_1*x[i])+p_0));
    }
    
    printf(" | [Derivatives] dp_0 :: %.5f dp_1 :: %.5f",dp_0,dp_1);
    p_0 -= float((dp_0/N)*lr_alpha);
    p_1 -= float((dp_1/N)*lr_alpha);
    
    printf(" | [Updates] => p_0 :: %.5f  p_1 :: %.5f | ",p_0,p_1);   
}

void LinearRegressor::training(int epocs,float lr)
{
    for(int i=1;i<=epocs;i++)
    {
        if(i%10==0)
        {
            cout<<"\n epoc = "<<i<<" :: ";
            updateWeights(lr);        // lr_alpha 
            //cout<<"MSE => "<< MeanSquaredError(p_0,p_1)<<endl;
            printf(" | [MSE] %.5f |",MeanSquaredError());
        }
    }
    print_predicted();
}


float LinearRegressor::predict(float x_sub)
{
    // just predicts the value of x(i)
    return float(x_sub*p_1+p_0);
}


void LinearRegressor::print_weights()
{
    cout<<" p(0) => "<<p_0<<" | p(1) => "<<p_1<<" | "<<endl;
}

float LinearRegressor::MeanSquaredError()
{
    float sqe=0.0f,inter;
    for(int i=0;i<N;i++)
    {
        inter=float(y[i]-(p_1*x[i]+p_0));
        //printf(" %5.5f ",inter);
        sqe=sqe+pow(inter,2);
    }
    printf("sqe = %.5f",sqe);
    return float(sqe/N);
}

int main()
{
    LinearRegressor l;
    l.print_weights();
    // Note ::=> Set the learning rate to a very small value, and the more epocs, the more good the predicted 
    // value is...
    l.training(5000,.001);
    return 0;
}
