//gauseJordan

A = input('Enter your co-efficient matrix: ')
b = input('source value: ')
N = length(b)
x = zeros(N,1)
Aug = [A b]
for j=1:N
  Aug(j,:) = Aug(j,:)/Aug(j,j)
  for i=1:N
    if i~=j
      m=Aug(i,j)
      Aug(i,:) = Aug(i,:) - m*Aug(j,:)
    end
  end
end

//gauseElemination

#include <stdio.h>
int n;

void convertToUpperTriangular(float a[][n+1], int n)
{
    int i, j, x, y, k;
    float ratio;
    for( i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
        if(j > i)
        {
            ratio = a[j][i] / a[i][i];
            for(k = 0; k < n+1; k++)
                a[j][k] = a[j][k] -( ratio * a[i][k]);

            printf ("Intermediate forms : \n");
            for( x = 0; x < n; x++)
             {
               for(y = 0; y < n+1; y++)
                printf("%.2f   ", a[x][y]);
                    printf("\n");   
            }
            
            printf("\n");
             
        } 
      
      }
    }
}

void ApplyBackSubstitution (float a[][n+1], float value[], int n)
{   
    int i, j;
    float sum;
    value[n-1] = a[n-1][n] / a[n-1][n-1]; 

    for(i = n - 2;i >= 0;i--)
    {
        sum=0;
        for(j = i+1; j < n; j++)
            sum = sum + a[i][j] * value[j];  
        value[i] = (a[i][n] - sum) / a[i][i];
    } 
}

void print(float value[], int n)
{  
    int i;
    printf("Values of unknowns are : \n");
    for(i = 0; i < n; i++)
        printf("Value[%d] = %f\n", i, value[i]);
   
}

int main()
{
    int i, j, k, x, y;
    float sum, ratio;
    printf("Enter no of Unknowns : \n");
    scanf("%d", &n);
    float a[n][n+1], value[n];
    printf("Enter the Augmented Matrix : \n");
    for(int i = 0;i < n; i++)
    {
        for(int j = 0; j < n+1; j++)
            scanf("%f", &a[i][j]);
    }
    
    convertToUpperTriangular(a, n);
    ApplyBackSubstitution(a, value, n);
    print(value, n); 
    
    return 0;
}



//task gause
clc;
t1 = input('Enter the time of first moment : ');
v1 = input('Enter the velocity of first moment : ');
t2 = input('Enter the time of second moment : ');
v2 = input('Enter the velocity of second moment : ');
t3 = input('Enter the time of third moment : ');
v3 = input('Enter the velocity of third moment  : ');
t12 = t1*t1;
t22 = t2*t2;
t32 = t3*t3;
Aug = [t12 t1 1 v1; t22 t2 1 v2; t32 t3 1 v3];

for i=1:2
  for j=i+1:3
   m = Aug(j,i)./Aug(i,i);
   Aug(j,:) = Aug(j,:) - m.*Aug(i,:);
  end
end

disp(Aug);
a3 = Aug(3,4)./Aug(3,3);
a2 = (Aug(2,4) - Aug(2,3).*a3)./Aug(2,2);
a1 = (Aug(1,4) - Aug(1,2).*a2 - Aug(1,3).*a3)/Aug(1,1);

fprintf('a1 = %0.2f\n a2 = %0.2f\n a3 = %0.2f\n',a1,a2,a3);
t = input('Enter the time to print velocity : ');
v = (t*t)*a1+t*a2+a3;
fprintf('The velocity for %d seconds is %0.4f\n',t,v);

void Lagrange ()
{
    for(i=1;i=n;i++)
    {
        p=1;
        for(j=1;j<=n;j++)
        {
            if(i!=j) 
                p = p* (xp - x[j])/(x[i] - x[j]);
        }
        yp = yp + p * y[i]
    }
    cout<<endl<<"Interpolated value at "<< xp<<" is "<< yP;
}


//newton interpolation


#include<stdio.h>
#include<conio.h>

void main()
{
float x[10],y[10],X,p=1,u,h,val;

int i,j,n;
printf("OUTPUT\n");
printf("Number of arguments\n");
scanf("%d",&n);
printf("Enter the value of x and f(x)\n");
printf("x\t\tf(x)\n");

for(i=1;i<=n;i++)
    scanf("%f\t%f",&x[i],&y[i]);

    h=x[2]-x[1];
    printf("Value of x where the functional value is to be determined ");
    scanf("%f",&X);
    u=(X-x[1])/h;
    val=y[1];
    for(i=1;i<=n-1;i++)
    {
        for(j=1;j<=n-i;j++)
            y[i]=y[j+1]-y[j];
        p=p*(u-i+1)/i;
        val=val+p*y[1];
    }
    printf("The value of f(%f)=%f",X,val);
    getch();
}




float bisection(float a,float b)
{
    float c=(a+b)/2;
    for(float i=0;i<20;i++)
    {
        float f=c*c*c+c-1;
        if(f<0) a=c;
        else b=c;
        c=(a+b)/2;
    }
    return c;

}


float falsePosition(float a, float b) 
{
    float c = (a * function(b) - b * function(a)) / (function(b) - function(a));
    for (float i = 0; i < 20; i++) 
    {
        float fc = function(c);
        if (fc < 0)
            a = c;
        else
            b = c;
        c = (a * function(b) - b * function(a)) / (function(b) - function(a));
    }
    return c;
}



float newtonRaphson(float initialGuess, float tolerance, int maxIterations) 
{
    float x = initialGuess;

    for (int i = 0; i < maxIterations; ++i) {
        float fx = function(x);
        float fpx = derivative(x);

        if (std::abs(fx) < tolerance) {
            std::cout << "Newton-Raphson method converged to a root after " << i + 1 << " iterations." << std::endl;
            return x;
        }

        x = x - fx / fpx;
    }

    cout << "Newton-Raphson method did not converge within the specified number of iterations." <<endl;
    return NAN;
}




