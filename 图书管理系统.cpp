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
 
void display(void);//��ʾͼ����Ϣ����˵�*
void load(void);//��ͼ����Ϣ���ص��ڴ�*
void save(void);//�����ݱ��浽����*
void Sort(void);//����*
void SortByScore(void);//����������ĸ����*
void AscendVyPick(void);//��������������*
void DesendByPick(void);//�����۽�������*
int cmp1(library a, library b);//����������ĸ�����ж�*
int cmp2(library a, library b);//���������������ж�*
int cmp3(library a, library b);//�����۽��������ж�*
void IdArrange(void);//�����������*
void Find(void);//����*
void add(void);//���*
void edit(void);//�޸�*
void DeleteAll(void);//ɾ��������Ϣ*
void PrintRecord(void);//���һ����¼*
void FindByName(void);//����������*
void FindByNum(void);//����Ų���*
void FindByAuthor(void);//�����߲���*
void output(void);//�������ͼ����Ϣ*
void over(void);//��������*
void Huifu(void);//�ָ���������*
void PrinEdit(void);//����޸Ĳ˵�*
void FindEdit(void);//������Ҳ˵�*
void PrintSort(void);//�������˵�*
void CheckUser(void);//�����˺ŵĺϷ���*
void addUser(void);//�½��˺�*
void findPassword(void);//�һ�����*
void EditPassword(void);//�޸�����*
void loadUser(void);//���˺Ŷ����ڴ�*
void saveUser(void);//���˺Ŵ������*
void printuser(void);//����˺Ų˵�*
int ling(void);//�˺ŵ�¼*
void PrintBorrow(void);//��ӡ�������ϵͳ�˵�*
void Menu(void);//ͼ����Ϣ����*
void Borrow(void);//ͼ��軹ϵͳ*
void BorrowRecord(L q);//�����¼*
void BorrowBook(L q, L y);//����*
void SendBook(L q, L y);//����*
L LookUser(L head);//�û�����*
void loadBorrow(L head);//�������¼���ص��ڴ�*
void saveBorrow(L head);//���û������¼���ص�����*
void FuactionIntrod(void);//ϵͳ���ܽ���*
void Intropeople(void);//������Ա����*
void Mainmenu(void);//��ӡ���˵�*
void hhk(void);//��ӡ�������� *
void loaduu(void);//���������ص��ڴ�*
void saveuu(void);//���������ص�����*
void Cpy(void);//����ͼ����Ϣ*
void HideCursor(void);//���ع��*
void inwrong(void);//�ж������Ƿ���ȷ*
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
 
