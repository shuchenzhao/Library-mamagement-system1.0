#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <windows.h>
#include<algorithm>
 
using namespace std;
 
struct library{
	int ID;
	char name[30];
	double price;
	char author[30];
	int quan;
	char itd[2000];
}stu[100];
struct asccount{
    char AcName[30];
    char password[12];
    char nickname[30];
}sta[100];
struct Book{
	char Name[30];
	char time[40];
};
struct node{
	char users[30];
	int sexes;
	struct Book book[30];
	int r;
	node *Next;
};
typedef struct node *L;
L pre, hnj=NULL, kl = new node;
L HEAD = new node;
char strr[30];
int num=42,LLL,jj=2,logo=0,h=0,F=1,k=2,huan,oo;
 
void display(void);//显示图书信息管理菜单*
void load(void);//把图书信息加载到内存*
void save(void);//将数据保存到磁盘*
void Sort(void);//排序*
void SortByScore(void);//按书名首字母排序*
void AscendVyPick(void);//按单价升序排序*
void DesendByPick(void);//按单价降序排序*
int cmp1(library a, library b);//按书名首字母排序判断*
int cmp2(library a, library b);//按单价升序排序判断*
int cmp3(library a, library b);//按单价降序排序判断*
void IdArrange(void);//重新整理书号*
void Find(void);//查找*
void add(void);//添加*
void edit(void);//修改*
void DeleteAll(void);//删除所有信息*
void PrintRecord(void);//输出一条记录*
void FindByName(void);//按书名查找*
void FindByNum(void);//按书号查找*
void FindByAuthor(void);//按作者查找*
void output(void);//输出所有图书信息*
void over(void);//结束程序*
void Huifu(void);//恢复出厂设置*
void PrinEdit(void);//输出修改菜单*
void FindEdit(void);//输出查找菜单*
void PrintSort(void);//输出排序菜单*
void CheckUser(void);//检验账号的合法性*
void addUser(void);//新建账号*
void findPassword(void);//找回密码*
void EditPassword(void);//修改密码*
void loadUser(void);//将账号读入内存*
void saveUser(void);//将账号存入磁盘*
void printuser(void);//输出账号菜单*
int ling(void);//账号登录*
void PrintBorrow(void);//打印借书管理系统菜单*
void Menu(void);//图书信息管理*
void Borrow(void);//图书借还系统*
void BorrowRecord(L q);//借书记录*
void BorrowBook(L q, L y);//借书*
void SendBook(L q, L y);//还书*
L LookUser(L head);//用户搜索*
void loadBorrow(L head);//将借书记录加载到内存*
void saveBorrow(L head);//将用户借书记录加载到磁盘*
void FuactionIntrod(void);//系统功能介绍*
void Intropeople(void);//开发人员介绍*
void Mainmenu(void);//打印主菜单*
void hhk(void);//打印操作错误 *
void loaduu(void);//数据数加载到内存*
void saveuu(void);//数据数加载到磁盘*
void Cpy(void);//备份图书信息*
void HideCursor(void);//隐藏光标*
void inwrong(void);//判断输入是否正确*
void shan(void);
void beifen(void);
 
int main()
{
	int i,selt;
	HideCursor();
	LLL = 1;
	loaduu();
	if(!ling())
        return 0;
    system("cls");
    load();
    while(1){
        Mainmenu();
        oo = scanf("%d",&selt);
        if(!oo){
            	inwrong();
            	continue;
        }
        switch(selt){
            case 1:
                Menu(); saveuu(); break;
            case 2:
                Borrow(); break;
            case 3:
                FuactionIntrod(); break;
            case 4:
                system("cls"); Intropeople(); break;
            case 5:
                system("cls"); if(ling() == 0){return 0;}  system("cls"); break;
            case 6:
                saveuu(); system("cls"); over(); return 0;
            default :
            	system("cls"); hhk(); system("cls"); break;
        }
    }
    return 0;
}
 
