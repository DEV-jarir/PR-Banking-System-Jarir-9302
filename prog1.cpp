#include<iostream>
using namespace std;

class Bank_Account
{
public:
   long long int acc_Number;  
    string acc_HolderName;
    double acc_Balance;
    double deposit_amount;
    double withdraw_amount;
    int acc_Type;

public:
    void setDetails()
    {
         cout << "Enter Account Holder Name : ";
         getline(cin, acc_HolderName);
        cout << "Enter Account Number : ";
        cin >>acc_Number;
        if (acc_Number <= 0)
        {
            cout << "Account Number Should Be Positive"<< endl;
            cout << "Please Enter A Valid Account Number : ";
            cin >>acc_Number;
        }
      
        cout <<"-------Enter Account Type ---------" << endl << "Enter for 1 Saving Account " << endl << "Enter for 2 Current Account" << endl << "Enter for 3 Fixed Deposit Account" << endl << "Enter Your Choice : ";
        cin >> acc_Type;
          cout<<"---------------------------------------"<<endl;
        if (acc_Type == 1 || acc_Type == 2 || acc_Type == 3)
        {             
            cout << "Enter Initial Account Balance : ";
            cin >>acc_Balance;
            
            while (acc_Balance <= 0)
            {
                cout << "Account Balance Should Be Positive"<< endl;
                cout << "Please Enter A Valid Account Balance : ";
                cin >> acc_Balance;
            }
        }
        else
        {
            cout << "Enter valid Account Type. Try Again." << endl;
        }

        switch (acc_Type)
        {
            case 1:
                cout << "---- Saving Account Is Successfully Created. ----" << endl;        
                break;
            
            case 2:
                cout << "---- Current Account is Successfully Created. ----" << endl;
                break;
            case 3:
                cout << "---- Fixed Deposit Account is Successfully Created. ----" << endl;
                break;
            
            default:
                while (acc_Balance <= 0)
                {
                    cout << "Account Must be Between (1-3) : "<< endl;
                    cout << "Please Enter A Valid Account Type : ";
                    cin >> acc_Type;
                }
                break;
        }
    }

    void deposit()
    {
        cout << "Enter A Amount To Deposit :";
        cin >> this->deposit_amount;
        while (deposit_amount <= 0)
        {
            cout << "Deposit Amount Should Be Positive"<< endl;
            cout << "Please Enter A Valid Deposit Amount : ";
            cin >> this->deposit_amount;
        }
        acc_Balance += deposit_amount;
    }

    void withdraw()
    {
        cout << "Enter A Amount To Withdraw : ";
        cin >> withdraw_amount;

        while (withdraw_amount <= 0)
        {
            cout << "Withdraw Amount Must be Positive Or Greater Than 0"<< endl;
            cout << "Please Enter A Valid Withdraw Amount : ";
            cin >> withdraw_amount;
        }
        acc_Balance -= withdraw_amount;
        cout << "Withdraw Successfully... Current Balance Is :" << acc_Balance << endl;
    }

    double getBalance()
    {
        return acc_Balance;
    }

    void displayAccountInfo()
    {
        cout << "Account Number : " << acc_Number << endl;
        cout << "Account Holder Name : " << acc_HolderName << endl;
        cout << "Account Balance : " << acc_Balance << endl;
    }
};

class SavingAccount : public Bank_Account 
{
private:
    double intrest_rate;

public:
    void calculateIntrest()
    {
        intrest_rate = (acc_Balance * 0.05);
        cout << "Your Bank Is Providing " << intrest_rate << " Rupees Of Interest. Updated Balance: " << acc_Balance << endl;
        acc_Balance += intrest_rate;
    }
};

class CheckingAccount : public Bank_Account
{
public:
    double overDraftLimit = 50000;

    void DraftCheaker()
    { 
        if (acc_Balance > overDraftLimit)
        {       
            cout << "You Have Exceeded The Draft Limit. Your Current Balance Is: " << acc_Balance << endl;
        }
        else
        {
            cout << "You Haven't Exceeded The Draft Limit. Your Current Balance Is: " << acc_Balance << endl;
        }
    }
};

class FixedDepositAmount : public Bank_Account 
{
public:
    double term, fixed_deposit_intrest = 0.15, intrest;

