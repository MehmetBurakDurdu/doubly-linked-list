#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head;

struct node* dugum_olusturucu(int data)
{
    printf("\ndugum olusturuluyor...");
    struct node* yeni_dugum = (struct node*)malloc(sizeof (struct node));
    yeni_dugum->data = data;
    yeni_dugum->prev = NULL;
    yeni_dugum->next = NULL;
    return yeni_dugum;
}

void bastir()
{
    printf("\n");
    struct node* temp = head;
    while(temp != NULL)
    {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
}


void sona_ekleme(int data)
{
    printf("\nsona ekleniyor...");
    struct node* son_yeni = dugum_olusturucu(data);
    if(head == NULL)
    {
        printf("\nliste bos ilk kez ekleme yapiliyor");

        head = son_yeni;
    }

    else
    {
        printf("\n traverse yapiliyor...");
        struct node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        son_yeni->prev = temp;
        temp->next = son_yeni;
    }
}

void basa_ekle(int data)
{
    struct node* bas_yeni = dugum_olusturucu(data);
    if(head == NULL)
    {
        printf("\nliste bos ilk kez ekleme yapiliyor...");
        head = bas_yeni;
        return;
    }
    else
    {
        head->prev = bas_yeni;
        bas_yeni->next =head;
        head=bas_yeni;
    }

}

void araya_ekle(int ptr ,int temp2 )
{

    struct node* temp = head;
    struct node* ara_yeni = dugum_olusturucu(temp2);
    struct node * onceki=NULL;


    if(head == NULL)
    {
        head=ara_yeni;
    }

    else if(head->data== ptr)
    {
        basa_ekle(temp2);
    }
    else
    {
        while (temp->next != NULL)
        {
            if(temp->data == ptr)
            {
                onceki=temp->prev;
                break;
            }
            temp=temp->next;
        }
        temp->prev=ara_yeni;
        ara_yeni->next=temp;
        ara_yeni->prev=onceki;
        onceki->next=ara_yeni;

    }

}

void sondan_sil()
{
    if(head == NULL)
    {
        return(printf("liste bos silme islemi yapilamaz"));
    }

    else if(head->next == NULL)
    {
        head = NULL;
    }

    else
    {
        struct node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        struct node* onceki = temp->prev;
        onceki->next = NULL;
        free(temp);
    }
}

void bastanSil()
{
    if(head == NULL)
    {
        return(printf("liste bos"));
    }


    else if(head->next == NULL)
    {
        head = NULL;
    }

    else
    {
        struct node* bas_yeni = head->next;
        free(head);
        head = bas_yeni;
        bas_yeni->prev = NULL;
    }
}

void aradanSil(int silinecek)
{
    struct node* temp = head;
    while(temp != NULL)
    {
        if(temp->data == silinecek)
        {
             break;
        }
        temp = temp->next;
    }
    struct node* onceki = temp->prev;
    struct node* sonraki = temp->next;
    free(temp);
    onceki->next = sonraki;
    sonraki->prev = onceki;
}





int main()
{
    while(1)
    {
        int secim, sayi, sayi1;
        printf("\n1-) sona ekle");
        printf("\n2-) basa ekle");
        printf("\n3-) araya ekle");
        printf("\n4-) sondan sil");
        printf("\n5-) bastan sil");
        printf("\n6-) aradan sil");
        printf("\nseciminizi yapiniz: ");
        scanf("%d", &secim);
        switch (secim)
        {
            case 1:
                printf("sona eklemek istediginiz elemani giriniz: ");
                scanf("%d", &sayi);
                sona_ekleme(sayi);
                printf("\nsona sayi eklendi");
                bastir();
                break;
            case 2:
                printf("basa eklemek istediginiz elemani giriniz: ");
                scanf("%d", &sayi);
                basa_ekle(sayi);
                printf("\nbasa sayi eklendi");
                bastir();
                break;
            case 3:
                printf("araya eklemek istediginiz elemani giriniz: ");
                scanf("%d", &sayi);
                printf("hangisi datadan once eklemek istiyorsunuz: ");
                scanf("%d", &sayi1);
                araya_ekle(sayi1,sayi);
                printf("\naraya eleman eklendi");
                bastir();
                break;
            case 4:
                sondan_sil();
                printf("\nsondan eleman silindi");
                bastir();
                break;
            case 5:
                bastanSil();
                printf("\nbastan eleman silindi");
                bastir();
                break;
            case 6:
                printf("hangi datayi silmek istiyorsunuz: ");
                scanf("%d", &sayi);
                aradanSil(sayi);
                bastir();
                break;
        }

    }
}

