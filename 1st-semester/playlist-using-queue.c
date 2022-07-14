#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct music
{

    char Judul[25];
    char Artis[25];
    char Genre[25];
    struct music *next;

} Playlist;

Playlist *front = NULL;
Playlist *rear = NULL;

void Menu();
void MenambahLagu();
void MemutarLagu();
void MenampilkanLagu();
void MenyimpanLagukeBinary();
void LaguDisimpan();

int main()
{
    Menu();

    return 0;
}

void Menu()
{

    printf("\n================= MENU PLAYLIST =================");
    printf("\n1. Menambahkan Lagu ke Dalam Playlist");
    printf("\n2. Memutar Lagu pada Playlist");
    printf("\n3. Menampilkan Daftar Lagu pada Playlist");
    printf("\n4. Menyimpan Playlist dalam Binary Files");
    printf("\n5. Keluar dari Playlist\n");

    while (1)
    {

        int userchoice;
        printf("\nMasukkan pilihan user : \n"); // input user choice
        printf("=> ");
        scanf("%d", &userchoice);

        switch (userchoice)
        {

        case 1:
            MenambahLagu();
            break;

        case 2:
            MemutarLagu();
            break;

        case 3:
            MenampilkanLagu();
            break;

        case 4:
            MenyimpanLagukeBinary();

        case 5:
            exit(1);

        default:
            printf("\nPilihan yang anda masukkan salah!\n");
            printf("Silakan coba kembali\n");
        }
    }
}

void MenambahLagu() // function to add a song
{

    Playlist *newnode;

    newnode = (Playlist *)malloc(sizeof(Playlist));

    printf("\n\nDetail Lagu yang akan ditambahkan : \n");
    puts("====================================================================");
    printf("Judul Lagu\t\t : ");
    fflush(stdin);
    gets(newnode->Judul);
    printf("Artis\t\t\t : ");
    fflush(stdin);
    gets(newnode->Artis);
    printf("Genre\t\t\t : ");
    fflush(stdin);
    gets(newnode->Genre);
    puts("===================================================================");

    newnode->next = NULL;

    if (front == NULL && rear == NULL)
    {

        front = rear = newnode;
    }

    else
    {

        rear->next = newnode;
        rear = newnode;
    }
}

void MemutarLagu() // function to play a song
{
    Playlist *play;

    play = front;

    if (rear == NULL && front == NULL)
    {
        printf("\nTidak ada lagu di dalam playlist.\n");
    }

    else
    {

        printf("\n\nMemutar Lagu yang berjudul %s...", play->Judul);

        printf("\n\nDetail Lagu yang sedang diputar : \n");
        printf("Judul Lagu \t\t : %s\n", play->Judul);
        printf("Artis \t\t\t : %s\n", play->Artis);
        printf("Genre \t\t\t : %s\n", play->Genre);

        front = front->next;
        free(play);
    }
}

void MenampilkanLagu() // function to show the song list
{
    Playlist *display;

    if (front == NULL && rear == NULL)
    {

        printf("\nTidak ada lagu di dalam playlist.\n");
    }

    else
    {

        display = front;

        int i = 1;
        while (display != NULL)
        {

            printf("\n\nDetail Lagu ke-%d : \n", i);
            printf("Judul Lagu \t\t : %s\n", display->Judul);
            printf("Artis \t\t\t : %s\n", display->Artis);
            printf("Genre \t\t\t : %s\n", display->Genre);
            i++;
            display = display->next;
        }
    }
}

void MenyimpanLagukeBinary() // function to save playlist into binary files
{

    Playlist *newnode;
    FILE *playlist;

    playlist = fopen("Playlist.dat", "wb");

    if (playlist == NULL)
    {

        printf("\nFile playlist tidak tersedia!\n");
    }

    else
    {

        newnode = front;
        while (newnode != NULL)
        {
            newnode = newnode->next;
        }
    }

    fwrite(&newnode, sizeof(Playlist), 1, playlist);
    fclose(playlist);
    printf("\nPlaylist berhasil disimpan!\n\n");
}
