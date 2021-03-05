#include<iostream>
using namespace std;
struct item {
    int ID;
    string name;
    int numofpiece;
    double price;
};
void add(){
    int i=0;
    item arr[10000];
    cout<<"enter the name\n";
    cin>>arr[i].name;
    cout<<"enter the ID\n";
    cin>>arr[i].ID;
    cout<<"enter the num of piece\n";
    cin>>arr[i].numofpiece;
    cout<<"enter the price\n";
    cin>>arr[i].price;
}

int main (){
    do{
        int x,i=0;
        cout<<endl;
        system("pause");
        system("CLS");

        cout<<"1:add an item\n";
        cout<<"2:delete an item\n";
        cout<<"3:display a list with all the items\n";
        cout<<"4:show the total amount of the bill\n";
        cout<<"5:make discount on the total amount\n";
        cout<<"6:exit\n";

        cin>>x;

        switch(x){
        case 1: add; break;





        }
    }
    while(x>=6);



}
