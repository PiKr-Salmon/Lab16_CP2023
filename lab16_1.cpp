#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}

void showData(double *dPtr,int N,int M){
	cout << fixed << setprecision(2);
    for(int i = 0; i < N*M; i++){
        cout << dPtr[i];
        if(((i+1) % M) == 0) cout << endl;
        else cout << " ";
	}
}

void randData(double *dPtr,int N,int M){
    for(int i = 0; i < N*M; i++){
        dPtr[i] = (rand() % 101)/ 100.00; 
    }
}

void findRowSum(const double *dPtr,double *sum1,int N,int M){
	int rs1 = 0;
	double sum = 0;
	double s[M*N] = {};
	for(int i = 0; i < N*M; i++){  
	    sum = sum + dPtr[i];
	    s[i] = sum;
	}
	for(int i = 0; i < N*M; i++){
        if(M == 1){ sum1[i] = dPtr[i]; rs1++; }
        if(((i+1) % M) == 0 && i < M && M != 1){ sum1[rs1] = s[i]; rs1++;}
        if(((i+1) % M) == 0 && i > M){ sum1[rs1] = s[i] - s[(i-M)]; rs1++;}
	}
}


void findColSum(const double *dPtr,double *sum2,int N,int M){
	int cs1 = 0;
	double s[M] = {};
	
	for(int cch = 0 ; cch < M ; cch++){
	    double sum = 0;
		for(int i = 0; i < N*M; i++){  
			if((i+1) % M == cch){
			sum = sum + dPtr[i];
		    }
		}
    if(cch == 0){s[(cch+M)-1] = sum;}
    s[cch-1] = sum;
	}
	
	for(int i = 0 ; i < M ; i++){
	    sum2[cs1] = s[i];
	    cs1++;
	}
}