//�ж������Ƿ���ȷ
void inwrong(void)
{
	char s[50];
	gets(s);
    system("cls");
    printf("\t\t\t������󣡣�\n");
    system("PAUSE");system("cls");
}
//���ع��
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
//���������ص��ڴ�
void loaduu(void)
{
    FILE *fp;
    fp = fopen("���ݸ���.txt", "r");
    fscanf(fp, "%d", &num);
    fscanf(fp, "%d", &jj);
    fclose(fp);
    k = jj;
}
//���������ص�����
void saveuu(void)
{
    FILE *fp;
    fp = fopen("���ݸ���.txt", "w");
    fprintf(fp, "%d\n", num);
    fprintf(fp, "%d\n", jj);
    fclose(fp);
}
//����ͼ����Ϣ
void Cpy(void)
{
    FILE *fp;
    int i;
    shan();
    fp = fopen("ͼ����Ϣ��.txt", "w");
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
    printf("\n\n\t\t\t���ݳɹ�����\n");
    system("PAUSE");
    system("cls");
}
//��ӡ���˵�
void Mainmenu(void)
{
    printf("\t   ************************************************************\n");
    if(LLL){
    printf("\t   *                ��ӭʹ��ͼ�����ϵͳ                      *\n");
    LLL = 0;
    }
    else{
    printf("\t   *                                                          *\n");
    printf("\t   *      �����Խ������²���:                                 *\n");
    }
    printf("\t   *                                                          *\n");
    printf("\t   *      ͼ����Ϣ���� �밴 1                                 *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      ͼ��軹���� �밴 2                                 *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      ϵͳ���ܽ��� �밴 3                                 *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      ������Ա���� �밴 4                                 *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      �л��˺� �밴 5                                     *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      �˳�ϵͳ �밴 6                                     *\n");
    printf("\t   *                                                          *\n");
    printf("\t   ************************************************************\n\n");
}
//ϵͳ���ܽ���
void FuactionIntrod(void)
{
	system("cls");
	printf("��ϵͳ��ִ�����²���:\n\n");
	printf("һ����¼���湦�ܽ���\n\n");
	printf("1.��¼�˺�\n\n2.ע�����˺�\n\n3.�����һ�\n\n4.�޸�����\n\n\t\t\t   ");
	system("PAUSE");
	system("cls");
    printf("����ͼ����Ϣ����ϵͳ���ܽ���\n\n");
    printf("1. ���ҹ���\n\n");
    printf("1������Ų���\n2������������\n3�������߲���\n4���������ͼ����Ϣ\n\n");
    printf("2. ������\n\n");
    printf("1������������ĸ����\n2����������������\n3�������۽�������\n\n");
    printf("3. �޸Ĺ���\n\n");
    printf("1�����\n\n  ��������Ȿ��\n\n2��ɾ��һ��ͼ��\n3��ɾ��ȫ��ͼ��\n\n");
    printf("4. �ָ�ͼ����Ϣ\n\n  �����ɾ��ͼ����Ϣ���ɻָ���һ�α��ݵ�ͼ����Ϣ\n\n");
    printf("5.����ͼ����Ϣ\n\n\t\t\t   ");
    system("PAUSE");
	system("cls");
    printf("����ͼ��軹ϵͳ���ܽ���\n\n");
    printf("1.����ͼ�鹦��\n\n");
    printf("�˹��ܿ�ʹ�û����ı�ϵͳ���ִ��ͼ��\n\n");
	printf("2.���鹦��\n\n");
	printf("�˹��ܿɷ����û�����\n\n");
    printf("3. �û����黹���¼��ѯ����\n\n");
    printf("�˹��ܿɲ�ѯ���˽���ͻ����¼\n\n");
    printf("4. �û����黹��������ѯ����\n\n");
    printf("�˹��ܿɲ�ѯ�����ߵĸ�������ֵ��������ֵ����60��������ͨ����ϵͳ���飬ͬʱ��ÿһ����ĩ���������ֵ����ͳ�ƣ�\n");
    printf("���������û�����ֵ�ָ�Ϊ100��\n\n");
    printf("����ֵ�۳���׼��\n\n");
    printf("1����������������������ڹ黹�����ڻ���  ÿ�ο۳�����ֵ 5��\n");
    printf("2����ͼ������𻵻�ʧ��  ÿ�ο۳�����ֵ 10 �� ��ԭ���⳥��\n");
    printf("3����������ʱ��һ�������յģ�����ֵ����ֱ�����㣬�������ڱ�ϵͳ�����κβ�����\n\n");
    printf("�ġ��л��˺Ź���\n\n �����л��˺�\n\n\t\t\t   ");
    system("PAUSE");
    system("cls");
}
 
