class Solution {
public:
    bool isNumber(string s) {
        bool digitSeen = false;
        bool dotSeen = false;
        bool exponentSeen = false;
        bool digitAfterExponent = true;

        for(int i = 0; i < s.size(); i++){
            char c = s[i];

            //Digit
            if(isdigit(c)){
                digitSeen = true;

                // If exponent exists, we need a digit after it 
                if(exponentSeen){
                    digitAfterExponent = true;

                }
            }
            //Dot

            else if( c=='.'){
                // Dot cannot appear twice
                // and cannot appear after exponent

                if(dotSeen || exponentSeen){
                    return false;
                }

                dotSeen = true;
            }

            //Exponent

            else if (c == 'e' || c == 'E'){
             //Exponent can not appear twice
             // and there must be a number before it

             if (exponentSeen || !digitSeen){
                return false;
             }

             exponentSeen = true;
             digitAfterExponent = false;

        
            }
            //SIGN

            else if (c == '+' || c == '-'){

                // Sign is valid only at the beginning
                // or immediately after e/E

                if( i != 0 && s[i - 1] != 'e' && s[i - 1] != 'E'){
                    return false;
                }
            }

            //Anything else
            else{
                return false;
            }
        }
        return digitSeen && digitAfterExponent;
    }
};