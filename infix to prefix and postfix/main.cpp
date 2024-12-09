#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
using namespace  std;

struct NumOrOpr{
    float num;
    char opr;
};

void postfix(string);
string changeToPostfix(string);
float solvePostfix(string , float);
void prefix(string);
void variable(string);

bool isNumber(char c){
    if(c <= '9' && c >= '0')
        return true;
    if(c == 'x')
        return true;

    return false;
}

int precedence(char opr1 , char opr2){
    if(opr1 == '(' || opr2 == '(')
        return 2;
    if((opr1 == '*' || opr1 == '/') && (opr2 == '*' || opr2 == '/'))
        return 1;
    if((opr1 == '+' || opr1 == '-') && (opr2 == '+' || opr2 == '-'))
        return 1;
    if(opr1 == '^')
        return 2;
    if(opr2 == '^')
        return 0;
    if(opr1 == '*' || opr1 == '/')
        return 2;

    return 0;

}

float solve(char opt , float f1 , float f2){
    switch (opt) {
        case '^' :
            return pow(f1 , f2);
            break;
        case '+':
            return f1 + f2;
            break;
        case '-':
            return f1 - f2;
            break;
        case '*':
            return f1 * f2;
            break;
        case '/':
            return f1 * 1.0 / f2;
            break;
    }

}

int main() {
    int option;
    string str;
    cout<<"Do you want to enter as a number or a variable?\n1.number\n2.variable\n"<<endl;
    cin>>option;

    cout<<"\nInfix : ";
    cin>>str;
    if(option == 1){

        postfix(str);
        prefix(str);

    }
    else{
        variable(str);
    }

    //plot//


}

string changeToPostfix(string s){
    string result;
    stack<char> st;
    int length = s.length();
    bool isParentheses = false;

    for(int i = 0;i < length;i++){
        if(isNumber(s[i]))
            result += s[i];
        else{
            if(s[i] == '-' && (i == 0 || !isNumber(s[i - 1]) && s[i - 1] != ')'))
                result += "~";
            else {
                if(s[i] == ')')
                    isParentheses = true;
                while (isParentheses || !st.empty() && precedence(s[i], st.top()) < 2) {
                    if(st.top() == '(' && isParentheses){
                        st.pop();
                        break;
                    }
                    result += st.top();
                    st.pop();
                }

                if(isParentheses){
                    isParentheses = false;
                    continue;
                }
                st.push((s[i]));


            }
        }
    }

    while(!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

float solvePostfix(string result , float f){
    int length = result.length();
    NumOrOpr value;
    stack<NumOrOpr> sta;
    float solution , fl;
    for(int i = 0;i < length;i++){
        if(isNumber(result[i])) {
            if(result[i] == 'x')
                value.num = f;
            else
                value.num = result[i] - '0';
            value.opr = '\0';
        }
        else{
            value.opr = result[i];
            value.num = 0;
        }

        if(sta.empty()) {
            sta.push(value);
        }
        else if(sta.top().opr == '~'){
            value.num *= -1;
            sta.pop();
            sta.push(value);
        }
        else if(value.opr == '\0') {

            sta.push(value);
        }
        else{
            fl = sta.top().num;
            sta.pop();
            solution = solve(value.opr, sta.top().num, fl);
            sta.pop();
            value.num = solution;
            value.opr = '\0';
            sta.push(value);
        }

    }

    return sta.top().num ;

}

void postfix(string s){

    string post = changeToPostfix(s);
    cout<<"\npostfix : "<<post<< " = " << solvePostfix(post , 0);


}



void prefix(string s){
    string result , temp;
    stack<char> st;
    int length = s.length();
    bool isParentheses = false;

    for(int i = length - 1;i >= 0;i--){
        if(isNumber(s[i])) {
            temp = s[i];
            temp += result;
            result = temp;
        }
        else{
            if(s[i] == '-' && (i == 0 || !isNumber(s[i - 1]) && s[i - 1] != ')')){
                temp = "~";
                temp += result;
                result = temp;
            }
            else {
                if(s[i] == '(')
                    isParentheses = true;
                if(s[i] == ')')
                    s[i] = '(';
                while (isParentheses || !st.empty() && precedence(s[i], st.top()) == 0) {
                    if(st.top() == '(' && isParentheses){
                        st.pop();
                        break;
                    }

                    temp = st.top();
                    temp += result;
                    result = temp;

                    st.pop();
                }

                if(isParentheses){
                    isParentheses = false;
                    continue;
                }
                st.push((s[i]));

            }
        }
    }

    while(!st.empty()) {
        temp = st.top();
        temp += result;
        result = temp;
        st.pop();
    }

    cout<<"\nprefix : "<<result;

    //solving

    length = result.length();
    NumOrOpr value;
    stack<NumOrOpr> sta;
    float solution , fl;
    for(int i = 0;i < length;i++){
        if(isNumber(result[i])) {
            value.num = result[i] - '0';
            value.opr = '\0';
        }
        else{
            value.opr = result[i];
            value.num = 0;
        }

        if(sta.empty()) {
            sta.push(value);
        }
        else if(sta.top().opr == '~'){
            value.num *= -1;
            sta.pop();
            sta.push(value);
        }
        else{
            while(!sta.empty() && sta.top().opr == '\0' && value.opr == '\0') {
                fl = sta.top().num;
                sta.pop();
                solution = solve(sta.top().opr, fl, value.num);
                sta.pop();
                value.num = solution;
                value.opr = '\0';
            }
            sta.push(value);
        }
    }
    cout<<" = "<<sta.top().num<<endl;

}



void variable(string s){
    int option;
    cout<<"\nDo you want to give a value or see the plot?\n1.value\n2.plot\n"<<endl;
    cin>>option;
    string post = changeToPostfix(s);
    if(option == 1){
        float value;
        cout<<"\nEnter value : ";
        cin>>value;
        cout<<"\nThe result = "<<solvePostfix(post , value)<<endl;
    }
    else{
        sf::RenderWindow window(sf::VideoMode(800, 600), "Plot");
        window.setFramerateLimit(60);

        sf::VertexArray axes(sf::Lines, 4);
        axes[0].position = sf::Vector2f(400, 0); // y
        axes[1].position = sf::Vector2f(400, 600);
        axes[2].position = sf::Vector2f(0, 300); // x
        axes[3].position = sf::Vector2f(800, 300);
        for (int i = 0; i < 4; i++) axes[i].color = sf::Color::Black;


        sf::VertexArray points(sf::Points);

        float scale = 50.0f; // مقیاس
        for (float x = -10.0f; x <= 10.0f; x += 0.0001f) {
            float y = solvePostfix(post , x);
            float screenX = 400 + x * scale;
            float screenY = 300 - y * scale;

            if (screenY >= 0 && screenY <= 600) {
                points.append(sf::Vertex(sf::Vector2f(screenX, screenY), sf::Color::Red));
            }
        }

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            window.clear(sf::Color::White);
            window.draw(axes);
            window.draw(points);
            window.display();
        }

    }


}