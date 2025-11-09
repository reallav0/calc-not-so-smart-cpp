#include <iostream>
#include <string>
#include <sstream> 
using namespace std;

    char p = '+';
    char m = '-';
    char t = '*';
    char d = '/';
    char st = '(';
    char se = ')';

int plus(int a, int b){
        int res = a + b;
        return res;
}
int minus(int a, int b){
        int res = a - b;
        return res;
}

bool validEquation(string eq){
    int foundLeft = 0;
    int foundRight = 0;

    for (int i = 0; i < eq.length(); i++) {
        if (eq[i] == st){
            ++foundLeft;
        };
        if (eq[i] == se){
            ++foundRight;
        }
        if (i > 0){
            if ((eq[i] == p) && ((eq[i-1] == p) || (eq[i-1] == m) || (eq[i-1] == t) || (eq[i-1] == d) || (eq[i+1] == p) || (eq[i+1] == t) || (eq[i+1] == d))){
                    cout << "Double check your equation for typo at position " << i;
                    return false;
            }
            if ((eq[i] == m) && ((eq[i+1] == p) ||  (eq[i+1] == t) || (eq[i+1] == d))){
                    cout << "Double check your equation for typo at position" << i;
                    return false;
            }
            if ((eq[i] == t) && ((eq[i-1] == p) || (eq[i-1] == m) || (eq[i-1] == t) || (eq[i-1] == d) || (eq[i+1] == p) ||  (eq[i+1] == t) || (eq[i+1] == d))){
                    cout << "Double check your equation for typo at position " << i;
                    return false;
            }
            if ((eq[i] == d) && ((eq[i-1] == p) || (eq[i-1] == m) || (eq[i-1] == t) || (eq[i-1] == d) || (eq[i+1] == p) || (eq[i+1] == t) || (eq[i+1] == d))){
                    cout << "Double check your equation for typo at position " << i;
                    return false;
            }
        }

    };
    if ((foundLeft != foundRight) || (eq[0] == p) || (eq.back() == m) || (eq.back() == p) ||(eq[0] == t) || (eq.back() == d) || (eq.back() == t) ||(eq[0] == d)){
        cout << "Double check your equation for typo";
        return false;
    }

    return true;
};


string detachPriority(string equation){
    int posST;
    int posSE;

    posST = equation.rfind(st);
    if (posST != string::npos) {
    
    }
    posSE = equation.substr(posST).find(se);
    if (posSE != string::npos) {
        posSE += posST;

    }
    string newEQ = equation.substr(posST + 1, posSE - posST - 1);
    return newEQ;
}

string seperator(string equation) {

    int mPos = equation.find(t);
    int dPos = equation.find(d);

    string checkEQL;
    string checkEQR;

    if (mPos != string::npos && (dPos == string::npos || mPos < dPos)) {
    

        int endL;
        checkEQL = equation.substr(0, mPos);
 

        endL = checkEQL.rfind(p);

        if (endL != string::npos) {
            checkEQL = checkEQL.substr(endL + 1, mPos - endL);
        } else {
            endL = checkEQL.rfind(m);
            if (endL != string::npos) {
                checkEQL = checkEQL.substr(endL, mPos - endL);
            }
        }

        int endR;
        checkEQR = equation.substr(mPos, equation.back());

        endR = checkEQR.find(p);

                size_t minusPos = checkEQR.find(m);
            
                if (minusPos == string::npos || endR < minusPos) {
                    checkEQR = checkEQR.substr(0, endR);
                } else {
                    int count = 0;
                    while ((endR = checkEQR.find(m)) != string::npos) {

                        if (count > checkEQR.size()) {
                            break; 
                        }

                        if (checkEQR[endR - 1] != d && checkEQR[endR - 1] != t) {
                            checkEQR = checkEQR.substr(0, endR);
                            break;
                        } else {
       
                            checkEQR[endR] = '_';
                        }
                        ++count;
                    }
                
            }
    }


    else if (dPos != string::npos && (mPos == string::npos || dPos < mPos)){

        int endL;
        checkEQL = equation.substr(0, dPos);

        endL = checkEQL.rfind(p);

        if (endL != string::npos)
            checkEQL = checkEQL.substr(endL + 1, dPos - endL);
        else {
            endL = checkEQL.rfind(m);
            if (endL != string::npos)
                checkEQL = checkEQL.substr(endL, dPos - endL);
        }

        int endR;
        checkEQR = equation.substr(dPos, equation.back());

        endR = checkEQR.find(p);

        
            size_t minusPos = checkEQR.find(m);

            if (minusPos == string::npos || endR < minusPos) {
                checkEQR = checkEQR.substr(0, endR);
            } else {

                int count = 0;

                while ((endR = checkEQR.find(m)) != string::npos) {


                    if (count > checkEQR.size()) {
                        break;
                    }

                    if (checkEQR[endR - 1] != d && checkEQR[endR - 1] != t) {
                        checkEQR = checkEQR.substr(0, endR);
                        break;
                    } else {
                        checkEQR[endR] = '_';
                    }
                    ++count;
                }
            
        }
    }

  
    string newEQ = checkEQL + checkEQR;

    int n;
    while ((n = newEQ.find('_')) != string::npos)
        newEQ[n] = '-';

    return newEQ;
}

