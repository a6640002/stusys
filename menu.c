#include "student.h"
#include "menu.h"
int count = 0;
int login_menu(node_t *stulist, node_t *tchlist)
{
    //system("clear");
    printf("\t\t\t\t 欢迎登陆！\n");
    printf("\t\t\t\t 输入按键 操作\n");
    printf("\t\t\t\t 1:进入管理员界面\n");
    printf("\t\t\t\t 2:进入学生界面\n");
    printf("\t\t\t\t 3:退出\n");
    count = 0;
    int op = 0;

    int flag = scanf(" %d", &op);
    while (flag != 1)
    {
        printf("\t\t\t\t输入错误 重新输入\n");
        printf("----->");

        getchar();
        flag = scanf(" %d", &op);
    }
    switch (op)
    {
    case 1:
        welcomeadmin_menu(stulist, tchlist);
        break;
    case 2:
        welcomestu_menu(stulist);
        break;
    case 3:
        return 0;

    default:
        login_menu(stulist, tchlist);
        break;
    }
    return 0;
}

int admin_menu(node_t *stulist, node_t *tchlist)
{
    //system("clear");
    printf("\t\t\t\t 欢迎进入管理员界面！\n");
    printf("\t\t\t\t 输入按键 操作\n");
    printf("\t\t\t\t 1:添加学生\n");
    printf("\t\t\t\t 2:删除学生\n");
    printf("\t\t\t\t 3:修改学生\n");
    printf("\t\t\t\t 4：查看学生\n");
    printf("\t\t\t\t 5：排序学生\n");
    printf("\t\t\t\t 6：返回主界面\n");
    //admin_menu(stulist, tchlist);
    int op = 0, count = 0;
    //  getchar();
    while (scanf("%d", &op) != 1)
    {
        printf("input error");
        admin_menu(stulist, tchlist);
        return 1;
        //  login_menu(stulist, tchlist);
    }

    if (op == 1)
    {
        addstu(stulist);
        show_stu_all(stulist);
        // sleep(10);

        // system("clear");
        admin_menu(stulist, tchlist);
        return 0;
    }
    if (op == 2)
    {
        printf("输入学号来删除学生 \n");
        show_stu_all(stulist);
        while (scanf(" %d", &op) != 1)
        {
            printf("input error");

            //  login_menu(stulist, tchlist);
        }
        delstu_cid(stulist, op);

        //show_stu_all(stulist);
        show_stu_all(stulist);
        // sleep(10);

        system("clear");
        admin_menu(stulist, tchlist);
        return 0;
    }
    if (op == 3)
    {

        show_stu_all(stulist);
        printf("\t\t\t\t 输入学生id来修改学生信息");
        getchar();
        while (scanf(" %d", &op) != 1)
        {
            printf("input error");

            //  login_menu(stulist, tchlist);
        }
        node_t *find = getstu(stulist, 1, &op);
        show_stu(find->data);
        stu_t *stup = find->data;

        printf("\t\t\t\t 输入按键 操作\n");
        printf("\t\t\t\t 1:修改年龄\n");
        printf("\t\t\t\t 2:修改班级\n");
        printf("\t\t\t\t 3:删除密码\n");
        printf("\t\t\t\t 4：修改姓名\n");
        int op = 0, count = 0;
        getchar();
        while (scanf(" %d", &op) != 1)
        {
            printf("input error");
            return 1;
            //  login_menu(stulist, tchlist);
        }

        if (op == 1)
        {
            printf("输入年龄-> \n");
            int age = 0, count = 0;
            while (scanf(" %d", &age) != 1)
            {
                printf("input error");
                return 1;
                //  login_menu(stulist, tchlist);
            }
            stup->age = age;
            printf("\t修改成功！\n");
            printf("学号\t姓名\t密码\t总分\tc语言成绩\t数学成绩\t语文成绩\t年龄\t班级\n");

            show_stu(find->data);
        }
        if (op == 2)
        {
            printf("输入班级-> \n");
            int classid = 0, count = 0;
            while (scanf(" %d", &classid) != 1)
            {
                printf("input error");
                return 1;
                //  login_menu(stulist, tchlist);
            }
            stup->classid = classid;
            printf("\t修改成功！\n");
            printf("学号\t姓名\t密码\t总分\tc语言成绩\t数学成绩\t语文成绩\t年龄\t班级\n");

            show_stu(find->data);
        }
        if (op == 3)
        {
            printf("输入密码-> \n");
            char pass[10], count = 0;
            while (scanf(" %s", pass) != 1)
            {
                printf("input error");
                return 1;
                //  login_menu(stulist, tchlist);
            }
            strncpy(stup->pass, pass, sizeof(stup->pass));
            printf("\t修改成功！\n");
            printf("学号\t姓名\t密码\t总分\tc语言成绩\t数学成绩\t语文成绩\t年龄\t班级\n");
            show_stu(find->data);
        }
        if (op == 4)
        {
            printf("输入姓名-> \n");
            char name[10], count = 0;
            while (scanf(" %s", name) != 1)
            {
                printf("input error");
                return 1;
                //  login_menu(stulist, tchlist);
            }
            strncpy(stup->name, name, sizeof(stup->name));
            printf("\t修改成功！\n");
            printf("学号\t姓名\t密码\t总分\tc语言成绩\t数学成绩\t语文成绩\t年龄\t班级\n");
            show_stu(find->data);
        }
        show_stu_all(stulist);
        //sleep(10);
        //show_stu_all(stulist);
        // system("clear");
        admin_menu(stulist, tchlist);
    }
    if (op == 4)
    {
        show_stu_all(stulist);
        sleep(1);
        // show_stu_all(stulist);
        // system("clear");
        admin_menu(stulist, tchlist);
        return 0;
    }
    if (op == 5)
    {
        printf("\t\t\t输入排序方式\n");
        printf("\t\t\t1.根据学号排序\n");
        printf("\t\t\t2.根据数学成绩排序\n");
        printf("\t\t\t3.根据语文成绩排序\n");
        printf("\t\t\t4.根据总分排序\n");
        int op = 0, count = 0;
        //getchar();
        while (scanf("%d", &op) != 1)
        {
            printf("input error");
            return 1;
            //  login_menu(stulist, tchlist);
        }
        if (op > 5 || op < 0)
        {
            printf("input error \n");
            admin_menu(stulist, tchlist);
            return -1;
        }
        sortstu(stulist, op);
        // sleep(10);
        show_stu_all(stulist);
        //system("clear");
        admin_menu(stulist, tchlist);
        //show_stu_all()
        return 0;
    }
    if (op == 6)
    {
        login_menu(stulist, tchlist);
        return 0;
    }
}

