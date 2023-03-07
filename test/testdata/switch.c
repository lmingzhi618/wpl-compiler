int func(int a) {
    int ret;
    int x = 1;
    switch(x - 0) {
    case -1: 
        a = 1; 
        break;
    case 0:
        ret = 2;
        break;
    case 1:
        ret = 0;
        break;
    }

    return ret;
}
