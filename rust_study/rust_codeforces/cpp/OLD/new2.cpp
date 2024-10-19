#include<iostream>
using namespace std;

int main() {
	float nums[100001] = { 5, 19, 8, 1 };
	int i = 0;
	float sum1, sum2;
	while(nums[i]!=0)
		sum1 += nums[i], i++;
	sum2 = sum1/2;
	int step = 0;
	//cout<<sum1<<endl; 
	while(sum1>sum2) {
		for(int q = 0;q<=i+1;q++)
			for(int p = 0;p<i+1;p++)
				if(nums[p]<nums[p+1])
					swap(nums[p+1], nums[p]);
		step++;
		sum1 -= nums[0]/2;
		nums[0] /= 2;
		//cout<<sum1<<" ";
	}
	cout<<step;
	int JJ = 0;cin>>JJ;
	return 0;


}
