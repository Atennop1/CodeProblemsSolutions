#include <cstdio>

namespace SecondKyu
{
    char a[4][7] = { "Common", "Point", "Boost", "Better" };
    char (*b[4])[7] = { a + 3, a + 1, a, a + 2 };

    char (*(*C())[4])[7]
    {
        return &b;
    }

    char (**D())[7]
    {
        return C()[1] - 3;
    }

    char buf[256];

    char *PointerMonster()
    {
        int len;
        char (**(*f)())[7] = D;

        len  = sprintf(buf, "%s", *f()[0]);
        len += sprintf(buf + len, "%s ", *(f() - 1)[0]+4);
        len += sprintf(buf + len, "%s", (*f())[0]-4);
        len += sprintf(buf + len, "%s", f()[1][2]+3);
        sprintf(buf + len, "%s", *((*f)() - 1)[0] + 4);
        return buf;
    }
}