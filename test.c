#include <linux/string.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include<linux/module.h>
#include<linux/list.h>
#include<linux/slab.h>

struct birthday{
    int day;
    int month;
    int year;
    char* name;
    char* number;
    struct list_head list;
};
static LIST_HEAD(birthday_list);

int simple_init(void){
    struct birthday *ptr;
    struct birthday *person,*person2,*person3,*person4,*person5;
    person = kmlloc(sizeof(*person),GFP_KERNEL);
    person->day = 22;
    person->month = 7;
    person->year = 2018;
    person->name = kmlloc(sizeof("Jane"),GFP_KERNEL);
    strcpy(person->name,"Jane");
    person->number = kmlloc(sizeof("D0511000"),GFP_KERNEL);
    strcpy(person->name,"D0511000");

    person2 = kmlloc(sizeof(*person2),GFP_KERNEL);
    person2->day = 4;
    person2->month = 3;
    person2->year = 2018;
    person2->name = kmlloc(sizeof("Michael"),GFP_KERNEL);
    strcpy(person->name,"Michael");
    person2->number = kmlloc(sizeof("D0511001"),GFP_KERNEL);
    strcpy(person->name,"D0511001");

    person3 = kmlloc(sizeof(*person3),GFP_KERNEL);
    person3->day = 4;
    person3->month = 3;
    person3->year = 2018;
    person3->name = kmlloc(sizeof("Lacey"),GFP_KERNEL);
    strcpy(person->name,"Lacey");
    person3->number = kmlloc(sizeof("D0511002"),GFP_KERNEL);
    strcpy(person->name,"D0511002");

    person4 = kmlloc(sizeof(*person4),GFP_KERNEL);
    person4->day = 4;
    person4->month = 4;
    person4->year = 2018;
    person4->name = kmlloc(sizeof("Tom"),GFP_KERNEL);
    strcpy(person->name,"Tom");
    person4->number = kmlloc(sizeof("D0511003"),GFP_KERNEL);
    strcpy(person->name,"D0511003");

    person5 = kmlloc(sizeof(*person5),GFP_KERNEL);
    person5->day = 4;
    person5->month = 5;
    person5->year = 2018;
    person5->name = kmlloc(sizeof("Stuart"),GFP_KERNEL);
    strcpy(person->name,"Stuart");
    person5->number = kmlloc(sizeof("D0511004"),GFP_KERNEL);
    strcpy(person->name,"D0511004");

    INIT_LIST_HEAD(&person->list);
    list_add_tail(&person->list,&birthday_list);
    list_add_tail(&person2->list,&birthday_list);
    list_add_tail(&person3->list,&birthday_list);
    list_add_tail(&person4->list,&birthday_list);
    list_add_tail(&person5->list,&birthday_list);

    printk(KERN_INFO "loading module\n");
    list_for_each_entry(ptr,&birthday_list,list){
        printk(KERN_ALERT "Name:%s, ID: %s, Birthday: %d/%d/%d",ptr->name,ptr->number,ptr->year,ptr->month,ptr->day);
    return 0;
}

void simple_exit(void){
    struct birthday *ptr, *next;

    list_for_each_entry_safe(ptr, next, &birthday_list, list){
        list_del(&ptr->list);
        kfree(ptr);
    }

    printk(KERN_INFO "Removing module\n");
}

module_init(simple_init);
module_init(simple_exit);
