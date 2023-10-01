#include "utf8.hh"

char *set_utf8(void)
{
#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);
    _setmode(_fileno(stderr), _O_U8TEXT);

    if (!SetConsoleOutputCP(65001))
    {
        return nullptr;
    }
    
    for (int8_t index = 0; locales[index]; index++) {
        char *ret = setlocale(LC_ALL, locales[index]);

        if (ret) {
            return ret;
        }
    }
#else
    FILE *locales = popen("locale -a | grep -i '\\.utf-8$\\|\\.utf8$'", "r");

    if (locales)
    {
        char locale[32];
        while (fgets(locale, sizeof(locale), locales))
        {
            locale[strlen(locale) - 1] = '\0';
            char *ret = setlocale(LC_ALL, locale);

            if (ret) {
                return ret;
            }
        }
        pclose(locales);
    }
#endif
    return nullptr;
}
