#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct values{

    int way;
    char name;
    int depth;

};


void oScreen();
void Choose();
void katsayilarMatrisi();
void printMatris();
void kareMatris();

int main(){

    oScreen(); // ekrany açmak için gerekli olan komutlar fonksiyonu
    Choose();// grafik secimi ve yon belirtmeleri


return 0;
}

  END_OF_MAIN();


void oScreen(){

    allegro_init();
    install_keyboard();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0);
    clear_to_color(screen,makecol(0,0,0));
    install_mouse();


}



void Choose(){
    BITMAP *image=load_bitmap("resim.bmp",NULL);
    BITMAP *image1=load_bitmap("resim1.bmp",NULL);
    BITMAP *buffer =create_bitmap(SCREEN_W,SCREEN_H);//  katman açıyor

show_mouse(screen); //işaretci yüklüyor
 int i,j;
        char z;
           char road[4];
        while(!key[KEY_A]){ //grafikleri ekrana basma

      rectfill(buffer,150,350,200,400,makecol(255,0,0));
      blit(image,buffer,0,0,0,50,800,600);   // grafikleri basıyor
      blit(image1,buffer,0,0,300,50,800,600);
      rectfill(buffer,400,350,450,400,makecol(255,0,0));
      textout_ex(buffer,font,"SECIM1",150,360,makecol(0,0,0),-1);
      textout_ex(buffer,font,"SECIM2",400,360,makecol(0,0,0),-1);
      textout_ex(buffer,font,"SECIM YAPABILMEK ICIN 1.GRAFIK ICIN SECIM1, 2.GRAFIK ICIN SECIM2 BUTONUNA BASINIZ.",0,10,makecol(255,255,255),-1);

      draw_sprite(screen,buffer,0,0); //bufferı screeni veriyor
    if(mouse_x>150 && mouse_x<200&&mouse_y>350&&mouse_y<400 && (mouse_b & 1)  )
            break;
        else if(mouse_x>400 && mouse_x<450&&mouse_y>350&&mouse_y<400 && (mouse_b & 1)  )
            break;
        }

        if(mouse_x>150 && mouse_x<200&&mouse_y>350&&mouse_y<400 && (mouse_b & 1)  ){ //1. grafik secildiyse
                clear_bitmap(screen);
                struct values input[8];
                int temp=0;



while((mouse_b & 1)){
                    blit(image,screen,0,0,0,0,800,600);
                    textout_ex(screen,font,"KONSOL EKRANINA GIRIS YAPINIZ.",300,50,makecol(255,255,255),-1);
                }
                    printf("KUCUK HARFLERLE GIRIS YAPMANIZ GEREKMEKTEDIR.\n\n");
                    printf("ANA YOLLARDAN GIRIS VE CIKIS OLANLARI BELIRTINIZ.(2 GIRIS,2 CIKIS!)\n\n");
                    printf("ONCE GIRIS YOLLARINI GIRMENIZ GEREKMEKTEDIR.\n");


                    for(i=0;i<4;i++){
                       loop2 :scanf(" %c",&road[i]);
                                if(i!= 0){
                            for(j=i-1;j>=0;j--){
                                if(road[i]== road[j]){
                                    printf("AYNI YOL IKI KERE GIRILMEZ.TEKRAR GIRIS YAPINIZ.");
                                    goto loop2;
                                }
                            }
                            }

                        if(road[i] != 'x'&& road[i] != 'y'&& road[i] != 'z'&& road[i] != 't'){
                            printf("BOYLE BIR YOL BULUNMAMAKTA LUTFEN EN BASTAN GIRIS YAPINIZ.\n\n");
                            i=-1;
                        }
                            if(i==2){ //hata ekrani
                                loop :printf("3. GIRDIGINIZ YOL CIKIS ISE 'c' GIRIS ISE 'g' TUSLAYINIZ.\n\n");
                                scanf(" %c",&z);
                                    if(z=='c'){
                                            printf("CIKIS YOLLARINI YAZMAYA DEVAM EDINIZ.\n\n");
                                        continue;
                                    }
                                    else if(z== 'g'){
                                        printf("2'DEN FAZLA GIRIS YOLU OLAMAZ LUTFEN BASTAN GIRIS YAPINIZ!!\n\n");
                                        i=-1;
                                    }
                                    else{ //g veya c den baska birseye basilirsa.
                                        printf("YANLIS GIRIS YAPTINIZ.TEKRAR GIRIS YAPINIZ.\n\n");
                                        goto loop;
                            }
                            }



}

                for(i=0;i<4;i++){ //ana yollarin yogunlugu
                    if(i<2){
                    printf("%c YOLU ICIN\n",road[i]);
                    function(input,road[i],temp,1);
                    temp++;
        }
                        else if(i>=2){
                            printf("%c YOLU ICIN\n",road[i]);
                            function(input,road[i],temp,-1);

                            temp++;
        }
    }

  char r1,r2; //switchler icin
int a1,a2,a1y,a2y,h; //koordinatlar icin
            printf("ARA YOLLARIN YONUNU BELIRTINIZ."); //A yolu icin yon belirleme.
           loop4: printf("\n\nA yolunun yonunu belirtiniz.Once baslangic sonra cikis noktasini giriniz.\n\n");
            scanf( " %c %c",&r1,&r2);

            switch(r1){ //a yolunun baslangici
                case 'x': a1=132;
                        a1y=30;
                    break;
                case 't': a1=25;
                        a2y=130;
                    break;
                 default: printf("Yanlis yol girisi yaptiniz.Yeniden giriniz.");
                    goto loop4;

            }

            switch(r2){ //a yolunun cıkışı
                case 'x': a2=132;
                    break;
                case 't': a2=25;
                    break;
                 default: printf("Yanlis yol girisi yaptiniz.Yeniden giriniz.");
                    goto loop4;

            }

                if(a1<a2){ //t den x e
                        j=a2y;

                          h=a1+25;
                    for(i=0;i<4;i++){

                           circlefill(screen,h,j,5,makecol(255,255,0));
                                            j=j-20;
                                            h=h+18;
                                            rest(500);


                    }
            function(input,'a',temp,1);
            temp++;


                 }

                 if(a1>a2){ //x ten t ye
                        j=a1y;

                         h=a1;
                    for(i=0;i<4;i++){

                           circlefill(screen,h,j,5,makecol(255,255,0));
                                            j=j+33;
                                            h=h-27;
                                            rest(500);


                    }
                function(input,'a',temp,-1);
                temp++;

                 }



                 loop5: printf("\n\nB yolunun yonunu belirtiniz.Once baslangic sonra cikis noktasini giriniz.\n\n");
            scanf( " %c %c",&r1,&r2);

            switch(r1){ //b yolunun baslangici
                case 'x': a1=132;
                        a1y=30;
                    break;
                case 'y': a1=240;
                        a2y=134;
                    break;
                 default: printf("Yanlis yol girisi yaptiniz.Yeniden giriniz.");
                    goto loop5;

            }

            switch(r2){ //b yolunun cıkışı
                case 'x': a2=132;
                    break;
                case 'y': a2=240;
                    break;
                 default: printf("Yanlis yol girisi yaptiniz.Yeniden giriniz.");
                    goto loop5;

            }

            clear_bitmap(screen);
             blit(image,screen,0,0,0,0,800,600);
                if(a1<a2){  //x den  y ye
                        j=a1y+22;

                         h=a1;
                    for(i=0;i<4;i++){

                           circlefill(screen,h,j,5,makecol(255,255,0));
                                            j=j+20;
                                            h=h+23;
                                            rest(500);


                    }
            function(input,'b',temp,-1);
            temp++;


                 }

                 if(a1>a2){ //y den x e
                        j=a2y;

                         h=a1-25;
                    for(i=0;i<4;i++){

                           circlefill(screen,h,j,5,makecol(255,255,0));
                                            j=j-27;
                                            h=h-27;
                                            rest(500);


                    }
            function(input,'b',temp,1);
            temp++;

                 }

                 loop6: printf("\n\nC yolunun yonunu belirtiniz.Once baslangic sonra cikis noktasini giriniz.\n\n");
            scanf( " %c %c",&r1,&r2);

            switch(r1){ //c yolunun baslangici
                case 'z': a1=132;
                        a1y=238;
                    break;
                case 't': a1=25;
                        a2y=130;
                    break;
                 default: printf("Yanlis yol girisi yaptiniz.Yeniden giriniz.");
                    goto loop6;

            }

            switch(r2){ //c yolunun cıkışı
                case 'z': a2=132;
                    break;
                case 't': a2=25;
                    break;
                 default: printf("Yanlis yol girisi yaptiniz.Yeniden giriniz.");
                    goto loop6;

            }

           clear_bitmap(screen);
             blit(image,screen,0,0,0,0,800,600);


                if(a1<a2){ //t'den z'ye
                        j=a2y;

                        h=a1+25;
                    for(i=0;i<4;i++){

                           circlefill(screen,h,j,5,makecol(255,255,0));
                                            j=j+23;
                                            h=h+22;
                                            rest(500);
                    }
            function(input,'c',temp,-1);
            temp++;

                 }

                 if(a1>a2){ //z'den t'ye
                        j=a1y-25;

                         h=a1;
                    for(i=0;i<4;i++){

                           circlefill(screen,h,j,5,makecol(255,255,0));
                                            j=j-21;
                                            h=h-21;
                                            rest(500);


                    }
                function(input,'c',temp,1);
                temp++;

                 }

                 loop7: printf("\n\nD yolunun yonunu belirtiniz.Once baslangic sonra cikis noktasini giriniz.\n\n");
            scanf( " %c %c",&r1,&r2);

            switch(r1){ //d yolunun baslangici
                case 'z': a1=132;
                        a1y=238;
                    break;
                case 'y': a1=240;
                        a2y=134;
                    break;
                 default: printf("Yanlis yol girisi yaptiniz.Yeniden giriniz.");
                    goto loop7;

            }

            switch(r2){ //d yolunun cıkışı
                case 'z': a2=132;
                    break;
                case 'y': a2=240;
                    break;
                 default: printf("Yanlis yol girisi yaptiniz.Yeniden giriniz.");
                    goto loop7;

            }

           clear_bitmap(screen);
             blit(image,screen,0,0,0,0,800,600);


                if(a1<a2){ //z'den y'e
                        j=a1y-25;

                         h=a1;
                    for(i=0;i<4;i++){

                           circlefill(screen,h,j,5,makecol(255,255,0));
                                            j=j-23;
                                            h=h+22;
                                            rest(500);
                    }
                function(input,'d',temp,1);
                temp++;

                 }

                 if(a1>a2){ //y'den z'ye
                        j=a2y;

                         h=a1-25;
                    for(i=0;i<4;i++){

                           circlefill(screen,h,j,5,makecol(255,255,0));
                                            j=j+23;
                                            h=h-22;
                                            rest(500);
                    }
                    function(input,'d',temp,-1);
                    temp++;

                 }



        katsayilarMatrisi(1,input);
   //1. grafik icin yol yoğunlari ve gauss jordan çözümü


}
if(mouse_x>400 && mouse_x<450&&mouse_y>350&&mouse_y<400 && (mouse_b & 1)  ){//2. grafik için
        clear_bitmap(screen);
        struct values input[9];
        int temp=0;


    while((mouse_b & 1)){

                    blit(image1,screen,0,0,0,0,800,600);
                    textout_ex(screen,font,"KONSOL EKRANINA GIRIS YAPINIZ.",300,50,makecol(255,255,255),-1);
                }
                  printf("ANA YOLLARDAN GIRIS VE CIKIS OLANLARI BELIRTINIZ(2 GIRIS,2 CIKIS)\n\n");
                 printf("ONCE GIRIS YOLLARINI GIRMENIZ GEREKMEKTEDIR.\n");


                        for(i=0;i<4;i++){

				loop3 :scanf(" %c",&road[i]);
                                if(i!= 0){
                            for(j=i-1;j>=0;j--){
                                if(road[i]== road[j]){
                                    printf("AYNI YOL IKI KERE GIRILEMEZ TEKRAR GIRINIZ.");
                                    goto loop3;

                                }
                            }


                        if(road[i] != 'x'&& road[i] != 'y'&& road[i] != 'z'&& road[i] != 't'){
                            printf("BOYLE BIR YOL BULUNMAMAKTA.LUTFEN EN BASTAN GIRIS YAPIN.\n\n");
                            i=-1;
                        }
                            if(i==2){ //hata ekrani
                                loop1 :printf("3. GIRDIGINIZ YOL GIRIS ISE 'g' CIKIS ISE 'c' TUSLAYINIZ.\n\n");
                                scanf(" %c",&z);
                                    if(z=='c'){
                                            printf("CIKIS YOLLARINI YAZMAYA DEVAM EDINIZ\n\n");
                                        continue;
                                    }
                                    else if(z== 'g'){
                                        printf("2'DEN FAZLA GIRIS YOLU OLAMAZ!BASTAN GIRIS YAPINIZ.\n\n");
                                        i=-1;
                                    }
                                    else{ //g veya c den baska birseye basilirsa.
                                        printf("YANLIS GIRIS YAPTINIZ.TEKRAR GIRIS YAPINIZ.\n\n");
                                        goto loop1;
                            }
                            }


}
}
      for(i=0;i<4;i++){ //ana yollarin yogunlugu
                    if(i<2){
                    printf("%c YOLU ICIN:\n",road[i]);
                    function(input,road[i],temp,1);
                    temp++;
        }
                        else if(i>=2){
                            printf("%c YOLU ICIN\n",road[i]);
                            function(input,road[i],temp,-1);
                            temp++;
        }
    }

char r1,r2; //switchler icin
int a1,a2,a1y,a2y,h; //grafik çiziminde koordinat tutmak icin
            printf("ARA YOLLARIN YONUNU BELIRTINIZ.");
            //A yolu icin yon belirleme.
           loop8: printf("\n\nA yolunun yonunu belirtiniz.Once baslangic sonra cikis noktasini giriniz.\n\n");
            scanf( " %c %c",&r1,&r2);

            switch(r1){ //a yolunun baslangici
                case 'x': a1=132;
                        a1y=30;
                    break;
                case 't': a1=25;
                        a2y=130;
                    break;
                 default: printf("Yanlis yol girisi yaptiniz.Yeniden giriniz.");
                    goto loop8;

            }

            switch(r2){ //a yolunun cıkışı
                case 'x': a2=132;
                    break;
                case 't': a2=25;
                    break;
                 default: printf("Yanlis yol girisi yaptiniz.Yeniden giriniz.");
                    goto loop8;

            }




                if(a1<a2){ //t den x e
                        j=a2y;

                          h=a1+25;
                    for(i=0;i<4;i++){

                           circlefill(screen,h,j,5,makecol(255,255,0));
                                            j=j-20;
                                            h=h+18;
                                            rest(500);


                    }

                    function(input,'a',temp,1);
                    temp++;



                 }

                 if(a1>a2){ //x ten t ye
                        j=a1y;

                         h=a1;
                    for(i=0;i<4;i++){

                           circlefill(screen,h,j,5,makecol(255,255,0));
                                            j=j+33;
                                            h=h-27;
                                            rest(500);


                    }
                    function(input,'a',temp,-1);
                    temp++;

                 }



                 loop9: printf("\n\nB yolunun yonunu belirtiniz.Once baslangic sonra cikis noktasini giriniz.\n\n");
            scanf( " %c %c",&r1,&r2);

            switch(r1){ //b yolunun baslangici
                case 'x': a1=132;
                        a1y=30;
                    break;
                case 'y': a1=240;
                        a2y=134;
                    break;
                 default: printf("Yanlis yol girisi yaptiniz.Yeniden giriniz.");
                    goto loop9;

            }

            switch(r2){ //b yolunun cıkışı
                case 'x': a2=132;
                    break;
                case 'y': a2=240;
                    break;
                 default: printf("Yanlis yol girisi yaptiniz.Yeniden giriniz.");
                    goto loop9;

            }

            clear_bitmap(screen);
           blit(image1,screen,0,0,0,0,800,600);


                if(a1<a2){  //x den  y ye
                        j=a1y+22;

                         h=a1;
                    for(i=0;i<4;i++){

                           circlefill(screen,h,j,5,makecol(255,255,0));
                                            j=j+20;
                                            h=h+23;
                                            rest(500);


                    }

                    function(input,'b',temp,-1);
                    temp++;

                 }

                 if(a1>a2){ //y den x e
                        j=a2y;

                         h=a1-25;
                    for(i=0;i<4;i++){

                           circlefill(screen,h,j,5,makecol(255,255,0));
                                            j=j-27;
                                            h=h-27;
                                            rest(500);


                    }
                    function(input,'b',temp,1);
                    temp++;

                 }

                 loop10: printf("\n\nC yolunun yonunu belirtiniz.Once baslangic sonra cikis noktasini giriniz.\n\n");
            scanf( " %c %c",&r1,&r2);

            switch(r1){ //c yolunun baslangici
                case 'z': a1=132;
                        a1y=238;
                    break;
                case 't': a1=25;
                        a2y=130;
                    break;
                 default: printf("Yanlis yol girisi yaptiniz.Yeniden giriniz.");
                    goto loop10;

            }

            switch(r2){ //c yolunun cıkışı
                case 'z': a2=132;
                    break;
                case 't': a2=25;
                    break;
                 default: printf("Yanlis yol girisi yaptiniz.Yeniden giriniz.");
                    goto loop10;

            }

            clear_bitmap(screen);
           blit(image1,screen,0,0,0,0,800,600);


                if(a1<a2){ //t'den z'ye
                        j=a2y;

                        h=a1+25;
                    for(i=0;i<4;i++){

                           circlefill(screen,h,j,5,makecol(255,255,0));
                                            j=j+23;
                                            h=h+22;
                                            rest(500);


                    }
                    function(input,'c',temp,-1);
                    temp++;

                 }

                 if(a1>a2){ //z'den t'ye
                        j=a1y-25;

                         h=a1;
                    for(i=0;i<4;i++){

                           circlefill(screen,h,j,5,makecol(255,255,0));
                                            j=j-21;
                                            h=h-21;
                                            rest(500);


                    }

function(input,'c',temp,1);
                    temp++;
                 }

                 loop11: printf("\n\nD yolunun yonunu belirtiniz.Once baslangic sonra cikis noktasini giriniz.\n\n");
            scanf( " %c %c",&r1,&r2);

            switch(r1){ //d yolunun baslangici
                case 'z': a1=132;
                        a1y=238;
                    break;
                case 'y': a1=240;
                        a2y=134;
                    break;
                 default: printf("Yanlis yol girisi yaptiniz.Yeniden giriniz.");
                    goto loop11;

            }

            switch(r2){ //d yolunun cıkışı
                case 'z': a2=132;
                    break;
                case 'y': a2=240;
                    break;
                 default: printf("Yanlis yol girisi yaptiniz.Yeniden giriniz.");
                    goto loop11;

            }

            clear_bitmap(screen);
           blit(image1,screen,0,0,0,0,800,600);


                if(a1<a2){ //z'den y'e
                        j=a1y-25;

                         h=a1;
                    for(i=0;i<4;i++){

                           circlefill(screen,h,j,5,makecol(255,255,0));
                                            j=j-23;
                                            h=h+22;
                                            rest(500);


                    }
                    function(input,'d',temp,1);
                    temp++;

                 }

                 if(a1>a2){ //y'den z'ye
                        j=a2y;

                         h=a1-25;
                    for(i=0;i<4;i++){

                           circlefill(screen,h,j,5,makecol(255,255,0));
                                            j=j+23;
                                            h=h-22;
                                            rest(500);


                    }
                    function(input,'d',temp,-1);
                    temp++;

                 }

                 loop12: printf("\n\nE yolunun yonunu belirtiniz.Once baslangic sonra cikis noktasini giriniz.\n\n");
            scanf( " %c %c",&r1,&r2);

            switch(r1){ //e yolunun baslangici
                case 't': a1=25;
                        a1y=130;
                    break;
                case 'y': a1=240;
                        a2y=134;
                    break;
                 default: printf("Yanlis yol girisi yaptiniz.Yeniden giriniz.");
                    goto loop12;

            }

            switch(r2){ //e yolunun cıkışı
                case 't': a2=25;
                    break;
                case 'y': a2=240;
                    break;
                 default: printf("Yanlis yol girisi yaptiniz.Yeniden giriniz.");
                    goto loop12;

            }

            clear_bitmap(screen);
           blit(image1,screen,0,0,0,0,800,600);


                if(a1<a2){ //t'den y'e

                        j=a1y;
                         h=a1+25;
                    for(i=0;i<5;i++){

                           circlefill(screen,h,j,5,makecol(255,255,0));
                                            h=h+35;
                                            rest(500);


                    }
                function(input,'e',temp,1);
                    temp++;

                 }

                 if(a1>a2){ //y'den t'ye
                        j=a2y-5;

                         h=a1-25;
                    for(i=0;i<5;i++){

                           circlefill(screen,h,j,5,makecol(255,255,0));
                                            h=h-35;
                                            rest(500);


                    }
                    function(input,'e',temp,-1);
                    temp++;

                 }

        katsayilarMatrisi(2,input);
   //2. grafik icin yol yoğunlari ve gauss jordan çözümü


}
}

