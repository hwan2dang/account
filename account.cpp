
#include <iostream>
#include <vector>

using namespace std;

class Account {
public:
    Account() {
        
    }

    //Email check
    bool isValidEmail(string inputEmail) {
        if(  essentialChar(inputEmail)
             && essentialLocation(inputEmail)
             && essentialLocation3(inputEmail)
             && essentialLocation4(inputEmail)) {
            return true;
        }
        return false;
    }

    //password check
    bool isValidPassword(string inputPassword) {
        if(  passwordLength(inputPassword)
             && includeAllChar(inputPassword)
             && includeSpecialChar(inputPassword)
             && noSameChar(inputPassword)) {

            password = inputPassword;
            return true;
        }
        return false;
    }

    //password dobule check
    bool isMatchingPassword(string inputMatchingPassword) {
        if(password == inputMatchingPassword ) {
            return true;
        }
        return false;
    }

// Email check help funtion ----------------------------------------------

    bool essentialChar(string inputEmail) {
        int count1 = 0;
        int count2 = 0;
        for(int i = 0; i < inputEmail.size(); i++) {
            if(inputEmail[i] == '@') {
                count1++;
            } else if(inputEmail[i] == '.')
                count2++;
        }
        return (count1 == 1 && count2 == 1);
    }

    //Error "weoijf@", "" // @, .
    bool essentialLocation(string inputEmail) {
        if(inputEmail[0] != '@' && inputEmail[0] != '.') {
            return true;
        }
        return false;
    }


    bool essentialLocation3(string inputEmail) {
        int location = 0;
        for(int i = 0; i < inputEmail.size(); i++) {
            if(inputEmail[i] == '@'){
                location = i;
            }
        }

        bool result;
        for(int i = 0; i < location; i++) {
            if(inputEmail[i] != '.') {
                result = true;
            } else {
                result = false;
            }
        }
        return result;
    }

    bool essentialLocation4(string inputEmail) {
        int location1 = 0;
        int location2 = 0;
        for(int i = 0; i < inputEmail.size(); i++) {
            if(inputEmail[i] == '@'){
                location1 = i;
            }
            if(inputEmail[i] == '.') {
                location2 = i;
            }
        }

        bool result;
        for(int i = 0; i < location2; i++) {
            if(inputEmail[location2 - 1] != '@') {
                result = true;
            } else {
                result = false;
            }
        }

        for(int i = location1 + 1; i < location2; i++) {
            if(!(inputEmail[i] >='a' && inputEmail[i] <= 'z')
            && !(inputEmail[i] >='A' && inputEmail[i] <= 'Z')
            && !(inputEmail[i] >='0' && inputEmail[i] <= '9')) {
              result = false;
            }
        }

        for(int i = 0; i < location1; i++) {
            if(!(inputEmail[i] >='a' && inputEmail[i] <= 'z')
            && !(inputEmail[i] >='A' && inputEmail[i] <= 'Z')
            && !(inputEmail[i] >='0' && inputEmail[i] <= '9')) {
              result = false;
            }
        }

        for(int i = location2 + 1; i < inputEmail.size(); i++) {
            if(!(inputEmail[i] >='a' && inputEmail[i] <= 'z')
            && !(inputEmail[i] >='A' && inputEmail[i] <= 'Z')
            && !(inputEmail[i] >='0' && inputEmail[i] <= '9')) {
              result = false;
            }
        }
        return result;
    }

// password check help funtion -------------------------------------------

    bool passwordLength(string inputPassword) { //Change naming style
        if(inputPassword.size() > 8) {
            return true;
        }
        return false;
    }

    bool includeAllChar(string inputPassword) {
        int lower = 0;
        int upper = 0;
        int number = 0;
        
        for(int i = 0; i < inputPassword.size(); i++) {
            if(inputPassword[i] >= 'a' && inputPassword[i] <= 'z') {
                lower++;
            } else if(inputPassword[i] >= 'A' && inputPassword[i] <= 'Z') {
                upper++;
            } else if(inputPassword[i] >= '0' && inputPassword[i] <= '9') {
                number++;        
            }
        }       
        return (lower > 0) && (upper > 0) && (number > 0);
    }


    bool includeSpecialChar(string inputPassword) {
        for(int i = 0; i < inputPassword.size(); i++) {
            if(!(inputPassword[i] >='a' && inputPassword[i] <= 'z')
            && !(inputPassword[i] >='A' && inputPassword[i] <= 'Z')
            && !(inputPassword[i] >='0' && inputPassword[i] <= '9')) {
                return true;
            }
        }
        return false;
    }


    bool noSameChar(string inputPassword) {
        char previous = inputPassword[0];
        int count = 1;
        bool result = false;

        for(int i = 1; i < inputPassword.size(); i++) {
            if(previous == inputPassword[i]) {
                count++;
            } else if(count < 4) {
                count = 0;
                previous = inputPassword[i];
                result = true;
            }
        }
        return result;
    }


private:
    string Email;
    string password;
};
//---------------------------

int main() {
    //Validation
    Account account;

    string email = "";
    while(!account.isValidEmail(email)) {
        cout << "Type email: ";
        cin >> email; //abc@gmail.com
        if(!account.isValidEmail(email)) {
            cout << "Your email " << email << " is not valid" << endl;
        }
    }

    string password = "";
    while(!account.isValidPassword(password)) {
        cout << "Type password: ";
        cin >> password;
        if(!account.isValidPassword(password)) {
            cout << "Your passwor is not valid" << endl;
        }
    }

    string confirmingPassword = "";
    while(!account.isMatchingPassword(confirmingPassword)) {
        cout << "Type confirming password: ";
        cin >> confirmingPassword;
        if(!account.isMatchingPassword(confirmingPassword)) {
            cout << "Your passwor is not valid" << endl;
        }
    }

    cout << "Done!" << endl;

    return 0;
}