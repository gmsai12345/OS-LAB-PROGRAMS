#include <bits/stdc++.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 10
struct mesg
{
    long msg_type;
    string msg;
};
int main()
{
    struct mesg mes;
    key_t key;
    int msgid;
    key=ftok("progfile",65);
    mes.msg_type=1;
    msgid=msgget(key,0666|IPC_CREAT);
    cout << "enter message";
    cin >> mes.msg;
    msgsend(msgid,&mes,sizeof(struct mesg));
    cout <<endl;
    cout << "data sent is" << mes.msg;

}