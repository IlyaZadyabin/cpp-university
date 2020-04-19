int main()
{
    int count;
    std::cin >> count;

    int i;
    Holder mas[count];

    for(i = 0; i < count - i - 1; i++) {
        mas[i].swap(mas[count - i - 1]);
    }
}
