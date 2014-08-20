#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<assert.h>

#define MAX_TOP_ITEMS 10

struct top_item {

	char *page;
	unsigned long count;

	struct top_item *next_item;
};

static struct top_item *head = NULL;

static void format_items(){
       int n=0;
       struct top_item *tmp = head;
       printf("TOP LIST\n");
       printf("========\n");
       while (tmp!=NULL){
         printf("%02d. %50s %15lu\n",(n+1),tmp->page,tmp->count);
	 tmp= tmp->next_item;
         n++;
       }
       printf("\n");
 
}
static void dump_items(){
       int n=0;
       struct top_item *tmp = head;
       printf ("===== HEAD %p\n",tmp);
       while (tmp!=NULL){
         printf("0x%p %s %lu n=%d,->%p\n",tmp,tmp->page,tmp->count,n,tmp->next_item);
	 tmp= tmp->next_item;
         n++;
       }
       printf("  END\n");
}

/*
 * creates and returns top_item structure filled with page and count
 * next_item is set to NULL
 */
static struct top_item *create_top_item( char *page, unsigned long count){
       struct top_item *t = (struct top_item*)malloc(sizeof(struct top_item));
       assert( t!=NULL );
       // initialize fields
       t->page = strdup(page);
       t->count = count;
       t->next_item = NULL;
       return t;
}

static void insert_top_item( char *page, unsigned long count){
	struct top_item *tmp=NULL,*prev_tmp=NULL;
        int nitems = 0;

        // empty list - easy
	if (head == NULL ){
                struct top_item *t = create_top_item(page,count);
		head = t;
		return;
        }
 	
	for( tmp = head;tmp!=NULL;){
	  if ( tmp->count <= count ){
		break;
          }
 	  prev_tmp = tmp;
          tmp=tmp->next_item;
          nitems++;
        }
        if ( tmp == NULL ){
           // if there is room in list, add...
           if ( nitems < MAX_TOP_ITEMS ){
                struct top_item *t = create_top_item(page,count);
                if (prev_tmp == NULL ){
                     head = t;
                } else {
                     prev_tmp->next_item = t;
                }
           }
           return;
        }
        // tmp is not NULL - insert into middle of list
	struct top_item *t = create_top_item(page,count);
	if (prev_tmp == NULL ){
	     head = t;
	} else {
	     prev_tmp->next_item = t;
	}
        t->next_item = tmp;
        // dump_items();

	nitems = 0;
        prev_tmp = NULL;
        for(tmp=head;tmp!=NULL;){
            nitems++;
            if (nitems > MAX_TOP_ITEMS){
              assert( tmp != NULL );
              assert( tmp->next_item == NULL );
              free(tmp->page);
              prev_tmp->next_item = NULL; 
              free(tmp);
              break;
            }
            prev_tmp = tmp; 
            tmp=tmp->next_item;
        }

}

int main(int argc,char **argv){

        int ignored = 0,rows=0;
        int err = 0;
	char project[20];
        char page[1024];
        unsigned long count=0,sz=0;
	

	while ( (err = scanf("%19s %1023s %lu %lu",project,page,&count,&sz)) == 4 ){
		rows++;
                // ignore non-english projects
                if (strncmp(project,"en",2)!=0){
 			ignored ++;
			continue;
                }
                // ignore pages with %XX (weird national characters etc..)
                if (strchr(page,'%')!=NULL){
 			ignored ++;
			continue;
                }
                insert_top_item(page,count);
                // dump_items();
		// printf("Page '%s', count '%lu'\n",page,count);
		// if ( (rows % 100000)==0 ){
	 	//	format_items();
                // }

        }
        if ( errno ){
		perror("scanf");
                exit(2);
        }
        format_items();
       

	return 0;
}