//判断输入是否正确
void inwrong(void)
{
	char s[50];
	gets(s);
    system("cls");
    printf("\t\t\t输入错误！！\n");
    system("PAUSE");system("cls");
}
//隐藏光标
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
//数据数加载到内存
void loaduu(void)
{
    FILE *fp;
    fp = fopen("数据个数.txt", "r");
    fscanf(fp, "%d", &num);
    fscanf(fp, "%d", &jj);
    fclose(fp);
    k = jj;
}
//数据数加载到磁盘
void saveuu(void)
{
    FILE *fp;
    fp = fopen("数据个数.txt", "w");
    fprintf(fp, "%d\n", num);
    fprintf(fp, "%d\n", jj);
    fclose(fp);
}
//备份图书信息
void Cpy(void)
{
    FILE *fp;
    int i;
    shan();
    fp = fopen("图书信息库.txt", "w");
    for(i = 0; i < num; i++){
        fprintf(fp, "%d\n",stu[i].ID);
        fprintf(fp, "%s\n",stu[i].name);
        fprintf(fp, "%.2lf\n",stu[i].price);
        fprintf(fp, "%s\n",stu[i].author);
        fprintf(fp, "%d\n",stu[i].quan);
        fprintf(fp, "%s\n",stu[i].itd);
    }
    fclose(fp);
    saveuu();
    printf("\n\n\t\t\t备份成功！！\n");
    system("PAUSE");
    system("cls");
}
//打印主菜单
void Mainmenu(void)
{
    printf("\t   ************************************************************\n");
    if(LLL){
    printf("\t   *                欢迎使用图书管理系统                      *\n");
    LLL = 0;
    }
    else{
    printf("\t   *                                                          *\n");
    printf("\t   *      您可以进行以下操作:                                 *\n");
    }
    printf("\t   *                                                          *\n");
    printf("\t   *      图书信息管理 请按 1                                 *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      图书借还管理 请按 2                                 *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      系统功能介绍 请按 3                                 *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      开发人员介绍 请按 4                                 *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      切换账号 请按 5                                     *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      退出系统 请按 6                                     *\n");
    printf("\t   *                                                          *\n");
    printf("\t   ************************************************************\n\n");
}
//系统功能介绍
void FuactionIntrod(void)
{
	system("cls");
	printf("本系统能执行以下操作:\n\n");
	printf("一、登录界面功能介绍\n\n");
	printf("1.登录账号\n\n2.注册新账号\n\n3.密码找回\n\n4.修改密码\n\n\t\t\t   ");
	system("PAUSE");
	system("cls");
    printf("二、图书信息管理系统功能介绍\n\n");
    printf("1. 查找功能\n\n");
    printf("1）按书号查找\n2）按书名查找\n3）按作者查找\n4）输出所有图书信息\n\n");
    printf("2. 排序功能\n\n");
    printf("1）按书名首字母排序\n2）按单价升序排序\n3）按单价降序排序\n\n");
    printf("3. 修改功能\n\n");
    printf("1）添加\n\n  可添加任意本书\n\n2）删除一本图书\n3）删除全部图书\n\n");
    printf("4. 恢复图书信息\n\n  如错误删除图书信息，可恢复上一次备份的图书信息\n\n");
    printf("5.备份图书信息\n\n\t\t\t   ");
    system("PAUSE");
	system("cls");
    printf("三、图书借还系统功能介绍\n\n");
    printf("1.借阅图书功能\n\n");
    printf("此功能可使用户借阅本系统中现存的图书\n\n");
	printf("2.还书功能\n\n");
	printf("此功能可方便用户还书\n\n");
    printf("3. 用户借书还书记录查询功能\n\n");
    printf("此功能可查询个人借书和还书记录\n\n");
    printf("4. 用户借书还书信誉查询功能\n\n");
    printf("此功能可查询借书者的个人信誉值，若信誉值低于60将不能再通过本系统借书，同时，每一年年末都会对信誉值进行统计，\n");
    printf("并将所有用户信誉值恢复为100。\n\n");
    printf("信誉值扣除标准：\n\n");
    printf("1）借的书需在两个工作日内归还，逾期还书  每次扣除信誉值 5。\n");
    printf("2）对图书造成损坏或丢失的  每次扣除信誉值 10 ， 并原价赔偿。\n");
    printf("3）超过还书时间一个工作日的，信誉值将被直接清零，并不能在本系统进行任何操作。\n\n");
    printf("四、切换账号功能\n\n 可以切换账号\n\n\t\t\t   ");
    system("PAUSE");
    system("cls");
}
 
