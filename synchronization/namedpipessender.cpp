#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#DEFINE FIFO_FILE "/tmp/my_fifo" 
struct details
{
    int regno;
    string name;
    string course;
    string school;
}
using namespace std;
int main()
{
    int fd;
    struct details detail;
    mkfifo(FIFO_FILE,0666);
    fd=open(FIFO_FILE,O_WRONLY);
    cout << "enter registration number";
    cin >> detail.regno;
    cout <<endl;
    cout << "name";
    cin >> detail.name;
    cout <<endl;
    cout << "course";
    cin >> detail.course;
    cout <<endl;
    cout << "enter school";
    cin >> detail.school;
    cout <<endl;
    write(fd,&detail,sizeof(struct details));
}