# include<conio.h>
# include<iostream>
# include<string>
using namespace std;
/* Mini project -ATM
 ->check balance
 ->cash withdrawl
 ->user details
 ->update mobile no
 */
class atm{
    private:
    long int account_no;
    string name;
    int PIN;
    double balance;
    string mobile_no;
    public:
    void setdata(long int account_no_a,string name_a,int PIN_a,double balance_a,string mobile_no_a){
        account_no = account_no_a;
        name = name_a;
        PIN = PIN_a;
        balance = balance_a;
        mobile_no = mobile_no_a;

    }
    long int getaccount_no(){
        return account_no;
    }
    string getname(){
        return name;
    }
    int getPIN(){
        return PIN;
    }
    double getbalance (){
        return balance;
    }
    string getmobile_no(){
        return mobile_no;
    }
    void cashwithdraw(int amount_a){
        if(amount_a >0 && amount_a < balance){
            balance -= amount_a;
            cout<<endl<<"please collect cash"<<endl;
            cout<<"Available amount:"<<balance;
            _getch();
        }
        else{
            cout<<endl<<"invalid input or insufficient balance"<<endl;
            _getch();
        }
    }
    void setmobile(string mob_prev,string mob_new){
        if(mob_prev == mobile_no){
            mobile_no = mob_new;
            cout<<endl<<"Successfully mobile number is added!...."<<endl;
            _getch();

        }
        else{
            cout<<endl<<"OOps! check the mobile no";
            _getch();
        }
    }

};
int main(){
    int choice = 0,enterPIN;
    long int enteraccount_no;
    system("cls");
    atm user1;
    user1.setdata(987654321,"Tharun",2222,50000.59567,"9392746638");
    do{
        system("cls");
        cout<<endl<<"**WELCOME TO THARUN'S ATM**"<<endl;
        cout<<endl<<"enter the account no:";
        cin>>enteraccount_no;

        cout<<endl<<"enter the pin:";
        cin>>enterPIN;
        if((enteraccount_no == user1.getaccount_no())&& (enterPIN == user1.getPIN())){
            do{
                int amount = 0;
                string oldmobile_no,newmobile_no;
                system("cls");
                cout<<endl<<"**WELCOME TO THARUN'S ATM**"<<endl;
                cout<<endl<<"select options";
                cout<<endl<<"1.CHECK BALANCE";
                cout<<endl<<"2.CASH WITHDRAW";
                cout<<endl<<"3. SHOW USER DETAILS";
                cout<<endl<<"4.UPDATE MOBILE NO:";
                cout<<endl<<"5.EXIT"<<endl;
                cin>>choice;
                switch(choice){
                    case 1:
                    cout<<endl<<"your balance is"<<user1.getbalance();
                    _getch();
                    break;
                    case 2:
                    cout<<endl<<"Enter the amonut :";
                    cin>> amount;
                    user1.cashwithdraw(amount);
                   
                    break;
                    case 3:
                    cout<<endl<<"**user details are:-"<<endl;
                    cout<<endl<<"->Account number is:"<<user1.getaccount_no()<<endl;
                    cout<<endl<<"->user name  is:"<<user1.getname()<<endl;
                    cout<<endl<<"->balance  is:"<<user1.getbalance()<<endl;
                    cout<<endl<<"->Mobile  number is:"<<user1.getmobile_no()<<endl;
                    

                    _getch();
                    break;
                    case 4:
                    cout<<endl<<"enter old mobile no:"<<endl;
                    cin>>oldmobile_no;

                    cout<<endl<<"enter new mobile no:"<<endl;
                    cin>>newmobile_no;

                    user1.setmobile(oldmobile_no,newmobile_no);
                    break;
                    case 5:
                      exit(0);
                    default:
                      cout<<endl<<"enter valid data!...";

                }
            }
            while(1);
        }
        

    }
    while(1);

}