//检验账号的合法性
void CheckUser(void)
{
    int i,flag = 0,K,KK;
    char ss[30],sf[10];
    printf("\t\t\t\t请输入登录账号：\n\n\t\t\t\t ");
    scanf("%s",ss);
    for(i = 0; i < jj; i++){
        if(strcmp(sta[i].AcName, ss) == 0){
            strcpy(strr, ss);
            flag = 1;
            break;
        }
    }
    if(!flag){
        printf("\n\t\t\t\t此账号还未注册！！\n\n\t\t\t   ");
        system("PAUSE");
        system("cls");
        return;
    }
    printf("\t\t\t\t请输入密码：\n\n\t\t\t\t ");
    scanf("%s",sf);
    if(strcmp(sta[i].password, sf) == 0){
        h = 0;
        flag = 2;
    }
    if(flag == 1){
        system("cls");
        printf("\t\t\t\t密码错误！！\n\n\t\t\t   ");
        system("PAUSE");
        system("cls");
        h++;
        return ;
    }
    else if(flag == 2){
    	printf("\t\t\t   请输入下面的验证码：\n");
        srand((unsigned)time(NULL));
        K = rand();
        printf("\n\t\t\t\t  %d\n\t\t\t\t  ",K);
        oo = scanf("%d",&KK);
        if(!oo){
            inwrong();
            return ;
        }
        if(KK != K){
            printf("\n\t\t\t验证码错误！！\n");
            system("PAUSE");
            system("cls");
            return ;
        }
		logo = 1;
	}   
}
//将账号存入磁盘
void saveUser(void)
{
    int i;
    FILE *fp;
    fp = fopen("账号.txt", "w");
    for(i = 0; i <= jj; i++){
        fprintf(fp, "%s\n", sta[i].AcName);
        fprintf(fp, "%s\n", sta[i].password);
        fprintf(fp, "%s\n", sta[i].nickname);
    }
    fclose(fp);
}
//新建账号
void addUser(void)
{
    FILE *fp;
    int j=0,i;
    char c[12],str[30];
    printf("\t\t\t请输入账号：\n\n\t\t\t  ");
    scanf("%s",str);
    for(i = 0; i < jj; i++){
        if(strcmp(sta[i].AcName, str) == 0){
            printf("\t\t\t该账号已被注册，请重新申请！！\n\n\t\t\t   ");
            system("PAUSE");
            return ;
        }
    }
    strcpy(sta[jj].AcName, str);
    printf("\t\t\t请输入密码（密码长度不超过十个字符）：\n\n\t\t\t  ");
    scanf("%s", sta[jj].password);
    printf("\t\t\t请再输入一次密码：\n\n\t\t\t  ");
    scanf("%s",c);
    if(strcmp(sta[jj].password, c) != 0){
        printf("\t\t\t两次密码不一致请从新申请\n\n\t\t\t");
        system("PAUSE");
        system("cls");
        printf("\n");
        addUser();
		j = 1;
    }
    if(j)
        return ;
    printf("\n\t\t\t请输入昵称\n\n\t\t\t  ");
    scanf("%s",sta[jj].nickname);
    saveUser();
    printf("\t\t\t\t账号申请成功！！\n\n\t\t\t");
    jj++;
    strcpy(kl->users, sta[jj-1].AcName);
    kl->sexes = 0;
    strcpy(kl->book[0].Name, "0");
    strcpy(kl->book[0].time, "0");
    kl->r = 100;
    kl->Next = NULL;
    hnj = kl;
    saveuu();
    loadBorrow(HEAD);
    saveBorrow(HEAD);
    system("PAUSE");
}
//找回密码
void findPassword(void)
{
    int i;
    char a[30];
    printf("\t\t\t请输入要找回的账号：\n\t\t\t\t");
    scanf("%s",a);
    for(i = 0; i < jj; i++)
        if(strcmp(sta[i].AcName, a) == 0){
            printf("\t\t\t密码：%s\n",sta[i].password);
            system("PAUSE");
            return ;
        }
    printf("\t\t\t\t查无此账号！！\n\n\t\t\t");
    system("PAUSE");
}
//修改密码
void EditPassword(void)
{
    int i,K=0,KK=0;
    char a[30];
    printf("\t\t\t  请输入要修改密码的账号：\n\t\t\t  ");
    scanf("%s",a);
    for(i = 0; i < jj; i++)
        if(strcmp(sta[i].AcName, a) == 0){
            printf("\n\t\t\t   请输入原密码：\n\t\t\t   ");
            scanf("%s",a);
            if(strcmp(sta[i].password, a) != 0){
                printf("\n\t\t\t\t密码错误！！\n\n\t\t\t   ");
                system("PAUSE");
                system("cls");
                return ;
            }
            printf("\n\t\t\t   请输入新密码：\n\t\t\t   ");
            scanf("%s",a);
            if(strcmp(sta[i].password, a) == 0){
                printf("\n\t\t\t新密码与原密码重复，请从新修改！！\n\n\t\t\t   ");
                system("PAUSE");
                system("cls");
                return ;
            }
            strcpy(sta[i].password, a);
            printf("\t\t\t   请输入下面的验证码：\n");
            srand((unsigned)time(NULL));
            K = rand();
            printf("\n\t\t\t\t  %d\n\t\t\t\t  ",K);
            oo = scanf("%d",&KK);
            if(!oo){
            	inwrong();
            	return ;
        	}
            if(KK != K){
                printf("\n\t\t\t验证码错误！！\n");
                system("PAUSE");
                system("cls");
                return ;
            }
            printf("\n\t\t\t\t修改密码成功！！\n");
            saveUser();
            system("PAUSE");
            system("cls");
            return ;
        }
    printf("\n\t\t\t\t查无此账号！！\n\n\t\t\t");
    system("PAUSE");
 
}
//将账号读入内存
void loadUser(void)
{
    int i;
    freopen("账号.txt", "r", stdin);
    for(i = 0; i < jj; i++){
        scanf("%s",sta[i].AcName);
        scanf("%s",sta[i].password);
        scanf("%s",sta[i].nickname);
    }
    freopen("CON", "r", stdin);
}
//输出账号菜单
void printuser(void)
{
    printf("\t\t\t************************************\n");
    printf("\t\t\t*    登录 请按 1                   *\n");
    printf("\t\t\t*    注册新账号 请按 2             *\n");
    printf("\t\t\t*    找回密码 请按 3               *\n");
    printf("\t\t\t*    修改密码 请按 4               *\n");
    printf("\t\t\t*    退出程序 请按 5               *\n");
    printf("\t\t\t************************************\n");
}
//账号登录
int ling(void)
{
    int sh,i;
    hnj=NULL, kl = new node;
    h = logo = 0;
    while(1){
            printuser();
            loadUser();
            loaduu();
            oo = scanf("%d",&sh);
            if(!oo){
            	inwrong();
            	continue;
            }
            switch(sh){
            case 1:
                CheckUser(); break;
            case 2:
                addUser(); saveuu(); system("cls"); break;
            case 3:
                findPassword(); system("cls"); break;
            case 4:
                EditPassword(); break;
            case 5:
                system("cls");
                printf("\n");
                printf("\t\t\t欢迎下次使用本图书管理系统\n"); return 0;
            default :
            	system("cls"); hhk();system("cls"); break;
        }
        if(logo)
            return 1;
        if(h == 3){
            printf("\t\t\t密码错误三次，系统将自动关闭！！\n\n");
            printf("\t\t\t欢迎下次使用本的图书管理系统\n");
            return 0;
        }
    }
}
 
