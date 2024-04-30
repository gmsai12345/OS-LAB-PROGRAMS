#include <bits/stdc++.h>
#include <sys/ipc.h>
#include <sys/msg.h>
using namespace std;

struct mesg
{
    long mesg_type;
    string msg;
};

int main()
{
    struct mesg mes;
    key_t key;
    int msgid;
    key=ftok("progfile",65);
    msgid=msgget(key,0666|IPC_CREAT);
    mes.mesg_type=1;
    cout << "got data is" <<endl;
    msgrcv(msgid,&mes,sizeof(struct mesg));
    cout << mes.msg;
    msgctl(msgid, IPC_RMID, NULL); 
    return 0;
}