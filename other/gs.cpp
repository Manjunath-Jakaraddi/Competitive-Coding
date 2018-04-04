#include<bits/stdc++.h>
using namespace std;

int primes[100001];

void sieve() {
  primes[0]=primes[1]=1;
  for(int i=2;i*i<100000000;i++) {
    if(!primes[i]) {
      for(int j=i;j*j<100000000;j+=i)
	primes[i]=1;
    }
  }
}

int main() {
  // sieve();
  return 0;
}
