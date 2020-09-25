#include <iostream>
#include <cstdlib>
#define MAX 20

using namespace std;

struct queue{
	int data[MAX];
	int awal, akhir;
} antrean;

void init(){
	antrean.awal=-1;
	antrean.akhir=-1;
}

bool full(){
	if(antrean.akhir == MAX-1){
		return true;
	}else{
		return false;
	}
}

bool empty(){
	if(antrean.akhir==-1){
		return true;
	}else{
		return false;
	}
}

void tampilData(){
	int i;
	if(!empty()){
		for(int i = antrean.awal;i<antrean.akhir; i++){
			cout<<antrean.data[i]<<" | ";
		}
	}
	cout<<endl;
}

void inQueue(){
	tampilData();
	int elemen;

	if(!full()){
		cout<<"Data yang akan dimasukan : ";
		cin>>elemen;
		cout<<"Data berhasil ditambahkan\n";
		antrean.data[antrean.akhir]=elemen;
		antrean.akhir++;
	}else{
		cout<<"Queue Penuh";
	}
}

void deQueue(){
	int i;
	tampilData();
	if(!empty()){
		cout<<"mengambil data "<<antrean.data[antrean.awal]<<endl;
		for(i = antrean.awal; i<antrean.akhir; i++){
			antrean.data[i]=antrean.data[i+1];
		}
		antrean.akhir--;
	}else{
		cout<<"Antrean Kosong"<<endl;
	}
}

void clear(){
	antrean.awal=-1;
	antrean.akhir=-1;
}

void search(){
	bool ketemu = false;
	int index;
	int q;

	cout<<"masukan data yang ingin dicari : "; cin>>q;
	for(int i =antrean.awal; i<antrean.akhir;i++){
		if(q == antrean.data[i]){
			ketemu = true;
			index = i+2;
		}
	}

	if(ketemu){
		cout<<"Data ditemukan pada antrean ke-"<<index<<endl;
	}else{
		cout<<"Data tidak ditemukan"<<endl;
	}
	cout<<"======================"<<endl;
}

void maxMin(){
	int number[100];
	int min=0;
	int jml, terbesar=0, terkecil=number[0];

	for (int i = antrean.awal; i < antrean.akhir+1; i++){
		number[i] = antrean.data[i-1];
	}

	for (int i = 0; i < antrean.akhir+1; i++){
		if(number[i] > terbesar){
			terbesar = number[i];
		}
		if(number[i] < terkecil){
			terkecil = number[i];
		}
	}

	cout<<"Data terbesar : "<<terbesar<<endl;
	cout<<"Data terkecil : "<<terkecil<<endl;
	cout<<"Data terkecil : "<<terkecil<<endl;
	cout<<"Data terkecil : "<<terkecil<<endl;
	cout<<"Data terkecil : "<<terkecil<<endl;
	cout<<"Data terkecil : "<<terkecil<<endl;
	cout<<"Data terkecil : "<<terkecil<<endl;
	cout<<"Data terkecil : "<<terkecil<<endl;
	cout<<"Data terkecil : "<<terkecil<<endl;
	cout<<"Data terkecil : "<<terkecil<<endl;
	cout<<"Data terkecil : "<<terkecil<<endl;
	cout<<"Data terkecil : "<<terkecil<<endl;
}

void information(){
	if(!empty()){
		int total=0;
		float rata;
		int jumlahData = antrean.akhir+1;
		for (int i = antrean.awal; i < antrean.akhir+1; i++){
			total += antrean.data[i];
		}
		rata = total/jumlahData;
		cout<<"Nilai total : "<<total<<endl;
		cout<<"Rata-rata : "<<rata<<endl;
		maxMin();
	}else{
		cout<<"Queue Kosong";
	}
}

int main(){
	int pilihan, elemen;
	init();
	do{
		tampilData();
		cout<<"======================"<<endl;
		cout<<"Demo Queue by Alfin Andika Pratama"<<endl;
		cout<<"======================"<<endl;
		cout<<"\n [1] init \n [2] inQueue \n [3] deQueue \n [4] clear \n [5] search \n [6] Information \n [0] Keluar \n";
		cout<<"======================"<<endl;
		cout<<"Masukan Pilihan : ";
		cin>>pilihan;
		cout<<"======================"<<endl;
		switch(pilihan){
			case 1: init(); break;
			case 2: inQueue(); break;
			case 3: deQueue(); break;
			case 4: clear(); break;
			case 5: search(); break;
			case 6: information(); break;
		}
	}while(pilihan!=0);
}
