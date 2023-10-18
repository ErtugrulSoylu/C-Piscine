void ft_div_mod(int a, int b, int *div, int *mod);
int main(void) {
    int a = 31;
    int b = 4;
    int x, y;
    int *div = &x;
    int *mod = &y;
    ft_div_mod(a, b, div, mod);
}
