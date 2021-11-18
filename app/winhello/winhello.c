int api_openwin(char *buf, int xsiz, int ysiz, int col_inv, char *title);
int api_getkey(int mode);

char buf[150*50];

void main(void)
{
    int win;
    win = api_openwin(buf, 150, 50, -1, "hello");
    api_getkey(1);
}