//�����˺ŵĺϷ���
void CheckUser(void)
{
    int i,flag = 0,K,KK;
    char ss[30],sf[10];
    printf("\t\t\t\t�������¼�˺ţ�\n\n\t\t\t\t ");
    scanf("%s",ss);
    for(i = 0; i < jj; i++){
        if(strcmp(sta[i].AcName, ss) == 0){
            strcpy(strr, ss);
            flag = 1;
            break;
        }
    }
    if(!flag){
        printf("\n\t\t\t\t���˺Ż�δע�ᣡ��\n\n\t\t\t   ");
        system("PAUSE");
        system("cls");
        return;
    }
    printf("\t\t\t\t���������룺\n\n\t\t\t\t ");
    scanf("%s",sf);
    if(strcmp(sta[i].password, sf) == 0){
        h = 0;
        flag = 2;
    }
    if(flag == 1){
        system("cls");
        printf("\t\t\t\t������󣡣�\n\n\t\t\t   ");
        system("PAUSE");
        system("cls");
        h++;
        return ;
    }
    else if(flag == 2){
    	printf("\t\t\t   �������������֤�룺\n");
        srand((unsigned)time(NULL));
        K = rand();
        printf("\n\t\t\t\t  %d\n\t\t\t\t  ",K);
        oo = scanf("%d",&KK);
        if(!oo){
            inwrong();
            return ;
        }
        if(KK != K){
            printf("\n\t\t\t��֤����󣡣�\n");
            system("PAUSE");
            system("cls");
            return ;
        }
		logo = 1;
	}   
}
//���˺Ŵ������
void saveUser(void)
{
    int i;
    FILE *fp;
    fp = fopen("�˺�.txt", "w");
    for(i = 0; i <= jj; i++){
        fprintf(fp, "%s\n", sta[i].AcName);
        fprintf(fp, "%s\n", sta[i].password);
        fprintf(fp, "%s\n", sta[i].nickname);
    }
    fclose(fp);
}
//�½��˺�
void addUser(void)
{
    FILE *fp;
    int j=0,i;
    char c[12],str[30];
    printf("\t\t\t�������˺ţ�\n\n\t\t\t  ");
    scanf("%s",str);
    for(i = 0; i < jj; i++){
        if(strcmp(sta[i].AcName, str) == 0){
            printf("\t\t\t���˺��ѱ�ע�ᣬ���������룡��\n\n\t\t\t   ");
            system("PAUSE");
            return ;
        }
    }
    strcpy(sta[jj].AcName, str);
    printf("\t\t\t���������루���볤�Ȳ�����ʮ���ַ�����\n\n\t\t\t  ");
    scanf("%s", sta[jj].password);
    printf("\t\t\t��������һ�����룺\n\n\t\t\t  ");
    scanf("%s",c);
    if(strcmp(sta[jj].password, c) != 0){
        printf("\t\t\t�������벻һ�����������\n\n\t\t\t");
        system("PAUSE");
        system("cls");
        printf("\n");
        addUser();
		j = 1;
    }
    if(j)
        return ;
    printf("\n\t\t\t�������ǳ�\n\n\t\t\t  ");
    scanf("%s",sta[jj].nickname);
    saveUser();
    printf("\t\t\t\t�˺�����ɹ�����\n\n\t\t\t");
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
//�һ�����
void findPassword(void)
{
    int i;
    char a[30];
    printf("\t\t\t������Ҫ�һص��˺ţ�\n\t\t\t\t");
    scanf("%s",a);
    for(i = 0; i < jj; i++)
        if(strcmp(sta[i].AcName, a) == 0){
            printf("\t\t\t���룺%s\n",sta[i].password);
            system("PAUSE");
            return ;
        }
    printf("\t\t\t\t���޴��˺ţ���\n\n\t\t\t");
    system("PAUSE");
}
//�޸�����
void EditPassword(void)
{
    int i,K=0,KK=0;
    char a[30];
    printf("\t\t\t  ������Ҫ�޸�������˺ţ�\n\t\t\t  ");
    scanf("%s",a);
    for(i = 0; i < jj; i++)
        if(strcmp(sta[i].AcName, a) == 0){
            printf("\n\t\t\t   ������ԭ���룺\n\t\t\t   ");
            scanf("%s",a);
            if(strcmp(sta[i].password, a) != 0){
                printf("\n\t\t\t\t������󣡣�\n\n\t\t\t   ");
                system("PAUSE");
                system("cls");
                return ;
            }
            printf("\n\t\t\t   �����������룺\n\t\t\t   ");
            scanf("%s",a);
            if(strcmp(sta[i].password, a) == 0){
                printf("\n\t\t\t��������ԭ�����ظ���������޸ģ���\n\n\t\t\t   ");
                system("PAUSE");
                system("cls");
                return ;
            }
            strcpy(sta[i].password, a);
            printf("\t\t\t   �������������֤�룺\n");
            srand((unsigned)time(NULL));
            K = rand();
            printf("\n\t\t\t\t  %d\n\t\t\t\t  ",K);
            oo = scanf("%d",&KK);
            if(!oo){
            	inwrong();
            	return ;
        	}
            if(KK != K){
                printf("\n\t\t\t��֤����󣡣�\n");
                system("PAUSE");
                system("cls");
                return ;
            }
            printf("\n\t\t\t\t�޸�����ɹ�����\n");
            saveUser();
            system("PAUSE");
            system("cls");
            return ;
        }
    printf("\n\t\t\t\t���޴��˺ţ���\n\n\t\t\t");
    system("PAUSE");
 
}
//���˺Ŷ����ڴ�
void loadUser(void)
{
    int i;
    freopen("�˺�.txt", "r", stdin);
    for(i = 0; i < jj; i++){
        scanf("%s",sta[i].AcName);
        scanf("%s",sta[i].password);
        scanf("%s",sta[i].nickname);
    }
    freopen("CON", "r", stdin);
}
//����˺Ų˵�
void printuser(void)
{
    printf("\t\t\t************************************\n");
    printf("\t\t\t*    ��¼ �밴 1                   *\n");
    printf("\t\t\t*    ע�����˺� �밴 2             *\n");
    printf("\t\t\t*    �һ����� �밴 3               *\n");
    printf("\t\t\t*    �޸����� �밴 4               *\n");
    printf("\t\t\t*    �˳����� �밴 5               *\n");
    printf("\t\t\t************************************\n");
}
//�˺ŵ�¼
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
                printf("\t\t\t��ӭ�´�ʹ�ñ�ͼ�����ϵͳ\n"); return 0;
            default :
            	system("cls"); hhk();system("cls"); break;
        }
        if(logo)
            return 1;
        if(h == 3){
            printf("\t\t\t����������Σ�ϵͳ���Զ��رգ���\n\n");
            printf("\t\t\t��ӭ�´�ʹ�ñ���ͼ�����ϵͳ\n");
            return 0;
        }
    }
}
 
