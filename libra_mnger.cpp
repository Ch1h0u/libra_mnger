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
    struct vip vip1[comps]={{"张三",100},{"李四",600},{"王五",500},{"陆六",1000},{"钱七",900},{"大强",100},{"小丽",100},{"敏敏",100}};
	struct book book1[comps]={{"C#2.0宝典", 88}, {"Java编程基础", 55}, { "J2SE桌面应用程序开发", 60}, { "数据库设计和应用", 45}, {"水浒传", 55}, {"红楼梦", 68}, {"三国演义", 78}, {"地心游记", 29}};
	
	
	
    PASSWDERROR:printf("输入用户名:\n");
    scanf("%s",username);
    if(strcmp(username,adminusername)!=0)
        {printf("用户名错误！请重新");
            goto PASSWDERROR;}
    for(int i=0;i<3;++i)
    {

        printf("输入密码:\n");
        scanf("%s",passwd);
        if(strcmp(username,adminusername)==0&&strcmp(passwd,adminpasswd)==0)goto INIT;
        else
        {
            if(step==2)goto ERROR;
            printf("密码输入错误，你还有%d次机会\n",2-i);
            step++;
            continue;
        }
    }
    ERROR:printf("密码错误，你的输入机会已用完\n");
    goto PASSWDERROR;
    return 114514;
	
	 INIT:int brunch;
   
    system("cls");
    


	printf("******************************\n*      图书销售管理系统      *\n*         1.会员管理         *\n*         2.书籍管理         *\n*         3.购物结算         *\n*         4.注销             *\n******************************\n");
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
        printf("正在注销 ");
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
    printf("******************************\n*  1.显示所有会员        *\n*  2.添加会员信息        *\n*  3.修改会员信息        *\n*  4.返回主菜单          *\n******************************\n请选择，输入数字：\n");
    scanf("%d",&quest);
    if(quest==1){
        system("cls");
		vip_screen(vip1);
        printf("输入任意数据回到上一级");
			char q[900];
			scanf("%s",q);
        goto VIPSTART;

    }else if(quest==2){
        n++;
		vip_add(vip1);
    	goto VIPSTART;
    }else if(quest==3){
        int chg;
        printf("你要修改几号会员的信息");
        vip_screen(vip1);
        scanf("%d",&chg);
        if(vip_change(vip1,chg)==-1)goto VIPSTART;
    }else if(quest==4){
         return 1;
    }
    return 0;
}

int vip_screen(struct vip vip1[]){
	printf("图书销售管理系统 > 会员信息管理 > 显示会员信息"); 
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
	printf("图书销售管理系统 > 会员信息管理 > 添加会员信息\n");
    struct vip term;
    printf("输入名字");
    scanf("%s",term.name);
    printf("名字是%s,输入积分",term.name);
    scanf("%d",&term.cash);
    printf("积分是%d,yes!\n",term.cash);
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
	printf("图书销售管理系统 > 会员信息管理 > 更改会员信息\n");
	struct vip term;
	char change[50];
    printf("请输入%d号会员的姓名",n);
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
	    printf("图书销售管理系统 >书籍管理\n****************\n* 1.查看书目   *\n* 2.添加书籍   *\n* 3.删除书籍   *\n* 4.返回主菜单 *\n****************\n");
		
	    scanf("%d",&quest);
	    if(quest==1){
	        system("cls");
			bk_screen(book1);
	        printf("输入任意数据回到上一级");
			char q[900];
			scanf("%s",q);
	        goto BKSTART;
	
	    }else if(quest==2){
	        nbook++;
			bk_add(book1);
	    	goto BKSTART;
	    }else if(quest==3){
	        int chg;
	        printf("你要删除几号书籍");
	        scanf("%d",&chg);
	        if(bk_del(book1,chg)==-1){printf("删除失败");goto BKSTART;}
	        else{nbook--;printf("删除成功");goto BKSTART;}
	    }else if(quest==4){
	         return 1;
	    }
	    return nbook;
}

int bk_screen(struct book book1[]){

		printf("图书销售管理系统>书籍管理>书籍列表\n");
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
	printf("图书销售管理系统>书籍管理>添加书籍\n");
	
	    struct book term;
	    printf("输入书名");
	    scanf("%s",term.name);
	    printf("书名是%s,输入价格",term.name);
	    scanf("%d",&term.price);
	    printf("价格是%d,yes!\n",term.price);
	    for(unsigned i = 0;i<strlen(term.name);++i)
		{
		strcpy(book1[nbook].name,term.name);
		printf("%c",book1[nbook].name[i]);
		}
	    book1[nbook].price=term.price;
	    printf("书名是%s",book1[nbook].name);
	    printf("yes!");
	    return nbook+1;
}

int bk_del(struct book book1[],int chg){
	system("cls");
	printf("图书销售管理系统>书籍管理>删除书籍\n");
	struct book term;
	printf("请输入%d号书的名字",chg);
	scanf("%s",term.name);
	if(strcmp(term.name,book1[nbook].name)==0){book1[nbook].price=0;return 0;}//del successfully
	else{return -1;}//del wrong
	
}

int market(struct book book1[],struct vip vip1[])
{
	printf("图书销售管理系统>购物结算\n");
	system("cls");
	printf("");
	bk_screen(book1);
	vip_screen(vip1);
	int m,b,num;
	printf("请输入购买的会员号:\n");
	scanf("%d",&m);
	printf("请输入要购买的书籍编号:\n");
	scanf("%d",&b);
	printf("请输入您要购买的数量:\n");
	scanf("%d",&num);
	minm = m;
	minus = book1[b-1].price*num;
	return 0;
}