int welcomeadmin_menu(node_t *stulist, node_t *tchlist)
{

    if (count >= 3)
    {
        sleep(1);
        printf("登陆次数超过3次 请重新登陆 \n");
        count = 0;
        login_menu(stulist, tchlist);
        return 1;
    }
    //count = 0;
    // system("clear");
    printf("\t\t\t\t 欢迎进入管理员登陆界面！\n");
    printf("\t\t\t\t 输入按键 操作\n");
    printf("\t\t\t\t 请输入账号 密码\n");
    printf("\t\t\t\t 你还有%d次输入机会\n", 3 - count);
    //int count = 0;
    getchar();
    char name[10], pass[10];
    while (scanf(" %s %s", name, pass) != 2)
    {
        printf("\t\t\t\t 输入错误\n");
        return 1;
        //  login_menu(stulist, tchlist);
    }

    // if ((strncmp(name, ADMINNAME, sizeof(name)) == 0) && (strncmp(pass, ADMINPASS, sizeof(pass)) == 0))
    if ((strncmp(name, ADMINNAME, sizeof(name)) == 0) && (strncmp(pass, ADMINPASS, sizeof(pass)) == 0))
    {
        sleep(1);
        printf("\t\t\t\t 登陆成功\n");
        admin_menu(stulist, tchlist);
        return 0;
    }

    printf("\t\t\t\t 登陆失败,密码错误\n");
    sleep(1);
    count++;
    welcomeadmin_menu(stulist, tchlist);
}

int welcomestu_menu(node_t *stulist)
{
    if (count >= 3)
    {
        sleep(1);
        printf("错误次数超过3次 请重新登陆 \n");
        count = 0;
        return 1;
    }
    // system("clear");
    printf("\t\t\t\t 欢迎进入学生登陆界面！\n");
    printf("\t\t\t\t 输入按键 操作\n");
    printf("\t\t\t\t 请输入账号 密码\n");
    //int count = 0;
    //getchar();
    char name[10], pass[10];
    getchar();
    int flag = scanf("  %s %s", name, pass);
    while (flag != 2)
    {
        printf("\t\t\t\t输入错误 重新输入\n");
        printf("----->");

        getchar();
        flag = scanf("  %s %s", name, pass);
    }

    /* while (scanf("  %s %s", name, pass) != 2)
    {
        getchar();
        printf("\t\t\t\t 输入错误\n");
        return 1;
        //  login_menu(stulist, tchlist);
    }
    */
    // printf("%s %s \n", name, pass);
    node_t *find = getstu(stulist, 2, name);
    if (find == NULL)
    {
        printf("账户错误 !\n");
        count++;
        welcomestu_menu(stulist);
        return 1;
    }
    //((stu_t *)(find->data))->pass
    // if ((strncmp(name, ADMINNAME, sizeof(name)) == 0) && (strncmp(pass, ADMINPASS, sizeof(pass)) == 0))
    if ((strncmp(pass, ((stu_t *)(find->data))->pass, sizeof(pass)) == 0))
    {
        sleep(1);
        printf("\t\t\t\t 登陆成功\n");
        stu_menu(find, find->data);
        // admin_menu(stulist, tchlist);
    }
    sleep(1);
    // printf("\t\t\t\t 密码失败\n");
    count++;
    // welcomeadmin_menu(stulist, tchlist);
}

