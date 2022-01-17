#include <cstdio>
#include <cstdlib>
#include <cstring>

char adminusername[10]="admin";
char adminpasswd[15]="123456";
const int namelim = 90;
const int comps = 53;

struct vip{
    char name[namelim];//vip1[4].name   p=vip1  p[4]->name
    int cash;
};

struct book{
    char name[namelim];
    int price;
};

int vip_mng(struct vip vip1[]);
int vip_change(struct vip vip1[],int chg);
int book_mng(struct book book1[]);
int market(struct book book1[],struct vip vip1[]);
int vip_screen(struct vip vip1[]);
int vip_add(struct vip vip1[] );

int bk_screen(struct book book1[]);
int bk_add(struct book book1[]);
int bk_del(struct book book1[],int chg);

int n =8,nbook=8;
int minus=0,minm=0;

int main()
{
    char passwd[15],username[10];
    int step=0;
    struct vip vip1[comps]={{"����",100},{"����",600},{"����",500},{"½��",1000},{"Ǯ��",900},{"��ǿ",100},{"С��",100},{"����",100}};
	struct book book1[comps]={{"C#2.0����", 88}, {"Java��̻���", 55}, { "J2SE����Ӧ�ó��򿪷�", 60}, { "���ݿ���ƺ�Ӧ��", 45}, {"ˮ䰴�", 55}, {"��¥��", 68}, {"��������", 78}, {"�����μ�", 29}};
	
	
	
    PASSWDERROR:printf("�����û���:\n");
    scanf("%s",username);
    if(strcmp(username,adminusername)!=0)
        {printf("�û�������������");
            goto PASSWDERROR;}
    for(int i=0;i<3;++i)
    {

        printf("��������:\n");
        scanf("%s",passwd);
        if(strcmp(username,adminusername)==0&&strcmp(passwd,adminpasswd)==0)goto INIT;
        else
        {
            if(step==2)goto ERROR;
            printf("������������㻹��%d�λ���\n",2-i);
            step++;
            continue;
        }
    }
    ERROR:printf("�����������������������\n");
    goto PASSWDERROR;
    return 114514;
	
	 INIT:int brunch;
   
    system("cls");
    


	printf("******************************\n*      ͼ�����۹���ϵͳ      *\n*         1.��Ա����         *\n*         2.�鼮����         *\n*         3.�������         *\n*         4.ע��             *\n******************************\n");
    scanf("%d",&brunch);
    if(brunch==1)
    {
        vip_mng(vip1);
        goto INIT;
    }else if(brunch==2)
    {
        book_mng(book1);
        goto INIT;
    }else if(brunch==3)
    {
       market(book1,vip1);
       vip1[minm].cash-=minus;
       
       goto INIT;
    }else if(brunch==4)
    {
        printf("����ע�� ");
		/*for(int i=0;i<100000000;++i){
			if(i%1000000==1){}
			else if(i%1000000==0){printf("\b|");}
			else if(i%1000000==249900){printf("\b|");}
			else if(i%1000000==499900){printf("\b/");}
			else if(i%1000000==749900){printf("\b-");}
			else{}
		}*/
		exit(0);
		
    }
    return 0;
}

int vip_mng(struct vip vip1[])
{
    int quest;
    VIPSTART:system("cls");
    printf("******************************\n*  1.��ʾ���л�Ա        *\n*  2.��ӻ�Ա��Ϣ        *\n*  3.�޸Ļ�Ա��Ϣ        *\n*  4.�������˵�          *\n******************************\n��ѡ���������֣�\n");
    scanf("%d",&quest);
    if(quest==1){
        system("cls");
		vip_screen(vip1);
        printf("�����������ݻص���һ��");
			char q[900];
			scanf("%s",q);
        goto VIPSTART;

    }else if(quest==2){
        n++;
		vip_add(vip1);
    	goto VIPSTART;
    }else if(quest==3){
        int chg;
        printf("��Ҫ�޸ļ��Ż�Ա����Ϣ");
        vip_screen(vip1);
        scanf("%d",&chg);
        if(vip_change(vip1,chg)==-1)goto VIPSTART;
    }else if(quest==4){
         return 1;
    }
    return 0;
}

