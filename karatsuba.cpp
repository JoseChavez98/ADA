#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <stack>

std::string SumaColumna(std::vector<std::string> numeros){
    unsigned long size=0;
    for(auto &i: numeros){
        if(i.size()>size){
            size=i.size();
        }
    }

    int sum_holder=0;
    int sum=0;
    std::string numero;
    std::string extra;
    for(int i=0;i<size;i++){
        for(auto &j : numeros){
            if(i<j.size()) {
                extra=j[(j.size()-1)-i];
                sum += stoi(extra);
            }
        }
        sum+=sum_holder;
        if(i==size-1){
            numero.insert(0,std::to_string(sum));
        }
        else{

            sum_holder= (sum/10);
            sum=sum%10;
            numero.insert(0,std::to_string(sum));
            sum=0;

        }
    }
    return numero;
}

std::string multiply(std::string a, std::string b){
    std::vector<std::string> numeros;
    std::string string_holder;
    int num_holder=0;
    int  sum_holder=0;
    int mult=0;
    if(a>=b){
        for(int i=b.size()-1;i>=0;i--){

            for(int j=a.size()-1;j>=0;j--){
                std::string d="";
                std::string s="";
                d+=b[i];
                s+=a[j];
                mult=(stoi(d)* stoi(s))+sum_holder;
                num_holder=mult%10;
                sum_holder=mult/10;
                if(j==0){
                    string_holder.insert(0,std::to_string(mult));

                }else{
                string_holder.insert(0,std::to_string(num_holder));
                }
                d="";
                s="";
            }
            for(int k=1;k<b.size()-i;k++){
                string_holder+="0";
            }
            numeros.push_back(string_holder);
            string_holder="";
            sum_holder=0;
        }
    }
    else{
        auto temp=a;
        a=b;
        b=temp;

        for(int i=b.size()-1;i>=0;i--){

            for(int j=a.size()-1;j>=0;j--){
                std::string d="";
                std::string s="";
                d+=b[i];
                s+=a[j];
                mult=(stoi(d)* stoi(s))+sum_holder;
                num_holder=mult%10;
                sum_holder=mult/10;
                if(j==0){
                    string_holder.insert(0,std::to_string(mult));

                }else{
                    string_holder.insert(0,std::to_string(num_holder));
                }
                d="";
                s="";

            }
            for(int k=1;k<b.size()-i;k++){
                string_holder+="0";
            }
            numeros.push_back(string_holder);
            string_holder="";
            sum_holder=0;
            num_holder=0;
        }
    }
    std::string final=SumaColumna(numeros);
    return final;
}

std::string devide_by_two(std::string number){
    std::string new_number;
    std::string new_number2;
    std::string holder;
    std::string next_holder="0";
    std::string extra;
    char digit;
    int divide;
    for(int i=0;i<number.size();i++){
            holder=next_holder;
            extra=number[i];
            if(stoi(extra)%2!=0){
                next_holder="5";
            }else{
                next_holder="0";
            }
            divide=(stoi(extra)/2)+stoi(holder);
            new_number+=std::to_string(divide);
        }
    bool switchs=false;
        for(auto &i :new_number){
            if(new_number.size()==1){
                new_number2=new_number;
                break;}
            if(i!='0'){switchs=true;}
            if(switchs){
                new_number2+=i;
            }
        }
    return new_number2;
    }

std::string bin_stack(std::string number){
    char last = number[number.size()-1];
    if(last=='1' or last=='3' or last=='5' or last=='7' or last=='9'){
        return "1";
    }else{
        return "0";
    }
}

std::string make_binary(std::string number){
    std::string final_binary_number;
    std::stack<std::string> binary_number;
    if(number == "0" ){
        binary_number.push("0");
    }else{
        while(number!="0" ){
            binary_number.push(bin_stack(number));
            number=devide_by_two(number);
        }
    }
    for(auto i=0;i,binary_number.size();i++){
        final_binary_number+=binary_number.top();
        binary_number.pop();
    }
    return final_binary_number;
}

int same_size(std::string &number1, std::string &number2){
    int size = number1.size();
    int size1 = number2.size();
    if (size < size1){
        for (int i=0;i< size1-size;i++) {
            number1 = '0' + number1;
        }
        return size1;
    }
    else if (size > size1)
    {
        for (int i=0;i<size-size1;i++) {
            number2 = '0' + number2;
        }
    }
    return size;
}

