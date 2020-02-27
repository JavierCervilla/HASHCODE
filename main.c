#include "includes/include_file.h"

int main (int argc, char *argv[])
{
    file f;
    argc++;
    int i;
    int libraries_used = 0;
    char *aux;
    char *out;
    int fd;

    bzero(&f, sizeof(file));
    f.output_char = ft_strdup("");
    read_file(argv[1], &f);
    calculate(&f);
    while (f.days_remaining > 0)
    {
        i = 0;
        while (i < f.libraries)
        {
            if (f.days_remaining < f.info_libraries[i].ndays ||
                                                f.info_libraries[i].score <= 0)
                useless(&f.info_libraries[i]);
            else if (f.info_libraries[i].scanned == false &&
                                                f.info_libraries[i].score > 0)
            {
                f.output_char = ft_strjoin(f.output_char, scan(&f, i));
                useless(&f.info_libraries[i]);
                libraries_used++;
                break;
            }
            i++;
        }
        calculate(&f);
       f.days_remaining--;
    }
    aux = ft_strjoin(ft_itoa(libraries_used), "\n");
    out = ft_strjoin(aux, f.output_char);
    free(aux);
    free(f.output_char);
    fd = creat("out.txt", 0644);
    write(fd, out, ft_strlen(out));
    close(fd);
    if (f.days > 0)
    {
        free(f.indiv_books);
        free(f.info_libraries);
    }
    return (0);
}