void function(struct values inputs[],char n,int temp,int w){
    inputs[temp].name=n;
    inputs[temp].way=w;
    printf("yogunlugu giriniz:\n");
    scanf("%d",&inputs[temp].depth);

}


 void katsayilarMatrisi(int v,struct values inputs[]){
        int i,n,temp=0;
        if(v==2){
            n=9;
        } else if(v==1)
            n=8;



        for(i=0;i<n;i++){
            if(inputs[i].depth== -1)
                temp++;

        }
        if(temp>5){
            printf("BU DENKLEMİN COZUMU YAPILAMAMAKTADIR.");
            exit (1);
        }
          char unkown[temp];
          int j=0;

        for(i=0;i<n;i++){
            if(inputs[i].depth== -1){
                unkown[j]=inputs[i].name;
                inputs[i].depth=0;
                j++;
            }
        }

        char node[4]={'N','S','W','E'};
        int value=0,index,k;


        if(v==2){
        int matris[5][10];

        for(i=0;i<5;i++){ //matrisin tüm değerleri 0'lanır.
                for(j=0;j<10;j++){
                    matris[i][j]=0;
                }
            }

        value=inputs[0].depth+inputs[1].depth-inputs[2].depth-inputs[3].depth;//denklem1
            if(value<0)
            value=value*-1;
            char index1[4];
        matris[0][9]=value;
         i=0;
         for(j=0;j<4;j++){ //ana yolun değerleri aranır.
                        index1[j]=inputs[j].name;
                        }

             for(j=0;j<temp;j++){//matriste bilinmeyen yerine 1 koyuldu

                        if(unkown[j]=='x'&&(unkown[j]==index1[0]||unkown[j]==index1[1])){
                                matris[0][0]=1;

                        }

                            if(unkown[j]=='y'&&(unkown[j]==index1[0]||unkown[j]==index1[1])){
                                matris[0][1]=1;

                        }
                              if(unkown[j]=='z'&&(unkown[j]==index1[0]||unkown[j]==index1[1])){
                                matris[0][2]=1;

                        }
                                if(unkown[j]=='t'&&(unkown[j]==index1[0]||unkown[j]==index1[1])){
                                matris[0][3]=1;

                        }


                        if(unkown[j]=='x'&&(unkown[j]==index1[2] || unkown[j]==index1[3])){
                                matris[0][0]=-1;

                        }
                            if(unkown[j]=='y'&&(unkown[j]==index1[2] || unkown[j]==index1[3])){
                                matris[0][1]=-1;

                        }
                              if(unkown[j]=='z'&&(unkown[j]==index1[2] || unkown[j]==index1[3])){
                                matris[0][2]=-1;

                        }
                                if(unkown[j]=='t'&&(unkown[j]==index1[2] || unkown[j]==index1[3])){
                                matris[0][3]=-1;

                        }

             }

            for(i=0;i<4;i++){ //tum node'ları gezmek icin

            switch(node[i]){ //dugum noktalarına gore denklem kurulur.

              case 'N': for(j=0;j<4;j++){ //ana yolun değerleri aranır.
                        if(inputs[j].name=='x')
                            index=j;
                        }
            value=((inputs[index].depth*inputs[index].way))+(inputs[4].depth*inputs[4].way)+(inputs[5].depth*inputs[5].way);
             if(value<0)
            value=value*-1;
              matris[1][9]=value;

                for(j=0;j<temp;j++){ //matriste bilinmeyen yerine 1 koyuldu
                        if(unkown[j]=='x')
                            matris[1][0]=1*inputs[index].way;
                            if(unkown[j]=='a')
                            matris[1][4]=1*inputs[4].way;
                              if(unkown[j]=='b')
                            matris[1][5]=1*inputs[5].way;
                        }

                printMatris(10,matris,5);
                break;

              case 'S':  for(j=0;j<4;j++){ //ana yolun değerleri aranır.
                        if(inputs[j].name=='z')
                            index=j;
                        }
        value=(inputs[index].depth*inputs[index].way)+((inputs[6].depth*inputs[6].way)*-1)+((inputs[7].depth*inputs[7].way)*-1);
         if(value<0)
            value=value*-1;

              matris[2][9]=value;

               for(j=0;j<temp;j++){ //matriste bilinmeyen yerine 1 koyuldu
                        if( unkown[j]=='z')
                            matris[2][2]=1*inputs[index].way;
                           if( unkown[j]=='c')
                            matris[2][6]=1*inputs[6].way*-1;
                             if( unkown[j]=='d')
                            matris[2][7]=1*inputs[7].way*-1;
                        }

                printMatris(10,matris,5);
                break;

              case 'E': for(j=0;j<4;j++){ //ana yolun değerleri aranır.
                        if(inputs[j].name=='y')
                            index=j;
                        }
value=(inputs[index].depth*inputs[i].way)+((inputs[5].depth*inputs[5].way)*-1)+(inputs[7].depth*inputs[7].way)+(inputs[8].depth*inputs[8].way);
 if(value<0)
            value=value*-1;
            matris[3][9]=value;

                 for(j=0;j<temp;j++){ //matriste bilinmeyen yerine 1 koyuldu
                        if( unkown[j]=='y')
                         matris[3][1]=1*inputs[index].way;
                           if( unkown[j]=='d')
                          matris[3][7]=1*inputs[7].way;
                             if( unkown[j]=='b')
                            matris[3][5]=1*inputs[5].way*-1;
                                if( unkown[j]=='e')
                              matris[3][8]=1*inputs[8].way;
                        }

                printMatris(10,matris,5);
                break;



              case 'W': for(j=0;j<4;j++){ //ana yolun değerleri aranır.
                        if(inputs[j].name=='t')
                            index=j;
                        }

value=(inputs[index].depth*inputs[index].way)+((inputs[4].depth*inputs[4].way)*-1)+(inputs[6].depth*inputs[6].way)+((inputs[8].depth*inputs[8].way)*-1);
 if(value<0)
            value=value*-1;
            matris[4][9]=value;

                        for(j=0;j<temp;j++){ //matriste bilinmeyen yerine 1 koyuldu
                        if( unkown[j]=='t')
                            matris[4][3]=1*inputs[index].way;
                           if( unkown[j]=='c')
                             matris[4][6]=1*inputs[6].way;
                             if( unkown[j]=='a')
                              matris[4][4]=1*inputs[4].way*-1;
                                if( unkown[j]=='e')
                               matris[4][8]=1*inputs[8].way*-1;
                        }
                printMatris(10,matris,5);
                break;
          }
       }
       kareMatris(10,matris,5,unkown,temp);

        }

        if(v==1){
            int matris[5][9];

        for(i=0;i<5;i++){ //matrisin tüm değerleri 0'lanır.
                for(j=0;j<9;j++){
                    matris[i][j]=0;
                }
            }

        value=inputs[0].depth+inputs[1].depth - inputs[2].depth - inputs[3].depth;//denklem1
         if(value<0)
            value=value*-1;
            char index1[4];
        matris[0][8]=value;
        i=0;

             for(j=0;j<4;j++){ //ana yolun değerleri aranır.
                        index1[j]=inputs[j].name;
                        }

             for(j=0;j<temp;j++){//matriste bilinmeyen yerine 1 koyuldu

                        if(unkown[j]=='x'&&(unkown[j]==index1[0]||unkown[j]==index1[1])){
                                matris[0][0]=1;

                        }

                            if(unkown[j]=='y'&&(unkown[j]==index1[0]||unkown[j]==index1[1])){
                                matris[0][1]=1;

                        }
                              if(unkown[j]=='z'&&(unkown[j]==index1[0]||unkown[j]==index1[1])){
                                matris[0][2]=1;

                        }
                                if(unkown[j]=='t'&&(unkown[j]==index1[0]||unkown[j]==index1[1])){
                                matris[0][3]=1;

                        }


                        if(unkown[j]=='x'&&(unkown[j]==index1[2] || unkown[j]==index1[3])){
                                matris[0][0]=-1;

                        }
                            if(unkown[j]=='y'&&(unkown[j]==index1[2] || unkown[j]==index1[3])){
                                matris[0][1]=-1;

                        }
                              if(unkown[j]=='z'&&(unkown[j]==index1[2] || unkown[j]==index1[3])){
                                matris[0][2]=-1;

                        }
                                if(unkown[j]=='t'&&(unkown[j]==index1[2] || unkown[j]==index1[3])){
                                matris[0][3]=-1;

                        }
             }

            for(i=0;i<4;i++){ //tum node'ları gezmek icin

            switch(node[i]){ //dugum noktalarına gore denklem kurulur.

              case 'N': for(j=0;j<4;j++){ //ana yolun değerleri aranır.
                        if(inputs[j].name=='x')
                            index=j;
                        }
            value=((inputs[index].depth*inputs[index].way))+(inputs[4].depth*inputs[4].way)+(inputs[5].depth*inputs[5].way);
             if(value<0)
            value=value*-1;
              matris[1][8]=value;

                for(j=0;j<temp;j++){ //matriste bilinmeyen yerine 1 koyuldu
                        if(unkown[j]=='x')
                            matris[1][0]=1*inputs[index].way;
                            if(unkown[j]=='a')
                            matris[1][4]=1*inputs[4].way;
                              if(unkown[j]=='b')
                            matris[1][5]=1*inputs[5].way;
                        }

                printMatris(9,matris,5);
                break;

              case 'S':  for(j=0;j<4;j++){ //ana yolun değerleri aranır.
                        if(inputs[j].name=='z')
                            index=j;
                        }
        value=(inputs[index].depth*inputs[index].way)+((inputs[6].depth*inputs[6].way)*-1)+((inputs[7].depth*inputs[7].way)*-1);
     if(value<0)
            value=value*-1;
              matris[2][8]=value;

               for(j=0;j<temp;j++){ //matriste bilinmeyen yerine 1 koyuldu
                        if( unkown[j]=='z')
                            matris[2][2]=1*inputs[index].way;
                           if( unkown[j]=='c')
                            matris[2][6]=1*inputs[6].way*-1;
                             if( unkown[j]=='d')
                            matris[2][7]=1*inputs[7].way*-1;
                        }

                printMatris(9,matris,5);
                break;

              case 'E': for(j=0;j<4;j++){ //ana yolun değerleri aranır.
                        if(inputs[j].name=='y')
                            index=j;
                        }
                value=(inputs[index].depth*inputs[i].way)+((inputs[5].depth*inputs[5].way)*-1)+(inputs[7].depth*inputs[7].way);
             if(value<0)
            value=value*-1;
            matris[3][8]=value;

                 for(j=0;j<temp;j++){ //matriste bilinmeyen yerine 1 koyuldu
                        if( unkown[j]=='y')
                         matris[3][1]=1*inputs[index].way;
                           if( unkown[j]=='d')
                          matris[3][7]=1*inputs[7].way;
                             if( unkown[j]=='b')
                            matris[3][5]=1*inputs[5].way*-1;
                        }
                if(matris[3][1]==0 && matris[3][7]==0 && matris[3][5]==0)
                            matris[3][8]=0;

                printMatris(9,matris,5);
                break;



              case 'W': for(j=0;j<4;j++){ //ana yolun değerleri aranır.
                        if(inputs[j].name=='t')
                            index=j;
                        }

        value=(inputs[index].depth*inputs[index].way)+((inputs[4].depth*inputs[4].way)*-1)+(inputs[6].depth*inputs[6].way);
            if(value<0)
            value=value*-1;
            matris[4][8]=value;

                        for(j=0;j<temp;j++){ //matriste bilinmeyen yerine 1 koyuldu
                        if( unkown[j]=='t')
                            matris[4][3]=1*inputs[index].way;
                           if( unkown[j]=='c')
                             matris[4][6]=1*inputs[6].way;
                             if( unkown[j]=='a')
                              matris[4][4]=1*inputs[4].way*-1;
          }
          printMatris(9,matris,5);
                break;
       }
        }
    kareMatris(9,matris,5,unkown,temp);
}
 }
