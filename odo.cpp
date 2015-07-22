#include<iostream>
using namespace std;

bool isCorrect(int reading)
{
	for(int n=reading/10, r=reading%10; n>0; n/=10, r=n%10)
	{
		if(n%10>r) return false;
	}
	return true;		
}

int smallestNum(int numOfDigits)
{
	switch(numOfDigits)
	{
		case 2: return(12);
		case 3: return(123);
		case 4: return(1234);
		case 5: return(12345);
		case 6: return(123456);
		case 7: return(1234567);
		case 8: return(12345678);
	}
}

int largestNum(int numOfDigits)
{
	switch(numOfDigits)
	{
		case 2: return(89);
		case 3: return(789);
		case 4: return(6789);
		case 5: return(56789);
		case 6: return(456789);
		case 7: return(3456789);
		case 8: return(23456789);
	}
}

int nextReading(int reading, int numOfDigits)
{
    int lowerBound = smallestNum(numOfDigits);
    int upperBound = largestNum(numOfDigits);
    if (reading == upperBound)
	{
        return lowerBound;
    }
    while(isCorrect(reading) && reading < upperBound)
	{
        reading++;
    }    
    return reading;
}

int previousReading(int reading, int numOfDigits)
{
    int lowerBound = smallestNum(numOfDigits);
    int upperBound = largestNum(numOfDigits);
    if (reading == lowerBound)
	{
        return upperBound;
    }
    while(isCorrect(reading) && reading > lowerBound)
	{
        reading--;
    }
    return reading;
}

int main()
{
	int currReading, noOfDigits;
	cin>>noOfDigits>>currReading;
	cout<<"Previous Reading: "<<previousReading(currReading, numOfDigits)<<endl;
	cout<<"Next Reading: "<<nextReading(currReading, numOfDigits)<<endl;
}