//恢复出厂设置
void Huifu(void)
{
    beifen();
    saveuu();
    int i = num;
    freopen("图书信息库.txt", "r",stdin);
    for(i = 0; i < num; i++){
        scanf("%d",&stu[i].ID);
        scanf("%s",stu[i].name);
        scanf("%lf",&stu[i].price);
        scanf("%s",stu[i].author);
        scanf("%d",&stu[i].quan);
        scanf("%s",stu[i].itd);
    }
    freopen("CON", "r", stdin);
    save();
    printf("\n\n\t\t\t恢复成功！！\n");
    system("PAUSE");
    system("cls");
}
void PrintRecord(int i)//输出一条记录
{
    printf("\t\t\t书号：%04d\n",stu[i].ID);
    printf("\t\t\t书名：%s\n",stu[i].name);
    printf("\t\t\t价格：%.2lf\n",stu[i].price);
    printf("\t\t\t作者：%s\n",stu[i].author);
    printf("\t\t\t库存：%d\n",stu[i].quan);
    printf("\n简介：%s\n\n",stu[i].itd);
}
 
//图书信息管理
void Menu(void)
{
    int select;
    system("cls");
    load();
    while(1){
        display();
        oo = scanf("%d",&select);
        if(!oo){
            inwrong();
            continue;
        }
        switch(select){
            case 1:
                Find(); break;
            case 2:
                Sort(); break;
            case 3:
                edit(); break;
            case 4:
                Huifu(); break;
            case 5:
                Cpy(); break;
            case 6:
                system("cls"); return ;
            default :
            	hhk(); system("cls"); break;
        }
    }
}
//显示图书信息管理菜单
void display(void)
{
    char str[3][20] = {"查找 请按 1","排序 请按 2","修改 请按 3"};
    int i,j;
    printf("\t   ************************************************************\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      您可以进行以下操作:                                 *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      查找 请按 1                                         *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      排序 请按 2                                         *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      修改 请按 3                                         *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      恢复图书信息 请按 4                                 *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      备份图书信息 请按 5                                 *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      返回上一级菜单 请按 6                               *\n");
    printf("\t   *                                                          *\n");
    printf("\t   ************************************************************\n\n");
}
//打印开发人员信息
void Intropeople(void)
{
    printf("\t   ************************************************************\n");
    printf("\t   *                                                          *\n");
    printf("\t   *                      开发人员信息                        *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *         软件工程1903052班 19030500122赵书晨              *\n");
    printf("\t   *                                                          *\n"); 
    printf("\t   ************************************************************\n\n");
    system("PAUSE");
    system("cls");
}
 
void hhk(void)//打印操作错误
{
	printf("\n");
	printf("\t\t\t  操作错误，请从新选择操作选项！！\n\n");
	system("PAUSE");
}
 
