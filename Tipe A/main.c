#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define hargaAsusa 8000000
#define hargaLenova 7500000
#define hargaApel 15000000
#define hargaSangsung 18000000

//untuk SOAL BONUS 
#define pabrikAsusa 7000000
#define pabrikLenova 6500000
#define pabrikApel 13500000
#define pabrikSangsung 16000000

typedef char string[50];

void inisialisasi(int *cekIn, int *toleransi, int *pembeli, int *pembelian, int *pembelianKhusus, int *tempJenis, int *jmlAsusa, int *jmlLenova, int *jmlApel, int *jmlSangsung, 
                    int *totAsusa, int *totLenova, int *totApel, int *totSangsung, int *tempAsusa, int *tempLenova, int *tempApel, int *tempSangsung, int *total);
void pengurangan(int *m, int pengurang);
void penjumlahan(int *m, int penjumlah);
void perkalian(int *hasil, int harga, int pengali);
void cekLogin(int *cekIn, string nama, int pass);
void cekJenis(int *tempJenis, string jenis, int A, int L, int Ap, int S);
void pembaruanKetersediaan(int *jmlA, int *jmlL, int *jmlAp, int *jmlS, int *totA, int *totL, int *totAp, int *totS, string jenis, int jumlah);
void tampilDataPembeli(string nama, string tanggal, string jam);
void tampilDataPembeliKhusus(string nik, string pekerjaan, string alamat);
void rincianPembelian(int jmlA, int jmlL, int jmlAp, int jmlS, int hA, int hL, int hAp, int hS, int totA, int totL, int totAp, int totS);
void hitungTotal(int *total, int totA, int totL, int totAp, int totS);

// Untuk Bonus
void inisialisasiSoalBonus(int *kA, int *kL, int *kAp, int *kS);
void hitungKeuntungan(int *keuntungan, int jml, int hargaJual, int hargaPabrik);


