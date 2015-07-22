#include<iostream>
using namespace std;

bool isCorrect(int reading)
{
	int num = reading;
	int prev_digit = num % 10;
	while(num>0)
	{
		num /= 10;
		if(num%10 >= prev_digit )
		{
			return false;
		}
		prev_digit = num % 910;
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
    reading++;
    while(!isCorrect(reading) && reading < upperBound)
	{
        reading++;
    }    
    if (reading >= upperBound)
	{
        return lowerBound;
    }
    return reading;
}

int previousReading(int reading, int numOfDigits)
{
    int lowerBound = smallestNum(numOfDigits);
    int upperBound = largestNum(numOfDigits);
    reading--;
    while(!isCorrect(reading) && reading > lowerBound)
	{
        reading--;
    }
    if (reading <= lowerBound)
	{
        return upperBound;
    }
    return reading;
}

int main()
{
	int currReading, numOfDigits;
	cin>>numOfDigits>>currReading;
	cout<<"Previous Reading: "<<previousReading(currReading, numOfDigits)<<endl;
	cout<<"Next Reading: "<<nextReading(currReading, numOfDigits)<<endl;
}
