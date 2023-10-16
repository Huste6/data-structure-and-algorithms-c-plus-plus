#include<stdio.h>
#include<math.h>
#define maxn 256
typedef struct Profile
{
    char name[maxn];
    char email[maxn];
    struct Profile* next;
    struct Profile* prev;
}Profile;
Profile* first, *last;
Profile* makeProfile(char* name, char* email)
{
    Profile* node = (Profile*)malloc(sizeof(Profile));
    strcpy(node->name,name);
    strcpy(node->email,email);
    node->next = NULL;node->prev=NULL;
    return node;
}
void initList()
{
    first = NULL;
    last = NULL;
}
int listEmpty()
{
    return first == NULL && last == NULL;
}
void inserLast(char* name, char* email)
{
    Profile* profile = makeProfile(name, email);
    if(listEmpty())
    {
        first = profile;
        last = profile;
    }
    else
    {
        last->next = profile;
        profile->prev=last;
        last = profile;
    }
}
void printListLeft2Right()
{
    for(Profile* p = first; p != NULL; p = p->next)
        printf("%s, %s\n", p->name, p->email);
}
void printListRight2Left()
{
    for(Profile*p=last;p!=NULL;p=p->prev){
        printf("%s %s\n",p->name,p->email);
    }
}
Profile*find(char*name)
{
    for(Profile*p=first;p!=NULL;p=p->next)
    {
        if(strcmp(p->name,name)==0){
            return p;
        }
    }
    return NULL;
}
Profile* removeProfile(Profile* f, char* name)
{
    if(listEmpty()) return NULL;
    Profile*profile=find(name);
    if(profile==NULL){
        printf("NOT FOUND!\n");
    }else{
        Profile*left=profile->prev;
        Profile*right=profile->next;
        if(left!=NULL) left->next=right;
        if(right!=NULL) right->prev=left;
        if(left==NULL) first=right;
        if(right==NULL) last=left;
        free(profile);
    }
}
void load(char* filename)
{
    FILE* f = fopen(filename,"r");
    if(f == NULL) printf("Load data -> file not found\n");
    initList();
    while(!feof(f))
    {
        char name[maxn], email[maxn];
        fscanf(f,"%s%s", name, email);
        inserLast(name, email);
        printf("insert %s,%s\n",name,email);
    }
    fclose(f);
}
void processFind()
{
    char name[maxn];
    scanf("%s",name);
    Profile* profile = NULL;
    for(Profile* p = first; p != NULL; p = p->next)
    {
        if(strcmp(p->name,name) == 0)
        {
            profile = p;
            break;
        }
    }
    if(profile == NULL) printf("NOT FOUND profile %s\n",name);
    else printf("FOUND profile %s, %s\n",profile->name,profile->email);
}
void processLoad()
{
    char filename[maxn];
    scanf("%s",filename);
    load(filename);
}
void processStore()
{
    char filename[maxn];
    scanf("%s",filename);
    FILE* f = fopen(filename,"w");
    for(Profile* p = first; p != NULL; p = p->next)
    {
        fprintf(f,"%s %s", p->name, p->email);
        if(p->next != NULL) fprintf(f,"\n");
    }
    fclose(f);
}
void processInsert()
{
    char name[maxn],email[maxn];
    scanf("%s%s", name, email);
    inserLast(name, email);
}
void processRemove()
{
    char name[maxn];
    scanf("%s",name);
    first = removeProfile(first, name);
}
void processprintList()
{
    printf("danh sach tu trai qua phai: ");
    printListLeft2Right();
    printf("danh sach tu phai qua trai: ");
    printListRight2Left();
}
void finalize()
{
    Profile*p=first;
    while(p!=NULL)
    {
        Profile*np=p->next;
        free(p);
        p=np;
    }
}
int main()
{
    initList();
    while(1)
    {
        printf("Enter command: \n");
        char cmd[maxn];
        scanf("%s",cmd);
        if(strcmp(cmd,"Quit") == 0) break;
        else if(strcmp(cmd,"Load") == 0) processLoad();
        else if(strcmp(cmd,"Print") == 0) processprintList();
        else if(strcmp(cmd,"Find") == 0) processFind();
        else if(strcmp(cmd,"Insert") == 0) processInsert();
        else if(strcmp(cmd,"Remove") == 0) processRemove();
        else if(strcmp(cmd,"Store") == 0) processStore();
    }
}
