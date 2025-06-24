/*
	1. integers num=numerator, den=denominator
	2. return fraction in string format.
	3. if fraction is repeating, enclose in paranthesis
	4. length of the string is less than 10^4.
	5. num, den lies [-2^31, 2^31-1], better to consider long int,instead of int
	6. den !=0 


*/



#include<iostream>
#include<unordered_map>


using namespace std;

class Solution{
public:
	string fractionToDecimal(int num, int den){
		long int lnum = num;
		long int lden = den;

		string res="";
				
		//sample decimal number format --- 12.345(6789) {sign part, integer part, non recurring decimal part, recurring decimal part}

		//sign part calculation
		//if signs of num and den are different, then result is negative, else result is positive.
		if((lnum<0 && lden>0) || (lnum>0 && lden<0)) res+="-";

		//convert lnum and lden to positives
		if(lnum<0) lnum=-1*lnum;
		if(lden<0) lden=-1*lden;


		//calculate integer part
		long int remainder = lnum%lden;
		long int quotient = lnum/lden;

		res+=to_string(quotient);

		if(remainder){
			res+=".";

			unordered_map<int, int> indexMap;


			while(remainder){
				//cout<<"remainder "<<remainder<<"\n";

				if(indexMap.find(remainder) != indexMap.end()){
					res.insert(indexMap[remainder], "(");
					res+=")";
					break;
				}
				
				else{
					indexMap[remainder] = res.size();

					lnum = remainder*10;
					quotient = lnum/lden;
					res+=to_string(quotient);
					remainder = lnum%lden;
					
				}
		
			
			}

			
			// 2/7 = (20/7) /10 = (2 + 6/7)/10 = 0.2 + (6/7)/10 = 0.2 + (60/7)/100 = 0.2 + (8 + 4/7)/100 = 0.2 + 0.08 + (4/7)/100
			// 2/73 = (200/73)/100 = (2 + 54/73)/100 = 0.02 + (54/73)/100

			//1/30 -- 0.03  , 1/30
					


		}
	
		return res;
	}


};



int main(){

	Solution sol;
	cout<<"Fraction to Decimal for num=1 and den=2 is: "<< sol.fractionToDecimal(1, 2)<<"\n";
	cout<<"Fraction to Decimal for num=2 and den=1 is: "<<sol.fractionToDecimal(2, 1)<<"\n";
	cout<<"Fraction to Decimal for num=4 and den=333 is:"<<sol.fractionToDecimal(-4, 333)<<"\n";
	

	return 0;
}