double PlusAndMinusCal(string eq) {
    while (eq.find("--") != string::npos) eq.replace(eq.find("--"), 2, "+");
    while (eq.find("+-") != string::npos) eq.replace(eq.find("+-"), 2, "-");
    while (eq.find("-+") != string::npos) eq.replace(eq.find("-+"), 2, "-");

    stringstream newEQ(eq);
    double number, total = 0.0;
    char op = '+';

    while (newEQ >> number) {
        if (op == '+') total += number;
        else if (op == '-') total -= number;
        newEQ >> op;
    }

    total = round(total * 1e6) / 1e6;
    return total;
}
double MultiAndDivideCal(string eq){

            while (eq.find("--") != string::npos)
            eq.replace(eq.find("--"), 2, "+");
            while (eq.find("+-") != string::npos)
            eq.replace(eq.find("+-"), 2, "-");
            while (eq.find("-+") != string::npos)
            eq.replace(eq.find("-+"), 2, "-");

            stringstream newEQ(eq);
            double number, total = 0;
            char op = '+';
            while (newEQ >> number){
                if (op == p) total += number; 
                else if (op == m) total -= number;
                else if (op == t) total *= number;
                else if (op == d) total /= number;
                newEQ >> op;
            }
            return total;
};


   
int main() {
    while (true) {
        string equation;
        cout << "Enter your equation (or type 'exit' to quit): ";
        cin >> equation;

        if (equation == "exit") {
            cout << "Goodbye!" << endl;
            break;
        }

        if (!validEquation(equation)) {
            cout << "Error here, stop" << endl;
            continue; 
        }

        while (equation.find(st) != string::npos || equation.find(se) != string::npos) {
                string CalToReplace = detachPriority(equation);

                while (CalToReplace.find(m) != string::npos || CalToReplace.find(d) != string::npos) {
                    string CalToRemove = seperator(CalToReplace);
                    if (CalToRemove.empty()) {
                    
                        break;
                    }

                    string MultiAndDivisionReplacement = to_string(MultiAndDivideCal(CalToRemove));
                    if (MultiAndDivisionReplacement.find('.') != string::npos) {
                        while (!MultiAndDivisionReplacement.empty() && MultiAndDivisionReplacement.back() == '0')
                            MultiAndDivisionReplacement.pop_back();

                        if (!MultiAndDivisionReplacement.empty() && MultiAndDivisionReplacement.back() == '.')
                            MultiAndDivisionReplacement.pop_back();
                    };
                    size_t pos = CalToReplace.find(CalToRemove);
                    if (pos != string::npos) {
                        CalToReplace.replace(pos, CalToRemove.length(), MultiAndDivisionReplacement);
                    } else {
                       
                        break;
                    }

                  
                    

                    static string lastState;
                    if (CalToReplace == lastState) break;
                    lastState = CalToReplace;
                }


                while (CalToReplace.find(p) != string::npos || CalToReplace.find(m, 1) != string::npos) {
                    string CalToRemove = CalToReplace; 
                    string PlusAndMinusReplacement = to_string(PlusAndMinusCal(CalToRemove));
                    if (PlusAndMinusReplacement.find('.') != string::npos) {
                        while (!PlusAndMinusReplacement.empty() && PlusAndMinusReplacement.back() == '0')
                            PlusAndMinusReplacement.pop_back();

                        if (!PlusAndMinusReplacement.empty() && PlusAndMinusReplacement.back() == '.')
                            PlusAndMinusReplacement.pop_back();
                    };
                    CalToReplace = PlusAndMinusReplacement;
                }

                int posST;
                int posSE;

                posST = equation.rfind(st);
                if (posST != string::npos) {
                }
                posSE = equation.substr(posST).find(se);
                if (posSE != string::npos) {
                    posSE += posST;
                }
                equation.replace(posST, (posSE- posST) + 1, CalToReplace);

            }
        while (equation.find("--") != string::npos)
            equation.replace(equation.find("--"), 2, "+");
        while (equation.find("+-") != string::npos)
            equation.replace(equation.find("+-"), 2, "-");
        while (equation.find("-+") != string::npos)
            equation.replace(equation.find("-+"), 2, "-");

        while (equation.find(t) != string::npos || equation.find(d) != string::npos) {
                    string CalToRemove = seperator(equation);
                    if (CalToRemove.empty()) {
                        break;
                    }

                    string MultiAndDivisionReplacement = to_string(MultiAndDivideCal(CalToRemove));
                    if (MultiAndDivisionReplacement.find('.') != string::npos) {
                        while (!MultiAndDivisionReplacement.empty() && MultiAndDivisionReplacement.back() == '0')
                            MultiAndDivisionReplacement.pop_back();

                        if (!MultiAndDivisionReplacement.empty() && MultiAndDivisionReplacement.back() == '.')
                            MultiAndDivisionReplacement.pop_back();
                    };
                    size_t pos = equation.find(CalToRemove);
                    if (pos != string::npos) {
                        equation.replace(pos, CalToRemove.length(), MultiAndDivisionReplacement);
                    } else {
                        break;
                    }

                    
                    static string lastState;
                    if (equation == lastState) break;
                    lastState = equation;
                }

        while (equation.find(p) != string::npos || equation.find(m, 1) != string::npos) {
                    string CalToRemove = equation; 
                    string PlusAndMinusReplacement = to_string(PlusAndMinusCal(CalToRemove));
                    if (PlusAndMinusReplacement.find('.') != string::npos) {
                        while (!PlusAndMinusReplacement.empty() && PlusAndMinusReplacement.back() == '0')
                            PlusAndMinusReplacement.pop_back();

                        if (!PlusAndMinusReplacement.empty() && PlusAndMinusReplacement.back() == '.')
                            PlusAndMinusReplacement.pop_back();
                    };
                    equation = PlusAndMinusReplacement;
                } 
                
        cout << "|| The answer is : " << equation << " ||" << endl;
        cout << "\n=== Finished! Restarting... ===\n" << endl;
    }

    return 0;

}