//�ָ���������
void Huifu(void)
{
    beifen();
    saveuu();
    int i = num;
    freopen("ͼ����Ϣ��.txt", "r",stdin);
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
    printf("\n\n\t\t\t�ָ��ɹ�����\n");
    system("PAUSE");
    system("cls");
}
void PrintRecord(int i)//���һ����¼
{
    printf("\t\t\t��ţ�%04d\n",stu[i].ID);
    printf("\t\t\t������%s\n",stu[i].name);
    printf("\t\t\t�۸�%.2lf\n",stu[i].price);
    printf("\t\t\t���ߣ�%s\n",stu[i].author);
    printf("\t\t\t��棺%d\n",stu[i].quan);
    printf("\n��飺%s\n\n",stu[i].itd);
}
 
//ͼ����Ϣ����
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
//��ʾͼ����Ϣ����˵�
void display(void)
{
    char str[3][20] = {"���� �밴 1","���� �밴 2","�޸� �밴 3"};
    int i,j;
    printf("\t   ************************************************************\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      �����Խ������²���:                                 *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      ���� �밴 1                                         *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      ���� �밴 2                                         *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      �޸� �밴 3                                         *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      �ָ�ͼ����Ϣ �밴 4                                 *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      ����ͼ����Ϣ �밴 5                                 *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      ������һ���˵� �밴 6                               *\n");
    printf("\t   *                                                          *\n");
    printf("\t   ************************************************************\n\n");
}
//��ӡ������Ա��Ϣ
void Intropeople(void)
{
    printf("\t   ************************************************************\n");
    printf("\t   *                                                          *\n");
    printf("\t   *                      ������Ա��Ϣ                        *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *         �������1903052�� 19030500122���鳿              *\n");
    printf("\t   *                                                          *\n"); 
    printf("\t   ************************************************************\n\n");
    system("PAUSE");
    system("cls");
}
 
void hhk(void)//��ӡ��������
{
	printf("\n");
	printf("\t\t\t  �������������ѡ�����ѡ���\n\n");
	system("PAUSE");
}
 
//��������
void over()
{
    printf("\n\t\t\t29��ͼ�����ϵͳף���Ķ���죡����\n");
}
 