int vip_screen(struct vip vip1[]){
	printf("ͼ�����۹���ϵͳ > ��Ա��Ϣ���� > ��ʾ��Ա��Ϣ"); 
    for(int i=0;i<=n;++i)
    {
        if(!vip1[i].cash){continue;}
        
		printf("%-3d %s\t",i+1,vip1[i].name);
        printf("%d\n",vip1[i].cash);
    }
    
    return 0;
}


  int vip_add(struct vip vip1[])
{
    system("cls");
	printf("ͼ�����۹���ϵͳ > ��Ա��Ϣ���� > ��ӻ�Ա��Ϣ\n");
    struct vip term;
    printf("��������");
    scanf("%s",term.name);
    printf("������%s,�������",term.name);
    scanf("%d",&term.cash);
    printf("������%d,yes!\n",term.cash);
    for(unsigned i = 0;i<strlen(term.name);++i)
	{
		vip1[n].name[i]=term.name[i];
		printf("%c",vip1[n].name[i]);
	}
    strcpy(vip1[n].name,term.name);
    vip1[n].cash=term.cash;
    return n+1;
}

int vip_change(struct vip vip1[],int chg)
{
   // system("cls");
	printf("ͼ�����۹���ϵͳ > ��Ա��Ϣ���� > ���Ļ�Ա��Ϣ\n");
	struct vip term;
	char change[50];
    printf("������%d�Ż�Ա������",n);
    scanf("%s",term.name);
    scanf("%d",&term.cash);
    if(strcmp(term.name,(vip1+chg)->name)==0){strcpy((vip1+chg)->name[50],change[50]);}
    else{return -1;}
    vip1[chg].cash=term.cash;
	return 0;
}



int book_mng(struct book book1[])
{
	int quest;
	    BKSTART:system("cls");
	    printf("ͼ�����۹���ϵͳ >�鼮����\n****************\n* 1.�鿴��Ŀ   *\n* 2.����鼮   *\n* 3.ɾ���鼮   *\n* 4.�������˵� *\n****************\n");
		
	    scanf("%d",&quest);
	    if(quest==1){
	        system("cls");
			bk_screen(book1);
	        printf("�����������ݻص���һ��");
			char q[900];
			scanf("%s",q);
	        goto BKSTART;
	
	    }else if(quest==2){
	        nbook++;
			bk_add(book1);
	    	goto BKSTART;
	    }else if(quest==3){
	        int chg;
	        printf("��Ҫɾ�������鼮");
	        scanf("%d",&chg);
	        if(bk_del(book1,chg)==-1){printf("ɾ��ʧ��");goto BKSTART;}
	        else{nbook--;printf("ɾ���ɹ�");goto BKSTART;}
	    }else if(quest==4){
	         return 1;
	    }
	    return nbook;
}

int bk_screen(struct book book1[]){

		printf("ͼ�����۹���ϵͳ>�鼮����>�鼮�б�\n");
	    for(int i=0;i<=nbook;++i)
	    {
	        
			if(!book1[i].price){continue;}
			printf("%-3d",i+1);
			printf("%10s\t",book1[i].name);
	        printf("%d\n",book1[i].price);
	    }
		return 0 ;
}

int bk_add(struct book book1[]){
	system("cls");
	printf("ͼ�����۹���ϵͳ>�鼮����>����鼮\n");
	
	    struct book term;
	    printf("��������");
	    scanf("%s",term.name);
	    printf("������%s,����۸�",term.name);
	    scanf("%d",&term.price);
	    printf("�۸���%d,yes!\n",term.price);
	    for(unsigned i = 0;i<strlen(term.name);++i)
		{
		strcpy(book1[nbook].name,term.name);
		printf("%c",book1[nbook].name[i]);
		}
	    book1[nbook].price=term.price;
	    printf("������%s",book1[nbook].name);
	    printf("yes!");
	    return nbook+1;
}

int bk_del(struct book book1[],int chg){
	system("cls");
	printf("ͼ�����۹���ϵͳ>�鼮����>ɾ���鼮\n");
	struct book term;
	printf("������%d���������",chg);
	scanf("%s",term.name);
	if(strcmp(term.name,book1[nbook].name)==0){book1[nbook].price=0;return 0;}//del successfully
	else{return -1;}//del wrong
	
}

int market(struct book book1[],struct vip vip1[])
{
	printf("ͼ�����۹���ϵͳ>�������\n");
	system("cls");
	printf("");
	bk_screen(book1);
	vip_screen(vip1);
	int m,b,num;
	printf("�����빺��Ļ�Ա��:\n");
	scanf("%d",&m);
	printf("������Ҫ������鼮���:\n");
	scanf("%d",&b);
	printf("��������Ҫ���������:\n");
	scanf("%d",&num);
	minm = m;
	minus = book1[b-1].price*num;
	return 0;
}
