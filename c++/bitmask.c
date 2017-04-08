#include <stdlib.h>
#include <stdio.h>

int bits1(int n){
	int ans = n&1;
	while(n>>=1){
		ans+=n&1;
	}
	return ans;
}

int int_size(){
	return (int)sizeof(int)*8;
}

int is_neg(int x){
	return (x>>31)&1;
}
unsigned int repBits(unsigned int x, int i , int k , unsigned int val){
	printf("%0x\n",x);
	x<<=(k-1);
	x<<=1;
	printf("%0x\n",x);
	x>>=(k-1);
	x>>=1;
	printf("%0x\n",x);
	while(i+k<31){
		printf("%0x\n",val);
		val<<=1;
		i++;
	}
	printf("%0x\n",val);
	return val|x;
}
int unset1(int n){
	int bit = (1<<30);
	while(!(bit&n) && bit!=0){
		bit>>=1;
	}
	if(bit!=0)
		return (~bit)&n;
	return n;
}
int abs(int x){
	return (int)((*(unsigned int*)(&x))&(~(1<<30)));
}
int main(){
	int a = 100;
	printf("%0x\n",repBits(0x12345678,4,8,0xaa));
	return 0;
}