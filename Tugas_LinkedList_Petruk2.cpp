//Anisa Raden 1817051007
include <iostream>
include <conio.h>
using namespace std;
struct node
{
  int urut ;
  node *next;
};

node *first_ptr = NULL;
node *posisi;
int pilihan = 0;

void tambah_node_first()
{
  node *baru;
  baru= new node;
  cout<<"Masukkan Data : ";
  cin>>baru->urut;
  baru->next = NULL;

  if (first_ptr == NULL)
  {
    first_ptr=baru;
    first_ptr->next = NULL;
  }
  else
  {
    baru->next = first_ptr;
    first_ptr = baru;
  }
}

void tambah_node_akhir()
{
  node *temp, *temp2;
  temp = new node;
  cout<<"Masukan Data : ";
  cin>>temp->urut;
  temp->next = NULL;
  
  if (first_ptr == NULL)
  {
    first_ptr = temp;
    posisi = first_ptr;
  }
  else
  {
    temp2 = first_ptr;
    while (temp2->next !=NULL)
    {
      temp2 = temp2->next;
    }
    temp2->next = temp;
  }
}
//Livia Ayu Istoria H 1817051031
void display_list()
{
  node *temp;
  temp = first_ptr;
  cout<<endl;
  cout<<" DATA [";
  if (temp == NULL)
    cout << "List kosong!"<<endl;
  else
  {
    while (temp != NULL)
    {
      cout<<""<<temp->urut<<",";
      if(temp == posisi)
        cout<<" <<<< posisi node";
      temp = temp->next;
    }
    cout<<"]";
    cout<<"Akhir List!"<<endl;
  }
}
void hapus_node_first()
{
  node *temp;
  temp=first_ptr;
  first_ptr=first_ptr->next;
  delete temp;
}
  // Mutiara Widdi A 1817051047
void hapus_node_akhir ()
{
   node *temp1, *temp2;
  if (first_ptr == NULL)
    cout<<"List Kosong !"<<endl;
    else
    {
      temp1 = first_ptr;
      if (temp1->next == NULL)
      {
        delete temp1;
        first_ptr = NULL;
      }
      else
      {
        while (temp1->next != NULL)
        {
          temp2 = temp1;
          temp1 = temp1->next;
        }
        delete temp1;
        temp2->next = NULL;
      }
    }
  }

void menyisipkan_node_tertentu()
{
  node *baru, *bantu;
  int posisi_sisip;
  if (first_ptr != NULL)
  {
    cout<<"Akan disisip setelah Data Ke ? : ";
    cin>>posisi_sisip;
    baru = new node;
    bantu = first_ptr;
    
    for(int i=1;i<posisi_sisip-1;i++) {
      if(bantu->next != NULL)
        bantu=bantu->next;
      else
        break;
    }
  cout << "Masukkan data : ";
  cin >> baru->urut;
  baru->next=bantu->next;
  bantu->next=baru;
  }
  else
  {
    cout<<"Belum ada data !! silakan isi data dulu....";
    getch();
  }
}

//Atika Istiqomah 1817051004

int data (int nilai){
  node *baru;
  baru = new node;
  baru->urut = nilai;
  baru -> next = NULL;
  
  if (first_ptr == NULL) {
    first_ptr = baru;
    first_ptr->next = NULL;
  } else {
    baru->next = first_ptr;
    first_ptr = baru;
  }
}

int main ()
{
  cout<<"*********************************************"<<endl;
  cout<<"NAMA KELOMPOK : "<<endl;
  cout<<"ATIKA ISTIQOMAH - 1817051004 \n";
  cout<<"ANISA RADEN - 1817051007 \n";
  cout<<"LIVIA AYU ISTORIA HERNANI - 1817051031 \n";
  cout<<"MUTIARA WIDDI AYUNINTYAS - 1817051047 \n";
  cout<<"*********************************************"<<endl;
  
  first_ptr = NULL;
  data (10);
  data (12);
  data (5);
  data (7);
  data (22);
  
  do {
    display_list() ;
    cout<<endl;
    cout<<"MENU PILIHAN : "<<endl;
    cout<<"0. Keluar Program. \n";
    cout<<"1. Tambah Node Depan. \n";
    cout<<"2. Tambah Node Belakang. \n";
    cout<<"3. Hapus Node Depan. \n";
    cout<<"4. Hapus Node Belakang. \n";
    cout<<"5. Menyisipkan Node Diposisi Tertentu. \n";
    cout<<"\n Pilihan >> ";
    cin>>pilihan;

switch (pilihan) {
  case 1 : tambah_node_first();
    break;
  case 2 : tambah_node_akhir();
    break;
  case 3 : hapus_node_first();
    break;
  case 4 : hapus_node_akhir();
    break;
  case 5 : menyisipkan_node_tertentu();
  }
 }
  while (pilihan != 0);
}