int main(){
    string username, nama, telp, tgl, jam, jenis, nik, pekerjaan, alamat, konfirm;
    int pass, pil, jumlah, cekIn, toleransi, pembeli, pembelian, tempJenis, pembelianKhusus;
    int jmlAsusa, jmlLenova, jmlApel, jmlSangsung, totAsusa, totLenova, totApel, totSangsung;
    int tempAsusa, tempLenova, tempApel, tempSangsung, total;
    int keuntunganAsusa, keuntunganLenova, keuntunganApel, keuntunganSangsung, totalUntung;

    inisialisasi(&cekIn, &toleransi, &pembeli, &pembelian, &tempJenis, &pembelianKhusus, &jmlAsusa, &jmlLenova, &jmlApel, &jmlSangsung, 
                    &totAsusa, &totLenova, &totApel, &totSangsung, &tempAsusa, &tempLenova, &tempApel, &tempSangsung, &total);
	inisialisasiSoalBonus(&keuntunganAsusa, &keuntunganLenova, &keuntunganApel, &keuntunganSangsung);
	
    do{
        system("cls");
        printf("\n\n\n\n");
        printf("\n\t\t\t\t     --------------------------------------");
        printf("\n\t\t\t\t     |         -UGD PROSEDUR 2-           |");
        printf("\n\t\t\t\t     |              TIPE A                |");
        printf("\n\t\t\t\t     |        TOKO MONITOR ATMA1          |");
        printf("\n\t\t\t\t     --------------------------------------\n");
        printf("\n\t\t\t\t\t\t=== LOGIN ===");
        printf("\n\t\t\t\t\t\tToleransi : %d\n", toleransi);
        printf("\n\t\t\t\t\tUsername (Atma): "); fflush(stdin); gets(username);
        printf("\t\t\t\t\tPassword (10659) : "); scanf("%d", &pass);
        cekLogin(&cekIn, username, pass);

        if(cekIn==1){
            do{
                system("cls");
                printf("\n\t\t==== MENU ====");
                printf("\n\t  Ketersediaan Monitor : \n\t  %d Asusa - %d Lenova - %d Apel - %d Sangsung", jmlAsusa, jmlLenova, jmlApel, jmlSangsung);
                printf("\n\t[1] Input Pembeli");
                printf("\n\t[2] Input Pembelian");
                printf("\n\t[3] Rincian");
                printf("\n\t[4] Reset Data");
                printf("\n\t[0] Logout");
                
                printf("\n\n\t[5] Hitung Keuntungan [TUGAS]\n");
                printf("\n\t>>> "); scanf("%d", &pil);

                switch (pil){
                    case 1:
                        if(pembeli==1){
                            printf("\n\t\t[!] Data Pembeli sudah terinput!");
                        }else{
                            printf("\n\t\t===== INPUT PEMBELI =====\n");
                            printf("\t Nama               : "); fflush(stdin); gets(nama);
                            while(strlen(nama)==0 || strcmpi(nama,"-")==0){
                                printf("\n\t\t[!] Nama tidak boleh kosong!\n");
                                printf("\n\t Nama               : "); fflush(stdin); gets(nama);
                            }
                            printf("\t No. Telp           : "); fflush(stdin); gets(telp);
                            while(strlen(telp)==0 || strcmpi(telp,"-")==0){
                                printf("\n\t\t[!] No. Telp tidak boleh kosong!\n");
                                printf("\n\t No. Telp           : "); fflush(stdin); gets(telp);
                            }
                            printf("\t Tanggal Kedatangan : "); fflush(stdin); gets(tgl);
                            while(strlen(tgl)!=10){
                                printf("\n\t\t[!] Tanggal salah!\n");
                                printf("\n\t Tanggal Kedatangan : "); fflush(stdin); gets(tgl);
                            }
                            printf("\t Jam Kedatangan     : "); fflush(stdin); gets(jam);
                            while(strlen(jam)!=8){
                                printf("\n\t\t[!] Jam salah!\n");
                                printf("\n\t Jam Kedatangan     : "); fflush(stdin); gets(jam);
                            }
                            printf("\n\t\tBerhasil Input Data...");
                            pembeli=1;
                        }  
                        getch(); 
                        break;
                    
                    case 2:
                        if(pembeli==0){
                            printf("\n\t\t[!] Input Data Pembeli Dulu!");
                        }else{
                            printf("\n\t\t===== INPUT PEMBELIAN =====");
                            printf("\n\tJenis Monitor yang ingin dibeli (Asusa, Lenova, Apel, Sangsung) : "); fflush(stdin); gets(jenis);
                            cekJenis(&tempJenis, jenis, jmlAsusa, jmlLenova, jmlApel, jmlSangsung);

                            if(tempJenis==-1){
                                printf("\n\t\t[!] Jenis Monitor tidak diketahui!");
                            }else{
                                printf("\n\tJumlah Monitor yang ingin dibeli : "); scanf("%d", &jumlah);
                                if(jumlah<0){
                                    printf("\n\t\t[!] Jumlah tidak diketahui!");	
                                }else if(tempJenis==0){
                                    printf("\n\t\t[!] Monitor jenis ini sudah habis!");	
                                }else if(jumlah>tempJenis){
                                    printf("\n\t\t[!] Jumlah melebihi ketersediaan!");
                                }else{
                                    pembaruanKetersediaan(&jmlAsusa, &jmlLenova, &jmlApel, &jmlSangsung, &totAsusa, &totLenova, &totApel, &totSangsung, jenis, jumlah);
                                    if((strcmpi(jenis,"Apel")==0 || strcmpi(jenis,"Sangsung")==0) && pembelianKhusus==0){
                                        printf("\n\n\tNIK                : "); fflush(stdin); gets(nik);
                                        while(strlen(nik)!=16){
                                            printf("\n\t\t[!] NIK salah!\n");
                                            printf("\n\tNIK                : "); fflush(stdin); gets(nik);
                                        }
                                        printf("\tPekerjaan          : "); fflush(stdin); gets(pekerjaan);
                                        while(strlen(pekerjaan)==0){
                                            printf("\n\t\t[!] Pekerjaan harus diisi!\n");
                                            printf("\n\tPekerjaan          : "); fflush(stdin); gets(pekerjaan);
                                        }
                                        printf("\tAlamat             : "); fflush(stdin); gets(alamat);
                                        while(strlen(alamat)==0){
                                            printf("\n\t\t[!] Alamat harus diisi!\n");
                                            printf("\n\tAlamat             : "); fflush(stdin); gets(alamat);
                                        }
                                        pembelianKhusus=1;
                                    }
                                    printf("\n\t\tBerhasil Input Pembelian...");
                                    pembelian=1;
                                }
                            }
                        }
                        getch();
                        break;
                    
                    case 3:
                        if(pembeli!=1 && pembelian!=1){
                            printf("\n\t\t[!] Input Data Pembeli dan Data Pembelian dulu!");
                        }else if(pembeli!=1){
                            printf("\n\t\t[!] Input Data Pembeli dulu!");
                        }else if(pembelian!=1){
                            printf("\n\t\t[!] Input Data Pembelian dulu!");
                        }else{
                            printf("\n\t\t\t=== PEMBAYARAN ===");
                            tampilDataPembeli(nama, tgl, jam);
                            if(pembelianKhusus==1){
                                tampilDataPembeliKhusus(nik, pekerjaan, alamat);
                            }
                            perkalian(&tempAsusa, hargaAsusa, totAsusa);
                            perkalian(&tempLenova, hargaLenova, totLenova);
                            perkalian(&tempApel, hargaApel, totApel);
                            perkalian(&tempSangsung, hargaSangsung, totSangsung);

                            rincianPembelian(totAsusa, totLenova, totApel, totSangsung, hargaAsusa, hargaLenova, hargaApel, hargaSangsung, tempAsusa, tempLenova, tempApel, tempSangsung);
                            hitungTotal(&total,tempAsusa, tempLenova, tempApel, tempSangsung);
                            printf("\n\n\tTotal : Rp %d", total);
                        }
                        getch();
                        break;
                    
                    case 4:
                        printf("\n\t\t=== RESET DATA ===");
                        printf("\n\tApakah Anda yakin ingin mereset data? [ya/tidak]\n");
                        printf("\t"); fflush(stdin); gets(konfirm);
                        if(strcmpi(konfirm,"ya")==0){
                            inisialisasi(&cekIn, &toleransi, &pembeli, &pembelian, &tempJenis, &pembelianKhusus, &jmlAsusa, &jmlLenova, &jmlApel, &jmlSangsung, 
                                            &totAsusa, &totLenova, &totApel, &totSangsung, &tempAsusa, &tempLenova, &tempApel, &tempSangsung, &total);
                            inisialisasiSoalBonus(&keuntunganAsusa, &keuntunganLenova, &keuntunganApel, &keuntunganSangsung);
                            cekIn=1;
                            printf("\n\t\tBerhasil Reset Data...");
                        }
                        getch();
                        break;
                    
                    case 5:
						if(pembeli!=1 && pembelian!=1){
							printf("\n\t\t[!] Input Data Pembeli dan Data Pembelian dulu!");
						}else if(pembeli!=1){
							printf("\n\t\t[!] Input Data Pembeli dulu!");
						}else if(pembelian!=1){
							printf("\n\t\t[!] Input Data Pembelian dulu!");
						}else{
							hitungKeuntungan(&keuntunganAsusa, totAsusa, hargaAsusa, pabrikAsusa);
							printf("\n\tKeuntungan Monitor Asusa  = Rp %d", keuntunganAsusa);
							hitungKeuntungan(&keuntunganLenova, totLenova, hargaLenova, pabrikLenova);
							printf("\n\tKeuntungan Monitor Lenova = Rp %d", keuntunganLenova);
							hitungKeuntungan(&keuntunganApel, totApel, hargaApel, pabrikApel);
							printf("\n\tKeuntungan Monitor Apel   = Rp %d", keuntunganApel);
							hitungKeuntungan(&keuntunganSangsung, totSangsung, hargaSangsung, pabrikSangsung);
							printf("\n\tKeuntungan Monitor Sangsung = Rp %d", keuntunganSangsung);
							
							hitungTotal(&totalUntung, keuntunganAsusa, keuntunganLenova, keuntunganApel, keuntunganSangsung);
							printf("\n\n\tTotal Keuntungan : Rp %d", totalUntung);
						}
						getch();
						break;

                    case 0:
                        printf("\n\t\tTerima Kasih...");
                        toleransi=3;
                        break;

                    default:
                        printf("\n\t\t[!] Menu tak diketahui!");
                        getch();
                        break;
                }
            }while(pil!=0);
            getch();
        }else if(cekIn==-1){
            printf("\n\t\t\t\t\t[!] Username / Password Salah!");
			toleransi--;
            getch();
        }
		
    }while(toleransi!=0 && cekIn!=0);

        printf("\n\n\t\t\t\t\tBerhasil Keluar...");
		printf("\n\t\t\t\t\tNama - NPM - Kelas");
		getch();
    return 0;
}

