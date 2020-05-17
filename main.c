#include "menu.h"
#include "student.h"
#include "teacher.h"
#include "comm.h"

int main()
{
    node_t *stulist = NULL;
    node_t *tchlist = NULL;
    stulist = loadstu();
    //welcomestu_menu(stulist);
    //
    int a = 1;
    node_t *find = getstu(stulist, 1, &a);
    show_stu(find->data);
    // admin_menu(stulist, tchlist);
    // login_menu(stulist, tchlist);
    //  savestuInfo(stulist);
    return 0;
}