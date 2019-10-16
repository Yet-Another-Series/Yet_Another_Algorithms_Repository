#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct head_word{
    char word[40];
    struct head_word*left,*down;
};
struct file_list
{
    char name[10];
    struct file_list*left;
};
void create_list(struct head_word**head,char word[40],char file_name[10])
{
    struct head_word *temp1=(struct head_word*)malloc(sizeof(struct head_word));
    struct head_word *temp2=(struct head_word*)malloc(sizeof(struct head_word));
    strcpy(temp2->word,word);
    strcpy(temp1->word,file_name);
    temp1->down=NULL;
    temp1->left=NULL;
    temp2->left=temp1;
    if(*head==NULL || strcmp((*head)->word,word)>=0)
    {
        temp2->down=*head;
        *head=temp2;
    }
    else
    {
        struct head_word*curr=*head;
        while(curr->down!=NULL && strcmp(curr->down->word,temp2->word)<0)
        {
            curr=curr->down;
        }
        temp2->down=curr->down;
        curr->down=temp2;
    }
    
     
}
void add_docs(struct head_word**head,char word[40],char file_name[12])
{
    struct head_word *temp1=(struct head_word*)malloc(sizeof(struct head_word));
    strcpy(temp1->word,file_name);
    temp1->left=NULL;
    temp1->down=NULL;
    struct head_word* temp2=*head;
    while(temp2)
    {
        if(strcmp(temp2->word,word)==0)
        {
            
            struct head_word*head_docs1=temp2->left;
            struct head_word*head_docs2;
            while(head_docs1)
            {
                head_docs2=head_docs1;
                head_docs1=head_docs1->left;
                if(strcmp(head_docs2->word,file_name)==0)
                    return;
                // printf("%s \n",head_docs1->word);
            }
            
            head_docs2->left=temp1;
            
            break;
        }
        temp2=temp2->down;
    }
}
void print(struct head_word*head)
{
    struct head_word*temp1=head;
    while(temp1)
    {
        struct head_word* temp2=temp1->left;
        printf("%s ->",temp1->word);
        while(temp2)
        {
            printf(" %s ",temp2->word);
            temp2=temp2->left;
            
        
        }
        // printf("@*");
        printf("\n");
        temp1=temp1->down;
    }
    return;
}

int word_search(struct head_word*head,char word[20])
{
    struct head_word*tmp=head;
    while(tmp)
    {
        // printf("%s\n",tmp->word);
        if(strcmp(tmp->word,word)==0)
            return 1;
        tmp=tmp->down;    
    }
    return 0;
}


int main()
{
    struct head_word*head=NULL;
    int n;
    printf("Enter the number of files:");
    scanf("%d",&n);
    int count=0;
    while(n--)
    {
        char file_name[200];
        printf("Enter the file name:");
        scanf("%s",file_name);
        FILE *fp=fopen(file_name,"r");
        int k=0;
        char c;
        char word[20];
        
        int v=0;

        
        v=0;
        while((c=fgetc(fp))!=EOF)
        {
            if(((int)c>=65 && (int)c<=90) || ((int)c>=97 && (int)c<=122))
            {
                word[k]=c;
                k+=1;
            }      
            else
            {
                // printf("%s ",word);
                if(word_search(head,word))
                {
                    
                    // char file_name[12]={'d','o','c','2','.','t','x','t'};
                    add_docs(&head,word,file_name);
                }
                else
                {
                    
                    // char file_name[12]={'d','o','c','1','.','t','x','t'};
                    if(word[0]!=' ')
                    create_list(&head,word,file_name);
                    count++;
                }
                
                k=0;
                for(int i=0;i<20;i++)word[i]=0;
            }     
        }
    }
    
    
    
    print(head);
    
}