void inisialisasi(int *cekIn, int *toleransi, int *pembeli, int *pembelian, int *pembelianKhusus, int *tempJenis, int *jmlAsusa, int *jmlLenova, int *jmlApel, int *jmlSangsung, 
                    int *totAsusa, int *totLenova, int *totApel, int *totSangsung, int *tempAsusa, int *tempLenova, int *tempApel, int *tempSangsung, int *total){
    *cekIn=0;
    *toleransi=3;
    *pembeli=0;
    *pembelian=0;
    *tempJenis=0;
    *pembelianKhusus=0;
    *jmlAsusa=30;
    *jmlLenova=30;
    *jmlApel=60;
    *jmlSangsung=60;
    *totAsusa=0;
    *totLenova=0;
    *totApel=0;
    *totSangsung=0;
    *tempAsusa=0;
    *tempLenova=0;
    *tempApel=0;
    *tempSangsung=0;
    *total=0;
}

void pengurangan(int *m, int pengurang){
	
	if(*m >= pengurang){
		*m = *m - pengurang;
	}
	
}

void penjumlahan(int *m, int penjumlah){
	
	*m = *m + penjumlah;
}

void perkalian(int *hasil, int harga, int pengali){
	
	*hasil = harga * pengali;
}

void cekLogin(int *cekIn, string nama, int pass){
    if(strcmp(nama,"Atma")==0 && pass==10659){
        *cekIn=1;
    }else if(strcmp(nama,"0")==0 && pass==0){
        *cekIn=0;
    }else{
        *cekIn=-1;
    }
}