int stu_menu(node_t *stulist, stu_t *stup)
{
    // system("clear");
    printf("\t\t\t\t 欢迎进入学生界面！\n");
    printf("\t\t\t\t 输入按键 操作\n");
    printf("\t\t\t\t 1:修改年龄\n");
    printf("\t\t\t\t 2:修改班级\n");
    printf("\t\t\t\t 3:删除密码\n");
    printf("\t\t\t\t 4：修改姓名\n");
    printf("\t\t\t\t 5：退出\n");
    int op = 0, count = 0;
    int flag = scanf(" %d", &op);
    while (flag != 1)
    {
        printf("\t\t\t\t输入错误 重新输入\n");
        printf("----->");

        getchar();
        flag = scanf(" %d", &op);
    }

    if (op == 1)
    {
        printf("输入年龄-> \n");
        int age = 0, count = 0;
        while (scanf(" %d", &age) != 1)
        {
            printf("input error");
            stu_menu(stulist, stup);
            //  login_menu(stulist, tchlist);
        }
        // printf("age =%d \n ", age);
        // printf("%d \n ", stup->age);
        stup->age = age;
        //printf("%d \n ", stup->age);
        printf("学号\t姓名\t密码\t总分\tc语言成绩\t数学成绩\t语文成绩\t年龄\t班级\n");
        show_stu(stulist->data);
    }
    if (op == 2)
    {
        printf("输入班级-> \n");
        int classid = 0, count = 0;
        while (scanf(" %d", &classid) != 1)
        {
            printf("input error");
            stu_menu(stulist, stup);
            // return 1;
            //  login_menu(stulist, tchlist);
        }
        stup->classid = classid;
        printf("学号\t姓名\t密码\t总分\tc语言成绩\t数学成绩\t语文成绩\t年龄\t班级\n");
        show_stu(stulist->data);
    }
    if (op == 3)
    {
        printf("输入密码-> \n");
        char pass[10], count = 0;
        while (scanf(" %s", pass) != 1)
        {
            printf("input error");
            stu_menu(stulist, stup);
            //  login_menu(stulist, tchlist);
        }
        strncpy(stup->pass, pass, sizeof(stup->pass));
        printf("学号\t姓名\t密码\t总分\tc语言成绩\t数学成绩\t语文成绩\t年龄\t班级\n");
        show_stu(stulist->data);
    }
    if (op == 4)
    {
        printf("输入姓名-> \n");
        char name[10], count = 0;
        while (scanf(" %s", name) != 1)
        {
            printf("input error");
            stu_menu(stulist, stup);
            //  login_menu(stulist, tchlist);
        }
        strncpy(stup->name, name, sizeof(stup->name));
        printf("学号\t姓名\t密码\t总分\tc语言成绩\t数学成绩\t语文成绩\t年龄\t班级\n");
        show_stu(stulist->data);
    }
    if (op == 5)
    {

        return 0;
    }

    stu_menu(stulist, stup);
}

/****************
功能： 管理员修改函数
参数：node_t *find 指定学生节点; int op  选择操作模式;
返回值：成功 返回0，失败则返回1

函数流程：
1、switch(op) 
case 1: //1.修改学生姓名
case 2: //2.修改学生密码
case 3: // 3.修改学生年龄 
case 4: //4.修改学生数学成绩
case 5: //5.修改C语言成绩
case 6: //6.修改语文成绩
case 7: //7.修改总分
case 7: //8.修改排序
case 7: //7.修改班号

*************/
int modify_by_admin(node_t *find, int op)
{

    switch (op)
    {
    case 1:
        char name[32];
        fflush(0);
        scanf("%s", ((stu_t *)(find->data))->name);
        // strncpy(, )

        break;

    default:
        break;
    }
}