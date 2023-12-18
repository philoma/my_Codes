bool checkArmstrong(int n){
	//Write your code here

	int m=n, i=0, sum=0;

	int digits= log10(n)+1; // best- to find count of digits

	while(m){
		sum+=pow(m%10,digits);
		m=m/10;
	}

	return sum==n;

}



int sumOfAllDivisors(int n){
	// Write your code here.
	  int sum=0;
    for(int i=1;i<=n;i++){

        sum+=(n/i)*i;

    }

    return sum; 
}
