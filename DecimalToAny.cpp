#include <iostream>
#include <string>

class DecimalToAny{
private:
    float Dec_value;
public:
    DecimalToAny(float dec_value) : Dec_value(dec_value) {}
    void calculate(){
        int choice;
        std::cout << "Your number: " << Dec_value << std::endl;
        std::cout << "1 - Decimal -> Binary" << std::endl;
        std::cout << "2 - Decimal -> Octal" << std::endl;
        std::cout << "3 - Decimal - Hex" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        std::string res = "";
        int number = (int)Dec_value;
        float dec_number = Dec_value - (int)Dec_value;

        switch(choice){
            case 1: res = decimalToBinary(number);
                    res += fractionalToBinary(dec_number);
                    std::cout << res << std::endl;
                    break; 
            case 2: res = decimalToOctal(number);
                    res += fractionalToOctal(dec_number);
                    std::cout << res << std::endl;
                    break;
            case 3: res = decimalToHex(number);
                    res += fractionalToHex(dec_number);
                    std::cout << res << std::endl;
                    break;
            default: std::cout << "Invalid Choice" << std::endl; break;
        }
    }
    std::string decimalToBinary(int number){
        std::string result = "";
        while(number >= 1){
            result = std::to_string(number % 2) + result;
            number /= 2;
        }
        return result.empty() ? "0" : result;
    }
    std::string decimalToOctal(int number){
        std::string result = "";
        while(number >= 1){
            result = std::to_string(number % 8) + result;
            number /= 8;
        }
        return result.empty() ? "0" : result;
    }
    std::string decimalToHex(int number){
        std::string result = "";
        char hexChars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
        while(number >= 1){
            result = hexChars[number % 16] + result;
            number /= 16;
        }
        return result.empty() ? "0" : result;
    }
    std::string fractionalToOctal(float number){
        std::string result = ".";
        int count = 0;
        while(count < 2){
            number *= 8;
            result += std::to_string((int)number);
            number -= (int)number;
            count++;
        }
        return result;
    }
    std::string fractionalToHex(float number){
        std::string result = ".";
        int count = 0;
        char hexChars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
        while(count < 2){
            number *= 16;
            result += hexChars[(int)number];
            number -= (int)number;
            count++;
        }
        return result;
    }
    std::string fractionalToBinary(float number){
        std::string result = ".";
        int count = 0;
        while(count < 2){
            number *= 2;
            result += std::to_string((int)number);
            number -= (int)number;
            count++;
        }
        return result;
    }
};

int main()
{
    float num;
    std::cout << "Enter number in decimal system: ";
    std::cin >> num;

    DecimalToAny ml(num);

    ml.calculate();

    return 0;

}