void printMatris(int k,int matris[][k],int n){
    int i,j;
    printf("MATRISIN YENI HALI:\n");
    for(i=0;i<n;i++){
                    for(j=0;j<k;j++){
                        printf("%d\t",matris[i][j]);
                    }
                    printf("\n");
                }

}

void kareMatris(int k,int matris[][k],int n,char unkown[],int temp){
    int i,j,h=0,temp1=0,u=0;
    int matris1[5][temp+1],matris2[temp][temp+1];

    for(i=0;i<temp;i++){
        for(j=0;j<5;j++){
            matris1[i][j]=0;
        }
    }

    for(i=0;i<5;i++){
            switch(unkown[i]){
                case 'x':for(j=0;j<5;j++){
                            matris1[j][h]=matris[j][0];
                }
                break;

                case 'y':for(j=0;j<5;j++){
                            matris1[j][h]=matris[j][1];
                }
                break;

                case 'z':  for(j=0;j<5;j++){
                            matris1[j][h]=matris[j][2];
                }
                break;

                case 't':  for(j=0;j<5;j++){
                            matris1[j][h]=matris[j][3];
                }
                break;

                case 'a':  for(j=0;j<5;j++){
                            matris1[j][h]=matris[j][4];
                }
                break;

                case 'b':  for(j=0;j<5;j++){
                            matris1[j][h]=matris[j][5];
                }
                break;

                case 'c':  for(j=0;j<5;j++){
                            matris1[j][h]=matris[j][6];
                }
                break;

                case 'd':  for(j=0;j<5;j++){
                            matris1[j][h]=matris[j][7];
                }
                break;

                case 'e':  for(j=0;j<5;j++){
                            matris1[h][j]=matris[8][j];
                }
                break;
            }
            h++;
    }
        for(i=0;i<5;i++){
            matris1[i][temp]=matris[i][k-1];
        }

    printMatris(temp+1,matris1,5);

        for(i=0;i<5;i++){
            for(j=0;j<temp;j++){
                if(matris1[i][j]== 0)
                    temp1++;
            }
                if(temp==temp1)
                continue;
                    else if(temp1 != temp){

                        for(h=0;h<temp;h++){
                            matris2[u][h]=matris1[i][h];
                        }
                        matris2[u][temp]=matris[i][k-1];
                        u++;

            }
            temp1=0;
        }
        printMatris(temp+1,matris2,temp);
        gaussJordan(temp+1,matris2,temp,unkown);
}

