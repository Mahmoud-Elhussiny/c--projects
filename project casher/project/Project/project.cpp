#include<iostream>
#include<string>
using namespace std;
int c = 0, sum;
struct item {
	int ID;
	string name;
	int numofpiece;
	double price;
};
item arr[10000];
void add(){
	int k = 0;

		cout << "please,enter the name of piece : ";
		cin >> arr[c].name;
		cout << "please,enter the ID of piece : ";
		cin >> arr[c].ID;
		cout << "please,enter the number of piece : ";
		cin >> arr[c].numofpiece;
		cout << "enter the price of piece : ";
		cin >> arr[c].price;

		for (int i = 0; i < c; i++){
			if (arr[c].name == arr[i].name){
				arr[c].numofpiece += arr[i].numofpiece;
				k = i+1;
				break;
			}
		}
		if (k){
			for (int i = k-1; i < c ; i++)
				arr[i] = arr[i + 1];

			c--;
		}
		c++;


}
void delet(){
	item x;
	int a=-1;
	if (c == 0)
		cout << "There are no items \n";
	else{
		cout << "please,enter the name you want delet : ";
		cin >> x.name;
		for (int i = 0; i < c; i++)
		if (x.name == arr[i].name){
			a = i;
			break;
		}
		if (a!=-1){
			for (int i = a; i < c - 1; i++)
				arr[i] = arr[i + 1];
			c--;
		}
	}
}

void display(){
	if (c == 0)
		cout << "There are no items \n";
	else{

		cout << "name\t\t" << "ID\t\t" << "price\t\t" << "num of pice\n";
		cout << "--------------------------------------------------------------------\n";
		for (int i = 0; i < c; i++){
			cout << arr[i].name << "\t\t";
			cout << arr[i].ID << "\t\t";
			cout << arr[i].price << "\t\t";
			cout << arr[i].numofpiece << "\n";
		}
	}
}
void total(){
	sum = 0;
	for (int i = 0; i < c; i++)
		sum += (arr[i].numofpiece*arr[i].price);
	cout << "the total amount of the bill :  ";
	cout << sum << "$" << endl;
}
void discount(){
	if (c==0)
		cout << "There are no items \n";
	else{
		double z;
		cout << "please,enter discount namber you want  :  ";
		cin >> z;
		sum = 0;
		for (int i = 0; i < c; i++)
			sum += (arr[i].numofpiece*arr[i].price);

		cout << "the total price after discount : ";
		cout << sum - (sum*(z / 100)) << endl;
	}
}
void exit(){
	cout << "Thank you for using this program"<<endl;
	system("pause");
}


int main(){
	string x;
	int z;
	do{
		z = 0;
		
		system("pause");
		system("CLS");

		cout << "1:add an item\n";
		cout << "2:delete an item\n";
		cout << "3:display a list with all the items\n";
		cout << "4:show the total amount of the bill\n";
		cout << "5:make discount on the total amount\n";
		cout << "6:exit\n";
		int w = 0;
		cin >> x;
		for (int i = 0; i < x.size(); i++){
			if ((x[i] <= 'z' && x[i] >= 'a') || (x[i] <= 'Z' && x[i] >= 'A')){
				w = 1;
				break;
			}
		}
		
		if (w==1)
			cout << "error \nplease,enter the namber you want choose \n";
		else{
			for (int i = 0; i < x.size(); i++){
				z = (z * 10) + (x[i] - '0');
			}

			switch (z){

			case 1: add(); break;
			case 2: delet(); break;
			case 3: display(); break;
			case 4: total(); break;
			case 5: discount(); break;
			case 6: exit(); break;

			default:cout << "Select the number from 1 to 6 \n";
			}
		}
	} while (z != 6);



}