std::string suma_binary( std::string first, std::string second ){
    std::string result;

    int length = same_size(first, second);
    int carry = 0;

    for (int i = length-1 ; i >= 0 ; i--)
    {
        int firstBit = first.at(i) - '0';
        int secondBit = second.at(i) - '0';

        int sum = (firstBit ^ secondBit ^ carry)+'0';

        result = (char)sum + result;

        carry = (firstBit&secondBit) | (secondBit&carry) | (firstBit&carry);
    }

    if (carry)  result = '1' + result;

    return result;
}

int multiplyiSingleBit(std::string a, std::string b)
{  return (a[0] - '0')*(b[0] - '0');  }

unsigned long int multiply1(std::string X, std::string Y)
{
    int n = same_size(X, Y);

    if (n == 0) return 0;
    if (n == 1) return multiplyiSingleBit(X, Y);

    int fh = n/2;
    int sh = (n-fh);

    std::string Xl = X.substr(0, fh);
    std::string Xr = X.substr(fh, sh);

    std::string Yl = Y.substr(0, fh);
    std::string Yr = Y.substr(fh, sh);

    unsigned long int P1 = multiply1(Xl, Yl);
    unsigned long int P2 = multiply1(Xr, Yr);
    unsigned long int P3 = multiply1(suma_binary(Xl, Xr), suma_binary(Yl, Yr));

    return P1*(1<<(2*sh)) + (P3 - P1 - P2)*(1<<sh) + P2;
}


std::string karatsuba(std::string number1,std::string number2){
    /*
     * separating numbers in two sets
     * */

    if(number1.size()==1 && number2.size()==1){
        return std::to_string(std::stoi(number1)*std::stoi(number2));
    }
    std::string aa,bb,cc,dd;
    int half;
    if(number1.size()%2==0) {
        half = number1.size() / 2;
    }else{
        half = (number1.size() / 2)+1;
    }
    bool switchs=false;
    int cont=0;
    for(auto &i : number1){
        if(cont==half){
            switchs=true;
            cont++;
        }
        if(!switchs){
            aa+=i;
            cont++;
        }else{
            bb+=i;
        }
    }
    int half1;
    if(number2.size()%2==0) {
        half1 = number2.size() / 2;
    }else{
        half1 = (number2.size() / 2)+1;
    }
    bool switchs1=false;
    int cont1=0;
    for(auto &i : number2){
        if(cont1==half1){
            switchs1=true;
            cont1++;
        }
        if(!switchs1){
            cc+=i;
            cont1++;
        }else{
            dd+=i;
        }
    }
/*
 * multiplication process
 * */

    std::string ac,bd;
    if(number1.size()>2){
        ac=karatsuba(aa,cc);
        bd=karatsuba(bb,dd);
    }else{
        ac=std::to_string(stoi(aa)*stoi(cc));
        bd=std::to_string(stoi(bb)*stoi(dd));
    }

    unsigned long int a,b,c,d;

    a=stoi(aa);
    b=stoi(bb);
    c=stoi(cc);
    d=stoi(dd);

    unsigned long int mid_term=(a+b)*(c+d);

    unsigned long int nac=stoi(ac);
    unsigned long int nbd=stoi(bd);

    unsigned long int  first_term;
    unsigned long int second_term;

    if(number1.size()%2==0){
        first_term=(pow(10,number1.size())*nac);
        second_term=(pow(10,(number2.size()/2))*(mid_term-(nac+nbd)));
    }else{
        first_term=(pow(10,number1.size()-1)*nac);
        second_term=(pow(10,((int)(number2.size()/2)))*(mid_term-(nac+nbd)));
    }

    unsigned long int ecuation=first_term+second_term+nbd;
    return std::to_string(ecuation);
}

int main(){

    std::string a="3141592653589793238462643383279502884197169399375105820974944592";
    std::string b="2718281828459045235360287471352662497757247093699959574966967627";
    //std::cin>>a>>b;
    std::cout<<multiply(a,b)<<'\n';
    //std::cout<<karatsuba(a,b);
//    a=make_binary(a);
//    b=make_binary(b);
//    std::cout<<multiply1(a,b);

    return 0;
}