void gaussJordan(int k,int matris[][k],int n,char unknown[]){
    int i,j,index=7,h;
for(i=0;i<k-1;i++){ //köşegeni 1 yapmak için.
        if(matris[i][i]==-1){
            for(j=0;j<k;j++){

                matris[i][j]=matris[i][j]*-1;
            }
            printf("\n\n%d. satir -1 ile carpildi.\n\n",i);
            printMatris(k,matris,n);
        }

        if(matris[i][i]==0){
            for(j=0;j<n;j++){
                if(j==i)
                    continue;
                else if(matris[j][i]==1){
                        if(j==i)
                            continue;
                        index=j;
                        break;
            }
                }
                if(index==7){
                     for(j=0;j<n;j++){
                if(j==i)
                    continue;
                else if(matris[j][i]==-1){
                        index=j;
                        break;
            }
                }
                 for(j=0;j<k;j++){
                        matris[i][j]=matris[i][j]+(matris[index][j]*-1);
            }
            printf("\n\n%d. satir ile %d. satir -1 ile carpilip toplandi.%d. satira yazildi.\n\n",i,index,i);
            printMatris(k,matris,n);
                }
                else if(index != 7){
             degis(k,matris,n,i,index);
            printf("\n\n%d. satir ile %d. yer degistirdi.\n\n",i,index);
            printMatris(k,matris,n);
        }
        }
        index=7;
    }

        if(matris[0][0]==-1){
            for(j=0;j<k;j++){
                matris[0][j]=matris[0][j]*-1;
            }
            printf("\n\n0 satir -1 ile carpilir.\n\n");
            printMatris(k,matris,n);
          }
    if(matris[0][0]==0){
        for(j=0;j<n;j++){
            if(j==0)
                continue;
                if(matris[j][0]==1){
                    index=j;
                    break;
                }
        }
        if(index != 7)
        degis(k,matris,n,j,index);

        if(index==7){
             for(j=0;j<n;j++){
            if(j==0)
                continue;
                if(matris[j][0]==-1){
                    index=j;
                    break;
                }
        }
          for(j=0;j<n;j++){
            matris[0][j]=matris[0][j]+(-1*matris[index][j]);
          }
          printf("\n\n%d. satir -1 ile carpilip 0. satir ile toplandi.0. satira yazildi.\n\n",index);
          printMatris(k,matris,n);
        }
    }
        index=7;

        for(i=1;i<k-1;i++){ //0. sütun icin
            if(matris[i][0]==-1){
                for(j=0;j<n;j++){
                    if(i==j)
                        continue;
                    if(matris[j][0]==1){
                        index=j;
                        break;
                    }
                }

                if(index != 7){
                    for(j=0;j<n;j++){
                        matris[i][j]=matris[i][j]+matris[index][j];
                    }
                    printf("\n\n %d. satirla %d. satir toplandi.%d. satira yazildi.\n\n",i,index,i);
                    printMatris(k,matris,n);
                }
                if(index==7){
                         for(j=0;j<n;j++){
                    if(i==j)
                        continue;
                    if(matris[j][0]==-1){
                        index=j;
                        break;
                    }
                }
                 for(j=0;j<n;j++){
                        matris[i][j]=matris[i][j]+(matris[index][j]*-1);
                    }
                    printf("\n\n %d. satir -1 ile carpilip %d. satir toplandi.%d. satira yazildi.\n\n",index,i,i);
                    printMatris(k,matris,n);
                }
            }

            if(matris[i][0]==1){
                for(j=0;j<n;j++){
                    if(i==j)
                        continue;
                    if(matris[j][0]==1){
                        index=j;
                        break;
                    }
                }

                if(index != 7){
                    for(j=0;j<n;j++){
                        matris[i][j]=matris[i][j]-matris[index][j];
                    }
                    printf("\n\n %d. satirdan %d. satir cikarildi.%d. satira yazildi.\n\n",i,index,i);
                    printMatris(k,matris,n);
                }
                if(index==7){
                         for(j=0;j<n;j++){
                    if(i==j)
                        continue;
                    if(matris[j][0]==-1){
                        index=j;
                        break;
                    }
                }
                 for(j=0;j<n;j++){
                        matris[i][j]=matris[i][j]+(matris[index][j]);
                    }
                    printf("\n\n %d. satir ile %d. satir toplandi.%d. satira yazildi.\n\n",i,index,i);
                    printMatris(k,matris,n);
                }
            }
            index=7;
        }
    index=7;
    for(i=1;i<k-1;i++){
        for(j=n-1;j>i;j--){
                   if(matris[j][i]==-1){
                    for(h=0;h<k;h++){
                        matris[j][h]=matris[j][h]*-1;
                    }
                    printf("\n\nMatrisin %d. satiri -1 ile carpildi.\n\n",j);
                    printMatris(k,matris,n);

                    for(h=1;h<n;h++){
                            if(h==j)
                                continue;
                        if(matris[h][i]==1){
                            index=h;
                            break;
                        }
                    }
                    if(index != 7){
                    for(h=0;h<k;h++){
                        matris[j][h]=matris[j][h]-matris[index][h];
                    }
                    printf("\n\nMatrisin %d. satirindan %d. satiri cikarildi.%d. satira yazildi.\n\n",j,index,j);
                    printMatris(k,matris,n);
                    }
                    if(index==7){
                        for(h=1;h<n;h++){
                            if(h==j)
                                continue;
                        if(matris[h][i]==-1){
                            index=h;
                            break;
                        }
                    }

                     if(index==7){
                                for(h=1;h<n;h++){
                                if(h==j)
                                    continue;
                        if(matris[h][i]==0){
                            index=h;
                            break;
                        }
                    }
                    degis(k,matris,n,j,index);
                    goto loop13;
                        }
                    for(h=0;h<k;h++){
                        matris[j][h]=matris[j][h]+matris[index][h];
                    }
                     printf("\n\nMatrisin %d. satiri ile %d. satir toplandi.%d. satira yazildi.\n\n",j,index,j);
                     printMatris(k,matris,n);

                    }
                   }

                   if(matris[j][i]==1){
                         for(h=1;h<n;h++){
                                if(h==j)
                                    continue;
                        if(matris[h][i]==1){
                            index=h;
                            break;
                        }
                    }
                    if(index != 7){
                    for(h=0;h<k;h++){
                        matris[j][h]=matris[j][h]-matris[index][h];
                    }
                    printf("\n\nMatrisin %d. satirindan %d. satiri cikarildi.%d. satira yazildi.\n\n",j,index,j);
                    printMatris(k,matris,n);
                    }

                    if(index==7){
                            for(h=1;h<n;h++){
                                if(h==j)
                                    continue;
                        if(matris[h][i]==-1){
                            index=h;
                            break;
                        }
                    }

                        if(index==7){
                                for(h=1;h<n;h++){
                                if(h==j)
                                    continue;
                        if(matris[h][i]==0){
                            index=h;
                            break;
                        }
                    }
                    degis(k,matris,n,j,index);
                    goto loop13;
                        }
                        else if(index != 7){
                    for(h=0;h<k;h++){
                        matris[j][h]=matris[j][h]+matris[index][h];
                    }
                    printf("\n\nMatrisin %d. satir ile %d. satir toplandi.%d. satira yazildi.\n\n",j,index,j);
                    printMatris(k,matris,n);

                    }
                    }
        }

                    }
                     loop13:index=7;
                   }
                   index=7;
                   for(i=0;i<k-1;i++){ //köşegeni 1 yapmak için.
        if(matris[i][i]==-1){
            for(j=0;j<k;j++){

                matris[i][j]=matris[i][j]*-1;
            }
            printf("\n\n%d. satir -1 ile carpildi.\n\n",i);
            printMatris(k,matris,n);
        }

        if(matris[i][i]==0){
            for(j=0;j<n;j++){
                if(j==i)
                    continue;
                else if(matris[j][i]==1){
                        if(j==i)
                            continue;
                        index=j;
                        break;
            }
                }
                if(index==7){
                     for(j=0;j<n;j++){
                if(j==i)
                    continue;
                else if(matris[j][i]==-1){
                        index=j;
                        break;
            }
                }
                 for(j=0;j<k;j++){
                        matris[i][j]=matris[i][j]+(matris[index][j]*-1);
            }
            printf("\n\n%d. satir ile %d. satir -1 ile carpilip toplandi.%d. satira yazildi.\n\n",i,index,i);
            printMatris(k,matris,n);
                }
                else if(index != 7){
             degis(k,matris,n,j,index);
        }
        }
        index=7;
    }
    index=n-1;
    for(j=k-2;j>1;j--){
        for(i=0;i<n;i++){
            if(i==j)
                continue;

            if(matris[i][j]==1){
                    if(index==i)
                        continue;
                for(h=0;h<k;h++){
                    matris[i][h]=matris[i][h]-matris[index][h];
                }
                printf("\n\nMatrisin %d. satirindan %d. satiri cikarildi. %d. satira yazildi.\n\n",i,index,i);
                printMatris(k,matris,n);

            }

             if(matris[i][j]==-1){
                    if(index==i)
                        continue;
                for(h=0;h<k;h++){
                    matris[i][h]=matris[i][h]+matris[index][h];
                }
                printf("\n\nMatrisin %d. satiri ile %d. satiri toplandi. %d. satira yazildi.\n\n",i,index,i);
                printMatris(k,matris,n);

            }
        }
        index--;
    }

    if(matris[0][1]==1){
            for(h=0;h<k;h++){
        matris[0][h]=matris[0][h]-matris[1][h];
            }
            printf("\n\n0.satirdan 1. satir cikarildi.\n\n");
            printMatris(k,matris,n);
    }
    if(matris[0][1]==-1){
            for(h=0;h<k;h++){
        matris[0][h]=matris[0][h]+matris[1][h];
            }
            printf("\n\n0.satirdan 1. satir cikarildi.\n\n");
            printMatris(k,matris,n);
    }

    for(i=0;i<n;i++){
            if(matris[i][k-1]<0){
        printf("\n\n%c:%d\n\n",unknown[i],(matris[i][k-1]*-1));
    }
            if(matris[i][k-1]>0){
        printf("\n\n%c:%d\n\n",unknown[i],matris[i][k-1]);
    }
    }
}

    void degis(int k,int matris[][k],int n,int j,int index){
        int i,temp;

            for(i=0;i<k;i++){
                temp=matris[j][i];
                matris[j][i]=matris[index][i];
                matris[index][i]=temp;
            }
            printf("\n\n%d. satir ile %d. satir yer degistirdi.\n\n",j,index);
            printMatris(k,matris,n);

    }




