void cekJenis(int *tempJenis, string jenis, int A, int L, int Ap, int S){
    if(strcmpi(jenis,"Asusa")==0){
		*tempJenis=A;
	}else if(strcmpi(jenis,"Lenova")==0){
		*tempJenis=L;
	}else if(strcmpi(jenis,"Apel")==0){
		*tempJenis=Ap;
	}else if(strcmpi(jenis,"Sangsung")==0){
		*tempJenis=S;
	}else{
		*tempJenis=-1;
	}
}

void pembaruanKetersediaan(int *jmlA, int *jmlL, int *jmlAp, int *jmlS, int *totA, int *totL, int *totAp, int *totS, string jenis, int jumlah){
    if(strcmpi(jenis,"Asusa")==0){
		pengurangan(&(*jmlA), jumlah);
        penjumlahan(&(*totA), jumlah);
	}else if(strcmpi(jenis,"Lenova")==0){
		pengurangan(&(*jmlL), jumlah);
        penjumlahan(&(*totL), jumlah);
	}else if(strcmpi(jenis,"Apel")==0){
		pengurangan(&(*jmlAp), jumlah);
        penjumlahan(&(*totAp), jumlah);
	}else if(strcmpi(jenis,"Sangsung")==0){
		pengurangan(&(*jmlS), jumlah);
        penjumlahan(&(*totS), jumlah);
	}
}

void tampilDataPembeli(string nama, string tanggal, string jam){
	
	printf("\n\tNama             : %s", nama);
	printf("\n\tWaktu Kedatangan : %s %s", tanggal, jam);
}

void tampilDataPembeliKhusus(string nik, string pekerjaan, string alamat){
	
	printf("\n\tNIK              : %s", nik);
	printf("\n\tPekerjaan        : %s", pekerjaan);
	printf("\n\tAlamat           : %s", alamat);
}

void rincianPembelian(int jmlA, int jmlL, int jmlAp, int jmlS, int hA, int hL, int hAp, int hS, int totA, int totL, int totAp, int totS){
	
	printf("\n\n\t\t\t===== RINCIAN =====");
	printf("\n\tMonitor Asusa       | %d |\t| @Rp %d  |\t---> Total : Rp %d", jmlA, hA, totA);
	printf("\n\tMonitor Lenova      | %d |\t| @Rp %d  |\t---> Total : Rp %d", jmlL, hL, totL);
	printf("\n\tMonitor Apel        | %d |\t| @Rp %d |\t---> Total : Rp %d", jmlAp, hAp, totAp);
	printf("\n\tMonitor Sangsung    | %d |\t| @Rp %d |\t---> Total : Rp %d", jmlS, hS, totS);
	
}

void hitungTotal(int *total, int totA, int totL, int totAp, int totS){
	
	*total=totA+totL+totAp+totS;
}


//Untuk bonus
void inisialisasiSoalBonus(int *kA, int *kL, int *kAp, int *kS){
	
	*kA=0;
	*kL=0;
	*kAp=0;
	*kS=0;
}

void hitungKeuntungan(int *keuntungan, int jml, int hargaJual, int hargaPabrik){
	int penjualan, pabrik;
	
	perkalian(&penjualan,hargaJual,jml);
	perkalian(&pabrik,hargaPabrik,jml);
	pengurangan(&penjualan,pabrik);
	
	*keuntungan = penjualan;
}


