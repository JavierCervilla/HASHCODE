#include "includes/include_file.h"

void useless(library *l) // Anula librerias por falta de días
{
    l->scanned = true;
    l->score = 0;
    l->sum_score = 0;
}

int main (int argc, char *argv[])
{
    file f;
    argc++;
    int i;

    bzero(&f, sizeof(file));
    f.output_char = ft_strdup("");
    read_file(argv[1], &f);
    calculate(&f);
    while (f.days_remaining > 0)
    {
        i = 0;
        printf("dr: %d\n", f.days_remaining);
        while (i < f.libraries)
        {
            if (f.days_remaining < f.info_libraries[i].ndays ||
                                                f.info_libraries[i].score <= 0)
                useless(&f.info_libraries[i]);
            else if (f.info_libraries[i].scanned == false && f.info_libraries[i].score > 0)
            {
                f.output_char = ft_strjoin(f.output_char, scan(&f, i));
                useless(&f.info_libraries[i]);
                break;
            }
            i++;
        }
        calculate(&f);
       f.days_remaining--;
    }
    //printf("%s", f.output_char);
    return (0);
}