//结束程序
void over()
{
    printf("\n\t\t\t29组图书管理系统祝您阅读愉快！！！\n");
}
 
//把图书信息加载到内存
void load()
{
    int i;
    freopen("缓存区.txt", "r", stdin);
    for(i = 0; i < num; i++){
        scanf("%d",&stu[i].ID);
        scanf("%s",stu[i].name);
        scanf("%lf",&stu[i].price);
        scanf("%s",stu[i].author);
        scanf("%d",&stu[i].quan);
        scanf("%s",stu[i].itd);
    }
	freopen("CON", "r", stdin);
}
//将数据保存到磁盘
void save()
{
    int i;
    FILE *fp;
    fp = fopen("缓存区.txt", "w");
    for(i = 0; i < num; i++){
        fprintf(fp, "%d\n",stu[i].ID);
        fprintf(fp, "%s\n",stu[i].name);
        fprintf(fp, "%.2lf\n",stu[i].price);
        fprintf(fp, "%s\n",stu[i].author);
        fprintf(fp, "%d\n",stu[i].quan);
        fprintf(fp, "%s\n",stu[i].itd);
    }
    fclose(fp);
}
 
//输出修改菜单
void PrinEdit()
{
    printf("\t   ************************************************************\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      您可以进行以下操作:                                 *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      添加 请按 1                                         *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      删除一本图书 请按 2                                 *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      删除全部图书 请按 3                                 *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      返回上一级菜单 请按 4                               *\n");
    printf("\t   *                                                          *\n");
    printf("\t   ************************************************************\n\n");
}
void add()//添加
{
    FILE *fp;
    fp = fopen("缓存区.txt","a");
    int n,p,i;
    double q;
    char str[30],st[1000];
    printf("\t\t\t   亲，请输入你需要添加几项\n\n\t\t\t    ");
    oo = scanf("%d",&n);
    if(!oo){
        inwrong();
        return ;
    }
    for(i = num+1; i <= num+n; i++){
        fprintf(fp, "%d\n",i);
        stu[i-1].ID = i;
        printf("\t\t\t   请输入书名\n\n\t\t\t    ");
        scanf("%s",str);
        strcpy(stu[i-1].name, str);
        fprintf(fp, "%s\n",str);
        printf("\t\t\t   请输入价格\n\n\t\t\t    ");
        scanf("%lf",&q);
        stu[i-1].price = q;
        fprintf(fp, "%.2lf\n",q);
        printf("\t\t\t   请输入作者\n\n\t\t\t    ");
        scanf("%s",str);
        strcpy(stu[i-1].author, str);
        fprintf(fp, "%s\n",str);
        printf("\t\t\t   请输入该书的数量\n\n\t\t\t    ");
        scanf("%d",&p);
        stu[i-1].quan = p;
        fprintf(fp, "%d\n",p);
        printf("\t\t\t   请输入该书的简介\n\n\t\t\t    ");
        scanf("%s",st);
        strcpy(stu[i-1].itd, st);
 
        fprintf(fp, "%s\n",st);
    }
    num += n;
    fclose(fp);
    save();
    saveuu();
    system("PAUSE");
	system("cls");
}
void beifen(void)
{
    FILE *fp;
    if((fp = fopen("删除.txt", "r")) == NULL){
        printf("数据库加载失败，请重启本系统！\n");
        return ;
    }
    fscanf(fp, "%d",&num);
    fclose(fp);
}
void shan(void)
{
    FILE *fp;
    if((fp = fopen("删除.txt", "w")) == NULL){
        printf("数据库加载失败，请重启本系统！\n");
        return ;
    }
    fprintf(fp, "%d\n", num);
    fclose(fp);
}
//删除所有信息
void DeleteAll()
{
    FILE *fp;
    if((fp = fopen("缓存区.txt", "w")) == NULL){
        printf("数据库加载失败，请重启本系统！\n");
        return ;
    }
    fprintf(fp, "0");
    printf("\t\t\t删除成功，若想恢复请恢复备份！！\n\t\t\t");
    fclose(fp);
    num = 0;
    saveuu();
    system("PAUSE");
    system("cls");
}
void DeleteRecord()//删除一条信息
{
    int j,i,flag = 0;
    printf("\t\t\t   请输入书号\n\t\t\t    ");
    oo = scanf("%d",&j);
    if(!oo){
        inwrong();
        return ;
    }
    if(j == num){
    	num--;
    	save();
    	printf("\t\t\t   删除成功！\n\t\t\t   ");
    	system("PAUSE");
    	system("cls");
    	return ;
	}
    for(i = 0 ; i < num-1; i++){
        if(stu[i].ID == j)
            flag = 1;
        if(flag){
            strcpy(stu[i].name, stu[i+1].name);
            stu[i].price = stu[i+1].price;
            strcpy(stu[i].name, stu[i+1].name);
            stu[i].quan = stu[i+1].quan;
            strcpy(stu[i].itd, stu[i+1].itd);
        }
    }
	num--;
	save();
	saveuu();
	printf("\t\t\t删除成功！\n");
	system("PAUSE");
	system("cls");
}
//修改
void edit()
{
    system("cls");
    load();
    int i,sele;
    while(1){
        PrinEdit();
        oo = scanf("%d",&sele);
        if(!oo){
        	inwrong();
        	continue;
    	}
        switch(sele){
            case 1:
                add(); break;
            case 2:
                DeleteRecord(); break;
            case 3:
                DeleteAll(); break;
            case 4:
                system("cls"); return ;
            default :
            	system("cls"); hhk(); break;
        }
    }
}
 
