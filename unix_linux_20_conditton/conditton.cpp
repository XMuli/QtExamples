#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct node  //节点结构
{
    int data;
    struct node* next;
} Node;

Node* g_head =  nullptr;  //永远指向链表头部的指针

pthread_mutex_t g_mutex;  //互斥锁--线程同步
pthread_cond_t g_cond;    //条件变量--阻塞线程，等待条件满足

void* funProducer(void* arg);  //生产者--添加一个头结点
void* funCustomer(void* arg);  //消费者--删除一个头结点

int main(int argc, char *argv[])
{
    pthread_t p1;
    pthread_t p2;

    pthread_mutex_init(&g_mutex, nullptr);  //初始化互斥锁
    pthread_cond_init(&g_cond, nullptr);    //初始化条件变量

    pthread_create(&p1, nullptr, funProducer, nullptr);  //创建生产者线程
    pthread_create(&p2, nullptr, funCustomer, nullptr);  //创建消费者线程

    pthread_join(p1, nullptr);  //阻塞回收子线程
    pthread_join(p2, nullptr);

    pthread_mutex_destroy(&g_mutex);  //配套销毁互斥锁
    pthread_cond_destroy(&g_cond);    //配套销毁条件变量
    
    return 0;
}

void* funProducer(void* arg)
{
    while (true) {
        Node* pNew = new Node();
        // Node* pNew = (Node *)malloc(sizeof(Node));
        pNew->data = rand() % 1000; 

        pthread_mutex_lock(&g_mutex);  //加锁
        pNew->next = g_head;
        g_head = pNew;
        printf("-----funProducer(生产者): %lu, %d\n", pthread_self(), pNew->data);
        pthread_mutex_unlock(&g_mutex);  //解锁
        
        pthread_cond_signal(&g_cond);  //通知阻塞的消费者线程，解除阻塞

        sleep(rand() % 3);  //随机休息 0~2 s
    }
    
    return nullptr;
}

void* funCustomer(void* arg)
{
    while (true) {
        pthread_mutex_lock(&g_mutex);  //加锁

        if (g_head == nullptr) {  //若是没有，则等待生产者生产出来，在此阻塞，等待消费
            pthread_cond_wait(&g_cond, &g_mutex); //阻塞线程，且该函数会对互斥锁解锁；且接解除阻塞之后，对互斥锁进行加锁操作
        }

        Node* pDel = g_head;
        g_head = g_head->next;
        printf("-----funCustomer(消费者): %lu, %d\n", pthread_self(), pDel->data);
        delete pDel;
        // free(pDel);
        pthread_mutex_unlock(&g_mutex);  //解锁
    }

    return nullptr;
}