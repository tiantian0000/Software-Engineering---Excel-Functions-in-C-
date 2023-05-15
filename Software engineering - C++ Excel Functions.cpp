#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int i,j;
	cout<<"Input the number of rows: ";
	cin>>i;
	cout<<endl<<"Input the number of columns: ";
	cin>>j;
	int a[i][j];
	cout<<endl<<"Now, enter your data: "<<endl;
	for (int k=1; k<=i; k++ ){
		for(int l=1; l<=j; l++){
			cin>>a[k][l];
		}
	}
	cout<<endl<<"What would you like to do (enter number)?"<<endl<<"1. Sort "<<"2. Calculate ";
	int ans;
	cin>>ans;
	if (ans==1){
		int c, d;
		int ei, ej;
		cout<<endl<<"What is the domain of the data you would like to sort? Please enter in the position of number inside the array you entered that you would like to start on and the number you want to end the domain on.(Row number then column) "<<endl<<"From: ";
		cin>>c>>d;
		cout<<endl<<"To: ";
		cin>>ei>>ej;
		while (ei>i||ej>j||ei<c||c>i||d>j){
			cout<<"Sorry, your input was invalid because this coordinate is positioned before your starting coordinate, or it does not occur inside your 2D array. Please try again: "<<endl;
			cout<<"From :";
			cin>>c>>d;
			cout<<endl<<"To: ";
			cin>>ei>>ej;
		}
		int b[1000]; 
		int p=0;
		int o,f;
		for(o=c;o<=ei;o++){
			if (o==c){
				for (f=d; f<=j; f++)
				{
					b[p]=a[o][f];
					p=p+1;	
				}
			}
			else {
				for (f=1; f<=j; f++)
				if (o==ei&&f==ej){
					b[p]=a[o][f];
					break;
				}
				else {
					b[p]=a[o][f];
					p=p+1;	      
				}
			}
		}
		cout<<"Here are the values that you selected:";
		for (int g=0; g<=p; g++)
			cout<<" "<<b[g]<<" ";
		cout<<endl<<"What order should these numbers be sorted into? 1. ascending 2. descending ";
		int answer;
		cin>>answer;
		for(int i=0;i<=p;i++)
			{
				int u=i;
				int temp=b[i];
				for(int k=i-1;k>=0&&b[k]>temp;k--)
				{
					b[k+1]=b[k];
					u=k;
				}	
				int y;
				b[u]=temp; 
			}
		if (answer==1){
			cout<<"Sorted ascending values from position ("<<c<<", "<<d<<") to ("<<ei<<", "<<ej<<"): ";
			for(int x=0;x<=p;x++)
				cout<<b[x]<<' '; 
		}
		if (answer==2){
			cout<<"Sorted descending values from position ("<<c<<", "<<d<<") to ("<<ei<<", "<<ej<<"): ";
			for(int i=p;i>=0;i--)
				cout<<b[i]<<' '; 
		}
		}
	if (ans==2){
		int c,d;
		int ei,ej;
		cout<<endl<<"What is the domain of the data you want to select? Please enter in the position of number inside the array you entered that you would like to start on and the number you want to end the domain on.(Row number then column) "<<endl<<"From: ";
		cin>>c>>d;
		cout<<endl<<"To: ";
		cin>>ei>>ej;
		while (ei>i||ej>j||ei<c||c>i||d>j){
			cout<<"Sorry, your input was invalid because this coordinate is positioned before your starting coordinate, or it does not occur inside your 2D array. Please try again: "<<endl;
			cout<<"From :";
			cin>>c>>d;
			cout<<endl<<"To: ";
			cin>>ei>>ej;
		}
		int b[1000]; 
		int p=0;
		int o,f;
		for(o=c;o<=ei;o++){
			if (o==c){
				for (f=d; f<=j; f++)
				{
					b[p]=a[o][f];
					p=p+1;	
				}
			}
			else {
				for (f=1; f<=j; f++)
				if (o==ei&&f==ej){
					b[p]=a[o][f];
					break;
				}
				else {
					b[p]=a[o][f];
					p=p+1;	      
				}
			}
		}
		cout<<"Here are the values that you selected:";
		for (int g=0; g<=p; g++)
			cout<<" "<<b[g]<<" ";
		cout<<endl<<"What calculations would you like to do?"<<endl<<" 1. Find the sum of these"<<endl<<" 2. Calculate the mean, median and range of these"<<endl<<" 3. Multiply, divide, add or subtract all selected values by a certain scalar (coefficient)"<<endl;
		int x;
		cin>>x;
		if (x==1){
			int sum=0;
			for (int g=0; g<p; g++)
				sum=sum+b[g];
			cout<<endl<<sum;
			}
		if (x==2){
			for(int i=0;i<=p;i++)
			{
				int u=i;
				int temp=b[i];
				for(int j=i-1;j>=0&&b[j]>temp;j--)
				{
					b[j+1]=b[j];
					u=j;
				}	
				int y;
				b[u]=temp; 
			}
			int sum=0;
			for (int g=0; g<=p; g++)
				sum=sum+b[g];
			int range=b[p]-b[0];
			float avg;
			float um=sum;
			float no=p+1;
			float med;
			avg=um/no;
			if ((p+1)%2!=0){
				float z=b[(p)/2];
				float zz=b[(p+2)/2];
				med=(z+zz)/2;
			}
			else 
				med=b[(p+1)/2];
			cout<<"Median: "<<med<<endl;
			cout<<"Range: "<<range<<endl;
			cout<<"Average: ";
			printf("%.2f", avg);
			}
		
		if (x==3){
			cout<<endl<<"What operation? 1.Add/Subtract 2.Multiply 3.Divide ";
			int q;
			cin>>q;
			cout<<endl<<"Enter the value (has to be an integer - enter a negative value if subtracting): ";
			int v;
			cin>>v;
			if (q==1){
				for (int o=0; o<=p; o++){
					b[o]=b[o]+v;
					cout<<b[o]<<" ";
				}
			}
			if (q==2){
				for (int o=0; o<=p; o++){
					b[o]=b[o]*v;
					cout<<b[o]<<" ";
				}
			}
			if (q==3){				
				float c[100];
				for (int o=0; o<=p; o++){
					c[o]=b[o];
					c[o]=c[o]/v;
					printf("%.2f", c[o]);
					cout<<" ";
				}
				
			}
		}
}
	return 0;
}