//输出查找菜单
void FindEdit()
{
    printf("\t   ************************************************************\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      您可以进行以下操作:                                 *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      按书号查找 请按 1                                   *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      按书名查找 请按 2                                   *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      按作者查找 请按 3                                   *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      输出所有图书信息 请按 4                             *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      返回上一级菜单 请按 5                               *\n");
    printf("\t   *                                                          *\n");
    printf("\t   ************************************************************\n\n");
}
//按书号查找
void FindByNum(void)
{
    system("cls");
    if(num == 0){
        printf("\n\n\t\t\t数据库中暂没有图书信息，请添加图书信息\n\n\t\t\t   ");
        system("PAUSE");
        return ;
    }
    int i,sex;
    printf("\t\t\t   请输入要查找的书号：\n\n\t\t\t\t");
    oo = scanf("%d",&sex);
    if(!oo){
        inwrong();
        return ;
    }
    if(sex > num){
        printf("\t\t\t\t未找到该书！！\n\n\t\t\t   ");
        system("PAUSE");
        return ;
    }
    for(i = 0; i < num; i++){
        if(stu[i].ID == sex){
            PrintRecord(i);
            printf("\t\t\t   ");
            system("PAUSE");
            return;
        }
    }
}
//按书名查找
void FindByName()
{
    system("cls");
    if(num == 0){
        printf("\n\n\t\t\t数据库中暂没有图书信息，请添加图书信息\n\n\t\t\t   ");
        system("PAUSE");
        return ;
    }
    int i;
    char s[30];
    printf("\t\t\t   请输入要查找的书名：\n\n\t\t\t    ");
    scanf("%s",s);
    for(i = 0; i < num; i++){
        if(strcmp(stu[i].name, s) == 0){
            if(F == 1)
                PrintRecord(i);
            else if(!F){
                if(stu[i].quan == 0 && huan == 1)
                    F = 99998;
                else if(stu[i].quan != 0 || huan == 0){
                    PrintRecord(i);
                    F = i;
                }
            }
            printf("\t\t\t   ");
            system("PAUSE");
            return ;
        }
    }
    F = 99999;
    printf("\n\t\t\t   未找到该书！！\n");
    printf("\n\t\t\t   ");
    system("PAUSE");
}
//按作者查找
void FindByAuthor()
{
    system("cls");
    if(num == 0){
        printf("\n\n\t\t\t数据库中暂没有图书信息，请添加图书信息\n\n\t\t\t   ");
        system("PAUSE");
        return ;
    }
    int i;
    char s[30];
    printf("\t\t\t  请输入要查找的作者\n\n\t\t\t   ");
    scanf("%s",s);
    for(i = 0; i < num; i++){
        if(strcmp(stu[i].author, s) == 0){
            PrintRecord(i);
            printf("\t\t\t   ");
            system("PAUSE");
            return ;
        }
    }
    printf("\n\t\t\t\t未找到有关该作者的书！！\n\n\t\t\t   ");
    system("PAUSE");
}
//输出所有图书信息
void output()
{
    int i;
    if(num == 0){
        printf("\n\n\t\t\t数据库中暂没有图书信息，请添加图书信息\n\n\t\t\t   ");
        system("PAUSE");
        system("cls");
        return ;
    }
    for(i = 0; i < num; i++){
        PrintRecord(i);
    }
    printf("\t\t\t   ");
    system("PAUSE");
}
//查找
void Find()
{
    system("cls");
    int i,sclele;
    F = 1;
    while(1){
        FindEdit();
        oo = scanf("%d",&sclele);
        if(!oo){
        	inwrong();
        	continue;
    	}
        switch(sclele){
            case 1:
                FindByNum(); break;
            case 2:
                FindByName(); break;
            case 3:
                FindByAuthor(); break;
            case 4:
                output(); break;
            case 5:
                system("cls"); return ;
            default :
            	system("cls"); hhk(); break;
        }
        system("cls");
    }
}
 
