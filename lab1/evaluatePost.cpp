#include<iostream>
#include<cmath>
#include<stack>
#include<string>

float evaluatePost(std::string);

int main()
{
    std::cout<<"12*3-5+ = "<<evaluatePost("12*3-5+")<<std::endl;
    return 0;
}

float evaluatePost(std::string postfix)
{
    std::stack<float> st;
    float a, b;

    for (const auto &ch: postfix)
    {
        if(ch >= '0' && ch <= '9')
        {
            st.push(ch - '0');
        }
        else
        {
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            if(ch == '^')
            {
                st.push(pow(b,a));
            }
            if(ch == '/')
            {
                st.push(b/a);
            }
            if(ch == '*')
            {
                st.push(b*a);
            }
            if(ch == '+')
            {
                st.push(b+a);
            }
            if(ch == '-')
            {
                st.push(b-a);
            }
        }
    }
    return st.top();
}