    void calculateIntrest()
    {
        intrest = (acc_Balance * fixed_deposit_intrest) * term;
        cout << "Your Bank Will Provide " << intrest << " Rupees Of Interest In " << term << " Months. Updated Balance: " << acc_Balance << endl;
        acc_Balance += intrest;
    }
};
int main()
{
    cout << endl << "----- Welcome To Our Bank -----" << endl << endl;
    Bank_Account bank_obj;
    bank_obj.setDetails();

    SavingAccount    saving_obj;                                                                                                                   
    CheckingAccount cheking_obj;
    FixedDepositAmount fixed_obj;

    if (bank_obj.acc_Type == 1)
    {
        int choice_S;
        do
        {
            cout << endl << "---- Welcome To Saving Account Services ----";
            cout << endl << "Press 1 To Deposit" << endl;
            cout << "Press 2 To Withdraw" << endl;
            cout << "Press 3 To Calculate Interest" << endl;
            cout << "Press 4 To Check Balance" << endl;
            cout << "Press 5 For Account Details" << endl;
            cout << "Press 0 To Exit" << endl;
            cout << "Enter your Choice : ";
            cin >> choice_S;
            cout << endl;

            switch (choice_S)
            {
                case 0:
                    cout << "---- Exited Successfully ----";
                    break;
                case 1:
                    bank_obj.deposit();
                    break;
                case 2:
                    bank_obj.withdraw();
                    break;
                case 3:
                    saving_obj.acc_Balance = bank_obj.getBalance();  
                    saving_obj.calculateIntrest();
                    break;
                case 4:
                    cout << "Current Balance : " << bank_obj.getBalance() << endl;
                    break;
                case 5:
                    bank_obj.displayAccountInfo();
                    break;
                default:
                    cout << "Sorry, Wrong Choice." << endl;
                    break;
            }
        } while (choice_S != 0);
    }
    else if (bank_obj.acc_Type == 2)
    {
        int choice_service;
        do
        {
            cout << endl << "---- Welcome To Current Account Services ----";
            cout << endl << "Press 1 To Deposit" << endl;
            cout << "Press 2 To Withdraw" << endl;
            cout << "Press 3 To Check Overdraft" << endl;
            cout << "Press 4 To Check Balance" << endl;
            cout << "Press 5 For Account Details" << endl;
            cout << "Press 0 To Exit" << endl;
            cout << "Enter your Choice : ";
            cin >> choice_service;
            cout << endl;

            switch (choice_service)
            {
                case 0:
                    cout << "---- Exited Successfully ----";
                    break;
                case 1:
                    bank_obj.deposit();
                    break;
                case 2:
                    bank_obj.withdraw();
                    break;
                case 3:
                    cheking_obj.acc_Balance = bank_obj.getBalance();
                    cheking_obj.DraftCheaker();
                    break;
                case 4:
                    cout << "Current Balance : " << bank_obj.getBalance() << endl;
                    break;
                case 5:
                    bank_obj.displayAccountInfo();
                    break;
                default:
                    cout << "Sorry, Wrong Choice." << endl;
                    break;
            }
        } while (choice_service != 0);
    }
    else if (bank_obj.acc_Type == 3)
    {
        int choice_Fd;
        cout << "Enter Time Duration Of Your Fixed Deposit Account (In Months) : ";
        cin >> fixed_obj.term;

        do
        {
            cout << endl << "---- Welcome To Fixed Deposit Account Services ----";
            cout << endl << "Press 1 To Deposit" << endl;
            cout << "Press 2 To Withdraw" << endl;
            cout << "Press 3 To Calculate Interest" << endl;
            cout << "Press 4 To Check Balance" << endl;
            cout << "Press 5 For Account Details" << endl;
            cout << "Press 0 To Exit" << endl;
            cout << "Enter your Choice : ";
            cin >> choice_Fd;
            cout << endl;

            switch (choice_Fd)
            {
                case 0:
                    cout << "---- Exited Successfully ----";
                    break;
                case 1:
                    bank_obj.deposit();
                    break;
                case 2:
                    cout << "You can't withdraw before the term period ends." << endl;
                    break;
                case 3:
                    fixed_obj.acc_Balance = bank_obj.getBalance();
                    fixed_obj.calculateIntrest();
                    break;
                case 4:
                    cout << "Current Balance : " << bank_obj.getBalance() << endl;
                    break;
                case 5:
                    bank_obj.displayAccountInfo();
                    break;
                default:
                    cout << "Sorry, Wrong Choice." << endl;
                    break;
            }
        } while (choice_Fd != 0);
    }

    return 0;
}