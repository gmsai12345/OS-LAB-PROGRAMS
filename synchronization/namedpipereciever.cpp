#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/stat.h>
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
    struct details detail1;
    fd=open(FIFI_FILE,O_RDONLY);
    read(fd,&detail1,sizeof(struct details));
    cout << detail1.name << " " << detail1.regno << " " << detail1.course << " " << " " <<detail1.school; 
    return 0;
}