void ft_swap(int *a, int *b);
int main(void) {
    int a = 4;
    int b = 7;
    int *ptr1 = &a;
    int *ptr2 = &b;
    ft_swap(ptr1, ptr2);
}