//��ͼ����Ϣ���ص��ڴ�
void load()
{
    int i;
    freopen("������.txt", "r", stdin);
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
//�����ݱ��浽����
void save()
{
    int i;
    FILE *fp;
    fp = fopen("������.txt", "w");
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
 
//����޸Ĳ˵�
void PrinEdit()
{
    printf("\t   ************************************************************\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      �����Խ������²���:                                 *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      ��� �밴 1                                         *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      ɾ��һ��ͼ�� �밴 2                                 *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      ɾ��ȫ��ͼ�� �밴 3                                 *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      ������һ���˵� �밴 4                               *\n");
    printf("\t   *                                                          *\n");
    printf("\t   ************************************************************\n\n");
}
void add()//���
{
    FILE *fp;
    fp = fopen("������.txt","a");
    int n,p,i;
    double q;
    char str[30],st[1000];
    printf("\t\t\t   �ף�����������Ҫ��Ӽ���\n\n\t\t\t    ");
    oo = scanf("%d",&n);
    if(!oo){
        inwrong();
        return ;
    }
    for(i = num+1; i <= num+n; i++){
        fprintf(fp, "%d\n",i);
        stu[i-1].ID = i;
        printf("\t\t\t   ����������\n\n\t\t\t    ");
        scanf("%s",str);
        strcpy(stu[i-1].name, str);
        fprintf(fp, "%s\n",str);
        printf("\t\t\t   ������۸�\n\n\t\t\t    ");
        scanf("%lf",&q);
        stu[i-1].price = q;
        fprintf(fp, "%.2lf\n",q);
        printf("\t\t\t   ����������\n\n\t\t\t    ");
        scanf("%s",str);
        strcpy(stu[i-1].author, str);
        fprintf(fp, "%s\n",str);
        printf("\t\t\t   ��������������\n\n\t\t\t    ");
        scanf("%d",&p);
        stu[i-1].quan = p;
        fprintf(fp, "%d\n",p);
        printf("\t\t\t   ���������ļ��\n\n\t\t\t    ");
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
    if((fp = fopen("ɾ��.txt", "r")) == NULL){
        printf("���ݿ����ʧ�ܣ���������ϵͳ��\n");
        return ;
    }
    fscanf(fp, "%d",&num);
    fclose(fp);
}
void shan(void)
{
    FILE *fp;
    if((fp = fopen("ɾ��.txt", "w")) == NULL){
        printf("���ݿ����ʧ�ܣ���������ϵͳ��\n");
        return ;
    }
    fprintf(fp, "%d\n", num);
    fclose(fp);
}
//ɾ��������Ϣ
void DeleteAll()
{
    FILE *fp;
    if((fp = fopen("������.txt", "w")) == NULL){
        printf("���ݿ����ʧ�ܣ���������ϵͳ��\n");
        return ;
    }
    fprintf(fp, "0");
    printf("\t\t\tɾ���ɹ�������ָ���ָ����ݣ���\n\t\t\t");
    fclose(fp);
    num = 0;
    saveuu();
    system("PAUSE");
    system("cls");
}
void DeleteRecord()//ɾ��һ����Ϣ
{
    int j,i,flag = 0;
    printf("\t\t\t   ���������\n\t\t\t    ");
    oo = scanf("%d",&j);
    if(!oo){
        inwrong();
        return ;
    }
    if(j == num){
    	num--;
    	save();
    	printf("\t\t\t   ɾ���ɹ���\n\t\t\t   ");
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
	printf("\t\t\tɾ���ɹ���\n");
	system("PAUSE");
	system("cls");
}
//�޸�
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
 
//������Ҳ˵�
void FindEdit()
{
    printf("\t   ************************************************************\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      �����Խ������²���:                                 *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      ����Ų��� �밴 1                                   *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      ���������� �밴 2                                   *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      �����߲��� �밴 3                                   *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      �������ͼ����Ϣ �밴 4                             *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      ������һ���˵� �밴 5                               *\n");
    printf("\t   *                                                          *\n");
    printf("\t   ************************************************************\n\n");
}
//����Ų���
void FindByNum(void)
{
    system("cls");
    if(num == 0){
        printf("\n\n\t\t\t���ݿ�����û��ͼ����Ϣ�������ͼ����Ϣ\n\n\t\t\t   ");
        system("PAUSE");
        return ;
    }
    int i,sex;
    printf("\t\t\t   ������Ҫ���ҵ���ţ�\n\n\t\t\t\t");
    oo = scanf("%d",&sex);
    if(!oo){
        inwrong();
        return ;
    }
    if(sex > num){
        printf("\t\t\t\tδ�ҵ����飡��\n\n\t\t\t   ");
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
//����������
void FindByName()
{
    system("cls");
    if(num == 0){
        printf("\n\n\t\t\t���ݿ�����û��ͼ����Ϣ�������ͼ����Ϣ\n\n\t\t\t   ");
        system("PAUSE");
        return ;
    }
    int i;
    char s[30];
    printf("\t\t\t   ������Ҫ���ҵ�������\n\n\t\t\t    ");
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
    printf("\n\t\t\t   δ�ҵ����飡��\n");
    printf("\n\t\t\t   ");
    system("PAUSE");
}
//�����߲���
void FindByAuthor()
{
    system("cls");
    if(num == 0){
        printf("\n\n\t\t\t���ݿ�����û��ͼ����Ϣ�������ͼ����Ϣ\n\n\t\t\t   ");
        system("PAUSE");
        return ;
    }
    int i;
    char s[30];
    printf("\t\t\t  ������Ҫ���ҵ�����\n\n\t\t\t   ");
    scanf("%s",s);
    for(i = 0; i < num; i++){
        if(strcmp(stu[i].author, s) == 0){
            PrintRecord(i);
            printf("\t\t\t   ");
            system("PAUSE");
            return ;
        }
    }
    printf("\n\t\t\t\tδ�ҵ��йظ����ߵ��飡��\n\n\t\t\t   ");
    system("PAUSE");
}
//�������ͼ����Ϣ
void output()
{
    int i;
    if(num == 0){
        printf("\n\n\t\t\t���ݿ�����û��ͼ����Ϣ�������ͼ����Ϣ\n\n\t\t\t   ");
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
//����
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
 
//����
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
//�������˵�
void PrintSort()
{
    printf("\t   ************************************************************\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      �����Խ������²���:                                 *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      ����������ĸ���� �밴 1                             *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      �������������� �밴 2                               *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      �����۽������� �밴 3                               *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      ������һ���˵� �밴 4                               *\n");
    printf("\t   *                                                          *\n");
    printf("\t   ************************************************************\n\n");
}
//����������ĸ�����ж�
int cmp1(library a, library b)
{
    if(strcmp(a.name, b.name) == -1)
        return 1;
    else
        return 0;
}
//���������������ж�
int cmp2(library a, library b)
{
    return a.price < b.price;
}
//�����۽��������ж�
int cmp3(library a, library b)
{
    return a.price > b.price;
}
//�����������
void IdArrange()
{
    int i;
    for(i = 0; i < num; i++)
        stu[i].ID = i+1;
}
//����������ĸ����
void SortByScore()
{
    int i;
    sort(stu, stu+num, cmp1);
    IdArrange();
    save();
    printf("\n\t\t\t\t������ɣ���\n\n\t\t\t   ");
    system("PAUSE");
}
//��������������
void AscendVyPick()
{
    int i;
    sort(stu, stu+num, cmp2);
    IdArrange();
    save();
    printf("\n\t\t\t\t������ɣ���\n\n\t\t\t   ");
    system("PAUSE");
}
//�����۽�������
void DesendByPick()
{
    int i;
    sort(stu, stu+num, cmp3);
    IdArrange();
    save();
    printf("\n\t\t\t\t������ɣ���\n\n\t\t\t   ");
    system("PAUSE");
}
 
//��ӡ����˵�
void PrintBorrow(void)
{
    printf("\t   ************************************************************\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      �����Խ������²���:                                 *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      �����¼��ѯ �밴 1                                 *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      ͼ����� �밴 2                                     *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      ͼ��黹 �밴 3                                     *\n");
    printf("\t   *                                                          *\n");
    printf("\t   *      ������һ���˵� �밴 4                               *\n");
    printf("\t   *                                                          *\n");
    printf("\t   ************************************************************\n\n");
}
//���û������¼���ص�����
void saveBorrow(L head)
{
    int i;
    L p = head->Next;
	FILE *fp;
	fp = fopen("�����¼.txt", "w");
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
//�������¼���ص��ڴ�
void loadBorrow(L head)
{
	int i,j;
	L p, rear = head;
	freopen("�����¼.txt", "r", stdin);
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
//�û�����
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
//�����¼
void BorrowRecord(L q)
{
	int i;
	system("cls");
	printf("\t\t�����������%d\n\n",q->sexes);
	for(i = 0; i < q->sexes; i++){
		printf("\t\t%d.%s\n",i+1, q->book[i].Name);
		printf("\t\t  ����ʱ�䣺%s\n\n",q->book[i].time);
	}
	printf("\t\t����ֵ��%d\n\n",q->r);
	printf("\t\t\t   ");
	system("PAUSE");
	system("cls");
}
 
//����
void BorrowBook(L q, L y)
{
    int o,i;
    char str[30];
    huan = 1;
    system("cls");
    if(q->r < 60){
        printf("\n\n");
        printf("\t\t\t����ֵ����60�����ܽ��н����������\n\n\t\t\t   ");
        system("PAUSE");
        system("cls");
        return ;
    }
    F = 0;
    FindByName();
    if(F == 99998){
        printf("\n");
        printf("\t\t\tSORRY��������û�п�棡��\n\n\t\t\t   ");
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
    printf("\n\t\t���������ʱ�䣨��ʽΪyear/month/day����\n\n\t\t\t ");
    scanf("%s",str);
    strcpy(q->book[q->sexes].time, str);
    q->sexes++;
    F = 1;
    save();
    saveBorrow(y);
    printf("\n\t\t\t\t����ɹ�����\n\n\t\t\t   ");
    system("PAUSE");
    system("cls");
}
//����
void SendBook(L q, L y)
{
    system("cls");
    int i,kk=0,flag = 1;
    char st[30];
    F = huan = 0;
    if(q->sexes == 0){
        printf("\n\t\t\t  ����û�н���Ŷ����\n\n\t\t\t   ");
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
        printf("\n\t\t\t  ����û�н����Ŷ����\n\n\t\t\t   ");
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
    printf("\t\t\t����ʱ�䣺%s\n\n",st);
    printf("\t\t   �����Ա�ж��Ƿ����ڻ����ͼ��������\n\n\t\t\t     ");
    system("PAUSE");
    printf("\n\t\t   ��ʱ���� �밴 1\n\n");
    printf("\t\t   ���ڻ��鵫������һ�������� �밴 2\n\n");
    printf("\t\t   ����ʱ�䳬��һ�������� �밴 3\n\n");
    printf("\t\t   ͼ�������� �밴 4\n\n\t\t    ");
    scanf("%d",&kk);
	if(kk == 1)
        printf("\n\t\t\t\t��л����ʹ�ã���\n\n");
	else if(kk == 2){
		q->r -= 5;
		if(q->r < 60)
			printf("�������Ĳ�����Ϊ�϶࣬����ֵ�Ѳ���60������Ƚ������ڱ�ϵͳ���飡��\n\n");
		else
			printf("�뱣�����õĽ�����Ϊ���������㽫�޷��ڱ�ϵͳ���飡��\n\n");
	}
	else if(kk == 3){
		q->r = 0;
		printf("�������Ļ���ʱ�䳬���涨ʱ��һ�������գ����Ա���Ƚ������ڱ�ϵͳ���飡��\n\n");
	}
	else if(kk == 4){
		q->r -= 10;
		printf("\t\t\t����ͼ����������ԭ���⳥����\n\n");
		for(i = 0; i < num; i++)
		    if(strcmp(stu[i].name, stu[F].name) == 0){
		    	printf("\t\t\t\tԭ�ۣ�%.2lf\n\n",stu[i].price);
		    	break;
			}
        if(q->r < 60)
			printf("�������Ĳ�����Ϊ�϶࣬����ֵ�Ѳ���60������Ƚ������ڱ�ϵͳ���飡��\n\n");
		else
			printf("�뱣�����õĽ�����Ϊ���������㽫�޷��ڱ�ϵͳ���飡��\n\n");
	}
	saveBorrow(y);
	printf("\t\t\t   ");
    system("PAUSE");
	system("cls");
}
//ͼ��軹ϵͳ
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