//排序
void Sort()
{
    system("cls");
    int sexh;
    while(1){
        system("cls");
        PrintSort();
        oo = scanf("%d",&sexh);
        if(!oo){
        	inwrong();
        	continue;
    	}
        switch(sexh){
            case 1:
                SortByScore(); break;
            case 2:
                AscendVyPick(); break;
            case 3:
                DesendByPick(); break;
            case 4:
                 system("cls"); return ;
            default :
            	system("cls"); hhk(); break;
        }
    }
}
//输出排序菜单
void PrintSort()
{
    printf("\t   ************************************************************\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      您可以进行以下操作:                                 *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      按书名首字母排序 请按 1                             *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      按单价升序排序 请按 2                               *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      按单价降序排序 请按 3                               *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      返回上一级菜单 请按 4                               *\n");
    printf("\t   *                                                          *\n");
    printf("\t   ************************************************************\n\n");
}
//按书名首字母排序判断
int cmp1(library a, library b)
{
    if(strcmp(a.name, b.name) == -1)
        return 1;
    else
        return 0;
}
//按单价升序排序判断
int cmp2(library a, library b)
{
    return a.price < b.price;
}
//按单价降序排序判断
int cmp3(library a, library b)
{
    return a.price > b.price;
}
//重新整理书号
void IdArrange()
{
    int i;
    for(i = 0; i < num; i++)
        stu[i].ID = i+1;
}
//按书名首字母排序
void SortByScore()
{
    int i;
    sort(stu, stu+num, cmp1);
    IdArrange();
    save();
    printf("\n\t\t\t\t排序完成！！\n\n\t\t\t   ");
    system("PAUSE");
}
//按单价升序排序
void AscendVyPick()
{
    int i;
    sort(stu, stu+num, cmp2);
    IdArrange();
    save();
    printf("\n\t\t\t\t排序完成！！\n\n\t\t\t   ");
    system("PAUSE");
}
//按单价降序排序
void DesendByPick()
{
    int i;
    sort(stu, stu+num, cmp3);
    IdArrange();
    save();
    printf("\n\t\t\t\t排序完成！！\n\n\t\t\t   ");
    system("PAUSE");
}
 
//打印借书菜单
void PrintBorrow(void)
{
    printf("\t   ************************************************************\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      您可以进行以下操作:                                 *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      借书记录查询 请按 1                                 *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      图书借阅 请按 2                                     *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      图书归还 请按 3                                     *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      返回上一级菜单 请按 4                               *\n");
    printf("\t   *                                                          *\n");
    printf("\t   ************************************************************\n\n");
}
//将用户借书记录加载到磁盘
void saveBorrow(L head)
{
    int i;
    L p = head->Next;
	FILE *fp;
	fp = fopen("借书记录.txt", "w");
	while(p){
        fprintf(fp, "%s\n", p->users);
        fprintf(fp, "%d\n", p->sexes);
        for(i = 0; i < p->sexes; i++){
            fprintf(fp, "%s\n", p->book[i].Name);
            fprintf(fp, "%s\n", p->book[i].time);
        }
        fprintf(fp, "%d\n", p->r);
        p = p->Next;
	}
	fclose(fp);
}
//将借书记录加载到内存
void loadBorrow(L head)
{
	int i,j;
	L p, rear = head;
	freopen("借书记录.txt", "r", stdin);
	for(i = 0; i < k; i++){
		p = new node;
		scanf("%s",p->users);
		scanf("%d",&p->sexes);
		for(j = 0; j < p->sexes; j++){
			scanf("%s",p->book[j].Name);
			scanf("%s",p->book[j].time);
		}
		scanf("%d\n",&p->r);
		rear->Next = p;
		rear = p;
	}
	rear->Next = NULL;
	freopen("CON", "r", stdin);
	if(hnj != NULL){
		rear->Next = kl;
        rear = kl;
	}
	rear->Next = NULL;
	saveBorrow(head);
}
//用户搜索
L LookUser(L head)
{
    L p = head;
    while(p){
        p = p->Next;
        if(strcmp(p->users, strr) == 0)
            break;
    }
    return p;
}
//借书记录
void BorrowRecord(L q)
{
	int i;
	system("cls");
	printf("\t\t借书的数量：%d\n\n",q->sexes);
	for(i = 0; i < q->sexes; i++){
		printf("\t\t%d.%s\n",i+1, q->book[i].Name);
		printf("\t\t  借书时间：%s\n\n",q->book[i].time);
	}
	printf("\t\t信誉值：%d\n\n",q->r);
	printf("\t\t\t   ");
	system("PAUSE");
	system("cls");
}
 
