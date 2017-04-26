OPENDIR / READDIR / CLOSEDIR
#include <dirent.h>
{
dir *opendir(const char *filename);
// Ouvre un dossier, renvoie un pointeur sur le dossier. Renvoie NULL si erreur.
struct dirent *readdir(dir *dirp);
// Renvoie un pointeur sur la prochaine entree du dossier, renvoie NULL si erreur ou dossier lu en entier.
int closedir(dir *dirp);
// Ferme le dossier et libere les structures *dirp, renvoie 0 en cas de succes, -1 si erreur.
}

struct dirent {
    ino_t          d_ino;       /* numéro d'inœud */
    off_t          d_off;       /* décalage jusqu'à la dirent suivante */
    unsigned short d_reclen;    /* longueur de cet enregistrement */
    unsigned char  d_type;      /* type du fichier */
    char           d_name[256]; /* nom du fichier */
};


STAT / LSTAT
#include <sys/stat.h>
{
int stat(const char *restrict path, struct stat *restict buf);
// Recupere les informations d'un fichier, pas besoin d'autorisations.
int lstat(const char *restrict path, struct stat *restict buf);
// Pareil, mais en cas de lien symbolique stat renvoie les infos du fichier lié, lstat renvoie les infos du lien lui meme.
}

struct stat
         {
             dev_t         st_dev;      /* Périphérique                */
             ino_t         st_ino;      /* Numéro i-noeud              */
             mode_t        st_mode;     /* Protection                  */
             nlink_t       st_nlink;    /* Nb liens matériels          */
             uid_t         st_uid;      /* UID propriétaire            */
             gid_t         st_gid;      /* GID propriétaire            */
             dev_t         st_rdev;     /* Type périphérique           */
             off_t         st_size;     /* Taille totale en octets     */
             unsigned long st_blksize;  /* Taille de bloc pour E/S     */
             unsigned long st_blocks;   /* Nombre de blocs alloués     */
             time_t        st_atime;    /* Heure dernier accès         */
             time_t        st_mtime;    /* Heure dernière modification */
             time_t        st_ctime;    /* Heure dernier changement    */
        };

GETPWUID
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
{
struct passwd *getpwuid(uid_t uid);
//Cherche le mot de passe a partir d'un uid. Renvoie un pointeur sur la structure passwd correspondant a l'uid.
}

struct passwd 
{
    char   *pw_name;   /* Nom d'utilisateur */
    char   *pw_passwd; /* Mot de passe de l'utilisateur */
    uid_t   pw_uid;    /* Identifiant de l'utilisateur */
    gid_t   pw_gid;    /* Identifiant du groupe de l'utilisateur */
    char   *pw_gecos;  /* Nom réel */
    char   *pw_dir;    /* Répertoire personnel */
    char   *pw_shell;  /* Interpréteur de commande */
};

GETGRGID 
#include <grp.h>
#include <uuid/uuid.h>
{
struct group *getgrgid(gid_t gid);
// Cherche un groupe via son id. Renvoie un pointeur sur la structure du groupe cherché.
}

     struct group {
                   char   *gr_name;    /* Nom du groupe.          */
                   char   *gr_passwd;  /* Mot de passe du groupe. */
                   gid_t   gr_gid;     /* ID du groupe.           */
                   char  **gr_mem;     /* Membres du groupe.      */
              };

TIME / CTIME
#include <time.h>
{
time_t time(time_t *tloc);
// Renvoie la date exacte a la seconde dans une time_t, et la stock egalement dans *tloc.
char *ctime(const time_t *clock);
// Renvoie la date exacte a la seconde pres dans une chaine de 26 caracteres.
}

READLINK
#include <unistd.h>
{
ssize_t readlink(const char restrict *path, char restrict *buf, size_t bufsize);
// Envoie le contenu d'un lien symbolique dans buf. Renvoie le nombre de caracteres du buffer si succes, -1 si erreur.
}

PERROR / STERROR
{
#include <stdio.h>
#include <string.h>
void perror(const char *s);
// Trouve le message d'erreur correspondant au errno et l'affiche suivi d'un \n. Si *s n'est pas NULL, son contenu est affiché apres le message d'erreur
char *sterror(int errnum);
// Renvoie le message d'erreur correspondant au errno.
}