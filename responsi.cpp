#include<iostream>
#include<string>
#define MAX 50
using namespace std;


void push(char);
char pop();
string hasil(string);
char stk[MAX];
int top=-1;
bool isFull();
bool isEmpty();

int main()
{
    int cont;
    string nilai, post;
    cout<<"masukkan nilai : ";
    cin>>nilai;
    post = hasil(nilai);
    return 0;
}

bool isFull()
{
    if(top == MAX - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isEmpty()
{
    if(top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// prosedur memasukkan operator ke stack
void push(char oper)
{
    if(isFull())
    {
        cout<<"";
    }

    else
    {
        top++;
        stk[top]=oper;
    }
}

// fungsi untuk menghapus data dari stack
char pop()
{
    char ch;
    if(isEmpty())
    {
        cout<<"";
    }
    else
    {
        ch=stk[top];
        stk[top]='\0';
        top--;
        return(ch);
    }
    return 0;
}


/*
* fungsi untuk mengonversi infix ke postfix, asumsinya semua ekspresi sudah valid
*/
string hasil(string nilai)
{
    int i=0;
    string pst = "";

    // looping selama urutan terakhir string tidak kosong
    while(nilai[i]!='\0')
    {
        // jika ketemu alfabet, maka masukkan ke variabel
        if(nilai[i]>='a' && nilai[i]<='z' || nilai[i]>='A' && nilai[i]<='Z')
        {
            pst.insert(pst.end(),nilai[i]);
            i++;
        }
        // jika ketemu kurung buka, push ke stack
        else if(nilai[i]=='*')
        {
            pop();
            i++;
        }
        //jika ketemu kurung tutup, pop dari stack

    }

    // pada akhirnya, remove semua operator dari stack
    while(top!=-1)
    {
        pst.insert(pst.end(),pop());
    }
    cout<<"Hasil niali setelah pop  : "<<pst;
    return pst;
}