//借书
void BorrowBook(L q, L y)
{
    int o,i;
    char str[30];
    huan = 1;
    system("cls");
    if(q->r < 60){
        printf("\n\n");
        printf("\t\t\t信誉值低于60，不能进行借书操作！！\n\n\t\t\t   ");
        system("PAUSE");
        system("cls");
        return ;
    }
    F = 0;
    FindByName();
    if(F == 99998){
        printf("\n");
        printf("\t\t\tSORRY，该书已没有库存！！\n\n\t\t\t   ");
        system("PAUSE");
        system("cls");
        F = 1;
        return ;
    }
    else if(F == 99999){
        system("cls");
        return ;
    }
    strcpy(q->book[q->sexes].Name, stu[F].name);
    stu[F].quan--;
    printf("\n\t\t请输入借书时间（格式为year/month/day）：\n\n\t\t\t ");
    scanf("%s",str);
    strcpy(q->book[q->sexes].time, str);
    q->sexes++;
    F = 1;
    save();
    saveBorrow(y);
    printf("\n\t\t\t\t借书成功！！\n\n\t\t\t   ");
    system("PAUSE");
    system("cls");
}
//还书
void SendBook(L q, L y)
{
    system("cls");
    int i,kk=0,flag = 1;
    char st[30];
    F = huan = 0;
    if(q->sexes == 0){
        printf("\n\t\t\t  您还没有借书哦！！\n\n\t\t\t   ");
        system("PAUSE");
        system("cls");
        return ;
    }
    FindByName();
    if(F == 99999){
        system("cls");
        return ;
    }
    for(i = 0; i < q->sexes; i++)
        if(strcmp(q->book[i].Name, stu[F].name) == 0)
            flag = 0;
    if(flag){
        system("cls");
        printf("\n\t\t\t  您还没有借该书哦！！\n\n\t\t\t   ");
        system("PAUSE");
        system("cls");
        return ;
    }
    for(i = 0; i < q->sexes; i++){
        if(strcmp(q->book[i].Name, stu[F].name) == 0 && kk == 0){
        	strcpy(st, q->book[i].time);
            if(i == q->sexes-1)
                break;
            kk = 1;
        }
        if(kk){
            strcpy(q->book[i].Name, q->book[i+1].Name);
            strcpy(q->book[i].time, q->book[i+1].time);
        }
    }
    q->sexes--;
    stu[F].quan++;
    save();
    for(i = 1; i <= 16; i++)
    	printf(" ");
    printf("\t\t\t借书时间：%s\n\n",st);
    printf("\t\t   请管理员判断是否逾期还书或图书有破损\n\n\t\t\t     ");
    system("PAUSE");
    printf("\n\t\t   按时还书 请按 1\n\n");
    printf("\t\t   逾期还书但不超过一个工作日 请按 2\n\n");
    printf("\t\t   还书时间超过一个工作日 请按 3\n\n");
    printf("\t\t   图书有破损 请按 4\n\n\t\t    ");
    scanf("%d",&kk);
	if(kk == 1)
        printf("\n\t\t\t\t感谢您的使用！！\n\n");
	else if(kk == 2){
		q->r -= 5;
		if(q->r < 60)
			printf("由于您的不良行为较多，信誉值已不足60，本年度将不能在本系统借书！！\n\n");
		else
			printf("请保持良好的借书行为，信誉不足将无法在本系统借书！！\n\n");
	}
	else if(kk == 3){
		q->r = 0;
		printf("由于您的还书时间超过规定时间一个工作日，所以本年度将不能在本系统借书！！\n\n");
	}
	else if(kk == 4){
		q->r -= 10;
		printf("\t\t\t由于图书有破损，请原价赔偿！！\n\n");
		for(i = 0; i < num; i++)
		    if(strcmp(stu[i].name, stu[F].name) == 0){
		    	printf("\t\t\t\t原价：%.2lf\n\n",stu[i].price);
		    	break;
			}
        if(q->r < 60)
			printf("由于您的不良行为较多，信誉值已不足60，本年度将不能在本系统借书！！\n\n");
		else
			printf("请保持良好的借书行为，信誉不足将无法在本系统借书！！\n\n");
	}
	saveBorrow(y);
	printf("\t\t\t   ");
    system("PAUSE");
	system("cls");
}
//图书借还系统
void Borrow(void)
{
	system("cls");
	int shl,i;
	L head = new node;
	loadBorrow(head);
	pre = LookUser(head);
	while(1){
		PrintBorrow();
		oo = scanf("%d", &shl);
		if(!oo){
        	inwrong();
        	continue;
    	}
		switch(shl){
			case 1:
				BorrowRecord(pre); break;
			case 2:
				BorrowBook(pre, head); break;
			case 3:
				SendBook(pre, head); break;
			case 4:
				system("cls"); return ;
			default :
				system("cls"); hhk(); break;
		}
	}
}

